---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (strongly connected components)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/2-sat.test.cpp
    title: "\u305D\u306E\u4ED6/2-SAT"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#pragma once\r\n#include <vector>\r\n#include \"../graph/edge.hpp\"\r\n#include\
    \ \"../graph/scc.hpp\"\r\n\r\nstruct TwoSat {\r\n  TwoSat(int n) : n(n), graph(n\
    \ << 1) {}\r\n\r\n  int negate(int x) const { return (n + x) % (n << 1); }\r\n\
    \r\n  void add_or(int x, int y) {\r\n    graph[negate(x)].emplace_back(negate(x),\
    \ y);\r\n    graph[negate(y)].emplace_back(negate(y), x);\r\n  }\r\n\r\n  void\
    \ add_if(int x, int y) { add_or(negate(x), y); }\r\n\r\n  void add_nand(int x,\
    \ int y) { add_or(negate(x), negate(y)); }\r\n\r\n  void set_true(int x) { add_or(x,\
    \ x); }\r\n\r\n  void set_false(int x) { set_true(negate(x)); }\r\n\r\n  std::vector<bool>\
    \ build() const {\r\n    SCC<bool> scc(graph);\r\n    std::vector<bool> res(n);\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      if (scc.id[i] == scc.id[negate(i)])\
    \ return {};\r\n      res[i] = scc.id[negate(i)] < scc.id[i];\r\n    }\r\n   \
    \ return res;\r\n  }\r\n\r\nprivate:\r\n  int n;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph;\r\n};\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/scc.hpp
  isVerificationFile: false
  path: misc/2-sat.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/2-sat.test.cpp
documentation_of: misc/2-sat.hpp
layout: document
title: 2-SAT
---

節内のリテラル数が高々2である連言標準形の充足可能性を判定する問題である．


## 時間計算量

$N$ 変数 $M$ 節 のとき $O(N + M)$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`TwoSat(n)`|$N$ 変数の 2-SAT を考える．|軽量版では `TwoSatLight(n)` である．|
|`negate(x)`|$\neg x$ を表す頂点番号||
|`add_or(x, y)`|$x \vee y$ を追加する．||
|`add_if(x, y)`|$x \Rightarrow y$ を追加する．||
|`add_nand(x, y)`|$\neg (x \land y)$ を追加する．||
|`set_true(x)`|$x$ を $T$ とする．||
|`set_false(x)`|$x$ を $F$ とする．||
|`build()`|各変数の真理値|矛盾が生じる場合は空配列となる．|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.288-290
- https://github.com/beet-aizu/library/blob/master/graph/stronglyconnectedcomponent.cpp


## Verified

- https://judge.yosupo.jp/submission/2712
- [軽量版](https://judge.yosupo.jp/submission/2711)
