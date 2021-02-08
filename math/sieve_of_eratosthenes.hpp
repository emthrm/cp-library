#pragma once
#include <vector>

std::vector<bool> sieve_of_eratosthenes(int val) {
  std::vector<bool> res(val + 1, true);
  res[0] = false;
  if (val >= 1) res[1] = false;
  for (int i = 2; i * i <= val; ++i) {
    if (res[i]) {
      for (int j = i * i; j <= val; j += i) res[j] = false;
    }
  }
  return res;
}
