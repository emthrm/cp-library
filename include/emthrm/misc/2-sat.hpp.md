---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/2-sat.test.cpp
    title: "\u305D\u306E\u4ED6/2-SAT"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/misc/2-sat.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\nnamespace emthrm {\n\nstruct TwoSat {\n  explicit TwoSat(const\
    \ int n)\n      : n(n), graph(n << 1), rgraph(n << 1), is_visited(n << 1), ids(n\
    \ << 1) {\n    order.reserve(n << 1);\n  }\n\n  int negate(const int x) const\
    \ { return (n + x) % (n << 1); }\n\n  void add_or(const int x, const int y) {\n\
    \    graph[negate(x)].emplace_back(y);\n    graph[negate(y)].emplace_back(x);\n\
    \    rgraph[y].emplace_back(negate(x));\n    rgraph[x].emplace_back(negate(y));\n\
    \  }\n\n  void add_if(const int x, const int y) { add_or(negate(x), y); }\n\n\
    \  void add_nand(const int x, const int y) { add_or(negate(x), negate(y)); }\n\
    \n  void set_true(const int x) { add_or(x, x); }\n\n  void set_false(const int\
    \ x) { set_true(negate(x)); }\n\n  std::vector<bool> build() {\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\n    std::fill(ids.begin(), ids.end(), -1);\n    order.clear();\n\
    \    for (int i = 0; i < (n << 1); ++i) {\n      if (!is_visited[i]) dfs(i);\n\
    \    }\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\n      if (ids[order[i]]\
    \ == -1) rdfs(order[i], id++);\n    }\n    std::vector<bool> res(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n      if (ids[i] == ids[negate(i)]) return {};\n\
    \      res[i] = ids[negate(i)] < ids[i];\n    }\n    return res;\n  }\n\n private:\n\
    \  const int n;\n  std::vector<std::vector<int>> graph, rgraph;\n  std::vector<bool>\
    \ is_visited;\n  std::vector<int> ids, order;\n\n  void dfs(const int ver) {\n\
    \    is_visited[ver] = true;\n    for (const int dst : graph[ver]) {\n      if\
    \ (!is_visited[dst]) dfs(dst);\n    }\n    order.emplace_back(ver);\n  }\n\n \
    \ void rdfs(const int ver, const int cur_id) {\n    ids[ver] = cur_id;\n    for\
    \ (const int dst : rgraph[ver]) {\n      if (ids[dst] == -1) rdfs(dst, cur_id);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MISC_2_SAT_HPP_\n#define EMTHRM_MISC_2_SAT_HPP_\n\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace emthrm {\n\nstruct TwoSat {\n  explicit\
    \ TwoSat(const int n)\n      : n(n), graph(n << 1), rgraph(n << 1), is_visited(n\
    \ << 1), ids(n << 1) {\n    order.reserve(n << 1);\n  }\n\n  int negate(const\
    \ int x) const { return (n + x) % (n << 1); }\n\n  void add_or(const int x, const\
    \ int y) {\n    graph[negate(x)].emplace_back(y);\n    graph[negate(y)].emplace_back(x);\n\
    \    rgraph[y].emplace_back(negate(x));\n    rgraph[x].emplace_back(negate(y));\n\
    \  }\n\n  void add_if(const int x, const int y) { add_or(negate(x), y); }\n\n\
    \  void add_nand(const int x, const int y) { add_or(negate(x), negate(y)); }\n\
    \n  void set_true(const int x) { add_or(x, x); }\n\n  void set_false(const int\
    \ x) { set_true(negate(x)); }\n\n  std::vector<bool> build() {\n    std::fill(is_visited.begin(),\
    \ is_visited.end(), false);\n    std::fill(ids.begin(), ids.end(), -1);\n    order.clear();\n\
    \    for (int i = 0; i < (n << 1); ++i) {\n      if (!is_visited[i]) dfs(i);\n\
    \    }\n    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {\n      if (ids[order[i]]\
    \ == -1) rdfs(order[i], id++);\n    }\n    std::vector<bool> res(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n      if (ids[i] == ids[negate(i)]) return {};\n\
    \      res[i] = ids[negate(i)] < ids[i];\n    }\n    return res;\n  }\n\n private:\n\
    \  const int n;\n  std::vector<std::vector<int>> graph, rgraph;\n  std::vector<bool>\
    \ is_visited;\n  std::vector<int> ids, order;\n\n  void dfs(const int ver) {\n\
    \    is_visited[ver] = true;\n    for (const int dst : graph[ver]) {\n      if\
    \ (!is_visited[dst]) dfs(dst);\n    }\n    order.emplace_back(ver);\n  }\n\n \
    \ void rdfs(const int ver, const int cur_id) {\n    ids[ver] = cur_id;\n    for\
    \ (const int dst : rgraph[ver]) {\n      if (ids[dst] == -1) rdfs(dst, cur_id);\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MISC_2_SAT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/misc/2-sat.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/2-sat.test.cpp
documentation_of: include/emthrm/misc/2-sat.hpp
layout: document
title: 2-SAT
---

節内のリテラル数が高々 $2$ である連言標準形の充足可能性を判定する問題である。


## 時間計算量

$N$ 変数 $M$ 節 のとき $O(N + M)$


## 仕様

```cpp
struct TwoSat;
```

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit TwoSat(const int n);`|$N$ 変数のオブジェクトを構築する。|
|`int negate(const int x) const;`|$\neg x$ を表す頂点番号|
|`void add_or(const int x, const int y);`|$x \vee y$ を追加する。|
|`void add_if(const int x, const int y);`|$x \Rightarrow y$ を追加する。|
|`void add_nand(const int x, const int y);`|$\neg (x \land y)$ を追加する。|
|`void set_true(const int x);`|$x$ を真とする。|
|`void set_false(const int x);`|$x$ を偽とする。|
|`std::vector<bool> build();`|変数の真理値。ただし矛盾が生じるときは空配列を返す。|


## 参考文献

- Bengt Aspvall, Michael F. Plass, and Robert Endre Tarjan: A linear-time algorithm for testing the truth of certain quantified boolean formulas, *Information Processing Letters*, Vol. 8, No. 3, pp. 121–123 (1979). https://doi.org/10.1016/0020-0190(79)90002-4
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.288-290，マイナビ出版（2012）
- https://github.com/beet-aizu/library/blob/346558ee0881bd18b10c0d32d7678b033d6b0326/graph/stronglyconnectedcomponent.cpp


## Submissons

- https://judge.yosupo.jp/submission/2711
