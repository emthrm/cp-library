---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/divisor.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2932\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"emthrm/math/divisor.hpp\"\n\nint\
    \ main() {\n  long long n;\n  std::cin >> n;\n  std::vector<long long> d = emthrm::divisor(n);\n\
    \  d.pop_back();\n  int ans1 = 0;\n  const int ans2 = d.size();\n  while (!d.empty())\
    \ {\n    ++ans1;\n    std::vector<long long> nxt;\n    for (const long long e\
    \ : d) {\n      if (d.back() % e != 0) nxt.emplace_back(e);\n    }\n    d = nxt;\n\
    \  }\n  std::cout << ans1 << ' ' << ans2 << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/divisor.hpp
  isVerificationFile: true
  path: test/math/divisor.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/divisor.test.cpp
- /verify/test/math/divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
