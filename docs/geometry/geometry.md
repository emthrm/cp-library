---
title: 計算幾何学 (computational geometry)
documentation_of: geometry/geometry.hpp
---


## 時間計算量

||時間計算量|
|:--:|:--:|
|最近点対|$O(N\log{N})$|
|多角形の面積|$O(N)$|
|多角形の重心|$O(N)$|
|多角形に対する点の内外判定|$O(N)$|
|凸性判定|$O(N)$|
|monotone chain|$O(N\log{N})$|
|凸多角形の切断|$O(N)$|
|キャリパー法 (rotating calipers)|$O(N)$|


## 使用法

||説明|
|:--:|:--:|
|`sgn(x)`|$\begin{cases} 1 & (x > \varepsilon) \\\\ -1 & (x < -\varepsilon) \\\\ 0 & (\text{otherwise}) \end{cases}$|
|`degree_to_radian(d)`|$\frac{\pi d}{180}\,\mathrm{rad}$|
|`radian_to_degree(r)`|$(\frac{180r}{\pi})^\circ$|

- 点

||説明|備考|
|:--:|:--:|:--:|
|`Point(x = 0, y = 0)`|点 $(x, y)$||
|`x`, `y`|$(x, y)$||
|`abs()`|$\lVert \boldsymbol{p} \rVert$||
|`arg()`|$\arg(x + iy)$|$[0, 2\pi)$|
|`norm()`|${\lVert \boldsymbol{p} \rVert}^2$||
|`rotate(angle)`|原点周りに $\mathrm{angle}$ だけ回転させたときの座標 $(x^{\prime}, y^{\prime})$|$\begin{cases} x^{\prime} = x\cos(\mathrm{angle}) - y\sin(\mathrm{angle}) \\\\ y^{\prime} = x\sin(\mathrm{angle}) + y\cos(\mathrm{angle}) \end{cases}$|
|`unit_vector()`|単位ベクトル||
|`normal_unit_vector()`|単位法線ベクトル|

- 線分

||説明|
|:--:|:--:|
|`Segment(s = (0, 0), t = (0, 0))`|始点 $s$, 終点 $t$ の線分|
|`s`|始点|
|`t`|終点|

- 直線

||説明|備考|
|:--:|:--:|:--:|
|`Line(s = (0, 0), t = (0, 0))`|始点 $s$, 終点 $t$ の線分||
|`Line(a, b, c)`|$ax + by + c = 0$ で表される直線|`s`, `t` には代表する2点を格納する．|
|`s`|始点|
|`t`|終点|

- 円

||説明|
|:--:|:--:|
|`Circle(p = (0, 0), r = 0)`|中心 $\mathrm{P}$, 半径 $r$ の円|
|`p`|中心|
|`r`|半径|

- 多角形

頂点は反時計回りに並ぶ．

- ライブラリ

||説明|備考|
|:--:|:--:|:--:|
|`cross(a, b)`|$\boldsymbol{a} \times \boldsymbol{b}$||
|`dot(a, b)`|$\boldsymbol{a} \cdot \boldsymbol{b}$||
|`ccw(a, b, c)`|$\begin{cases} -2 & (\mathrm{A}, \mathrm{B}, \mathrm{C} \text{ の順で一直線上に並ぶ．}) \\\\ -1 & (\mathrm{AB} \text{ から見て } \mathrm{C} \text{ は右側にある．}) \\\\ 0 & (\mathrm{A}, \mathrm{C}, \mathrm{B} \text{ の順で一直線上に並ぶ．}) \\\\ 1 & (\mathrm{AB} \text{ から見て } \mathrm{C} \text{ は左側にある．}) \\\\ 2 & (\mathrm{C}, \mathrm{A}, \mathrm{B} \text{ の順で一直線上に並ぶ．}) \end{cases}$||
|`get_angle(a, b, c)`|$\angle{\mathrm{ABC}}$||
|`closest_pair(ps)`|点集合 $\mathrm{ps}$ の最近点対間距離||
|`projection(a, b)`|点 $\mathrm{A}$ に対する点 $\mathrm{B}$ の射影||
|`reflection(a, b)`|点 $\mathrm{A}$ に対する点 $\mathrm{B}$ の鏡映||
|`is_parallel(a, b)`|$\boldsymbol{a} \parallel \boldsymbol{b}$|$\Leftrightarrow \boldsymbol{a} \times \boldsymbol{b} = 0$|
|`is_orthogonal(a, b)`|$\boldsymbol{a} \perp \boldsymbol{b}$|$\Leftrightarrow \boldsymbol{a} \cdot \boldsymbol{b} = 0$|
|`has_intersected(a, b)`|点 $\mathrm{A}$ と点 $\mathrm{B}$ は交差しているか．||
|`intersection(a, b)`|点 $\mathrm{A}$ と点 $\mathrm{B}$ の交点||
|`distance(a, b)`|点 $\mathrm{A}$ と点 $\mathrm{B}$ の距離||
|`tangency(a, b)`|点 $\mathrm{B}$ から円 $\mathrm{A}$ に引いた接線の接点|円 $(x - a)^2 + (y - b)^2 = r^2$ 上の点 $(x_0, y_0)$ における接線の方程式は $(x_0 - a)(x - a) + (y_0 - b)(y - b) = r^2$ である．|
|`common_tangent_num(a, b)`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通接線の本数||
|`common_tangent(a, b)`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通接線|2円が接していないとき，`s` は円 $\mathrm{A}$ における接点，`t` は円 $\mathrm{B}$ における接点が格納される．|
|`intersection_area(a, b)`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通部分の面積||
|`area(a)`|多角形 $\mathrm{A}$ の面積||
|`centroid(a)`|多角形 $\mathrm{A}$ の重心||
|`contains(a, b)`|点 $\mathrm{B}$ は多角形 $\mathrm{A}$ の内部に存在するか．||
|`is_convex(a)`|多角形 $\mathrm{A}$ は凸性を満たすか．||
|`monotone_chain(ps, 凸包の辺上にある点を含まないか = true)`|点集合 $\mathrm{ps}$ の凸包|座標幅 $w$ のとき，頂点数は $O(\sqrt{w})$ 個である．|
|`cut_convex(a, b)`|直線 $\mathrm{B}$ で凸多角形 $\mathrm{A}$ を切断したときの左側の凸多角形||
|`rotating_calipers(a)`|凸多角形 $\mathrm{A}$ の直径||


## 参考

- https://www.ioi-jp.org/camp/2017/2017-sp_camp-hide.pdf
- https://sen-comp.hatenablog.com/archive/category/%E3%80%8C%E5%9F%BA%E7%A4%8E%E7%9A%84%E8%A8%88%E7%AE%97%E5%B9%BE%E4%BD%95%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA%E3%81%AE%E4%BD%9C%E3%82%8A%E6%96%B9%E3%80%8D
- http://www.deqnotes.net/acmicpc/2d_geometry/
- https://ei1333.github.io/luzhiled/snippets/geometry/template.html

最近点対
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.324-326，マイナビ出版（2012）

接点
- https://mathtrain.jp/ennosessen

2円の共通接線の本数
- http://www.e-learning-jp.net/teach_math/mathA/text_1/6/11/001a.htm

2円の共通接線
- http://nutsu.com/blog/2007/102601_as_circletest6.html

多角形の面積
- https://blog.goo.ne.jp/m4g/e/82eb68689c322dc43d52ce16b29a9a74

2円の共通部分の面積
- https://drken1215.hatenablog.com/entry/2020/02/02/005800

点の多角形に対する内外判定
- https://www.nttpc.co.jp/technology/number_algorithm.html


## ToDo

- https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc
- 3次元幾何学
  - https://github.com/beet-aizu/library/tree/master/geometry/3D
  - https://lumakernel.github.io/ecasdqina/geometory/geometory3D
  - https://github.com/drken1215/algorithm/blob/master/Geometry/basic_elements_3D.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Geometry/3DGeometry.cpp
  - 3次元凸包
    - https://lumakernel.github.io/ecasdqina/geometory/ConvexHull3D
    - https://www.slideshare.net/abc3141/3-65377198
- monotone chain 以外の凸包を求めるアルゴリズム
  - https://www.jaist.ac.jp/~uehara/course/2014/i481f/pdf/ppt-3.pdf
  - http://www-ikn.ist.hokudai.ac.jp/~k-sekine/slides/convexhull.pdf
  - http://www.thothchildren.com/chapter/5b268e086298160664e807e9
- 凸包の併合
  - https://atcoder.jp/contests/abc244/tasks/abc244_h
  - https://twitter.com/tatyam_prime/status/1505549013260537858
- 動的凸包
  - https://codeforces.com/blog/entry/75929
  - https://judge.yosupo.jp/problem/convex_layers
  - https://atcoder.jp/contests/geocon2013/tasks/geocon2013_c
  - https://atcoder.jp/contests/abc244/tasks/abc244_h
- 線分アレンジメント
  - https://github.com/ei1333/library/blob/master/geometry/template.cpp
  - https://ei1333.github.io/luzhiled/snippets/geometry/template.html
  - https://ei1333.github.io/algorithm/segment-arrangement.html
  - https://github.com/beet-aizu/library/blob/master/geometry/geometry.cpp
  - https://tubo28.me/compprog/algorithm/segment-arrangement/
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/segment_arrangement.cc
  - http://www.prefield.com/algorithm/geometry/segment_arrangement.html
  - https://github.com/primenumber/ProconLib/blob/master/Geometry/Arrangement.cpp
  - https://onlinejudge.u-aizu.ac.jp/problems/1033
- 直線アレンジメント
  - http://www.prefield.com/algorithm/geometry/walk_arrangement.html
  - https://nya3.jp/libicpc/#%E5%B9%BE%E4%BD%95/%E3%81%9D%E3%81%AE%E4%BB%96/%E3%82%A2%E3%83%AC%E3%83%B3%E3%82%B8%E3%83%A1%E3%83%B3%E3%83%88
- 円と多角形の共通部分の面積
  - https://github.com/ei1333/library/blob/master/geometry/template.cpp
  - https://ei1333.github.io/luzhiled/snippets/geometry/template.html
  - https://github.com/beet-aizu/library/blob/master/geometry/geometry.cpp
  - https://drken1215.hatenablog.com/entry/2020/02/02/091000
  - https://github.com/drken1215/algorithm/blob/master/Geometry/area_common_circle_polygon.cpp
  - http://kyopro.hateblo.jp/entry/2019/08/01/192232
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/not522/20130728/1374979041.html
  - https://twitter.com/not_522/status/1008671743584583682
- 円の和集合の面積
  - https://docs.google.com/presentation/d/119Ve9FB0qTzN01P4EKmia-atXMiPSsJGEDWotVZ6GDg
- 点と半直線の距離
  - https://sen-comp.hatenablog.com/entry/2020/03/14/183251#distanceBetweenPointAndRay%E7%82%B9%E3%81%A8%E5%8D%8A%E7%9B%B4%E7%B7%9A%E3%81%AE%E8%B7%9D%E9%9B%A2
- 凸多角形の共通部分
  - http://www.prefield.com/algorithm/geometry/convex_intersect.html
  - http://gihyo.jp/dev/serial/01/geometry/0009
- 点の凸多角形に対する内外判定
  - http://www.prefield.com/algorithm/geometry/convex_contains.html
- 直線から最も遠い凸多角形上の点
  - http://www.prefield.com/algorithm/geometry/convex_extreme.html
- 二等分線
  - https://github.com/beet-aizu/library/blob/master/geometry/geometry.cpp
  - https://github.com/drken1215/algorithm/blob/master/Geometry/convex_cut.cpp
- 点から凸多角形への接線
  - https://tjkendev.github.io/procon-library/python/geometry/convex_polygon_tangent.html
- アポロニウスの円 (circle of Apollonius)
  - https://ja.wikipedia.org/wiki/%E3%82%A2%E3%83%9D%E3%83%AD%E3%83%8B%E3%82%A6%E3%82%B9%E3%81%AE%E5%86%86
  - https://mathtrain.jp/apollonius
  - https://github.com/drken1215/algorithm/blob/master/Geometry/All.cpp
  - https://onlinejudge.u-aizu.ac.jp/problems/1039
- 3点を通る円
  - http://www.prefield.com/algorithm/geometry/misc.html
- ピックの定理 (Pick's theorem)
  - https://ja.wikipedia.org/wiki/%E3%83%94%E3%83%83%E3%82%AF%E3%81%AE%E5%AE%9A%E7%90%86
- 線分の併合
  - http://www.prefield.com/algorithm/geometry/merge_segments.html
  - https://github.com/ei1333/library/blob/master/geometry/template.cpp
  - https://ei1333.github.io/luzhiled/snippets/geometry/template.html
  - https://onlinejudge.u-aizu.ac.jp/problems/1033
- 点位置決定問題 (point location problem)
  - https://en.wikipedia.org/wiki/Point_location
  - http://www.orsj.or.jp/~wiki/wiki/index.php/%E7%82%B9%E4%BD%8D%E7%BD%AE%E6%B1%BA%E5%AE%9A
  - https://ikatakos.com/pot/programming_algorithm/geometry/planar_point_location
  - http://www-imai.is.s.u-tokyo.ac.jp/~tsuyoshi/tmp/compgeo-20040608.pdf
  - http://www.prefield.com/algorithm/geometry/point_location.html
- 串刺し問題
  - http://www.prefield.com/algorithm/geometry/stabbing_line.html
- 耳分解 (ear decomposition)
  - https://en.wikipedia.org/wiki/Ear_decomposition
  - http://www.prefield.com/algorithm/geometry/triangulate.html
- 多角形の平行移動
  - http://www.prefield.com/algorithm/geometry/shrink_polygon.html
- ドロネー図 (delaunay diagram)
  - https://ja.wikipedia.org/wiki/%E3%83%89%E3%83%AD%E3%83%8D%E3%83%BC%E5%9B%B3
  - https://www.slideshare.net/Kinokkory/ss-25736696
  - http://www.orsj.or.jp/~wiki/wiki/index.php/%E3%83%89%E3%83%AD%E3%83%8D%E3%83%BC%E5%9B%B3
  - http://www.thothchildren.com/chapter/5bded85141f88f267247fdc6
  - http://hadashia.hatenablog.com/entry/2018/10/11/194602
  - http://www.prefield.com/algorithm/geometry/delaunay.html
- kd 木 (k-d tree)
  - https://ja.wikipedia.org/wiki/Kd%E6%9C%A8
  - https://www.slideshare.net/okuraofvegetable/ss-65377588
  - https://trap.jp/post/1489/
  - https://twitter.com/noshi91/status/1395285823403167745
  - https://github.com/beet-aizu/library/blob/master/datastructure/kdtree.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Structure/kdTree.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/kd_tree.cc
  - http://www.prefield.com/algorithm/geometry/kdtree.html
  - https://tjkendev.github.io/procon-library/cpp/range_query/kd-tree.html
  - https://atcoder.jp/contests/abc234/tasks/abc234_h
  - https://atcoder.jp/contests/abc234/submissions/28417490
  - randomized k-d tree
    - https://github.com/spaghetti-source/algorithm/blob/master/geometry/randomized_kd_tree.cc
    - https://www.slideshare.net/keisukeumezawa5/scalable-nearest-neighbor-algorithms-for-high-dimensional-data-71772599
- BK-tree
  - https://en.wikipedia.org/wiki/BK-tree
  - https://postd.cc/bk-tree/
  - https://postd.cc/symspell-vs-bk-tree-100x-faster-fuzzy-string-search-spell-checking/
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/bk_tree.cc
  - http://agtn.hatenablog.com/entry/2017/05/13/183310
- vantage-point tree (VP tree)
  - https://en.wikipedia.org/wiki/Vantage-point_tree
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/vantage_point_tree.cc
- rectilinear minimum spanning tree
  - https://en.wikipedia.org/wiki/Rectilinear_minimum_spanning_tree
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/rectilinear_mst.cc
- 双対変換
  - http://www.prefield.com/algorithm/geometry/dual_transformation.html
- 双対グラフ (dual graph)
  - https://en.wikipedia.org/wiki/Dual_graph
  - https://firiexp.github.io/library/library/geometry/dualgraph.cpp.html
  - https://github.com/primenumber/ProconLib/blob/master/Geometry/DualGraph.cpp
  - https://onlinejudge.u-aizu.ac.jp/problems/0273
- 斜方投射
  - https://github.com/beet-aizu/library/blob/master/geometry/projectilemotion.cpp
- random ball cover
  - http://www.lcayton.com/rbc.pdf
  - http://jsatml.blogspot.com/2012/10/random-ball-cover.html
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/random_ball_cover.cc
- On Finding the Maxima of a Set of Vectors
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/coordinate_domination.cc
- タクシー幾何学 (taxicab geometry)
  - https://en.wikipedia.org/wiki/Taxicab_geometry
- 問題集
  - https://gist.github.com/MiSawa/16d5f84cf66fd2913c82
- 三角形の外心 / 内心 / 垂心


## Verified

- [単位ベクトル](https://atcoder.jp/contests/abc246/submissions/30680516)
- [`ccw(a, b, c)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_1_C/review/4325588/emthrm/C++14)
- ~~$\angle{\mathrm{ABC}}$~~
- [最近点対](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_5_A/review/4325777/emthrm/C++14)
- [射影](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_1_A/review/4325794/emthrm/C++14)
- [鏡映](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_1_B/review/4325814/emthrm/C++14)
- [平行](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_A/review/4325838/emthrm/C++14)
- [垂直](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_A/review/4325838/emthrm/C++14)
- [点と線分の交差判定](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_D/review/4325929/emthrm/C++14)
- [2線分の交差判定](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_B/review/4325860/emthrm/C++14)
- ~~点と直線の交差判定~~
- ~~線分と直線の交差判定~~
- ~~2直線の交差判定~~
- ~~点と円の交差判定~~
- [線分と円の交差判定](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2276/review/4339412/emthrm/C++14)
- ~~直線と円の交差判定~~
- ~~2円の交差判定~~
- [2直線の交点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_4_C/review/4326103/emthrm/C++14)
- [2線分の交点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_C/review/4325877/emthrm/C++14)
- ~~線分と直線の交点~~
- [直線と円の交点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_D/review/4325892/emthrm/C++14)
- [線分と円の交点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2316/review/4345536/emthrm/C++14)
- [2円の交点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_E/review/4325909/emthrm/C++14)
- [2点の距離](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_F/review/4325939/emthrm/C++14)
- [点と線分の距離](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_D/review/4325929/emthrm/C++14)
- [2線分の距離](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_2_D/review/4325929/emthrm/C++14)
- ~~点と直線の距離~~
- ~~線分と直線の距離~~
- ~~2直線の距離~~
- [接点](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_F/review/4325939/emthrm/C++14)
- [2円の共通接線の本数](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_A/review/4325959/emthrm/C++14)
- [2円の共通接線](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_G/review/4325977/emthrm/C++14)
- [2円の共通部分の面積](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_7_I/review/4967134/emthrm/C++17)
- [多角形の面積](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_3_A/review/4326007/emthrm/C++14)
- ~~多角形の重心~~
- [多角形に対する点の内外判定](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_3_C/review/4326013/emthrm/C++14)
- [凸性判定](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_3_B/review/4326091/emthrm/C++14)
- [凸包](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_4_A/review/4326095/emthrm/C++14)
- [凸多角形の切断](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_4_C/review/4326103/emthrm/C++14)
- [凸多角形の直径](https://onlinejudge.u-aizu.ac.jp/solutions/problem/CGL_4_B/review/4326112/emthrm/C++14)
