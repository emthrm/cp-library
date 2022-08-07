---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB"
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB\
    \n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../../../math/convolution/number_theoretic_transform.hpp\"\
    \n#include \"../../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n\
    \  ModInt::set_mod(998244353);\n  int n, m;\n  std::cin >> n >> m;\n  std::vector<int>\
    \ a(n), b(m);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n \
    \ for (int i = 0; i < m; ++i) {\n    std::cin >> b[i];\n  }\n  const std::vector<ModInt>\
    \ ans =\n      NumberTheoreticTransform<0>().convolution(a, b);\n  for (int i\
    \ = 0; i <= (n - 1) + (m - 1); ++i) {\n    std::cout << ans[i] << \" \\n\"[i ==\
    \ (n - 1) + (m - 1)];\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/math/convolution/number_theoretic_transform.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/number_theoretic_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/number_theoretic_transform.test.cpp
- /verify/test/math/convolution/number_theoretic_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6570\u8AD6\u5909\u63DB"
---
