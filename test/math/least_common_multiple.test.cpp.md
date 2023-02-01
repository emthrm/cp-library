---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/least_common_multiple.hpp
    title: "\u6700\u5C0F\u516C\u500D\u6570 (least common multiple)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
    document_title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ test/math/least_common_multiple.test.cpp: line 11: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "/*\n * @brief \u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C\"\n\n#include\
    \ <iostream>\n\n#if __cplusplus >= 201703L\n# include <numeric>\n#else\n# include\
    \ \"emthrm/math/least_common_multiple.hpp\"\n#endif  // __cplusplus >= 201703L\n\
    \nint main() {\n  int n;\n  std::cin >> n;\n  int ans = 1;\n  while (n--) {\n\
    \    int a;\n    std::cin >> a;\n#if __cplusplus >= 201703L\n    ans = std::lcm(ans,\
    \ a);\n#else\n    ans = emthrm::__lcm(ans, a);\n#endif  // __cplusplus >= 201703L\n\
    \  }\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/least_common_multiple.hpp
  isVerificationFile: true
  path: test/math/least_common_multiple.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/least_common_multiple.test.cpp
layout: document
redirect_from:
- /verify/test/math/least_common_multiple.test.cpp
- /verify/test/math/least_common_multiple.test.cpp.html
title: "\u6570\u5B66/\u6700\u5C0F\u516C\u500D\u6570"
---
