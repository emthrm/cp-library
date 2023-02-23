---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0015
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/bigint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)\n\
    \ */\n#define IGNORE\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0015\"\
    \n\n#include <iostream>\n\n#include \"emthrm/math/bigint.hpp\"\n\nint main() {\n\
    \  int t;\n  std::cin >> t;\n  while (t--) {\n    emthrm::BigInt<> a, b;\n   \
    \ std::cin >> a >> b;\n    emthrm::BigInt<> ans = a + b;\n    if (ans.length()\
    \ > 80) {\n      std::cout << \"overflow\\n\";\n    } else {\n      std::cout\
    \ << ans << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.10.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/bigint.10.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.10.test.cpp
- /verify/test/math/bigint.10.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570 (\u6841\u6570)"
---
