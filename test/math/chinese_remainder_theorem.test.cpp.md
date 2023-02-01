---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/chinese_remainder_theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406 (Chinese remainder theorem)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/mod_inv.hpp
    title: "\u9006\u5143 (inverse element)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/186
    document_title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
    links:
    - https://yukicoder.me/problems/no/186
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/chinese_remainder_theorem.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n */\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/186\"\n\n#include <iostream>\n#if\
    \ __cplusplus < 201703L\n# include <tuple>\n#endif  // __cplusplus < 201703L\n\
    #include <vector>\n\n#include \"emthrm/math/chinese_remainder_theorem.hpp\"\n\n\
    int main() {\n  constexpr int N = 3;\n  std::vector<long long> x(N), y(N);\n \
    \ for (int i = 0; i < N; ++i) {\n    std::cin >> x[i] >> y[i];\n  }\n#if __cplusplus\
    \ >= 201703L\n  const auto [ans, mod] = emthrm::chinese_remainder_theorem(x, y);\n\
    #else\n  long long ans, mod;\n  std::tie(ans, mod) = emthrm::chinese_remainder_theorem(x,\
    \ y);\n#endif  // __cplusplus >= 201703L\n  if (mod == 0) {\n    std::cout <<\
    \ \"-1\\n\";\n  } else {\n    std::cout << (ans == 0 ? mod : ans) << '\\n';\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/chinese_remainder_theorem.hpp
  - include/emthrm/math/mod_inv.hpp
  isVerificationFile: true
  path: test/math/chinese_remainder_theorem.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/chinese_remainder_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/math/chinese_remainder_theorem.test.cpp
- /verify/test/math/chinese_remainder_theorem.test.cpp.html
title: "\u6570\u5B66/\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
