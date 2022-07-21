---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/slope_trick.hpp
    title: slope trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc123/tasks/arc123_d
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
    links:
    - https://atcoder.jp/contests/arc123/tasks/arc123_d
  bundledCode: "#line 1 \"test/data_structure/slope_trick.test.cpp\"\n/*\n * @brief\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/slope trick\n */\n#define PROBLEM \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"\
    data_structure/slope_trick.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <limits>\n#include <numeric>\n#include <queue>\n#include <utility>\n\
    #line 9 \"data_structure/slope_trick.hpp\"\n\ntemplate <typename T>\nstruct SlopeTrick\
    \ {\n  const T inf;\n\n  explicit SlopeTrick(\n      const T min_f = 0, const\
    \ T inf = std::numeric_limits<T>::max())\n      : added_l(0), added_r(0), min_f(min_f),\
    \ inf(inf) {}\n\n  T min() const { return min_f; }\n  std::pair<T, T> argmin()\
    \ const { return {top_l(), top_r()}; }\n\n  template <typename U>\n  U f(const\
    \ U x) {\n    U f_x = min_f;\n    std::vector<T> tmp;\n    for (; top_l() > x;\
    \ l.pop()) {\n      const T t = top_l();\n      f_x += t - x;\n      tmp.emplace_back(t);\n\
    \    }\n    for (; !tmp.empty(); tmp.pop_back()) {\n      emplace_l(tmp.back());\n\
    \    }\n    for (; top_r() < x; r.pop()) {\n      const T t = top_r();\n     \
    \ f_x += x - t;\n      tmp.emplace_back(t);\n    }\n    for (; !tmp.empty(); tmp.pop_back())\
    \ {\n      emplace_r(tmp.back());\n    }\n    return f_x;\n  }\n\n  void constant_function(const\
    \ T c) { min_f += c; }\n\n  void x_minus_a(const T a) {\n    const T t = top_l();\n\
    \    if (t <= a) {\n      emplace_r(a);\n    } else {\n      min_f += t - a;\n\
    \      emplace_l(a);\n      l.pop();\n      emplace_r(t);\n    }\n  }\n\n  void\
    \ a_minus_x(const T a) {\n    const T t = top_r();\n    if (a <= t) {\n      emplace_l(a);\n\
    \    } else {\n      min_f += a - t;\n      emplace_r(a);\n      r.pop();\n  \
    \    emplace_l(t);\n    }\n  }\n\n  void abs_x_minus_a(const T a) {\n    x_minus_a(a);\n\
    \    a_minus_x(a);\n  }\n\n  void cumulative_min() {\n    while (!r.empty()) r.pop();\n\
    \    added_r = 0;\n  }\n\n  void rcumulative_min() {\n    while (!l.empty()) l.pop();\n\
    \    added_l = 0;\n  }\n\n  void translate(const T a) { sliding_window_minimum(a,\
    \ a); }\n\n  void sliding_window_minimum(const T a, const T b) {\n    assert(a\
    \ <= b);\n    added_l += a;\n    added_r += b;\n  }\n\n private:\n  T added_l,\
    \ added_r, min_f;\n  std::priority_queue<T> l;\n  std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> r;\n\n  void emplace_l(const T a) { l.emplace(a - added_l);\
    \ }\n  void emplace_r(const T a) { r.emplace(a - added_r); }\n\n  T top_l() const\
    \ { return l.empty() ? -inf : l.top() + added_l; }\n  T top_r() const { return\
    \ r.empty() ? inf : r.top() + added_r; }\n};\n#line 11 \"test/data_structure/slope_trick.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  SlopeTrick<long long>\
    \ slope_trick(0);\n  slope_trick.abs_x_minus_a(0);\n  slope_trick.abs_x_minus_a(a.front());\n\
    \  for (int i = 1; i < n; ++i) {\n    slope_trick.translate(std::max(a[i] - a[i\
    \ - 1], 0));\n    slope_trick.cumulative_min();\n    slope_trick.abs_x_minus_a(0);\n\
    \    slope_trick.abs_x_minus_a(a[i]);\n  }\n  std::cout << slope_trick.min() <<\
    \ '\\n';\n  return 0;\n}\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/slope trick\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/arc123/tasks/arc123_d\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#include \"../../data_structure/slope_trick.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  SlopeTrick<long long>\
    \ slope_trick(0);\n  slope_trick.abs_x_minus_a(0);\n  slope_trick.abs_x_minus_a(a.front());\n\
    \  for (int i = 1; i < n; ++i) {\n    slope_trick.translate(std::max(a[i] - a[i\
    \ - 1], 0));\n    slope_trick.cumulative_min();\n    slope_trick.abs_x_minus_a(0);\n\
    \    slope_trick.abs_x_minus_a(a[i]);\n  }\n  std::cout << slope_trick.min() <<\
    \ '\\n';\n  return 0;\n}\n"
  dependsOn:
  - data_structure/slope_trick.hpp
  isVerificationFile: true
  path: test/data_structure/slope_trick.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/slope_trick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/slope_trick.test.cpp
- /verify/test/data_structure/slope_trick.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/slope trick"
---
