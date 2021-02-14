---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/partition_function_init.hpp
    title: "\u5206\u5272\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
    links:
    - https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/partition_function_init.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570\r\n\
    \ */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/modint.hpp\"\
    \r\n#include \"../../../math/twelvefold_way/partition_function_init.hpp\"\r\n\r\
    \nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\
    \n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<int> a, b;\r\n  int killa\
    \ = 0, killb = 0, same = 1;\r\n  int now;\r\n  std::cin >> now;\r\n  killa +=\
    \ now;\r\n  for (int i = 1; i < n; ++i) {\r\n    int tmp;\r\n    std::cin >> tmp;\r\
    \n    killa += tmp;\r\n    if (tmp == now) {\r\n      ++same;\r\n    } else {\r\
    \n      a.emplace_back(same);\r\n      same = 1;\r\n    }\r\n    now = tmp;\r\n\
    \  }\r\n  a.emplace_back(same);\r\n  std::cin >> now;\r\n  killb += now;\r\n \
    \ same = 1;\r\n  for (int i = 1; i < m; ++i) {\r\n    int tmp;\r\n    std::cin\
    \ >> tmp;\r\n    killb += tmp;\r\n    if (tmp == now) {\r\n      ++same;\r\n \
    \   } else {\r\n      b.emplace_back(same);\r\n      same = 1;\r\n    }\r\n  \
    \  now = tmp;\r\n  }\r\n  b.emplace_back(same);\r\n  std::vector<std::vector<ModInt>>\
    \ pf = partition_function_init<ModInt>(100, 1000);\r\n  std::vector<std::vector<ModInt>>\
    \ dpa(a.size() + 1, std::vector<ModInt>(killb + 1, 0));\r\n  for (int j = 0; j\
    \ <= killb; ++j) {\r\n    dpa[0][j] = 1;\r\n    dpa[1][j] = pf[a[0]][j];\r\n \
    \ }\r\n  for (int i = 1; i < a.size(); ++i) for (int j = 0; j <= killb; ++j) {\r\
    \n    for (int k = 0; k <= j; ++k) {\r\n      dpa[i + 1][j] += dpa[i][j - k] *\
    \ pf[a[i]][k];\r\n    }\r\n  }\r\n  std::vector<std::vector<ModInt>> dpb(b.size()\
    \ + 1, std::vector<ModInt>(killa + 1, 0));\r\n  for (int j = 0; j <= killa; ++j)\
    \ {\r\n    dpb[0][j] = 1;\r\n    dpb[1][j] = pf[b[0]][j];\r\n  }\r\n  for (int\
    \ i = 1; i < b.size(); ++i) for (int j = 0; j <= killa; ++j) {\r\n    for (int\
    \ k = 0; k <= j; ++k) {\r\n      dpb[i + 1][j] += dpb[i][j - k] * pf[b[i]][k];\r\
    \n    }\r\n  }\r\n  std::cout << dpa[a.size()][killb] * dpb[b.size()][killa] <<\
    \ '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/partition_function_init.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/partition_function_init.test.cpp
  requiredBy: []
  timestamp: '2021-02-15 03:05:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/partition_function_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/partition_function_init.test.cpp
- /verify/test/math/twelvefold_way/partition_function_init.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u5206\u5272\u6570"
---
