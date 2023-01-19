---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/rolling_hash.test.cpp
    title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/rolling_hash.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <string>\n#include <vector>\n\nnamespace emthrm {\n\n\
    template <typename T = std::string>\nstruct RollingHash {\n  T s;\n\n  explicit\
    \ RollingHash(const T& s, const int base = 10007,\n                       const\
    \ int mod = 1000000007)\n      : base(base), mod(mod), hash({0}), power({1}) {\n\
    \    const int n = s.size();\n    this->s.reserve(n);\n    hash.reserve(n + 1);\n\
    \    power.reserve(n + 1);\n    add(s);\n  }\n\n  long long get(const int left,\
    \ const int right) const {\n    const long long res =\n        hash[right] - hash[left]\
    \ * power[right - left] % mod;\n    return res < 0 ? res + mod : res;\n  }\n\n\
    \  void add(const T& t) {\n    for (const auto c : t) {\n      s.push_back(c);\n\
    \      const int hash_nxt = (hash.back() * base % mod + c) % mod;\n      hash.emplace_back(hash_nxt);\n\
    \      const int power_nxt = power.back() * base % mod;\n      power.emplace_back(power_nxt);\n\
    \    }\n  }\n\n  int longest_common_prefix(const int i, const int j) const {\n\
    \    const int n = s.size();\n    int lb = 0, ub = n + 1 - std::max(i, j);\n \
    \   while (ub - lb > 1) {\n      const int mid = (lb + ub) >> 1;\n      (get(i,\
    \ i + mid) == get(j, j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n\
    \  template <typename U>\n  int longest_common_prefix(const RollingHash<U>& t,\n\
    \                            const int i, const int j) const {\n    int lb = 0;\n\
    \    int ub = std::min(static_cast<int>(s.size()) - i,\n                     \
    \ static_cast<int>(t.s.size()) - j)\n             + 1;\n    while (ub - lb > 1)\
    \ {\n      const int mid = (lb + ub) >> 1;\n      (get(i, i + mid) == t.get(j,\
    \ j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n private:\n  const\
    \ int base, mod;\n  std::vector<long long> hash, power;\n};\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_ROLLING_HASH_HPP_\n#define EMTHRM_STRING_ROLLING_HASH_HPP_\n\
    \n#include <algorithm>\n#include <string>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T = std::string>\nstruct RollingHash {\n  T s;\n\n \
    \ explicit RollingHash(const T& s, const int base = 10007,\n                 \
    \      const int mod = 1000000007)\n      : base(base), mod(mod), hash({0}), power({1})\
    \ {\n    const int n = s.size();\n    this->s.reserve(n);\n    hash.reserve(n\
    \ + 1);\n    power.reserve(n + 1);\n    add(s);\n  }\n\n  long long get(const\
    \ int left, const int right) const {\n    const long long res =\n        hash[right]\
    \ - hash[left] * power[right - left] % mod;\n    return res < 0 ? res + mod :\
    \ res;\n  }\n\n  void add(const T& t) {\n    for (const auto c : t) {\n      s.push_back(c);\n\
    \      const int hash_nxt = (hash.back() * base % mod + c) % mod;\n      hash.emplace_back(hash_nxt);\n\
    \      const int power_nxt = power.back() * base % mod;\n      power.emplace_back(power_nxt);\n\
    \    }\n  }\n\n  int longest_common_prefix(const int i, const int j) const {\n\
    \    const int n = s.size();\n    int lb = 0, ub = n + 1 - std::max(i, j);\n \
    \   while (ub - lb > 1) {\n      const int mid = (lb + ub) >> 1;\n      (get(i,\
    \ i + mid) == get(j, j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n\
    \  template <typename U>\n  int longest_common_prefix(const RollingHash<U>& t,\n\
    \                            const int i, const int j) const {\n    int lb = 0;\n\
    \    int ub = std::min(static_cast<int>(s.size()) - i,\n                     \
    \ static_cast<int>(t.s.size()) - j)\n             + 1;\n    while (ub - lb > 1)\
    \ {\n      const int mid = (lb + ub) >> 1;\n      (get(i, i + mid) == t.get(j,\
    \ j + mid) ? lb : ub) = mid;\n    }\n    return lb;\n  }\n\n private:\n  const\
    \ int base, mod;\n  std::vector<long long> hash, power;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_STRING_ROLLING_HASH_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: include/emthrm/string/rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (rolling hash)"
---


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 仕様

```cpp
template <typename T = std::string>
struct RollingHash;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`s`|$S$|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit RollingHash(const T& s, const int base = 10007, const int mod = 1000000007);`|$S$ に対してオブジェクトを構築する。|$S_i \neq 0$|
|`long long get(const int left, const int right) const;`|`S[left:right]` におけるハッシュ値||
|`void add(const T& t);`|$S$ の末尾に $T$ を追加する。|$T_i \neq 0$|
|`int longest_common_prefix(const int i, const int j) const;`|`S[i:]` と `S[j:]` の最長共通接頭辞長||
|`template <typename U> int longest_common_prefix(const RollingHash<U>& t, const int i, const int j) const;`|`S[i:]` と `T[j:]` の最長共通接頭辞長||


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
- https://github.com/drken1215/algorithm/blob/5f6710d0f5a92456528100ae7d8b8c4f70ed99e2/String/rolling_hash.cpp


## TODO

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://togetter.com/li/1413936
- 2次元ローリングハッシュ
  - https://github.com/beet-aizu/library/blob/master/datastructure/2D/rollinghash2D.cpp


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086443/emthrm/C++14
