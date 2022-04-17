---
title: Manacher
documentation_of: string/manacher.hpp
---

文字列に対してそれぞれのインデックスを中心とした回文の最大半径を求めるアルゴリズムである．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|
|:--:|:--:|
|`Manacher(s)`|$S$ の Manacher を考える．|
|`odd(idx)`|位置 $\mathrm{idx}$ を中心とした回文の最大半径|
|`even(idx)`|位置 $\mathrm{idx} + 0.5$ を中心とした回文の最大半径|
|`is_palindrome(left, right)`|$\lbrack \mathrm{left}, \mathrm{right})$ は回文であるか．|


## 参考

- https://snuke.hatenablog.com/entry/2014/12/02/235837
- https://github.com/drken1215/algorithm/blob/d4d987bfd9205655862986b3d27339381b1ffaf7/String/manacher.cpp


## ToDo

- palindromic tree (eertree)
  - https://math314.hateblo.jp/entry/2016/12/19/005919
  - http://mojashi.hatenablog.com/entry/2017/07/17/155520
  - http://miti-7.hatenablog.com/entry/2016/03/14/195721
  - https://codeforces.com/blog/entry/13958
  - https://github.com/spaghetti-source/algorithm/blob/master/string/palindromic_tree.cc
  - https://github.com/beet-aizu/library/blob/master/datastructure/palindromictree.cpp
- distinct な部分回文をすべて求める．
  - https://github.com/eandbsoftware/libraryCPP/blob/master/!SubPalindrome.cpp


## Verified

https://judge.yosupo.jp/submission/31002
