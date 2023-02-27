---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree.hpp
    title: "2\u6B21\u5143 Fenwick tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick\
      \ tree"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
  bundledCode: "#line 1 \"test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick\
    \ tree\n *\n * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\n\
    \ */\n\n#include <iostream>\n#include <tuple>\n#include <queue>\n\n#line 1 \"\
    include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree.hpp\"\n\n\n\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTree2D\
    \ {\n  explicit FenwickTree2D(\n      const int height_, const int width_, const\
    \ Abelian ID = 0)\n      : height(height_ + 1), width(width_ + 1), ID(ID) {\n\
    \    data.assign(height, std::vector<Abelian>(width, ID));\n  }\n\n  void add(int\
    \ y, int x, const Abelian val) {\n    ++y; ++x;\n    for (int i = y; i < height;\
    \ i += i & -i) {\n      for (int j = x; j < width; j += j & -j) {\n        data[i][j]\
    \ += val;\n      }\n    }\n  }\n\n  Abelian sum(int y, int x) const {\n    ++y;\
    \ ++x;\n    Abelian res = ID;\n    for (int i = y; i > 0; i -= i & -i) {\n   \
    \   for (int j = x; j > 0; j -= j & -j) {\n        res += data[i][j];\n      }\n\
    \    }\n    return res;\n  }\n\n  Abelian sum(const int y1, const int x1, const\
    \ int y2, const int x2) const {\n    return y1 > y2 || x1 > x2 ? ID : sum(y2,\
    \ x2) - sum(y2, x1 - 1)\n                                     - sum(y1 - 1, x2)\
    \ + sum(y1 - 1, x1 - 1);\n  }\n\n  Abelian get(const int y, const int x) const\
    \ { return sum(y, x, y, x); }\n\n private:\n  const int height, width;\n  const\
    \ Abelian ID;\n  std::vector<std::vector<Abelian>> data;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 12 \"test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp\"\
    \n\nint main() {\n  int h, w, t, q;\n  std::cin >> h >> w >> t >> q;\n  emthrm::FenwickTree2D<int>\
    \ baked(h, w), unbaked(h, w);\n  std::queue<std::tuple<int, int, int>> que;\n\
    \  while (q--) {\n    int t_i, c, h_1, w_1;\n    std::cin >> t_i >> c >> h_1 >>\
    \ w_1;\n    --h_1; --w_1;\n    while (!que.empty() && std::get<0>(que.front())\
    \ <= t_i) {\n      const int y = std::get<1>(que.front()), x = std::get<2>(que.front());\n\
    \      que.pop();\n      unbaked.add(y, x, -1);\n      baked.add(y, x, 1);\n \
    \   }\n    if (c == 0) {\n      unbaked.add(h_1, w_1, 1);\n      que.emplace(t_i\
    \ + t, h_1, w_1);\n    } else if (c == 1) {\n      if (baked.get(h_1, w_1) ==\
    \ 1) baked.add(h_1, w_1, -1);\n    } else if (c == 2) {\n      int h_2, w_2;\n\
    \      std::cin >> h_2 >> w_2;\n      --h_2; --w_2;\n      std::cout << baked.sum(h_1,\
    \ w_1, h_2, w_2) << ' '\n                << unbaked.sum(h_1, w_1, h_2, w_2) <<\
    \ '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick\
    \ tree\n *\n * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\n\
    \ */\n\n#include <iostream>\n#include <tuple>\n#include <queue>\n\n#include \"\
    emthrm/data_structure/fenwick_tree/2d_fenwick_tree.hpp\"\n\nint main() {\n  int\
    \ h, w, t, q;\n  std::cin >> h >> w >> t >> q;\n  emthrm::FenwickTree2D<int> baked(h,\
    \ w), unbaked(h, w);\n  std::queue<std::tuple<int, int, int>> que;\n  while (q--)\
    \ {\n    int t_i, c, h_1, w_1;\n    std::cin >> t_i >> c >> h_1 >> w_1;\n    --h_1;\
    \ --w_1;\n    while (!que.empty() && std::get<0>(que.front()) <= t_i) {\n    \
    \  const int y = std::get<1>(que.front()), x = std::get<2>(que.front());\n   \
    \   que.pop();\n      unbaked.add(y, x, -1);\n      baked.add(y, x, 1);\n    }\n\
    \    if (c == 0) {\n      unbaked.add(h_1, w_1, 1);\n      que.emplace(t_i + t,\
    \ h_1, w_1);\n    } else if (c == 1) {\n      if (baked.get(h_1, w_1) == 1) baked.add(h_1,\
    \ w_1, -1);\n    } else if (c == 2) {\n      int h_2, w_2;\n      std::cin >>\
    \ h_2 >> w_2;\n      --h_2; --w_2;\n      std::cout << baked.sum(h_1, w_1, h_2,\
    \ w_2) << ' '\n                << unbaked.sum(h_1, w_1, h_2, w_2) << '\\n';\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/2d_fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick tree"
---
