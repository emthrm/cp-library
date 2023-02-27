---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/string/morris-pratt.hpp
    title: "Morris\u2013Pratt algorithm"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/morris-pratt.1.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/Morris\u2013Pratt algorithm (match(t))\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/string/morris-pratt.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/string/morris-pratt.hpp\"\n#include <vector>\n\
    \nnamespace emthrm {\n\nstruct MorrisPratt {\n  std::string s;\n  std::vector<int>\
    \ border;\n\n  explicit MorrisPratt(const std::string& s) : s(s), border({-1}),\
    \ j(-1) {\n    const int n = s.length();\n    for (int i = 0; i < n; ++i) {\n\
    \      solve(i);\n    }\n  }\n\n  void add(const char c) {\n    s += c;\n    solve(s.length()\
    \ - 1);\n  }\n\n  std::vector<int> match(const std::string& t) const {\n    const\
    \ int n = s.length(), m = t.length();\n    std::vector<int> res;\n    for (int\
    \ i = 0, k = 0; i < m; ++i) {\n      while (k >= 0 && t[i] != s[k]) k = border[k];\n\
    \      if (++k == n) res.emplace_back(i - n + 1);\n    }\n    return res;\n  }\n\
    \n  int period(const int idx) const { return idx - border[idx]; }\n\n private:\n\
    \  int j;\n\n  void solve(const int idx) {\n    while (j >= 0 && s[idx] != s[j])\
    \ j = border[j];\n    border.emplace_back(++j);\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 11 \"test/string/morris-pratt.1.test.cpp\"\n\nint main() {\n  std::string\
    \ t, p;\n  std::cin >> t >> p;\n  for (const int ans : emthrm::MorrisPratt(p).match(t))\
    \ {\n    std::cout << ans << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))\n\
    \ *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/morris-pratt.hpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::MorrisPratt(p).match(t)) {\n    std::cout << ans << '\\n';\n \
    \ }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/morris-pratt.hpp
  isVerificationFile: true
  path: test/string/morris-pratt.1.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/morris-pratt.1.test.cpp
layout: document
redirect_from:
- /verify/test/string/morris-pratt.1.test.cpp
- /verify/test/string/morris-pratt.1.test.cpp.html
title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm (match(t))"
---
