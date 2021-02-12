---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: dp/lis/lis_rmq.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 RMQ \u7248"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/LIS/\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217 RMQ \u7248"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ dp/lis/lis_rmq.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/LIS/\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217 RMQ \u7248\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../dp/lis/lis_rmq.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\
    \n  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  std::cout << lis_rmq(a)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/lis/lis_rmq.hpp
  - data_structure/segment_tree/segment_tree.hpp
  isVerificationFile: true
  path: test/dp/lis/lis_rmq.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dp/lis/lis_rmq.test.cpp
layout: document
redirect_from:
- /verify/test/dp/lis/lis_rmq.test.cpp
- /verify/test/dp/lis/lis_rmq.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/LIS/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
  \ RMQ \u7248"
---
