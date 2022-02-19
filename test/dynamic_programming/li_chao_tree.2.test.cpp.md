---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic_programming/li_chao_tree.hpp
    title: Li Chao tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024\
      )"
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/dynamic_programming/li_chao_tree.2.test.cpp\"\n/*\r\
    \n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)\r\
    \n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 2 \"dynamic_programming/li_chao_tree.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#include <iterator>\r\n#include\
    \ <utility>\r\n#line 7 \"dynamic_programming/li_chao_tree.hpp\"\n\r\ntemplate\
    \ <typename T, bool IS_MINIMIZED = true>\r\nstruct LiChaoTree {\r\n  struct Line\
    \ {\r\n    T a, b;\r\n    explicit Line(const T a, const T b) : a(a), b(b) {}\r\
    \n    T f(const T x) const { return a * x + b; }\r\n  };\r\n\r\n  explicit LiChaoTree(const\
    \ std::vector<T>& xs_, const T inf) : n(1), xs(xs_) {\r\n    std::sort(xs.begin(),\
    \ xs.end());\r\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\r\n\
    \    const int xs_size = xs.size();\r\n    assert(xs_size > 0);\r\n    while (n\
    \ < xs_size) n <<= 1;\r\n    const T xs_back = xs.back();\r\n    xs.resize(n,\
    \ xs_back);\r\n    dat.assign(n << 1, Line(0, inf));\r\n  }\r\n\r\n  void add(T\
    \ a, T b) {\r\n    if (!IS_MINIMIZED) {\r\n      a = -a;\r\n      b = -b;\r\n\
    \    }\r\n    Line line(a, b);\r\n    add(&line, 1, 0, n);\r\n  }\r\n\r\n  void\
    \ add(T a, T b, T left, T right) {\r\n    if (!IS_MINIMIZED) {\r\n      a = -a;\r\
    \n      b = -b;\r\n    }\r\n    for (int len = 1,\r\n             node_l = std::distance(\r\
    \n                 xs.begin(), std::lower_bound(xs.begin(), xs.end(), left)),\r\
    \n             node_r = std::distance(\r\n                 xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), right)),\r\n             l = node_l + n, r = node_r + n;\r\n     \
    \    l < r;\r\n         l >>= 1, r >>= 1, len <<= 1) {\r\n      if (l & 1) {\r\
    \n        Line line(a, b);\r\n        add(&line, l++, node_l, node_l + len);\r\
    \n        node_l += len;\r\n      }\r\n      if (r & 1) {\r\n        Line line(a,\
    \ b);\r\n        node_r -= len;\r\n        add(&line, --r, node_r, node_r + len);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  T query(const T x) const {\r\n    int node\
    \ = n + std::distance(xs.begin(),\r\n                                 std::lower_bound(xs.begin(),\
    \ xs.end(), x));\r\n    T res = dat[node].f(x);\r\n    while (node >>= 1) {\r\n\
    \      if (dat[node].f(x) < res) res = dat[node].f(x);\r\n    }\r\n    return\
    \ IS_MINIMIZED ? res : -res;\r\n  }\r\n\r\n private:\r\n  int n;\r\n  std::vector<T>\
    \ xs;\r\n  std::vector<Line> dat;\r\n\r\n  void add(Line* line, int node, int\
    \ left, int right) {\r\n    const bool flag_l = dat[node].f(xs[left]) <= line->f(xs[left]);\r\
    \n    const bool flag_r = dat[node].f(xs[right - 1]) <= line->f(xs[right - 1]);\r\
    \n    if (flag_l && flag_r) return;\r\n    if (!flag_l && !flag_r) {\r\n     \
    \ std::swap(dat[node], *line);\r\n      return;\r\n    }\r\n    const int mid\
    \ = (left + right) >> 1;\r\n    if (line->f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node],\
    \ *line);\r\n    if (line->f(xs[left]) <= dat[node].f(xs[left])) {\r\n      add(line,\
    \ node << 1, left, mid);\r\n    } else {\r\n      add(line, (node << 1) + 1, mid,\
    \ right);\r\n    }\r\n  }\r\n};\r\n#line 10 \"test/dynamic_programming/li_chao_tree.2.test.cpp\"\
    \n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n \
    \ int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int> query(q), l(n + q),\
    \ r(n + q), a(n + q), p(q);\r\n  std::vector<long long> b(n + q), xs;\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\r\
    \n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cin >> query[i];\r\n    if\
    \ (query[i] == 0) {\r\n      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n\
    \ + i];\r\n    } else if (query[i] == 1) {\r\n      std::cin >> p[i];\r\n    \
    \  xs.emplace_back(p[i]);\r\n    }\r\n  }\r\n  if (xs.empty()) return 0;\r\n \
    \ LiChaoTree<long long, false> li_chao_tree(xs, LINF);\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    li_chao_tree.add(-a[i], -b[i], l[i], r[i]);\r\n  }\r\n  for\
    \ (int i = 0; i < q; ++i) {\r\n    if (query[i] == 0) {\r\n      li_chao_tree.add(-a[n\
    \ + i], -b[n + i], l[n + i], r[n + i]);\r\n    } else if (query[i] == 1) {\r\n\
    \      const long long ans = -li_chao_tree.query(p[i]);\r\n      if (ans == LINF)\
    \ {\r\n        std::cout << \"INFINITY\\n\";\r\n      } else {\r\n        std::cout\
    \ << ans << '\\n';\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\
    \u5024)\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include \"../../dynamic_programming/li_chao_tree.hpp\"\
    \r\n\r\nint main() {\r\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\n\
    \  int n, q;\r\n  std::cin >> n >> q;\r\n  std::vector<int> query(q), l(n + q),\
    \ r(n + q), a(n + q), p(q);\r\n  std::vector<long long> b(n + q), xs;\r\n  for\
    \ (int i = 0; i < n; ++i) {\r\n    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\r\
    \n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cin >> query[i];\r\n    if\
    \ (query[i] == 0) {\r\n      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n\
    \ + i];\r\n    } else if (query[i] == 1) {\r\n      std::cin >> p[i];\r\n    \
    \  xs.emplace_back(p[i]);\r\n    }\r\n  }\r\n  if (xs.empty()) return 0;\r\n \
    \ LiChaoTree<long long, false> li_chao_tree(xs, LINF);\r\n  for (int i = 0; i\
    \ < n; ++i) {\r\n    li_chao_tree.add(-a[i], -b[i], l[i], r[i]);\r\n  }\r\n  for\
    \ (int i = 0; i < q; ++i) {\r\n    if (query[i] == 0) {\r\n      li_chao_tree.add(-a[n\
    \ + i], -b[n + i], l[n + i], r[n + i]);\r\n    } else if (query[i] == 1) {\r\n\
    \      const long long ans = -li_chao_tree.query(p[i]);\r\n      if (ans == LINF)\
    \ {\r\n        std::cout << \"INFINITY\\n\";\r\n      } else {\r\n        std::cout\
    \ << ans << '\\n';\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - dynamic_programming/li_chao_tree.hpp
  isVerificationFile: true
  path: test/dynamic_programming/li_chao_tree.2.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/li_chao_tree.2.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/li_chao_tree.2.test.cpp
- /verify/test/dynamic_programming/li_chao_tree.2.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)"
---
