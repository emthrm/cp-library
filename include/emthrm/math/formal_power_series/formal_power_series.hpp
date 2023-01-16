#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_FORMAL_POWER_SERIES_HPP_
#define EMTHRM_MATH_FORMAL_POWER_SERIES_FORMAL_POWER_SERIES_HPP_

#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <vector>

namespace emthrm {

template <typename T>
struct FormalPowerSeries {
  std::vector<T> coef;

  explicit FormalPowerSeries(const int deg = 0) : coef(deg + 1, 0) {}
  explicit FormalPowerSeries(const std::vector<T>& coef) : coef(coef) {}
  FormalPowerSeries(const std::initializer_list<T> init)
      : coef(init.begin(), init.end()) {}
  template <typename InputIter>
  explicit FormalPowerSeries(const InputIter first, const InputIter last)
      : coef(first, last) {}

  inline const T& operator[](const int term) const { return coef[term]; }
  inline T& operator[](const int term) { return coef[term]; }

  using Mult = std::function<std::vector<T>(const std::vector<T>&,
                                            const std::vector<T>&)>;
  using Sqrt = std::function<bool(const T&, T*)>;
  static void set_mult(const Mult mult) { get_mult() = mult; }
  static void set_sqrt(const Sqrt sqrt) { get_sqrt() = sqrt; }

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
    return *this = get_mult()(coef, x.coef);
  }
  FormalPowerSeries& operator/=(const T x) {
    assert(x != 0);
    return *this *= static_cast<T>(1) / x;
  }
  FormalPowerSeries& operator/=(const FormalPowerSeries& x) {
    const int n = degree() - x.degree() + 1;
    if (n <= 0) return *this = FormalPowerSeries();
    const std::vector<T> tmp = get_mult()(
        std::vector<T>(coef.rbegin(), std::next(coef.rbegin(), n)),
        FormalPowerSeries(
            x.coef.rbegin(),
            std::next(x.coef.rbegin(), std::min(x.degree() + 1, n)))
        .inv(n - 1).coef);
    return *this = FormalPowerSeries(std::prev(tmp.rend(), n), tmp.rend());
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

  bool operator==(FormalPowerSeries x) const {
    x.shrink();
    FormalPowerSeries y = *this;
    y.shrink();
    return x.coef == y.coef;
  }
  bool operator!=(const FormalPowerSeries& x) const { return !(*this == x); }

  FormalPowerSeries operator+() const { return *this; }
  FormalPowerSeries operator-() const {
    FormalPowerSeries res = *this;
    for (T& e : res.coef) e = -e;
    return res;
  }

  FormalPowerSeries operator+(const FormalPowerSeries& x) const {
    return FormalPowerSeries(*this) += x;
  }
  FormalPowerSeries operator-(const FormalPowerSeries& x) const {
    return FormalPowerSeries(*this) -= x;
  }
  FormalPowerSeries operator*(const T x) const {
    return FormalPowerSeries(*this) *= x;
  }
  FormalPowerSeries operator*(const FormalPowerSeries& x) const {
    return FormalPowerSeries(*this) *= x;
  }
  FormalPowerSeries operator/(const T x) const {
    return FormalPowerSeries(*this) /= x;
  }
  FormalPowerSeries operator/(const FormalPowerSeries& x) const {
    return FormalPowerSeries(*this) /= x;
  }
  FormalPowerSeries operator%(const FormalPowerSeries& x) const {
    return FormalPowerSeries(*this) %= x;
  }
  FormalPowerSeries operator<<(const int n) const {
    return FormalPowerSeries(*this) <<= n;
  }
  FormalPowerSeries operator>>(const int n) const {
    return FormalPowerSeries(*this) >>= n;
  }

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

  FormalPowerSeries exp(const int deg) const {
    assert(coef[0] == 0);
    const int n = coef.size();
    const FormalPowerSeries one{1};
    FormalPowerSeries res = one;
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FormalPowerSeries(coef.begin(),
                               std::next(coef.begin(), std::min(n, i << 1)))
             - res.log((i << 1) - 1) + one;
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }
  FormalPowerSeries exp() const { return exp(degree()); }

  FormalPowerSeries inv(const int deg) const {
    assert(coef[0] != 0);
    const int n = coef.size();
    FormalPowerSeries res{static_cast<T>(1) / coef[0]};
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FormalPowerSeries(
          coef.begin(), std::next(coef.begin(), std::min(n, i << 1)));
      res.coef.resize(i << 1);
    }
    res.resize(deg);
    return res;
  }
  FormalPowerSeries inv() const { return inv(degree()); }

  FormalPowerSeries log(const int deg) const {
    assert(coef[0] == 1);
    FormalPowerSeries integrand = differential() * inv(deg - 1);
    integrand.resize(deg);
    for (int i = deg; i > 0; --i) {
      integrand[i] = integrand[i - 1] / i;
    }
    integrand[0] = 0;
    return integrand;
  }
  FormalPowerSeries log() const { return log(degree()); }

  FormalPowerSeries pow(long long exponent, const int deg) const {
    const int n = coef.size();
    if (exponent == 0) {
      FormalPowerSeries res(deg);
      if (deg != -1) res[0] = 1;
      return res;
    }
    assert(deg >= 0);
    for (int i = 0; i < n; ++i) {
      if (coef[i] == 0) continue;
      if (i > deg / exponent) break;
      const long long shift = exponent * i;
      T tmp = 1, base = coef[i];
      for (long long e = exponent; e > 0; e >>= 1) {
        if (e & 1) tmp *= base;
        base *= base;
      }
      const FormalPowerSeries res = ((*this >> i) / coef[i]).log(deg - shift);
      return ((res * exponent).exp(deg - shift) * tmp) << shift;
    }
    return FormalPowerSeries(deg);
  }
  FormalPowerSeries pow(const long long exponent) const {
    return pow(exponent, degree());
  }

  FormalPowerSeries mod_pow(long long exponent,
                            const FormalPowerSeries& md) const {
    const int deg = md.degree() - 1;
    if (deg < 0) return FormalPowerSeries(-1);
    const FormalPowerSeries inv_rev_md =
        FormalPowerSeries(md.coef.rbegin(), md.coef.rend()).inv();
    const auto mod_mult = [&md, &inv_rev_md, deg](
        FormalPowerSeries* multiplicand, const FormalPowerSeries& multiplier)
        -> void {
      *multiplicand *= multiplier;
      if (deg < multiplicand->degree()) {
        const int n = multiplicand->degree() - deg;
        const FormalPowerSeries quotient =
            FormalPowerSeries(multiplicand->coef.rbegin(),
                              std::next(multiplicand->coef.rbegin(), n))
            * FormalPowerSeries(
                  inv_rev_md.coef.begin(),
                  std::next(inv_rev_md.coef.begin(), std::min(deg + 2, n)));
        *multiplicand -=
            FormalPowerSeries(std::prev(quotient.coef.rend(), n),
                              quotient.coef.rend()) * md;
        multiplicand->resize(deg);
      }
      multiplicand->shrink();
    };
    FormalPowerSeries res{1}, base = *this;
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) mod_mult(&res, base);
      mod_mult(&base, base);
    }
    return res;
  }

  FormalPowerSeries sqrt(const int deg) const {
    const int n = coef.size();
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
    if (!get_sqrt()(coef.front(), &s)) return FormalPowerSeries(-1);
    FormalPowerSeries res{s};
    const T half = static_cast<T>(1) / 2;
    for (int i = 1; i <= deg; i <<= 1) {
      res = (FormalPowerSeries(coef.begin(),
                               std::next(coef.begin(), std::min(n, i << 1)))
             * res.inv((i << 1) - 1) + res) * half;
    }
    res.resize(deg);
    return res;
  }
  FormalPowerSeries sqrt() const { return sqrt(degree()); }

  FormalPowerSeries translate(const T c) const {
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
      g[i] = coef[i] * fact[i];
    }
    std::reverse(g.begin(), g.end());
    T pow_c = 1;
    for (int i = 0; i < n; ++i) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    const std::vector<T> conv = get_mult()(g, ex);
    FormalPowerSeries res(n - 1);
    for (int i = 0; i < n; ++i) {
      res[i] = conv[n - 1 - i] * inv_fact[i];
    }
    return res;
  }

 private:
  static Mult& get_mult() {
    static Mult mult = [](const std::vector<T>& a, const std::vector<T>& b)
        -> std::vector<T> {
      const int n = a.size(), m = b.size();
      std::vector<T> res(n + m - 1, 0);
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          res[i + j] += a[i] * b[j];
        }
      }
      return res;
    };
    return mult;
  }
  static Sqrt& get_sqrt() {
    static Sqrt sqrt = [](const T&, T*) -> bool { return false; };
    return sqrt;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_FORMAL_POWER_SERIES_HPP_
