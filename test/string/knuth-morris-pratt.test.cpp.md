---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/knuth-morris-pratt.hpp
    title: "Knuth\u2013Morris\u2013Pratt algorithm"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/Knuth\u2013Morris\u2013Pratt algorithm"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/knuth-morris-pratt.test.cpp\"\n/*\n * @title\
    \ \u6587\u5B57\u5217/Knuth\u2013Morris\u2013Pratt algorithm\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/string/knuth-morris-pratt.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/string/knuth-morris-pratt.hpp\"\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T = std::string>\nstruct KnuthMorrisPratt\
    \ {\n  std::vector<int> border;\n\n  explicit KnuthMorrisPratt(const T& s) : s(s)\
    \ {\n    const int n = s.size();\n    border.assign(n + 1, -1);\n    for (int\
    \ i = 0, j = -1; i < n; ++i) {\n      while (j >= 0 && s[i] != s[j]) j = border[j];\n\
    \      ++j;\n      border[i + 1] = (i + 1 < n && s[i + 1] == s[j] ? border[j]\
    \ : j);\n    }\n  }\n\n  std::vector<int> match(const T& t) const {\n    const\
    \ int n = s.size(), m = t.size();\n    std::vector<int> res;\n    for (int i =\
    \ 0, k = 0; i < m; ++i) {\n      while (k >= 0 && t[i] != s[k]) k = border[k];\n\
    \      if (++k == n) res.emplace_back(i - n + 1);\n    }\n    return res;\n  }\n\
    \n private:\n  const T s;\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"test/string/knuth-morris-pratt.test.cpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::KnuthMorrisPratt<>(p).match(t)) {\n    std::cout << ans << '\\\
    n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/Knuth\u2013Morris\u2013Pratt algorithm\n\
    \ *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/knuth-morris-pratt.hpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::KnuthMorrisPratt<>(p).match(t)) {\n    std::cout << ans << '\\\
    n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/knuth-morris-pratt.hpp
  isVerificationFile: true
  path: test/string/knuth-morris-pratt.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/knuth-morris-pratt.test.cpp
layout: document
redirect_from:
- /verify/test/string/knuth-morris-pratt.test.cpp
- /verify/test/string/knuth-morris-pratt.test.cpp.html
title: "\u6587\u5B57\u5217/Knuth\u2013Morris\u2013Pratt algorithm"
---
