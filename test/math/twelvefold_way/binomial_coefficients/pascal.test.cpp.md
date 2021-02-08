---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':x:'
    path: math/twelvefold_way/binomial_coefficients/pascal.hpp
    title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/420
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u30D1\
      \u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
    links:
    - https://yukicoder.me/problems/no/420
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/pascal.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\
    /\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62\r\n */\r\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/420\"\r\n\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include \"../../../../math/bigint.hpp\"\r\n#include \"../../../../math/twelvefold_way/binomial_coefficients/pascal.hpp\"\
    \r\n\r\nint main() {\r\n  using bigint = BigInt<>;\r\n  constexpr int N = 31;\r\
    \n  std::vector<std::vector<bigint>> c = pascal<bigint>(N);\r\n  int x;\r\n  std::cin\
    \ >> x;\r\n  if (x > N) {\r\n    std::cout << 0 << ' ' << 0 << '\\n';\r\n    return\
    \ 0;\r\n  }\r\n  std::cout << c[N][x] << ' ';\r\n  bigint ans = 0;\r\n  if (x\
    \ > 0) {\r\n    for (int bit = 0; bit < N; ++bit) ans += c[N - 1][x - 1] * (1\
    \ << bit);\r\n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/bigint.hpp
  - math/twelvefold_way/binomial_coefficients/pascal.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp
- /verify/test/math/twelvefold_way/binomial_coefficients/pascal.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u30D1\u30B9\u30AB\
  \u30EB\u306E\u4E09\u89D2\u5F62"
---
