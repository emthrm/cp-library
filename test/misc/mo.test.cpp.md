---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
  - icon: ':x:'
    path: include/emthrm/misc/mo.hpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    document_title: "\u305D\u306E\u4ED6/Mo's algorithm"
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/fenwick_tree/fenwick_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/Mo's algorithm\n */\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <iterator>\n#include <vector>\n\n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n#include \"emthrm/misc/mo.hpp\"\n\nstd::vector<int> a;\nlong long inv = 0;\n\
    int l = 0, r = 0, m;\nconstexpr int M = 100000;\nemthrm::FenwickTree<int> bit(M);\n\
    \nvoid emthrm::Mo::add(const int idx) const {\n  if (idx + 1 == l) {\n    inv\
    \ += bit.sum(0, a[idx]);\n    --l;\n  } else if (idx == r) {\n    inv += bit.sum(a[idx]\
    \ + 1, m);\n    ++r;\n  }\n  bit.add(a[idx], 1);\n}\n\nvoid emthrm::Mo::del(const\
    \ int idx) const {\n  if (idx == l) {\n    inv -= bit.sum(0, a[idx]);\n    ++l;\n\
    \  } else if (idx + 1 == r) {\n    inv -= bit.sum(a[idx] + 1, m);\n    --r;\n\
    \  }\n  bit.add(a[idx], -1);\n}\n\nint main() {\n  int n, q;\n  std::cin >> n\
    \ >> q;\n  a.resize(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n\
    \  }\n  std::vector<int> tmp = a;\n  std::sort(tmp.begin(), tmp.end());\n  tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n  m = tmp.size();\n  for (int i = 0; i < n; ++i) {\n\
    \    a[i] = std::distance(tmp.begin(),\n                         std::lower_bound(tmp.begin(),\
    \ tmp.end(), a[i]));\n  }\n  std::vector<int> ls(q), rs(q);\n  for (int i = 0;\
    \ i < q; ++i) {\n    std::cin >> ls[i] >> rs[i];\n  }\n  emthrm::Mo mo(ls, rs);\n\
    \  std::vector<long long> ans(q);\n  for (int i = 0; i < q; ++i) {\n    const\
    \ int idx = mo.process();\n    ans[idx] = inv;\n  }\n  for (int i = 0; i < q;\
    \ ++i) {\n    std::cout << ans[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  - include/emthrm/misc/mo.hpp
  isVerificationFile: true
  path: test/misc/mo.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/mo.test.cpp
layout: document
redirect_from:
- /verify/test/misc/mo.test.cpp
- /verify/test/misc/mo.test.cpp.html
title: "\u305D\u306E\u4ED6/Mo's algorithm"
---
