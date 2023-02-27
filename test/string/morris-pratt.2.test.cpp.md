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
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://codeforces.com/problemset/problem/1138/D
    document_title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u6700\u5C0F\
      \u5468\u671F\uFF09"
    links:
    - https://codeforces.com/problemset/problem/1138/D
  bundledCode: "#line 1 \"test/string/morris-pratt.2.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u6700\u5C0F\u5468\u671F\uFF09\n\
    \ *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://codeforces.com/problemset/problem/1138/D\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <string>\n\n#line 1 \"include/emthrm/string/morris-pratt.hpp\"\n\n\n\n#line\
    \ 5 \"include/emthrm/string/morris-pratt.hpp\"\n#include <vector>\n\nnamespace\
    \ emthrm {\n\nstruct MorrisPratt {\n  std::string s;\n  std::vector<int> border;\n\
    \n  explicit MorrisPratt(const std::string& s) : s(s), border({-1}), j(-1) {\n\
    \    const int n = s.length();\n    for (int i = 0; i < n; ++i) {\n      solve(i);\n\
    \    }\n  }\n\n  void add(const char c) {\n    s += c;\n    solve(s.length() -\
    \ 1);\n  }\n\n  std::vector<int> match(const std::string& t) const {\n    const\
    \ int n = s.length(), m = t.length();\n    std::vector<int> res;\n    for (int\
    \ i = 0, k = 0; i < m; ++i) {\n      while (k >= 0 && t[i] != s[k]) k = border[k];\n\
    \      if (++k == n) res.emplace_back(i - n + 1);\n    }\n    return res;\n  }\n\
    \n  int period(const int idx) const { return idx - border[idx]; }\n\n private:\n\
    \  int j;\n\n  void solve(const int idx) {\n    while (j >= 0 && s[idx] != s[j])\
    \ j = border[j];\n    border.emplace_back(++j);\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 14 \"test/string/morris-pratt.2.test.cpp\"\n\nint main() {\n  constexpr\
    \ int SIGMA = 2;\n  std::string s, t;\n  std::cin >> s >> t;\n  int num[2];\n\
    \  for (int c = 0; c < SIGMA; ++c) {\n    num[c] = std::count(s.begin(), s.end(),\
    \ '0' + c);\n  }\n  const emthrm::MorrisPratt morris_pratt(t);\n  std::string\
    \ ans = \"\";\n  const int period = morris_pratt.period(t.length());\n  for (int\
    \ pos = 0; num[t[pos] - '0'] > 0; pos = (pos + 1) % period) {\n    ans += t[pos];\n\
    \    --num[t[pos] - '0'];\n  }\n  for (int c = 0; c < SIGMA; ++c) {\n    ans +=\
    \ std::string(num[c], '0' + c);\n  }\n  std::cout << ans << '\\n';\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u6587\u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u6700\u5C0F\
    \u5468\u671F\uFF09\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://codeforces.com/problemset/problem/1138/D\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/morris-pratt.hpp\"\
    \n\nint main() {\n  constexpr int SIGMA = 2;\n  std::string s, t;\n  std::cin\
    \ >> s >> t;\n  int num[2];\n  for (int c = 0; c < SIGMA; ++c) {\n    num[c] =\
    \ std::count(s.begin(), s.end(), '0' + c);\n  }\n  const emthrm::MorrisPratt morris_pratt(t);\n\
    \  std::string ans = \"\";\n  const int period = morris_pratt.period(t.length());\n\
    \  for (int pos = 0; num[t[pos] - '0'] > 0; pos = (pos + 1) % period) {\n    ans\
    \ += t[pos];\n    --num[t[pos] - '0'];\n  }\n  for (int c = 0; c < SIGMA; ++c)\
    \ {\n    ans += std::string(num[c], '0' + c);\n  }\n  std::cout << ans << '\\\
    n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/morris-pratt.hpp
  isVerificationFile: true
  path: test/string/morris-pratt.2.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 16:52:23+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/string/morris-pratt.2.test.cpp
layout: document
redirect_from:
- /verify/test/string/morris-pratt.2.test.cpp
- /verify/test/string/morris-pratt.2.test.cpp.html
title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u6700\u5C0F\u5468\u671F\
  \uFF09"
---
