---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"game/misere_nim.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \n#line 3 \"game/nim.hpp\"\n\ntemplate <typename T>\nbool nim(const std::vector<T>&\
    \ a) {\n  long long x = 0;\n  for (const T e : a) x ^= e;\n  return x != 0;\n\
    }\n#line 6 \"game/misere_nim.hpp\"\n\ntemplate <typename T>\nbool misere_nim(const\
    \ std::vector<T>& a) {\n  std::vector<T> positive;\n  positive.reserve(a.size());\n\
    \  for (const T e : a) {\n    if (e > 0) positive.emplace_back(e);\n  }\n  if\
    \ (positive.empty()) return true;\n  return *std::max_element(positive.begin(),\
    \ positive.end()) == 1 ?\n         positive.size() % 2 == 0 : nim(positive);\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n#include \"./nim.hpp\"\
    \n\ntemplate <typename T>\nbool misere_nim(const std::vector<T>& a) {\n  std::vector<T>\
    \ positive;\n  positive.reserve(a.size());\n  for (const T e : a) {\n    if (e\
    \ > 0) positive.emplace_back(e);\n  }\n  if (positive.empty()) return true;\n\
    \  return *std::max_element(positive.begin(), positive.end()) == 1 ?\n       \
    \  positive.size() % 2 == 0 : nim(positive);\n}\n"
  dependsOn:
  - game/nim.hpp
  isVerificationFile: false
  path: game/misere_nim.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: game/misere_nim.hpp
layout: document
title: "mis\xE8re Nim"
---

[ニム](nim.md)のルールの内，操作できなくなった方を勝ちとするものである．


## 時間計算量

$O(N)$


## 使用法

||説明|
|:--:|:--:|
|`misere_nim(a)`|盤面が $A$ のときの misère Nim で先手が勝利するか．|


## 参考

- http://winjii.hatenablog.com/entry/2016/05/29/143653
