---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    document_title: "\u6587\u5B57\u5217/Manacher"
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/string/manacher.test.cpp\"\n/*\n * @brief \u6587\u5B57\
    \u5217/Manacher\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"string/manacher.hpp\"\n\
    #include <vector>\n\nstruct Manacher {\n  template <typename T>\n  explicit Manacher(const\
    \ T& s) {\n    T str;\n    int n = s.size();\n    str.reserve(n * 2 + 1);\n  \
    \  for (int i = 0; i < n; ++i) {\n      str.push_back(s[i]);\n      str.push_back('$');\n\
    \    }\n    str.pop_back();\n    n = str.size();\n    radius.resize(n);\n    for\
    \ (int i = 0, j = 1; i < n;) {\n      while (i - j >= 0 && i + j < n && str[i\
    \ - j] == str[i + j]) ++j;\n      radius[i] = j;\n      int k = 1;\n      for\
    \ (; i - k >= 0 && i + k < n && k + radius[i - k] < j; ++k) {\n        radius[i\
    \ + k] = radius[i - k];\n      }\n      i += k;\n      j -= k;\n    }\n  }\n\n\
    \  int odd(const int idx) const { return (radius[idx * 2] + 1) / 2; }\n\n  int\
    \ even(const int idx) const { return radius[idx * 2 + 1] / 2; }\n\n  bool is_palindrome(const\
    \ int left, const int right) const {\n    const int mid = (left + right - 1) /\
    \ 2;\n    return ((right - left) & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)\n   \
    \        >= right - left;\n  }\n\n private:\n  std::vector<int> radius;\n};\n\
    #line 10 \"test/string/manacher.test.cpp\"\n\nint main() {\n  std::string s;\n\
    \  std::cin >> s;\n  const int n = s.length();\n  Manacher manacher(s);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cout << (manacher.odd(i) - 1) * 2 + 1;\n\
    \    if (i + 1 == n) {\n      std::cout << '\\n';\n    } else {\n      std::cout\
    \ << ' ' << manacher.even(i) * 2 << ' ';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/Manacher\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../string/manacher.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  const int n = s.length();\n\
    \  Manacher manacher(s);\n  for (int i = 0; i < n; ++i) {\n    std::cout << (manacher.odd(i)\
    \ - 1) * 2 + 1;\n    if (i + 1 == n) {\n      std::cout << '\\n';\n    } else\
    \ {\n      std::cout << ' ' << manacher.even(i) * 2 << ' ';\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - string/manacher.hpp
  isVerificationFile: true
  path: test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/manacher.test.cpp
- /verify/test/string/manacher.test.cpp.html
title: "\u6587\u5B57\u5217/Manacher"
---
