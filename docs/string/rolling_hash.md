---
title: rolling hash
documentation_of: //include/emthrm/string/rolling_hash.hpp
---


## 時間計算量

$\langle O(\lvert S \rvert), O(1) \rangle$


## 仕様

```cpp
template <typename T = char>
struct RollingHash;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> str`|$S$|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`template <typename U>`<br>`explicit RollingHash(const U& str_, const std::int64_t base = generate_base());`|$S$ に対してオブジェクトを構築する。||
|`void add(const T ch);`|$S$ の末尾に $\mathrm{ch}$ を追加する。|$0 \leq \mathrm{ch} < 2^{61} - 1$|
|`std::int64_t get(const int left, const int right) const;`|`S[left:right]` におけるハッシュ値||


## 参考文献

- https://www.slideshare.net/nagisaeto/rolling-hash-149990902
- https://togetter.com/li/1413936
- https://twitter.com/noshi91/status/1269257182870073344
- https://twitter.com/noshi91/status/1612080505318707201


## TODO

- 2次元 rolling hash
  - https://github.com/beet-aizu/library/blob/42bf89efb7043053ac652a0053cf0a8e325195ca/string/rectanglehash.cpp
  - https://github.com/NyaanNyaan/library/blob/06f3f98a5aada992bfc5e83b6f59363694179635/string/rolling-hash-2d.hpp
  - https://github.com/kopricky/My-Algorithm/blob/4cb6da81e5e904422d0c153e5afe0bd6a25874c6/Competitive_Programming/ICPC/ICPC_rolling_hash_2d.hpp


## Submissons

https://atcoder.jp/contests/abc141/submissions/38527267
