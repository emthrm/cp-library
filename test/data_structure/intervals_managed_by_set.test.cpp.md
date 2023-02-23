---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/intervals_managed_by_set.hpp
    title: "\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set \u3067\
      \u7BA1\u7406\u3059\u308B\u3084\u3064"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/intervals_managed_by_set.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set\
    \ \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n#include <vector>\n\
    \n#include \"emthrm/data_structure/intervals_managed_by_set.hpp\"\n\nint main()\
    \ {\n  int n, m, q;\n  std::cin >> n >> m >> q;\n  std::vector<int> d(m), a(m),\
    \ b(m), e(q), s(q), t(q);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> d[i]\
    \ >> a[i] >> b[i];\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cin >> e[i]\
    \ >> s[i] >> t[i];\n  }\n  std::vector<int> order(m + q);\n  std::iota(order.begin(),\
    \ order.end(), 0);\n  std::sort(order.begin(), order.end(), [m, &d, &e](const\
    \ int a, const int b) {\n    const int t_a = (a < m ? d[a] : e[a - m]), t_b =\
    \ (b < m ? d[b] : e[b - m]);\n    return t_a != t_b ? t_a < t_b : (a < m) < (b\
    \ < m);\n  });\n  std::vector<bool> ans(q, false);\n  emthrm::IntervalsManagedBySet<int>\
    \ intervals;\n  for (int i : order) {\n    if (i < m) {\n      intervals.insert(a[i],\
    \ b[i] - 1);\n    } else {\n      i -= m;\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i],\
    \ t[i] - 1);\n    }\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << (ans[i]\
    \ ? \"Yes\\n\" : \"No\\n\");\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/intervals_managed_by_set.hpp
  isVerificationFile: true
  path: test/data_structure/intervals_managed_by_set.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/intervals_managed_by_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/intervals_managed_by_set.test.cpp
- /verify/test/data_structure/intervals_managed_by_set.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u533A\u9593\u3092 std::set \u3067\u7BA1\u7406\
  \u3059\u308B\u3084\u3064"
---
