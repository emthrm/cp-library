---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/manacher.test.cpp
    title: "\u6587\u5B57\u5217/Manacher"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/manacher.hpp\"\n#include <vector>\r\n\r\nstruct Manacher\
    \ {\r\n  template <typename T>\r\n  explicit Manacher(const T& s) {\r\n    T str;\r\
    \n    int n = s.size();\r\n    str.reserve(n * 2 + 1);\r\n    for (int i = 0;\
    \ i < n; ++i) {\r\n      str.push_back(s[i]);\r\n      str.push_back('$');\r\n\
    \    }\r\n    str.pop_back();\r\n    n = str.size();\r\n    radius.resize(n);\r\
    \n    for (int i = 0, j = 1; i < n;) {\r\n      while (i - j >= 0 && i + j < n\
    \ && str[i - j] == str[i + j]) ++j;\r\n      radius[i] = j;\r\n      int k = 1;\r\
    \n      for (; i - k >= 0 && i + k < n && k + radius[i - k] < j; ++k) {\r\n  \
    \      radius[i + k] = radius[i - k];\r\n      }\r\n      i += k;\r\n      j -=\
    \ k;\r\n    }\r\n  }\r\n\r\n  int odd(const int idx) const { return (radius[idx\
    \ * 2] + 1) / 2; }\r\n\r\n  int even(const int idx) const { return radius[idx\
    \ * 2 + 1] / 2; }\r\n\r\n  bool is_palindrome(const int left, const int right)\
    \ const {\r\n    const int mid = (left + right - 1) / 2;\r\n    return ((right\
    \ - left) & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)\r\n           >= right - left;\r\
    \n  }\r\n\r\n private:\r\n  std::vector<int> radius;\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\nstruct Manacher {\r\n  template\
    \ <typename T>\r\n  explicit Manacher(const T& s) {\r\n    T str;\r\n    int n\
    \ = s.size();\r\n    str.reserve(n * 2 + 1);\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      str.push_back(s[i]);\r\n      str.push_back('$');\r\n    }\r\n  \
    \  str.pop_back();\r\n    n = str.size();\r\n    radius.resize(n);\r\n    for\
    \ (int i = 0, j = 1; i < n;) {\r\n      while (i - j >= 0 && i + j < n && str[i\
    \ - j] == str[i + j]) ++j;\r\n      radius[i] = j;\r\n      int k = 1;\r\n   \
    \   for (; i - k >= 0 && i + k < n && k + radius[i - k] < j; ++k) {\r\n      \
    \  radius[i + k] = radius[i - k];\r\n      }\r\n      i += k;\r\n      j -= k;\r\
    \n    }\r\n  }\r\n\r\n  int odd(const int idx) const { return (radius[idx * 2]\
    \ + 1) / 2; }\r\n\r\n  int even(const int idx) const { return radius[idx * 2 +\
    \ 1] / 2; }\r\n\r\n  bool is_palindrome(const int left, const int right) const\
    \ {\r\n    const int mid = (left + right - 1) / 2;\r\n    return ((right - left)\
    \ & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)\r\n           >= right - left;\r\n \
    \ }\r\n\r\n private:\r\n  std::vector<int> radius;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/manacher.test.cpp
documentation_of: string/manacher.hpp
layout: document
title: Manacher
---

文字列に対してそれぞれのインデックスを中心とした回文の最大半径を求めるアルゴリズムである．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`Manacher(s)`|$S$ の Manacher を考える．|
|`odd(idx)`|位置 $\mathrm{idx}$ を中心とした回文の最大半径|
|`even(idx)`|位置 $\mathrm{idx} + 0.5$ を中心とした回文の最大半径|
|`is_palindrome(left, right)`|$\lbrack \mathrm{left}, \mathrm{right})$ は回文であるか．|


## 参考

- https://snuke.hatenablog.com/entry/2014/12/02/235837
- https://github.com/drken1215/algorithm/blob/d4d987bfd9205655862986b3d27339381b1ffaf7/String/manacher.cpp


## ToDo

- palindromic tree (eertree)
  - https://math314.hateblo.jp/entry/2016/12/19/005919
  - http://mojashi.hatenablog.com/entry/2017/07/17/155520
  - http://miti-7.hatenablog.com/entry/2016/03/14/195721
  - https://codeforces.com/blog/entry/13958
  - https://github.com/spaghetti-source/algorithm/blob/master/string/palindromic_tree.cc
  - https://github.com/beet-aizu/library/blob/master/datastructure/palindromictree.cpp
- distinct な部分回文をすべて求める．
  - https://github.com/eandbsoftware/libraryCPP/blob/master/!SubPalindrome.cpp


## Verified

https://judge.yosupo.jp/submission/31002
