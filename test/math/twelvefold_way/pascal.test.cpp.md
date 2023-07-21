---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/twelvefold_way/pascal.hpp
    title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62 (Pascal's triangle)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/abc254/tasks/abc254_b
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
      \u4E09\u89D2\u5F62"
    links:
    - https://atcoder.jp/contests/abc254/tasks/abc254_b
  bundledCode: "#line 1 \"test/math/twelvefold_way/pascal.test.cpp\"\n/*\n * @title\
    \ \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\
    \u5F62\n *\n * verification-helper: IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/abc254/tasks/abc254_b\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/math/twelvefold_way/pascal.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/twelvefold_way/pascal.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T>\nstd::vector<std::vector<T>> pascal(const\
    \ int n) {\n  std::vector<std::vector<T>> c(n + 1, std::vector<T>(n + 1, 0));\n\
    \  for (int i = 0; i <= n; ++i) {\n    c[i][0] = 1;\n    for (int j = 1; j <=\
    \ i; ++j) {\n      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];\n    }\n  }\n  return\
    \ c;\n}\n\n}  // namespace emthrm\n\n\n#line 12 \"test/math/twelvefold_way/pascal.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::vector<int>>\
    \ ans = emthrm::pascal<int>(n - 1);\n  for (int i = 0; i < n; ++i) {\n    for\
    \ (int j = 0; j <= i; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j == i];\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
    \u4E09\u89D2\u5F62\n *\n * verification-helper: IGNORE\n * verification-helper:\
    \ PROBLEM https://atcoder.jp/contests/abc254/tasks/abc254_b\n */\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/math/twelvefold_way/pascal.hpp\"\n\nint\
    \ main() {\n  int n;\n  std::cin >> n;\n  const std::vector<std::vector<int>>\
    \ ans = emthrm::pascal<int>(n - 1);\n  for (int i = 0; i < n; ++i) {\n    for\
    \ (int j = 0; j <= i; ++j) {\n      std::cout << ans[i][j] << \" \\n\"[j == i];\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/twelvefold_way/pascal.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/pascal.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/math/twelvefold_way/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/pascal.test.cpp
- /verify/test/math/twelvefold_way/pascal.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\
  \u5F62"
---
