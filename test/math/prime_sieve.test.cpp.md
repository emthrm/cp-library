---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/843
    document_title: "\u6570\u5B66/prime sieve"
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/math/prime_sieve.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /prime sieve\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/843\n\
    \ */\n\n#include <iostream>\n#include <set>\n#include <vector>\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const\
    \ int n) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/prime_sieve.test.cpp\"\n\
    \nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<int> tmp = emthrm::prime_sieve<true>(n);\n\
    \  const std::set<int> prime(tmp.begin(), tmp.end());\n  int ans = 0;\n  for (const\
    \ int p : prime) {\n    if (p * p - 2 > n) break;\n    if (prime.contains(p *\
    \ p - 2)) ans += (p == 2 ? 1 : 2);\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/prime sieve\n *\n * verification-helper: PROBLEM\
    \ https://yukicoder.me/problems/no/843\n */\n\n#include <iostream>\n#include <set>\n\
    #include <vector>\n\n#include \"emthrm/math/prime_sieve.hpp\"\n\nint main() {\n\
    \  int n;\n  std::cin >> n;\n  const std::vector<int> tmp = emthrm::prime_sieve<true>(n);\n\
    \  const std::set<int> prime(tmp.begin(), tmp.end());\n  int ans = 0;\n  for (const\
    \ int p : prime) {\n    if (p * p - 2 > n) break;\n    if (prime.contains(p *\
    \ p - 2)) ans += (p == 2 ? 1 : 2);\n  }\n  std::cout << ans << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/prime_sieve.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/prime_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/prime_sieve.test.cpp
- /verify/test/math/prime_sieve.test.cpp.html
title: "\u6570\u5B66/prime sieve"
---
