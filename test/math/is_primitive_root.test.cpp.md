---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839 (primitive root) \u5224\u5B9A"
  - icon: ':question:'
    path: include/emthrm/math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 / \u4E8C\u5206\u7D2F\u4E57\u6CD5\
      \ / \u30D0\u30A4\u30CA\u30EA\u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/1409
    document_title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
    links:
    - https://yukicoder.me/problems/no/1409
  bundledCode: "#line 1 \"test/math/is_primitive_root.test.cpp\"\n/*\n * @title \u6570\
    \u5B66/\u539F\u59CB\u6839\u5224\u5B9A\n *\n * verification-helper: PROBLEM https://yukicoder.me/problems/no/1409\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include\
    \ <random>\n#include <vector>\n\n#line 1 \"include/emthrm/math/is_primitive_root.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/is_primitive_root.hpp\"\n#include <map>\n\
    #line 7 \"include/emthrm/math/is_primitive_root.hpp\"\n#include <ranges>\n#include\
    \ <utility>\n#line 10 \"include/emthrm/math/is_primitive_root.hpp\"\n\n#line 1\
    \ \"include/emthrm/math/euler_phi.hpp\"\n\n\n\n#include <cassert>\n\nnamespace\
    \ emthrm {\n\nlong long euler_phi(long long n) {\n  assert(n >= 1);\n  long long\
    \ res = n;\n  for (long long i = 2; i * i <= n; ++i) {\n    if (n % i == 0) [[unlikely]]\
    \ {\n      res -= res / i;\n      while (n % i == 0) n /= i;\n    }\n  }\n  return\
    \ n > 1 ? res - res / n : res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/mod_pow.hpp\"\
    \n\n\n\nnamespace emthrm {\n\nlong long mod_pow(long long x, long long n, const\
    \ int m) {\n  if ((x %= m) < 0) x += m;\n  long long res = 1;\n  for (; n > 0;\
    \ n >>= 1) {\n    if (n & 1) res = (res * x) % m;\n    x = (x * x) % m;\n  }\n\
    \  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/math/prime_factorization.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> prime_factorization(T\
    \ n) {\n  std::vector<std::pair<T, int>> res;\n  for (T i = 2; i * i <= n; ++i)\
    \ {\n    if (n % i == 0) [[unlikely]] {\n      int exponent = 0;\n      for (;\
    \ n % i == 0; n /= i) {\n        ++exponent;\n      }\n      res.emplace_back(i,\
    \ exponent);\n    }\n  }\n  if (n > 1) res.emplace_back(n, 1);\n  return res;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 14 \"include/emthrm/math/is_primitive_root.hpp\"\
    \n\nnamespace emthrm {\n\nbool is_primitive_root(long long root, const int m)\
    \ {\n  if ((root %= m) < 0) root += m;\n  if (std::gcd(root, m) > 1) return false;\n\
    \  static std::map<int, int> phi;\n  if (!phi.contains(m)) phi[m] = euler_phi(m);\n\
    \  const int phi_m = phi[m];\n  static std::map<int, std::vector<int>> primes;\n\
    \  if (!primes.contains(phi_m)) {\n    // GCC 12 adopted P2415.\n    const std::vector<std::pair<int,\
    \ int>> pf = prime_factorization(phi_m);\n    const auto ev = pf | std::views::keys;\n\
    \    // const auto ev = prime_factorization(phi_m) | std::views::keys;\n    primes[phi_m]\
    \ = std::vector<int>(ev.begin(), ev.end());\n  }\n  return std::none_of(primes[phi_m].begin(),\
    \ primes[phi_m].end(),\n                      [root, phi_m, m](const int p) ->\
    \ bool {\n                        return mod_pow(root, phi_m / p, m) == 1;\n \
    \                     });\n}\n\n}  // namespace emthrm\n\n\n#line 15 \"test/math/is_primitive_root.test.cpp\"\
    \n\nint main() {\n  int t;\n  std::cin >> t;\n  std::mt19937_64 engine(std::random_device\
    \ {} ());\n  while (t--) {\n    int v, x;\n    std::cin >> v >> x;\n    const\
    \ int p = v * x + 1;\n    std::uniform_int_distribution<int> dist(1, p - 1);\n\
    \    int root = 0;\n    do {\n      root = dist(engine);\n    } while (!emthrm::is_primitive_root(root,\
    \ p));\n    std::vector<int> a(x, emthrm::mod_pow(root, v, p));\n    a.front()\
    \ = 1;\n    std::partial_sum(a.begin(), a.end(), a.begin(),\n                \
    \     [p](const int l, const int r) -> int {\n                       return static_cast<long\
    \ long>(l) * r % p;\n                     });\n    std::sort(a.begin(), a.end());\n\
    \    for (int i = 0; i < x; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1\
    \ == x];\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/1409\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <numeric>\n#include <random>\n#include <vector>\n\
    \n#include \"emthrm/math/is_primitive_root.hpp\"\n#include \"emthrm/math/mod_pow.hpp\"\
    \n\nint main() {\n  int t;\n  std::cin >> t;\n  std::mt19937_64 engine(std::random_device\
    \ {} ());\n  while (t--) {\n    int v, x;\n    std::cin >> v >> x;\n    const\
    \ int p = v * x + 1;\n    std::uniform_int_distribution<int> dist(1, p - 1);\n\
    \    int root = 0;\n    do {\n      root = dist(engine);\n    } while (!emthrm::is_primitive_root(root,\
    \ p));\n    std::vector<int> a(x, emthrm::mod_pow(root, v, p));\n    a.front()\
    \ = 1;\n    std::partial_sum(a.begin(), a.end(), a.begin(),\n                \
    \     [p](const int l, const int r) -> int {\n                       return static_cast<long\
    \ long>(l) * r % p;\n                     });\n    std::sort(a.begin(), a.end());\n\
    \    for (int i = 0; i < x; ++i) {\n      std::cout << a[i] << \" \\n\"[i + 1\
    \ == x];\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/is_primitive_root.hpp
  - include/emthrm/math/euler_phi.hpp
  - include/emthrm/math/mod_pow.hpp
  - include/emthrm/math/prime_factorization.hpp
  isVerificationFile: true
  path: test/math/is_primitive_root.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/is_primitive_root.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_primitive_root.test.cpp
- /verify/test/math/is_primitive_root.test.cpp.html
title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
---
