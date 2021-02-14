---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/inverse_element/mod_inv_extgcd.hpp
    title: "\u9006\u5143 \u62E1\u5F35 Euclid \u306E\u4E92\u9664\u6CD5\u7248"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\
      \u9805\u4FC2\u6570"
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp: line 6:\
    \ #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\
    /\u4E8C\u9805\u4FC2\u6570\r\n */\r\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../../../math/modint.hpp\"\
    \r\n#include \"../../../../math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr int MOD = 1000000007;\r\n  BinomialCoefficients\
    \ bc(MOD, 1000000);\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(MOD);\r\n\
    \  ModInt::init(1999999);\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\
    \n    std::string s;\r\n    std::cin >> s;\r\n    std::string n = \"\";\r\n  \
    \  int idx = 2;\r\n    while (true) {\r\n      char c = s[idx];\r\n      if (c\
    \ == ',') break;\r\n      n += c;\r\n      ++idx;\r\n    }\r\n    std::string\
    \ k = s.substr(idx + 1);\r\n    if (s[0] == 'C') {\r\n      std::cout << bc.query(std::stoi(n),\
    \ std::stoi(k));\r\n    } else if (s[0] == 'P') {\r\n      std::cout << ModInt::nPk(std::stoi(n),\
    \ std::stoi(k));\r\n    } else {\r\n      std::cout << ModInt::nHk(std::stoi(n),\
    \ std::stoi(k));\r\n    }\r\n    std::cout << '\\n';\r\n  }\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/binomial_coefficients/binomial_coefficients.hpp
  - math/inverse_element/mod_inv_extgcd.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp
- /verify/test/math/twelvefold_way/binomial_coefficients/binomial_coefficients.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570/\u4E8C\u9805\u4FC2\
  \u6570"
---
