#pragma once
#include <ctime>

struct Xor128 {
  Xor128() : x(123456789), y(362436069), z(521288629), w(std::time(nullptr)) {}
  int rand() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  }
  int rand(const int ub) {
    const int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(const int lb, const int ub) { return lb + rand(ub - lb); }
  long long randll() {
    return (static_cast<unsigned long long>(rand()) << 32) | rand();
  }
  long long randll(const long long ub) {
    const long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(const long long lb, const long long ub) {
    return lb + randll(ub - lb);
  }
private:
  unsigned int x, y, z, w;
} xor128;
