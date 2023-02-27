---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/2
    document_title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
    links:
    - https://yukicoder.me/problems/no/2
  bundledCode: "#line 1 \"test/game/nim.test.cpp\"\n/*\n * @title \u30B2\u30FC\u30E0\
    /\u30CB\u30E0\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/2\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/game/nim.hpp\"\n\n\n\n#line 5 \"include/emthrm/game/nim.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nbool nim(const std::vector<T>&\
    \ a) {\n  long long x = 0;\n  for (const T e : a) x ^= e;\n  return x != 0;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_factorization.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\n  std::vector<std::pair<T, int>> res;\n  for (T i = 2; i * i <= n; ++i)\
    \ {\n    if (n % i == 0) [[unlikely]] {\n      int exponent = 0;\n      for (;\
    \ n % i == 0; n /= i) {\n        ++exponent;\n      }\n      res.emplace_back(i,\
    \ exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n, 1);\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 14 \"test/game/nim.test.cpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<int> a;\n  // GCC 12 adopted P2415.\n\
    \  const std::vector<std::pair<int, int>> pf = emthrm::prime_factorization(n);\n\
    \  const auto ev = pf | std::views::values;\n  // const auto ev = emthrm::prime_factorization(n)\
    \ | std::views::values;\n  std::cout << (emthrm::nim(std::vector<int>(ev.begin(),\
    \ ev.end())) ?\n                \"Alice\\n\" : \"Bob\\n\");\n  return 0;\n}\n"
  code: "/*\n * @title \u30B2\u30FC\u30E0/\u30CB\u30E0\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/2\n */\n\n#include <iostream>\n#include\
    \ <ranges>\n#include <utility>\n#include <vector>\n\n#include \"emthrm/game/nim.hpp\"\
    \n#include \"emthrm/math/prime_factorization.hpp\"\n\nint main() {\n  int n;\n\
    \  std::cin >> n;\n  std::vector<int> a;\n  // GCC 12 adopted P2415.\n  const\
    \ std::vector<std::pair<int, int>> pf = emthrm::prime_factorization(n);\n  const\
    \ auto ev = pf | std::views::values;\n  // const auto ev = emthrm::prime_factorization(n)\
    \ | std::views::values;\n  std::cout << (emthrm::nim(std::vector<int>(ev.begin(),\
    \ ev.end())) ?\n                \"Alice\\n\" : \"Bob\\n\");\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/game/nim.hpp
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: true
  path: test/game/nim.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/game/nim.test.cpp
layout: document
redirect_from:
- /verify/test/game/nim.test.cpp
- /verify/test/game/nim.test.cpp.html
title: "\u30B2\u30FC\u30E0/\u30CB\u30E0"
---
