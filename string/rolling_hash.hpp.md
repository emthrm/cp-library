---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/rolling_hash.test.cpp
    title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <algorithm>\r\n#include\
    \ <string>\r\n#include <vector>\r\n\r\ntemplate <typename T = std::string>\r\n\
    struct RollingHash {\r\n  T s;\r\n\r\n  explicit RollingHash(const T& s, const\
    \ int base = 10007,\r\n                       const int mod = 1000000007)\r\n\
    \      : base(base), mod(mod), hash({0}), power({1}) {\r\n    const int n = s.size();\r\
    \n    this->s.reserve(n);\r\n    hash.reserve(n + 1);\r\n    power.reserve(n +\
    \ 1);\r\n    add(s);\r\n  }\r\n\r\n  long long get(const int left, const int right)\
    \ const {\r\n    const long long res =\r\n        hash[right] - hash[left] * power[right\
    \ - left] % mod;\r\n    return res < 0 ? res + mod : res;\r\n  }\r\n\r\n  void\
    \ add(const T& t) {\r\n    for (const auto c : t) {\r\n      s.push_back(c);\r\
    \n      const int hash_nxt = (hash.back() * base % mod + c) % mod;\r\n      hash.emplace_back(hash_nxt);\r\
    \n      const int power_nxt = power.back() * base % mod;\r\n      power.emplace_back(power_nxt);\r\
    \n    }\r\n  }\r\n\r\n  int longest_common_prefix(const int i, const int j) const\
    \ {\r\n    const int n = s.size();\r\n    int lb = 0, ub = n + 1 - std::max(i,\
    \ j);\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n    return\
    \ lb;\r\n  }\r\n\r\n  template <typename U>\r\n  int longest_common_prefix(const\
    \ RollingHash<U>& t,\r\n                            const int i, const int j)\
    \ const {\r\n    int lb = 0;\r\n    int ub = std::min(static_cast<int>(s.size())\
    \ - i,\r\n                      static_cast<int>(t.str.size()) - j)\r\n      \
    \       + 1;\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >>\
    \ 1;\r\n      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\
    \n    return lb;\r\n  }\r\n\r\n private:\r\n  const int base, mod;\r\n  std::vector<long\
    \ long> hash, power;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T = std::string>\r\nstruct RollingHash {\r\n  T s;\r\n\
    \r\n  explicit RollingHash(const T& s, const int base = 10007,\r\n           \
    \            const int mod = 1000000007)\r\n      : base(base), mod(mod), hash({0}),\
    \ power({1}) {\r\n    const int n = s.size();\r\n    this->s.reserve(n);\r\n \
    \   hash.reserve(n + 1);\r\n    power.reserve(n + 1);\r\n    add(s);\r\n  }\r\n\
    \r\n  long long get(const int left, const int right) const {\r\n    const long\
    \ long res =\r\n        hash[right] - hash[left] * power[right - left] % mod;\r\
    \n    return res < 0 ? res + mod : res;\r\n  }\r\n\r\n  void add(const T& t) {\r\
    \n    for (const auto c : t) {\r\n      s.push_back(c);\r\n      const int hash_nxt\
    \ = (hash.back() * base % mod + c) % mod;\r\n      hash.emplace_back(hash_nxt);\r\
    \n      const int power_nxt = power.back() * base % mod;\r\n      power.emplace_back(power_nxt);\r\
    \n    }\r\n  }\r\n\r\n  int longest_common_prefix(const int i, const int j) const\
    \ {\r\n    const int n = s.size();\r\n    int lb = 0, ub = n + 1 - std::max(i,\
    \ j);\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n    return\
    \ lb;\r\n  }\r\n\r\n  template <typename U>\r\n  int longest_common_prefix(const\
    \ RollingHash<U>& t,\r\n                            const int i, const int j)\
    \ const {\r\n    int lb = 0;\r\n    int ub = std::min(static_cast<int>(s.size())\
    \ - i,\r\n                      static_cast<int>(t.str.size()) - j)\r\n      \
    \       + 1;\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb + ub) >>\
    \ 1;\r\n      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\
    \n    return lb;\r\n  }\r\n\r\n private:\r\n  const int base, mod;\r\n  std::vector<long\
    \ long> hash, power;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (rolling hash)"
---


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`RollingHash<T = std::string>(s, 基数 = 10007, 除数 = 1000000007)`|$S$ のローリングハッシュを考える．|要素は $0$ 以外でなければならない．|
|`s`|$S$||
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ におけるハッシュ値||
|`add(t)`|$S$ に $T$ を追加する．||
|`longest_common_prefix(i, j)`|`S[i:]` と `S[j:]` の最長共通接頭辞長||
|`longest_common_prefix(t, i, j)`|`S[i:]` と `T[j:]` の最長共通接頭辞長|$T$ はローリングハッシュである．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
- https://github.com/drken1215/algorithm/blob/5f6710d0f5a92456528100ae7d8b8c4f70ed99e2/String/rolling_hash.cpp


## ToDo

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://togetter.com/li/1413936
- 2次元ローリングハッシュ
  - https://github.com/beet-aizu/library/blob/master/datastructure/2D/rollinghash2D.cpp


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086443/emthrm/C++14
