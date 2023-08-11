---
title: 多倍長整数
documentation_of: //include/emthrm/math/bigint.hpp
---


## 時間計算量

|アルゴリズム|時間計算量|
|:--|:--|
|カラツバ法 (Karatsuba algorithm)|$O(N^{\log 3}) \sim O(N^{1.585})$|
|Knuth's Algorithm D|$O(N^2)$|


## 参考文献

- ~~https://lumakernel.github.io/ecasdqina/misc/BigInteger~~
- https://github.com/spaghetti-source/algorithm/blob/b9b6e0b7c50600d985b2c0114fb569ee2d3102dc/math/bigint.cc

カラツバ法
- A. Karatsuba and Yu. Ofman: Multiplication of many-digital numbers by automatic computers, *Doklady Akademii Nauk SSSR*, Vol. 145, No. 2, pp. 293–294 (1962).
- http://xn--w6q13e505b.jp/method/karatsuba.html

Knuth's Algorithm D
- Donald E. Knuth: The Art of Computer Programming, Volume 2: Seminumerical Algorithms, Addison-Wesley, 3rd edition (1997).
- http://yamatyuu.net/computer/program/long/div/index.html


## TODO

- https://qiita.com/square1001/items/1aa12e04934b6e749962
- http://xn--w6q13e505b.jp/method/
- http://poset.jp/ompa/node3.html
- https://judge.yosupo.jp/problem/division_of_big_integers
- 乗算の高速化
  - http://xn--w6q13e505b.jp/method/mult.html
  - http://fussy.web.fc2.com/algo/math3_mult.htm
  - ショーンハーゲ・ストラッセン法 (Schönhage–Strassen algorithm)
    - https://ja.wikipedia.org/wiki/%E3%82%B7%E3%83%A7%E3%83%BC%E3%83%B3%E3%83%8F%E3%83%BC%E3%82%B2%E3%83%BB%E3%82%B9%E3%83%88%E3%83%A9%E3%83%83%E3%82%BB%E3%83%B3%E6%B3%95
    - https://qiita.com/peria/items/fbdd52768b4659823d88
    - http://poset.jp/ompa/node5.html
    - https://qiita.com/peria/items/19e37b192cb62bdbc3a1
    - https://cookies.hatenablog.jp/entry/2018/12/18/092106
    - https://pisan-dub.jp/doc/2011/20110201001/2000/20000819001/0.pdf
  - Toom–Cook 法 (Toom-3)
    - https://en.wikipedia.org/wiki/Toom%E2%80%93Cook_multiplication
    - http://xn--w6q13e505b.jp/method/toomcook.html
    - https://azapen6.hatenablog.com/entry/2014/04/11/235315
    - https://www.mk-mode.com/blog/2013/04/29/cpp-big-multiply-toom-cook-3/
    - http://poset.jp/ompa/node4.html#SECTION00044000000000000000
- 階乗
  - http://fussy.web.fc2.com/algo/math2_bignum.htm
- ニュートン・ラプソン除算 (Newton–Raphson division)
  - https://ja.wikipedia.org/wiki/%E9%99%A4%E7%AE%97_(%E3%83%87%E3%82%B8%E3%82%BF%E3%83%AB)#%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3-%E3%83%A9%E3%83%97%E3%82%BD%E3%83%B3%E9%99%A4%E7%AE%97
  - https://wiki2.org/en/Division_algorithm#Fast_division_methods
  - http://xn--w6q13e505b.jp/method/newton.html
  - http://www.hundredsoft.jp/win7blog/log/eid99.html
- 平方根
  - https://codeforces.com/blog/entry/22566
  - http://poset.jp/ompa/node2.html#SECTION00024000000000000000
  - ~~http://www.prefield.com/algorithm/math/bignum.html~~


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2679/review/4092735/emthrm/C++14
- [加算](https://judge.yosupo.jp/submission/155155)
- [減算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_B/review/4092740/emthrm/C++14)
- [乗算](https://judge.yosupo.jp/submission/155180)
- [除算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_D/review/4092743/emthrm/C++14)
- [剰余演算](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_2_E/review/4092744/emthrm/C++14)
- [大小比較](https://atcoder.jp/contests/abc059/submissions/9334290)
- [冪演算](https://codeforces.com/problemsets/acmsguru/submission/99999/68307060)
- [桁和](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP1_8_B/review/4967090/emthrm/C++17)
- [桁数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0015/review/4092752/emthrm/C++14)
