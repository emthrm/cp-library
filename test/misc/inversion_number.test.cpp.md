---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
  - icon: ':x:'
    path: misc/inversion_number.hpp
    title: "\u8EE2\u5012\u6570 (inversion number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    document_title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/fenwick_tree.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u8EE2\u5012\u6570\r\n */\r\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\r\n\r\
    \n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../misc/inversion_number.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  std::cout\
    \ << inversion_number(a) << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/inversion_number.hpp
  - data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/misc/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 15:47:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/test/misc/inversion_number.test.cpp
- /verify/test/misc/inversion_number.test.cpp.html
title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
---
