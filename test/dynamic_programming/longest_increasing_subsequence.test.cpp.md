---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/longest_increasing_subsequence.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (longest increasing subsequence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217"
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dynamic_programming/longest_increasing_subsequence.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../dynamic_programming/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::vector<int> ans;\n\
    \  int i = 0;\n  for (const int lis_i : longest_increasing_subsequence(a)) {\n\
    \    while (a[i] != lis_i) ++i;\n    ans.emplace_back(i++);\n  }\n  const int\
    \ k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i) {\n\
    \    std::cout << ans[i] << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n}\n"
  dependsOn:
  - dynamic_programming/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/dynamic_programming/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2022-08-08 06:23:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/longest_increasing_subsequence.test.cpp
- /verify/test/dynamic_programming/longest_increasing_subsequence.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
