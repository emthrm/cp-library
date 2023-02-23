---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/sparse_table.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/sparse table\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/sparse_table.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  std::vector<int> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  emthrm::SparseTable<int>\
    \ dst(\n      a, [](const int a, const int b) -> int { return std::min(a, b);\
    \ });\n  while (q--) {\n    int l, r;\n    std::cin >> l >> r;\n    std::cout\
    \ << dst.query(l, r) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/data_structure/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/sparse_table.test.cpp
- /verify/test/data_structure/sparse_table.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/sparse table"
---
