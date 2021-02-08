---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/mp.1.test.cpp
    title: "\u6587\u5B57\u5217/MP \u6CD5 (`match(t)`)"
  - icon: ':x:'
    path: test/string/mp.2.test.cpp
    title: "\u6587\u5B57\u5217/MP \u6CD5 (period(idx))"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/string/kmp.md
    document_title: "MP \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/mp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief MP \u6CD5\r\n * @docs docs/string/kmp.md\r\n */\r\n\r\n\
    #pragma once\r\n#include <string>\r\n#include <vector>\r\n\r\nstruct MP {\r\n\
    \  std::vector<int> border;\r\n\r\n  MP(const std::string &s) : str(s) {\r\n \
    \   int n = str.length();\r\n    border.assign(1, -1);\r\n    for (int i = 0;\
    \ i < n; ++i) solve(i);\r\n  }\r\n\r\n  void add(char c) {\r\n    int idx = str.length();\r\
    \n    str += c;\r\n    solve(idx);\r\n  }\r\n\r\n  std::vector<int> match(const\
    \ std::string &t) const {\r\n    int n = str.length(), m = t.length();\r\n   \
    \ std::vector<int> res;\r\n    int k = 0;\r\n    for (int i = 0; i < m; ++i) {\r\
    \n      while (k >= 0 && t[i] != str[k]) k = border[k];\r\n      if (++k == n)\
    \ res.emplace_back(i - n + 1);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  int\
    \ period(int idx) const { return idx - border[idx]; }\r\n\r\nprivate:\r\n  int\
    \ j = -1;\r\n  std::string str;\r\n\r\n  void solve(int idx) {\r\n    while (j\
    \ >= 0 && str[idx] != str[j]) j = border[j];\r\n    border.emplace_back(++j);\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/mp.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/mp.2.test.cpp
  - test/string/mp.1.test.cpp
documentation_of: string/mp.hpp
layout: document
redirect_from:
- /library/string/mp.hpp
- /library/string/mp.hpp.html
title: "MP \u6CD5"
---
# KMP 法 (Knuth-Morris-Pratt algorithm)

ある文字列 $S$ について `S[0:i]` を除く `S[0:i]` の接頭辞と接尾辞の先頭において一致する最大文字数を求めるアルゴリズムである．


## 時間計算量

パターン長を $N$, テキスト長を $M$ とおく．

- MP 法

|処理|時間計算量|
|:--:|:--:|
|前処理|$O(N)$|
|更新|$\text{amortized } O(N)$ ?|
|パターンマッチング|$O(M)$|

- KMP 法

$$\langle O(N), O(M) \rangle$$


## 使用法

- MP 法

||説明|
|:--:|:--:|
|`MP(s)`|文字列 $S$ の MP 法を考える．|
|`border[i]`|`S[0:i]` の最長 border 長|
|`add(c)`|$S$ に文字 $c$ を追加する．|
|`match(t)`|$S$ が出現する文字列 $T$ 中の位置|
|`period(idx)`|`S[0:idx]` の最小周期|

- KMP 法

||説明|
|:--:|:--:|
|`KMP<T = string>(s)`|$S$ の KMP 法を考える．|
|`border[i]`|`S[0:i]` の最長 tagged border 長|
|`match(t)`|$S$ が出現する $T$ 中の位置|


## 参考

MP 法
- https://snuke.hatenablog.com/entry/2014/12/01/235807

KMP 法
- https://snuke.hatenablog.com/entry/2017/07/18/101026
- http://potetisensei.hatenablog.com/entry/2017/07/10/174908

周期性判定
- https://snuke.hatenablog.com/entry/2015/04/05/184819

パターンマッチング
- https://github.com/drken1215/algorithm/blob/master/String/knuth_morris_pratt.cpp


## Verified

- MP 法
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [KMP 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
