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
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024\
      )"
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/dynamic_programming/li_chao_tree.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024\
    )\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/li_chao_tree.hpp\"\
    \n\nint main() {\n  constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n  int n,\
    \ q;\n  std::cin >> n >> q;\n  std::vector<int> query(q), l(n + q), r(n + q),\
    \ a(n + q), p(q);\n  std::vector<long long> b(n + q), xs;\n  for (int i = 0; i\
    \ < n; ++i) {\n    std::cin >> l[i] >> r[i] >> a[i] >> b[i];\n  }\n  for (int\
    \ i = 0; i < q; ++i) {\n    std::cin >> query[i];\n    if (query[i] == 0) {\n\
    \      std::cin >> l[n + i] >> r[n + i] >> a[n + i] >> b[n + i];\n    } else if\
    \ (query[i] == 1) {\n      std::cin >> p[i];\n      xs.emplace_back(p[i]);\n \
    \   }\n  }\n  if (xs.empty()) return 0;\n  emthrm::LiChaoTree<long long> li_chao_tree(xs,\
    \ LINF);\n  for (int i = 0; i < n; ++i) {\n    li_chao_tree.add(a[i], b[i], l[i],\
    \ r[i]);\n  }\n  for (int i = 0; i < q; ++i) {\n    if (query[i] == 0) {\n   \
    \   li_chao_tree.add(a[n + i], b[n + i], l[n + i], r[n + i]);\n    } else if (query[i]\
    \ == 1) {\n      const long long ans = li_chao_tree.query(p[i]);\n      if (ans\
    \ == LINF) {\n        std::cout << \"INFINITY\\n\";\n      } else {\n        std::cout\
    \ << ans << '\\n';\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/li_chao_tree.hpp
  isVerificationFile: true
  path: test/dynamic_programming/li_chao_tree.1.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/li_chao_tree.1.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/li_chao_tree.1.test.cpp
- /verify/test/dynamic_programming/li_chao_tree.1.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/Li Chao tree (\u6700\u5C0F\u5024)"
---
