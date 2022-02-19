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
  bundledCode: "#line 1 \"test/string/manacher.test.cpp\"\n/*\r\n * @brief \u6587\u5B57\
    \u5217/Manacher\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"string/manacher.hpp\"\
    \n#include <vector>\r\n\r\nstruct Manacher {\r\n  template <typename T>\r\n  explicit\
    \ Manacher(const T& s) {\r\n    T str;\r\n    int n = s.size();\r\n    str.reserve(n\
    \ * 2 + 1);\r\n    for (int i = 0; i < n; ++i) {\r\n      str.push_back(s[i]);\r\
    \n      str.push_back('$');\r\n    }\r\n    str.pop_back();\r\n    n = str.size();\r\
    \n    radius.resize(n);\r\n    for (int i = 0, j = 1; i < n;) {\r\n      while\
    \ (i - j >= 0 && i + j < n && str[i - j] == str[i + j]) ++j;\r\n      radius[i]\
    \ = j;\r\n      int k = 1;\r\n      for (; i - k >= 0 && i + k < n && k + radius[i\
    \ - k] < j; ++k) {\r\n        radius[i + k] = radius[i - k];\r\n      }\r\n  \
    \    i += k;\r\n      j -= k;\r\n    }\r\n  }\r\n\r\n  int odd(const int idx)\
    \ const { return (radius[idx * 2] + 1) / 2; }\r\n\r\n  int even(const int idx)\
    \ const { return radius[idx * 2 + 1] / 2; }\r\n\r\n  bool is_palindrome(const\
    \ int left, const int right) const {\r\n    const int mid = (left + right - 1)\
    \ / 2;\r\n    return ((right - left) & 1 ? odd(mid) * 2 - 1 : even(mid) * 2)\r\
    \n           >= right - left;\r\n  }\r\n\r\n private:\r\n  std::vector<int> radius;\r\
    \n};\r\n#line 10 \"test/string/manacher.test.cpp\"\n\r\nint main() {\r\n  std::string\
    \ s;\r\n  std::cin >> s;\r\n  const int n = s.length();\r\n  Manacher manacher(s);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cout << (manacher.odd(i) - 1) *\
    \ 2 + 1;\r\n    if (i + 1 == n) {\r\n      std::cout << '\\n';\r\n    } else {\r\
    \n      std::cout << ' ' << manacher.even(i) * 2 << ' ';\r\n    }\r\n  }\r\n \
    \ return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/Manacher\r\n */\r\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/enumerate_palindromes\"\r\n\r\n#include <iostream>\r\
    \n#include <string>\r\n\r\n#include \"../../string/manacher.hpp\"\r\n\r\nint main()\
    \ {\r\n  std::string s;\r\n  std::cin >> s;\r\n  const int n = s.length();\r\n\
    \  Manacher manacher(s);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cout <<\
    \ (manacher.odd(i) - 1) * 2 + 1;\r\n    if (i + 1 == n) {\r\n      std::cout <<\
    \ '\\n';\r\n    } else {\r\n      std::cout << ' ' << manacher.even(i) * 2 <<\
    \ ' ';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/manacher.hpp
  isVerificationFile: true
  path: test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/manacher.test.cpp
- /verify/test/string/manacher.test.cpp.html
title: "\u6587\u5B57\u5217/Manacher"
---
