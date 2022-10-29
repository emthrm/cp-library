---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: game/misere_nim.hpp
    title: "mis\xE8re Nim"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/game/nim.test.cpp
    title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"game/nim.hpp\"\n#include <vector>\n\ntemplate <typename\
    \ T>\nbool nim(const std::vector<T>& a) {\n  long long x = 0;\n  for (const T\
    \ e : a) x ^= e;\n  return x != 0;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nbool nim(const\
    \ std::vector<T>& a) {\n  long long x = 0;\n  for (const T e : a) x ^= e;\n  return\
    \ x != 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: game/nim.hpp
  requiredBy:
  - game/misere_nim.hpp
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/game/nim.test.cpp
documentation_of: game/nim.hpp
layout: document
title: "\u30CB\u30E0 (nim)"
---

$N$ 個の山のいずれかから一つ以上を二人が交互に取り，操作できなくなった方を負けとするゲームである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`nim(a)`|盤面が $A$ のときのニムで先手が勝利するか．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.277-278，マイナビ出版（2012）


## ToDo

- nim product
  - https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV
  - https://github.com/yosupo06/library-checker-problems/issues/317
  - https://sotanishy.github.io/cp-library-cpp/math/nimber.hpp
  - https://judge.yosupo.jp/problem/nim_product_64
  - https://yukicoder.me/problems/no/1775
  - https://atcoder.jp/contests/abc274/tasks/abc274_h


## Verified

https://yukicoder.me/submissions/701261
