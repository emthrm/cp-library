#pragma once
#include <algorithm>

long long __lcm(const long long a, const long long b) {
  return a / std::__gcd(a, b) * b;
}
