---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/kmp.test.cpp
    title: "\u6587\u5B57\u5217/KMP \u6CD5"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/kmp.md
    document_title: "KMP \u6CD5"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/kmp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief KMP \u6CD5\r\n * @docs docs/string/kmp.md\r\n */\r\n\r\n\
    #pragma once\r\n#include <string>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T = std::string>\r\nstruct KMP {\r\n  std::vector<int> border;\r\n\r\n  KMP(const\
    \ T &s) : str(s) {\r\n    int n = str.size();\r\n    border.resize(n + 1);\r\n\
    \    border[0] = -1;\r\n    int j = -1;\r\n    for (int i = 0; i < n; ++i) {\r\
    \n      while (j >= 0 && str[i] != str[j]) j = border[j];\r\n      ++j;\r\n  \
    \    border[i + 1] = i + 1 < n && str[i + 1] == str[j] ? border[j] : j;\r\n  \
    \  }\r\n  }\r\n\r\n  std::vector<int> match(const T &t) const {\r\n    int n =\
    \ str.size(), m = t.size();\r\n    std::vector<int> res;\r\n    int k = 0;\r\n\
    \    for (int i = 0; i < m; ++i) {\r\n      while (k >= 0 && t[i] != str[k]) k\
    \ = border[k];\r\n      if (++k == n) res.emplace_back(i - n + 1);\r\n    }\r\n\
    \    return res;\r\n  }\r\n\r\nprivate:\r\n  T str;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/kmp.test.cpp
documentation_of: string/kmp.hpp
layout: document
redirect_from:
- /library/string/kmp.hpp
- /library/string/kmp.hpp.html
title: "KMP \u6CD5"
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