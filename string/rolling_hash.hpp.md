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
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <algorithm>\r\n#include\
    \ <string>\r\n#include <vector>\r\n\r\ntemplate <typename T = std::string>\r\n\
    struct RollingHash {\r\n  T str;\r\n\r\n  RollingHash(const T &s, const int base\
    \ = 10007, const int md = 1000000007) : str(s), base(base), md(md) {\r\n    int\
    \ n = str.size();\r\n    hash_val.resize(n + 1);\r\n    hash_val[0] = 0;\r\n \
    \   power.resize(n + 1);\r\n    power[0] = 1;\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      hash_val[i + 1] = (hash_val[i] * base % md + str[i]) % md;\r\n  \
    \    power[i + 1] = power[i] * base % md;\r\n    }\r\n  }\r\n\r\n  long long get(int\
    \ left, int right) const {\r\n    long long res = hash_val[right] - hash_val[left]\
    \ * power[right - left] % md;\r\n    return res < 0 ? res + md : res;\r\n  }\r\
    \n\r\n  void add(const T &t) {\r\n    for (auto c : t) {\r\n      hash_val.emplace_back((hash_val.back()\
    \ * base % md + c) % md);\r\n      power.emplace_back(power.back() * base % md);\r\
    \n    }\r\n  }\r\n\r\n  int lcp(int i, int j) const {\r\n    int n = str.size(),\
    \ lb = 0, ub = n + 1 - std::max(i, j);\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1;\r\n      (get(i, i + mid) == get(j, j + mid) ? lb : ub)\
    \ = mid;\r\n    }\r\n    return lb;\r\n  }\r\n\r\n  template <typename U>\r\n\
    \  int lcp(const RollingHash<U> &t, int i, int j) const {\r\n    int lb = 0, ub\
    \ = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size())\
    \ - j) + 1;\r\n    while (ub - lb > 1) {\r\n      int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n  \
    \  return lb;\r\n  }\r\n\r\nprivate:\r\n  int base, md;\r\n  std::vector<long\
    \ long> hash_val, power;\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <string>\r\n#include <vector>\r\
    \n\r\ntemplate <typename T = std::string>\r\nstruct RollingHash {\r\n  T str;\r\
    \n\r\n  RollingHash(const T &s, const int base = 10007, const int md = 1000000007)\
    \ : str(s), base(base), md(md) {\r\n    int n = str.size();\r\n    hash_val.resize(n\
    \ + 1);\r\n    hash_val[0] = 0;\r\n    power.resize(n + 1);\r\n    power[0] =\
    \ 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      hash_val[i + 1] = (hash_val[i]\
    \ * base % md + str[i]) % md;\r\n      power[i + 1] = power[i] * base % md;\r\n\
    \    }\r\n  }\r\n\r\n  long long get(int left, int right) const {\r\n    long\
    \ long res = hash_val[right] - hash_val[left] * power[right - left] % md;\r\n\
    \    return res < 0 ? res + md : res;\r\n  }\r\n\r\n  void add(const T &t) {\r\
    \n    for (auto c : t) {\r\n      hash_val.emplace_back((hash_val.back() * base\
    \ % md + c) % md);\r\n      power.emplace_back(power.back() * base % md);\r\n\
    \    }\r\n  }\r\n\r\n  int lcp(int i, int j) const {\r\n    int n = str.size(),\
    \ lb = 0, ub = n + 1 - std::max(i, j);\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1;\r\n      (get(i, i + mid) == get(j, j + mid) ? lb : ub)\
    \ = mid;\r\n    }\r\n    return lb;\r\n  }\r\n\r\n  template <typename U>\r\n\
    \  int lcp(const RollingHash<U> &t, int i, int j) const {\r\n    int lb = 0, ub\
    \ = std::min(static_cast<int>(str.size()) - i, static_cast<int>(t.str.size())\
    \ - j) + 1;\r\n    while (ub - lb > 1) {\r\n      int mid = (lb + ub) >> 1;\r\n\
    \      (get(i, i + mid) == t.get(j, j + mid) ? lb : ub) = mid;\r\n    }\r\n  \
    \  return lb;\r\n  }\r\n\r\nprivate:\r\n  int base, md;\r\n  std::vector<long\
    \ long> hash_val, power;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/rolling_hash.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (rolling hash)"
---

効率的に構築することができる部分列のハッシュ値である．


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`RollingHash<T>(s, 基数 = 10007, 除数 = 1000000007)`|$S$ のローリングハッシュを考える．|各要素は $0$ 以外でなければならない．|
|`str`|$S$||
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ におけるハッシュ値||
|`add(t)`|$S$ に $T$ を追加する．||
|`lcp(i, j)`|`S[i:]` と `S[j:]` の先頭における最大共通文字数||
|`lcp(t, i, j)`|`S[i:]` と `T[j:]` の先頭における最大共通文字数|$T$ はローリングハッシュである．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
- https://github.com/drken1215/algorithm/blob/master/String/rolling_hash.cpp


## ToDo

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://togetter.com/li/1413936
- 2次元ローリングハッシュ
  - https://github.com/beet-aizu/library/blob/master/datastructure/2D/rollinghash2D.cpp


## Verified

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086443/emthrm/C++14
