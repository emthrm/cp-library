---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/smallest_enclosing_circle.test.cpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u6700\u5C0F\u5305\u542B\u5186"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/geometry/geometry.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_\n#define EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_\n\
    \n#include <algorithm>\n#include <random>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/geometry/geometry.hpp\"\n\nnamespace emthrm {\n\nnamespace\
    \ geometry {\n\nCircle smallest_enclosing_circle(std::vector<Point> ps) {\n  const\
    \ int n = ps.size();\n  if (n == 1) return Circle(ps.front(), 0);\n  std::shuffle(ps.begin(),\
    \ ps.end(), std::mt19937_64(std::random_device {} ()));\n  const auto get_circle\
    \ = [](const Point& p1, const Point& p2) -> Circle {\n    return Circle((p1 +\
    \ p2) * 0.5, distance(p1, p2) * 0.5);\n  };\n  Circle res = get_circle(ps[0],\
    \ ps[1]);\n  const auto is_in = [&res](const Point& p) -> bool {\n    return sgn(res.r\
    \ - distance(res.p, p)) != -1;\n  };\n  for (int i = 2; i < n; ++i) {\n    if\
    \ (is_in(ps[i])) continue;\n    res = get_circle(ps[0], ps[i]);\n    for (int\
    \ j = 1; j < i; ++j) {\n      if (is_in(ps[j])) continue;\n      res = get_circle(ps[j],\
    \ ps[i]);\n      for (int k = 0; k < j; ++k) {\n        if (is_in(ps[k])) continue;\n\
    \        const double a = (ps[i] - ps[j]).norm(), b = (ps[k] - ps[i]).norm();\n\
    \        const double c = (ps[j] - ps[k]).norm();\n        const double s = cross(ps[i]\
    \ - ps[k], ps[j] - ps[k]);\n        const Point p = (ps[k] * a * (b + c - a) +\
    \ ps[j] * b * (c + a - b)\n                         + ps[i] * c * (a + b - c))\
    \ / (4 * s * s);\n        res = Circle(p, distance(ps[k], p));\n      }\n    }\n\
    \  }\n  return res;\n}\n\n}  // namespace geometry\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_GEOMETRY_SMALLEST_ENCLOSING_CIRCLE_HPP_\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: false
  path: include/emthrm/geometry/smallest_enclosing_circle.hpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/smallest_enclosing_circle.test.cpp
documentation_of: include/emthrm/geometry/smallest_enclosing_circle.hpp
layout: document
title: "\u6700\u5C0F\u5305\u542B\u5186 (smallest enclosing circle)"
---

与えられた点集合に属するすべての点を内部または円周上に含む円の内、半径最小のものである。


## 時間計算量

expected $O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`geometry::Circle geometry::smallest_enclosing_circle(std::vector<Point> ps);`|点集合 $\mathrm{ps}$ の最小包含円|


## 参考文献

- https://www.jaist.ac.jp/~uehara/course/2014/i481f/pdf/ppt-7.pdf
- https://tubo28.me/compprog/algorithm/minball/
- http://nonoishi.web.fc2.com/math/fivecenters.pdf


## Submissons

- https://atcoder.jp/contests/abc151/submissions/11968904
