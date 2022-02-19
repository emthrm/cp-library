---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/sqrt_decomposition.hpp
    title: "\u5E73\u65B9\u5206\u5272 (sqrt decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/misc/sqrt_decomposition.test.cpp\"\n/*\r\n * @brief\
    \ \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"misc/sqrt_decomposition.hpp\"\
    \n#include <cmath>\r\n#line 4 \"misc/sqrt_decomposition.hpp\"\n\r\nstruct SqrtDecomposition\
    \ {\r\n  const int block_size, n;\r\n  std::vector<int> ls, rs;\r\n  std::vector<bool>\
    \ to_be_eval;\r\n\r\n  explicit SqrtDecomposition(const int n_)\r\n      : block_size(std::round(std::sqrt(n_))),\r\
    \n        n((n_ + block_size - 1) / block_size) {\r\n    ls.resize(n);\r\n   \
    \ rs.resize(n);\r\n    to_be_eval.assign(n, false);\r\n    for (int i = 0; i <\
    \ n; ++i) {\r\n      ls[i] = block_size * i;\r\n      rs[i] = (i + 1 == n ? n_\
    \ : block_size * (i + 1));\r\n    }\r\n  }\r\n\r\n  template <typename T> void\
    \ partial_update(const int idx, const T val);\r\n\r\n  template <typename T> void\
    \ total_update(const int idx, const T val);\r\n\r\n  template <typename T>\r\n\
    \  void update(const int l, const int r, const T val) {\r\n    if (r <= l) return;\r\
    \n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\r\n    if (b_l\
    \ < b_r) {\r\n      if (l == ls[b_l]) {\r\n        total_update(b_l, val);\r\n\
    \      } else {\r\n        for (int i = l; i < rs[b_l]; ++i) {\r\n          partial_update(i,\
    \ val);\r\n        }\r\n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\
    \n        total_update(i, val);\r\n      }\r\n      if (r == rs[b_r]) {\r\n  \
    \      total_update(b_r, val);\r\n      } else {\r\n        for (int i = ls[b_r];\
    \ i < r; ++i) {\r\n          partial_update(i, val);\r\n        }\r\n      }\r\
    \n    } else {\r\n      for (int i = l; i < r; ++i) {\r\n        partial_update(i,\
    \ val);\r\n      }\r\n    }\r\n  }\r\n\r\n  template <typename T> void partial_query(const\
    \ int idx, T* val);\r\n\r\n  template <typename T> void total_query(const int\
    \ idx, T* val);\r\n\r\n  template <typename T>\r\n  T query(const int l, const\
    \ int r, const T id) {\r\n    const int b_l = l / block_size, b_r = (r - 1) /\
    \ block_size;\r\n    T res = id;\r\n    if (b_l < b_r) {\r\n      if (l == ls[b_l])\
    \ {\r\n        total_query(b_l, &res);\r\n      } else {\r\n        for (int i\
    \ = l; i < rs[b_l]; ++i) {\r\n          partial_query(i, &res);\r\n        }\r\
    \n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\n        total_query(i,\
    \ &res);\r\n      }\r\n      if (r == rs[b_r]) {\r\n        total_query(b_r, &res);\r\
    \n      } else {\r\n        for (int i = ls[b_r]; i < r; ++i) {\r\n          partial_query(i,\
    \ &res);\r\n        }\r\n      }\r\n    } else {\r\n      for (int i = l; i <\
    \ r; ++i) {\r\n        partial_query(i, &res);\r\n      }\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n#line 10 \"test/misc/sqrt_decomposition.test.cpp\"\n\r\n\
    std::vector<long long> a, b, lazy;\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::partial_update(const\
    \ int idx, const T val) {\r\n  a[idx] += val;\r\n  b[idx / block_size] += val;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_update(const\
    \ int idx, const T val) {\r\n  lazy[idx] += val;\r\n  to_be_eval[idx] = true;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::partial_query(const\
    \ int idx, T* val) {\r\n  const int block = idx / block_size;\r\n  if (to_be_eval[block])\
    \ {\r\n    for (int i = ls[block]; i < rs[block]; ++i) {\r\n      partial_update(i,\
    \ lazy[block]);\r\n    }\r\n    lazy[block] = 0;\r\n    to_be_eval[block] = false;\r\
    \n  }\r\n  *val += a[idx];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_query(const\
    \ int idx, T* val) {\r\n  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);\r\n\
    }\r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  SqrtDecomposition\
    \ sqrt_decomposition(n);\r\n  a.assign(n, 0);\r\n  b.assign(sqrt_decomposition.n,\
    \ 0);\r\n  lazy.assign(sqrt_decomposition.n, 0);\r\n  while (q--) {\r\n    int\
    \ type, s, t;\r\n    std::cin >> type >> s >> t;\r\n    --s; --t;\r\n    if (type\
    \ == 0) {\r\n      int x;\r\n      std::cin >> x;\r\n      sqrt_decomposition.update(s,\
    \ t + 1, x);\r\n    } else if (type == 1) {\r\n      std::cout << sqrt_decomposition.query(s,\
    \ t + 1, 0LL) << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\r\n */\r\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../misc/sqrt_decomposition.hpp\"\
    \r\n\r\nstd::vector<long long> a, b, lazy;\r\n\r\ntemplate <typename T>\r\nvoid\
    \ SqrtDecomposition::partial_update(const int idx, const T val) {\r\n  a[idx]\
    \ += val;\r\n  b[idx / block_size] += val;\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid SqrtDecomposition::total_update(const int idx, const T val) {\r\n  lazy[idx]\
    \ += val;\r\n  to_be_eval[idx] = true;\r\n}\r\n\r\ntemplate <typename T>\r\nvoid\
    \ SqrtDecomposition::partial_query(const int idx, T* val) {\r\n  const int block\
    \ = idx / block_size;\r\n  if (to_be_eval[block]) {\r\n    for (int i = ls[block];\
    \ i < rs[block]; ++i) {\r\n      partial_update(i, lazy[block]);\r\n    }\r\n\
    \    lazy[block] = 0;\r\n    to_be_eval[block] = false;\r\n  }\r\n  *val += a[idx];\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid SqrtDecomposition::total_query(const\
    \ int idx, T* val) {\r\n  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);\r\n\
    }\r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  SqrtDecomposition\
    \ sqrt_decomposition(n);\r\n  a.assign(n, 0);\r\n  b.assign(sqrt_decomposition.n,\
    \ 0);\r\n  lazy.assign(sqrt_decomposition.n, 0);\r\n  while (q--) {\r\n    int\
    \ type, s, t;\r\n    std::cin >> type >> s >> t;\r\n    --s; --t;\r\n    if (type\
    \ == 0) {\r\n      int x;\r\n      std::cin >> x;\r\n      sqrt_decomposition.update(s,\
    \ t + 1, x);\r\n    } else if (type == 1) {\r\n      std::cout << sqrt_decomposition.query(s,\
    \ t + 1, 0LL) << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/sqrt_decomposition.hpp
  isVerificationFile: true
  path: test/misc/sqrt_decomposition.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 18:14:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/sqrt_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/misc/sqrt_decomposition.test.cpp
- /verify/test/misc/sqrt_decomposition.test.cpp.html
title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
---
