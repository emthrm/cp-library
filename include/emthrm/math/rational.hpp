#ifndef EMTHRM_MATH_RATIONAL_HPP_
#define EMTHRM_MATH_RATIONAL_HPP_

// #include <cassert>
#include <limits>
#if __cplusplus >= 201703L
# include <numeric>
#else
# include <algorithm>
#endif  // __cplusplus >= 201703L
#include <ostream>

namespace emthrm {

template <typename T = long long>
struct Rational {
  T num, den;

  Rational() : num(0), den(1) {}
  Rational(const T num, const T den = 1) : num(num), den(den) {
    // assert(den != 0);
    reduce();
  }

  template <typename Real = long double>
  Real to_real() const { return static_cast<Real>(num) / den; }

  Rational& operator+=(const Rational& x) {
#if __cplusplus >= 201703L
    const T g = std::gcd(den, x.den);
#else
    const T g = std::__gcd(den, x.den);
#endif  // __cplusplus >= 201703L
    num = num * (x.den / g) + x.num * (den / g);
    den *= x.den / g;
    reduce();
    return *this;
  }
  Rational& operator-=(const Rational& x) { return *this += -x; }

  Rational& operator*=(const Rational& x) {
#if __cplusplus >= 201703L
    const T g1 = std::gcd(num, x.den), g2 = std::gcd(den, x.num);
#else
    const T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);
#endif  // __cplusplus >= 201703L
    num = (num / g1) * (x.num / g2);
    den = (den / g2) * (x.den / g1);
    reduce();
    return *this;
  }
  Rational& operator/=(const Rational& x) {
    return *this *= Rational(x.den, x.num);
  }

  bool operator==(const Rational& x) const {
    return num == x.num && den == x.den;
  }
  bool operator!=(const Rational& x) const { return !(*this == x); }
  bool operator<(const Rational& x) const { return (x - *this).num > 0; }
  bool operator<=(const Rational& x) const { return !(x < *this); }
  bool operator>(const Rational& x) const { return x < *this; }
  bool operator>=(const Rational& x) const { return !(*this < x); }

  Rational& operator++() {
    if ((num += den) == 0) den = 1;
    return *this;
  }
  Rational operator++(int) {
    const Rational res = *this;
    ++*this;
    return res;
  }
  Rational& operator--() {
    if ((num -= den) == 0) den = 1;
    return *this;
  }
  Rational operator--(int) {
    const Rational res = *this;
    --*this;
    return res;
  }

  Rational operator+() const { return *this; }
  Rational operator-() const { return Rational(-num, den); }

  Rational operator+(const Rational& x) const { return Rational(*this) += x; }
  Rational operator-(const Rational& x) const { return Rational(*this) -= x; }
  Rational operator*(const Rational& x) const { return Rational(*this) *= x; }
  Rational operator/(const Rational& x) const { return Rational(*this) /= x; }

  friend std::ostream& operator<<(std::ostream& os, const Rational& x) {
    if (x.den == 1) return os << x.num;
    return os << x.num << '/' << x.den;
  }

 private:
  void reduce() {
#if __cplusplus >= 201703L
    const T g = std::gcd(num, den);
#else
    const T g = std::__gcd(num, den);
#endif  // __cplusplus >= 201703L
    num /= g;
    den /= g;
    if (den < 0) {
      num = -num;
      den = -den;
    }
  }
};

}  // namespace emthrm

namespace std {

template <typename T>
emthrm::Rational<T> abs(emthrm::Rational<T> x) {
  if (x.num < 0) x.num = -x.num;
  return x;
}

template <typename T>
emthrm::Rational<T> max(const emthrm::Rational<T>& a,
                        const emthrm::Rational<T>& b) {
  return a < b ? b : a;
}

template <typename T>
emthrm::Rational<T> min(const emthrm::Rational<T>& a,
                        const emthrm::Rational<T>& b) {
  return a < b ? a : b;
}

template <typename T> struct numeric_limits<emthrm::Rational<T>> {
  static constexpr emthrm::Rational<T> max() {
    return std::numeric_limits<T>::max();
  }
  static constexpr emthrm::Rational<T> lowest() {
    return std::numeric_limits<T>::lowest();
  }
};

}  // namespace std

#endif  // EMTHRM_MATH_RATIONAL_HPP_
