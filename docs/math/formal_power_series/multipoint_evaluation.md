---
title: multipoint evaluation
documentation_of: include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
---

複数の $x$ に対して $f(x)$ を求めるアルゴリズムである．


## 時間計算量

$\langle O(N(\log{N})^2), O(N(\log{N})^2) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`MultipointEvaluation<多項式, T>(xs)`|multipoint evaluation を考える．|
|`f_x`|$\lbrace f(x) \mid x \in \mathrm{xs} \rbrace$|
|`subproduct_tree`|subproduct tree|
|`build(f)`|多項式 $f$ に対して `f_x` を構築する．|


## 参考

- https://www.sci.kanagawa-u.ac.jp/info/matsuo/pub/pdf/IKM09.pdf
- https://judge.yosupo.jp/submission/3271
- https://scrapbox.io/ecasdqina-cp/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%EF%BC%88%EF%BC%9F%EF%BC%89%E3%81%AA%E3%83%86%E3%82%AF


## ToDo

- https://drive.google.com/drive/folders/1gszRctvUfme7ST-K3DsrH7FIU64kHcsD


## Verified

https://judge.yosupo.jp/submission/3793
