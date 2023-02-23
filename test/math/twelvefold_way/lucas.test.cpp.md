---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: include/emthrm/math/twelvefold_way/lucas.hpp
    title: "Lucas \u306E\u5B9A\u7406 (Lucas's theorem)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc117/tasks/arc117_c
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
    links:
    - https://atcoder.jp/contests/arc117/tasks/arc117_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406\n\
    \ */\n#define PROBLEM \"https://atcoder.jp/contests/arc117/tasks/arc117_c\"\n\n\
    #include <iostream>\n#include <map>\n#include <string>\n\n#include \"emthrm/math/modint.hpp\"\
    \n#include \"emthrm/math/twelvefold_way/lucas.hpp\"\n\nint main() {\n  constexpr\
    \ int C = 3;\n  using ModInt = emthrm::MInt<C>;\n  const std::string color = \"\
    BWR\";\n  std::map<char, int> mp;\n  for (int i = 0; i < C; ++i) {\n    mp[color[i]]\
    \ = i;\n  }\n  int n;\n  std::cin >> n;\n  std::string c;\n  std::cin >> c;\n\
    \  ModInt ans = 0;\n  for (int i = 0; i < n; ++i) {\n    ans += emthrm::lucas<C>(n\
    \ - 1, i) * mp[c[i]];\n  }\n  if (n % 2 == 0) ans = -ans;\n  std::cout << color[ans.v]\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/twelvefold_way/lucas.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/lucas.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/lucas.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/lucas.test.cpp
- /verify/test/math/twelvefold_way/lucas.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/Lucas \u306E\u5B9A\u7406"
---
