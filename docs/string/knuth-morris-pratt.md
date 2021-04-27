# Knuth-Morris-Pratt algorithm

ある文字列 $S$ について `S[0:i]` の接頭辞と接尾辞の最大共通文字数 $(< i)$ を求めるアルゴリズムである．


## 時間計算量

パターン長を $N$, テキスト長を $M$ とおく．

- Morris-Pratt algorithm

|処理|時間計算量|
|:--:|:--:|
|前処理|$O(N)$|
|更新|$\text{amortized } O(N)$ ?|
|パターンマッチング|$O(M)$|

- Knuth-Morris-Pratt algorithm

$$\langle O(N), O(M) \rangle$$


## 使用法

- Morris-Pratt algorithm

||説明|
|:--:|:--:|
|`MorrisPratt(s)`|文字列 $S$ の Morris-Pratt algorithm を考える．|
|`border[i]`|`S[0:i]` の最長 border 長|
|`add(c)`|$S$ に文字 $c$ を追加する．|
|`match(t)`|$S$ が出現する文字列 $T$ 中の位置|
|`period(idx)`|`S[0:idx]` の最小周期|

- Knuth-Morris-Pratt algorithm

||説明|
|:--:|:--:|
|`KnuthMorrisPratt<T = string>(s)`|$S$ の Knuth-Morris-Pratt algorithm を考える．|
|`border[i]`|`S[0:i]` の最長 tagged border 長|
|`match(t)`|$S$ が出現する $T$ 中の位置|


## 参考

Morris-Pratt algorithm
- https://snuke.hatenablog.com/entry/2014/12/01/235807

Knuth-Morris-Pratt algorithm
- https://snuke.hatenablog.com/entry/2017/07/18/101026
- http://potetisensei.hatenablog.com/entry/2017/07/10/174908

周期性判定
- https://snuke.hatenablog.com/entry/2015/04/05/184819

パターンマッチング
- https://github.com/drken1215/algorithm/blob/d41481f5011e8b129128050627faddebe2add91a/String/knuth_morris_pratt.cpp


## Verified

- Morris-Pratt algorithm
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [Knuth-Morris-Pratt algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
