---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/noshi_graph.test.cpp
    title: "\u30B0\u30E9\u30D5/\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/graph/edge.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GRAPH_NOSHI_GRAPH_HPP_\n#define EMTHRM_GRAPH_NOSHI_GRAPH_HPP_\n\
    \n#include <bit>\n#include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <typename CostType>\nstruct NoshiGraph {\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n\n  explicit NoshiGraph(const int n)\n      : p2(std::bit_ceil(static_cast<unsigned\
    \ int>(n))) {\n    const int dbl = p2 << 1, hlf = p2 >> 1;\n    graph.resize(dbl\
    \ + p2);\n    for (int i = 1; i < hlf; ++i) {\n      add_edge(i + p2, (i << 1)\
    \ + p2);\n      add_edge(i + p2, (i << 1) + 1 + p2);\n      add_edge((i << 1)\
    \ + dbl, i + dbl);\n      add_edge((i << 1) + 1 + dbl, i + dbl);\n    }\n    for\
    \ (int src = p2 + hlf, dst = 0; dst < p2; ++src, dst += 2) {\n      add_edge(src,\
    \ dst);\n      add_edge(src, dst + 1);\n    }\n    for (int src = 0, dst = dbl\
    \ + hlf; src < p2; src += 2, ++dst) {\n      add_edge(src, dst);\n      add_edge(src\
    \ + 1, dst);\n    }\n  }\n\n  void add_edge(const int src, const int dst, const\
    \ CostType cost = 0) {\n    graph[src].emplace_back(src, dst, cost);\n  }\n\n\
    \  void add_edge(int src_l, int src_r, int dst_l, int dst_r,\n               \
    \ const CostType cost) {\n    if (src_r <= src_l || dst_r <= dst_l) [[unlikely]]\
    \ return;\n    const int src_id = graph.size(), dst_id = src_id + 1;\n    graph.emplace_back();\n\
    \    graph.emplace_back();\n    if ((dst_l += p2) & 1) add_edge(dst_id, dst_l++\
    \ - p2);\n    if ((dst_r += p2) & 1) add_edge(dst_id, --dst_r - p2);\n    for\
    \ (dst_l >>= 1, dst_r >>= 1; dst_l < dst_r; dst_l >>= 1, dst_r >>= 1) {\n    \
    \  if (dst_l & 1) add_edge(dst_id, dst_l++ + p2);\n      if (dst_r & 1) add_edge(dst_id,\
    \ --dst_r + p2);\n    }\n    add_edge(src_id, dst_id, cost);\n    if ((src_l +=\
    \ p2) & 1) add_edge(src_l++ - p2, src_id);\n    if ((src_r += p2) & 1) add_edge(--src_r\
    \ - p2, src_id);\n    for (src_l >>= 1, src_r >>= 1; src_l < src_r; src_l >>=\
    \ 1, src_r >>= 1) {\n      if (src_l & 1) add_edge(src_l++ + (p2 << 1), src_id);\n\
    \      if (src_r & 1) add_edge(--src_r + (p2 << 1), src_id);\n    }\n  }\n\n private:\n\
    \  const int p2;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_NOSHI_GRAPH_HPP_\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  isVerificationFile: false
  path: include/emthrm/graph/noshi_graph.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/noshi_graph.test.cpp
documentation_of: include/emthrm/graph/noshi_graph.hpp
layout: document
title: "\u533A\u9593\u306B\u8FBA\u3092\u5F35\u308B\u30C6\u30AF"
---


## 時間計算量

$O(\log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct NoshiGraph;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::vector<Edge<CostType>>> graph`|有向グラフ|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit NoshiGraph(const int n);`|頂点数 $n$ のオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const CostType cost = 0);`|コスト $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。|
|`add_edge(src_l, src_r, dst_l, dst_r, cost);`|コスト $\mathrm{cost}$ の辺 $(s, t)$ ($s \in \lbrace \mathrm{srcL}, \ldots, \mathrm{srcR} - 1 \rbrace,\ t \in \lbrace \mathrm{dstL}, \ldots, \mathrm{dstR} - 1 \rbrace$) を加える。|


## 参考文献

- https://twitter.com/noshi91/status/1193177214453338113
- https://twitter.com/noshi91/status/1272380264396648448
- https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656


## Submissons

https://codeforces.com/contest/786/submission/100222769
