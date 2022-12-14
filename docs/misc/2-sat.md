---
title: 2-SAT
documentation_of: include/emthrm/misc/2-sat.hpp
---

節内のリテラル数が高々 $2$ である連言標準形の充足可能性を判定する問題である．


## 時間計算量

$N$ 変数 $M$ 節 のとき $O(N + M)$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`TwoSat(n)`|$N$ 変数の 2-SAT を考える．||
|`negate(x)`|$\neg x$ を表す頂点番号||
|`add_or(x, y)`|$x \vee y$ を追加する．||
|`add_if(x, y)`|$x \Rightarrow y$ を追加する．||
|`add_nand(x, y)`|$\neg (x \land y)$ を追加する．||
|`set_true(x)`|$x$ を真とする．||
|`set_false(x)`|$x$ を偽とする．||
|`build()`|変数の真理値|矛盾が生じるときは空配列となる．|


## 参考

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.288-290，マイナビ出版（2012）
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp


## Verified

- https://judge.yosupo.jp/submission/2711
