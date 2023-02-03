#ifndef EMTHRM_MATH_POLYNOMIAL_HPP_
#define EMTHRM_MATH_POLYNOMIAL_HPP_

#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <utility>
#include <vector>

namespace emthrm {

template <typename T>
struct Polynomial {
  std::vector<T> coef;

  explicit Polynomial(const int deg = 0) : coef(deg + 1, 0) {}
  explicit Polynomial(const std::vector<T>& coef) : coef(coef) {}
  Polynomial(const std::initializer_list<T> init)
      : coef(init.begin(), init.end()) {}
  template <typename InputIter>
  explicit Polynomial(const InputIter first, const InputIter last)
      : coef(first, last) {}

  inline const T& operator[](const int term) const { return coef[term]; }
  inline T& operator[](const int term) { return coef[term]; }

  using Mult = std::function<std::vector<T>(const std::vector<T>&,
                                            const std::vector<T>&)>;
  static void set_mult(const Mult mult) { get_mult() = mult; }

  void resize(const int deg) { coef.resize(deg + 1, 0); }
  void shrink() {
    while (coef.size() > 1 && coef.back() == 0) coef.pop_back();
  }
  int degree() const { return std::ssize(coef) - 1; }

  Polynomial& operator=(const std::vector<T>& coef_) {
    coef = coef_;
    return *this;
  }
  Polynomial& operator=(const Polynomial& x) = default;

  Polynomial& operator+=(const Polynomial& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] += x[i];
    }
    return *this;
  }
  Polynomial& operator-=(const Polynomial& x) {
    const int deg_x = x.degree();
    if (deg_x > degree()) resize(deg_x);
    for (int i = 0; i <= deg_x; ++i) {
      coef[i] -= x[i];
    }
    return *this;
  }
  Polynomial& operator*=(const T x) {
    for (T& e : coef) e *= x;
    return *this;
  }
  Polynomial& operator*=(const Polynomial& x) {
    return *this = get_mult()(coef, x.coef);
  }
  Polynomial& operator/=(const T x) {
    assert(x != 0);
    return *this *= static_cast<T>(1) / x;
  }
  std::pair<Polynomial, Polynomial> divide(Polynomial x) const {
    x.shrink();
    Polynomial rem = *this;
    const int n = rem.degree(), m = x.degree(), deg = n - m;
    if (deg < 0) return {Polynomial{0}, rem};
    Polynomial quo(deg);
    for (int i = 0; i <= deg; ++i) {
      quo[deg - i] = rem[n - i] / x[m];
      for (int j = 0; j <= m; ++j) {
        rem[n - i - j] -= x[m - j] * quo[deg - i];
      }
    }
    rem.resize(deg);
    return {quo, rem};
  }
  Polynomial& operator/=(const Polynomial& x) {
    return *this = divide(x).first;
  }
  Polynomial& operator%=(const Polynomial& x) {
    return *this = divide(x).second;
  }
  Polynomial& operator<<=(const int n) {
    coef.insert(coef.begin(), n, 0);
    return *this;
  }

  bool operator==(Polynomial x) const {
    x.shrink();
    Polynomial y = *this;
    y.shrink();
    return x.coef == y.coef;
  }
  bool operator!=(const Polynomial& x) const { return !(*this == x); }

  Polynomial operator+() const { return *this; }
  Polynomial operator-() const {
    Polynomial res = *this;
    for (T& e : res.coef) e = -e;
    return res;
  }

  Polynomial operator+(const Polynomial& x) const {
    return Polynomial(*this) += x;
  }
  Polynomial operator-(const Polynomial& x) const {
    return Polynomial(*this) -= x;
  }
  Polynomial operator*(const T x) const {
    return Polynomial(*this) *= x;
  }
  Polynomial operator*(const Polynomial& x) const {
    return Polynomial(*this) *= x;
  }
  Polynomial operator/(const T x) const { return Polynomial(*this) /= x; }
  Polynomial operator/(const Polynomial& x) const {
    return Polynomial(*this) /= x;
  }
  Polynomial operator%(const Polynomial& x) const {
    return Polynomial(*this) %= x;
  }
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
      g[i] = coef[i] * fact[i];
    }
    std::reverse(g.begin(), g.end());
    T pow_c = 1;
    for (int i = 0; i < n; ++i) {
      ex[i] = pow_c * inv_fact[i];
      pow_c *= c;
    }
    const std::vector<T> conv = get_mult()(g, ex);
    Polynomial res(n - 1);
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
};

}  // namespace emthrm

#endif  // EMTHRM_MATH_POLYNOMIAL_HPP_
