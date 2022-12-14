---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/knuth-morris-pratt.test.cpp
    title: "\u6587\u5B57\u5217/Knuth\u2013Morris\u2013Pratt algorithm"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/knuth-morris-pratt.md
    document_title: "Knuth\u2013Morris\u2013Pratt algorithm"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/knuth-morris-pratt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Knuth\u2013Morris\u2013Pratt algorithm\n * @docs docs/string/knuth-morris-pratt.md\n\
    \ */\n\n#pragma once\n#include <string>\n#include <vector>\n\ntemplate <typename\
    \ T = std::string>\nstruct KnuthMorrisPratt {\n  std::vector<int> border;\n\n\
    \  explicit KnuthMorrisPratt(const T& s) : s(s) {\n    const int n = s.size();\n\
    \    border.assign(n + 1, -1);\n    for (int i = 0, j = -1; i < n; ++i) {\n  \
    \    while (j >= 0 && s[i] != s[j]) j = border[j];\n      ++j;\n      border[i\
    \ + 1] = (i + 1 < n && s[i + 1] == s[j] ? border[j] : j);\n    }\n  }\n\n  std::vector<int>\
    \ match(const T& t) const {\n    const int n = s.size(), m = t.size();\n    std::vector<int>\
    \ res;\n    for (int i = 0, k = 0; i < m; ++i) {\n      while (k >= 0 && t[i]\
    \ != s[k]) k = border[k];\n      if (++k == n) res.emplace_back(i - n + 1);\n\
    \    }\n    return res;\n  }\n\n private:\n  const T s;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/knuth-morris-pratt.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/knuth-morris-pratt.test.cpp
documentation_of: string/knuth-morris-pratt.hpp
layout: document
redirect_from:
- /library/string/knuth-morris-pratt.hpp
- /library/string/knuth-morris-pratt.hpp.html
title: "Knuth\u2013Morris\u2013Pratt algorithm"
---
# Knuth–Morris–Pratt algorithm

文字列 $S$ に対して `S[0:i]` の接頭辞と接尾辞の最大共通文字数 ($< i$) を求めるアルゴリズムである．


## 時間計算量

パターン長を $N$, テキスト長を $M$ とおく．

- Morris–Pratt algorithm

|処理|時間計算量|
|:--:|:--:|
|前処理|$O(N)$|
|更新|amortized $O(N)$ ?|
|パターンマッチング|$O(M)$|

- Knuth–Morris–Pratt algorithm

$$
  \langle O(N), O(M) \rangle
$$


## 使用法

- Morris–Pratt algorithm

||説明|
|:--:|:--:|
|`MorrisPratt(s)`|文字列 $S$ の Morris–Pratt algorithm を考える．|
|`str`|文字列 $S$|
|`border[i]`|`S[0:i]` の最長 border 長|
|`add(c)`|$S$ に文字 $c$ を追加する．|
|`match(t)`|$S$ が出現する文字列 $T$ 中の位置|
|`period(idx)`|`S[0:idx]` の最小周期|

- Knuth–Morris–Pratt algorithm

||説明|
|:--:|:--:|
|`KnuthMorrisPratt<T = string>(s)`|$S$ の Knuth–Morris–Pratt algorithm を考える．|
|`border[i]`|`S[0:i]` の最長 tagged border 長|
|`match(t)`|$S$ が出現する $T$ 中の位置|


## 参考

Morris–Pratt algorithm
- https://snuke.hatenablog.com/entry/2014/12/01/235807

Knuth–Morris–Pratt algorithm
- https://snuke.hatenablog.com/entry/2017/07/18/101026
- http://potetisensei.hatenablog.com/entry/2017/07/10/174908

周期性判定
- https://snuke.hatenablog.com/entry/2015/04/05/184819

パターンマッチング
- https://github.com/drken1215/algorithm/blob/d41481f5011e8b129128050627faddebe2add91a/String/knuth_morris_pratt.cpp


## Verified

- Morris–Pratt algorithm
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [Knuth–Morris–Pratt algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
