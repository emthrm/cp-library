---
title: ローリングハッシュ (rolling hash)
documentation_of: string/rolling_hash.hpp
---

効率的に構築することができる部分列のハッシュ値である．


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`RollingHash<T>(s, 基数 = 10007, 除数 = 1000000007)`|$S$ のローリングハッシュを考える．|各要素は $0$ 以外でなければならない．|
|`str`|$S$||
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ におけるハッシュ値||
|`add(t)`|$S$ に $T$ を追加する．||
|`lcp(i, j)`|`S[i:]` と `S[j:]` の先頭における最大共通文字数||
|`lcp(t, i, j)`|`S[i:]` と `T[j:]` の先頭における最大共通文字数|$T$ はローリングハッシュである．|


## 参考

- https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
- https://github.com/drken1215/algorithm/blob/5f6710d0f5a92456528100ae7d8b8c4f70ed99e2/String/rolling_hash.cpp


## ToDo

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
- https://togetter.com/li/1413936
- 2次元ローリングハッシュ
  - https://github.com/beet-aizu/library/blob/master/datastructure/2D/rollinghash2D.cpp


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086443/emthrm/C++14
