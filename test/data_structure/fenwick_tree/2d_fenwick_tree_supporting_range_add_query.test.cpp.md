---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
    title: "\u533A\u9593\u52A0\u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick\
      \ tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://yukicoder.me/problems/no/1490
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
      \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
    links:
    - https://yukicoder.me/problems/no/1490
  bundledCode: "#line 1 \"test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/1490\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTree2DSupportingRangeAddQuery\
    \ {\n  explicit FenwickTree2DSupportingRangeAddQuery(\n      const int height_,\
    \ const int width_, const Abelian ID = 0)\n      : height(height_ + 1), width(width_\
    \ + 1), ID(ID) {\n    data_const.assign(height, std::vector<Abelian>(width, ID));\n\
    \    data_linear[0].assign(height, std::vector<Abelian>(width, ID));\n    data_linear[1].assign(height,\
    \ std::vector<Abelian>(width, ID));\n    data_quadratic.assign(height, std::vector<Abelian>(width,\
    \ ID));\n  }\n\n  void add(int y1, int x1, int y2, int x2, const Abelian val)\
    \ {\n    ++y1; ++x1; ++y2; ++x2;\n    for (int i = y1; i < height; i += i & -i)\
    \ {\n      for (int j = x1; j < width; j += j & -j) {\n        data_const[i][j]\
    \ += val * (y1 - 1) * (x1 - 1);\n        data_linear[0][i][j] -= val * (x1 - 1);\n\
    \        data_linear[1][i][j] -= val * (y1 - 1);\n        data_quadratic[i][j]\
    \ += val;\n      }\n    }\n    for (int i = y1; i < height; i += i & -i) {\n \
    \     for (int j = x2 + 1; j < width; j += j & -j) {\n        data_const[i][j]\
    \ -= val * (y1 - 1) * x2;\n        data_linear[0][i][j] += val * x2;\n       \
    \ data_linear[1][i][j] += val * (y1 - 1);\n        data_quadratic[i][j] -= val;\n\
    \      }\n    }\n    for (int i = y2 + 1; i < height; i += i & -i) {\n      for\
    \ (int j = x1; j < width; j += j & -j) {\n        data_const[i][j] -= val * y2\
    \ * (x1 - 1);\n        data_linear[0][i][j] += val * (x1 - 1);\n        data_linear[1][i][j]\
    \ += val * y2;\n        data_quadratic[i][j] -= val;\n      }\n    }\n    for\
    \ (int i = y2 + 1; i < height; i += i & -i) {\n      for (int j = x2 + 1; j <\
    \ width; j += j & -j) {\n        data_const[i][j] += val * y2 * x2;\n        data_linear[0][i][j]\
    \ -= val * x2;\n        data_linear[1][i][j] -= val * y2;\n        data_quadratic[i][j]\
    \ += val;\n      }\n    }\n  }\n\n  Abelian sum(int y, int x) const {\n    ++y;\
    \ ++x;\n    Abelian quad = ID, cons = ID, line[2]{ID, ID};\n    for (int i = y;\
    \ i > 0; i -= i & -i) {\n      for (int j = x; j > 0; j -= j & -j) {\n       \
    \ quad += data_quadratic[i][j];\n        line[0] += data_linear[0][i][j];\n  \
    \      line[1] += data_linear[1][i][j];\n        cons += data_const[i][j];\n \
    \     }\n    }\n    return quad * y * x + line[0] * y + line[1] * x + cons;\n\
    \  }\n\n  Abelian sum(const int y1, const int x1, const int y2, const int x2)\
    \ const {\n    return y1 > y2 || x1 > x2 ? ID : sum(y2, x2) - sum(y2, x1 - 1)\n\
    \                                     - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1);\n\
    \  }\n\n private:\n  const int height, width;\n  const Abelian ID;\n  std::vector<std::vector<Abelian>>\
    \ data_const, data_quadratic;\n  std::vector<std::vector<Abelian>> data_linear[2];\n\
    };\n\n}  // namespace emthrm\n\n\n#line 12 \"test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp\"\
    \n\nint main() {\n  int h, w, n, m;\n  std::cin >> h >> w >> n >> m;\n  std::vector<int>\
    \ t(n), u(n), l(n), r(n), a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> t[i] >> u[i] >> l[i] >> r[i] >> a[i];\n    --t[i]; --u[i];\n    --l[i]; --r[i];\n\
    \  }\n  emthrm::FenwickTree2DSupportingRangeAddQuery<long long> bit(h, w);\n \
    \ while (m--) {\n    int x, y, b, c;\n    std::cin >> x >> y >> b >> c;\n    --x;\
    \ --y;\n    bit.add(std::max(x - b, 0), std::max(y - b, 0),\n            std::min(x\
    \ + b, h - 1), std::min(y + b, w - 1), c);\n  }\n  int ans = 0;\n  for (int i\
    \ = 0; i < n; ++i) {\n    ans += bit.sum(t[i], l[i], u[i], r[i]) < a[i];\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\
    \u7B97\u30AF\u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree\n *\n * verification-helper:\
    \ PROBLEM https://yukicoder.me/problems/no/1490\n */\n\n#include <algorithm>\n\
    #include <iostream>\n#include <vector>\n\n#include \"emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp\"\
    \n\nint main() {\n  int h, w, n, m;\n  std::cin >> h >> w >> n >> m;\n  std::vector<int>\
    \ t(n), u(n), l(n), r(n), a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> t[i] >> u[i] >> l[i] >> r[i] >> a[i];\n    --t[i]; --u[i];\n    --l[i]; --r[i];\n\
    \  }\n  emthrm::FenwickTree2DSupportingRangeAddQuery<long long> bit(h, w);\n \
    \ while (m--) {\n    int x, y, b, c;\n    std::cin >> x >> y >> b >> c;\n    --x;\
    \ --y;\n    bit.add(std::max(x - b, 0), std::max(y - b, 0),\n            std::min(x\
    \ + b, h - 1), std::min(y + b, w - 1), c);\n  }\n  int ans = 0;\n  for (int i\
    \ = 0; i < n; ++i) {\n    ans += bit.sum(t[i], l[i], u[i], r[i]) < a[i];\n  }\n\
    \  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree_supporting_range_add_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/\u533A\u9593\u52A0\u7B97\u30AF\
  \u30A8\u30EA\u5BFE\u5FDC2\u6B21\u5143 Fenwick tree"
---
