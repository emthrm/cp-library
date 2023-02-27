---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/union-find.hpp
    title: union-find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
      \u30BF\u69CB\u9020/union-find"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/data_structure/union-find/union-find.test.cpp\"\n/*\n\
    \ * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020/union-find\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/data_structure/union-find/union-find.hpp\"\
    \n\n\n\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\nstruct\
    \ UnionFind {\n  explicit UnionFind(const int n) : data(n, -1) {}\n\n  int root(const\
    \ int ver) {\n    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);\n\
    \  }\n\n  bool unite(int u, int v) {\n    u = root(u);\n    v = root(v);\n   \
    \ if (u == v) return false;\n    if (data[u] > data[v]) std::swap(u, v);\n   \
    \ data[u] += data[v];\n    data[v] = u;\n    return true;\n  }\n\n  bool is_same(const\
    \ int u, const int v) { return root(u) == root(v); }\n\n  int size(const int ver)\
    \ { return -data[root(ver)]; }\n\n private:\n  std::vector<int> data;\n};\n\n\
    }  // namespace emthrm\n\n\n#line 10 \"test/data_structure/union-find/union-find.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::UnionFind union_find(n);\n\
    \  while (q--) {\n    int com, x, y;\n    std::cin >> com >> x >> y;\n    if (com\
    \ == 0) {\n      union_find.unite(x, y);\n    } else if (com == 1) {\n      std::cout\
    \ << union_find.is_same(x, y) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020/union-find\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/data_structure/union-find/union-find.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::UnionFind union_find(n);\n\
    \  while (q--) {\n    int com, x, y;\n    std::cin >> com >> x >> y;\n    if (com\
    \ == 0) {\n      union_find.unite(x, y);\n    } else if (com == 1) {\n      std::cout\
    \ << union_find.is_same(x, y) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/union-find.test.cpp
  requiredBy: []
  timestamp: '2023-02-26 01:10:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/union-find.test.cpp
- /verify/test/data_structure/union-find/union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
  /union-find"
---
