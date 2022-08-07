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
  bundledCode: "#line 1 \"test/misc/sqrt_decomposition.test.cpp\"\n/*\n * @brief \u305D\
    \u306E\u4ED6/\u5E73\u65B9\u5206\u5272\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"misc/sqrt_decomposition.hpp\"\
    \n#include <cmath>\n#line 4 \"misc/sqrt_decomposition.hpp\"\n\nstruct SqrtDecomposition\
    \ {\n  const int block_size, n;\n  std::vector<int> ls, rs;\n  std::vector<bool>\
    \ to_be_eval;\n\n  explicit SqrtDecomposition(const int n_)\n      : block_size(std::round(std::sqrt(n_))),\n\
    \        n((n_ + block_size - 1) / block_size) {\n    ls.resize(n);\n    rs.resize(n);\n\
    \    to_be_eval.assign(n, false);\n    for (int i = 0; i < n; ++i) {\n      ls[i]\
    \ = block_size * i;\n      rs[i] = (i + 1 == n ? n_ : block_size * (i + 1));\n\
    \    }\n  }\n\n  template <typename T> void partial_update(const int idx, const\
    \ T val);\n\n  template <typename T> void total_update(const int idx, const T\
    \ val);\n\n  template <typename T>\n  void update(const int l, const int r, const\
    \ T val) {\n    if (r <= l) return;\n    const int b_l = l / block_size, b_r =\
    \ (r - 1) / block_size;\n    if (b_l < b_r) {\n      if (l == ls[b_l]) {\n   \
    \     total_update(b_l, val);\n      } else {\n        for (int i = l; i < rs[b_l];\
    \ ++i) {\n          partial_update(i, val);\n        }\n      }\n      for (int\
    \ i = b_l + 1; i < b_r; ++i) {\n        total_update(i, val);\n      }\n     \
    \ if (r == rs[b_r]) {\n        total_update(b_r, val);\n      } else {\n     \
    \   for (int i = ls[b_r]; i < r; ++i) {\n          partial_update(i, val);\n \
    \       }\n      }\n    } else {\n      for (int i = l; i < r; ++i) {\n      \
    \  partial_update(i, val);\n      }\n    }\n  }\n\n  template <typename T> void\
    \ partial_query(const int idx, T* val);\n\n  template <typename T> void total_query(const\
    \ int idx, T* val);\n\n  template <typename T>\n  T query(const int l, const int\
    \ r, const T id) {\n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\n\
    \    T res = id;\n    if (b_l < b_r) {\n      if (l == ls[b_l]) {\n        total_query(b_l,\
    \ &res);\n      } else {\n        for (int i = l; i < rs[b_l]; ++i) {\n      \
    \    partial_query(i, &res);\n        }\n      }\n      for (int i = b_l + 1;\
    \ i < b_r; ++i) {\n        total_query(i, &res);\n      }\n      if (r == rs[b_r])\
    \ {\n        total_query(b_r, &res);\n      } else {\n        for (int i = ls[b_r];\
    \ i < r; ++i) {\n          partial_query(i, &res);\n        }\n      }\n    }\
    \ else {\n      for (int i = l; i < r; ++i) {\n        partial_query(i, &res);\n\
    \      }\n    }\n    return res;\n  }\n};\n#line 10 \"test/misc/sqrt_decomposition.test.cpp\"\
    \n\nstd::vector<long long> a, b, lazy;\n\ntemplate <typename T>\nvoid SqrtDecomposition::partial_update(const\
    \ int idx, const T val) {\n  a[idx] += val;\n  b[idx / block_size] += val;\n}\n\
    \ntemplate <typename T>\nvoid SqrtDecomposition::total_update(const int idx, const\
    \ T val) {\n  lazy[idx] += val;\n  to_be_eval[idx] = true;\n}\n\ntemplate <typename\
    \ T>\nvoid SqrtDecomposition::partial_query(const int idx, T* val) {\n  const\
    \ int block = idx / block_size;\n  if (to_be_eval[block]) {\n    for (int i =\
    \ ls[block]; i < rs[block]; ++i) {\n      partial_update(i, lazy[block]);\n  \
    \  }\n    lazy[block] = 0;\n    to_be_eval[block] = false;\n  }\n  *val += a[idx];\n\
    }\n\ntemplate <typename T>\nvoid SqrtDecomposition::total_query(const int idx,\
    \ T* val) {\n  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);\n}\n\nint main()\
    \ {\n  int n, q;\n  std::cin >> n >> q;\n  SqrtDecomposition sqrt_decomposition(n);\n\
    \  a.assign(n, 0);\n  b.assign(sqrt_decomposition.n, 0);\n  lazy.assign(sqrt_decomposition.n,\
    \ 0);\n  while (q--) {\n    int type, s, t;\n    std::cin >> type >> s >> t;\n\
    \    --s; --t;\n    if (type == 0) {\n      int x;\n      std::cin >> x;\n   \
    \   sqrt_decomposition.update(s, t + 1, x);\n    } else if (type == 1) {\n   \
    \   std::cout << sqrt_decomposition.query(s, t + 1, 0LL) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../misc/sqrt_decomposition.hpp\"\
    \n\nstd::vector<long long> a, b, lazy;\n\ntemplate <typename T>\nvoid SqrtDecomposition::partial_update(const\
    \ int idx, const T val) {\n  a[idx] += val;\n  b[idx / block_size] += val;\n}\n\
    \ntemplate <typename T>\nvoid SqrtDecomposition::total_update(const int idx, const\
    \ T val) {\n  lazy[idx] += val;\n  to_be_eval[idx] = true;\n}\n\ntemplate <typename\
    \ T>\nvoid SqrtDecomposition::partial_query(const int idx, T* val) {\n  const\
    \ int block = idx / block_size;\n  if (to_be_eval[block]) {\n    for (int i =\
    \ ls[block]; i < rs[block]; ++i) {\n      partial_update(i, lazy[block]);\n  \
    \  }\n    lazy[block] = 0;\n    to_be_eval[block] = false;\n  }\n  *val += a[idx];\n\
    }\n\ntemplate <typename T>\nvoid SqrtDecomposition::total_query(const int idx,\
    \ T* val) {\n  *val += b[idx] + lazy[idx] * (rs[idx] - ls[idx]);\n}\n\nint main()\
    \ {\n  int n, q;\n  std::cin >> n >> q;\n  SqrtDecomposition sqrt_decomposition(n);\n\
    \  a.assign(n, 0);\n  b.assign(sqrt_decomposition.n, 0);\n  lazy.assign(sqrt_decomposition.n,\
    \ 0);\n  while (q--) {\n    int type, s, t;\n    std::cin >> type >> s >> t;\n\
    \    --s; --t;\n    if (type == 0) {\n      int x;\n      std::cin >> x;\n   \
    \   sqrt_decomposition.update(s, t + 1, x);\n    } else if (type == 1) {\n   \
    \   std::cout << sqrt_decomposition.query(s, t + 1, 0LL) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - misc/sqrt_decomposition.hpp
  isVerificationFile: true
  path: test/misc/sqrt_decomposition.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/sqrt_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/misc/sqrt_decomposition.test.cpp
- /verify/test/misc/sqrt_decomposition.test.cpp.html
title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
---
