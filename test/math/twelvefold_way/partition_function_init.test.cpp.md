---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/twelvefold_way/partition_function.hpp
    title: "\u5206\u5272\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/269
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
    links:
    - https://yukicoder.me/problems/no/269
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/modint.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570\n */\n\
    #define PROBLEM \"https://yukicoder.me/problems/no/269\"\n\n#include <iostream>\n\
    \n#include \"emthrm/math/modint.hpp\"\n#include \"emthrm/math/twelvefold_way/partition_function.hpp\"\
    \n\nint main() {\n  using ModInt = emthrm::MInt<1000000007>;\n  int n, s, k;\n\
    \  std::cin >> n >> s >> k;\n  for (int i = 1; i < n; ++i) {\n    s -= k * i;\n\
    \  }\n  std::cout << (s >= 0 ? emthrm::partition_function<ModInt>(n, s)[n][s]\
    \ : 0)\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/modint.hpp
  - include/emthrm/math/twelvefold_way/partition_function.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/partition_function_init.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 16:05:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/partition_function_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/partition_function_init.test.cpp
- /verify/test/math/twelvefold_way/partition_function_init.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
---
