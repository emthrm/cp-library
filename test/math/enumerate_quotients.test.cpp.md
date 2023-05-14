---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/enumerate_quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    document_title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/math/enumerate_quotients.test.cpp\"\n/*\n * @title\
    \ \u6570\u5B66/\u5546\u306E\u5217\u6319\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients\n\
    \ */\n\n#include <iostream>\n#include <ranges>\n\n#line 1 \"include/emthrm/math/enumerate_quotients.hpp\"\
    \n\n\n\n#include <tuple>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T>\nstd::vector<std::tuple<T, T, T>> enumerate_quotients(const T n)\
    \ {\n  std::vector<std::tuple<T, T, T>> quotients;\n  for (T l = 1; l <= n;) {\n\
    \    const T quotient = n / l, r = n / quotient + 1;\n    quotients.emplace_back(l,\
    \ r, quotient);\n    l = r;\n  }\n  return quotients;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 11 \"test/math/enumerate_quotients.test.cpp\"\n\nint main() {\n  long\
    \ long n;\n  std::cin >> n;\n  const auto a = emthrm::enumerate_quotients(n)\n\
    \               | std::views::elements<2>\n               | std::views::reverse;\n\
    \  const int k = a.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i <\
    \ k; ++i) {\n    std::cout << a[i] << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n\
    }\n"
  code: "/*\n * @title \u6570\u5B66/\u5546\u306E\u5217\u6319\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/enumerate_quotients\n */\n\n#include\
    \ <iostream>\n#include <ranges>\n\n#include \"emthrm/math/enumerate_quotients.hpp\"\
    \n\nint main() {\n  long long n;\n  std::cin >> n;\n  const auto a = emthrm::enumerate_quotients(n)\n\
    \               | std::views::elements<2>\n               | std::views::reverse;\n\
    \  const int k = a.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i <\
    \ k; ++i) {\n    std::cout << a[i] << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/math/enumerate_quotients.hpp
  isVerificationFile: true
  path: test/math/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2023-05-02 09:31:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerate_quotients.test.cpp
- /verify/test/math/enumerate_quotients.test.cpp.html
title: "\u6570\u5B66/\u5546\u306E\u5217\u6319"
---
