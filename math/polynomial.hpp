#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>

template <typename T>
struct Polynomial {
  using MUL = std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;
  std::vector<T> co;
  Polynomial(int deg = 0) : co(deg + 1, 0) {}
  Polynomial(const std::vector<T> &co) : co(co) {}
  Polynomial(std::initializer_list<T> init) : co(init.begin(), init.end()) {}
  template <typename InputIter> Polynomial(InputIter first, InputIter last) : co(first, last) {}
  inline const T &operator[](int term) const { return co[term]; }
  inline T &operator[](int term) { return co[term]; }
  static void set_mul(MUL mul) { get_mul() = mul; }
  void shrink() { while (co.size() > 1 && co.back() == 0) co.pop_back(); }
  int degree() const { return static_cast<int>(co.size()) - 1; }
  Polynomial &operator=(const std::vector<T> &new_co) {
    co.resize(new_co.size());
    std::copy(new_co.begin(), new_co.end(), co.begin());
    return *this;
  }
  Polynomial &operator=(const Polynomial &x) {
    co.resize(x.co.size());
    std::copy(x.co.begin(), x.co.end(), co.begin());
    return *this;
  }
  Polynomial &operator+=(const Polynomial &x) {
    int n = x.co.size();
    if (n > co.size()) co.resize(n, 0);
    for (int i = 0; i < n; ++i) co[i] += x.co[i];
    return *this;
  }
  Polynomial &operator-=(const Polynomial &x) {
    int n = x.co.size();
    if (n > co.size()) co.resize(n, 0);
    for (int i = 0; i < n; ++i) co[i] -= x.co[i];
    return *this;
  }
  Polynomial &operator*=(T x) {
    for (T &e : co) e *= x;
    return *this;
  }
  Polynomial &operator*=(const Polynomial &x) { return *this = get_mul()(co, x.co); }
  Polynomial &operator/=(T x) {
    assert(x != 0);
    T inv_x = static_cast<T>(1) / x;
    for (T &e : co) e *= inv_x;
    return *this;
  }
  std::pair<Polynomial, Polynomial> divide(const Polynomial &x) const {
    Polynomial p(x);
    p.shrink();
    int n = co.size(), m = p.co.size(), sz = n - m + 1;
    if (sz <= 0) return {Polynomial({0}), *this};
    Polynomial quo(sz - 1), rem = *this;
    for (int i = 0; i < sz; ++i) {
      quo.co[sz - 1 - i] = rem.co[n - 1 - i] / p.co.back();
      for (int j = 0; j < m; ++j) rem[n - 1 - i - j] -= p.co[m - 1 - j] * quo.co[sz - 1 - i];
    }
    rem.co.resize(sz);
    return {quo, rem};
  }
  Polynomial &operator/=(const Polynomial &x) { return *this = divide(x).first; }
  Polynomial &operator%=(const Polynomial &x) { return *this = divide(x).second; };
  Polynomial &operator<<=(int n) {
    co.insert(co.begin(), n, 0);
    return *this;
  }
  bool operator==(const Polynomial &x) const {
    Polynomial a(*this), b(x);
    a.shrink(); b.shrink();
    int n = a.co.size();
    if (n != b.co.size()) return false;
    for (int i = 0; i < n; ++i) if (a.co[i] != b.co[i]) return false;
    return true;
  }
  bool operator!=(const Polynomial &x) const { return !(*this == x); }
  Polynomial operator+() const { return *this; }
  Polynomial operator-() const {
    Polynomial res(*this);
    for (T &e : res.co) e = -e;
    return res;
  }
  Polynomial operator+(const Polynomial &x) const { return Polynomial(*this) += x; }
  Polynomial operator-(const Polynomial &x) const { return Polynomial(*this) -= x; }
  Polynomial operator*(T x) const { return Polynomial(*this) *= x; }
  Polynomial operator*(const Polynomial &x) const { return Polynomial(*this) *= x; }
  Polynomial operator/(T x) const { return Polynomial(*this) /= x; }
  Polynomial operator/(const Polynomial &x) const { return Polynomial(*this) /= x; }
  Polynomial operator%(const Polynomial &x) const { return Polynomial(*this) %= x; }
  Polynomial operator<<(int n) const { return Polynomial(*this) <<= n; }
  T horner(T x) const {
    T res = static_cast<T>(0);
    for (int i = static_cast<int>(co.size()) - 1; i >= 0; --i) (res *= x) += co[i];
    return res;
  }
  Polynomial differential() const {
    int n = co.size();
    assert(n >= 1);
    Polynomial res(n - 1);
    for (int i = 1; i < n; ++i) res.co[i - 1] = co[i] * i;
    return res;
  }
  Polynomial integral() const {
    int n = co.size();
    Polynomial res(n + 1);
    for (int i = 0; i < n; ++i) res[i + 1] = co[i] / (i + 1);
    return res;
  }
  Polynomial pow(int exponent) const {
    Polynomial res({1}), base = *this;
    while (exponent > 0) {
      if (exponent & 1) res *= base;
      base *= base;
      exponent >>= 1;
    }
    return res;
  }
  Polynomial translate(T c) const {
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
    Polynomial res(n - 1);
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
};
