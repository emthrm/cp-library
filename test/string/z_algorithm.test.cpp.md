---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/z_algorithm.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    document_title: "\u6587\u5B57\u5217/Z algorithm"
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/z_algorithm.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/Z algorithm\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n\
    \ */\n\n#include <iostream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/string/z_algorithm.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"include/emthrm/string/z_algorithm.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T>\nstd::vector<int> z_algorithm(const T &s) {\n  const int n = s.size();\n\
    \  std::vector<int> res(n, 0);\n  for (int i = 1, j = 0; i < n; ++i) {\n    if\
    \ (i + res[i - j] < j + res[j]) {\n      res[i] = res[i - j];\n    } else {\n\
    \      res[i] = std::max(j + res[j] - i, 0);\n      while (i + res[i] < n && s[i\
    \ + res[i]] == s[res[i]]) ++res[i];\n      j = i;\n    }\n  }\n  res[0] = n;\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 13 \"test/string/z_algorithm.test.cpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  const std::vector<int>\
    \ ans = emthrm::z_algorithm(s);\n  for (int i = 0; std::cmp_less(i, s.length());\
    \ ++i) {\n    std::cout << ans[i] << \" \\n\"[std::cmp_equal(i + 1, s.length())];\n\
    \  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/Z algorithm\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/zalgorithm\n */\n\n#include <iostream>\n\
    #include <string>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/string/z_algorithm.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  const std::vector<int>\
    \ ans = emthrm::z_algorithm(s);\n  for (int i = 0; std::cmp_less(i, s.length());\
    \ ++i) {\n    std::cout << ans[i] << \" \\n\"[std::cmp_equal(i + 1, s.length())];\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/z_algorithm.hpp
  isVerificationFile: true
  path: test/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/string/z_algorithm.test.cpp
- /verify/test/string/z_algorithm.test.cpp.html
title: "\u6587\u5B57\u5217/Z algorithm"
---
