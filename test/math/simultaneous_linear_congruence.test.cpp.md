---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  - icon: ':x:'
    path: include/emthrm/math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    document_title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/simultaneous_linear_congruence.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\n */\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/186\"\n\n#include <iostream>\n\
    #include <tuple>\n#include <vector>\n\n#include \"emthrm/math/simultaneous_linear_congruence.hpp\"\
    \n\nint main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n  long long\
    \ ans, mod;\n  std::tie(ans, mod) = emthrm::simultaneous_linear_congruence(\n\
    \      std::vector<long long>(N, 1), x, y);\n  if (mod == 0) {\n    std::cout\
    \ << \"-1\\n\";\n  } else {\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/simultaneous_linear_congruence.hpp
  - include/emthrm/math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/simultaneous_linear_congruence.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/simultaneous_linear_congruence.test.cpp
layout: document
redirect_from:
- /verify/test/math/simultaneous_linear_congruence.test.cpp
- /verify/test/math/simultaneous_linear_congruence.test.cpp.html
title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
---
