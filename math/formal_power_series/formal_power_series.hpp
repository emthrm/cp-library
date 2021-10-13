#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <vector>

template <typename T>
struct FormalPowerSeries {
  std::vector<T> coef;

  explicit FormalPowerSeries(const int deg = 0) : coef(deg + 1, 0) {}
  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef) {}
  FormalPowerSeries(std::initializer_list<T> init) : coef(init.begin(), init.end()) {}
  template <typename InputIter>
  explicit FormalPowerSeries(InputIter first, InputIter last) : coef(first, last) {}

  inline const T &operator[](const int term) const { return coef[term]; }
  inline T &operator[](const int term) { return coef[term]; }

  using MUL = std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;
  using SQR = std::function<bool(const T&, T&)>;
  static void set_mul(const MUL mul) { get_mul() = mul; }
  static void set_sqr(const SQR sqr) { get_sqr() = sqr; }

  void resize(const int deg) { coef.resize(deg + 1, 0); }
  void shrink() {
    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();
  }
  int degree() const { return static_cast<int>(coef.size()) - 1; }

  FormalPowerSeries& operator=(const std::vector<T>& coef_) {
    coef = coef_;
    return *this;
  }
  FormalPowerSeries& operator=(const FormalPowerSeries& x) = default;

  FormalPowerSeries& operator+=(const FormalPowerSeries& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] += x[i];
    }
    return *this;
  }
  FormalPowerSeries& operator-=(const FormalPowerSeries& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] -= x[i];
    }
    return *this;
  }
  FormalPowerSeries& operator*=(const T x) {
    for (T& e : coef) e *= x;
    return *this;
  }
  FormalPowerSeries& operator*=(const FormalPowerSeries& x) {
    return *this = get_mul()(coef, x.coef);
  }
  FormalPowerSeries& operator/=(const T x) {
    assert(x != 0);
    const T inv_x = static_cast<T>(1) / x;
    for (T& e : coef) e *= inv_x;
    return *this;
  }
  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {
    const int x_size = x.coef.size();
    if (x_size > coef.size()) return *this = FormalPowerSeries();
    const int n = coef.size() - x_size + 1;
    FormalPowerSeries tmp = FormalPowerSeries(x.coef.rbegin(), x.coef.rbegin() + std::min(x_size, n)).inv(n - 1);
    tmp = FormalPowerSeries(coef.rbegin(), coef.rbegin() + n) * tmp;
    return *this = FormalPowerSeries(tmp.coef.rend() - n, tmp.coef.rend());
  }
  FormalPowerSeries& operator%=(const FormalPowerSeries& x) {
    if (x.degree() == 0) return *this = FormalPowerSeries{0};
    *this -= *this / x * x;
    resize(x.degree() - 1);
    return *this;
  }
  FormalPowerSeries& operator<<=(const int n) {
    coef.insert(coef.begin(), n, 0);
    return *this;
  }
  FormalPowerSeries& operator>>=(const int n) {
    if (degree() < n) return *this = FormalPowerSeries();
    coef.erase(coef.begin(), coef.begin() + n);
    return *this;
  }

  bool operator==(const FormalPowerSeries& x) const {
    FormalPowerSeries a(*this), b(x);
    a.shrink();
    b.shrink();
    const int deg = a.degree();
    if (deg != b.degree()) return false;
    for (int i = 0; i <= deg; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  bool operator!=(const FormalPowerSeries& x) const { return !(*this == x); }

  FormalPowerSeries operator+() const { return *this; }
  FormalPowerSeries operator-() const {
    FormalPowerSeries res(*this);
    for (T& e : res.coef) e = -e;
    return res;
  }

  FormalPowerSeries operator+(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) += x; }
  FormalPowerSeries operator-(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) -= x; }
  FormalPowerSeries operator*(const T x) const { return FormalPowerSeries(*this) *= x; }
  FormalPowerSeries operator*(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) *= x; }
  FormalPowerSeries operator/(const T x) const { return FormalPowerSeries(*this) /= x; }
  FormalPowerSeries operator/(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) /= x; }
  FormalPowerSeries operator%(const FormalPowerSeries& x) const { return FormalPowerSeries(*this) %= x; }
  FormalPowerSeries operator<<(const int n) const { return FormalPowerSeries(*this) <<= n; }
  FormalPowerSeries operator>>(const int n) const { return FormalPowerSeries(*this) >>= n; }

  T horner(const T x) const {
    T res = 0;
    for (int i = degree(); i >= 0; --i) {
      res = res * x + coef[i];
    }
    return res;
  }

  FormalPowerSeries differential() const {
    const int deg = degree();
    assert(deg >= 0);
    FormalPowerSeries res(std::max(deg - 1, 0));
    for (int i = 1; i <= deg; ++i) {
      res[i - 1] = coef[i] * i;
    }
    return res;
  }

  FormalPowerSeries exp(int deg = -1) const {
    assert(coef[0] == 0);
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    const FormalPowerSeries one{1};
    FormalPowerSeries res(one);
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1)) - res.log((i << 1) - 1) + one;
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries inv(int deg = -1) const {
    assert(coef[0] != 0);
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    FormalPowerSeries res{static_cast<T>(1) / coef[0]};
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1));
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries log(int deg = -1) const {
    assert(coef[0] == 1);
    if (deg == -1) deg = degree();
    FormalPowerSeries integrand = differential() * inv(deg - 1);
    integrand.resize(deg);
    for (int i = deg; i > 0; --i) {
      integrand[i] = integrand[i - 1] / i;
    }
    integrand[0] = 0;
    return integrand;
  }

  FormalPowerSeries pow(long long exponent, int deg = -1) const {
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    for (int i = 0; i < n; ++i) {
      if (coef[i] == 0) continue;
      const long long shift = exponent * i;
      if (shift > deg) break;
      T tmp = 1, base = coef[i];
      for (long long e = exponent; e > 0; e >>= 1) {
        if (e & 1) tmp *= base;
        base *= base;
      }
      const FormalPowerSeries res = ((*this >> i) * (static_cast<T>(1) / coef[i])).log(deg - shift);
      return ((res * static_cast<T>(exponent)).exp(deg - shift) * tmp) << shift;
    }
    return FormalPowerSeries(deg);
  }

  FormalPowerSeries mod_pow(long long exponent, const FormalPowerSeries& md) const {
    const FormalPowerSeries inv_rev_md = FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();
    const int inv_rev_md_size = inv_rev_md.coef.size(), md_size = md.coef.size();
    auto mod_mul = [&md, &inv_rev_md, inv_rev_md_size, md_size](
        FormalPowerSeries& multiplicand,
        const FormalPowerSeries& multiplier) -> void {
      multiplicand *= multiplier;
      if (md_size <= multiplicand.coef.size()) {
        const int n = multiplicand.coef.size() - md_size + 1;
        const FormalPowerSeries quotient =
            FormalPowerSeries(multiplicand.coef.rbegin(), multiplicand.coef.rbegin() + n) *
            FormalPowerSeries(inv_rev_md.coef.begin(), inv_rev_md.coef.begin() + std::min(inv_rev_md_size, n));
        multiplicand -= FormalPowerSeries(quotient.coef.rend() - n, quotient.coef.rend()) * md;
      }
      multiplicand.coef.resize(md_size - 1);
      if (multiplicand.coef.empty()) multiplicand.coef = {0};
    };
    FormalPowerSeries res{1}, base = *this;
    mod_mul(base, res);
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) mod_mul(res, base);
      mod_mul(base, base);
    }
    return res;
  }

  FormalPowerSeries sqrt(int deg = -1) const {
    const int n = coef.size();
    if (deg == -1) deg = n - 1;
    if (coef[0] == 0) {
      for (int i = 1; i < n; ++i) {
        if (coef[i] == 0) continue;
        if (i & 1) return FormalPowerSeries(-1);
        const int shift = i >> 1;
        if (deg < shift) break;
        FormalPowerSeries res = (*this >> i).sqrt(deg - shift);
        if (res.coef.empty()) return FormalPowerSeries(-1);
        res <<= shift;
        res.resize(deg);
        return res;
      }
      return FormalPowerSeries(deg);
    }
    T s;
    if (!get_sqr()(coef[0], s)) return FormalPowerSeries(-1);
    FormalPowerSeries res{s};
    const T half = static_cast<T>(1) / 2;
    for (int i = 1; i <= deg; i <<= 1) {
      res += FormalPowerSeries(coef.begin(), coef.begin() + std::min(n, i << 1)) * res.inv((i << 1) - 1);
      res *= half;
    }
    res.resize(deg);
    return res;
  }

  FormalPowerSeries translate(T c) const {
    const int n = coef.size();
    std::vector<T> fact(n, 1), inv_fact(n, 1);
    for (int i = 1; i < n; ++i) {
      fact[i] = fact[i - 1] * i;
    }
    inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];
    for (int i = n - 1; i > 0; --i) {
      inv_fact[i - 1] = inv_fact[i] * i;
    }
    std::vector<T> g(n), ex(n);
    for (int i = 0; i < n; ++i) {
      g[n - 1 - i] = coef[i] * fact[i];
    }
    T pow_c = 1;
    for (int i = 0; i < n; ++i) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    const std::vector<T> conv = get_mul()(g, ex);
    FormalPowerSeries res(n - 1);
    for (int i = 0; i < n; ++i) {
      res[i] = conv[n - 1 - i] * inv_fact[i];
    }
    return res;
  }

private:
  static MUL& get_mul() {
    static MUL mul = [](const std::vector<T>& a, const std::vector<T>& b) -> std::vector<T> {
      const int n = a.size(), m = b.size();
      std::vector<T> res(n + m - 1, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    };
    return mul;
  }
  static SQR& get_sqr() {
    static SQR sqr = [](const T& a, T& res) -> bool { return false; };
    return sqr;
  }
};
