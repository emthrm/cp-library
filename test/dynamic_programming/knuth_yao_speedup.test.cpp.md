---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/knuth_yao_speedup.hpp
    title: "Knuth\u2013Yao speedup"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/dynamic_programming/knuth_yao_speedup.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup\n */\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2415\"\
    \n\n#include <iostream>\n#include <limits>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/knuth_yao_speedup.hpp\"\
    \n\n// \u4E8C\u5206\u63A2\u7D22\u6728\u306E\u30B3\u30B9\u30C8 \\sum_{i = 1}^N\
    \ w_i * depth(i) \u306E\u6700\u5C0F\u5024\nint main() {\n  int n;\n  std::cin\
    \ >> n;\n  std::vector<std::vector<long long>> w(n, std::vector<long long>(n));\n\
    \  for (int j = 0; j < n; ++j) {\n    std::cin >> w.front()[j];\n    if (j > 0)\
    \ w.front()[j] += w.front()[j - 1];\n  }\n  for (int i = 1; i < n; ++i) {\n  \
    \  for (int j = i; j < n; ++j) {\n      w[i][j] = w.front()[j] - w.front()[i -\
    \ 1];\n    }\n  }\n  std::cout << emthrm::knuth_yao_speedup(\n               \
    \    w, std::numeric_limits<long long>::max())[0][n - 1]\n            << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/knuth_yao_speedup.hpp
  isVerificationFile: true
  path: test/dynamic_programming/knuth_yao_speedup.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/knuth_yao_speedup.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp
- /verify/test/dynamic_programming/knuth_yao_speedup.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Knuth\u2013Yao speedup"
---
