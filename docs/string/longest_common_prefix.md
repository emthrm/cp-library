---
title: longest common prefix
documentation_of: string/longest_common_prefix.hpp
---


### 高さ配列 (longest common prefix array)

接尾辞配列中で隣接する接尾辞の最長共通接頭辞長を表す配列である．


## 時間計算量

テキスト長を $N$ とおくと $\langle O(N\log{N}), O(1) \rangle$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`LongestCommonPrefix<T = string>(s)`|$S$ の longest common prefix を考える．||
|`lcp_array`|高さ配列||
|`query(i, j)`|位置 $i, j$ を一文字目とする接尾辞の最長共通接頭辞長|$i \neq j$ でなければならない．|


## 参考

- https://github.com/beet-aizu/library/blob/8ca8433c2baf5ddd8efca091927475ad03caadce/string/longestcommonprefix.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.339-340，マイナビ出版（2012）


## Verified

https://judge.yosupo.jp/submission/3244
