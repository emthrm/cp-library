---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dynamic_programming/convert_online_dp_to_offline_dp.hpp
    title: "\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\
      \u63DB"
  - icon: ':question:'
    path: math/convolution/number_theoretic_transform.hpp
    title: "\u6570\u8AD6\u5909\u63DB"
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
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\
      \u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/abc213/tasks/abc213_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/convolution/number_theoretic_transform.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\
    \u30FB\u30AA\u30F3\u30E9\u30A4\u30F3\u5909\u63DB\r\n */\r\n#define IGNORE\r\n\
    #define PROBLEM \"https://atcoder.jp/contests/abc213/tasks/abc213_h\"\r\n\r\n\
    #include <algorithm>\r\n#include <functional>\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include \"../../math/modint.hpp\"\r\n#include \"../../math/convolution/number_theoretic_transform.hpp\"\
    \r\n#include \"../../dynamic_programming/convert_online_dp_to_offline_dp.hpp\"\
    \r\n\r\nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(998244353);\r\
    \n  int n, m, t;\r\n  std::cin >> n >> m >> t;\r\n  std::vector<int> a(m), b(m);\r\
    \n  std::vector<std::vector<ModInt>> p(m, std::vector<ModInt>(t + 1, 0));\r\n\
    \  for (int i = 0; i < m; ++i) {\r\n    std::cin >> a[i] >> b[i];\r\n    --a[i];\
    \ --b[i];\r\n    for (int j = 1; j <= t; ++j) {\r\n      std::cin >> p[i][j];\r\
    \n    }\r\n  }\r\n  std::vector<std::vector<ModInt>> dp(n, std::vector(t + 1,\
    \ ModInt(0)));\r\n  dp[0][0] = 1;\r\n  NumberTheoreticTransform<0> ntt;\r\n  std::function<void(int,\
    \ int, int)> induce = [m, &dp, &a, &b, &p, &ntt](int l, int mid, int r) -> void\
    \ {\r\n    for (int id = 0; id < m; ++id) {\r\n      std::vector<ModInt> dp_id(mid\
    \ - l), p_id(r - l);\r\n      std::copy(dp[a[id]].begin() + l, dp[a[id]].begin()\
    \ + mid, dp_id.begin());\r\n      std::copy(p[id].begin(), p[id].begin() + (r\
    \ - l), p_id.begin());\r\n      std::vector<ModInt> c = ntt.convolution(dp_id,\
    \ p_id);\r\n      for (int i = mid; i < r; ++i) {\r\n        dp[b[id]][i] += c[i\
    \ - l];\r\n      }\r\n      std::copy(dp[b[id]].begin() + l, dp[b[id]].begin()\
    \ + mid, dp_id.begin());\r\n      c = ntt.convolution(dp_id, p_id);\r\n      for\
    \ (int i = mid; i < r; ++i) {\r\n        dp[a[id]][i] += c[i - l];\r\n      }\r\
    \n    }\r\n  };\r\n  convert_online_dp_to_offline_dp(t + 1, induce);\r\n  std::cout\
    \ << dp[0][t] << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/convolution/number_theoretic_transform.hpp
  - dynamic_programming/convert_online_dp_to_offline_dp.hpp
  isVerificationFile: true
  path: test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
  requiredBy: []
  timestamp: '2021-08-20 04:01:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp
- /verify/test/dynamic_programming/convert_online_dp_to_offline_dp.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u30AA\u30D5\u30E9\u30A4\u30F3\u30FB\u30AA\u30F3\
  \u30E9\u30A4\u30F3\u5909\u63DB"
---
