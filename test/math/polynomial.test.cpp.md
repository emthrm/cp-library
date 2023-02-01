---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: include/emthrm/math/polynomial.hpp
    title: "\u591A\u9805\u5F0F (polynomial)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u591A\u9805\u5F0F"
    links:
    - https://judge.yosupo.jp/problem/division_of_polynomials
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u591A\u9805\u5F0F\n */\n#define IGNORE\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\n\n#include\
    \ <iostream>\n#if __cplusplus < 201703L\n# include <tuple>\n#endif  // __cplusplus\
    \ < 201703L\n\n#include \"emthrm/math/modint.hpp\"\n#include \"emthrm/math/polynomial.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<998244353>;\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  emthrm::Polynomial<ModInt> f(n - 1), g(m - 1);\n  for (int i =\
    \ 0; i < n; ++i) {\n    std::cin >> f[i];\n  }\n  for (int i = 0; i < m; ++i)\
    \ {\n    std::cin >> g[i];\n  }\n#if __cplusplus >= 201703L\n  auto [q, r] = f.divide(g);\n\
    #else\n  emthrm::Polynomial<ModInt> q, r;\n  std::tie(q, r) = f.divide(g);\n#endif\
    \  // __cplusplus >= 201703L\n  q.shrink();\n  r.shrink();\n  const int u = (q\
    \ == emthrm::Polynomial<ModInt>{0} ? 0 : q.degree() + 1);\n  const int v = (r\
    \ == emthrm::Polynomial<ModInt>{0} ? 0 : r.degree() + 1);\n  std::cout << u <<\
    \ ' ' << v << '\\n';\n  for (int i = 0; i < u; ++i) {\n    std::cout << q[i];\n\
    \    if (i + 1 < u) std::cout << ' ';\n  }\n  std::cout << '\\n';\n  for (int\
    \ i = 0; i < v; ++i) {\n    std::cout << r[i];\n    if (i + 1 < v) std::cout <<\
    \ ' ';\n  }\n  std::cout << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/polynomial.hpp
  isVerificationFile: true
  path: test/math/polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 16:05:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/math/polynomial.test.cpp
- /verify/test/math/polynomial.test.cpp.html
title: "\u6570\u5B66/\u591A\u9805\u5F0F"
---
