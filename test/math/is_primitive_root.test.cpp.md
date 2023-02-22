---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/is_primitive_root.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A\n */\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1409\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <numeric>\n#include <random>\n#include <vector>\n\n#include\
    \ \"emthrm/math/is_primitive_root.hpp\"\n#include \"emthrm/math/mod_pow.hpp\"\n\
    \nint main() {\n  int t;\n  std::cin >> t;\n  std::mt19937_64 engine(std::random_device\
    \ {} ());\n  while (t--) {\n    int v, x;\n    std::cin >> v >> x;\n    const\
    \ int p = v * x + 1;\n    std::uniform_int_distribution<int> dist(1, p - 1);\n\
    \    int root = 0;\n    do {\n      root = dist(engine);\n    } while (!emthrm::is_primitive_root(root,\
    \ p));\n    std::vector<int> a(x, emthrm::mod_pow(root, v, p));\n    a.front()\
    \ = 1;\n    std::partial_sum(\n        a.begin(), a.end(), a.begin(),\n      \
    \  [p](const int l, const int r) -> int { return l * r % p; });\n    std::sort(a.begin(),\
    \ a.end());\n    for (int i = 0; i < x; ++i) {\n      std::cout << a[i] << \"\
    \ \\n\"[i + 1 == x];\n    }\n  }\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/math/is_primitive_root.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/is_primitive_root.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_primitive_root.test.cpp
- /verify/test/math/is_primitive_root.test.cpp.html
title: test/math/is_primitive_root.test.cpp
---
