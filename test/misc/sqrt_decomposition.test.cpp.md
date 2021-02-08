---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: misc/sqrt_decomposition.hpp
    title: "\u5E73\u65B9\u5206\u5272 (sqrt decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/misc/sqrt_decomposition.test.cpp\"\n/*\r\n * @brief\
    \ \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"misc/sqrt_decomposition.hpp\"\
    \n#include <cmath>\r\n#line 4 \"misc/sqrt_decomposition.hpp\"\n\r\nstruct SqrtDecomposition\
    \ {\r\n  int b, n;\r\n  std::vector<int> left, right;\r\n  std::vector<bool> need_to_be_eval;\r\
    \n\r\n  SqrtDecomposition(int n_) : b(std::sqrt(n_)) {\r\n    n = (n_ + b - 1)\
    \ / b;\r\n    left.resize(n);\r\n    right.resize(n);\r\n    need_to_be_eval.assign(n,\
    \ false);\r\n    for (int i = 0; i < n; ++i) {\r\n      left[i] = b * i;\r\n \
    \     right[i] = i + 1 == n ? n_ : b * (i + 1);\r\n    }\r\n  }\r\n\r\n  template\
    \ <typename T> void partial_update(int idx, T val);\r\n\r\n  template <typename\
    \ T> void total_update(int idx, T val);\r\n\r\n  template <typename T>\r\n  void\
    \ update(int l, int r, T val) {\r\n    if (r <= l) return;\r\n    int l_b = l\
    \ / b, r_b = (r - 1) / b;\r\n    if (l_b < r_b) {\r\n      if (l == left[l_b])\
    \ {\r\n        total_update(l_b, val);\r\n      } else {\r\n        for (int i\
    \ = l; i < right[l_b]; ++i) partial_update(i, val);\r\n      }\r\n      for (int\
    \ i = l_b + 1; i < r_b; ++i) total_update(i, val);\r\n      if (r == right[r_b])\
    \ {\r\n        total_update(r_b, val);\r\n      } else {\r\n        for (int i\
    \ = left[r_b]; i < r; ++i) partial_update(i, val);\r\n      }\r\n    } else {\r\
    \n      for (int i = l; i < r; ++i) partial_update(i, val);\r\n    }\r\n  }\r\n\
    \r\n  template <typename T> void partial_query(int idx, T &val);\r\n\r\n  template\
    \ <typename T> void total_query(int idx, T &val);\r\n\r\n  template <typename\
    \ T>\r\n  T query(int l, int r, const T UNITY) {\r\n    int l_b = l / b, r_b =\
    \ (r - 1) / b;\r\n    T res = UNITY;\r\n    if (l_b < r_b) {\r\n      if (l ==\
    \ left[l_b]) {\r\n        total_query(l_b, res);\r\n      } else {\r\n       \
    \ for (int i = l; i < right[l_b]; ++i) partial_query(i, res);\r\n      }\r\n \
    \     for (int i = l_b + 1; i < r_b; ++i) total_query(i, res);\r\n      if (r\
    \ == right[r_b]) {\r\n        total_query(r_b, res);\r\n      } else {\r\n   \
    \     for (int i = left[r_b]; i < r; ++i) partial_query(i, res);\r\n      }\r\n\
    \    } else {\r\n      for (int i = l; i < r; ++i) partial_query(i, res);\r\n\
    \    }\r\n    return res;\r\n  }\r\n};\r\n#line 9 \"test/misc/sqrt_decomposition.test.cpp\"\
    \n\r\nstd::vector<long long> A, B, lazy;\r\n\r\ntemplate <typename T>\r\nvoid\
    \ SqrtDecomposition::partial_update(int idx, T val) {\r\n  A[idx] += val;\r\n\
    \  B[idx / b] += val;\r\n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_update(int\
    \ idx, T val) {\r\n  lazy[idx] += val;\r\n  need_to_be_eval[idx] = true;\r\n}\r\
    \n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::partial_query(int idx,\
    \ T &val) {\r\n  int block = idx / b;\r\n  if (need_to_be_eval[block]) {\r\n \
    \   for (int i = left[block]; i < right[block]; ++i) partial_update(i, lazy[block]);\r\
    \n    lazy[block] = 0;\r\n    need_to_be_eval[block] = false;\r\n  }\r\n  val\
    \ += A[idx];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_query(int\
    \ idx, T &val) {\r\n  val += B[idx] + lazy[idx] * (right[idx] - left[idx]);\r\n\
    }\r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  SqrtDecomposition\
    \ sd(n);\r\n  A.assign(n, 0);\r\n  B.assign(sd.n, 0);\r\n  lazy.assign(sd.n, 0);\r\
    \n  while (q--) {\r\n    int query, s, t;\r\n    std::cin >> query >> s >> t;\r\
    \n    --s; --t;\r\n    if (query == 0) {\r\n      int x;\r\n      std::cin >>\
    \ x;\r\n      sd.update(s, t + 1, x);\r\n    } else if (query == 1) {\r\n    \
    \  std::cout << sd.query(s, t + 1, 0LL) << '\\n';\r\n    }\r\n  }\r\n  return\
    \ 0;\r\n}\r\n\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../misc/sqrt_decomposition.hpp\"\
    \r\n\r\nstd::vector<long long> A, B, lazy;\r\n\r\ntemplate <typename T>\r\nvoid\
    \ SqrtDecomposition::partial_update(int idx, T val) {\r\n  A[idx] += val;\r\n\
    \  B[idx / b] += val;\r\n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_update(int\
    \ idx, T val) {\r\n  lazy[idx] += val;\r\n  need_to_be_eval[idx] = true;\r\n}\r\
    \n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::partial_query(int idx,\
    \ T &val) {\r\n  int block = idx / b;\r\n  if (need_to_be_eval[block]) {\r\n \
    \   for (int i = left[block]; i < right[block]; ++i) partial_update(i, lazy[block]);\r\
    \n    lazy[block] = 0;\r\n    need_to_be_eval[block] = false;\r\n  }\r\n  val\
    \ += A[idx];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_query(int\
    \ idx, T &val) {\r\n  val += B[idx] + lazy[idx] * (right[idx] - left[idx]);\r\n\
    }\r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  SqrtDecomposition\
    \ sd(n);\r\n  A.assign(n, 0);\r\n  B.assign(sd.n, 0);\r\n  lazy.assign(sd.n, 0);\r\
    \n  while (q--) {\r\n    int query, s, t;\r\n    std::cin >> query >> s >> t;\r\
    \n    --s; --t;\r\n    if (query == 0) {\r\n      int x;\r\n      std::cin >>\
    \ x;\r\n      sd.update(s, t + 1, x);\r\n    } else if (query == 1) {\r\n    \
    \  std::cout << sd.query(s, t + 1, 0LL) << '\\n';\r\n    }\r\n  }\r\n  return\
    \ 0;\r\n}\r\n\r\n"
  dependsOn:
  - misc/sqrt_decomposition.hpp
  isVerificationFile: true
  path: test/misc/sqrt_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/sqrt_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/misc/sqrt_decomposition.test.cpp
- /verify/test/misc/sqrt_decomposition.test.cpp.html
title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
---
