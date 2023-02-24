---
title: 2-SAT
documentation_of: //include/emthrm/misc/2-sat.hpp
---

節内のリテラル数が高々 $2$ である連言標準形の充足可能性を判定する問題である。


## 時間計算量

$N$ 変数 $M$ 節 のとき $O(N + M)$


## 仕様

```cpp
struct TwoSat;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit TwoSat(const int n);`|$N$ 変数のオブジェクトを構築する。|
|`int negate(const int x) const;`|$\neg x$ を表す頂点番号|
|`void add_or(const int x, const int y);`|$x \vee y$ を追加する。|
|`void add_if(const int x, const int y);`|$x \Rightarrow y$ を追加する。|
|`void add_nand(const int x, const int y);`|$\neg (x \land y)$ を追加する。|
|`void set_true(const int x);`|$x$ を真とする。|
|`void set_false(const int x);`|$x$ を偽とする。|
|`std::vector<bool> build();`|変数の真理値。ただし矛盾が生じるときは空配列を返す。|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.288-290，マイナビ出版（2012）
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp


## Submissons

- https://judge.yosupo.jp/submission/2711
