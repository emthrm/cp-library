---
title: [
  Knuth–Morris–Pratt algorithm,
  Morris–Pratt algorithm
]
documentation_of: [
  //include/emthrm/string/knuth-morris-pratt.hpp,
  //include/emthrm/string/morris-pratt.hpp
]
---

# Knuth–Morris–Pratt algorithm

文字列 $S$ に対して `S[0:i]` の接頭辞と接尾辞の最大共通文字数 ($< i$) を求めるアルゴリズムである。


## 時間計算量

パターン長を $N$, テキスト長を $M$ とおく。

### Morris–Pratt algorithm

||時間計算量|
|:--|:--|
|前処理|$O(N)$|
|更新|amortized $O(N)$ ?|
|パターンマッチング|$O(M)$|

### Knuth–Morris–Pratt algorithm

$$
  \langle O(N), O(M) \rangle
$$


## 仕様

### Morris–Pratt algorithm

```cpp
struct MorrisPratt;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::string s`|文字列 $S$|
|`std::vector<int> border`|$\mathrm{border}_i$ は `S[0:i]` の最長 border 長を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit MorrisPratt(const std::string& s);`|文字列 $S$ に対してオブジェクトを構築する。|
|`void add(const char c);`|$S$ の末尾に文字 $c$ を追加する。|
|`std::vector<int> match(const std::string& t) const;`|$S$ が出現する文字列 $T$ 中の位置|
|`int period(const int idx) const;`|`S[0:idx]` の最小周期|


### Knuth–Morris–Pratt algorithm

```cpp
template <typename T = std::string>
struct KnuthMorrisPratt;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> border`|`border[i]` は `S[0:i]` の最長 tagged border 長を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit KnuthMorrisPratt(const T& s);`|文字列 $S$ に対してオブジェクトを構築する。|
|`std::vector<int> match(const T& t) const;`|$S$ が出現する $T$ 中の位置|


## 参考文献

Morris–Pratt algorithm
- James H. Morris, Jr. and Vaughan R. Pratt: A Linear Pattern Matching Algorithm (1970).
- https://snuke.hatenablog.com/entry/2014/12/01/235807

Knuth–Morris–Pratt algorithm
- Donald E. Knuth, James H. Morris, Jr., and Vaughan R. Pratt: Fast Pattern Matching in Strings, *SIAM Journal on Computing*, Vol. 6, No. 2, pp. 323–350 (1977). https://doi.org/10.1137/0206024
- https://snuke.hatenablog.com/entry/2017/07/18/101026
- http://potetisensei.hatenablog.com/entry/2017/07/10/174908

周期性判定
- https://snuke.hatenablog.com/entry/2015/04/05/184819

パターンマッチング
- https://github.com/drken1215/algorithm/blob/d41481f5011e8b129128050627faddebe2add91a/String/knuth_morris_pratt.cpp


## Submissons

- Morris–Pratt algorithm
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [Knuth–Morris–Pratt algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
