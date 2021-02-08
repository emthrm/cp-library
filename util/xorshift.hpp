#pragma once
#include <ctime>

struct Xor128 {
  int rand() {
    unsigned t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  long long randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<long long>(res | rand());
  }
  long long randll(long long ub) {
    long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(long long lb, long long ub) { return lb + randll(ub - lb); }
private:
  unsigned x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned>(std::time(nullptr));
} xor128;
