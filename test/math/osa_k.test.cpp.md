---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/osa_k.hpp
    title: "osa_k \u6CD5"
  - icon: ':question:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_e
    document_title: "\u6570\u5B66/osa_k \u6CD5"
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_e
  bundledCode: "#line 1 \"test/math/osa_k.test.cpp\"\n/*\n * @title \u6570\u5B66/osa_k\
    \ \u6CD5\n *\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc177/tasks/abc177_e\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <ranges>\n#include\
    \ <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/math/osa_k.hpp\"\n\n\
    \n\n#line 6 \"include/emthrm/math/osa_k.hpp\"\n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const\
    \ int n) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/osa_k.hpp\"\n\n\
    namespace emthrm {\n\nstruct OsaK {\n  const std::vector<int> smallest_prime_factor;\n\
    \n  explicit OsaK(const int n) : smallest_prime_factor(prime_sieve<false>(n))\
    \ {}\n\n  std::vector<std::pair<int, int>> query(int n) const {\n    std::vector<std::pair<int,\
    \ int>> res;\n    while (n > 1) {\n      const int prime = smallest_prime_factor[n];\n\
    \      int exponent = 0;\n      for (; smallest_prime_factor[n] == prime; n /=\
    \ prime) {\n        ++exponent;\n      }\n      res.emplace_back(prime, exponent);\n\
    \    }\n    return res;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 14 \"test/math/osa_k.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const int max_a = *std::max_element(a.begin(),\
    \ a.end());\n  const emthrm::OsaK osa_k(max_a);\n  std::vector<int> prime_factor(max_a\
    \ + 1, 0);\n  for (const int a_i : a) {\n    // GCC 12 adopted P2415.\n    const\
    \ std::vector<std::pair<int, int>> pf = osa_k.query(a_i);\n    for (const int\
    \ prime : pf\n    // for (const int prime : osa_k.query(a_i)\n               \
    \          | std::views::transform(&std::pair<int, int>::first)) {\n      ++prime_factor[prime];\n\
    \    }\n  }\n  const int maximum =\n      *std::max_element(prime_factor.begin(),\
    \ prime_factor.end());\n  if (maximum <= 1) {\n    std::cout << \"pairwise coprime\\\
    n\";\n  } else if (maximum == n) {\n    std::cout << \"not coprime\\n\";\n  }\
    \ else {\n    std::cout << \"setwise coprime\\n\";\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/osa_k \u6CD5\n *\n * verification-helper: PROBLEM\
    \ https://atcoder.jp/contests/abc177/tasks/abc177_e\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/math/osa_k.hpp\"\n\nint main() {\n  int n;\n  std::cin >>\
    \ n;\n  std::vector<int> a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> a[i];\n  }\n  const int max_a = *std::max_element(a.begin(), a.end());\n\
    \  const emthrm::OsaK osa_k(max_a);\n  std::vector<int> prime_factor(max_a + 1,\
    \ 0);\n  for (const int a_i : a) {\n    // GCC 12 adopted P2415.\n    const std::vector<std::pair<int,\
    \ int>> pf = osa_k.query(a_i);\n    for (const int prime : pf\n    // for (const\
    \ int prime : osa_k.query(a_i)\n                         | std::views::transform(&std::pair<int,\
    \ int>::first)) {\n      ++prime_factor[prime];\n    }\n  }\n  const int maximum\
    \ =\n      *std::max_element(prime_factor.begin(), prime_factor.end());\n  if\
    \ (maximum <= 1) {\n    std::cout << \"pairwise coprime\\n\";\n  } else if (maximum\
    \ == n) {\n    std::cout << \"not coprime\\n\";\n  } else {\n    std::cout <<\
    \ \"setwise coprime\\n\";\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/osa_k.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/osa_k.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/math/osa_k.test.cpp
- /verify/test/math/osa_k.test.cpp.html
title: "\u6570\u5B66/osa_k \u6CD5"
---
