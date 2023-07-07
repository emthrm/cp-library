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
    PROBLEM: https://atcoder.jp/contests/abc143/tasks/abc143_c
    document_title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
      \u7E2E"
    links:
    - https://atcoder.jp/contests/abc143/tasks/abc143_c
  bundledCode: "#line 1 \"test/string/run_length_encoding.test.cpp\"\n/*\n * @title\
    \ \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\n *\n *\
    \ verification-helper: PROBLEM https://atcoder.jp/contests/abc143/tasks/abc143_c\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/string/run_length_encoding.hpp\"\
    \n\n\n\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T>\nrequires requires { typename T::value_type; }\nstd::vector<std::pair<typename\
    \ T::value_type, int>> run_length_encoding(\n    const T& s) {\n  const int n\
    \ = s.size();\n  std::vector<std::pair<typename T::value_type, int>> res;\n  if\
    \ (n == 0) [[unlikely]] return res;\n  typename T::value_type ch = s.front();\n\
    \  int num = 1;\n  for (int i = 1; i < n; ++i) {\n    if (s[i] != ch) {\n    \
    \  res.emplace_back(ch, num);\n      num = 0;\n    }\n    ch = s[i];\n    ++num;\n\
    \  }\n  res.emplace_back(ch, num);\n  return res;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 11 \"test/string/run_length_encoding.test.cpp\"\n\nint main() {\n  int\
    \ n;\n  std::cin >> n;\n  std::string s;\n  std::cin >> s;\n  std::cout << emthrm::run_length_encoding(s).size()\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\
    \u7E2E\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc143/tasks/abc143_c\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/run_length_encoding.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::string s;\n  std::cin >>\
    \ s;\n  std::cout << emthrm::run_length_encoding(s).size() << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/string/run_length_encoding.hpp
  isVerificationFile: true
  path: test/string/run_length_encoding.test.cpp
  requiredBy: []
  timestamp: '2023-07-07 02:42:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/run_length_encoding.test.cpp
layout: document
redirect_from:
- /verify/test/string/run_length_encoding.test.cpp
- /verify/test/string/run_length_encoding.test.cpp.html
title: "\u6587\u5B57\u5217/\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E"
---
