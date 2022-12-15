#ifndef EMTHRM_MATH_MOD_POW_HPP_
#define EMTHRM_MATH_MOD_POW_HPP_


namespace emthrm {

long long mod_pow(long long x, long long n, const int m) {
  if ((x %= m) < 0) x += m;
  long long res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = (res * x) % m;
    x = (x * x) % m;
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_MATH_MOD_POW_HPP_
