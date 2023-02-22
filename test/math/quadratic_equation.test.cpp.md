---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/quadratic_equation.hpp
    title: "\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F (quadratic equation)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1039
    document_title: "\u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1039
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F\n */\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1039\"\
    \n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n#if __cplusplus\
    \ < 201703L\n# include <tuple>\n#endif  // __cplusplus < 201703L\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/geometry/geometry.hpp\"\n#include \"emthrm/math/quadratic_equation.hpp\"\
    \n\nint main() {\n  constexpr double EPS = 1e-8;\n  constexpr int INF = 0x3f3f3f3f;\n\
    \  while (true) {\n    int n, m;\n    std::cin >> n >> m;\n    if (n == 0 && m\
    \ == 0) break;\n    std::vector<std::pair<emthrm::geometry::Point, double>> dog;\n\
    \    for (int i = 0; i < n; ++i) {\n      emthrm::geometry::Point d;\n      double\
    \ v;\n      std::cin >> d >> v;\n      dog.emplace_back(d, v);\n    }\n    std::vector<int>\
    \ ans(n, 0);\n    while (m--) {\n      emthrm::geometry::Point fp, fv;\n     \
    \ std::cin >> fp >> fv;\n      std::vector<double> t(n, INF);\n      for (int\
    \ i = 0; i < n; ++i) {\n#if __cplusplus >= 201703L\n        const auto [d, v]\
    \ = dog[i];\n#else\n        emthrm::geometry::Point d;\n        double v;\n  \
    \      std::tie(d, v) = dog[i];\n#endif  // __cplusplus >= 201703L\n        for\
    \ (std::vector<double> ans =\n                 emthrm::quadratic_equation(fv.norm()\
    \ - v * v,\n                                    emthrm::geometry::dot(fp - d,\
    \ fv) * 2,\n                                    (fp - d).norm());\n          \
    \   !ans.empty(); ans.pop_back()) {\n          if (ans.back() >= 0) t[i] = ans.back();\n\
    \        }\n      }\n      const double frisbee = *std::min_element(t.begin(),\
    \ t.end());\n      for (int i = 0; i < n; ++i) {\n        if (std::abs(t[i] -\
    \ INF) < EPS) continue;\n        if (std::abs(frisbee - t[i]) < EPS) ++ans[i];\n\
    \        const emthrm::geometry::Point cat = fp + fv * t[i];\n        dog[i].first\
    \ += (cat - dog[i].first) * frisbee / t[i];\n      }\n    }\n    for (int i =\
    \ 0; i < n; ++i) {\n      std::cout << ans[i] << \" \\n\"[i + 1 == n];\n    }\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  - include/emthrm/math/quadratic_equation.hpp
  isVerificationFile: true
  path: test/math/quadratic_equation.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/quadratic_equation.test.cpp
layout: document
redirect_from:
- /verify/test/math/quadratic_equation.test.cpp
- /verify/test/math/quadratic_equation.test.cpp.html
title: "\u6570\u5B66/\u4E00\u5143\u4E8C\u6B21\u65B9\u7A0B\u5F0F"
---
