---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"game/misere_nim.hpp\"\n#include <algorithm>\r\n#include\
    \ <vector>\r\n#line 3 \"game/nim.hpp\"\n\r\ntemplate <typename T>\r\nbool nim(const\
    \ std::vector<T> &a) {\r\n  long long x = 0;\r\n  for (T e : a) x ^= e;\r\n  return\
    \ x != 0;\r\n}\r\n#line 5 \"game/misere_nim.hpp\"\n\r\ntemplate <typename T>\r\
    \nbool misere_nim(const std::vector<T> &a) {\r\n  return *std::max_element(a.begin(),\
    \ a.end()) <= 1 ? a.size() % 2 == 0 : nim(a);\r\n}\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <vector>\r\n#include \"\
    nim.hpp\"\r\n\r\ntemplate <typename T>\r\nbool misere_nim(const std::vector<T>\
    \ &a) {\r\n  return *std::max_element(a.begin(), a.end()) <= 1 ? a.size() % 2\
    \ == 0 : nim(a);\r\n}\r\n"
  dependsOn:
  - game/nim.hpp
  isVerificationFile: false
  path: game/misere_nim.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: game/misere_nim.hpp
layout: document
title: "mis\xE8re Nim"
---

[ニム](nim.md)のルールの内, 操作を行えなくなった方を勝ちとするものである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`misere_nim(a)`|盤面が $A$ のときの misère Nim で先手が勝利するか．|


## 参考

- http://winjii.hatenablog.com/entry/2016/05/29/143653


## Verified
