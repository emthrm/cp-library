---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/run_length_encoding.hpp
    title: "\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E (run length encoding)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc143/tasks/abc143_c
    document_title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E"
    links:
    - https://atcoder.jp/contests/abc143/tasks/abc143_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/run_length_encoding.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E\n */\n#define PROBLEM \"https://atcoder.jp/contests/abc143/tasks/abc143_c\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/run_length_encoding.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::string s;\n  std::cin >>\
    \ s;\n  std::cout << emthrm::run_length_encoding(s).size() << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/string/run_length_encoding.hpp
  isVerificationFile: true
  path: test/string/run_length_encoding.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/run_length_encoding.test.cpp
layout: document
redirect_from:
- /verify/test/string/run_length_encoding.test.cpp
- /verify/test/string/run_length_encoding.test.cpp.html
title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
