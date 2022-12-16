---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/aho-corasick.hpp
    title: "Aho\u2013Corasick algorithm"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/trie.hpp
    title: "\u30C8\u30E9\u30A4\u6728 (trie)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    document_title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/aho-corasick.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/Aho\u2013Corasick algorithm\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include <iostream>\n#include\
    \ <string>\n\n#include \"emthrm/string/aho-corasick.hpp\"\n\nint main() {\n  std::string\
    \ s;\n  std::cin >> s;\n  emthrm::AhoCorasick<> aho([](const char c) -> int {\
    \ return c - 'A'; });\n  int m;\n  std::cin >> m;\n  for (int i = 0; i < m; ++i)\
    \ {\n    std::string p;\n    std::cin >> p;\n    aho.add(p, i);\n  }\n  aho.build();\n\
    \  std::cout << aho.match(s) << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/aho-corasick.hpp
  - include/emthrm/string/trie.hpp
  isVerificationFile: true
  path: test/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho-corasick.test.cpp
- /verify/test/string/aho-corasick.test.cpp.html
title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
---
