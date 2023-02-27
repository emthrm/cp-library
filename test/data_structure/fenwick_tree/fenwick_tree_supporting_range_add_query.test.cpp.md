---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
      \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\n */\n\
    \n#include <iostream>\n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n\n\n\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename Abelian>\n\
    struct FenwickTreeSupportingRangeAddQuery {\n  explicit FenwickTreeSupportingRangeAddQuery(\n\
    \      const int n_, const Abelian ID = 0)\n      : n(n_ + 1), ID(ID) {\n    data_const.assign(n,\
    \ ID);\n    data_linear.assign(n, ID);\n  }\n\n  void add(int left, const int\
    \ right, const Abelian val) {\n    if (right < ++left) [[unlikely]] return;\n\
    \    for (int i = left; i < n; i += i & -i) {\n      data_const[i] -= val * (left\
    \ - 1);\n      data_linear[i] += val;\n    }\n    for (int i = right + 1; i <\
    \ n; i += i & -i) {\n      data_const[i] += val * right;\n      data_linear[i]\
    \ -= val;\n    }\n  }\n\n  Abelian sum(const int idx) const {\n    Abelian res\
    \ = ID;\n    for (int i = idx; i > 0; i -= i & -i) {\n      res += data_linear[i];\n\
    \    }\n    res *= idx;\n    for (int i = idx; i > 0; i -= i & -i) {\n      res\
    \ += data_const[i];\n    }\n    return res;\n  }\n\n  Abelian sum(const int left,\
    \ const int right) const {\n    return left < right ? sum(right) - sum(left) :\
    \ ID;\n  }\n\n  Abelian operator[](const int idx) const { return sum(idx, idx\
    \ + 1); }\n\n private:\n  const int n;\n  const Abelian ID;\n  std::vector<Abelian>\
    \ data_const, data_linear;\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::FenwickTreeSupportingRangeAddQuery<long\
    \ long> bit(n);\n  while (q--) {\n    int kind, s, t;\n    std::cin >> kind >>\
    \ s >> t;\n    --s; --t;\n    if (kind == 0) {\n      int x;\n      std::cin >>\
    \ x;\n      bit.add(s, t + 1, x);\n    } else if (kind == 1) {\n      std::cout\
    \ << bit.sum(s, t + 1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC Fenwick tree\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\n */\n\
    \n#include <iostream>\n\n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::FenwickTreeSupportingRangeAddQuery<long\
    \ long> bit(n);\n  while (q--) {\n    int kind, s, t;\n    std::cin >> kind >>\
    \ s >> t;\n    --s; --t;\n    if (kind == 0) {\n      int x;\n      std::cin >>\
    \ x;\n      bit.add(s, t + 1, x);\n    } else if (kind == 1) {\n      std::cout\
    \ << bit.sum(s, t + 1) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp
- /verify/test/data_structure/fenwick_tree/fenwick_tree_supporting_range_add_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\u30AF\
  \u30A8\u30EA\u5BFE\u5FDC Fenwick tree"
---
