---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/rational.hpp
    title: "\u6709\u7406\u6570 (rational number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
    document_title: "\u6570\u5B66/\u6709\u7406\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/rational.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u6709\u7406\u6570\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2589\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/math/rational.hpp\"\n\nint main() {\n \
    \ using rational = emthrm::Rational<>;\n  constexpr int OCCURRENCE = 20;\n  int\
    \ p[OCCURRENCE + 1]{};\n  std::fill(p, p + (OCCURRENCE + 1), 1);\n  for (int i\
    \ = 1; i <= OCCURRENCE; ++i) {\n    p[i] = p[i - 1] * 2;\n  }\n  while (true)\
    \ {\n    std::string s;\n    std::cin >> s;\n    if (s == \"#\") break;\n    const\
    \ int n = s.length();\n    std::vector<int> dir;\n    for (int i = 0; i < n;)\
    \ {\n      if (s[i] == 'n') {\n        dir.emplace_back(0);\n        i += 5;\n\
    \      } else {\n        dir.emplace_back(90);\n        i += 4;\n      }\n   \
    \ }\n    std::reverse(dir.begin(), dir.end());\n    rational ans = dir.front();\n\
    \    for (int i = 1; std::cmp_less(i, dir.size()); ++i) {\n      ans += rational(90,\
    \ p[i]) * (dir[i] == 0 ? -1 : 1);\n    }\n    std::cout << ans << '\\n';\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/rational.hpp
  isVerificationFile: true
  path: test/math/rational.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/rational.test.cpp
layout: document
redirect_from:
- /verify/test/math/rational.test.cpp
- /verify/test/math/rational.test.cpp.html
title: "\u6570\u5B66/\u6709\u7406\u6570"
---
