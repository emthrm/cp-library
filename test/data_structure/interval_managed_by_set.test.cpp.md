---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/inverval_managed_by_set.hpp:\
    \ line -1: no such header\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/\u533A\u9593\u3092 std::set \u3067\u7BA1\
    \u7406\u3059\u308B\u3084\u3064\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2880\"\
    \r\n\r\n#include <algorithm>\r\n#include <iostream>\r\n#include <numeric>\r\n\
    #include <vector>\r\n\r\n#include \"../../data_structure/inverval_managed_by_set.hpp\"\
    \r\n\r\nint main() {\r\n  int n, m, q;\r\n  std::cin >> n >> m >> q;\r\n  std::vector<int>\
    \ d(m), a(m), b(m), e(q), s(q), t(q);\r\n  for (int i = 0; i < m; ++i) {\r\n \
    \   std::cin >> d[i] >> a[i] >> b[i];\r\n  }\r\n  for (int i = 0; i < q; ++i)\
    \ {\r\n    std::cin >> e[i] >> s[i] >> t[i];\r\n  }\r\n  std::vector<int> order(m\
    \ + q);\r\n  std::iota(order.begin(), order.end(), 0);\r\n  std::sort(order.begin(),\
    \ order.end(), [m, &d, &e](const int a, const int b) {\r\n    const int t_a =\
    \ (a < m ? d[a] : e[a - m]), t_b = (b < m ? d[b] : e[b - m]);\r\n    return t_a\
    \ != t_b ? t_a < t_b : (a < m) < (b < m);\r\n  });\r\n  std::vector<bool> ans(q,\
    \ false);\r\n  IntervalManagedBySet<int> intervals;\r\n  for (int i : order) {\r\
    \n    if (i < m) {\r\n      intervals.insert(a[i], b[i] - 1);\r\n    } else {\r\
    \n      i -= m;\r\n      ans[i] = s[i] >= t[i] || intervals.contains(s[i], t[i]\
    \ - 1);\r\n    }\r\n  }\r\n  for (int i = 0; i < q; ++i) {\r\n    std::cout <<\
    \ (ans[i] ? \"Yes\\n\" : \"No\\n\");\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/data_structure/interval_managed_by_set.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/interval_managed_by_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/interval_managed_by_set.test.cpp
- /verify/test/data_structure/interval_managed_by_set.test.cpp.html
title: test/data_structure/interval_managed_by_set.test.cpp
---
