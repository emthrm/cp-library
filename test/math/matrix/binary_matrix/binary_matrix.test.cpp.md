---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/binary_matrix/binary_matrix.hpp
    title: "\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
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
    document_title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
      /\u30D0\u30A4\u30CA\u30EA\u884C\u5217"
    links:
    - http://kmjp.hatenablog.jp/entry/2015/05/28/0900
    - http://sonickun.hatenablog.com/entry/2016/11/20/192743
    - https://atcoder.jp/contests/utpc2014/tasks/utpc2014_k
    - https://www.utpc.jp/2014/slides/K.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/matrix/binary_matrix/binary_matrix.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217\
    /\u30D0\u30A4\u30CA\u30EA\u884C\u5217\r\n */\r\n#define IGNORE\r\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/utpc2014/tasks/utpc2014_k\"\r\n\r\n#include <algorithm>\r\
    \n#include <bitset>\r\n#include <iostream>\r\n#include <limits>\r\n#include <map>\r\
    \n#include <utility>\r\n#include <vector>\r\n#include \"../../../../math/matrix/binary_matrix/binary_matrix.hpp\"\
    \r\n\r\n// editorial: https://www.utpc.jp/2014/slides/K.pdf\r\n//            http://kmjp.hatenablog.jp/entry/2015/05/28/0900\r\
    \n// BSGS \u306E\u89E3\u8AAC: http://sonickun.hatenablog.com/entry/2016/11/20/192743\r\
    \nint main() {\r\n  constexpr int N = 36;\r\n  using binary_matrix = BinaryMatrix<N>;\r\
    \n\r\n  long long a_ll, b_ll, x_ll;\r\n  std::cin >> a_ll >> b_ll >> x_ll;\r\n\
    \  std::bitset<N> a_bit(a_ll), b_bit(b_ll), x_bit(x_ll);\r\n  binary_matrix a(N,\
    \ 1), x(N, 1);\r\n  for (int i = 0; i < N; ++i) a[i][0] = a_bit[N - 1 - i];\r\n\
    \  for (int i = 0; i < N; ++i) x[i][0] = x_bit[N - 1 - i];\r\n\r\n  // 2\u9032\
    \u8868\u8A18\u3067 a_t \u306F abcdef\r\n  //           B   \u306F uvwxyz \u3067\
    \u3042\u308B\u3068\u304A\u304F\uFF0E\r\n  // a_{t+1} = (a_t >> 1) ^ ((a_t & 1)\
    \ * B)\r\n  //         = 0abcde ^ (f * uvwxyz)\r\n  //         = 0^(f&u) a^(f&v)\
    \ b^(f&w) c^(f&x) d^(f&y) e^(f&z)\uFF0E\r\n  // \u30D0\u30A4\u30CA\u30EA\u884C\
    \u5217 M \u3092\u7528\u3044\u308B\u3068\r\n  // 0^(f&u)   0 0 0 0 0 u  a\r\n \
    \ // a^(f&v)   1 0 0 0 0 v  b\r\n  // b^(f&w) = 0 1 0 0 0 w  c\r\n  // c^(f&x)\
    \   0 0 1 0 0 x  d\r\n  // d^(f&y)   0 0 0 1 0 y  e\r\n  // e^(f&z)   0 0 0 0\
    \ 1 z  f\r\n  // a_{t+1}        M      a_t\r\n  // \u3068\u306A\u308B\uFF0E\r\n\
    \  // \u2234 a_t = M^t A\uFF0E\r\n\r\n  binary_matrix m(N, N);  // \u30D0\u30A4\
    \u30CA\u30EA\u884C\u5217 M\r\n  for (int i = 0; i < N; ++i) m[i][N - 1] = b_bit[N\
    \ - 1 - i];\r\n  for (int i = 1; i < N; ++i) m[i][i - 1] = 1;\r\n\r\n  // a_t\
    \ \u306E\u3068\u308A\u3046\u308B\u5024\u306F 0 \u4EE5\u4E0A 2^36 \u672A\u6E80\u306E\
    \u9AD8\u3005 2^36 \u2253 7 * 10^10 \u500B\u3067\u3042\u308B\uFF0E\r\n  // \u5185\
    \u90E8\u72B6\u614B a \u306F\u9577\u3055 2^36 \u4EE5\u4E0B\u306E\u5468\u671F\u3092\
    \u3082\u3064\uFF0E\r\n  // \u3053\u3053\u3067 0 <= t < 2^36 \u3092\u6E80\u305F\
    \u3059\u6574\u6570 t \u306F\r\n  // 0 < i, j <= \u221A(2^36) \u3092\u6E80\u305F\
    \u3059\u6574\u6570 i, j \u3092\u7528\u3044\u3066 t = j \u221A(2^36) - i \u3068\
    \u4E00\u610F\u306B\u8868\u305B\u308B\uFF0E\r\n  //\r\n  // \u3057\u304B\u3057\u5468\
    \u671F \u221A(2^36) \u4EE5\u4E0B\u306E\u5834\u5408\uFF0C\u540C\u4E00\u306E t,\
    \ j \u306B\u5BFE\u3057\u3066\u4E0A\u8A18\u306E\u5F0F\u3092\u6E80\u305F\u3059 i\
    \ \u304C\u8907\u6570\u5B58\u5728\u3059\u308B\uFF0E\r\n  // \u305D\u306E\u305F\u3081\
    \u5468\u671F \u221A(2^36) \u4EE5\u4E0B\u306E\u3082\u306E\u306F\u611A\u76F4\u306B\
    \u8A08\u7B97\u3059\u308B\uFF0E\r\n  std::map<long long, bool> mp;  // \u5468\u671F\
    \u6027\u306E\u78BA\u8A8D\u306B\u7528\u3044\u308B\uFF0E\r\n  long long internal_state\
    \ = a_ll;\r\n  for (int t = 0; t < (1 << (N / 2)); ++t) {\r\n    if (internal_state\
    \ == x_ll) {\r\n      std::cout << t << '\\n';\r\n      return 0;\r\n    }\r\n\
    \    if (mp.count(internal_state) == 1) {\r\n      std::cout << \"-1\\n\";\r\n\
    \      return 0;\r\n    }\r\n    mp[internal_state] = true;\r\n    internal_state\
    \ = (internal_state >> 1) ^ ((internal_state & 1) * b_ll);\r\n  }\r\n\r\n  //\
    \ \u4EE5\u4E0B\uFF0CBaby-step Giant-step \u3092\u7528\u3044\u3066 a_t = X \u3092\
    \u6E80\u305F\u3059\u6700\u5C0F\u306E t \u3092\u6C42\u3081\u308B\uFF0E\r\n\r\n\
    \  /***** Baby-step *****/\r\n  std::vector<std::pair<long long, int>> mx(1 <<\
    \ (N / 2));  // {M^i X, i} (0 < i <= 2^18) \u3092\u6607\u9806\u306B\u683C\u7D0D\
    \u3059\u308B\uFF0E\r\n  binary_matrix mix = m * x;  // M^i X \u3092\u4FDD\u6301\
    \u3057\u3066\u304A\u304F\uFF0E\r\n  for (int i = 1; i <= (1 << (N / 2)); ++i)\
    \ {\r\n    long long val = 0;  // M^i X \u306E\u5024\r\n    for (int bit = 0;\
    \ bit < N; ++bit) val |= static_cast<long long>(mix[bit][0]) << (N - 1 - bit);\r\
    \n    mx[i - 1] = {val, -i};  // \u6700\u5C0F\u306E t \u3092\u6C42\u3081\u308B\
    \u305F\u3081 i \u306F\u3067\u304D\u308B\u9650\u308A\u5927\u304D\u304F\u3057\u305F\
    \u3044\uFF0E\r\n    mix = m * mix;  // M^(i+1) X = M * M^i X\uFF0E\r\n  }\r\n\
    \  std::sort(mx.begin(), mx.end());\r\n\r\n  /***** Giant-step *****/\r\n  binary_matrix\
    \ mh = m.pow(1 << (N / 2)), mha = mh * a;  // \u305D\u308C\u305E\u308C M^(2^18),\
    \ M^((2^18)j) A \u3092\u4FDD\u6301\u3057\u3066\u304A\u304F\uFF0E\r\n  for (int\
    \ j = 1; j <= (1 << (N / 2)); ++j) {\r\n    long long val = 0;  // M^((2^18)j)\
    \ A\r\n    for (int bit = 0; bit < N; ++bit) val |= static_cast<long long>(mha[bit][0])\
    \ << (N - 1 - bit);\r\n    auto it = std::lower_bound(mx.begin(), mx.end(), std::make_pair(val,\
    \ std::numeric_limits<int>::lowest()));\r\n    if (it != mx.end() && it->first\
    \ == val) {  // M^i X = M^((2^18)j) A \u3092\u6E80\u305F\u3059 i, j \u304C\u5B58\
    \u5728\u3059\u308B\u5834\u5408\r\n      // M \u304C\u6B63\u5247?\u306A\u3089\u3070\
    \ X = M((2^18)j-i) A \u304C\u6210\u308A\u7ACB\u3064\uFF0E\r\n      // \u3057\u304B\
    \u3057\u305D\u3046\u3067\u306A\u3044\u5834\u5408\u306B\u4E0A\u5F0F\u304C\u6210\
    \u308A\u7ACB\u3064\u3068\u306F\u9650\u3089\u306A\u3044\u305F\u3081\uFF0C\u5B9F\
    \u969B\u306B\u8A08\u7B97\u3092\u884C\u3046\uFF0E\r\n      long long ans = (1LL\
    \ << (N / 2)) * j + it->second;\r\n      binary_matrix maybe_x = m.pow(ans) *\
    \ a;\r\n      bool is_ans = true;\r\n      for (int bit = 0; bit < N; ++bit) {\r\
    \n        if (x[bit][0] != maybe_x[bit][0]) is_ans = false;\r\n      }\r\n   \
    \   if (is_ans) {\r\n        std::cout << ans << '\\n';\r\n        return 0;\r\
    \n      }\r\n    }\r\n    mha = mh * mha;\r\n  }\r\n\r\n  // a_t = x \u3092\u6E80\
    \u305F\u3059 t \u306F\u5B58\u5728\u3057\u306A\u3044\uFF0E\r\n  std::cout << \"\
    -1\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/matrix/binary_matrix/binary_matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/binary_matrix/binary_matrix.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 06:42:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/matrix/binary_matrix/binary_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/binary_matrix/binary_matrix.test.cpp
- /verify/test/math/matrix/binary_matrix/binary_matrix.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u30D0\u30A4\u30CA\u30EA\u884C\u5217/\u30D0\u30A4\
  \u30CA\u30EA\u884C\u5217"
---
