#pragma once
#include <algorithm>

long long __lcm(long long a, long long b) { return a / std::__gcd(a, b) * b; }
