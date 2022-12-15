---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/manacher.test.cpp
    title: "\u6587\u5B57\u5217/Manacher"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/manacher.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct Manacher {\n  template <typename T>\n  explicit\
    \ Manacher(const T& s) {\n    T str;\n    int n = s.size();\n    str.reserve(n\
    \ * 2 + 1);\n    for (int i = 0; i < n; ++i) {\n      str.push_back(s[i]);\n \
    \     str.push_back('$');\n    }\n    str.pop_back();\n    n = str.size();\n \
    \   radius.resize(n);\n    for (int i = 0, j = 1; i < n;) {\n      while (i -\
    \ j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;\n      radius[i] = j;\n\
    \      int k = 1;\n      for (; i - k >= 0 && i + k < n && k + radius[i - k] <\
    \ j; ++k) {\n        radius[i + k] = radius[i - k];\n      }\n      i += k;\n\
    \      j -= k;\n    }\n  }\n\n  int odd(const int idx) const { return (radius[idx\
    \ * 2] + 1) / 2; }\n\n  int even(const int idx) const { return radius[idx * 2\
    \ + 1] / 2; }\n\n  bool is_palindrome(const int left, const int right) const {\n\
    \    const int mid = (left + right - 1) / 2;\n    return ((right - left) & 1 ?\
    \ odd(mid) * 2 - 1 : even(mid) * 2)\n           >= right - left;\n  }\n\n private:\n\
    \  std::vector<int> radius;\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_MANACHER_HPP_\n#define EMTHRM_STRING_MANACHER_HPP_\n\
    \n#include <vector>\n\nnamespace emthrm {\n\nstruct Manacher {\n  template <typename\
    \ T>\n  explicit Manacher(const T& s) {\n    T str;\n    int n = s.size();\n \
    \   str.reserve(n * 2 + 1);\n    for (int i = 0; i < n; ++i) {\n      str.push_back(s[i]);\n\
    \      str.push_back('$');\n    }\n    str.pop_back();\n    n = str.size();\n\
    \    radius.resize(n);\n    for (int i = 0, j = 1; i < n;) {\n      while (i -\
    \ j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;\n      radius[i] = j;\n\
    \      int k = 1;\n      for (; i - k >= 0 && i + k < n && k + radius[i - k] <\
    \ j; ++k) {\n        radius[i + k] = radius[i - k];\n      }\n      i += k;\n\
    \      j -= k;\n    }\n  }\n\n  int odd(const int idx) const { return (radius[idx\
    \ * 2] + 1) / 2; }\n\n  int even(const int idx) const { return radius[idx * 2\
    \ + 1] / 2; }\n\n  bool is_palindrome(const int left, const int right) const {\n\
    \    const int mid = (left + right - 1) / 2;\n    return ((right - left) & 1 ?\
    \ odd(mid) * 2 - 1 : even(mid) * 2)\n           >= right - left;\n  }\n\n private:\n\
    \  std::vector<int> radius;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_MANACHER_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/manacher.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/manacher.test.cpp
documentation_of: include/emthrm/string/manacher.hpp
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


## TODO

- palindromic tree (eertree)
  - https://math314.hateblo.jp/entry/2016/12/19/005919
  - http://mojashi.hatenablog.com/entry/2017/07/17/155520
  - http://miti-7.hatenablog.com/entry/2016/03/14/195721
  - https://codeforces.com/blog/entry/13958
  - https://github.com/spaghetti-source/algorithm/blob/master/string/palindromic_tree.cc
  - https://github.com/beet-aizu/library/blob/master/datastructure/palindromictree.cpp
  - https://mugen1337.github.io/procon/String/PalindromicTree.cpp
  - https://sotanishy.github.io/cp-library-cpp/string/palindromic_tree.hpp
- distinct な部分回文をすべて求める．
  - https://github.com/eandbsoftware/libraryCPP/blob/master/!SubPalindrome.cpp


## Verified

https://judge.yosupo.jp/submission/31002
