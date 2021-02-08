---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/ntt.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
  - icon: ':question:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':x:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/931
    document_title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
    links:
    - https://yukicoder.me/problems/no/931
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/is_primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A\r\n */\r\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/931\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#include \"../../math/modint.hpp\"\r\n#include \"../../math/is_primitive_root.hpp\"\
    \r\n#include \"../../math/convolution/ntt.hpp\"\r\n\r\nint main() {\r\n  int p;\r\
    \n  std::cin >> p;\r\n  ModInt::set_mod(p);\r\n  std::vector<int> memo(p - 1);\r\
    \n  for (int root = 2; ; ++root) {\r\n    if (is_primitive_root(root, p)) {\r\n\
    \      for (int i = 0; i < p - 1; ++i) memo[i] = ModInt(root).pow(i).val;\r\n\
    \      break;\r\n    }\r\n  }\r\n  std::vector<int> a(p, 0), b(p, 0);\r\n  for\
    \ (int i = 1; i < p; ++i) std::cin >> a[i];\r\n  for (int i = 1; i < p; ++i) std::cin\
    \ >> b[i];\r\n  ModInt::set_mod(998244353);\r\n  NTT ntt;\r\n  std::vector<ModInt>\
    \ A(p - 1, 0), B(p - 1, 0);\r\n  for (int i = 0; i < p - 1; ++i) {\r\n    A[i]\
    \ = a[memo[i]];\r\n    B[i] = b[memo[i]];\r\n  }\r\n  std::vector<ModInt> C =\
    \ ntt.convolution(A, B);\r\n  for (int i = p - 1; i < C.size(); ++i) C[i % (p\
    \ - 1)] += C[i];\r\n  std::vector<ModInt> ans(p, 0);\r\n  for (int i = 0; i <\
    \ p - 1; ++i) ans[memo[i]] = C[i];\r\n  for (int i = 1; i < p; ++i) std::cout\
    \ << ans[i] << \" \\n\"[i + 1 == p];\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/is_primitive_root.hpp
  - math/divisor.hpp
  - math/mod_pow.hpp
  - math/convolution/ntt.hpp
  isVerificationFile: true
  path: test/math/is_primitive_root.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/is_primitive_root.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_primitive_root.test.cpp
- /verify/test/math/is_primitive_root.test.cpp.html
title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
---
