---
title: 計算幾何学 (computational geometry)
documentation_of: //include/emthrm/geometry/geometry.hpp
---


## 時間計算量

||時間計算量|
|:--|:--|
|最近点対|$O(N\log{N})$|
|多角形の面積|$O(N)$|
|多角形の重心|$O(N)$|
|多角形に対する点の内外判定|$O(N)$|
|凸性判定|$O(N)$|
|monotone chain|$O(N\log{N})$|
|凸多角形の切断|$O(N)$|
|キャリパー法 (rotating calipers)|$O(N)$|


## 仕様

|名前|説明・戻り値|備考|
|:--|:--|:--|
|`Real`|`double`||
|`int sgn(const Real x);`|$\begin{cases} 1 & (x > \varepsilon) \\\\ -1 & (x < -\varepsilon) \\\\ 0 & (\text{otherwise}) \end{cases}$|$\varepsilon = 10^{-8}$|
|`Real degree_to_radian(const Real d);`|$\frac{\pi d}{180}\,\mathrm{rad}$||
|`Real radian_to_degree(const Real r);`|$(\frac{180r}{\pi})^\circ$||


### 点

```cpp
struct Point;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`Real x`|$x$ 座標|
|`Real y`|$y$ 座標|

#### メンバ変数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit Point(const Real x = 0, const Real y = 0);`|点 $(x, y)$ を表すオブジェクトを構築する。||
|`Real abs() const;`|$\lVert \boldsymbol{p} \rVert$||
|`Real arg() const;`|$\arg(x + iy)$|$[0, 2\pi)$|
|`Real norm() const;`|${\lVert \boldsymbol{p} \rVert}^2$||
|`Point rotate(const Real angle) const;`|原点周りに $\mathrm{angle}$ だけ回転させたときの座標 $(x^{\prime}, y^{\prime})$|$\begin{cases} x^{\prime} = x\cos(\mathrm{angle}) - y\sin(\mathrm{angle}) \\\\ y^{\prime} = x\sin(\mathrm{angle}) + y\cos(\mathrm{angle}) \end{cases}$|
|`Point& operator+=(const Point& p);`<br>`Point& operator-=(const Point& p);`<br>`Point& operator*=(const Real k);`<br>`Point& operator/=(const Real k)`<br>`Point operator+(const Point& p);`<br>`Point operator-(const Point& p);`<br>`Point operator*(const Real k);`<br>`Point operator/(const Real k);`||
|`std::partial_ordering operator<=>(const Point& p) const;`|三方比較演算子||
|`Point operator+() const;`|$(x, y)$||
|`Point operator-() const;`|$(-x, -y)$||
|`friend std::ostream& operator<<(std::ostream& os, const Point& p);`|||
|`friend std::istream& operator>>(std::istream& is, Point& p);`|||


### 線分

```cpp
struct Segment;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`Point s`<br>`Point t`|端点|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Segment(const Point& s = Point(0, 0), const Point& t = Point(0, 0));`|端点 $s, t$ の線分を表すオブジェクトを構築する。|


### 直線

```cpp
struct Line : Segment;
```

#### メンバ関数

|名前|効果|備考|
|:--|:--|:--|
||継承コンストラクタ||
|`explicit Line(const Real a, const Real b, const Real c);`|直線 $ax + by + c = 0$ を表すオブジェクトを構築する。|`s`, `t` には代表する2点を格納する。|


### 円

```cpp
struct Circle;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`Point p`|中心|
|`Real r`|半径|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Circle(const Point& p = Point(0, 0), const Real r = 0);`|コンストラクタ|


### 多角形

|名前|説明|要件|
|:--|:--|:--|
|`Polygon`|`std::vector<Point>`|頂点は反時計回りに並ぶ。|


### ライブラリ

|名前|戻り値|備考|
|:--|:--|:--|
|`Point unit_vector(const Point& p);`|ベクトル $p$ の単位ベクトル||
|`std::tuple<Point, Point> normal_unit_vector(const Point& p);`|ベクトル $p$ の単位法線ベクトル|
|`Real cross(const Point& a, const Point& b);`|$\boldsymbol{a} \times \boldsymbol{b}$||
|`Real dot(const Point& a, const Point& b);`|$\boldsymbol{a} \cdot \boldsymbol{b}$||
|`int ccw(const Point& a, const Point& b, const Point& c);`|$\begin{cases} -2 & (\mathrm{A}, \mathrm{B}, \mathrm{C} \text{ の順で一直線上に並ぶ。}) \\\\ -1 & (\mathrm{AB} \text{ から見て } \mathrm{C} \text{ は右側にある。}) \\\\ 0 & (\mathrm{A}, \mathrm{C}, \mathrm{B} \text{ の順で一直線上に並ぶ。}) \\\\ 1 & (\mathrm{AB} \text{ から見て } \mathrm{C} \text{ は左側にある。}) \\\\ 2 & (\mathrm{C}, \mathrm{A}, \mathrm{B} \text{ の順で一直線上に並ぶ。}) \end{cases}$||
|`Real get_angle(const Point& a, const Point& b, const Point& c);`|$\angle{\mathrm{ABC}}$||
|`Real closest_pair(std::vector<Point> ps);`|点集合 $\mathrm{ps}$ の最近点対間距離||
|`Point projection(const Segment& a, const Point& b);`|点 $\mathrm{A}$ に対する点 $\mathrm{B}$ の射影||
|`Point reflection(const Segment& a, const Point& b);`|点 $\mathrm{A}$ に対する点 $\mathrm{B}$ の鏡映||
|`bool is_parallel(const Segment& a, const Segment& b);`|$\boldsymbol{a} \parallel \boldsymbol{b}$|$\Leftrightarrow \boldsymbol{a} \times \boldsymbol{b} = 0$|
|`bool is_orthogonal(const Segment& a, const Segment& b);`|$\boldsymbol{a} \perp \boldsymbol{b}$|$\Leftrightarrow \boldsymbol{a} \cdot \boldsymbol{b} = 0$|
|`bool has_intersected(const Segment& a, const Point& b);`<br>`bool has_intersected(const Segment& a, const Segment& b);`<br>`bool has_intersected(const Line& a, const Point& b);`<br>`bool has_intersected(const Line& a, const Segment& b);`<br>`bool has_intersected(const Line& a, const Line& b);`<br>`bool has_intersected(const Circle& a, const Point& b);`<br>`bool has_intersected(const Circle& a, const Segment& b);`<br>`bool has_intersected(const Circle& a, const Line& b);`<br>`bool has_intersected(const Circle& a, const Circle& b);`|$\mathrm{A}$ と $\mathrm{B}$ は交差しているか。||
|`Point intersection(const Line& a, const Line& b);`<br>`Point intersection(const Segment& a, const Segment& b);`<br>`Point intersection(const Line& a, const Segment& b);`<br>`std::vector<Point> intersection(const Circle& a, const Line& b);`<br>`std::vector<Point> intersection(const Circle& a, const Segment& b);`<br>`std::vector<Point> intersection(const Circle& a, const Circle& b);`|$\mathrm{A}$ と $\mathrm{B}$ の交点||
|`Real distance(const Point& a, const Point& b);`<br>`Real distance(const Segment& a, const Point& b);`<br>`Real distance(const Segment& a, const Segment& b);`<br>`Real distance(const Line& a, const Point& b);`<br>`Real distance(const Line& a, const Segment& b);`<br>`Real distance(const Line& a, const Line& b);`|$\mathrm{A}$ と $\mathrm{B}$ の距離||
|`std::vector<Point> tangency(const Circle& a, const Point& b);`|点 $\mathrm{B}$ から円 $\mathrm{A}$ に引いた接線の接点|円 $(x - a)^2 + (y - b)^2 = r^2$ 上の点 $(x_0, y_0)$ における接線の方程式は $(x_0 - a)(x - a) + (y_0 - b)(y - b) = r^2$ である。|
|`int common_tangent_num(const Circle& a, const Circle& b);`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通接線の本数||
|`std::vector<Line> common_tangent(const Circle& a, const Circle& b);`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通接線|2円が接していないとき、`s` は円 $\mathrm{A}$ における接点、`t` は円 $\mathrm{B}$ における接点が格納される。|
|`Real intersection_area(const Circle& a, const Circle& b);`|円 $\mathrm{A}$ と円 $\mathrm{B}$ の共通部分の面積||
|`Real area(Polygon a);`|多角形 $\mathrm{A}$ の面積||
|`Point centroid(Polygon a);`|多角形 $\mathrm{A}$ の重心||
|`int contains(Polygon a, const Point &b);`|点 $\mathrm{B}$ は多角形 $\mathrm{A}$ の内部に存在するか。|`0` は外部、`1` は線上、`2` は内部を表す。|
|`bool is_convex(Polygon a);`|多角形 $\mathrm{A}$ は凸性を満たすか。||
|`template <bool IS_TIGHT = true> Polygon monotone_chain(std::vector<Point> ps);`|点集合 $\mathrm{ps}$ の凸包|`IS_TIGHT` は凸包の辺上にある点を含まないかを表す。<br>座標幅 $w$ のとき、頂点数は $O(\sqrt{w})$ 個である。|
|`Polygon cut_convex(Polygon a, const Line& b);`|直線 $\mathrm{B}$ で凸多角形 $\mathrm{A}$ を切断したときの左側の凸多角形||
|`std::tuple<Point, Point> rotating_calipers(Polygon a);`|凸多角形 $\mathrm{A}$ の直径||


## 参考文献

- https://www.ioi-jp.org/camp/2017/2017-sp_camp-hide.pdf
- https://sen-comp.hatenablog.com/archive/category/%E3%80%8C%E5%9F%BA%E7%A4%8E%E7%9A%84%E8%A8%88%E7%AE%97%E5%B9%BE%E4%BD%95%E3%83%A9%E3%82%A4%E3%83%96%E3%83%A9%E3%83%AA%E3%81%AE%E4%BD%9C%E3%82%8A%E6%96%B9%E3%80%8D
- http://www.deqnotes.net/acmicpc/2d_geometry/
- https://ei1333.github.io/luzhiled/snippets/geometry/template.html

最近点対
- Jon Louis Bentley and Michael Ian Shamos: Divide-and-conquer in multidimensional space, *STOC '76: Proceedings of the eighth annual ACM symposium on Theory of computing*, pp. 220–230 (1976). https://doi.org/10.1145/800113.803652
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

monotone chain
- A.M. Andrew: Another efficient algorithm for convex hulls in two dimensions, *
Information Processing Letters*, Vol. 9, No. 5, pp. 216–219 (1979). https://doi.org/10.1016/0020-0190(79)90072-3

キャリパー法
- Michael Ian Shamos: Computational geometry (1978).


## TODO

- https://github.com/spaghetti-source/algorithm/blob/master/geometry/_geom.cc
- 3次元幾何学
  - https://github.com/beet-aizu/library/tree/master/geometry/3D
  - ~~https://lumakernel.github.io/ecasdqina/geometory/geometory3D~~
  - https://github.com/drken1215/algorithm/blob/master/Geometry/basic_elements_3D.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Geometry/3DGeometry.cpp
  - https://mugen1337.github.io/procon/Geometry3D/all.cpp
  - https://sotanishy.github.io/cp-library-cpp/geometry/geometry3d.hpp
  - 3次元凸包
    - ~~https://lumakernel.github.io/ecasdqina/geometory/ConvexHull3D~~
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
  - ~~http://www.prefield.com/algorithm/geometry/segment_arrangement.html~~
  - https://github.com/primenumber/ProconLib/blob/master/Geometry/Arrangement.cpp
  - https://onlinejudge.u-aizu.ac.jp/problems/1033
- 直線アレンジメント
  - ~~http://www.prefield.com/algorithm/geometry/walk_arrangement.html~~
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
  - ~~http://www.prefield.com/algorithm/geometry/convex_intersect.html~~
  - http://gihyo.jp/dev/serial/01/geometry/0009
- 点の凸多角形に対する内外判定
  - ~~http://www.prefield.com/algorithm/geometry/convex_contains.html~~
  - https://atcoder.jp/contests/abc296/editorial/6109
- 直線から最も遠い凸多角形上の点
  - ~~http://www.prefield.com/algorithm/geometry/convex_extreme.html~~
- 二等分線
  - https://sotanishy.github.io/cp-library-cpp/geometry/bisector.hpp
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
  - ~~http://www.prefield.com/algorithm/geometry/misc.html~~
- ピックの定理 (Pick's theorem)
  - https://ja.wikipedia.org/wiki/%E3%83%94%E3%83%83%E3%82%AF%E3%81%AE%E5%AE%9A%E7%90%86
  - https://mugen1337.github.io/procon/GeometryInt/CountLattice.cpp
- 線分の併合
  - ~~http://www.prefield.com/algorithm/geometry/merge_segments.html~~
  - https://github.com/ei1333/library/blob/master/geometry/template.cpp
  - https://ei1333.github.io/luzhiled/snippets/geometry/template.html
  - https://onlinejudge.u-aizu.ac.jp/problems/1033
- 点位置決定問題 (point location problem)
  - https://en.wikipedia.org/wiki/Point_location
  - http://www.orsj.or.jp/~wiki/wiki/index.php/%E7%82%B9%E4%BD%8D%E7%BD%AE%E6%B1%BA%E5%AE%9A
  - https://ikatakos.com/pot/programming_algorithm/geometry/planar_point_location
  - http://www-imai.is.s.u-tokyo.ac.jp/~tsuyoshi/tmp/compgeo-20040608.pdf
  - ~~http://www.prefield.com/algorithm/geometry/point_location.html~~
- 串刺し問題
  - ~~http://www.prefield.com/algorithm/geometry/stabbing_line.html~~
- 耳分解 (ear decomposition)
  - https://en.wikipedia.org/wiki/Ear_decomposition
  - ~~http://www.prefield.com/algorithm/geometry/triangulate.html~~
- 多角形の平行移動
  - ~~http://www.prefield.com/algorithm/geometry/shrink_polygon.html~~
- ドロネー図 (delaunay diagram)
  - https://ja.wikipedia.org/wiki/%E3%83%89%E3%83%AD%E3%83%8D%E3%83%BC%E5%9B%B3
  - https://www.slideshare.net/Kinokkory/ss-25736696
  - http://www.orsj.or.jp/~wiki/wiki/index.php/%E3%83%89%E3%83%AD%E3%83%8D%E3%83%BC%E5%9B%B3
  - http://www.thothchildren.com/chapter/5bded85141f88f267247fdc6
  - http://hadashia.hatenablog.com/entry/2018/10/11/194602
  - ~~http://www.prefield.com/algorithm/geometry/delaunay.html~~
  - https://sotanishy.github.io/cp-library-cpp/geometry/delaunay_diagram.hpp
- kd 木 (k-d tree)
  - https://ja.wikipedia.org/wiki/Kd%E6%9C%A8
  - https://www.slideshare.net/okuraofvegetable/ss-65377588
  - https://trap.jp/post/1489/
  - https://twitter.com/noshi91/status/1395285823403167745
  - https://github.com/beet-aizu/library/blob/master/datastructure/kdtree.cpp
  - https://github.com/primenumber/ProconLib/blob/master/Structure/kdTree.cpp
  - https://github.com/spaghetti-source/algorithm/blob/master/geometry/kd_tree.cc
  - ~~http://www.prefield.com/algorithm/geometry/kdtree.html~~
  - https://tjkendev.github.io/procon-library/cpp/range_query/kd-tree.html
  - https://mugen1337.github.io/procon/DataStructure/KDTree.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/kd_tree.cpp
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
  - ~~http://www.prefield.com/algorithm/geometry/dual_transformation.html~~
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
- 最遠点対
  - https://judge.yosupo.jp/problem/furthest_pair
- タクシー幾何学 (taxicab geometry)
  - https://en.wikipedia.org/wiki/Taxicab_geometry
- 問題集
  - https://gist.github.com/MiSawa/16d5f84cf66fd2913c82
- 三角形の外心 / 内心 / 垂心


## Submissons

- [点の回転](https://atcoder.jp/contests/abc259/submissions/33133157)
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
