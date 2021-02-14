---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/divisor.hpp
    title: "\u7D04\u6570\u5217\u6319"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/primitive_root.md
    document_title: "\u539F\u59CB\u6839\u5224\u5B9A"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/is_primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u539F\u59CB\u6839\u5224\u5B9A\r\n * @docs docs/math/primitive_root.md\r\
    \n */\r\n\r\n#pragma once\r\n#include <vector>\r\n#include \"divisor.hpp\"\r\n\
    #include \"mod_pow.hpp\"\r\n\r\nbool is_primitive_root(int primitive_root, int\
    \ mod) {\r\n  std::vector<int> d = divisor(mod - 1);\r\n  d.pop_back();\r\n  for\
    \ (int e : d) {\r\n    if (mod_pow(primitive_root, e, mod) == 1) return false;\r\
    \n  }\r\n  return true;\r\n}\r\n"
  dependsOn:
  - math/divisor.hpp
  - math/mod_pow.hpp
  isVerificationFile: false
  path: math/is_primitive_root.hpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
documentation_of: math/is_primitive_root.hpp
layout: document
redirect_from:
- /library/math/is_primitive_root.hpp
- /library/math/is_primitive_root.hpp.html
title: "\u539F\u59CB\u6839\u5224\u5B9A"
---
# 原始根 (primitive root)

正の整数 $n$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ を満たす $n$ が存在するときの $g$ の属する法 $n$ の剰余類 $g \bmod n$ である．


### 位数 (multiplicative order)

互いに素な整数 $a$ と正の整数 $n$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の正整数 $k$ である．


## 使用法

- 原始根判定

||説明|
|:--:|:--:|
|`is_primitive_root(primitive_root, mod)`|$\mathrm{primitive\_root}$ は $\mathrm{mod}$ を法とする原始根であるか|


## 参考

- https://ja.wikipedia.org/wiki/%E6%8C%87%E6%95%B0_(%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96)

原始根判定
  - https://lumakernel.github.io/ecasdqina/math/general


## ToDo

- https://37zigen.com/primitive-root/
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Verified

- [原始根判定](https://yukicoder.me/submissions/414440)
