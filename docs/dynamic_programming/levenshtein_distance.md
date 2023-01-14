---
title: レーベンシュタイン距離 (Levenshtein distance) / 編集距離 (edit distance)
documentation_of: include/emthrm/dynamic_programming/levenshtein_distance.hpp
---

任意の文字を削除・挿入・置換することによって、二つの文字列を一致させるために必要な操作回数の最小値である。


## 時間計算量

$O(NM)$


## 仕様

|名前|効果・戻り値|
|:--|:--|
|`levenshtein_distance(a, b)`|$A$ と $B$ のレーベンシュタイン距離|


## 参考文献

- https://ja.wikipedia.org/wiki/%E3%83%AC%E3%83%BC%E3%83%99%E3%83%B3%E3%82%B7%E3%83%A5%E3%82%BF%E3%82%A4%E3%83%B3%E8%B7%9D%E9%9B%A2


## TODO

- Method of Four Russians
  - https://en.wikipedia.org/wiki/Method_of_Four_Russians#:~:text=In%20computer%20science%2C%20the%20Method,bounded%20number%20of%20possible%20values.
  - https://qiita.com/okateim/items/a1b0523c1c862009e81f
  - https://echizen-tm.hatenadiary.org/entry/20120520/1337516536


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_E/review/4112291/emthrm/C++14
