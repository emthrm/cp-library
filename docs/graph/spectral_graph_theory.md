# スペクトルグラフ理論 (spectral graph theory)

隣接行列やラプラシアン行列等を用いてグラフを解析する手法である．

1. 行列木定理 (Kirchhoff's theorem, Kirchhoff's matrix tree theorem)

   ラプラシアン行列の任意の余因子は全域木の個数と等しい．

2. ラプラシアン行列における固有値$0$の個数は連結成分の個数に等しい．

3. 隣接行列の行列式の偶奇と完全マッチングの個数の偶奇は一致する．

4. ケイリーの公式 (Cayley's formula)

   $n$ 頂点のラベル付きの木の総数は $N^{N - 2}$ 個である．


### ラプラシアン行列 (laplacian Matrix)

$N$ 頂点の無向グラフにおいて

$$A_{ij} = \begin{cases} \text{頂点 } i \text{ の次数} & (i = j) \\ -(\text{頂点 } i \text{ と } j \text{ を結ぶ辺の本数}) & (\text{otherwise}) \end{cases}$$

となる $N \times N$ 行列である．


## 時間計算量

- 行列木定理 $O(N^3)$


## 使用法

- 行列木定理

||説明|備考|
|:--:|:--:|:--:|
|`matrix_tree_theorem(graph, ε)`|グラフ $\mathrm{graph}$ の全域木の個数|双方向の辺の情報が必要である．|


## 参考

1. https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
2. https://www.slideshare.net/irrrrr/ss-25911553
3. https://pekempey.hatenablog.com/entry/2016/11/29/200605
4. http://joisino.hatenablog.com/entry/2017/08/20/200000


## ToDo

- LGV 公式
  - https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf


## Verified

- [行列木定理](https://atcoder.jp/contests/arc018/submissions/9306140)
