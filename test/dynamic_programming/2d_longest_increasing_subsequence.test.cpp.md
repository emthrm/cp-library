---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dynamic_programming/2d_longest_increasing_subsequence.hpp
    title: "2\u6B21\u5143\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
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
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u6700\u9577\u5897\
      \u52A0\u90E8\u5206\u5217"
    links:
    - https://atcoder.jp/contests/abc038/tasks/abc038_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dynamic_programming/2d_longest_increasing_subsequence.hpp: line 6: #pragma once\
    \ found in a non-first line\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217\r\n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc038/tasks/abc038_d\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n#include\
    \ \"../../dynamic_programming/2d_longest_increasing_subsequence.hpp\"\r\n\r\n\
    int main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::pair<int, int>>\
    \ wh(n);\r\n  for (int i = 0; i < n; ++i) std::cin >> wh[i].first >> wh[i].second;\r\
    \n  std::cout << longest_increasing_subsequence_2d(wh) << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  dependsOn:
  - dynamic_programming/2d_longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/dynamic_programming/2d_longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dynamic_programming/2d_longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/2d_longest_increasing_subsequence.test.cpp
- /verify/test/dynamic_programming/2d_longest_increasing_subsequence.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143\u6700\u9577\u5897\u52A0\u90E8\
  \u5206\u5217"
---
