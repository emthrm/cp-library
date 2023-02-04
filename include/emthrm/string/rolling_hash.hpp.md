---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash.test.cpp
    title: "\u6587\u5B57\u5217/rolling hash"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/rolling_hash.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <cstdint>\n#include <random>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T = char>\nstruct RollingHash {\n  const std::int64_t\
    \ base;\n  std::vector<T> str;\n\n  template <typename U>\n  explicit RollingHash(const\
    \ U& str_, const std::int64_t base = generate_base())\n      : base(base), hashes({0}),\
    \ powers({1}) {\n    const int n = str_.size();\n    str.reserve(n);\n    hashes.reserve(n\
    \ + 1);\n    powers.reserve(n + 1);\n    for (const auto ch : str_) add(ch);\n\
    \  }\n\n  void add(const T ch) {\n    assert(0 <= ch && ch < MOD);\n    str.emplace_back(ch);\n\
    \    const std::int64_t h = mul(hashes.back(), base) + ch;\n    hashes.emplace_back(h\
    \ >= MOD ? h - MOD : h);\n    const std::int64_t p = mul(powers.back(), base);\n\
    \    powers.emplace_back(p);\n  }\n\n  std::int64_t get(const int left, const\
    \ int right) const {\n    const std::int64_t res =\n        hashes[right] - mul(hashes[left],\
    \ powers[right - left]);\n    return res < 0 ? res + MOD : res;\n  }\n\n private:\n\
    \  static constexpr int MOD_WIDTH = 61;\n  static constexpr std::int64_t MOD =\
    \ (INT64_C(1) << MOD_WIDTH) - 1;\n\n  std::vector<std::int64_t> hashes, powers;\n\
    \n  static std::int64_t generate_base() {\n    static std::mt19937_64 engine(std::random_device\
    \ {} ());\n    static std::uniform_int_distribution<std::int64_t> dist(0, MOD\
    \ - 1);\n    return dist(engine);\n  }\n\n  static std::int64_t mul(const std::int64_t\
    \ a, const std::int64_t b) {\n    const std::int64_t au = a >> 31, ad = a & ((UINT32_C(1)\
    \ << 31) - 1);\n    const std::int32_t bu = b >> 31, bd = b & ((UINT32_C(1) <<\
    \ 31) - 1);\n    const std::int64_t mid = au * bd + ad * bu;\n    std::int64_t\
    \ res = au * bu * 2 + ad * bd + (mid >> 30)\n                       + ((mid &\
    \ ((UINT32_C(1) << 30) - 1)) << 31);\n    res = (res >> MOD_WIDTH) + (res & MOD);\n\
    \    return res >= MOD ? res - MOD : res;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n"
  code: "#ifndef EMTHRM_STRING_ROLLING_HASH_HPP_\n#define EMTHRM_STRING_ROLLING_HASH_HPP_\n\
    \n#include <cassert>\n#include <cstdint>\n#include <random>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T = char>\nstruct RollingHash {\n \
    \ const std::int64_t base;\n  std::vector<T> str;\n\n  template <typename U>\n\
    \  explicit RollingHash(const U& str_, const std::int64_t base = generate_base())\n\
    \      : base(base), hashes({0}), powers({1}) {\n    const int n = str_.size();\n\
    \    str.reserve(n);\n    hashes.reserve(n + 1);\n    powers.reserve(n + 1);\n\
    \    for (const auto ch : str_) add(ch);\n  }\n\n  void add(const T ch) {\n  \
    \  assert(0 <= ch && ch < MOD);\n    str.emplace_back(ch);\n    const std::int64_t\
    \ h = mul(hashes.back(), base) + ch;\n    hashes.emplace_back(h >= MOD ? h - MOD\
    \ : h);\n    const std::int64_t p = mul(powers.back(), base);\n    powers.emplace_back(p);\n\
    \  }\n\n  std::int64_t get(const int left, const int right) const {\n    const\
    \ std::int64_t res =\n        hashes[right] - mul(hashes[left], powers[right -\
    \ left]);\n    return res < 0 ? res + MOD : res;\n  }\n\n private:\n  static constexpr\
    \ int MOD_WIDTH = 61;\n  static constexpr std::int64_t MOD = (INT64_C(1) << MOD_WIDTH)\
    \ - 1;\n\n  std::vector<std::int64_t> hashes, powers;\n\n  static std::int64_t\
    \ generate_base() {\n    static std::mt19937_64 engine(std::random_device {} ());\n\
    \    static std::uniform_int_distribution<std::int64_t> dist(0, MOD - 1);\n  \
    \  return dist(engine);\n  }\n\n  static std::int64_t mul(const std::int64_t a,\
    \ const std::int64_t b) {\n    const std::int64_t au = a >> 31, ad = a & ((UINT32_C(1)\
    \ << 31) - 1);\n    const std::int32_t bu = b >> 31, bd = b & ((UINT32_C(1) <<\
    \ 31) - 1);\n    const std::int64_t mid = au * bd + ad * bu;\n    std::int64_t\
    \ res = au * bu * 2 + ad * bd + (mid >> 30)\n                       + ((mid &\
    \ ((UINT32_C(1) << 30) - 1)) << 31);\n    res = (res >> MOD_WIDTH) + (res & MOD);\n\
    \    return res >= MOD ? res - MOD : res;\n  }\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_STRING_ROLLING_HASH_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2023-02-04 14:26:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: include/emthrm/string/rolling_hash.hpp
layout: document
title: rolling hash
---


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 仕様

```cpp
template <typename T = char>
struct RollingHash;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> str`|$S$|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`template <typename U> explicit RollingHash(const U& str_, const std::int64_t base = generate_base());`|$S$ に対してオブジェクトを構築する。||
|`void add(const T ch);`|$S$ の末尾に $\mathrm{ch}$ を追加する。|$0 \leq \mathrm{ch} < 2^{61} - 1$|
|`std::int64_t get(const int left, const int right) const;`|`S[left:right]` におけるハッシュ値||


## 参考文献

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://togetter.com/li/1413936
- https://twitter.com/noshi91/status/1269257182870073344
- https://twitter.com/noshi91/status/1612080505318707201


## TODO

- 2次元 rolling hash
  - https://github.com/beet-aizu/library/blob/42bf89efb7043053ac652a0053cf0a8e325195ca/string/rectanglehash.cpp
  - https://github.com/NyaanNyaan/library/blob/06f3f98a5aada992bfc5e83b6f59363694179635/string/rolling-hash-2d.hpp
  - https://github.com/kopricky/My-Algorithm/blob/4cb6da81e5e904422d0c153e5afe0bd6a25874c6/Competitive_Programming/ICPC/ICPC_rolling_hash_2d.hpp


## Submissons

https://atcoder.jp/contests/abc141/submissions/38527267
