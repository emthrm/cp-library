---
title: ローリングハッシュ (rolling hash)
documentation_of: include/emthrm/string/rolling_hash.hpp
---


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 仕様

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`RollingHash<T = std::string>(s, 基数 = 10007, 除数 = 1000000007)`|$S$ のローリングハッシュを考える。||
|`s`|$S$|$S_i \neq 0$|
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ におけるハッシュ値||
|`add(t)`|$S$ に $T$ を追加する。||
|`longest_common_prefix(i, j)`|`S[i:]` と `S[j:]` の最長共通接頭辞長||
|`longest_common_prefix(t, i, j)`|`S[i:]` と `T[j:]` の最長共通接頭辞長|$T$ はローリングハッシュである。|


## 参考文献

- https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
- https://github.com/drken1215/algorithm/blob/5f6710d0f5a92456528100ae7d8b8c4f70ed99e2/String/rolling_hash.cpp


## TODO

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://togetter.com/li/1413936
- 2次元ローリングハッシュ
  - https://github.com/beet-aizu/library/blob/master/datastructure/2D/rollinghash2D.cpp


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086443/emthrm/C++14
