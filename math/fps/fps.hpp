#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <vector>

template <typename T>
struct FPS {
  using MUL = std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;
  using SQR = std::function<bool(const T&, T&)>;
  std::vector<T> co;
  FPS(int deg = 0) : co(deg + 1, 0) {}
  FPS(const std::vector<T> &co) : co(co) {}
  FPS(std::initializer_list<T> init) : co(init.begin(), init.end()) {}
  template <typename InputIter> FPS(InputIter first, InputIter last) : co(first, last) {}
  inline const T &operator[](int term) const { return co[term]; }
  inline T &operator[](int term) { return co[term]; }
  static void set_mul(MUL mul) { get_mul() = mul; }
  static void set_sqr(SQR sqr) { get_sqr() = sqr; }
  void resize(int deg) { co.resize(deg + 1, 0); }
  void shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back(); }
  int degree() const { return static_cast<int>(co.size()) - 1; }
  FPS &operator=(const std::vector<T> &new_co) {
    co.resize(new_co.size());
    std::copy(new_co.begin(), new_co.end(), co.begin());
    return *this;
  }
  FPS &operator=(const FPS &x) {
    co.resize(x.co.size());
    std::copy(x.co.begin(), x.co.end(), co.begin());
    return *this;
  }
  FPS &operator+=(const FPS &x) {
    int n = x.co.size();
    if (n > co.size()) resize(n - 1);
    for (int i = 0; i < n; ++i) co[i] += x.co[i];
    return *this;
  }
  FPS &operator-=(const FPS &x) {
    int n = x.co.size();
    if (n > co.size()) resize(n - 1);
    for (int i = 0; i < n; ++i) co[i] -= x.co[i];
    return *this;
  }
  FPS &operator*=(T x) {
    for (T &e : co) e *= x;
    return *this;
  }
  FPS &operator*=(const FPS &x) { return *this = get_mul()(co, x.co); }
  FPS &operator/=(T x) {
    assert(x != 0);
    T inv_x = static_cast<T>(1) / x;
    for (T &e : co) e *= inv_x;
    return *this;
  }
  FPS &operator/=(const FPS &x) {
    int sz = x.co.size();
    if (sz > co.size()) return *this = FPS();
    int n = co.size() - sz + 1;
    FPS a(co.rbegin(), co.rbegin() + n), b(x.co.rbegin(), x.co.rbegin() + std::min(sz, n));
    b = b.inv(n - 1);
    a *= b;
    return *this = FPS(a.co.rend() - n, a.co.rend());
  }
  FPS &operator%=(const FPS &x) {
    *this -= *this / x * x;
    co.resize(static_cast<int>(x.co.size()) - 1);
    if (co.empty()) co = {0};
    return *this;
  }
  FPS &operator<<=(int n) {
    co.insert(co.begin(), n, 0);
    return *this;
  }
  FPS &operator>>=(int n) {
    if (co.size() < n) return *this = FPS();
    co.erase(co.begin(), co.begin() + n);
    return *this;
  }
  bool operator==(const FPS &x) const {
    FPS a(*this), b(x);
    a.shrink(); b.shrink();
    int n = a.co.size();
    if (n != b.co.size()) return false;
    for (int i = 0; i < n; ++i) if (a.co[i] != b.co[i]) return false;
    return true;
  }
  bool operator!=(const FPS &x) const { return !(*this == x); }
  FPS operator+() const { return *this; }
  FPS operator-() const {
    FPS res(*this);
    for (T &e : res.co) e = -e;
    return res;
  }
  FPS operator+(const FPS &x) const { return FPS(*this) += x; }
  FPS operator-(const FPS &x) const { return FPS(*this) -= x; }
  FPS operator*(T x) const { return FPS(*this) *= x; }
  FPS operator*(const FPS &x) const { return FPS(*this) *= x; }
  FPS operator/(T x) const { return FPS(*this) /= x; }
  FPS operator/(const FPS &x) const { return FPS(*this) /= x; }
  FPS operator%(const FPS &x) const { return FPS(*this) %= x; }
  FPS operator<<(int n) const { return FPS(*this) <<= n; }
  FPS operator>>(int n) const { return FPS(*this) >>= n; }
  T horner(T x) const {
    T res = 0;
    for (int i = static_cast<int>(co.size()) - 1; i >= 0; --i) (res *= x) += co[i];
    return res;
  }
  FPS differential() const {
    int n = co.size();
    assert(n >= 1);
    FPS res(n - 1);
    for (int i = 1; i < n; ++i) res.co[i - 1] = co[i] * i;
    return res;
  }
  FPS integral() const {
    int n = co.size();
    FPS res(n + 1);
    for (int i = 0; i < n; ++i) res[i + 1] = co[i] / (i + 1);
    return res;
  }
  FPS exp(int deg = -1) const {
    assert(co[0] == 0);
    int n = co.size();
    if (deg == -1) deg = n - 1;
    FPS one{1}, res = one;
    for (int i = 1; i <= deg; i <<= 1) {
      res *= FPS(co.begin(), co.begin() + std::min(n, i << 1)) - res.log((i << 1) - 1) + one;
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }
  FPS inv(int deg = -1) const {
    assert(co[0] != 0);
    int n = co.size();
    if (deg == -1) deg = n - 1;
    FPS res{static_cast<T>(1) / co[0]};
    for (int i = 1; i <= deg; i <<= 1) {
      res = res + res - res * res * FPS(co.begin(), co.begin() + std::min(n, i << 1));
      res.co.resize(i << 1);
    }
    res.co.resize(deg + 1);
    return res;
  }
  FPS log(int deg = -1) const {
    assert(co[0] == 1);
    if (deg == -1) deg = static_cast<int>(co.size()) - 1;
    FPS integrand = differential() * inv(deg - 1);
    integrand.co.resize(deg);
    return integrand.integral();
  }
  FPS pow(long long exponent, int deg = -1) const {
    int n = co.size();
    if (deg == -1) deg = n - 1;
    for (int i = 0; i < n; ++i) {
      if (co[i] != 0) {
        long long shift = exponent * i;
        if (shift > deg) break;
        T tmp = 1, base = co[i];
        long long e = exponent;
        while (e > 0) {
          if (e & 1) tmp *= base;
          base *= base;
          e >>= 1;
        }
        return ((((*this >> i) * (static_cast<T>(1) / co[i])).log(deg - shift) * static_cast<T>(exponent)).exp(deg - shift) * tmp) << shift;
      }
    }
    return FPS(deg);
  }
  FPS mod_pow(long long exponent, const FPS &md) const {
    FPS inv_rev_md = FPS(md.co.rbegin(), md.co.rend()).inv();
    int deg_of_md = md.co.size();
    auto mod_mul = [&](FPS &multiplicand, const FPS &multiplier) -> void {
      multiplicand *= multiplier;
      if (deg_of_md <= multiplicand.co.size()) {
        int n = multiplicand.co.size() - deg_of_md + 1;
        FPS quotient = FPS(multiplicand.co.rbegin(), multiplicand.co.rbegin() + n) * FPS(inv_rev_md.co.begin(), inv_rev_md.co.begin() + std::min(static_cast<int>(inv_rev_md.co.size()), n));
        multiplicand -= FPS(quotient.co.rend() - n, quotient.co.rend()) * md;
      }
      multiplicand.co.resize(deg_of_md - 1);
      if (multiplicand.co.empty()) multiplicand.co = {0};
    };
    FPS res{1}, base = *this;
    mod_mul(base, res);
    while (exponent > 0) {
      if (exponent & 1) mod_mul(res, base);
      mod_mul(base, base);
      exponent >>= 1;
    }
    return res;
  }
  FPS sqrt(int deg = -1) const {
    int n = co.size();
    if (deg == -1) deg = n - 1;
    if (co[0] == 0) {
      for (int i = 1; i < n; ++i) {
        if (co[i] == 0) continue;
        if (i & 1) return FPS(-1);
        int shift = i >> 1;
        if (deg < shift) break;
        FPS res = (*this >> i).sqrt(deg - shift);
        if (res.co.empty()) return FPS(-1);
        res <<= shift;
        res.resize(deg);
        return res;
      }
      return FPS(deg);
    }
    T s;
    if (!get_sqr()(co[0], s)) return FPS(-1);
    FPS res{s};
    T half = static_cast<T>(1) / 2;
    for (int i = 1; i <= deg; i <<= 1) {
      (res += FPS(co.begin(), co.begin() + std::min(n, i << 1)) * res.inv((i << 1) - 1)) *= half;
    }
    res.resize(deg);
    return res;
  }
  FPS translate(T c) const {
    int n = co.size();
    std::vector<T> fact(n, 1), inv_fact(n, 1);
    for (int i = 1; i < n; ++i) fact[i] = fact[i - 1] * i;
    inv_fact[n - 1] = static_cast<T>(1) / fact[n - 1];
    for (int i = n - 1; i > 0; --i) inv_fact[i - 1] = inv_fact[i] * i;
    std::vector<T> g(n), ex(n);
    for (int i = 0; i < n; ++i) g[n - 1 - i] = co[i] * fact[i];
    T pow_c = 1;
    for (int i = 0; i < n; ++i) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    std::vector<T> conv = get_mul()(g, ex);
    FPS res(n - 1);
    for (int i = 0; i < n; ++i) res[i] = conv[n - 1 - i] * inv_fact[i];
    return res;
  }
private:
  static MUL &get_mul() {
    static MUL mul = [](const std::vector<T> &a, const std::vector<T> &b) -> std::vector<T> {
      int n = a.size(), m = b.size();
      std::vector<T> res(n + m - 1, 0);
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
      return res;
    };
    return mul;
  }
  static SQR &get_sqr() {
    static SQR sqr = [](const T &a, T &res) -> bool { return false; };
    return sqr;
  }
};
