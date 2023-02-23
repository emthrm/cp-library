---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/segmented_sieve.hpp
    title: segmented sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/segmented sieve"
    links:
    - https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/segmented_sieve.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/segmented sieve\n */\n#define IGNORE\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_bt\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#include \"emthrm/math/segmented_sieve.hpp\"\
    \n\nint main() {\n  long long l, r;\n  std::cin >> l >> r;\n  std::cout << std::ranges::count(emthrm::segmented_sieve(l,\
    \ r + 1), true)\n            << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/segmented_sieve.hpp
  isVerificationFile: true
  path: test/math/segmented_sieve.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/segmented_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/math/segmented_sieve.test.cpp
- /verify/test/math/segmented_sieve.test.cpp.html
title: "\u6570\u5B66/segmented sieve"
---
