---
title: longest common prefix
documentation_of: include/emthrm/string/longest_common_prefix.hpp
---


### 高さ配列 (longest common prefix array)

接尾辞配列中で隣接する接尾辞の最長共通接頭辞長を表す配列である。


## 時間計算量

テキスト長を $N$ とおくと $\langle O(N\log{N}), O(1) \rangle$


## 仕様

```cpp
template <typename T = std::string>
struct LongestCommonPrefix : SuffixArray<T>;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> lcp_array`|高さ配列|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit LongestCommonPrefix(const T& s);`|$S$ に対してオブジェクトを構築する。||
|`int query(int i, int j) const;`|位置 $i, j$ を一文字目とする接尾辞の最長共通接頭辞長|$i \neq j$|


## 参考文献

- https://github.com/beet-aizu/library/blob/8ca8433c2baf5ddd8efca091927475ad03caadce/string/longestcommonprefix.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.339-340，マイナビ出版（2012）


## Submissons

https://judge.yosupo.jp/submission/3244
