---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/string/rolling_hash.hpp
    title: rolling hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/rolling hash"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/rolling_hash.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/rolling hash\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <set>\n#include <string>\n\n#include \"emthrm/string/rolling_hash.hpp\"\
    \n\nint main() {\n  int n;\n  std::string s;\n  std::cin >> n >> s;\n  emthrm::RollingHash<>\
    \ rolling_hash(s);\n  for (int len = n - 1; len >= 1; --len) {\n    std::set<std::int64_t>\
    \ hashes;\n    for (int i = len; i + len <= n; ++i) {\n      hashes.emplace(rolling_hash.get(i\
    \ - len, i));\n      if (hashes.count(rolling_hash.get(i, i + len))) {\n     \
    \   std::cout << len << '\\n';\n        return 0;\n      }\n    }\n  }\n  std::cout\
    \ << 0 << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/rolling_hash.hpp
  isVerificationFile: true
  path: test/string/rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2023-02-01 21:06:01+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash.test.cpp
- /verify/test/string/rolling_hash.test.cpp.html
title: "\u6587\u5B57\u5217/rolling hash"
---
