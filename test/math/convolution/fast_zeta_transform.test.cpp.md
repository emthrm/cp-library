---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/math/convolution/fast_zeta_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc100/tasks/arc100_e
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
      \u30BF\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/arc100/tasks/arc100_c
    - https://atcoder.jp/contests/arc100/tasks/arc100_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/fast_zeta_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\
    \u30BF\u5909\u63DB\n */\n#define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_e\"\
    \n// #define PROBLEM \"https://atcoder.jp/contests/arc100/tasks/arc100_c\"\n\n\
    #include <algorithm>\n#include <functional>\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::pair<int, int>>\
    \ a(1 << n, {0, 0});\n  for (int i = 0; i < (1 << n); ++i) {\n    std::cin >>\
    \ a[i].first;\n  }\n  const std::function<std::pair<int, int>(const std::pair<int,\
    \ int>&,\n                                          const std::pair<int, int>&)>\
    \ max =\n      [](const std::pair<int, int>& a, const std::pair<int, int>& b)\n\
    \          -> std::pair<int, int> {\n        int tmp[]{a.first, a.second, b.first,\
    \ b.second};\n        std::sort(tmp, tmp + 4, std::greater<int>());\n        return\
    \ {tmp[0], tmp[1]};\n      };\n  a = emthrm::fast_zeta_transform(a, false, {0,\
    \ 0}, max);\n  std::vector<int> ans(1 << n);\n  for (int i = 0; i < (1 << n);\
    \ ++i) {\n    ans[i] = a[i].first + a[i].second;\n  }\n  for (int i = 1; i < (1\
    \ << n); ++i) {\n    ans[i] = std::max(ans[i], ans[i - 1]);\n    std::cout <<\
    \ ans[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_zeta_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_zeta_transform.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/fast_zeta_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_zeta_transform.test.cpp
- /verify/test/math/convolution/fast_zeta_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\
  \u63DB"
---
