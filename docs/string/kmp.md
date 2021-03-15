# KMP 法 (Knuth-Morris-Pratt algorithm)

ある文字列 $S$ について `S[0:i]` の接頭辞と接尾辞の最大共通文字数 $(< i)$ を求めるアルゴリズムである．


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
- https://github.com/drken1215/algorithm/blob/d41481f5011e8b129128050627faddebe2add91a/String/knuth_morris_pratt.cpp


## Verified

- MP 法
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [KMP 法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
