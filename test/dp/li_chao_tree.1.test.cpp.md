---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/li_chao_tree.hpp
    title: Li Chao tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024\
      )"
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/dp/li_chao_tree.1.test.cpp\"\n/*\r\n * @brief \u52D5\
    \u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024)\r\n */\r\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\r\n\r\n#include <iostream>\r\
    \n#include <vector>\r\n#line 2 \"dp/li_chao_tree.hpp\"\n#include <algorithm>\r\
    \n#include <cassert>\r\n#include <utility>\r\n#line 6 \"dp/li_chao_tree.hpp\"\n\
    \r\ntemplate <typename T>\r\nstruct LiChaoTree {\r\n  struct Line {\r\n    T a,\
    \ b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n    T f(T x) const { return a *\
    \ x + b; }\r\n  };\r\n\r\n  LiChaoTree(const std::vector<T> &xs_, const T TINF,\
    \ bool is_minimized = true) : xs(xs_), is_minimized(is_minimized) {\r\n    std::sort(xs.begin(),\
    \ xs.end());\r\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\r\n\
    \    int sz = xs.size();\r\n    assert(sz > 0);\r\n    while (n < sz) n <<= 1;\r\
    \n    xs.resize(n, xs.back());\r\n    Line unity(0, TINF);\r\n    dat.assign(n\
    \ << 1, unity);\r\n  }\r\n\r\n  void add(T a, T b) {\r\n    if (!is_minimized)\
    \ {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    Line line(a, b);\r\n   \
    \ add(line, 1, 0, n);\r\n  }\r\n\r\n  void add(T a, T b, T left, T right) {\r\n\
    \    if (!is_minimized) {\r\n      a = -a;\r\n      b = -b;\r\n    }\r\n    int\
    \ l = std::lower_bound(xs.begin(), xs.end(), left) - xs.begin(), r = std::lower_bound(xs.begin(),\
    \ xs.end(), right) - xs.begin();\r\n    int len, node_l = l, node_r = r;\r\n \
    \   for (l += n, r += n, len = 1; l < r; l >>= 1, r >>= 1, len <<= 1) {\r\n  \
    \    if (l & 1) {\r\n        Line line(a, b);\r\n        add(line, l++, node_l,\
    \ node_l + len);\r\n        node_l += len;\r\n      }\r\n      if (r & 1) {\r\n\
    \        Line line(a, b);\r\n        node_r -= len;\r\n        add(line, --r,\
    \ node_r, node_r + len);\r\n      }\r\n    }\r\n  }\r\n\r\n  T query(T x) const\
    \ {\r\n    int node = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\r\
    \n    node += n;\r\n    T res = dat[node].f(x);\r\n    while (node >>= 1) {\r\n\
    \      if (dat[node].f(x) < res) res = dat[node].f(x);\r\n    }\r\n    return\
    \ is_minimized ? res : -res;\r\n  }\r\n\r\nprivate:\r\n  bool is_minimized;\r\n\
    \  int n = 1;\r\n  std::vector<T> xs;\r\n  std::vector<Line> dat;\r\n\r\n  void\
    \ add(Line &line, int node, int left, int right) {\r\n    bool l = dat[node].f(xs[left])\
    \ <= line.f(xs[left]), r = dat[node].f(xs[right - 1]) <= line.f(xs[right - 1]);\r\
    \n    if (l && r) return;\r\n    if (!l && !r) {\r\n      std::swap(dat[node],\
    \ line);\r\n      return;\r\n    }\r\n    int mid = (left + right) >> 1;\r\n \
    \   if (line.f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], line);\r\n\
    \    if (line.f(xs[left]) <= dat[node].f(xs[left])) {\r\n      add(line, node\
    \ << 1, left, mid);\r\n    } else {\r\n      add(line, (node << 1) + 1, mid, right);\r\
    \n    }\r\n  }\r\n};\r\n#line 9 \"test/dp/li_chao_tree.1.test.cpp\"\n\r\nint main()\
    \ {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n  int n, q;\r\n \
    \ std::cin >> n >> q;\r\n  std::vector<int> query(q), l(n + q), r(n + q), a(n\
    \ + q), p(q);\r\n  std::vector<long long> b(n + q), xs;\r\n  for (int i = 0; i\
    \ < n; ++i) std::cin >> l[i] >> r[i] >> a[i] >> b[i];\r\n  for (int i = 0; i <\
    \ q; ++i) {\r\n    std::cin >> query[i];\r\n    if (query[i] == 0) {\r\n     \
    \ std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];\r\n    } else if (query[i]\
    \ == 1) {\r\n      std::cin >> p[i];\r\n      xs.emplace_back(p[i]);\r\n    }\r\
    \n  }\r\n  if (xs.empty()) return 0;\r\n  LiChaoTree<long long> lct(xs, LINF);\r\
    \n  for (int i = 0; i < n; ++i) lct.add(a[i], b[i], l[i], r[i]);\r\n  for (int\
    \ i = 0; i < q; ++i) {\r\n    if (query[i] == 0) {\r\n      lct.add(a[n + i],\
    \ b[n + i], l[n + i], r[n + i]);\r\n    } else if (query[i] == 1) {\r\n      long\
    \ long ans = lct.query(p[i]);\r\n      if (ans == LINF) {\r\n        std::cout\
    \ << \"INFINITY\\n\";\r\n      } else {\r\n        std::cout << ans << '\\n';\r\
    \n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\
    \u5024)\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../dp/li_chao_tree.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n\
    \  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int> query(q), l(n + q),\
    \ r(n + q), a(n + q), p(q);\r\n  std::vector<long long> b(n + q), xs;\r\n  for\
    \ (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i] >> a[i] >> b[i];\r\n  for (int\
    \ i = 0; i < q; ++i) {\r\n    std::cin >> query[i];\r\n    if (query[i] == 0)\
    \ {\r\n      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];\r\n   \
    \ } else if (query[i] == 1) {\r\n      std::cin >> p[i];\r\n      xs.emplace_back(p[i]);\r\
    \n    }\r\n  }\r\n  if (xs.empty()) return 0;\r\n  LiChaoTree<long long> lct(xs,\
    \ LINF);\r\n  for (int i = 0; i < n; ++i) lct.add(a[i], b[i], l[i], r[i]);\r\n\
    \  for (int i = 0; i < q; ++i) {\r\n    if (query[i] == 0) {\r\n      lct.add(a[n\
    \ + i], b[n + i], l[n + i], r[n + i]);\r\n    } else if (query[i] == 1) {\r\n\
    \      long long ans = lct.query(p[i]);\r\n      if (ans == LINF) {\r\n      \
    \  std::cout << \"INFINITY\\n\";\r\n      } else {\r\n        std::cout << ans\
    \ << '\\n';\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dp/li_chao_tree.hpp
  isVerificationFile: true
  path: test/dp/li_chao_tree.1.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dp/li_chao_tree.1.test.cpp
layout: document
redirect_from:
- /verify/test/dp/li_chao_tree.1.test.cpp
- /verify/test/dp/li_chao_tree.1.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024)"
---
