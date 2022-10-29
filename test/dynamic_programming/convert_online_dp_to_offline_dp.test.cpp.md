---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/convert_online_dp_to_offline_dp.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\
      \u63DB"
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://atcoder.jp/contests/abc213/tasks/abc213_h
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\
      \u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/abc213/tasks/abc213_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\
    \u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\u63DB\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_h\"\
    \n\n#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <iterator>\n#include <vector>\n\n#include \"../../dynamic_programming/convert_online_dp_to_offline_dp.hpp\"\
    \n#include \"../../math/convolution/number_theoretic_transform.hpp\"\n#include\
    \ \"../../math/modint.hpp\"\n\nint main() {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(998244353);\n\
    \  int n, m, t;\n  std::cin >> n >> m >> t;\n  std::vector<int> a(m), b(m);\n\
    \  std::vector<std::vector<ModInt>> p(m, std::vector<ModInt>(t + 1, 0));\n  for\
    \ (int i = 0; i < m; ++i) {\n    std::cin >> a[i] >> b[i];\n    --a[i]; --b[i];\n\
    \    for (int j = 1; j <= t; ++j) {\n      std::cin >> p[i][j];\n    }\n  }\n\
    \  std::vector<std::vector<ModInt>> dp(n, std::vector<ModInt>(t + 1, 0));\n  dp[0][0]\
    \ = 1;\n  const std::function<void(int, int, int)> induce =\n      [m, &a, &b,\
    \ &p, &dp](const int l, const int mid, const int r) -> void {\n        static\
    \ NumberTheoreticTransform<0> ntt;\n        for (int id = 0; id < m; ++id) {\n\
    \          std::vector<ModInt> dp_id(mid - l), p_id(r - l);\n          std::copy(std::next(dp[a[id]].begin(),\
    \ l),\n                    std::next(dp[a[id]].begin(), mid), dp_id.begin());\n\
    \          std::copy(p[id].begin(), std::next(p[id].begin(), r - l),\n       \
    \             p_id.begin());\n          std::vector<ModInt> c = ntt.convolution(dp_id,\
    \ p_id);\n          for (int i = mid; i < r; ++i) {\n            dp[b[id]][i]\
    \ += c[i - l];\n          }\n          std::copy(std::next(dp[b[id]].begin(),\
    \ l),\n                    std::next(dp[b[id]].begin(), mid), dp_id.begin());\n\
    \          c = ntt.convolution(dp_id, p_id);\n          for (int i = mid; i <\
    \ r; ++i) {\n            dp[a[id]][i] += c[i - l];\n          }\n        }\n \
    \     };\n  convert_online_dp_to_offline_dp(t + 1, induce);\n  std::cout << dp[0][t]\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - dynamic_programming/convert_online_dp_to_offline_dp.hpp
  - math/convolution/number_theoretic_transform.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
- /verify/test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\u30F3\
  \u30E9\u30A4\u30F3\u5909\u63DB"
---
