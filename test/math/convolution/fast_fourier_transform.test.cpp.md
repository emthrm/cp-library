---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\
      \u30EA\u30A8\u5909\u63DB"
    links:
    - https://atcoder.jp/contests/atc001/tasks/fft_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/fast_fourier_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\n */\n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/atc001/tasks/fft_c\"\
    \n\n#include <cmath>\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/convolution/fast_fourier_transform.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n + 1, 0),\
    \ b(n + 1, 0);\n  for (int i = 1; i <= n; ++i) {\n    std::cin >> a[i] >> b[i];\n\
    \  }\n  const std::vector<emthrm::fast_fourier_transform::Real> ans =\n      emthrm::fast_fourier_transform::convolution(a,\
    \ b);\n  for (int i = 1; i <= n * 2; ++i) {\n    std::cout << std::llround(ans[i])\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_fourier_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_fourier_transform.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/convolution/fast_fourier_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_fourier_transform.test.cpp
- /verify/test/math/convolution/fast_fourier_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\
  \u5909\u63DB"
---
