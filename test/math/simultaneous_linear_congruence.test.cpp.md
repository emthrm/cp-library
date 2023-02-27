---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/simultaneous_linear_congruence.hpp
    title: "\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F (simultaneous linear congruence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/186
    document_title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "#line 1 \"test/math/simultaneous_linear_congruence.test.cpp\"\n/*\n\
    \ * @title \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/186\n */\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/math/simultaneous_linear_congruence.hpp\"\
    \n\n\n\n#include <numeric>\n#include <utility>\n#line 7 \"include/emthrm/math/simultaneous_linear_congruence.hpp\"\
    \n\n#line 1 \"include/emthrm/math/mod_inv.hpp\"\n\n\n\n#line 6 \"include/emthrm/math/mod_inv.hpp\"\
    \n\nnamespace emthrm {\n\nlong long mod_inv(long long a, const int m) {\n  if\
    \ ((a %= m) < 0) a += m;\n  if (std::gcd(a, m) != 1) return -1;\n  long long x\
    \ = 1;\n  for (long long b = m, u = 0; b > 0;) {\n    const long long q = a /\
    \ b;\n    std::swap(a -= q * b, b);\n    std::swap(x -= q * u, u);\n  }\n  x %=\
    \ m;\n  return x < 0 ? x + m : x;\n}\n\n}  // namespace emthrm\n\n\n#line 9 \"\
    include/emthrm/math/simultaneous_linear_congruence.hpp\"\n\nnamespace emthrm {\n\
    \ntemplate <typename T>\nstd::pair<T, T> simultaneous_linear_congruence(const\
    \ std::vector<T>& a,\n                                               const std::vector<T>&\
    \ b,\n                                               const std::vector<T>& m)\
    \ {\n  const int n = a.size();\n  T x = 0, md = 1;\n  for (int i = 0; i < n; ++i)\
    \ {\n    const T p = md * a[i], q = -x * a[i] + b[i], g = std::gcd(p, m[i]);\n\
    \    if (q % g != 0) return {0, -1};\n    const T m_i = m[i] / g;\n    x += md\
    \ * (q / g * mod_inv(p / g, m_i) % m_i);\n    md *= m_i;\n  }\n  return {x < 0\
    \ ? x + md : x, md};\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"test/math/simultaneous_linear_congruence.test.cpp\"\
    \n\nint main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n  const\
    \ auto [ans, mod] = emthrm::simultaneous_linear_congruence(\n      std::vector<long\
    \ long>(N, 1), x, y);\n  if (mod == 0) {\n    std::cout << \"-1\\n\";\n  } else\
    \ {\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F\n *\n\
    \ * verification-helper: PROBLEM https://yukicoder.me/problems/no/186\n */\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/math/simultaneous_linear_congruence.hpp\"\
    \n\nint main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n\
    \  for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n  const\
    \ auto [ans, mod] = emthrm::simultaneous_linear_congruence(\n      std::vector<long\
    \ long>(N, 1), x, y);\n  if (mod == 0) {\n    std::cout << \"-1\\n\";\n  } else\
    \ {\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/simultaneous_linear_congruence.hpp
  - include/emthrm/math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/simultaneous_linear_congruence.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/simultaneous_linear_congruence.test.cpp
layout: document
redirect_from:
- /verify/test/math/simultaneous_linear_congruence.test.cpp
- /verify/test/math/simultaneous_linear_congruence.test.cpp.html
title: "\u6570\u5B66/\u9023\u7ACB\u7DDA\u5F62\u5408\u540C\u5F0F"
---
