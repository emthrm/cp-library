#pragma once

bool is_prime(long long val) {
  if (val <= 1) return false;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) return false;
  }
  return true;
}
