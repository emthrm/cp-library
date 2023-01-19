---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/enumerate_quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc230/tasks/abc230_e
    document_title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc230/tasks/abc230_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/enumerate_quotients.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5546\u306E\u5217\u6319\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc230/tasks/abc230_e\"\n\n#include <iostream>\n\
    #if __cplusplus < 201703L\n#include <tuple>\n#endif\n\n#include \"emthrm/math/enumerate_quotients.hpp\"\
    \n\nint main() {\n  long long n;\n  std::cin >> n;\n  long long ans = 0;\n#if\
    \ __cplusplus >= 201703L\n  for (const auto& [l, r, q] : emthrm::enumerate_quotients(n))\
    \ {\n    ans += q * (r - l);\n  }\n#else\n  for (const std::tuple<long long, long\
    \ long, long long>& lrq\n       : emthrm::enumerate_quotients(n)) {\n    long\
    \ long l, r, q;\n    std::tie(l, r, q) = lrq;\n    ans += q * (r - l);\n  }\n\
    #endif\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 03:45:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_quotients.test.cpp
- /verify/test/math/enumerate_quotients.test.cpp.html
title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
---
