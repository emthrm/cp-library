#ifndef EMTHRM_MATH_MODINT_HPP_
#define EMTHRM_MATH_MODINT_HPP_

#ifndef ARBITRARY_MODINT
# include <cassert>
#endif
#include <compare>
#include <iostream>
// #include <numeric>
#include <utility>
#include <vector>

namespace emthrm {

#ifndef ARBITRARY_MODINT
template <unsigned int M>
struct MInt {
  unsigned int v;

  constexpr MInt() : v(0) {}
  constexpr MInt(const long long x) : v(x >= 0 ? x % M : x % M + M) {}
  static constexpr MInt raw(const int x) {
    MInt x_;
    x_.v = x;
    return x_;
  }

  static constexpr int get_mod() { return M; }
  static constexpr void set_mod(const int divisor) {
    assert(std::cmp_equal(divisor, M));
  }

  static void init(const int x) {
    inv<true>(x);
    fact(x);
    fact_inv(x);
  }

  template <bool MEMOIZES = false>
  static MInt inv(const int n) {
    // assert(0 <= n && n < M && std::gcd(n, M) == 1);
    static std::vector<MInt> inverse{0, 1};
    const int prev = inverse.size();
    if (n < prev) return inverse[n];
    if constexpr (MEMOIZES) {
      // "n!" and "M" must be disjoint.
      inverse.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        inverse[i] = -inverse[M % i] * raw(M / i);
      }
      return inverse[n];
    }
    int u = 1, v = 0;
    for (unsigned int a = n, b = M; b;) {
      const unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }

  static MInt fact(const int n) {
    static std::vector<MInt> factorial{1};
    if (const int prev = factorial.size(); n >= prev) {
      factorial.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
      }
    }
    return factorial[n];
  }

  static MInt fact_inv(const int n) {
    static std::vector<MInt> f_inv{1};
    if (const int prev = f_inv.size(); n >= prev) {
      f_inv.resize(n + 1);
      f_inv[n] = inv(fact(n).v);
      for (int i = n; i > prev; --i) {
        f_inv[i - 1] = f_inv[i] * i;
      }
    }
    return f_inv[n];
  }

  static MInt nCk(const int n, const int k) {
    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();
    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :
                                  fact_inv(n - k) * fact_inv(k));
  }
  static MInt nPk(const int n, const int k) {
    return n < 0 || n < k || k < 0 ? MInt() : fact(n) * fact_inv(n - k);
  }
  static MInt nHk(const int n, const int k) {
    return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));
  }

  static MInt large_nCk(long long n, const int k) {
    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();
    inv<true>(k);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) {
      res *= inv(i) * n--;
    }
    return res;
  }

  constexpr MInt pow(long long exponent) const {
    MInt res = 1, tmp = *this;
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }

  constexpr MInt& operator+=(const MInt& x) {
    if ((v += x.v) >= M) v -= M;
    return *this;
  }
  constexpr MInt& operator-=(const MInt& x) {
    if ((v += M - x.v) >= M) v -= M;
    return *this;
  }
  constexpr MInt& operator*=(const MInt& x) {
    v = (unsigned long long){v} * x.v % M;
    return *this;
  }
  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }

  constexpr auto operator<=>(const MInt& x) const = default;

  constexpr MInt& operator++() {
    if (++v == M) [[unlikely]] v = 0;
    return *this;
  }
  constexpr MInt operator++(int) {
    const MInt res = *this;
    ++*this;
    return res;
  }
  constexpr MInt& operator--() {
    v = (v == 0 ? M - 1 : v - 1);
    return *this;
  }
  constexpr MInt operator--(int) {
    const MInt res = *this;
    --*this;
    return res;
  }

  constexpr MInt operator+() const { return *this; }
  constexpr MInt operator-() const { return raw(v ? M - v : 0); }

  constexpr MInt operator+(const MInt& x) const { return MInt(*this) += x; }
  constexpr MInt operator-(const MInt& x) const { return MInt(*this) -= x; }
  constexpr MInt operator*(const MInt& x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }

  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {
    return os << x.v;
  }
  friend std::istream& operator>>(std::istream& is, MInt& x) {
    long long v;
    is >> v;
    x = MInt(v);
    return is;
  }
};
#else  // ARBITRARY_MODINT
template <int ID>
struct MInt {
  unsigned int v;

  constexpr MInt() : v(0) {}
  MInt(const long long x) : v(x >= 0 ? x % mod() : x % mod() + mod()) {}
  static constexpr MInt raw(const int x) {
    MInt x_;
    x_.v = x;
    return x_;
  }

  static int get_mod() { return mod(); }
  static void set_mod(const unsigned int divisor) { mod() = divisor; }

  static void init(const int x) {
    inv<true>(x);
    fact(x);
    fact_inv(x);
  }

  template <bool MEMOIZES = false>
  static MInt inv(const int n) {
    // assert(0 <= n && n < mod() && std::gcd(x, mod()) == 1);
    static std::vector<MInt> inverse{0, 1};
    const int prev = inverse.size();
    if (n < prev) return inverse[n];
    if constexpr (MEMOIZES) {
      // "n!" and "M" must be disjoint.
      inverse.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        inverse[i] = -inverse[mod() % i] * raw(mod() / i);
      }
      return inverse[n];
    }
    int u = 1, v = 0;
    for (unsigned int a = n, b = mod(); b;) {
      const unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }

  static MInt fact(const int n) {
    static std::vector<MInt> factorial{1};
    if (const int prev = factorial.size(); n >= prev) {
      factorial.resize(n + 1);
      for (int i = prev; i <= n; ++i) {
        factorial[i] = factorial[i - 1] * i;
      }
    }
    return factorial[n];
  }

  static MInt fact_inv(const int n) {
    static std::vector<MInt> f_inv{1};
    if (const int prev = f_inv.size(); n >= prev) {
      f_inv.resize(n + 1);
      f_inv[n] = inv(fact(n).v);
      for (int i = n; i > prev; --i) {
        f_inv[i - 1] = f_inv[i] * i;
      }
    }
    return f_inv[n];
  }

  static MInt nCk(const int n, const int k) {
    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();
    return fact(n) * (n - k < k ? fact_inv(k) * fact_inv(n - k) :
                                  fact_inv(n - k) * fact_inv(k));
  }
  static MInt nPk(const int n, const int k) {
    return n < 0 || n < k || k < 0 ? MInt() : fact(n) * fact_inv(n - k);
  }
  static MInt nHk(const int n, const int k) {
    return n < 0 || k < 0 ? MInt() : (k == 0 ? 1 : nCk(n + k - 1, k));
  }

  static MInt large_nCk(long long n, const int k) {
    if (n < 0 || n < k || k < 0) [[unlikely]] return MInt();
    inv<true>(k);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) {
      res *= inv(i) * n--;
    }
    return res;
  }

  MInt pow(long long exponent) const {
    MInt res = 1, tmp = *this;
    for (; exponent > 0; exponent >>= 1) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
    }
    return res;
  }

  MInt& operator+=(const MInt& x) {
    if ((v += x.v) >= mod()) v -= mod();
    return *this;
  }
  MInt& operator-=(const MInt& x) {
    if ((v += mod() - x.v) >= mod()) v -= mod();
    return *this;
  }
  MInt& operator*=(const MInt& x) {
    v = (unsigned long long){v} * x.v % mod();
    return *this;
    }
  MInt& operator/=(const MInt& x) { return *this *= inv(x.v); }

  auto operator<=>(const MInt& x) const = default;

  MInt& operator++() {
    if (++v == mod()) [[unlikely]] v = 0;
    return *this;
  }
  MInt operator++(int) {
    const MInt res = *this;
    ++*this;
    return res;
  }
  MInt& operator--() {
    v = (v == 0 ? mod() - 1 : v - 1);
    return *this;
  }
  MInt operator--(int) {
    const MInt res = *this;
    --*this;
    return res;
  }

  MInt operator+() const { return *this; }
  MInt operator-() const { return raw(v ? mod() - v : 0); }

  MInt operator+(const MInt& x) const { return MInt(*this) += x; }
  MInt operator-(const MInt& x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt& x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt& x) const { return MInt(*this) /= x; }

  friend std::ostream& operator<<(std::ostream& os, const MInt& x) {
    return os << x.v;
  }
  friend std::istream& operator>>(std::istream& is, MInt& x) {
    long long v;
    is >> v;
    x = MInt(v);
    return is;
  }

 private:
  static unsigned int& mod() {
    static unsigned int divisor = 0;
    return divisor;
  }
};
#endif  // ARBITRARY_MODINT

}  // namespace emthrm

#endif  // EMTHRM_MATH_MODINT_HPP_
