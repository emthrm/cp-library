---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: game/misere_nim.hpp
    title: "mis\xE8re Nim"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/game/nim.test.cpp
    title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"game/nim.hpp\"\n#include <vector>\r\n\r\ntemplate <typename\
    \ T>\r\nbool nim(const std::vector<T> &a) {\r\n  long long x = 0;\r\n  for (T\
    \ e : a) x ^= e;\r\n  return x != 0;\r\n}\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\nbool nim(const\
    \ std::vector<T> &a) {\r\n  long long x = 0;\r\n  for (T e : a) x ^= e;\r\n  return\
    \ x != 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: game/nim.hpp
  requiredBy:
  - game/misere_nim.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/game/nim.test.cpp
documentation_of: game/nim.hpp
layout: document
title: "\u30CB\u30E0 (nim)"
---

$N$ 個の山の内，ある山から一つ以上を二人が交互に取っていき，操作できなくなった方を負けとするゲームである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`nim(a)`|盤面が $A$ のときのニムで先手が勝利するか．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.277-278，マイナビ出版（2012）．


## ToDo

- nim product
  - https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV
  - https://github.com/yosupo06/library-checker-problems/issues/317
  - https://judge.yosupo.jp/problem/nim_product_64


## Verified

https://atcoder.jp/contests/arc013/submissions/9236426
