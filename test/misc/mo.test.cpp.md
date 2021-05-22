---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
  - icon: ':heavy_check_mark:'
    path: misc/mo.hpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    document_title: "\u305D\u306E\u4ED6/Mo's algorithm"
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/Mo's algorithm\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <iterator>\r\n#include <vector>\r\
    \n#include \"../../data_structure/fenwick_tree/fenwick_tree.hpp\"\r\n#include\
    \ \"../../misc/mo.hpp\"\r\n\r\nstd::vector<int> a;\r\nlong long inv = 0;\r\nint\
    \ l = 0, r = 0, m;\r\nconstexpr int M = 100000;\r\nFenwickTree<int> bit(M);\r\n\
    \r\nvoid Mo::add(int idx) const {\r\n  if (idx + 1 == l) {\r\n    inv += bit.sum(0,\
    \ a[idx]);\r\n    --l;\r\n  } else if (idx == r) {\r\n    inv += bit.sum(a[idx]\
    \ + 1, m);\r\n    ++r;\r\n  }\r\n  bit.add(a[idx], 1);\r\n}\r\n\r\nvoid Mo::del(int\
    \ idx) const {\r\n  if (idx == l) {\r\n    inv -= bit.sum(0, a[idx]);\r\n    ++l;\r\
    \n  } else if (idx + 1 == r) {\r\n    inv -= bit.sum(a[idx] + 1, m);\r\n    --r;\r\
    \n  }\r\n  bit.add(a[idx], -1);\r\n}\r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin\
    \ >> n >> q;\r\n  a.resize(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\
    \n  std::vector<int> tmp(a);\r\n  std::sort(tmp.begin(), tmp.end());\r\n  tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\r\n  m = tmp.size();\r\n  for (int i = 0; i < n; ++i)\
    \ {\r\n    a[i] = std::distance(tmp.begin(), std::lower_bound(tmp.begin(), tmp.end(),\
    \ a[i]));\r\n  }\r\n  std::vector<int> left(q), right(q);\r\n  for (int i = 0;\
    \ i < q; ++i) std::cin >> left[i] >> right[i];\r\n  Mo mo(left, right);\r\n  std::vector<long\
    \ long> ans(q);\r\n  for (int i = 0; i < q; ++i) {\r\n    int idx = mo.process();\r\
    \n    ans[idx] = inv;\r\n  }\r\n  for (int i = 0; i < q; ++i) std::cout << ans[i]\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree/fenwick_tree.hpp
  - misc/mo.hpp
  isVerificationFile: true
  path: test/misc/mo.test.cpp
  requiredBy: []
  timestamp: '2021-04-24 04:29:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/mo.test.cpp
layout: document
redirect_from:
- /verify/test/misc/mo.test.cpp
- /verify/test/misc/mo.test.cpp.html
title: "\u305D\u306E\u4ED6/Mo's algorithm"
---
