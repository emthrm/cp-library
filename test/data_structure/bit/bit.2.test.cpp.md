---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/bit/bit.hpp
    title: binary indexed tree
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
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/BIT/binary indexed tree (lower_bound(val))"
    links:
    - https://atcoder.jp/contests/arc033/tasks/arc033_3
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.4/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/bit/bit.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/BIT/binary indexed tree (lower_bound(val))\r\
    \n */\r\n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc033/tasks/arc033_3\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/bit/bit.hpp\"\
    \r\n\r\nint main() {\r\n  BIT<int> bit(200001);\r\n  int q;\r\n  std::cin >> q;\r\
    \n  while (q--) {\r\n    int t, x;\r\n    std::cin >> t >> x;\r\n    if (t ==\
    \ 1) {\r\n      bit.add(x, 1);\r\n    } else if (t == 2) {\r\n      int ans =\
    \ bit.lower_bound(x);\r\n      std::cout << ans << '\\n';\r\n      bit.add(ans,\
    \ -1);\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/bit/bit.hpp
  isVerificationFile: true
  path: test/data_structure/bit/bit.2.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/data_structure/bit/bit.2.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/bit/bit.2.test.cpp
- /verify/test/data_structure/bit/bit.2.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/BIT/binary indexed tree (lower_bound(val))"
---
