---
title: multipoint evaluation
documentation_of: //include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
---

複数の $x$ に対して $f(x)$ を求めるアルゴリズムである。


## 時間計算量

$\langle O(N(\log{N})^2), O(N(\log{N})^2) \rangle$


## 仕様

```cpp
template <template <typename> class C, typename T>
struct MultipointEvaluation;
```

- `C`：冪級数を表す構造体
- `T`：係数を表す要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> f_x`|$\lbrace f(x) \mid x \in \mathrm{xs} \rbrace$|
|`std::vector<C<T>> subproduct_tree`|subproduct tree|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit MultipointEvaluation(const std::vector<T> &xs);`|multipoint evaluation を考える。|
|`void build(const C<T>& f);`|多項式 $f$ に対して `f_x` を構築する。|


## 参考文献

- Allan Borodin and Robert Moen: Fast modular transforms, *Journal of Computer and System Sciences*, Vol. 8, No. 3, pp. 366–386 (1974). https://doi.org/10.1016/S0022-0000(74)80029-2
- https://www.sci.kanagawa-u.ac.jp/info/matsuo/pub/pdf/IKM09.pdf
- https://judge.yosupo.jp/submission/3271
- https://scrapbox.io/ecasdqina-cp/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%EF%BC%88%EF%BC%9F%EF%BC%89%E3%81%AA%E3%83%86%E3%82%AF


## TODO

- https://drive.google.com/drive/folders/1gszRctvUfme7ST-K3DsrH7FIU64kHcsD


## Submissons

https://judge.yosupo.jp/submission/3793
