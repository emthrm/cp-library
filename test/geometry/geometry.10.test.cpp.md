---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/geometry/geometry.hpp
    title: "\u8A08\u7B97\u5E7E\u4F55\u5B66 (computational geometry)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316
    document_title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66\
      \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u70B9)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316
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
    \ (\u7DDA\u5206\u3068\u5186\u306E\u4EA4\u70B9)\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2316\"\
    \n\n#include <algorithm>\n#include <cmath>\n#include <iostream>\n#include <numbers>\n\
    #include <string>\n#include <vector>\n\n#include \"emthrm/geometry/geometry.hpp\"\
    \n\nint main() {\n  constexpr double EPS = 1e-8;\n  int n, a, b;\n  std::cin >>\
    \ n >> a >> b;\n  std::vector<emthrm::geometry::Point> flo(n);\n  for (int i =\
    \ 0; i < n; ++i) {\n    std::cin >> flo[i];\n  }\n  emthrm::geometry::Point wheel\
    \ =\n      emthrm::geometry::intersection(\n          emthrm::geometry::Segment(emthrm::geometry::Point(a,\
    \ 0),\n                                    emthrm::geometry::Point(a, 200)),\n\
    \          emthrm::geometry::Segment(flo[0], flo[1]))\n      + emthrm::geometry::unit_vector(flo[1]\
    \ - flo[0]);\n  int ans = 0;\n  for (int i = 0; i + 2 < n; ++i) {\n    const double\
    \ sta = std::atan2((flo[i + 1] - flo[i]).y,\n                                \
    \  (flo[i + 1] - flo[i]).x);\n    while (true) {\n      int type = 0;\n      emthrm::geometry::Point\
    \ p;\n      bool must_skip = false;\n      for (int j = i + 1; j <= i + 2 && j\
    \ + 1 < n; ++j) {\n        for (const emthrm::geometry::Point& inter :\n     \
    \        emthrm::geometry::intersection(\n                 emthrm::geometry::Circle(wheel,\
    \ 1),\n                 emthrm::geometry::Segment(flo[j], flo[j + 1]))) {\n  \
    \        const double ar =\n              std::atan2((inter - wheel).y, (inter\
    \ - wheel).x) - sta;\n          if (-EPS < ar && ar < std::numbers::pi / 2 + EPS)\
    \ {\n            if (type == 0) {\n              type = 1;\n              p =\
    \ inter;\n              must_skip = j > i + 1;\n            } else if (type ==\
    \ 1) {\n              if (ar > std::atan2((p - wheel).y, (p - wheel).x) - sta)\
    \ {\n                p = inter;\n                must_skip = j > i + 1;\n    \
    \          }\n            }\n          }\n        }\n      }\n      for (int j\
    \ = i + 1; j <= i + 2 && j + 1 < n; ++j) {\n        for (const emthrm::geometry::Point&\
    \ inter :\n             emthrm::geometry::intersection(\n                 emthrm::geometry::Circle(wheel,\
    \ std::sqrt(2)),\n                 emthrm::geometry::Segment(flo[j], flo[j + 1])))\
    \ {\n          const double ar =\n              std::atan2((inter - wheel).y,\
    \ (inter - wheel).x) - sta;\n          if (std::numbers::pi / 4 - EPS < ar &&\n\
    \              ar < std::numbers::pi / 4 * 3 + EPS) {\n            if (type ==\
    \ 0) {\n              type = 2;\n              p = inter;\n              must_skip\
    \ = j > i + 1;\n            } else if (type == 1) {\n              if (ar - std::numbers::pi\
    \ / 4\n                  > std::atan2((p - wheel).y, (p - wheel).x) - sta) {\n\
    \                type = 2;\n                p = inter;\n                must_skip\
    \ = j > i + 1;\n              }\n            } else if (type == 2) {\n       \
    \       if (ar > std::atan2((p - wheel).y, (p - wheel).x) - sta) {\n         \
    \       p = inter;\n                must_skip = j > i + 1;\n              }\n\
    \            }\n          }\n        }\n      }\n      ans = (ans + std::max(type,\
    \ 1)) % 4;\n      if (type == 0) {\n        wheel += emthrm::geometry::unit_vector(flo[i\
    \ + 1] - flo[i]);\n      } else {\n        wheel = p;\n        i += must_skip;\n\
    \        break;\n      }\n    }\n  }\n  while (wheel.x <= b) {\n    wheel += emthrm::geometry::unit_vector(flo[n\
    \ - 1] - flo[n - 2]);\n    ans = (ans + 1) % 4;\n  }\n  std::cout << std::vector<std::string>{\"\
    Red\", \"Green\", \"Blue\", \"White\"}[ans]\n            << '\\n';\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/geometry/geometry.hpp
  isVerificationFile: true
  path: test/geometry/geometry.10.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/geometry.10.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/geometry.10.test.cpp
- /verify/test/geometry/geometry.10.test.cpp.html
title: "\u8A08\u7B97\u5E7E\u4F55\u5B66/\u8A08\u7B97\u5E7E\u4F55\u5B66 (\u7DDA\u5206\
  \u3068\u5186\u306E\u4EA4\u70B9)"
---
