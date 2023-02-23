---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/misc/sqrt_decomposition.hpp
    title: "\u5E73\u65B9\u5206\u5272 (sqrt decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/misc/sqrt_decomposition.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/misc/sqrt_decomposition.hpp\"\
    \n\nstd::vector<long long> a, b, lazy;\n\ntemplate <typename T>\nvoid emthrm::SqrtDecomposition::partial_update(const\
    \ int idx, const T val) {\n  a[idx] += val;\n  b[idx / block_size] += val;\n}\n\
    \ntemplate <typename T>\nvoid emthrm::SqrtDecomposition::total_update(const int\
    \ idx, const T val) {\n  lazy[idx] += val;\n  to_be_eval[idx] = true;\n}\n\ntemplate\
    \ <typename T>\nvoid emthrm::SqrtDecomposition::partial_query(const int idx, T*\
    \ val) {\n  const int block = idx / block_size;\n  if (to_be_eval[block]) {\n\
    \    for (int i = ls[block]; i < rs[block]; ++i) {\n      partial_update(i, lazy[block]);\n\
    \    }\n    lazy[block] = 0;\n    to_be_eval[block] = false;\n  }\n  *val += a[idx];\n\
    }\n\ntemplate <typename T>\nvoid emthrm::SqrtDecomposition::total_query(const\
    \ int idx, T* val) {\n  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);\n}\n\
    \nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::SqrtDecomposition\
    \ sqrt_decomposition(n);\n  a.assign(n, 0);\n  b.assign(sqrt_decomposition.n,\
    \ 0);\n  lazy.assign(sqrt_decomposition.n, 0);\n  while (q--) {\n    int type,\
    \ s, t;\n    std::cin >> type >> s >> t;\n    --s; --t;\n    if (type == 0) {\n\
    \      int x;\n      std::cin >> x;\n      sqrt_decomposition.update(s, t + 1,\
    \ x);\n    } else if (type == 1) {\n      std::cout << sqrt_decomposition.query(s,\
    \ t + 1, 0LL) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/misc/sqrt_decomposition.hpp
  isVerificationFile: true
  path: test/misc/sqrt_decomposition.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/sqrt_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/misc/sqrt_decomposition.test.cpp
- /verify/test/misc/sqrt_decomposition.test.cpp.html
title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
---
