---
data:
  libraryCategories:
  - name: data_structure
    pages:
    - icon: ':heavy_check_mark:'
      path: data_structure/binary_trie.hpp
      title: binary trie
    - icon: ':heavy_check_mark:'
      path: data_structure/disjoint_sparse_table.hpp
      title: disjoint sparse table
    - icon: ':heavy_check_mark:'
      path: data_structure/lazy_segment_tree.hpp
      title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    - icon: ':heavy_check_mark:'
      path: data_structure/segment_tree.hpp
      title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    - icon: ':heavy_check_mark:'
      path: data_structure/set_managed_by_interval.hpp
      title: "std::set \u3092\u533A\u9593\u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
    - icon: ':heavy_check_mark:'
      path: data_structure/slope_trick.hpp
      title: slope trick
    - icon: ':heavy_check_mark:'
      path: data_structure/sparse_table.hpp
      title: sparse table
  - name: data_structure/fenwick_tree
    pages:
    - icon: ':heavy_check_mark:'
      path: data_structure/fenwick_tree/2d_fenwick_tree.hpp
      title: "2\u6B21\u5143 Fenwick tree"
    - icon: ':heavy_check_mark:'
      path: data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
      title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143\
        \ Fenwick tree"
    - icon: ':question:'
      path: data_structure/fenwick_tree/fenwick_tree.hpp
      title: Fenwick tree
    - icon: ':heavy_check_mark:'
      path: data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
      title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
  - name: data_structure/union-find
    pages:
    - icon: ':heavy_check_mark:'
      path: data_structure/union-find/partially_persistent_union-find.hpp
      title: "\u90E8\u5206\u6C38\u7D9A union-find"
    - icon: ':x:'
      path: data_structure/union-find/undoable_union-find.hpp
      title: "undo \u53EF\u80FD union-find"
    - icon: ':question:'
      path: data_structure/union-find/union-find.hpp
      title: union-find
    - icon: ':heavy_check_mark:'
      path: data_structure/union-find/weighted_union-find.hpp
      title: "\u91CD\u307F\u3064\u304D union-find"
  - name: dynamic_programming
    pages:
    - icon: ':x:'
      path: dynamic_programming/2d_cumulative_sum.hpp
      title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    - icon: ':x:'
      path: dynamic_programming/convert_online_dp_to_offline_dp.hpp
      title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\
        \u63DB"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/convex_hull_trick.hpp
      title: convex hull trick
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/knuth_yao_speedup.hpp
      title: Knuth-Yao speedup
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/largest_rectangle.hpp
      title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\u306E\u6700\u5927\u9577\u65B9\
        \u5F62 (largest rectangle in a histogram)"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/levenshtein_distance.hpp
      title: "\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2 (Levenshtein\
        \ distance) / \u7DE8\u96C6\u8DDD\u96E2 (edit distance)"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/li_chao_tree.hpp
      title: Li Chao tree
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/longest_common_subsequence.hpp
      title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (longest common subsequence)"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/longest_increasing_subsequence.hpp
      title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (longest increasing subsequence)"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/slide_min.hpp
      title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    - icon: ':heavy_check_mark:'
      path: dynamic_programming/subset_sum_problem.hpp
      title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
  - name: game
    pages:
    - icon: ':warning:'
      path: game/misere_nim.hpp
      title: "mis\xE8re Nim"
    - icon: ':heavy_check_mark:'
      path: game/nim.hpp
      title: "\u30CB\u30E0 (nim)"
  - name: geometry
    pages:
    - icon: ':heavy_check_mark:'
      path: geometry/argument_sort.hpp
      title: "\u504F\u89D2\u30BD\u30FC\u30C8"
    - icon: ':question:'
      path: geometry/geometry.hpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
    - icon: ':x:'
      path: geometry/smallest_enclosing_circle.hpp
      title: "\u6700\u5C0F\u5305\u542B\u5186 (smallest enclosing circle)"
  - name: graph
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/2-edge-connected_components_imos.hpp
      title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 \u3044\u3082\u3059\
        \u6CD5\u7248"
    - icon: ':x:'
      path: graph/2-edge-connected_components_lowlink.hpp
      title: "\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3 lowlink \u7248"
    - icon: ':x:'
      path: graph/biconnected_component.hpp
      title: "\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 (biconnected component)\
        \ \u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: graph/chromatic_number.hpp
      title: "\u5F69\u8272\u6570 (chromatic number)"
    - icon: ':x:'
      path: graph/connencted_component_of_complement_graph.hpp
      title: "\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: graph/detect_bridge.hpp
      title: "\u6A4B\u306E\u691C\u51FA"
    - icon: ':heavy_check_mark:'
      path: graph/detect_directed_cycle.hpp
      title: "\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\u30E9\u30D5\u7248"
    - icon: ':question:'
      path: graph/edge.hpp
      title: "\u8FBA"
    - icon: ':x:'
      path: graph/eulerian_trail_in_directed_graph.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\u30E9\u30D5\u7248"
    - icon: ':heavy_check_mark:'
      path: graph/eulerian_trail_in_undirected_graph.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\u30E9\u30D5\u7248"
    - icon: ':heavy_check_mark:'
      path: graph/girth_in_directed_graph.hpp
      title: "\u5185\u5468 \u6709\u5411\u30B0\u30E9\u30D5\u7248"
    - icon: ':heavy_check_mark:'
      path: graph/girth_in_undirected_graph.hpp
      title: "\u5185\u5468 \u7121\u5411\u30B0\u30E9\u30D5\u7248"
    - icon: ':x:'
      path: graph/is_bipartite.hpp
      title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: graph/kruskal.hpp
      title: "Kruskal \u6CD5"
    - icon: ':question:'
      path: graph/lowlink.hpp
      title: lowlink
    - icon: ':x:'
      path: graph/matrix_tree_theorem.hpp
      title: "\u884C\u5217\u6728\u5B9A\u7406"
    - icon: ':x:'
      path: graph/noshi_graph.hpp
      title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
    - icon: ':heavy_check_mark:'
      path: graph/prim.hpp
      title: "Prim \u6CD5"
    - icon: ':x:'
      path: graph/reachability_on_dag.hpp
      title: "\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\u306E\u5230\u9054\
        \u53EF\u80FD\u6027\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: graph/strongly_connected_components.hpp
      title: "\u5F37\u9023\u7D50\u6210\u5206 (strongly connected components) \u5206\
        \u89E3"
    - icon: ':x:'
      path: graph/topological_sort.hpp
      title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 (topological\
        \ sort)"
    - icon: ':heavy_check_mark:'
      path: graph/traveling_salesman_problem.hpp
      title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (traveling\
        \ salesman problem)"
    - icon: ':heavy_check_mark:'
      path: graph/unicyclic_graph.hpp
      title: unicyclic graph (1-tree)
  - name: graph/flow/matching
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/flow/matching/bipartite_matching.hpp
      title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
        \u30B0"
    - icon: ':heavy_check_mark:'
      path: graph/flow/matching/hopcroft-karp_algorithm.hpp
      title: Hopcroft-Karp algorithm
    - icon: ':heavy_check_mark:'
      path: graph/flow/matching/maximum_matching.hpp
      title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
        \u30B0"
    - icon: ':question:'
      path: graph/flow/matching/weighted_bipartite_matching.hpp
      title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
        \u30DE\u30C3\u30C1\u30F3\u30B0"
  - name: graph/flow/maximum_flow
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/flow/maximum_flow/dinic.hpp
      title: "Dinic \u6CD5"
    - icon: ':heavy_check_mark:'
      path: graph/flow/maximum_flow/ford-fulkerson.hpp
      title: "Ford-Fulkerson \u6CD5"
    - icon: ':heavy_check_mark:'
      path: graph/flow/maximum_flow/maximum_flow_with_minimum_flow_constraint.hpp
      title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
    - icon: ':heavy_check_mark:'
      path: graph/flow/maximum_flow/project_selection_problem.hpp
      title: project selection problem
  - name: graph/flow/minimum_cost_flow
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/flow/minimum_cost_flow/minimum_cost_b-flow.hpp
      title: "\u6700\u5C0F\u8CBB\u7528 $\\boldsymbol{b}$-\u30D5\u30ED\u30FC \u6700\
        \u77ED\u8DEF\u53CD\u5FA9\u6CD5\u7248"
    - icon: ':heavy_check_mark:'
      path: graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.hpp
      title: "\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\
        \u6D41"
    - icon: ':question:'
      path: graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
      title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\
        \u53CD\u5FA9\u6CD5\u7248"
  - name: graph/shortest_path
    pages:
    - icon: ':heavy_check_mark:'
      path: graph/shortest_path/bellman-ford.hpp
      title: "Bellman-Ford \u6CD5"
    - icon: ':question:'
      path: graph/shortest_path/dijkstra.hpp
      title: "Dijkstra \u6CD5"
    - icon: ':heavy_check_mark:'
      path: graph/shortest_path/warshall-floyd.hpp
      title: "Warshall-Floyd \u6CD5"
  - name: graph/tree
    pages:
    - icon: ':x:'
      path: graph/tree/centroid.hpp
      title: "\u91CD\u5FC3 (centroid)"
    - icon: ':heavy_check_mark:'
      path: graph/tree/centroid_decomposition.hpp
      title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
    - icon: ':heavy_check_mark:'
      path: graph/tree/double_sweep.hpp
      title: double sweep
    - icon: ':heavy_check_mark:'
      path: graph/tree/euler_tour.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
    - icon: ':heavy_check_mark:'
      path: graph/tree/heavy-light_decomposition.hpp
      title: "HL \u5206\u89E3 (heavy-light decomposition)"
    - icon: ':question:'
      path: graph/tree/lowest_common_ancestor_by_doubling.hpp
      title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\u30D6\u30EA\u30F3\u30B0\u7248"
    - icon: ':heavy_check_mark:'
      path: graph/tree/lowest_common_ancestor_by_euler_tour.hpp
      title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\
        \u30FC\u7248"
  - name: math
    pages:
    - icon: ':heavy_check_mark:'
      path: math/basis.hpp
      title: "\u57FA\u5E95 (basis)"
    - icon: ':question:'
      path: math/bigint.hpp
      title: "\u591A\u500D\u9577\u6574\u6570"
    - icon: ':warning:'
      path: math/carmichal_function.hpp
      title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570"
    - icon: ':warning:'
      path: math/carmichal_function_init.hpp
      title: "\u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: math/catalan_number.hpp
      title: "\u30AB\u30BF\u30E9\u30F3\u6570 (Catalan number)"
    - icon: ':heavy_check_mark:'
      path: math/chinese_remainder_theorem.hpp
      title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
    - icon: ':heavy_check_mark:'
      path: math/divisor.hpp
      title: "\u7D04\u6570\u5217\u6319"
    - icon: ':heavy_check_mark:'
      path: math/enumerate_k-th_power.hpp
      title: $i^k \bmod m \ (0 \leq i \leq n)$
    - icon: ':heavy_check_mark:'
      path: math/ext_gcd.hpp
      title: "\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5 (extended Euclidean algorithm)"
    - icon: ':heavy_check_mark:'
      path: math/floor_sum.hpp
      title: sum of floor of linear
    - icon: ':heavy_check_mark:'
      path: math/is_prime.hpp
      title: "\u7D20\u6570\u5224\u5B9A (primality test)"
    - icon: ':heavy_check_mark:'
      path: math/is_primitive_root.hpp
      title: "\u539F\u59CB\u6839\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: math/jacobi_symbol.hpp
      title: "\u30E4\u30B3\u30D3\u8A18\u53F7"
    - icon: ':heavy_check_mark:'
      path: math/kita_masa.hpp
      title: "\u304D\u305F\u307E\u3055\u6CD5"
    - icon: ':x:'
      path: math/lagrange_interpolation.hpp
      title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u7248"
    - icon: ':question:'
      path: math/lagrange_interpolation2.hpp
      title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\u4FA1\u72482"
    - icon: ':heavy_check_mark:'
      path: math/least_common_multiple.hpp
      title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
    - icon: ':heavy_check_mark:'
      path: math/mod_inv.hpp
      title: "\u9006\u5143 (inverse element)"
    - icon: ':heavy_check_mark:'
      path: math/mod_log.hpp
      title: "\u96E2\u6563\u5BFE\u6570\u554F\u984C (discrete logarithm problem)"
    - icon: ':heavy_check_mark:'
      path: math/mod_pow.hpp
      title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\
        \u6CD5, \u30D0\u30A4\u30CA\u30EA\u6CD5)"
    - icon: ':heavy_check_mark:'
      path: math/mod_sqrt.hpp
      title: "\u5E73\u65B9\u5270\u4F59"
    - icon: ':question:'
      path: math/modint.hpp
      title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
    - icon: ':heavy_check_mark:'
      path: math/montmort_number.hpp
      title: "\u30E2\u30F3\u30E2\u30FC\u30EB\u6570 (Montmort number)"
    - icon: ':heavy_check_mark:'
      path: math/osa_k.hpp
      title: "osa_k \u6CD5"
    - icon: ':x:'
      path: math/polynomial.hpp
      title: "\u591A\u9805\u5F0F (polynomial)"
    - icon: ':heavy_check_mark:'
      path: math/prime_factorization.hpp
      title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
    - icon: ':heavy_check_mark:'
      path: math/prime_sieve.hpp
      title: prime sieve
    - icon: ':heavy_check_mark:'
      path: math/quadratic_equation.hpp
      title: "\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F (quadratic equation)"
    - icon: ':heavy_check_mark:'
      path: math/rational.hpp
      title: "\u6709\u7406\u6570 (rational number)"
    - icon: ':warning:'
      path: math/segmented_sieve.hpp
      title: segmented sieve
    - icon: ':heavy_check_mark:'
      path: math/simultaneous_linear_congruence.hpp
      title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  - name: math/convolution
    pages:
    - icon: ':heavy_check_mark:'
      path: math/convolution/and_convolution.hpp
      title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
    - icon: ':question:'
      path: math/convolution/fast_fourier_transform.hpp
      title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
    - icon: ':heavy_check_mark:'
      path: math/convolution/fast_mobius_transform.hpp
      title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
    - icon: ':question:'
      path: math/convolution/fast_zeta_transform.hpp
      title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
    - icon: ':heavy_check_mark:'
      path: math/convolution/gcd_convolution.hpp
      title: "\u6DFB\u3048\u5B57 gcd \u3067\u306E\u7573\u307F\u8FBC\u307F"
    - icon: ':question:'
      path: math/convolution/mod_convolution.hpp
      title: "\u4EFB\u610F\u306E\u6CD5\u306E\u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
    - icon: ':question:'
      path: math/convolution/number_theoretic_transform.hpp
      title: "\u6570\u8AD6\u5909\u63DB"
    - icon: ':warning:'
      path: math/convolution/or_convolution.hpp
      title: "\u6DFB\u3048\u5B57 or \u3067\u306E\u7573\u307F\u8FBC\u307F"
    - icon: ':heavy_check_mark:'
      path: math/convolution/xor_convolution.hpp
      title: "\u6DFB\u3048\u5B57 xor \u3067\u306E\u7573\u307F\u8FBC\u307F"
  - name: math/euler_phi
    pages:
    - icon: ':heavy_check_mark:'
      path: math/euler_phi/euler_phi.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    - icon: ':heavy_check_mark:'
      path: math/euler_phi/euler_phi_init.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: math/euler_phi/euler_phi_init2.hpp
      title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
        2"
  - name: math/formal_power_series
    pages:
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/bernoulli_number.hpp
      title: "\u30D9\u30EB\u30CC\u30FC\u30A4\u6570 (Bernoulli number)"
    - icon: ':warning:'
      path: math/formal_power_series/eulerian_number.hpp
      title: Eulerian number
    - icon: ':warning:'
      path: math/formal_power_series/eulerian_number_by_fps.hpp
      title: "Eulerian number \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/faulhaber_by_fps.hpp
      title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\
        \u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/faulhaber_by_lagrange_interpolation.hpp
      title: "\u30D5\u30A1\u30A6\u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\
        \u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\u7248"
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/formal_power_series.hpp
      title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/multipoint_evaluation.hpp
      title: multipoint evaluation
    - icon: ':heavy_check_mark:'
      path: math/formal_power_series/polynomial_interpolation.hpp
      title: "\u591A\u9805\u5F0F\u88DC\u9593"
  - name: math/matrix/binary_matrix
    pages:
    - icon: ':heavy_check_mark:'
      path: math/matrix/binary_matrix/binary_matrix.hpp
      title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    - icon: ':heavy_check_mark:'
      path: math/matrix/binary_matrix/gauss_jordan.hpp
      title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
        \u6CD5 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    - icon: ':heavy_check_mark:'
      path: math/matrix/binary_matrix/inverse_matrix.hpp
      title: "\u9006\u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    - icon: ':heavy_check_mark:'
      path: math/matrix/binary_matrix/linear_equation.hpp
      title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\
        \u5217\u7248"
  - name: math/matrix
    pages:
    - icon: ':question:'
      path: math/matrix/determinant.hpp
      title: "\u884C\u5217\u5F0F (determinant)"
    - icon: ':heavy_check_mark:'
      path: math/matrix/gauss_jordan.hpp
      title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
        \u6CD5 (Gauss-Jordan elimination)"
    - icon: ':heavy_check_mark:'
      path: math/matrix/inverse_matrix.hpp
      title: "\u9006\u884C\u5217 (inverse matrix)"
    - icon: ':heavy_check_mark:'
      path: math/matrix/linear_equation.hpp
      title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
    - icon: ':question:'
      path: math/matrix/matrix.hpp
      title: "\u884C\u5217 (matrix)"
  - name: math/mobius_mu
    pages:
    - icon: ':heavy_check_mark:'
      path: math/mobius_mu/mobius_mu.hpp
      title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570"
    - icon: ':heavy_check_mark:'
      path: math/mobius_mu/mobius_mu_focusing_on_divisor.hpp
      title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: math/mobius_mu/mobius_mu_init.hpp
      title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: math/mobius_mu/mobius_mu_init2.hpp
      title: "\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u306E\u6570\u88682"
  - name: math/twelvefold_way/bell_number
    pages:
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/bell_number/bell_number.hpp
      title: "\u30D9\u30EB\u6570"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/bell_number/bell_number_init.hpp
      title: "\u30D9\u30EB\u6570\u306E\u6570\u8868"
    - icon: ':warning:'
      path: math/twelvefold_way/bell_number/bell_number_init_by_fps.hpp
      title: "\u30D9\u30EB\u6570\u306E\u6570\u8868 $n = k$ \u7248"
  - name: math/twelvefold_way
    pages:
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/large_nCk_init.hpp
      title: "\u4E8C\u9805\u4FC2\u6570\u306E\u6570\u8868 \u5DE8\u5927\u306A $n$ \u7248"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/lucas.hpp
      title: "Lucas \u306E\u5B9A\u7406 (Lucas's theorem)"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/partition_function.hpp
      title: "\u5206\u5272\u6570"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/partition_function_by_fps.hpp
      title: "\u5206\u5272\u6570 $n = m$ \u7248"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/pascal.hpp
      title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
  - name: math/twelvefold_way/stirling_number
    pages:
    - icon: ':warning:'
      path: math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init.hpp
      title: "\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_by_fps.hpp
      title: "\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
        \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.hpp
      title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
      title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
      title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
        \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  - name: misc
    pages:
    - icon: ':heavy_check_mark:'
      path: misc/2-sat.hpp
      title: 2-SAT
    - icon: ':heavy_check_mark:'
      path: misc/inversion_number.hpp
      title: "\u8EE2\u5012\u6570 (inversion number)"
    - icon: ':heavy_check_mark:'
      path: misc/mo.hpp
      title: Mo's algorithm
    - icon: ':heavy_check_mark:'
      path: misc/rotate.hpp
      title: "\u56DE\u8EE2 (rotation)"
    - icon: ':heavy_check_mark:'
      path: misc/sqrt_decomposition.hpp
      title: "\u5E73\u65B9\u5206\u5272 (sqrt decomposition)"
  - name: string
    pages:
    - icon: ':heavy_check_mark:'
      path: string/aho-corasick.hpp
      title: "\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\u6CD5 (Aho-Corasick\
        \ algorithm)"
    - icon: ':heavy_check_mark:'
      path: string/knuth-morris-pratt.hpp
      title: Knuth-Morris-Pratt algorithm
    - icon: ':heavy_check_mark:'
      path: string/longest_common_prefix.hpp
      title: longest common prefix
    - icon: ':heavy_check_mark:'
      path: string/manacher.hpp
      title: Manacher
    - icon: ':question:'
      path: string/morris-pratt.hpp
      title: Morris-Pratt algorithm
    - icon: ':warning:'
      path: string/replace.hpp
      title: "\u6587\u5B57\u5217\u306E\u7F6E\u63DB"
    - icon: ':heavy_check_mark:'
      path: string/rolling_hash.hpp
      title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5 (rolling hash)"
    - icon: ':heavy_check_mark:'
      path: string/run_length_encoding.hpp
      title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
    - icon: ':x:'
      path: string/split.hpp
      title: "\u6587\u5B57\u5217\u306E\u5206\u5272"
    - icon: ':x:'
      path: string/subsequence_dp.hpp
      title: "\u90E8\u5206\u5217 DP"
    - icon: ':heavy_check_mark:'
      path: string/suffix_array.hpp
      title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
    - icon: ':heavy_check_mark:'
      path: string/trie.hpp
      title: "\u30C8\u30E9\u30A4\u6728 (trie)"
    - icon: ':heavy_check_mark:'
      path: string/z_algorithm.hpp
      title: Z algorithm
  - name: util
    pages:
    - icon: ':warning:'
      path: util/template.hpp
      title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    - icon: ':warning:'
      path: util/timer.hpp
      title: "\u30BF\u30A4\u30DE\u30FC (timer)"
    - icon: ':question:'
      path: util/xorshift.hpp
      title: xorshift
  verificationCategories:
  - name: test/data_structure
    pages:
    - icon: ':heavy_check_mark:'
      path: test/data_structure/binary_trie.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/disjoint_sparse_table.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/disjoint sparse table"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/lazy_segment_tree.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
        \u30F3\u30C8\u6728"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_minimum_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
        \ (range minimum query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_minimum_query_and_range_add_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
        \u30F3\u30C8\u6728 (range minimum query and range add query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_minimum_query_and_range_update_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
        \u30F3\u30C8\u6728 (range minimum query and range update query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_sum_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
        \ (range sum query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_sum_query_and_range_add_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
        \u30F3\u30C8\u6728 (range sum query and range add query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/range_sum_query_and_range_update_query.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
        \u30F3\u30C8\u6728 (range sum query and range update query)"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/segment_tree.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/set_managed_by_interval.test.cpp
      title: "\u305D\u306E\u4ED6/std::set \u3092\u533A\u9593\u3067\u7BA1\u7406\u3059\
        \u308B\u3084\u3064"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/slope_trick.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/sparse_table.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
  - name: test/data_structure/fenwick_tree
    pages:
    - icon: ':heavy_check_mark:'
      path: test/data_structure/fenwick_tree/2d_bit_range_add.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\
        \u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick tree"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/fenwick_tree/bit_range_add.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\
        \u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/fenwick_tree/fenwick_tree.1.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (sum(left,\
        \ right))"
    - icon: ':x:'
      path: test/data_structure/fenwick_tree/fenwick_tree.2.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/Fenwick tree (lower_bound(val))"
  - name: test/data_structure/union-find
    pages:
    - icon: ':heavy_check_mark:'
      path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u90E8\u5206\u6C38\u7D9A union-find"
    - icon: ':x:'
      path: test/data_structure/union-find/undoable_union-find.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/undo \u53EF\u80FD union-find"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/union-find/union-find.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/union-find"
    - icon: ':heavy_check_mark:'
      path: test/data_structure/union-find/weighted_union-find.test.cpp
      title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u91CD\u307F\u3064\u304D union-find"
  - name: test/dynamic_programming
    pages:
    - icon: ':x:'
      path: test/dynamic_programming/2d_cumulative_sum.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u7D2F\u7A4D\u548C"
    - icon: ':x:'
      path: test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\
        \u30F3\u30E9\u30A4\u30F3\u5909\u63DB"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/convex_hull_trick.1.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (query(x))"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/convex_hull_trick.2.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotonically_increasing_query(x))"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/convex_hull_trick.3.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/convex full trick (monotonically_decreasing_query(x))"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/knuth_yao_speedup.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth-Yao speedup"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/largest_rectangle.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u4E2D\
        \u306E\u6700\u5927\u9577\u65B9\u5F62"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/levenshtein_distance.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\
        \u30A4\u30F3\u8DDD\u96E2"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/li_chao_tree.1.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024)"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/li_chao_tree.2.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/longest_common_subsequence.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5171\u901A\u90E8\u5206\u5217"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/longest_increasing_subsequence.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/slide_min.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
    - icon: ':heavy_check_mark:'
      path: test/dynamic_programming/subset_sum_problem.test.cpp
      title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
  - name: test/game
    pages:
    - icon: ':heavy_check_mark:'
      path: test/game/nim.test.cpp
      title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
  - name: test/geometry
    pages:
    - icon: ':heavy_check_mark:'
      path: test/geometry/argument_sort.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u504F\u89D2\u30BD\u30FC\u30C8"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.01.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (ccw(a,\
        \ b, c))"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.02.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u6700\
        \u8FD1\u70B9\u5BFE)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.03.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u5C04\
        \u5F71)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.04.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u93E1\
        \u6620)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.05.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u5E73\
        \u884C / \u5782\u76F4)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.06.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u7DDA\
        \u5206\u306E\u4EA4\u5DEE\u5224\u5B9A)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.07.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\
        \u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.08.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u7DDA\
        \u5206\u306E\u4EA4\u70B9)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.09.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u76F4\
        \u7DDA\u3068\u5186\u306E\u4EA4\u70B9)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.10.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\
        \u5206\u3068\u5186\u306E\u4EA4\u70B9)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.11.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\
        \u306E\u4EA4\u70B9)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.12.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u7DDA\
        \u5206\u306E\u8DDD\u96E2)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.13.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u63A5\
        \u70B9)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.14.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\
        \u306E\u5171\u901A\u63A5\u7DDA\u306E\u672C\u6570)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.15.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\
        \u306E\u5171\u901A\u63A5\u7DDA)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.16.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (2\u5186\
        \u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.17.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u591A\
        \u89D2\u5F62\u306E\u9762\u7A4D)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.18.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u591A\
        \u89D2\u5F62\u306E\u5185\u5916\u5224\u5B9A)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.19.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\
        \u6027\u5224\u5B9A)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.20.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\
        \u5305)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.21.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\
        \u591A\u89D2\u5F62\u306E\u5207\u65AD)"
    - icon: ':heavy_check_mark:'
      path: test/geometry/geometry.22.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u51F8\
        \u591A\u89D2\u5F62\u306E\u76F4\u5F84)"
    - icon: ':x:'
      path: test/geometry/smallest_enclosing_circle.test.cpp
      title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
  - name: test/graph
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/2-edge-connected_components_imos.test.cpp
      title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
        \ \u3044\u3082\u3059\u6CD5\u7248"
    - icon: ':x:'
      path: test/graph/2-edge-connected_components_lowlink.test.cpp
      title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\
        \ lowlink \u7248"
    - icon: ':x:'
      path: test/graph/biconnected_component.test.cpp
      title: "\u30B0\u30E9\u30D5/\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u5206\
        \u89E3"
    - icon: ':heavy_check_mark:'
      path: test/graph/chromatic_number.test.cpp
      title: "\u30B0\u30E9\u30D5/\u5F69\u8272\u6570"
    - icon: ':x:'
      path: test/graph/connencted_component_of_complement_graph.test.cpp
      title: "\u30B0\u30E9\u30D5/\u88DC\u30B0\u30E9\u30D5\u306E\u9023\u7D50\u6210\u5206\
        \u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: test/graph/detect_bridge.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6A4B\u306E\u691C\u51FA"
    - icon: ':heavy_check_mark:'
      path: test/graph/detect_directed_cycle.test.cpp
      title: "\u30B0\u30E9\u30D5/\u9589\u8DEF\u306E\u691C\u51FA \u6709\u5411\u30B0\
        \u30E9\u30D5\u7248"
    - icon: ':x:'
      path: test/graph/eulerian_trail_in_directed_graph.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u6709\u5411\u30B0\
        \u30E9\u30D5\u7248"
    - icon: ':heavy_check_mark:'
      path: test/graph/eulerian_trail_in_undirected_graph.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30AA\u30A4\u30E9\u30FC\u8DEF \u7121\u5411\u30B0\
        \u30E9\u30D5\u7248"
    - icon: ':heavy_check_mark:'
      path: test/graph/girth.test.cpp
      title: "\u30B0\u30E9\u30D5/\u5185\u5468"
    - icon: ':x:'
      path: test/graph/is_bipartite.test.cpp
      title: "\u30B0\u30E9\u30D5/\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: test/graph/kruskal.test.cpp
      title: "\u30B0\u30E9\u30D5/Kruskal \u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/graph/lowlink.1.test.cpp
      title: "\u30B0\u30E9\u30D5/lowlink (\u6A4B)"
    - icon: ':heavy_check_mark:'
      path: test/graph/lowlink.2.test.cpp
      title: "\u30B0\u30E9\u30D5/lowlink (\u95A2\u7BC0\u70B9)"
    - icon: ':x:'
      path: test/graph/matrix_tree_theorem.test.cpp
      title: "\u30B0\u30E9\u30D5/\u884C\u5217\u6728\u5B9A\u7406"
    - icon: ':x:'
      path: test/graph/noshi_graph.test.cpp
      title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
    - icon: ':heavy_check_mark:'
      path: test/graph/prim.test.cpp
      title: "\u30B0\u30E9\u30D5/Prim \u6CD5"
    - icon: ':x:'
      path: test/graph/reachability_on_dag.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6709\u5411\u975E\u5DE1\u56DE\u30B0\u30E9\u30D5\u4E0A\
        \u306E\u5230\u9054\u53EF\u80FD\u6027\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: test/graph/strongly_connected_components.test.cpp
      title: "\u30B0\u30E9\u30D5/\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    - icon: ':x:'
      path: test/graph/topological_sort.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
    - icon: ':heavy_check_mark:'
      path: test/graph/traveling_salesman_problem.test.cpp
      title: "\u30B0\u30E9\u30D5/\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\
        \u984C"
    - icon: ':heavy_check_mark:'
      path: test/graph/unicyclic_graph.test.cpp
      title: "\u30B0\u30E9\u30D5/unicyclic graph"
  - name: test/graph/flow/matching
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/matching/bipartite_matching.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0\
        /\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/matching/hopcroft-karp_algorithm.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0\
        /Hopcroft-Karp algorithm"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/matching/maximum_matching.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0\
        /\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
    - icon: ':x:'
      path: test/graph/flow/matching/weighted_bipartite_matching.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u30DE\u30C3\u30C1\u30F3\u30B0\
        /\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\u30DE\
        \u30C3\u30C1\u30F3\u30B0"
  - name: test/graph/flow/maximum_flow
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/maximum_flow/ford-fulkerson.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/Ford-Fulkerson\
        \ \u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/maximum_flow/minimum_flow_constraint.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/\u6700\u5C0F\
        \u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5927\u6D41"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/maximum_flow/project_selection_problem.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5927\u6D41/project selection\
        \ problem"
  - name: test/graph/flow/minimum_cost_flow
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/minimum_cost_flow/minimum_cost_flow_with_minimum_flow_constraint.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41\
        /\u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u6700\u5C0F\u8CBB\u7528\u6D41"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.1.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41\
        /\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
        \u5FA9\u6CD5\u7248 (solve(s, t, flow))"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.2.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41\
        /\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
        \u5FA9\u6CD5\u7248 (solve(s, t))"
    - icon: ':heavy_check_mark:'
      path: test/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.3.test.cpp
      title: "\u30B0\u30E9\u30D5/\u30D5\u30ED\u30FC/\u6700\u5C0F\u8CBB\u7528\u6D41\
        /\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC \u6700\u77ED\u8DEF\u53CD\
        \u5FA9\u6CD5\u7248 (minimum_cost_maximum_flow(s, t, flow))"
  - name: test/graph/shortest_path
    pages:
    - icon: ':heavy_check_mark:'
      path: test/graph/shortest_path/bellman-ford.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Bellman-Ford \u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/graph/shortest_path/dijkstra.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Dijkstra \u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/graph/shortest_path/warshall-floyd.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6700\u77ED\u8DEF\u554F\u984C/Warshall-Floyd \u6CD5"
  - name: test/graph/tree
    pages:
    - icon: ':x:'
      path: test/graph/tree/centroid.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/centroid_decomposition.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/double_sweep.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/double sweep"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/heavy-light_decomposition.1.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/heavy-light_decomposition.2.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/HL \u5206\u89E3 (\u6700\u5C0F\u5171\u901A\u7956\
        \u5148)"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/lowest_common_ancestor_by_doubling.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30C0\
        \u30D6\u30EA\u30F3\u30B0\u7248"
    - icon: ':heavy_check_mark:'
      path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
      title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\
        \u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  - name: test/math
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/basis.test.cpp
      title: "\u6570\u5B66/\u57FA\u5E95"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.01.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.02.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u52A0\u7B97)"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.03.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6E1B\u7B97)"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.04.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u4E57\u7B97)"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.05.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u9664\u7B97)"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.06.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5270\u4F59\u6F14\u7B97\
        )"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.07.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u5927\u5C0F\u6BD4\u8F03\
        )"
    - icon: ':x:'
      path: test/math/bigint.08.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u51AA\u6F14\u7B97)"
    - icon: ':heavy_check_mark:'
      path: test/math/bigint.09.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u548C)"
    - icon: ':x:'
      path: test/math/bigint.10.test.cpp
      title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)"
    - icon: ':heavy_check_mark:'
      path: test/math/catalan_number.test.cpp
      title: "\u6570\u5B66/\u30AB\u30BF\u30E9\u30F3\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/chinese_remainder_theorem.test.cpp
      title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
    - icon: ':heavy_check_mark:'
      path: test/math/divisor.test.cpp
      title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    - icon: ':heavy_check_mark:'
      path: test/math/enumerate_k-th_power.test.cpp
      title: "\u6570\u5B66/$i^k \\bmod m \\ (0 \\leq i \\leq n)$"
    - icon: ':heavy_check_mark:'
      path: test/math/ext_gcd.test.cpp
      title: "\u6570\u5B66/\u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/math/fast_divisor.test.cpp
      title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    - icon: ':heavy_check_mark:'
      path: test/math/floor_sum.test.cpp
      title: "\u6570\u5B66/sum of floor of linear"
    - icon: ':heavy_check_mark:'
      path: test/math/is_prime.test.cpp
      title: "\u6570\u5B66/\u7D20\u6570\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: test/math/is_primitive_root.test.cpp
      title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
    - icon: ':heavy_check_mark:'
      path: test/math/jacobi_symbol.test.cpp
      title: "\u6570\u5B66/\u30E4\u30B3\u30D3\u8A18\u53F7"
    - icon: ':heavy_check_mark:'
      path: test/math/kita_masa.test.cpp
      title: "\u6570\u5B66/\u304D\u305F\u307E\u3055\u6CD5"
    - icon: ':x:'
      path: test/math/lagrange_interpolation.test.cpp
      title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\
        \u4FA1\u7248"
    - icon: ':x:'
      path: test/math/lagrange_interpolation2.test.cpp
      title: "\u6570\u5B66/\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 \u8A55\
        \u4FA1\u72482"
    - icon: ':heavy_check_mark:'
      path: test/math/least_common_multiple.test.cpp
      title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/mod_log.test.cpp
      title: "\u6570\u5B66/\u96E2\u6563\u5BFE\u6570\u554F\u984C"
    - icon: ':heavy_check_mark:'
      path: test/math/mod_pow.test.cpp
      title: "\u6570\u5B66/\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/math/mod_sqrt.test.cpp
      title: "\u6570\u5B66/\u5E73\u65B9\u5270\u4F59"
    - icon: ':heavy_check_mark:'
      path: test/math/montmort_number.test.cpp
      title: "\u6570\u5B66/\u30E2\u30F3\u30E2\u30FC\u30EB\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/osa_k.test.cpp
      title: "\u6570\u5B66/osa_k \u6CD5"
    - icon: ':x:'
      path: test/math/polynomial.test.cpp
      title: "\u6570\u5B66/\u591A\u9805\u5F0F"
    - icon: ':heavy_check_mark:'
      path: test/math/prime_factorization.test.cpp
      title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
    - icon: ':heavy_check_mark:'
      path: test/math/prime_sieve.test.cpp
      title: "\u6570\u5B66/prime sieve"
    - icon: ':heavy_check_mark:'
      path: test/math/quadratic_equation.test.cpp
      title: "\u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F"
    - icon: ':heavy_check_mark:'
      path: test/math/rational.test.cpp
      title: "\u6570\u5B66/\u6709\u7406\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/simultaneous_linear_congruence.test.cpp
      title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
  - name: test/math/convolution
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/convolution/and_convolution.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 and \u3067\u306E\
        \u7573\u307F\u8FBC\u307F"
    - icon: ':x:'
      path: test/math/convolution/fast_fourier_transform.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\u30EA\
        \u30A8\u5909\u63DB"
    - icon: ':heavy_check_mark:'
      path: test/math/convolution/fast_mobius_transform.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\
        \u30B9\u5909\u63DB"
    - icon: ':x:'
      path: test/math/convolution/fast_zeta_transform.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\
        \u5909\u63DB"
    - icon: ':heavy_check_mark:'
      path: test/math/convolution/gcd_convolution.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 gcd \u3067\u306E\
        \u7573\u307F\u8FBC\u307F"
    - icon: ':x:'
      path: test/math/convolution/mod_convolution.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u4EFB\u610F\u306E\u6CD5\u306E\
        \u4E0B\u3067\u306E\u7573\u307F\u8FBC\u307F"
    - icon: ':heavy_check_mark:'
      path: test/math/convolution/number_theoretic_transform.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB"
    - icon: ':heavy_check_mark:'
      path: test/math/convolution/xor_convolution.test.cpp
      title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 xor \u3067\u306E\
        \u7573\u307F\u8FBC\u307F"
  - name: test/math/euler_phi
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/euler_phi/euler_phi.test.cpp
      title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\
        /\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/euler_phi/euler_phi_init.test.cpp
      title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\
        /\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: test/math/euler_phi/euler_phi_init2.test.cpp
      title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\
        /\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
  - name: test/math/formal_power_series
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/bernoulli_number.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D9\u30EB\u30CC\
        \u30FC\u30A4\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/faulhaber_by_fps.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\
        \u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u5F62\u5F0F\u7684\u51AA\u7D1A\
        \u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/faulhaber_by_lagrange_interpolation.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u30D5\u30A1\u30A6\
        \u30EB\u30CF\u30FC\u30D0\u30FC\u306E\u516C\u5F0F \u30E9\u30B0\u30E9\u30F3\u30B8\
        \u30E5\u88DC\u9593\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.1.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (\u6307\u6570)"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.2.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (\u9006\u5143)"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.3.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (\u5BFE\u6570)"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.4.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (\u51AA\u4E57)"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.5.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (mod_pow(exponend, md))"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.6.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (\u5E73\u65B9\u6839)"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/formal_power_series.7.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u5F62\u5F0F\u7684\
        \u51AA\u7D1A\u6570 (translate(c))"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/multipoint_evaluation.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint evaluation"
    - icon: ':heavy_check_mark:'
      path: test/math/formal_power_series/polynomial_interpolation.test.cpp
      title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\
        \u88DC\u9593"
  - name: test/math/matrix/binary_matrix
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/binary_matrix/gauss_jordan.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30AC\
        \u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\u6CD5 \u30D0\
        \u30A4\u30CA\u30EA\u884C\u5217\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/binary_matrix/inverse_matrix.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9006\
        \u884C\u5217 \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/binary_matrix/linear_equation.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u9023\
        \u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F \u30D0\u30A4\u30CA\u30EA\u884C\u5217\u7248"
  - name: test/math/matrix
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/determinant.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217\u5F0F"
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/inverse_matrix.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u9006\u884C\u5217"
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/linear_equation.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
    - icon: ':heavy_check_mark:'
      path: test/math/matrix/matrix.test.cpp
      title: "\u6570\u5B66/\u884C\u5217/\u884C\u5217"
  - name: test/math/mobius_mu
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/mobius_mu/mobius_mu.test.cpp
      title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\
        \u30B9\u95A2\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/mobius_mu/mobius_mu_focusing_on_divisor.test.cpp
      title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\
        \u30B9\u95A2\u6570 \u7D04\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/mobius_mu/mobius_mu_init.test.cpp
      title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\
        \u30B9\u95A2\u6570\u306E\u6570\u8868"
    - icon: ':heavy_check_mark:'
      path: test/math/mobius_mu/mobius_mu_init2.test.cpp
      title: "\u6570\u5B66/\u30E1\u30D3\u30A6\u30B9\u95A2\u6570/\u30E1\u30D3\u30A6\
        \u30B9\u95A2\u6570\u306E\u6570\u88682"
  - name: test/math/twelvefold_way/bell_number
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/bell_number/bell_number.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570\
        \u306E\u6570\u8868"
  - name: test/math/twelvefold_way
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/binomial_coefficients.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/large_nCk.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570 \u5DE8\u5927\
        \u306A $n$ \u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/large_nCk_init.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\u306E\u6570\
        \u8868 \u5DE8\u5927\u306A $n$ \u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/lucas.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/partition_function_by_fps.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570 $n = m$ \u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/partition_function_init.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/pascal.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\
        \u89D2\u5F62"
  - name: test/math/twelvefold_way/stirling_number
    pages:
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_first_kind_init_with_fps.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
        \u6570/\u7B2C1\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
        \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
        \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
        \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
        \u8868"
    - icon: ':heavy_check_mark:'
      path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
      title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
        \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\
        \u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  - name: test/misc
    pages:
    - icon: ':heavy_check_mark:'
      path: test/misc/2-sat.test.cpp
      title: "\u305D\u306E\u4ED6/2-SAT"
    - icon: ':heavy_check_mark:'
      path: test/misc/inversion_number.test.cpp
      title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
    - icon: ':heavy_check_mark:'
      path: test/misc/mo.test.cpp
      title: "\u305D\u306E\u4ED6/Mo's algorithm"
    - icon: ':heavy_check_mark:'
      path: test/misc/rotate.test.cpp
      title: "\u305D\u306E\u4ED6/\u56DE\u8EE2"
    - icon: ':heavy_check_mark:'
      path: test/misc/sqrt_decomposition.test.cpp
      title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
  - name: test/string
    pages:
    - icon: ':heavy_check_mark:'
      path: test/string/aho-corasick.test.cpp
      title: "\u6587\u5B57\u5217/\u30A8\u30A4\u30DB-\u30B3\u30E9\u30B7\u30C3\u30AF\
        \u6CD5"
    - icon: ':heavy_check_mark:'
      path: test/string/knuth-morris-pratt.test.cpp
      title: "\u6587\u5B57\u5217/Knuth-Morris-Pratt algorithm"
    - icon: ':heavy_check_mark:'
      path: test/string/longest_common_prefix.test.cpp
      title: "\u6587\u5B57\u5217/longest common prefix"
    - icon: ':heavy_check_mark:'
      path: test/string/manacher.test.cpp
      title: "\u6587\u5B57\u5217/Manacher"
    - icon: ':heavy_check_mark:'
      path: test/string/morris-pratt.1.test.cpp
      title: "\u6587\u5B57\u5217/Morris-Pratt algorithm (match(t))"
    - icon: ':x:'
      path: test/string/morris-pratt.2.test.cpp
      title: "\u6587\u5B57\u5217/Morris-Pratt algorithm (period(idx))"
    - icon: ':heavy_check_mark:'
      path: test/string/rolling_hash.test.cpp
      title: "\u6587\u5B57\u5217/\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
    - icon: ':heavy_check_mark:'
      path: test/string/run_length_encoding.test.cpp
      title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
    - icon: ':x:'
      path: test/string/split.test.cpp
      title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
    - icon: ':x:'
      path: test/string/subsequence_dp.test.cpp
      title: "\u6587\u5B57\u5217/\u90E8\u5206\u5217 DP"
    - icon: ':heavy_check_mark:'
      path: test/string/suffix_array.test.cpp
      title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
    - icon: ':heavy_check_mark:'
      path: test/string/z_algorithm.test.cpp
      title: "\u6587\u5B57\u5217/Z algorithm"
layout: toppage
---
## Documents

### math

- [代数的構造](https://emthrm.github.io/library/algebraic_structure.html)
- [双対問題](https://emthrm.github.io/library/dual_problem.html)

### misc

- [メモ](https://emthrm.github.io/library/notes.html)
- [ToDo](https://emthrm.github.io/library/todo.html)
