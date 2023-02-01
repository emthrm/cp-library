---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/fast_mobius_transform.hpp
    title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-7
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/convolution/fast_mobius_transform.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\"\
    \n#define ERROR \"1e-7\"\n\n#include <cmath>\n#include <iomanip>\n#include <iostream>\n\
    #if __cplusplus >= 201703L\n# include <numeric>\n#else\n# include <algorithm>\n\
    #endif  // __cplusplus >= 201703L\n#include <vector>\n\n#include \"emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\nint main() {\n  int n;\n  long long m;\n  std::cin >> n >> m;\n  std::vector<long\
    \ long> a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n \
    \ std::vector<double> p(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >>\
    \ p[i];\n    p[i] /= 100;\n  }\n  std::vector<long long> g(1 << n, 0);\n  for\
    \ (int i = 1; i < (1 << n); ++i) {\n    long long l = 1;\n    for (int j = 0;\
    \ j < n; ++j) {\n      if (i >> j & 1) {\n#if __cplusplus >= 201703L\n       \
    \ l /= std::gcd(l, a[j]);\n#else\n        l /= std::__gcd(l, a[j]);\n#endif  //\
    \ __cplusplus >= 201703L\n        if (l > m / a[j]) {\n          l = m + 1;\n\
    \          break;\n        }\n        l *= a[j];\n      }\n    }\n    g[i] = m\
    \ / l;\n  }\n  g = emthrm::fast_mobius_transform(g, false);\n  double ans = 0;\n\
    \  for (int bit = 0; bit < (1 << n); ++bit) {\n    double prob = 1;\n    for (int\
    \ i = 0; i < n; ++i) {\n      prob *= (bit >> i & 1 ? p[i] : 1 - p[i]);\n    }\n\
    \    ans += prob * std::abs(g[bit]);\n  }\n  std::cout << std::fixed << std::setprecision(8)\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_mobius_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_mobius_transform.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/fast_mobius_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_mobius_transform.test.cpp
- /verify/test/math/convolution/fast_mobius_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\
  \u5909\u63DB"
---
