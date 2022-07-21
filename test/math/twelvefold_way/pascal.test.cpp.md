---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  - icon: ':x:'
    path: math/twelvefold_way/pascal.hpp
    title: "\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/420
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
      \u4E09\u89D2\u5F62"
    links:
    - https://yukicoder.me/problems/no/420
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/pascal.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\
    \u4E09\u89D2\u5F62\n */\n#define PROBLEM \"https://yukicoder.me/problems/no/420\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../math/bigint.hpp\"\
    \n#include \"../../../math/twelvefold_way/pascal.hpp\"\n\nint main() {\n  using\
    \ bigint = BigInt<>;\n  constexpr int B = 31;\n  const std::vector<std::vector<bigint>>\
    \ c = pascal<bigint>(B);\n  int x;\n  std::cin >> x;\n  if (x == 0) {\n    std::cout\
    \ << 1 << ' ' << 0 << '\\n';\n  } else if (x > B) {\n    std::cout << 0 << ' '\
    \ << 0 << '\\n';\n  } else {\n    std::cout << c[B][x] << ' ';\n    bigint ans\
    \ = 0;\n    for (int b = 0; b < B; ++b) {\n      ans += c[B - 1][x - 1] * (1 <<\
    \ b);\n    }\n    std::cout << ans << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - math/bigint.hpp
  - math/twelvefold_way/pascal.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/pascal.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/pascal.test.cpp
- /verify/test/math/twelvefold_way/pascal.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\
  \u5F62"
---
