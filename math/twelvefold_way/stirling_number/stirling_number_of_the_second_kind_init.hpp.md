---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/twelvefold_way/bell_number/bell_number_init.hpp
    title: "\u30D9\u30EB\u6570\u306E\u6570\u8868"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570\
      \u306E\u6570\u8868"
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/stirling_number/stirling_number.md
    document_title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
      \u6570\u8868"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp:\
    \ line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
    \u6570\u8868\r\n * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../../modint.hpp\"\
    \r\n\r\ntemplate <typename T>\r\nstd::vector<std::vector<T>> stirling_number_of_the_second_kind_init(int\
    \ n, int k) {\r\n  std::vector<std::vector<T>> stirling(n + 1, std::vector<T>(k\
    \ + 1, 0));\r\n  stirling[0][0] = 1;\r\n  for (int i = 1; i <= n; ++i) for (int\
    \ j = 1; j <= i && j <= k; ++j) {\r\n    stirling[i][j] = stirling[i - 1][j -\
    \ 1] + stirling[i - 1][j] * j;\r\n  }\r\n  return stirling;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  isVerificationFile: false
  path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
  requiredBy:
  - math/twelvefold_way/bell_number/bell_number_init.hpp
  timestamp: '2021-03-07 02:53:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/bell_number/bell_number_init.test.cpp
  - test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.test.cpp
documentation_of: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init.hpp.html
title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868"
---
