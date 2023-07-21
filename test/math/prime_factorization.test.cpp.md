---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    document_title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/math/prime_factorization.test.cpp\"\n/*\n * @title\
    \ \u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\n */\n\n#include\
    \ <iostream>\n#include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_factorization.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\n  std::vector<std::pair<T, int>> res;\n  for (T i = 2; i * i <= n; ++i)\
    \ {\n    if (n % i == 0) [[unlikely]] {\n      int exponent = 0;\n      for (;\
    \ n % i == 0; n /= i) {\n        ++exponent;\n      }\n      res.emplace_back(i,\
    \ exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n, 1);\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/prime_factorization.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::pair<int,\
    \ int>> ans = emthrm::prime_factorization(n);\n  std::cout << n << \": \";\n \
    \ for (int i = 0; std::cmp_less(i, ans.size()); ++i) {\n    for (int j = 0; j\
    \ < ans[i].second; ++j) {\n      std::cout << ans[i].first\n                <<\
    \ \" \\n\"[std::cmp_equal(i + 1, ans.size())\n                         && j +\
    \ 1 == ans[i].second];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\n */\n\
    \n#include <iostream>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/math/prime_factorization.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::pair<int,\
    \ int>> ans = emthrm::prime_factorization(n);\n  std::cout << n << \": \";\n \
    \ for (int i = 0; std::cmp_less(i, ans.size()); ++i) {\n    for (int j = 0; j\
    \ < ans[i].second; ++j) {\n      std::cout << ans[i].first\n                <<\
    \ \" \\n\"[std::cmp_equal(i + 1, ans.size())\n                         && j +\
    \ 1 == ans[i].second];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: true
  path: test/math/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_factorization.test.cpp
- /verify/test/math/prime_factorization.test.cpp.html
title: "\u6570\u5B66/\u7D20\u56E0\u6570\u5206\u89E3"
---