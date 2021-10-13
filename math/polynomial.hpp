#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>

template <typename T>
struct Polynomial {
  std::vector<T> coef;

  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}
  explicit Polynomial(const std::vector<T>& coef) : coef(coef) {}
  Polynomial(std::initializer_list<T> init) : coef(init.begin(), init.end()) {}
  template <typename InputIter>
  explicit Polynomial(InputIter first, InputIter last) : coef(first, last) {}

  inline const T& operator[](int term) const { return coef[term]; }
  inline T& operator[](int term) { return coef[term]; }

  using MUL = std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>;
  static void set_mul(const MUL mul) { get_mul() = mul; }

  void shrink() {
    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();
  }
  int degree() const { return static_cast<int>(coef.size()) - 1; }

  Polynomial& operator=(const std::vector<T>& coef_) {
    coef = coef_;
    return *this;
  }
  Polynomial& operator=(const Polynomial& x) = default;

  Polynomial& operator+=(const Polynomial& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) coef.resize(deg_x + 1, 0);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] += x[i];
    }
    return *this;
  }
  Polynomial& operator-=(const Polynomial& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) coef.resize(deg_x + 1, 0);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] -= x[i];
    }
    return *this;
  }
  Polynomial& operator*=(const T x) {
    for (T& e : coef) e *= x;
    return *this;
  }
  Polynomial& operator*=(const Polynomial& x) { return *this = get_mul()(coef, x.coef); }
  Polynomial& operator/=(const T x) {
    assert(x != 0);
    const T inv_x = static_cast<T>(1) / x;
    for (T& e : coef) e *= inv_x;
    return *this;
  }
  std::pair<Polynomial, Polynomial> divide(const Polynomial& x) const {
    Polynomial p(x);
    p.shrink();
    const int n = degree(), m = p.degree(), deg = n - m;
    if (deg < 0) return {Polynomial{0}, *this};
    Polynomial quo(deg), rem(*this);
    for (int i = 0; i <= deg; ++i) {
      quo[deg - i] = rem[n - i] / p[m];
      for (int j = 0; j <= m; ++j) {
        rem[n - i - j] -= p[m - j] * quo[deg - i];
      }
    }
    rem.coef.resize(deg + 1);
    return {quo, rem};
  }
  Polynomial& operator/=(const Polynomial& x) { return *this = divide(x).first; }
  Polynomial& operator%=(const Polynomial& x) { return *this = divide(x).second; };
  Polynomial& operator<<=(const int n) {
    coef.insert(coef.begin(), n, 0);
    return *this;
  }

  bool operator==(const Polynomial& x) const {
    Polynomial a(*this), b(x);
    a.shrink();
    b.shrink();
    const int deg = a.degree();
    if (deg != b.degree()) return false;
    for (int i = 0; i <= deg; ++i) {
      if (a[i] != b[i]) return false;
    }
    return true;
  }
  bool operator!=(const Polynomial& x) const { return !(*this == x); }

  Polynomial operator+() const { return *this; }
  Polynomial operator-() const {
    Polynomial res(*this);
    for (T& e : res.coef) e = -e;
    return res;
  }

  Polynomial operator+(const Polynomial& x) const { return Polynomial(*this) += x; }
  Polynomial operator-(const Polynomial& x) const { return Polynomial(*this) -= x; }
  Polynomial operator*(const T x) const { return Polynomial(*this) *= x; }
  Polynomial operator*(const Polynomial& x) const { return Polynomial(*this) *= x; }
  Polynomial operator/(const T x) const { return Polynomial(*this) /= x; }
  Polynomial operator/(const Polynomial& x) const { return Polynomial(*this) /= x; }
  Polynomial operator%(const Polynomial& x) const { return Polynomial(*this) %= x; }
  Polynomial operator<<(const int n) const { return Polynomial(*this) <<= n; }

  T horner(const T x) const {
    T res = 0;
    for (int i = degree(); i >= 0; --i) {
      res = res * x + coef[i];
    }
    return res;
  }

  Polynomial differential() const {
    const int deg = degree();
    assert(deg >= 0);
    Polynomial res(std::max(deg - 1, 0));
    for (int i = 1; i <= deg; ++i) {
      res[i - 1] = coef[i] * i;
    }
    return res;
  }

  Polynomial pow(int exponent) const {
    Polynomial res{1}, base = *this;
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= base;
      base *= base;
    }
    return res;
  }

  Polynomial translate(const T c) const {
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
    Polynomial res(n - 1);
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
};
