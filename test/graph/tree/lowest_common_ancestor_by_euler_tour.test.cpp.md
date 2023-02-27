---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/lazy_segment_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/euler_tour.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC (Euler tour)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
    title: "\u6700\u5C0F\u5171\u901A\u7956\u5148 (lowest common ancestor) \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
      \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667
  bundledCode: "#line 1 \"test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp\"\
    \n/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/lazy_segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n// #include <cassert>\n#include\
    \ <limits>\n#line 9 \"include/emthrm/data_structure/lazy_segment_tree.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <typename T>\nstruct LazySegmentTree {\n  using\
    \ Monoid = typename T::Monoid;\n  using OperatorMonoid = typename T::OperatorMonoid;\n\
    \n  explicit LazySegmentTree(const int n)\n      : LazySegmentTree(std::vector<Monoid>(n,\
    \ T::m_id())) {}\n\n  explicit LazySegmentTree(const std::vector<Monoid>& a)\n\
    \      : n(a.size()), height(std::countr_zero(std::bit_ceil(a.size()))),\n   \
    \     p2(1 << height) {\n    lazy.assign(p2, T::o_id());\n    data.assign(p2 <<\
    \ 1, T::m_id());\n    std::copy(a.begin(), a.end(), data.begin() + p2);\n    for\
    \ (int i = p2 - 1; i > 0; --i) {\n      data[i] = T::m_merge(data[i << 1], data[(i\
    \ << 1) + 1]);\n    }\n  }\n\n  void set(int idx, const Monoid val) {\n    idx\
    \ += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(idx >> i);\n\
    \    }\n    data[idx] = val;\n    for (int i = 1; i <= height; ++i) {\n      const\
    \ int current_idx = idx >> i;\n      data[current_idx] =\n          T::m_merge(data[current_idx\
    \ << 1], data[(current_idx << 1) + 1]);\n    }\n  }\n\n  void apply(int idx, const\
    \ OperatorMonoid val) {\n    idx += p2;\n    for (int i = height; i > 0; --i)\
    \ {\n      propagate(idx >> i);\n    }\n    data[idx] = T::apply(data[idx], val);\n\
    \    for (int i = 1; i <= height; ++i) {\n      const int current_idx = idx >>\
    \ i;\n      data[current_idx] =\n          T::m_merge(data[current_idx << 1],\
    \ data[(current_idx << 1) + 1]);\n    }\n  }\n\n  void apply(int left, int right,\
    \ const OperatorMonoid val) {\n    if (right <= left) [[unlikely]] return;\n \
    \   left += p2;\n    right += p2;\n    const int ctz_left = std::countr_zero(static_cast<unsigned\
    \ int>(left));\n    for (int i = height; i > ctz_left; --i) {\n      propagate(left\
    \ >> i);\n    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned\
    \ int>(right));\n    for (int i = height; i > ctz_right; --i) {\n      propagate(right\
    \ >> i);\n    }\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\n\
    \      if (l & 1) apply_sub(l++, val);\n      if (r & 1) apply_sub(--r, val);\n\
    \    }\n    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {\n      data[i]\
    \ = T::m_merge(data[i << 1], data[(i << 1) + 1]);\n    }\n    for (int i = right\
    \ >> (ctz_right + 1); i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i <<\
    \ 1], data[(i << 1) + 1]);\n    }\n  }\n\n  Monoid get(int left, int right) {\n\
    \    if (right <= left) [[unlikely]] return T::m_id();\n    left += p2;\n    right\
    \ += p2;\n    const int ctz_left = std::countr_zero(static_cast<unsigned int>(left));\n\
    \    for (int i = height; i > ctz_left; --i) {\n      propagate(left >> i);\n\
    \    }\n    const int ctz_right = std::countr_zero(static_cast<unsigned int>(right));\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    Monoid res_l = T::m_id(), res_r = T::m_id();\n    for (; left < right;\
    \ left >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::m_merge(res_l, data[left++]);\n\
    \      if (right & 1) res_r = T::m_merge(data[--right], res_r);\n    }\n    return\
    \ T::m_merge(res_l, res_r);\n  }\n\n  Monoid operator[](const int idx) {\n   \
    \ const int node = idx + p2;\n    for (int i = height; i > 0; --i) {\n      propagate(node\
    \ >> i);\n    }\n    return data[node];\n  }\n\n  template <typename G>\n  int\
    \ find_right(int left, const G g) {\n    if (left >= n) [[unlikely]] return n;\n\
    \    left += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(left\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      while (!(left &\
    \ 1)) left >>= 1;\n      Monoid nxt = T::m_merge(val, data[left]);\n      if (!g(nxt))\
    \ {\n        while (left < p2) {\n          propagate(left);\n          left <<=\
    \ 1;\n          nxt = T::m_merge(val, data[left]);\n          if (g(nxt)) {\n\
    \            val = nxt;\n            ++left;\n          }\n        }\n       \
    \ return left - p2;\n      }\n      val = nxt;\n      ++left;\n    } while (!std::has_single_bit(static_cast<unsigned\
    \ int>(left)));\n    return n;\n  }\n\n  template <typename G>\n  int find_left(int\
    \ right, const G g) {\n    if (right <= 0) [[unlikely]] return -1;\n    right\
    \ += p2;\n    for (int i = height; i > 0; --i) {\n      propagate((right - 1)\
    \ >> i);\n    }\n    Monoid val = T::m_id();\n    do {\n      --right;\n     \
    \ while (right > 1 && (right & 1)) right >>= 1;\n      Monoid nxt = T::m_merge(data[right],\
    \ val);\n      if (!g(nxt)) {\n        while (right < p2) {\n          propagate(right);\n\
    \          right = (right << 1) + 1;\n          nxt = T::m_merge(data[right],\
    \ val);\n          if (g(nxt)) {\n            val = nxt;\n            --right;\n\
    \          }\n        }\n        return right - p2;\n      }\n      val = nxt;\n\
    \    } while (!std::has_single_bit(static_cast<unsigned int>(right)));\n    return\
    \ -1;\n  }\n\n private:\n  const int n, height, p2;\n  std::vector<Monoid> data;\n\
    \  std::vector<OperatorMonoid> lazy;\n\n  void apply_sub(const int idx, const\
    \ OperatorMonoid& val) {\n    data[idx] = T::apply(data[idx], val);\n    if (idx\
    \ < p2) lazy[idx] = T::o_merge(lazy[idx], val);\n  }\n\n  void propagate(const\
    \ int idx) {\n    // assert(1 <= idx && idx < p2);\n    apply_sub(idx << 1, lazy[idx]);\n\
    \    apply_sub((idx << 1) + 1, lazy[idx]);\n    lazy[idx] = T::o_id();\n  }\n\
    };\n\nnamespace monoid {\n\ntemplate <typename T>\nstruct RangeMinimumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return std::numeric_limits<Monoid>::max(); }\n  static constexpr OperatorMonoid\
    \ o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n  }\n  static\
    \ Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::min(a, b);\n\
    \  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n             \
    \                   const OperatorMonoid& b) {\n    return b == o_id() ? a : b;\n\
    \  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ b == o_id() ? a : b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeMaximumAndUpdateQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() {\n    return std::numeric_limits<Monoid>::lowest();\n  }\n  static constexpr\
    \ OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::lowest();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ std::max(a, b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                const OperatorMonoid& b) {\n    return b\
    \ == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return b == o_id()? a : b;\n  }\n};\n\ntemplate <typename T, T Inf>\n\
    struct RangeMinimumAndAddQuery {\n  using Monoid = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr Monoid m_id() { return Inf; }\n  static constexpr OperatorMonoid\
    \ o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a, const Monoid&\
    \ b) {\n    return std::min(a, b);\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return a + b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return a + b;\n  }\n};\n\ntemplate <typename T, T Inf>\nstruct RangeMaximumAndAddQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return -Inf; }\n  static constexpr OperatorMonoid o_id() { return 0;\
    \ }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::max(a,\
    \ b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n       \
    \                         const OperatorMonoid& b) {\n    return a + b;\n  }\n\
    \  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ a + b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndUpdateQuery {\n\
    \  using Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n \
    \ static std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n,\
    \ Monoid{0, 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n \
    \ static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ Monoid{a.sum + b.sum, a.len + b.len};\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return b == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid&\
    \ a, const OperatorMonoid& b) {\n    return Monoid{b == o_id() ? a.sum : b * a.len,\
    \ a.len};\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndAddQuery {\n  using\
    \ Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n  static\
    \ std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n, Monoid{0,\
    \ 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n  static constexpr\
    \ OperatorMonoid o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a,\
    \ const Monoid& b) {\n    return Monoid{a.sum + b.sum, a.len + b.len};\n  }\n\
    \  static OperatorMonoid o_merge(const OperatorMonoid& a,\n                  \
    \              const OperatorMonoid& b) {\n    return a + b;\n  }\n  static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n    return Monoid{a.sum +\
    \ b * a.len, a.len};\n  }\n};\n\n}  // namespace monoid\n\n}  // namespace emthrm\n\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n#include <utility>\n#line 7 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n\n#line 1 \"include/emthrm/data_structure/sparse_table.hpp\"\n\n\n\n#line 6\
    \ \"include/emthrm/data_structure/sparse_table.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#line 9 \"include/emthrm/data_structure/sparse_table.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <typename Band>\nstruct SparseTable {\n  using\
    \ BinOp = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\n \
    \ explicit SparseTable(const std::vector<Band>& a, const BinOp bin_op) {\n   \
    \ init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>& a, const BinOp\
    \ bin_op_) {\n    bin_op = bin_op_;\n    const int n = a.size();\n    assert(n\
    \ > 0);\n    lg.assign(n + 1, 0);\n    for (int i = 2; i <= n; ++i) {\n      lg[i]\
    \ = lg[i >> 1] + 1;\n    }\n    const int table_h = std::countr_zero(std::bit_floor(a.size()))\
    \ + 1;\n    data.assign(table_h, std::vector<Band>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     for (int j = 0; j + (1 << i) <= n; ++j) {\n        data[i][j] = bin_op(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  Band query(const\
    \ int left, const int right) const {\n    assert(left < right);\n    const int\
    \ h = lg[right - left];\n    return bin_op(data[h][left], data[h][right - (1 <<\
    \ h)]);\n  }\n\n private:\n  BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Band>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/tree/euler_tour.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/graph/tree/euler_tour.hpp\"\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\
    \n/**\n * @title \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 7 \"include/emthrm/graph/tree/euler_tour.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct EulerTour {\n \
    \ std::vector<int> tour, depth, left, right, down, up;\n  std::vector<CostType>\
    \ cost;\n\n  explicit EulerTour(const std::vector<std::vector<Edge<CostType>>>\
    \ &graph,\n                     const int root = 0)\n      : graph(graph) {\n\
    \    const int n = graph.size();\n    left.resize(n);\n    right.resize(n);\n\
    \    down.assign(n, -1);\n    up.assign(n, (n - 1) << 1);\n    dfs(-1, root, 0);\n\
    \  }\n\n  template <typename Fn>\n  void update_v(const int ver, const Fn f) const\
    \ {\n    f(left[ver], right[ver] + 1);\n  }\n\n  template <typename T, typename\
    \ Fn>\n  T query_v(const int ver, const Fn f) const {\n    return f(left[ver],\
    \ right[ver] + 1);\n  }\n\n  template <typename T, typename Fn>\n  T query_e(const\
    \ int u, const int v, const Fn f) const {\n    return f(down[u] + 1, down[v] +\
    \ 1);\n  }\n\n  template <typename Fn>\n  void update_subtree_e(const int ver,\
    \ const Fn f) const {\n    f(down[ver] + 1, up[ver]);\n  }\n\n  template <typename\
    \ T, typename Fn>\n  T query_subtree_e(const int ver, const Fn f) const {\n  \
    \  return f(down[ver] + 1, up[ver]);\n  }\n\n private:\n  const std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n\n  void dfs(const int par, const int ver, const int cur_depth) {\n\
    \    left[ver] = tour.size();\n    tour.emplace_back(ver);\n    depth.emplace_back(cur_depth);\n\
    \    for (const Edge<CostType>& e : graph[ver]) {\n      if (e.dst != par) [[likely]]\
    \ {\n        down[e.dst] = cost.size();\n        cost.emplace_back(e.cost);\n\
    \        dfs(ver, e.dst, cur_depth + 1);\n        tour.emplace_back(ver);\n  \
    \      depth.emplace_back(cur_depth);\n        up[e.dst] = cost.size();\n    \
    \    cost.emplace_back(-e.cost);\n      }\n    }\n    right[ver] = tour.size()\
    \ - 1;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct LowestCommonAncestor\
    \ : EulerTour<CostType> {\n  explicit LowestCommonAncestor(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph,\n      const int root = 0)\n      : EulerTour<CostType>(graph, root)\
    \ {\n    const int n = this->tour.size();\n    std::vector<std::pair<int, int>>\
    \ nodes(n);\n    for (int i = 0; i < n; ++i) {\n      nodes[i] = {this->depth[i],\
    \ this->tour[i]};\n    }\n    sparse_table.init(\n        nodes,\n        [](const\
    \ std::pair<int, int>& a, const std::pair<int, int>& b)\n            -> std::pair<int,\
    \ int> {\n          return std::min(a, b);\n        });\n  }\n\n  int query(int\
    \ u, int v) const {\n    u = this->left[u];\n    v = this->left[v];\n    if (u\
    \ > v) std::swap(u, v);\n    return sparse_table.query(u, v + 1).second;\n  }\n\
    \n private:\n  SparseTable<std::pair<int, int>> sparse_table;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 13 \"test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::LowestCommonAncestor<long long> lowest_common_ancestor(graph,\
    \ 0);\n  struct M {\n    using Monoid = struct { int num; long long sum; };\n\
    \    using OperatorMonoid = int;\n    static constexpr Monoid m_id() { return\
    \ Monoid{0, 0}; }\n    static constexpr OperatorMonoid o_id() { return 0; }\n\
    \    static Monoid m_merge(const Monoid& a, const Monoid& b) {\n      return Monoid{a.num\
    \ + b.num, a.sum + b.sum};\n    }\n    static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                  const OperatorMonoid& b) {\n      return\
    \ a + b;\n    }\n    static Monoid apply(Monoid a, const OperatorMonoid& b) {\n\
    \      a.sum += b * a.num;\n      return a;\n    }\n  };\n  std::vector<M::Monoid>\
    \ init((n - 1) * 2, M::Monoid{0, 0});\n  for (int i = 1; i < n; ++i) {\n    init[lowest_common_ancestor.down[i]].num\
    \ = 1;\n    init[lowest_common_ancestor.up[i]].num = -1;\n  }\n  emthrm::LazySegmentTree<M>\
    \ seg(init);\n  const auto fn = [&seg](const int a, const int b) -> long long\
    \ {\n    return seg.get(a, b).sum;\n  };\n  while (q--) {\n    int type;\n   \
    \ std::cin >> type;\n    if (type == 0) {\n      int u, v;\n      std::cin >>\
    \ u >> v;\n      const int lca = lowest_common_ancestor.query(u, v);\n      std::cout\
    \ << lowest_common_ancestor.query_e<long long>(lca, u, fn)\n                 \
    \  + lowest_common_ancestor.query_e<long long>(lca, v, fn)\n                <<\
    \ '\\n';\n    } else if (type == 1) {\n      int v, x;\n      std::cin >> v >>\
    \ x;\n      lowest_common_ancestor.update_subtree_e(\n          v, [&seg, x](const\
    \ int a, const int b) { seg.apply(a, b, x); });\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148\
    \ \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u7248\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/lazy_segment_tree.hpp\"\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<std::vector<emthrm::Edge<long\
    \ long>>> graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b, 0);\n    graph[b].emplace_back(b,\
    \ a, 0);\n  }\n  emthrm::LowestCommonAncestor<long long> lowest_common_ancestor(graph,\
    \ 0);\n  struct M {\n    using Monoid = struct { int num; long long sum; };\n\
    \    using OperatorMonoid = int;\n    static constexpr Monoid m_id() { return\
    \ Monoid{0, 0}; }\n    static constexpr OperatorMonoid o_id() { return 0; }\n\
    \    static Monoid m_merge(const Monoid& a, const Monoid& b) {\n      return Monoid{a.num\
    \ + b.num, a.sum + b.sum};\n    }\n    static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                  const OperatorMonoid& b) {\n      return\
    \ a + b;\n    }\n    static Monoid apply(Monoid a, const OperatorMonoid& b) {\n\
    \      a.sum += b * a.num;\n      return a;\n    }\n  };\n  std::vector<M::Monoid>\
    \ init((n - 1) * 2, M::Monoid{0, 0});\n  for (int i = 1; i < n; ++i) {\n    init[lowest_common_ancestor.down[i]].num\
    \ = 1;\n    init[lowest_common_ancestor.up[i]].num = -1;\n  }\n  emthrm::LazySegmentTree<M>\
    \ seg(init);\n  const auto fn = [&seg](const int a, const int b) -> long long\
    \ {\n    return seg.get(a, b).sum;\n  };\n  while (q--) {\n    int type;\n   \
    \ std::cin >> type;\n    if (type == 0) {\n      int u, v;\n      std::cin >>\
    \ u >> v;\n      const int lca = lowest_common_ancestor.query(u, v);\n      std::cout\
    \ << lowest_common_ancestor.query_e<long long>(lca, u, fn)\n                 \
    \  + lowest_common_ancestor.query_e<long long>(lca, v, fn)\n                <<\
    \ '\\n';\n    } else if (type == 1) {\n      int v, x;\n      std::cin >> v >>\
    \ x;\n      lowest_common_ancestor.update_subtree_e(\n          v, [&seg, x](const\
    \ int a, const int b) { seg.apply(a, b, x); });\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/lazy_segment_tree.hpp
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/lowest_common_ancestor_by_euler_tour.hpp
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/graph/tree/euler_tour.hpp
  isVerificationFile: true
  path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
- /verify/test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
  \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
---
