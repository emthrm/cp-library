---
title: Manacher
documentation_of: //include/emthrm/string/manacher.hpp
---

文字列に対してそれぞれのインデックスを中心とした回文の最大半径を求めるアルゴリズムである。


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

```cpp
struct Manacher;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`template <typename T>`<br>`explicit Manacher(const T& s);`|$S$ に対してオブジェクトを構築する。|
|`int odd(const int idx) const;`|位置 $\mathrm{idx}$ を中心とした回文の最大半径|
|`int even(const int idx) const;`|位置 $\mathrm{idx} + 0.5$ を中心とした回文の最大半径|
|`bool is_palindrome(const int left, const int right) const;`|`S[left:right]` は回文であるか。|


## 参考文献

- Glenn Manacher: A New Linear-Time ``On-Line'' Algorithm for Finding the Smallest Initial Palindrome of a String, *Journal of the ACM*, Vol. 22, No. 3, pp. 346–351 (1975). https://doi.org/10.1145/321892.321896
- https://snuke.hatenablog.com/entry/2014/12/02/235837
- https://github.com/drken1215/algorithm/blob/d4d987bfd9205655862986b3d27339381b1ffaf7/String/manacher.cpp


## TODO

- palindromic tree (eertree)
  - https://math314.hateblo.jp/entry/2016/12/19/005919
  - http://mojashi.hatenablog.com/entry/2017/07/17/155520
  - http://miti-7.hatenablog.com/entry/2016/03/14/195721
  - https://codeforces.com/blog/entry/13958
  - https://github.com/spaghetti-source/algorithm/blob/master/string/palindromic_tree.cc
  - https://github.com/beet-aizu/library/blob/master/datastructure/palindromictree.cpp
  - https://mugen1337.github.io/procon/String/PalindromicTree.cpp
  - https://sotanishy.github.io/cp-library-cpp/string/palindromic_tree.hpp
  - https://judge.yosupo.jp/problem/palindromes_in_deque
  - https://judge.yosupo.jp/problem/eertree
  - 問題例 "[Mirror Relay](https://yukicoder.me/problems/no/2606)"
    - https://twitter.com/SSRS_cp/status/1745821698988109931
    - https://twitter.com/m_99kyopro/status/1745821743397405017
- distinct な部分回文をすべて求める。
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!SubPalindrome.cpp~~


## Submissons

https://judge.yosupo.jp/submission/31002
