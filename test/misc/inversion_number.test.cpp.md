---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree
  - icon: ':x:'
    path: include/emthrm/misc/inversion_number.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/misc/inversion_number.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/\u8EE2\u5012\u6570\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/misc/inversion_number.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::cout << emthrm::inversion_number(a)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/misc/inversion_number.hpp
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/misc/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/test/misc/inversion_number.test.cpp
- /verify/test/misc/inversion_number.test.cpp.html
title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
---
