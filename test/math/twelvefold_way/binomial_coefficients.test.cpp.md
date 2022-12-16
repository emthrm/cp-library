---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/117
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570"
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570\n\
    \ */\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <iterator>\n#include <string>\n\n#include \"emthrm/math/modint.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<0>;\n  ModInt::set_mod(1000000007);\n\
    \  int t;\n  std::cin >> t;\n  while (t--) {\n    std::string s;\n    std::cin\
    \ >> s;\n    const auto it = std::find(s.begin(), s.end(), ',');\n    const int\
    \ n = std::stoi(std::string(std::next(s.begin(), 2), it));\n    const int k =\
    \ std::stoi(std::string(std::next(it), std::prev(s.end())));\n    if (s.front()\
    \ == 'C') {\n      std::cout << ModInt::nCk(n, k) << '\\n';\n    } else if (s.front()\
    \ == 'P') {\n      std::cout << ModInt::nPk(n, k) << '\\n';\n    } else if (s.front()\
    \ == 'H') {\n      std::cout << ModInt::nHk(n, k) << '\\n';\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/binomial_coefficients.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/binomial_coefficients.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/binomial_coefficients.test.cpp
- /verify/test/math/twelvefold_way/binomial_coefficients.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u4E8C\u9805\u4FC2\u6570"
---
