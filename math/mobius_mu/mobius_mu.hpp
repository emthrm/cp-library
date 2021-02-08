/**
 * @brief メビウス関数
 * @docs docs/math/mobius_mu/mobius_mu.md
 */

int mobius_mu(long long val) {
  int cnt = 0;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) {
      val /= i;
      if (val % i == 0) return 0;
      ++cnt;
    }
  }
  if (val > 1) ++cnt;
  return cnt & 1 ? -1 : 1;
}
