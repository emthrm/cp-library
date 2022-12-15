---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/string/split.hpp
    title: "\u6587\u5B57\u5217\u306E\u5206\u5272"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
    links:
    - https://atcoder.jp/contests/abc033/tasks/abc033_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/split.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272\n */\n\
    #define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc033/tasks/abc033_c\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"emthrm/string/split.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  int ans = 0;\n  for (const\
    \ std::string& terms : emthrm::split(s, \"+\")) {\n    bool is_0 = false;\n  \
    \  for (int i = 0; i < static_cast<int>(terms.length()); i += 2) {\n      is_0\
    \ |= terms[i] == '0';\n    }\n    ans += !is_0;\n  }\n  std::cout << ans << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/split.hpp
  isVerificationFile: true
  path: test/string/split.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/split.test.cpp
layout: document
redirect_from:
- /verify/test/string/split.test.cpp
- /verify/test/string/split.test.cpp.html
title: "\u6587\u5B57\u5217/\u6587\u5B57\u5217\u306E\u5206\u5272"
---
