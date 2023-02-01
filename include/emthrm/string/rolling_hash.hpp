#ifndef EMTHRM_STRING_ROLLING_HASH_HPP_
#define EMTHRM_STRING_ROLLING_HASH_HPP_

#include <cassert>
#include <cstdint>
#include <random>
#include <vector>

namespace emthrm {

template <typename T = char>
struct RollingHash {
  std::vector<T> str;

  template <typename U>
  explicit RollingHash(const U& str_, const std::int64_t base = generate_base())
      : base(base), hashes({0}), powers({1}) {
    const int n = str_.size();
    str.reserve(n);
    hashes.reserve(n + 1);
    powers.reserve(n + 1);
    for (const auto ch : str_) add(ch);
  }

  void add(const T ch) {
    assert(0 <= ch && ch < MOD);
    str.emplace_back(ch);
    const std::int64_t h = mul(hashes.back(), base) + ch;
    hashes.emplace_back(h >= MOD ? h - MOD : h);
    const std::int64_t p = mul(powers.back(), base);
    powers.emplace_back(p);
  }

  std::int64_t get(const int left, const int right) const {
    const std::int64_t res =
        hashes[right] - mul(hashes[left], powers[right - left]);
    return res < 0 ? res + MOD : res;
  }

 private:
  static constexpr int MOD_WIDTH = 61;
  static constexpr std::int64_t MOD = (INT64_C(1) << MOD_WIDTH) - 1;

  const std::int64_t base;
  std::vector<std::int64_t> hashes, powers;

  static std::int64_t generate_base() {
    static std::mt19937_64 engine(std::random_device {} ());
    static std::uniform_int_distribution<std::int64_t> dist(0, MOD - 1);
    return dist(engine);
  }

  static std::int64_t mul(const std::int64_t a, const std::int64_t b) {
    const std::int64_t au = a >> 31, ad = a & ((UINT32_C(1) << 31) - 1);
    const std::int32_t bu = b >> 31, bd = b & ((UINT32_C(1) << 31) - 1);
    const std::int64_t mid = au * bd + ad * bu;
    std::int64_t res = au * bu * 2 + ad * bd + (mid >> 30)
                       + ((mid & ((UINT32_C(1) << 30) - 1)) << 31);
    res = (res >> MOD_WIDTH) + (res & MOD);
    return res >= MOD ? res - MOD : res;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_STRING_ROLLING_HASH_HPP_
