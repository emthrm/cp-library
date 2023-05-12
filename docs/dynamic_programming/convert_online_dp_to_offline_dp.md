---
title: オフライン・オンライン変換
documentation_of: //include/emthrm/dynamic_programming/convert_online_dp_to_offline_dp.hpp
---

$i = 1, 2, \ldots, N$ に対して $\mathrm{dp}(i) = f_i(I)$ ($I \subseteq \lbrace 1, 2, \ldots, i - 1 \rbrace$) で表せるオンライン動的計画法を考える。

ある[モノイド](../../.verify-helper/docs/static/algebraic_structure.md) $(S, \cdot, e)$ が存在し、$\forall i \in \lbrace 1, 2, \ldots, N \rbrace$ に対して $f_i(I) = a_i \cdot (\prod_{j \in I} F_{ij}) \cdot b_i$ ($a_i, b_i, F_{ij} \in S,\ F_{ij} \text{ は } \mathrm{dp}(j) \text{ に依存してもよい}$) と表せるならば、複数のオフライン動的計画法に分割できる。

e.g. [Stroll](https://atcoder.jp/contests/abc213/submissions/25161037)

モノイドを $(\mathbb{N}^N, +, \boldsymbol{0})$ とする。

$i = 0$ のとき

$$
  \mathrm{dp}(i) \mathrel{:=}
  \begin{pmatrix}
    1 \\
    0 \\
    \vdots \\
    0
  \end{pmatrix}
  + \boldsymbol{0} \text{、}
$$

$i = 1, 2, \ldots, T$ のとき

$$
  \mathrm{dp}(i)_n \mathrel{:=} 0 + \sum_{j = 0}^{i - 1} \left(\sum_{a_m = n} dp(j)_{b_m} \cdot p_{m, i - j} + \sum_{b_m = n} dp(j)_{a_m} \cdot p_{m, i - j} \right) + 0
$$

と表せる。


### オンライン動的計画法 / オフライン動的計画法

$i = 1, 2, \ldots, N$ に対して $\mathrm{dp}(i) = f_i(I)$ ($I \subseteq \lbrace 1, 2, \ldots, i - 1 \rbrace$) で表せる動的計画法を考える。

$f_i(I)$ に対してある $j \in I$ が存在して $\mathrm{dp}(j)$ に依存するとき、これをオンライン動的計画法と呼ぶ。依存しないときはオフライン動的計画法と呼ぶ。


## 時間計算量

変換したオフライン動的計画法の時間計算量を $O(M(N))$ とおくと $O(M(N)\log{N})$


## 仕様

|名前|効果|備考|
|:--|:--|:--|
|`void convert_online_dp_to_offline_dp(const int n, const std::function<void(int, int, int)> induce);`|幅 $N$ の動的計画法に対してオフライン・オンライン変換を適用する。|`induce(l, m, r)` は $\mathrm{dp}(j)$ ($j = l, l + 1, \ldots, m - 1$) を $\mathrm{dp}(i)$ ($i = m, m + 1, \ldots, r - 1$) に適用する関数である。|


## 参考文献

- Marvin Künnemann, Ramamohan Paturi, and Stefan Schneider: On the Fine-Grained Complexity of One-Dimensional Dynamic Programming, *44th International Colloquium on Automata, Languages, and Programming (ICALP 2017)*, Vol. 80, No. 21, pp. 1–15 (2017). https://doi.org/10.4230/LIPIcs.ICALP.2017.21
- https://qiita.com/tmaehara/items/0687af2cfb807cde7860
- https://motsu-xe.hatenablog.com/entry/2020/10/13/195949


## TODO

- [monotone 性](./knuth_yao_speedup.md)を用いた高速化
  - https://qiita.com/tmaehara/items/0687af2cfb807cde7860#%E5%86%92%E9%A0%AD%E3%81%AE%E5%95%8F%E9%A1%8C%E9%96%A2%E9%80%A3%E7%A0%94%E7%A9%B6
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://fumofumofuni.hatenablog.com/entry/2021/10/29/002145


## Submissons

https://atcoder.jp/contests/abc213/submissions/25161037
