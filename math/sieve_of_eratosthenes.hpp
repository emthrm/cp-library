#pragma once
#include <vector>

std::vector<bool> sieve_of_eratosthenes(int n) {
  std::vector<bool> res(n + 1, true);
  res[0] = false;
  if (n >= 1) res[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (res[i]) {
      for (int j = i * i; j <= n; j += i) res[j] = false;
    }
  }
  return res;
}
