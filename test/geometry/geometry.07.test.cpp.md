---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
    \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2276\"\n#define ERROR\
    \ \"1e-6\"\n\n#include <algorithm>\n#include <iomanip>\n#include <iostream>\n\
    #include <limits>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    #include \"emthrm/geometry/geometry.hpp\"\n\nint main() {\n  int n, k;\n  std::cin\
    \ >> n >> k;\n  std::vector<emthrm::geometry::Circle> people(n);\n  for (int i\
    \ = 0; i < n; ++i) {\n    emthrm::geometry::Point p;\n    double r;\n    std::cin\
    \ >> p >> r;\n    people[i] = emthrm::geometry::Circle(p, r);\n  }\n  std::vector<double>\
    \ l(n), r(n), comp;\n  for (int i = 0; i < n; ++i) {\n    const std::vector<emthrm::geometry::Point>\
    \ t =\n        emthrm::geometry::tangency(people[i], emthrm::geometry::Point(0,\
    \ 0));\n    l[i] = t[0].arg();\n    r[i] = t[1].arg();\n    if (l[i] > r[i]) std::swap(l[i],\
    \ r[i]);\n    if (r[i] > emthrm::geometry::PI &&\n        emthrm::geometry::has_intersected(\n\
    \            people[i],\n            emthrm::geometry::Segment(emthrm::geometry::Point(0,\
    \ 0),\n                              emthrm::geometry::Point(2415, 0)))) {\n \
    \     std::swap(l[i], r[i]);\n      l[i] = 0;\n    } else {\n      if (l[i] <\
    \ 0) l[i] = 0;\n      if (r[i] > emthrm::geometry::PI) r[i] = emthrm::geometry::PI;\n\
    \    }\n    if (l[i] < emthrm::geometry::PI) {\n      comp.emplace_back(l[i]);\n\
    \      comp.emplace_back(r[i]);\n    }\n  }\n  std::vector<bool> is_used(n, true);\n\
    \  for (int i = 0; i < n; ++i) {\n    if (l[i] >= emthrm::geometry::PI) is_used[i]\
    \ = false;\n    if (!is_used[i]) continue;\n    for (int j = 0; j < n; ++j) {\n\
    \      if (j != i && l[i] <= l[j] && r[j] <= r[i]) is_used[j] = false;\n    }\n\
    \  }\n  std::vector<std::pair<double, double>> balls;\n  for (int i = 0; i < n;\
    \ ++i) {\n    if (is_used[i]) balls.emplace_back(l[i], r[i]);\n  }\n  n = balls.size();\n\
    \  if (n == 0) {\n    std::cout << 0 << '\\n';\n    return 0;\n  }\n  std::sort(balls.begin(),\
    \ balls.end());\n  std::vector<std::vector<std::vector<double>>> dp(n,\n     \
    \ std::vector<std::vector<double>>(k + 1,\n          std::vector<double>(2, std::numeric_limits<double>::lowest())));\n\
    \  dp[0][0][false] = 0;\n  dp[0][1][true] = balls[0].second - balls[0].first;\n\
    \  for (int i = 1; i < n; ++i) {\n    double left, right;\n    std::tie(left,\
    \ right) = balls[i];\n    int x = i - 1;\n    while (x >= 0 && balls[i].first\
    \ <= balls[x].second) --x;\n    ++x;\n    if (x > i - 1) x = i - 1;\n    for (int\
    \ j = 0; j <= k; ++j) {\n      if (j + 1 <= k) {\n        dp[i][j + 1][true] =\n\
    \            std::max(dp[i][j + 1][true],\n                     dp[x][j][true]\
    \ + right - std::max(balls[x].second, left));\n        dp[i][j + 1][true] =\n\
    \            std::max(dp[i][j + 1][true], dp[x][j][false] + right - left);\n \
    \     }\n      dp[i][j][false] =\n          std::max(dp[i][j][false],\n      \
    \             std::max(dp[i - 1][j][false], dp[i - 1][j][true]));\n    }\n  }\n\
    \  double ans = 0;\n  for (int y = 0; y <= k; ++y) {\n    for (int z = 0; z <\
    \ 2; ++z) {\n      if (dp[n - 1][y][z] > ans) ans = dp[n - 1][y][z];\n    }\n\
    \  }\n  std::cout << std::fixed << std::setprecision(7)\n            << ans /\
    \ emthrm::geometry::PI << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.07.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.07.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.07.test.cpp
- /verify/test/geometry/geometry.07.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\
  \u3068\u5186\u306E\u4EA4\u5DEE\u5224\u5B9A)"
---
