# Aliens DP

$n$ 頂点有向非巡回グラフ $G = (V, E \mathrel{:=} \lbrace (i, j) \in \lbrace 0, 1, \ldots, n - 1 \rbrace \times \lbrace 0, 1, \ldots, n - 1 \rbrace \mid i < j \rbrace)$ を考える。辺 $(i, j) \in E$ の重みを $c(i, j) \in \mathbb{Z}$ とおく。

$c$ が [concave quadrangle inequality](../../../docs/dynamic_programming/knuth_yao_speedup.md) を満たすならば、ちょうど $d$ 辺通る始点 $0$、終点 $n - 1$ の道の内、最短のものの長さを高速に求められる。

## 時間計算量

$G$ 上で始点 $0$、終点 $n - 1$ の最短路長を $O(f(N))$ 時間で求められるとおくと $O(f(N) \log{\max_{(i, j) \in E} \lvert c(i, j)} \rvert)$

## 参考文献

- https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge
- https://github.com/LumaKernel/lib-cpp/blob/eb360cde5ad3e86a380de5745c7c741cfa165c37/src/dynamic-programming/speedup/AlienDP.md
- https://hitoare.hatenablog.com/entry/2023/06/22/212634
- https://twitter.com/kyort0n/status/1378225258289766406
- https://twitter.com/noshi91/status/1481498494808784901
- https://twitter.com/noshi91/status/1436696351547412493

## TODO

- https://noshi91.hatenablog.com/entry/2023/11/20/052227
- https://r-th.hatenablog.com/entry/2023/11/25/235711
- https://shino16.github.io/blog/post/algo/aliens_dp/
- https://twitter.com/shino16_cp/status/1729413813802254627
- 通る辺の本数を $\lbrack d - k, d \rbrack$ とするとき
  - https://noshi91.hatenablog.com/entry/2022/01/13/001217
  - https://twitter.com/noshi91/status/1481465898062213123
  - https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge#%E3%81%9D%E3%81%AE%E4%BB%96
  - https://github.com/LumaKernel/lib-cpp/blob/eb360cde5ad3e86a380de5745c7c741cfa165c37/src/dynamic-programming/speedup/AlienDP.md#k%E3%82%92%E3%81%82%E3%82%8B%E7%AF%84%E5%9B%B2%E3%81%A8%E3%81%99%E3%82%8B%E3%81%A8%E3%81%8D
- [LARSCH algorithm](../../../docs/dynamic_programming/knuth_yao_speedup.md) を用いた高速化
  - https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge#%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
- 三分探索の上界と下界
  - https://twitter.com/noshi91/status/1481302364330274817
- $l(\lambda)$ を満たす最短路の内、通る辺の数が最小のもの
  - https://twitter.com/noshi91/status/1481537569301368836
- 実装上の工夫
  - https://twitter.com/tko919_/status/1480569460172156929
  - https://twitter.com/noshi91/status/1481285572333551618
  - https://twitter.com/maspy_stars/status/1436701397123096585
- 問題例 "[Partitions and Inversions](https://yukicoder.me/problems/no/1867)"
- 問題例 "[New Year and Handle Change](https://codeforces.com/contest/1279/problem/F)"
  - https://tiramistercp.hatenablog.com/entry/ecr079-f
- 問題例 "[Red and Blue Lamps](https://atcoder.jp/contests/abc305/tasks/abc305_h)"
- 問題例 "[Subsegments with Large Sums](https://atcoder.jp/contests/arc168/tasks/arc168_e)"
  - https://twitter.com/nok0_kyopro/status/1726239631606505598
  - https://twitter.com/hitoare1/status/1726239855351599144
  - https://twitter.com/square10011/status/1726241277426237569
  - https://twitter.com/noshi91/status/1726241668721258850
  - https://twitter.com/_su1sen/status/1726242607943364632
  - https://twitter.com/maspy_stars/status/1726243099733860820


# Burrows–Wheeler 変換 (Burrows–Wheeler transform)

## TODO
- https://ja.wikipedia.org/wiki/%E3%83%96%E3%83%AD%E3%83%83%E3%82%AF%E3%82%BD%E3%83%BC%E3%83%88
- https://docs.google.com/presentation/d/1Sx_d4Mu2dO39cF7xWyEGU7Uqby996dll5Ef9VfnfZYU


# Cartesian tree

## TODO
- https://en.wikipedia.org/wiki/Cartesian_tree
- https://kmyk.github.io/blog/blog/2020/07/27/recursion-on-cartesian-tree/
- https://github.com/spaghetti-source/algorithm/blob/master/data_structure/cartesian_tree.cc
- https://sotanishy.github.io/cp-library-cpp/tree/cartesian_tree.cpp
- https://judge.yosupo.jp/problem/cartesian_tree
- https://atcoder.jp/contests/abc282/tasks/abc282_h


# color-coding

## TODO
- https://en.wikipedia.org/wiki/Color-coding
- https://tech.preferred.jp/ja/blog/color-coding/


# dominator tree

## TODO
- https://en.wikipedia.org/wiki/Dominator_(graph_theory)
- https://drive.google.com/drive/folders/1haW6Bv6LYmJQlZxMPcEbJP5HXW2A-Kbf
- https://knshnb.github.io/competitive_library/library/src/Graph/DominatorTree.hpp.html
- https://codeforces.com/blog/entry/22811
- http://sigma425.hatenablog.com/entry/2015/12/25/224053
- https://github.com/ei1333/library/blob/master/graph/others/dominator-tree.hpp
- https://sotanishy.github.io/cp-library-cpp/graph/dominator_tree.cpp
- https://judge.yosupo.jp/problem/dominatortree


# Dulmage–Mendelsohn decomposition

## TODO
- https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition
- https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp
- https://sotanishy.github.io/cp-library-cpp/flow/dm_decomposition.cpp
- https://yukicoder.me/problems/no/1615
- https://atcoder.jp/contests/abc223/tasks/abc223_g
- https://icpc.iisf.or.jp/past-icpc/domestic2021/contest/all_ja.html#section_F
- https://yukicoder.me/contests/361
- https://atcoder.jp/contests/jag2017summer-day1/tasks/jag2017summer_day1_i


# Hackenbush

## TODO
- https://en.wikipedia.org/wiki/Hackenbush
- https://www.link.cs.cmu.edu/15859-s11/notes/Hackenbush.pdf
- https://klein.mit.edu/~rstan/transparencies/games.pdf
- Green Hackenbush
  - https://codeforces.com/contest/1610/problem/I
  - https://atcoder.jp/contests/agc017/tasks/agc017_d


# Lenstra–Lenstra–Lovász lattice basis reduction algorithm

## TODO
- https://en.wikipedia.org/wiki/Lenstra%E2%80%93Lenstra%E2%80%93Lov%C3%A1sz_lattice_basis_reduction_algorithm
- https://yukicoder.me/problems/no/3014


# lexicographic breadth-first search

## TODO
- https://en.wikipedia.org/wiki/Lexicographic_breadth-first_search
- https://chocobaby-aporo.hatenablog.com/entry/2018/12/25/011447
- https://www.jaist.ac.jp/~uehara/etc/la/02/index.html


# link-cut tree

## TODO
- https://www.hamayanhamayan.com/entry/2018/07/13/093346
- https://www.slideshare.net/iwiwi/2-12188845
- ~~https://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376~~
- https://ei1333.hateblo.jp/entry/2018/05/29/011140
- https://ngtkana.hatenablog.com/entry/2024/05/11/033439
- https://smijake3.hatenablog.com/entry/2018/11/19/085919
- https://kopricky.github.io/code/DataStructure_OnGraph/link_cut_tree.html
- http://blue-jam.hatenablog.com/entry/2013/06/27/182049
- ~~http://beet-aizu.hatenablog.com/entry/2019/06/08/221833~~
- ~~http://beet-aizu.hatenablog.com/entry/2019/12/25/175809~~
- https://ei1333.hateblo.jp/entry/2019/06/13/133736
- https://ei1333.github.io/luzhiled/snippets/structure/link-cut-tree.html
- https://ei1333.github.io/luzhiled/snippets/structure/link-cut-tree-subtree.html
- https://github.com/ei1333/library/tree/master/structure/lct
- https://github.com/beet-aizu/library/tree/master/linkcuttree
- ~~https://lumakernel.github.io/ecasdqina/data-structure/misc/LinkCutTree~~
- https://github.com/spaghetti-source/algorithm/blob/master/graph/link_cut_tree.cc
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!LinkCutTree.cpp~~
- https://mugen1337.github.io/procon/Tree/LinkCutTree.cpp
- https://mugen1337.github.io/procon/Tree/LazyLinkCutTree.cpp
- https://sotanishy.github.io/cp-library-cpp/tree/link_cut_tree.cpp
- https://topcoder-g-hatena-ne-jp.jag-icpc.org/Mi_Sawa/20140320.html
- https://www.youtube.com/watch?v=sAN6hdpzhBE
- https://judge.yosupo.jp/problem/vertex_set_path_composite
- https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
- https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
- https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
- https://judge.yosupo.jp/problem/dynamic_tree_subtree_add_subtree_sum
- https://atcoder.jp/contests/abc235/tasks/abc235_e
- https://atcoder.jp/contests/pakencamp-2021-day3/tasks/pakencamp_2021_day3_g
- https://yukicoder.me/problems/no/2296


# Lyndon factorization

## TODO
- https://en.wikipedia.org/wiki/Lyndon_word
- https://qiita.com/nakashi18/items/66882bd6e0127174267a
- https://codeforces.com/blog/entry/89629
- https://judge.yosupo.jp/problem/lyndon_factorization


# Menger's theorem

## TODO
- https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%B3%E3%82%AC%E3%83%BC%E3%81%AE%E5%AE%9A%E7%90%86
- https://37zigen.com/menger-theorem/
- https://atcoder.jp/contests/utpc2021/editorial/3577


# permutation tree

## TODO
- https://codeforces.com/blog/entry/78898
- https://twitter.com/noshi91/status/1477934158911782915
- https://twitter.com/hotmanww/status/1477928012629049347
- https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/permutation_tree.rs
- https://twitter.com/rsat__m/status/1452104874619904001
- https://judge.yosupo.jp/problem/common_interval_decomposition_tree
- https://yukicoder.me/problems/no/1720
- https://atcoder.jp/contests/abc248/tasks/abc248_h


# policy based data structures

## TODO
- https://xuzijian629.hatenablog.com/entry/2018/12/01/000010
- http://hogloid.hatenablog.com/entry/2014/09/23/132440
- https://codeforces.com/blog/entry/11080
- https://codeforces.com/blog/entry/13279


# rope

## TODO
- https://en.wikipedia.org/wiki/Rope_(data_structure)
- 永続ロープ
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/persistent_rope.cc


# sack (DSU on tree)

## TODO
- https://noshi91.github.io/algorithm-encyclopedia/dsu-on-tree
- https://codeforces.com/blog/entry/44351
- https://camypaper.bitbucket.io/2016/12/18/adc2016/
- https://github.com/beet-aizu/library/blob/master/tree/sack.cpp
- https://nyaannyaan.github.io/library/tree/dsu-on-tree.hpp
- ~~https://lumakernel.github.io/ecasdqina/graph/DSU-on-Tree~~
- https://yukicoder.me/problems/no/1769


# sliding-window aggregation

## TODO
- https://scrapbox.io/data-structures/Sliding_Window_Aggregation
- https://github.com/ei1333/library/blob/master/structure/others/sliding-window-aggregation.cpp
- https://mugen1337.github.io/procon/DataStructure/SlidingWindowAgregation.cpp
- https://sotanishy.github.io/cp-library-cpp/data-structure/sliding_window_aggregation.cpp
- https://judge.yosupo.jp/problem/queue_operate_all_composite
- https://judge.yosupo.jp/problem/deque_operate_all_composite


# top tree

## TODO
- https://en.wikipedia.org/wiki/Top_tree
- https://scrapbox.io/data-structures/Top_Tree
- https://niuez.hatenablog.com/entry/2019/08/04/191420
- https://niuez.hatenablog.com/entry/2019/06/29/161729
- https://niuez.hatenablog.com/entry/2019/12/14/000036
- https://www.mathenachia.blog/top-trees-intro/
- https://noshi91.hatenablog.com/entry/2022/01/02/004104
- https://twitter.com/noshi91/status/1477348722099253248
- https://twitter.com/noshi91/status/1483744348886171651
- https://zhuanlan.zhihu.com/p/32413108
- https://twitter.com/noshi91/status/1729086719457395021
- https://twitter.com/akakimidori/status/1784851756431843656
- https://twitter.com/noshi91/status/1784870681999544418
- https://twitter.com/noshi91/status/1784894116771303722
- https://twitter.com/noshi91/status/1784897010044170643
- https://twitter.com/noshi91/status/1784903416936014011
- https://twitter.com/maspy_stars/status/1784905023924670836
- https://twitter.com/noshi91/status/1784921788176380339
- https://twitter.com/noshi91/status/1784928169549824395
- https://twitter.com/noshi91/status/1785033952845234177
- https://twitter.com/noshi91/status/1785034216767631796
- https://github.com/beet-aizu/library/tree/master/toptree
- static top tree
  - https://nachiavivias.github.io/cp-library/cpp/tree/static-top-tree.html
  - https://atcoder.jp/contests/abc351/editorial/9910
  - https://twitter.com/tatyam_prime/status/1784900848759500836
  - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
  - 問題例 "[Hash on Tree](https://atcoder.jp/contests/abc351/tasks/abc351_g)"
    - https://twitter.com/kude_coder/status/1784215998616535219
    - https://twitter.com/ChineristA/status/1784216617955762181
    - https://twitter.com/tatyam_prime/status/1784217150166856114
    - https://twitter.com/Cyanmond_mapr/status/1784217270702817383
    - https://twitter.com/_su1sen/status/1784219137092542696
    - https://twitter.com/minato2376/status/1784220736418361780
    - https://twitter.com/kyopro_friends/status/1784221734113362408
- 問題例 "[Dynamic Distance Sum](https://yukicoder.me/problems/no/772)"
  - https://paper.dropbox.com/doc/Top-Tree-ZWtQdaUh68tou1iu0YdRG
- 問題例 "[Query ζone](https://yukicoder.me/problems/no/902)"
- 問題例 "[Do Use Dynamic Tree](https://yukicoder.me/problems/no/1787)"
- 問題例 "[Cut then Connect](https://yukicoder.me/problems/no/1976)"
  - https://yukicoder.me/submissions/769888
- 問題例 "[The Jikka Tree](https://yukicoder.me/problems/no/2258)"


# triangle enumeration

## TODO
- https://www.slideshare.net/catupper/trianguler
- https://sotanishy.github.io/cp-library-cpp/graph/enumerate_triangles.cpp
- https://github.com/yosupo06/library-checker-problems/issues/442


# van Emde Boas tree

## TODO
- https://en.wikipedia.org/wiki/Van_Emde_Boas_tree
- https://twitter.com/hcpc_hokudai/status/1377524137321582594
- https://kopricky.github.io/code/Academic/van_emde_boas_tree.html
- https://natsugiri.hatenablog.com/entry/2016/10/12/021502
- https://kopricky.github.io/code/Academic/van_emde_boas_tree.html
- https://shibh308.hatenablog.com/entry/2020/04/14/232852
- https://twitter.com/noshi91/status/1437808190066810886
- https://atcoder.jp/contests/abc217/tasks/abc217_d


# y-fast trie

## TODO
- https://en.wikipedia.org/wiki/Y-fast_trie
- https://qiita.com/goonew/items/6ffac4b5e48dc05ca884
- https://shibh308.hatenablog.com/entry/2020/04/14/232852
- https://twitter.com/noshi91/status/1437808190066810886
- https://atcoder.jp/contests/abc217/tasks/abc217_d


# ウェーブレット行列 (wavelet matrix)

## TODO
- https://www.hamayanhamayan.com/entry/2017/06/13/103352
- https://takeda25.hatenablog.jp/entry/20130303/1362301095
- http://miti-7.hatenablog.com/entry/2018/04/28/152259
- https://scrapbox.io/data-structures/Wavelet_Matrix
- https://www.dropbox.com/sh/9lknvq4xay709cn/AAAX61z5W1m20MPkJ8V53l5ma/%23WaveletMatrix.cpp?dl=0
- https://www.pandanoir.info/entry/2016/03/01/230031
- https://github.com/MitI-7/Algorithm/wiki/%E3%82%A6%E3%82%A7%E3%83%BC%E3%83%96%E3%83%AC%E3%83%83%E3%83%88%E8%A1%8C%E5%88%97
- https://anta1.hatenadiary.org/entry/20130114/1358113488
- https://docs.google.com/presentation/d/1J7jl8BLHkbukicFzSP7zNYTcwF-DPevCUfVxD4VjzX0
- https://algoogle.hadrori.jp/algorithm/wavelet.html
- https://ei1333.github.io/algorithm/wavelet-matrix.html
- https://ei1333.github.io/luzhiled/snippets/structure/wavelet-matrix.html
- https://github.com/ei1333/library/tree/master/structure/wavelet
- https://github.com/beet-aizu/library/blob/master/datastructure/waveletmatrix.cpp
- https://github.com/spaghetti-source/algorithm/blob/master/data_structure/wavelet_matrix.cc
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletMatrix.cpp~~
- https://sotanishy.github.io/cp-library-cpp/data-structure/wavelet_matrix.cpp
- https://ferin-tech.hatenablog.com/entry/2019/11/09/yukicoder_No.924_%E7%B4%B2%E6%98%9F
- ~~https://wiki.kimiyuki.net/wavelet%20matrix~~
- https://noshi91.hatenablog.com/entry/2021/06/02/165408
- https://twitter.com/noshi91/status/1767146226783584611
- https://judge.yosupo.jp/problem/rectangle_sum


# ウェーブレット木 (wavelet tree)

## TODO
- https://www.slideshare.net/pfi/ss-15916040
- https://takeda25.hatenablog.jp/entry/20120804/1344066875
- https://echizen-tm.hatenadiary.org/entry/20100822/1282489619
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23WaveletTree.cpp~~
- https://jetbead.hatenablog.com/entry/20130202/1359735146
- https://drive.google.com/file/d/1NQb6ZXrPZuWI0gNBhJUQAvONjGqFxgUX


# 永続データ構造 (persistent data structure)

## TODO
- https://www.slideshare.net/qnighy/re-15443018
- https://trap.jp/post/663/
- https://qiita.com/hotman78/items/9c643feae1de087e6fc5
- 永続配列 (persistent array)
  - https://37zigen.com/persistent-array/
  - https://ei1333.github.io/luzhiled/snippets/structure/persistent-array.html
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/persistent_array.cc
  - https://sotanishy.github.io/cp-library-cpp/data-structure/persistent_array.cpp
- 永続キュー
  - https://sotanishy.github.io/cp-library-cpp/data-structure/persistent_queue.cpp
- 永続スタック
  - https://sotanishy.github.io/cp-library-cpp/data-structure/persistent_stack.cpp


# 階乗 (factorial)

$$
  n! = \prod_{i = 1}^n i
$$

### ウィルソンの定理

$$
  (m - 1)! \equiv -1 \pmod{m}
$$

## TODO
- $O(\sqrt{M} \log{M})$ に高速化する。
  - https://suisen-kyopro.hatenablog.com/entry/2023/11/22/201600
  - ~~https://min-25.hatenablog.com/entry/2017/04/10/215046~~
  - https://ei1333.github.io/luzhiled/snippets/math/factorial.html
  - https://codeforces.com/blog/entry/68885
  - https://yukicoder.me/problems/no/502
  - https://judge.yosupo.jp/problem/factorial
  - https://judge.yosupo.jp/problem/many_factorials
- ある素数 $p$ に対して $n! = a p^e$ を満たす $a \bmod p$ を求める。
  - 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.262-263，マイナビ出版（2012）


# ガウス整数 (Gaussian integer)

## TODO
- https://ja.wikipedia.org/wiki/%E3%82%AC%E3%82%A6%E3%82%B9%E6%95%B4%E6%95%B0
- https://mathtrain.jp/gaussianint
- http://aozoragakuen.sakura.ne.jp/suuron/node56.html
- ~~http://arimoto.lolipop.jp/%E3%82%AC%E3%82%A6%E3%82%B9%E3%81%AE%E7%B4%A0%E6%95%B0.pdf~~
- ~~http://www.prefield.com/algorithm/math/isgprime.html~~
- https://judge.yosupo.jp/problem/gcd_of_gaussian_integers


# 簡潔ビットベクトル (succinct indexable dictionaries)

## TODO
- https://ja.wikipedia.org/wiki/%E7%B0%A1%E6%BD%94%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0
- https://misteer.hatenablog.com/entry/bit-vector
- https://drive.google.com/file/d/167ZbJaMlaqsu5PxfrS2pqb7uOVLrqj5Z
- https://atcoder.jp/contests/joi2015ho/submissions/27476606
- https://twitter.com/noimi_kyopro/status/1462789725161287681
- https://sotanishy.github.io/cp-library-cpp/data-structure/bit_vector.cpp


# 木の同型性判定

## TODO
- https://www.hamayanhamayan.com/entry/2017/02/06/233824
- https://github.com/imulan/procon/issues/5
- http://chocobaby-aporo.hatenablog.com/entry/2017/12/05/233027
- https://snuke.hatenablog.com/entry/2017/02/03/054210
- https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
- https://www.slideshare.net/hcpc_hokudai/f-pub-73717800
- https://github.com/ei1333/library/blob/master/graph/tree/tree-isomorphism.hpp
- https://github.com/spaghetti-source/algorithm/blob/master/graph/tree_isomorphism.cc
- ~~https://lumakernel.github.io/ecasdqina/graph/is-same-tree~~
- ~~https://lumakernel.github.io/ecasdqina/string/tree-to-string~~
- https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
- ~~https://kimiyuki.net/writeup/algo/etc/icpc-2016-domestic-f/~~


# グラフの同型性判定

## TODO
- https://ja.wikipedia.org/wiki/%E3%82%B0%E3%83%A9%E3%83%95%E5%90%8C%E5%9E%8B
- ~~http://www.prefield.com/algorithm/graph/isomorphism.html~~
- https://github.com/spaghetti-source/algorithm/blob/master/graph/isomorphism.cc


# 構文解析 (parse)

## TODO
- https://ja.wikipedia.org/wiki/%E6%A7%8B%E6%96%87%E8%A7%A3%E6%9E%90
- https://gist.github.com/draftcode/1357281
- https://www.hamayanhamayan.com/entry/2018/07/13/085956
- https://github.com/beet-aizu/library/blob/master/tools/parse.cpp
- https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2019Day1/problems/C
- 再帰下降構文解析 (recursive descent parsing)
  - ~~http://www.prefield.com/algorithm/string/parser.html~~
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23RecursiveDecentParsing.cpp~~


# ゴモリ・フー木 (Gomory–Hu tree)

## TODO
- https://ja.wikipedia.org/wiki/%E3%82%B4%E3%83%A2%E3%83%AA%E3%83%BB%E3%83%95%E3%83%BC%E6%9C%A8
- ~~http://www.prefield.com/algorithm/graph/gomory_hu.html~~
- https://github.com/spaghetti-source/algorithm/blob/master/graph/gomory_hu_tree.cc


# 順序木

## TODO
- https://drive.google.com/file/d/1s6x_07yD54QVXrIgyUfF4Wu5qzmt1I4U


# 乗法的関数 (multiplicative function)

$n \in \mathbb{N}^+$ に対して定義される数論的関数 $f(n)$ の内、$a \perp b$ を満たす $a, b \in \mathbb{N}^+$ に対して $f(ab) = f(a)f(b)$ が成り立つものである。

## 参考文献
- https://ja.wikipedia.org/wiki/%E4%B9%97%E6%B3%95%E7%9A%84%E9%96%A2%E6%95%B0

## TODO
- https://nyaannyaan.github.io/library/multiplicative-function/sum-of-multiplicative-function.hpp.html
- https://rsk0315.github.io/slides/prime-counting.pdf
- https://atcoder.jp/contests/abc239/tasks/abc239_h


# 線形マトロイドパリティ問題

## TODO
- https://en.wikipedia.org/wiki/Matroid_parity_problem
- https://bigdata.nii.ac.jp/eratokansyasai4/wp-content/uploads/2017/09/f744cb6c19b28f67eacbc10721e1b526.pdf
- https://yukicoder.me/problems/no/1773
- https://yukicoder.me/problems/no/1775


# 中国人郵便配達問題 (Chinese postman problem)

## TODO
- https://ja.wikipedia.org/wiki/%E4%B8%AD%E5%9B%BD%E4%BA%BA%E9%83%B5%E4%BE%BF%E9%85%8D%E9%81%94%E5%95%8F%E9%A1%8C
- ~~http://www.prefield.com/algorithm/graph/undirected_chinese_postman.html~~
- https://tubo28.me/compprog/algorithm/cpp/


# テトレーション (tetration)

## TODO
- https://ja.wikipedia.org/wiki/%E3%83%86%E3%83%88%E3%83%AC%E3%83%BC%E3%82%B7%E3%83%A7%E3%83%B3
- https://yukicoder.me/problems/no/181/editorial
- https://github.com/ei1333/library/blob/master/math/combinatorics/mod-tetration.cpp
- ~~https://github.com/beet-aizu/library/blob/master/math/mtetra.cpp~~
- https://judge.yosupo.jp/problem/tetration_mod


# ヒープ (heap)

## TODO
- https://ja.wikipedia.org/wiki/%E3%83%92%E3%83%BC%E3%83%97
- http://hos.ac/blog/#blog0001
- https://github.com/ei1333/library/tree/ba1135e1610c8fad37bbe5186d0a8442a24fd905/structure/heap
- 二分ヒープ (binary heap)
  - https://ja.wikipedia.org/wiki/%E4%BA%8C%E5%88%86%E3%83%92%E3%83%BC%E3%83%97
  - https://scrapbox.io/data-structures/Binary_Heap
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!BinaryHeap.cpp~~
- radix heap
  - https://en.wikipedia.org/wiki/Radix_heap
  - https://scrapbox.io/data-structures/Radix_Heap
  - https://qiita.com/aqualength/items/1b14919c10360544eb41
  - https://github.com/iwiwi/radix-heap
  - https://ei1333.github.io/algorithm/radix-heap.html
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/Heap/RadixHeap~~
  - https://github.com/spaghetti-source/algorithm/blob/4fdac8202e26def25c1baf9127aaaed6a2c9f7c7/data_structure/radix_heap.cc
  - https://ikatakos.com/pot/programming_algorithm/data_structure/radix_heap
- double-ended priority queue
  - https://en.wikipedia.org/wiki/Double-ended_priority_queue
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20121006/1349491389.html
  - https://tubo28.me/compprog/algorithm/hogloid-heap/
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!IntervalHeap.cpp~~
  - http://natsugiri.hatenablog.com/entry/2016/10/10/035445
  - https://judge.yosupo.jp/problem/double_ended_priority_queue
  - min-max heap
    - https://en.wikipedia.org/wiki/Min-max_heap
    - https://github.com/spaghetti-source/algorithm/blob/4fdac8202e26def25c1baf9127aaaed6a2c9f7c7/data_structure/minmax_heap.cc
  - dual heap
    - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20121006/1349491389.html
  - interval heap
    - https://en.wikipedia.org/wiki/Double-ended_priority_queue#Interval_heaps
    - https://scrapbox.io/data-structures/Interval_Heap
- meldable heap
  - https://en.wikipedia.org/wiki/Randomized_meldable_heap
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120831/1346372776.html
  - https://github.com/spaghetti-source/algorithm/blob/4fdac8202e26def25c1baf9127aaaed6a2c9f7c7/data_structure/persistent_heap.cc
  - https://trap.jp/post/1050/
  - skew heap
    - https://en.wikipedia.org/wiki/Skew_heap
    - https://scrapbox.io/data-structures/Skew_Heap
    - https://ei1333.github.io/algorithm/skew-heap.html
    - https://ei1333.github.io/luzhiled/snippets/structure/skew-heap.html
    - https://github.com/beet-aizu/library/blob/4f26a088ff995dd9fc2612dbbafef9b56bdb0c61/datastructure/skewheap.cpp
    - ~~https://lumakernel.github.io/ecasdqina/data-structure/Heap/SkewHeap~~
    - https://github.com/spaghetti-source/algorithm/blob/4fdac8202e26def25c1baf9127aaaed6a2c9f7c7/data_structure/skew_heap.cc
    - https://github.com/primenumber/ProconLib/blob/f222b2d5a172cf17766b5abcae1987250a552bb8/Structure/SkewHeap.cpp
    - http://kagamiz.hatenablog.com/entry/2013/06/26/210256
    - https://twitter.com/yamerarenaku/status/1085593085931732992
  - leftist heap
    - https://en.wikipedia.org/wiki/Leftist_tree
    - https://scrapbox.io/data-structures/Leftist_Heap
    - ~~https://lumakernel.github.io/ecasdqina/data-structure/Heap/LeftistHeap~~
    - https://github.com/spaghetti-source/algorithm/blob/4fdac8202e26def25c1baf9127aaaed6a2c9f7c7/data_structure/leftist_heap.cc
    - https://mugen1337.github.io/procon/Heap/LeftistHeap.hpp
    - https://mugen1337.github.io/procon/Heap/PersistentLeftistHeap.hpp
    - https://sotanishy.github.io/cp-library-cpp/data-structure/leftist_heap.cpp
  - pairing heap
    - https://en.wikipedia.org/wiki/Pairing_heap
    - https://scrapbox.io/data-structures/Pairing_Heap
    - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120929/1348886107.html
    - https://ei1333.github.io/algorithm/pairing-heap.html
    - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23PairingHeap.cpp~~
  - Fibonacchi heap
    - https://en.wikipedia.org/wiki/Fibonacci_heap


# 非不偏ゲーム (partisan game)

## TODO
- https://en.wikipedia.org/wiki/Partisan_game
- http://www.ivis.co.jp/text/20111102.pdf
- hot game / cold game
  - https://en.wikipedia.org/wiki/Hot_game
  - https://atcoder.jp/contests/abc229/tasks/abc229_h
  - https://twitter.com/noshi91/status/1464590806841696256


# 平衡二分探索木 (self-balancing binary search tree)

## TODO
- https://ja.wikipedia.org/wiki/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E6%9C%A8
- https://www.slideshare.net/iwiwi/2-12188757
- https://scrapbox.io/data-structures/%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E6%9C%A8%E3%81%A8%E3%81%AF
- https://drive.google.com/file/d/1B4DnRVF6aasxZtdgTqIWXY7x3d6Y07Mk
- https://twitter.com/hamamu_kyopro/status/1615009114484248577
- https://twitter.com/noimi_kyopro/status/1619940049348616192
- https://twitter.com/noshi91/status/1425120446169501697
- https://twitter.com/hotmanww/status/1636877141198639104
- https://misawa.github.io/others/meld_binary_search_trees.html
- http://yosupo.hatenablog.com/entry/2014/12/09/222401
- https://github.com/ei1333/library/tree/master/structure/bbst
- https://github.com/beet-aizu/library/tree/master/bbst
- ~~https://lumakernel.github.io/ecasdqina/data-structure/BBST~~
- ~~https://competitive12.blogspot.com/2019/04/treap.html~~
- https://judge.yosupo.jp/problem/range_reverse_range_sum
- randomized binary search tree
  - https://en.wikipedia.org/wiki/Random_binary_tree
  - https://ei1333.github.io/algorithm/rbst.html
  - https://ei1333.github.io/luzhiled/snippets/structure/rbst.html
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/BBST/RBST~~
  - https://github.com/drken1215/algorithm/blob/master/DataStructure/randomized_binary_search_tree.cpp
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23RBST.cpp~~
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23PRBST.cpp~~
  - https://github.com/primenumber/ProconLib/blob/master/Structure/RBST.cpp
  - https://tjkendev.github.io/procon-library/python/binary_search_tree/RBST.html
  - http://h0rnet.hatenablog.com/entry/2016/02/07/Randomized_binary_search_tree_2
  - https://sotanishy.github.io/cp-library-cpp/data-structure/bst/rbst.cpp
- 赤黒木 (red-black tree)
  - https://ja.wikipedia.org/wiki/%E8%B5%A4%E9%BB%92%E6%9C%A8
  - http://wwwa.pikara.ne.jp/okojisan/rb-tree/index.html
  - https://wiki.bit-hive.com/north/pg/%E8%B5%A4%E9%BB%92%E6%9C%A8
  - http://fujimura2.fiw-web.net/java/mutter/tree/red-black-tree.html
  - https://ei1333.github.io/luzhiled/snippets/structure/red-black-tree.html
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/BBST/Red-Black-Tree~~
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23RedBlackTree.cpp~~
  - http://omochan.hatenablog.com/entry/2017/09/12/231111
  - http://shifth.hatenablog.com/entry/2015/05/10/103528
  - https://codeforces.com/contest/785/submission/25528555
  - https://sotanishy.github.io/cp-library-cpp/data-structure/bst/red_black_tree.cpp
- treap
  - https://ja.wikipedia.org/wiki/Treap
  - https://xuzijian629.hatenablog.com/entry/2018/12/08/000452
  - ~~https://lumakernel.github.io/ecasdqina/data-structure/BBST/Treap~~
  - ~~http://www.prefield.com/algorithm/container/treap.html~~
  - https://tubo28.me/compprog/algorithm/treap/
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!Treap.cpp~~
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/TreapMap.hpp~~
  - https://github.com/primenumber/ProconLib/blob/master/Structure/Treap.cpp
  - https://codeforces.com/contest/785/submission/25530899
  - https://algoogle.hadrori.jp/algorithm/treap.html
  - https://tjkendev.github.io/procon-library/python/binary_search_tree/treap.html
  - https://sotanishy.github.io/cp-library-cpp/data-structure/bst/treap.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/bst/lazy_treap.cpp
  - implicit treap
    - https://en.wikipedia.org/wiki/Treap#Implicit_treap
    - https://xuzijian629.hatenablog.com/entry/2019/10/25/234938
    - https://competitive12.blogspot.com/2019/03/implicit-treap.html
    - https://mugen1337.github.io/procon/BinarySearchTree/ImplicitTreap.cpp
    - https://mugen1337.github.io/procon/BinarySearchTree/ImplicitTreapWithLazy.cpp
- AVL 木 (Adelson-Velskii and Landis' tree)
  - https://ja.wikipedia.org/wiki/AVL%E6%9C%A8
  - http://wwwa.pikara.ne.jp/okojisan/avl-tree/index.html
  - https://qiita.com/mikecat_mixc/items/e9f8248de2ae7f7a0a29
  - https://qiita.com/QCFium/items/3cf26a6dc2d49ef490d7
  - ~~http://www.prefield.com/algorithm/container/avl_tree.html~~
  - https://tubo28.me/compprog/algorithm/avl_tree/
  - https://codeforces.com/contest/785/submission/25572561
- スプレー木 (splay tree)
  - https://ja.wikipedia.org/wiki/%E3%82%B9%E3%83%97%E3%83%AC%E3%83%BC%E6%9C%A8
  - ~~http://www.prefield.com/algorithm/container/splay_tree.html~~
  - https://ngtkana.hatenablog.com/entry/2024/04/22/205043
  - https://gist.github.com/hotman78/264dc72248075fcc4b7f85f25ea0c27b
  - https://github.com/spaghetti-source/algorithm/blob/master/data_structure/splay_tree.cc
  - https://www.youtube.com/watch?v=M6LcINhgXeM
  - https://mugen1337.github.io/procon/BinarySearchTree/SplayTree.cpp
  - https://mugen1337.github.io/procon/BinarySearchTree/SplayTree_dev.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/bst/splay_tree.cpp
- 永続平衡二分探索木
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23PersistentBinarySearchTree.cpp~~
  - 永続赤黒木
    - http://blog.mitaki28.info/1447078746296/
    - https://algoogle.hadrori.jp/algorithm/prbtree.html


# 平面グラフ (plane graph)

## TODO
- https://ja.wikipedia.org/wiki/%E5%B9%B3%E9%9D%A2%E3%82%B0%E3%83%A9%E3%83%95
- https://xuzijian629.hatenablog.com/entry/2019/12/14/163726
- https://yukicoder.me/problems/no/1777


# 文字列の検索

## TODO
- https://www.slideshare.net/kazumamikami1/ss-16964389
- https://speakerdeck.com/shibh308/wen-zi-lie-suo-yin-towen-zi-lie-ya-suo
- shift-and アルゴリズム
  - https://ja.wikipedia.org/wiki/Bitap%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
  - ~~http://www.prefield.com/algorithm/string/shift_and.html~~
  - http://monyone.github.io/teihen_library/#ShiftAnd
- ボイヤー・ムーア文字列検索アルゴリズム (Boyer–Moore string search algorithm)
  - https://ja.wikipedia.org/wiki/%E3%83%9C%E3%82%A4%E3%83%A4%E3%83%BC-%E3%83%A0%E3%83%BC%E3%82%A2%E6%96%87%E5%AD%97%E5%88%97%E6%A4%9C%E7%B4%A2%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
  - https://noshi91.github.io/algorithm-encyclopedia/boyer-moore
  - https://algoful.com/Archive/Algorithm/BMSearch
  - https://g940425.hatenadiary.org/entry/20100522/1274520718
  - ~~http://www.prefield.com/algorithm/string/boyer_moore.html~~
  - https://github.com/spaghetti-source/algorithm/blob/master/string/boyer_moore.cc
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/%23BoyerMoore.cpp~~
- Baker–Bird Algorithm
  - ~~http://www.prefield.com/algorithm/string/baker_bird.html~~
- Karp–Miller–Rosenberg algorithm
  - ~~http://www.prefield.com/algorithm/string/karp_miller_rosenberg.html~~


# 約数関数 (divisor function)

$$
  \sigma_x(n) = \sum_{d \mid n} d^x
$$

## 参考文献
- https://ja.wikipedia.org/wiki/%E7%B4%84%E6%95%B0%E9%96%A2%E6%95%B0

## TODO
- https://github.com/spaghetti-source/algorithm/blob/master/number_theory/divisor_sigma.cc
