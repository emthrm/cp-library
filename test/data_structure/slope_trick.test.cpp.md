---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/slope_trick.hpp
    title: slope trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
    links:
    - https://atcoder.jp/contests/arc123/tasks/arc123_d
  bundledCode: "#line 1 \"test/data_structure/slope_trick.test.cpp\"\n/*\r\n * @brief\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/slope trick\r\n */\r\n#define IGNORE\r\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\r\n\r\n#include\
    \ <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"data_structure/slope_trick.hpp\"\
    \n#include <cassert>\r\n#include <functional>\r\n#include <numeric>\r\n#include\
    \ <queue>\r\n#include <utility>\r\n#line 8 \"data_structure/slope_trick.hpp\"\n\
    \r\ntemplate <typename T>\r\nstruct SlopeTrick {\r\n  const T inf;\r\n\r\n  SlopeTrick(T\
    \ min_f = 0, const T inf = std::numeric_limits<T>::max()) : min_f(min_f), inf(inf)\
    \ {}\r\n\r\n  T min() const { return min_f; }\r\n\r\n  std::pair<T, T> argmin()\
    \ const { return {top_l(), top_r()}; }\r\n\r\n  template <typename U>\r\n  U f(U\
    \ x) {\r\n    U f_x = min_f;\r\n    std::vector<T> tmp;\r\n    while (top_l()\
    \ > x) {\r\n      T t = top_l();\r\n      f_x += t - x;\r\n      tmp.emplace_back(t);\r\
    \n      l.pop();\r\n    }\r\n    while (!tmp.empty()) {\r\n      emplace_l(tmp.back());\r\
    \n      tmp.pop_back();\r\n    }\r\n    while (top_r() < x) {\r\n      T t = top_r();\r\
    \n      f_x += x - t;\r\n      tmp.emplace_back(t);\r\n      r.pop();\r\n    }\r\
    \n    while (!tmp.empty()) {\r\n      emplace_r(tmp.back());\r\n      tmp.pop_back();\r\
    \n    }\r\n    return f_x;\r\n  }\r\n\r\n  void constant_function(T c) { min_f\
    \ += c; }\r\n\r\n  void x_minus_a(T a) {\r\n    T t = top_l();\r\n    if (t <=\
    \ a) {\r\n      emplace_r(a);\r\n    } else {\r\n      min_f += t - a;\r\n   \
    \   emplace_l(a);\r\n      l.pop();\r\n      emplace_r(t);\r\n    }\r\n  }\r\n\
    \r\n  void a_minus_x(T a) {\r\n    T t = top_r();\r\n    if (a <= t) {\r\n   \
    \   emplace_l(a);\r\n    } else {\r\n      min_f += a - t;\r\n      emplace_r(a);\r\
    \n      r.pop();\r\n      emplace_l(t);\r\n    }\r\n  }\r\n\r\n  void abs_x_minus_a(T\
    \ a) {\r\n    x_minus_a(a);\r\n    a_minus_x(a);\r\n  }\r\n\r\n  void cumulative_min()\
    \ {\r\n    while (!r.empty()) r.pop();\r\n    add_r = 0;\r\n  }\r\n\r\n  void\
    \ rcumulative_min() {\r\n    while (!l.empty()) l.pop();\r\n    add_l = 0;\r\n\
    \  }\r\n\r\n  void translate(T a) { sliding_window_minimum(a, a); }\r\n\r\n  void\
    \ sliding_window_minimum(T a, T b) {\r\n    assert(a <= b);\r\n    add_l += a;\r\
    \n    add_r += b;\r\n  }\r\n\r\nprivate:\r\n  T add_l = 0, add_r = 0, min_f;\r\
    \n  std::priority_queue<T> l;\r\n  std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ r;\r\n\r\n  void emplace_l(T a) { l.emplace(a - add_l); }\r\n\r\n  void emplace_r(T\
    \ a) { r.emplace(a - add_r); }\r\n\r\n  T top_l() const { return l.empty() ? -inf\
    \ : l.top() + add_l; }\r\n\r\n  T top_r() const { return r.empty() ? inf : r.top()\
    \ + add_r; }\r\n};\r\n#line 11 \"test/data_structure/slope_trick.test.cpp\"\n\r\
    \nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\n\
    \  for (int i = 0; i < n; ++i) std::cin >> a[i];\r\n  SlopeTrick<long long> slope_trick(0);\r\
    \n  slope_trick.abs_x_minus_a(0);\r\n  slope_trick.abs_x_minus_a(a.front());\r\
    \n  for (int i = 1; i < n; ++i) {\r\n    slope_trick.translate(std::max(a[i] -\
    \ a[i - 1], 0));\r\n    slope_trick.cumulative_min();\r\n    slope_trick.abs_x_minus_a(0);\r\
    \n    slope_trick.abs_x_minus_a(a[i]);\r\n  }\r\n  std::cout << slope_trick.min()\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/slope trick\r\n */\r\n#define\
    \ IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <vector>\r\n#include\
    \ \"../../data_structure/slope_trick.hpp\"\r\n\r\nint main() {\r\n  int n;\r\n\
    \  std::cin >> n;\r\n  std::vector<int> a(n);\r\n  for (int i = 0; i < n; ++i)\
    \ std::cin >> a[i];\r\n  SlopeTrick<long long> slope_trick(0);\r\n  slope_trick.abs_x_minus_a(0);\r\
    \n  slope_trick.abs_x_minus_a(a.front());\r\n  for (int i = 1; i < n; ++i) {\r\
    \n    slope_trick.translate(std::max(a[i] - a[i - 1], 0));\r\n    slope_trick.cumulative_min();\r\
    \n    slope_trick.abs_x_minus_a(0);\r\n    slope_trick.abs_x_minus_a(a[i]);\r\n\
    \  }\r\n  std::cout << slope_trick.min() << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/slope_trick.hpp
  isVerificationFile: true
  path: test/data_structure/slope_trick.test.cpp
  requiredBy: []
  timestamp: '2021-08-13 20:19:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/slope_trick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/slope_trick.test.cpp
- /verify/test/data_structure/slope_trick.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
---
