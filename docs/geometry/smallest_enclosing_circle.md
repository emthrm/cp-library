---
title: 最小包含円 (smallest enclosing circle)
documentation_of: include/emthrm/geometry/smallest_enclosing_circle.hpp
---

与えられた点集合に属するすべての点を内部または円周上に含む円の内、半径最小のものである。


## 時間計算量

expected $O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`geometry::Circle geometry::smallest_enclosing_circle(std::vector<Point> ps);`|点集合 $\mathrm{ps}$ の最小包含円|


## 参考文献

- https://www.jaist.ac.jp/~uehara/course/2014/i481f/pdf/ppt-7.pdf
- https://tubo28.me/compprog/algorithm/minball/
- http://nonoishi.web.fc2.com/math/fivecenters.pdf


## Submissons

- https://atcoder.jp/contests/abc151/submissions/11968904
