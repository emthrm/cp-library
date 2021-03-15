---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dp/2d_lis.hpp
    title: "2\u6B21\u5143 LIS"
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
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143 LIS"
    links:
    - https://atcoder.jp/contests/abc038/tasks/abc038_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dp/2d_lis.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143 LIS\r\n */\r\
    \n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/abc038/tasks/abc038_d\"\
    \r\n\r\n#include <iostream>\r\n#include <utility>\r\n#include <vector>\r\n#include\
    \ \"../../dp/2d_lis.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\
    \n  std::vector<std::pair<int, int>> wh(n);\r\n  for (int i = 0; i < n; ++i) std::cin\
    \ >> wh[i].first >> wh[i].second;\r\n  std::cout << lis_2d(wh) << '\\n';\r\n \
    \ return 0;\r\n}\r\n"
  dependsOn:
  - dp/2d_lis.hpp
  isVerificationFile: true
  path: test/dp/2d_lis.test.cpp
  requiredBy: []
  timestamp: '2021-03-04 19:21:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/dp/2d_lis.test.cpp
layout: document
redirect_from:
- /verify/test/dp/2d_lis.test.cpp
- /verify/test/dp/2d_lis.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/2\u6B21\u5143 LIS"
---
