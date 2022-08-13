---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/rerooting_dp.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u5168\u65B9\u4F4D\u6728 DP"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <vector>\n\
    \n#include \"../edge.hpp\"\n\ntemplate <typename CostType, typename CommutativeSemigroup,\n\
    \          typename E, typename F, typename G>\nstd::vector<CommutativeSemigroup>\
    \ rerooting_dp(\n    const std::vector<std::vector<Edge<CostType>>>& graph,\n\
    \    const std::vector<CommutativeSemigroup>& def,\n    const E merge, const F\
    \ f, const G g) {\n  const int n = graph.size();\n  if (n == 0) return {};\n \
    \ if (n == 1) return {g(def[0], 0)};\n  std::vector<std::vector<CommutativeSemigroup>>\
    \ children(n);\n  const std::function<CommutativeSemigroup(const int, const int)>\
    \ dfs1 =\n      [&graph, &def, merge, f, g, &children, &dfs1](\n          const\
    \ int par, const int ver) -> CommutativeSemigroup {\n        children[ver].reserve(graph[ver].size());\n\
    \        CommutativeSemigroup dp = def[ver];\n        for (const Edge<CostType>&\
    \ e : graph[ver]) {\n          if (e.dst == par) {\n            children[ver].emplace_back();\n\
    \          } else {\n            children[ver].emplace_back(f(dfs1(ver, e.dst),\
    \ e));\n            dp = merge(dp, children[ver].back());\n          }\n     \
    \   }\n        return g(dp, ver);\n      };\n  dfs1(-1, 0);\n  std::vector<CommutativeSemigroup>\
    \ dp = def;\n  const std::function<void(const int, const int,\n              \
    \             const CommutativeSemigroup&)> dfs2 =\n      [&graph, &def, merge,\
    \ f, g, &children, &dp, &dfs2](\n          const int par, const int ver, const\
    \ CommutativeSemigroup& m) -> void {\n        const int c = graph[ver].size();\n\
    \        for (int i = 0; i < c; ++i) {\n          if (graph[ver][i].dst == par)\
    \ {\n            children[ver][i] = f(m, graph[ver][i]);\n            break;\n\
    \          }\n        }\n        std::vector<CommutativeSemigroup> left{def[ver]},\
    \ right;\n        left.reserve(c);\n        for (int i = 0; i < c - 1; ++i) {\n\
    \          left.emplace_back(merge(left[i], children[ver][i]));\n        }\n \
    \       dp[ver] = g(merge(left.back(), children[ver].back()), ver);\n        if\
    \ (c >= 2) {\n          right.reserve(c - 1);\n          right.emplace_back(children[ver].back());\n\
    \          for (int i = c - 2; i > 0; --i) {\n            right.emplace_back(merge(children[ver][i],\
    \ right[c - 2 - i]));\n          }\n          std::reverse(right.begin(), right.end());\n\
    \        }\n        for (int i = 0; i < c; ++i) {\n          if (graph[ver][i].dst\
    \ != par) {\n            dfs2(ver, graph[ver][i].dst,\n                 g(i +\
    \ 1 == c ? left[i] : merge(left[i], right[i]), ver));\n          }\n        }\n\
    \      };\n  dfs2(-1, 0, CommutativeSemigroup());\n  return dp;\n}\n"
  dependsOn:
  - graph/edge.hpp
  isVerificationFile: false
  path: graph/tree/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/rerooting_dp.test.cpp
documentation_of: graph/tree/rerooting_dp.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728 DP"
---


## 使用法

||説明|
|:--:|:--:|
|`rerooting_dp(graph, def, merge, f, g)`|木 $\mathrm{graph}$ に対する全方位木 DP|


## 例

- [木の直径](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_A/review/6390469/emthrm/C++17)
- [高橋王国の分割統治](https://atcoder.jp/contests/arc028/submissions/29989915)
- [限界集落](https://atcoder.jp/contests/njpc2017/submissions/29991480)
- [Driving on a Tree](https://atcoder.jp/contests/s8pc-4/submissions/29991981)
- [The Fair Nut and the Best Path](https://codeforces.com/contest/1084/submission/149080099)
- [Subtree](https://atcoder.jp/contests/dp/submissions/29989850)
- [Maximum White Subtree](https://codeforces.com/contest/1324/submission/149079224)
- [Distributing Integers](https://atcoder.jp/contests/abc160/submissions/29989897)
- [Distance Sums 2](https://atcoder.jp/contests/abc220/submissions/29989935)
- [Expensive Expense](https://atcoder.jp/contests/abc222/submissions/29989944)
- [Vertex Deletion](https://atcoder.jp/contests/abc223/submissions/29989873)


## 参考

- https://ei1333.hateblo.jp/entry/2017/04/10/224413
- https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
- https://snuke.hatenablog.com/entry/2019/01/16/203626
- https://rsk0315.hatenablog.com/entry/2021/06/27/013506
- https://null-mn.hatenablog.com/entry/2020/04/14/124151
- https://twitter.com/noshi91/status/1438937367847456772
