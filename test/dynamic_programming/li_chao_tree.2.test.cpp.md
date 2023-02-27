---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/li_chao_tree.hpp
    title: Li Chao tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024\
      )"
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/dynamic_programming/li_chao_tree.2.test.cpp\"\n/*\n\
    \ * @title \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)\n\
    \ *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/segment_add_get_min\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/dynamic_programming/li_chao_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#include <iterator>\n\
    #include <numeric>\n#include <utility>\n#line 11 \"include/emthrm/dynamic_programming/li_chao_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, bool IS_MINIMIZED = true>\nstruct\
    \ LiChaoTree {\n  struct Line {\n    T a, b;\n    explicit Line(const T a, const\
    \ T b) : a(a), b(b) {}\n    T f(const T x) const { return a * x + b; }\n  };\n\
    \n  explicit LiChaoTree(const std::vector<T>& xs_, const T inf) : n(1), xs(xs_)\
    \ {\n    std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    assert(xs.size() > 0);\n    n = std::bit_ceil(xs.size());\n\
    \    const T xs_back = xs.back();\n    xs.resize(n, xs_back);\n    dat.assign(n\
    \ << 1, Line(0, inf));\n  }\n\n  void add(T a, T b) {\n    if constexpr (!IS_MINIMIZED)\
    \ {\n      a = -a;\n      b = -b;\n    }\n    Line line(a, b);\n    add(&line,\
    \ 1, 0, n);\n  }\n\n  void add(T a, T b, T left, T right) {\n    if constexpr\
    \ (!IS_MINIMIZED) {\n      a = -a;\n      b = -b;\n    }\n    for (int len = 1,\n\
    \             node_l = std::distance(\n                 xs.begin(), std::lower_bound(xs.begin(),\
    \ xs.end(), left)),\n             node_r = std::distance(\n                 xs.begin(),\
    \ std::lower_bound(xs.begin(), xs.end(), right)),\n             l = node_l + n,\
    \ r = node_r + n;\n         l < r;\n         l >>= 1, r >>= 1, len <<= 1) {\n\
    \      if (l & 1) {\n        Line line(a, b);\n        add(&line, l++, node_l,\
    \ node_l + len);\n        node_l += len;\n      }\n      if (r & 1) {\n      \
    \  Line line(a, b);\n        node_r -= len;\n        add(&line, --r, node_r, node_r\
    \ + len);\n      }\n    }\n  }\n\n  T query(const T x) const {\n    int node =\
    \ n + std::distance(xs.begin(),\n                                 std::lower_bound(xs.begin(),\
    \ xs.end(), x));\n    T res = dat[node].f(x);\n    while (node >>= 1) {\n    \
    \  if (dat[node].f(x) < res) res = dat[node].f(x);\n    }\n    return IS_MINIMIZED\
    \ ? res : -res;\n  }\n\n private:\n  int n;\n  std::vector<T> xs;\n  std::vector<Line>\
    \ dat;\n\n  void add(Line* line, int node, int left, int right) {\n    const bool\
    \ flag_l = dat[node].f(xs[left]) <= line->f(xs[left]);\n    const bool flag_r\
    \ = dat[node].f(xs[right - 1]) <= line->f(xs[right - 1]);\n    if (flag_l && flag_r)\
    \ return;\n    if (!flag_l && !flag_r) {\n      std::swap(dat[node], *line);\n\
    \      return;\n    }\n    const int mid = std::midpoint(left, right);\n    if\
    \ (line->f(xs[mid]) < dat[node].f(xs[mid])) std::swap(dat[node], *line);\n   \
    \ if (line->f(xs[left]) <= dat[node].f(xs[left])) {\n      add(line, node << 1,\
    \ left, mid);\n    } else {\n      add(line, (node << 1) + 1, mid, right);\n \
    \   }\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"test/dynamic_programming/li_chao_tree.2.test.cpp\"\
    \n\nint main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  int n,\
    \ q;\n  std::cin >> n >> q;\n  std::vector<int> query(q), l(n + q), r(n + q),\
    \ a(n + q), p(q);\n  std::vector<long long> b(n + q), xs;\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\n  }\n  for (int\
    \ i = 0; i < q; ++i) {\n    std::cin >> query[i];\n    if (query[i] == 0) {\n\
    \      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];\n    } else if\
    \ (query[i] == 1) {\n      std::cin >> p[i];\n      xs.emplace_back(p[i]);\n \
    \   }\n  }\n  if (xs.empty()) return 0;\n  emthrm::LiChaoTree<long long, false>\
    \ li_chao_tree(xs, LINF);\n  for (int i = 0; i < n; ++i) {\n    li_chao_tree.add(-a[i],\
    \ -b[i], l[i], r[i]);\n  }\n  for (int i = 0; i < q; ++i) {\n    if (query[i]\
    \ == 0) {\n      li_chao_tree.add(-a[n + i], -b[n + i], l[n + i], r[n + i]);\n\
    \    } else if (query[i] == 1) {\n      const long long ans = -li_chao_tree.query(p[i]);\n\
    \      if (ans == LINF) {\n        std::cout << \"INFINITY\\n\";\n      } else\
    \ {\n        std::cout << ans << '\\n';\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024\
    )\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/segment_add_get_min\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/li_chao_tree.hpp\"\
    \n\nint main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  int n,\
    \ q;\n  std::cin >> n >> q;\n  std::vector<int> query(q), l(n + q), r(n + q),\
    \ a(n + q), p(q);\n  std::vector<long long> b(n + q), xs;\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\n  }\n  for (int\
    \ i = 0; i < q; ++i) {\n    std::cin >> query[i];\n    if (query[i] == 0) {\n\
    \      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];\n    } else if\
    \ (query[i] == 1) {\n      std::cin >> p[i];\n      xs.emplace_back(p[i]);\n \
    \   }\n  }\n  if (xs.empty()) return 0;\n  emthrm::LiChaoTree<long long, false>\
    \ li_chao_tree(xs, LINF);\n  for (int i = 0; i < n; ++i) {\n    li_chao_tree.add(-a[i],\
    \ -b[i], l[i], r[i]);\n  }\n  for (int i = 0; i < q; ++i) {\n    if (query[i]\
    \ == 0) {\n      li_chao_tree.add(-a[n + i], -b[n + i], l[n + i], r[n + i]);\n\
    \    } else if (query[i] == 1) {\n      const long long ans = -li_chao_tree.query(p[i]);\n\
    \      if (ans == LINF) {\n        std::cout << \"INFINITY\\n\";\n      } else\
    \ {\n        std::cout << ans << '\\n';\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/li_chao_tree.hpp
  isVerificationFile: true
  path: test/dynamic_programming/li_chao_tree.2.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/li_chao_tree.2.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/li_chao_tree.2.test.cpp
- /verify/test/dynamic_programming/li_chao_tree.2.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5927\u5024)"
---
