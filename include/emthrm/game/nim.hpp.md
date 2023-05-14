---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/emthrm/game/misere_nim.hpp
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
  bundledCode: "#line 1 \"include/emthrm/game/nim.hpp\"\n\n\n\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nbool nim(const std::vector<T>&\
    \ a) {\n  long long x = 0;\n  for (const T e : a) x ^= e;\n  return x != 0;\n\
    }\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_GAME_NIM_HPP_\n#define EMTHRM_GAME_NIM_HPP_\n\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nbool nim(const std::vector<T>&\
    \ a) {\n  long long x = 0;\n  for (const T e : a) x ^= e;\n  return x != 0;\n\
    }\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GAME_NIM_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/game/nim.hpp
  requiredBy:
  - include/emthrm/game/misere_nim.hpp
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/game/nim.test.cpp
documentation_of: include/emthrm/game/nim.hpp
layout: document
title: "\u30CB\u30E0 (nim)"
---

$N$ 個の山のいずれかから一つ以上を二人が交互に取り、操作できなくなった方を負けとするゲームである。


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`bool nim(const std::vector<T>& a);`|盤面が $A$ のときのニムで先手が勝利するか。|


## 参考文献

- Charles L. Bouton: Nim, A Game with a Complete Mathematical Theory, *Annals of Mathematics*, Vol. 3, No. 14, pp. 35–39 (1901–1902). https://doi.org/10.2307/1967631
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.277-278，マイナビ出版（2012）


## TODO

- nim product
  - https://drive.google.com/file/d/16g1tfSHUU4NXNTDgaD8FSA1WB4FtJCyV
  - https://twitter.com/kyopro_friends/status/1646458244628611072
  - https://github.com/yosupo06/library-checker-problems/issues/317
  - https://sotanishy.github.io/cp-library-cpp/math/nimber.hpp
  - https://judge.yosupo.jp/problem/nim_product_64
  - https://yukicoder.me/problems/no/1775
  - https://atcoder.jp/contests/abc274/tasks/abc274_h


## Submissons

https://yukicoder.me/submissions/701261
