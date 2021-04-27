---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
    title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\
      \u6570/\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
      \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/twelvefold_way/stirling_number/stirling_number.md
    document_title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
      \u6570\u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp:\
    \ line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\
    \u6570\u8868 \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248\r\n * @docs docs/math/twelvefold_way/stirling_number/stirling_number.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"../../modint.hpp\"\
    \r\n#include \"../../formal_power_series/formal_power_series.hpp\"\r\n\r\ntemplate\
    \ <int T>\r\nstd::vector<MInt<T>> stirling_number_of_the_second_kind_init_by_fps(int\
    \ n) {\r\n  using ModInt = MInt<T>;\r\n  ModInt::init(n);\r\n  FormalPowerSeries<ModInt>\
    \ a(n), b(n);\r\n  for (int i = 0; i <= n; ++i) a[i] = ModInt(i).pow(n) * ModInt::fact_inv(i);\r\
    \n  for (int i = 0; i <= n; ++i) b[i] = ModInt::fact_inv(i) * (i & 1 ? -1 : 1);\r\
    \n  a *= b;\r\n  a.co.resize(n + 1);\r\n  return a.co;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_with_fps.test.cpp
documentation_of: math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
layout: document
redirect_from:
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp
- /library/math/twelvefold_way/stirling_number/stirling_number_of_the_second_kind_init_by_fps.hpp.html
title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u306E\u6570\u8868\
  \ \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u7248"
---
