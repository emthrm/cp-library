#ifndef EMTHRM_STRING_WILDCARD_PATTERN_MATCHING_HPP_
#define EMTHRM_STRING_WILDCARD_PATTERN_MATCHING_HPP_

#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "emthrm/math/convolution/number_theoretic_transform.hpp"

namespace emthrm {

template <typename T = std::string>
requires requires { typename T::value_type; }
std::vector<int> wildcard_pattern_matching(
    const T& text, const T& pattern, const typename T::value_type wildcard) {
  if (text.size() < pattern.size()) [[unlikely]] return {};
  const auto generate = [wildcard](const T& str)
      -> std::tuple<std::vector<long long>,
                    std::vector<long long>,
                    std::vector<long long>> {
    using Char = T::value_type;
    static std::map<Char, int> characters{{wildcard, 0}};
    std::vector<long long> v1(str.size());
    std::ranges::transform(
        str, v1.begin(),
        [](const Char c) -> int {
          if (const auto it = characters.find(c); it != characters.end()) {
            return it->second;
          }
          const int next_index = characters.size();
          assert(characters.emplace(c, next_index).second);
          return next_index;
        });
    std::vector<long long> v2 = v1;
    std::ranges::transform(
        v2, v2.begin(),
        [](const long long ch) -> long long { return ch * ch; });
    std::vector<long long> v3 = v1;
    std::ranges::transform(
        v3, v3.begin(),
        [](const long long ch) -> long long { return ch * ch * ch; });
    return {v1, v2, v3};
  };
  const auto [t1, t2, t3] = generate(text);
  auto [p1, p2, p3] = generate(pattern);
  std::ranges::reverse(p1);
  std::ranges::reverse(p2);
  std::ranges::reverse(p3);
  const int l = text.size() - pattern.size() + 1;
  std::vector<int> ans(l);
  std::iota(ans.begin(), ans.end(), 0);
  const auto check = [&pattern, &t1, &t2, &t3, &p1, &p2, &p3, l, &ans]
      <unsigned int M>(const NumberTheoreticTransform<M>& ntt) -> void {
    using ModInt = NumberTheoreticTransform<M>::ModInt;
    static const int offset = pattern.size() - 1;
    const std::vector<ModInt> t3p1 = ntt.convolution(t3, p1);
    const std::vector<ModInt> t2p2 = ntt.convolution(t2, p2);
    const std::vector<ModInt> t1p3 = ntt.convolution(t1, p3);
    std::vector<int> next_ans;
    next_ans.reserve(ans.size());
    for (const int i : ans) {
      const ModInt wmatch = t3p1[i + offset] - t2p2[i + offset] * ModInt::raw(2)
                            + t1p3[i + offset];
      if (wmatch == 0) next_ans.emplace_back(i);
    }
    ans.swap(next_ans);
  };
  check(NumberTheoreticTransform<998244353>());
  check(NumberTheoreticTransform<1004535809>());
  check(NumberTheoreticTransform<1007681537>());
  return ans;
}

}  // namespace emthrm

#endif  // EMTHRM_STRING_WILDCARD_PATTERN_MATCHING_HPP_
