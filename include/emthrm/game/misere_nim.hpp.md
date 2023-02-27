---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/game/nim.hpp
    title: "\u30CB\u30E0 (nim)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/game/misere_nim.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/game/nim.hpp\"\n\n\n\n#line 5 \"\
    include/emthrm/game/nim.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename T>\n\
    bool nim(const std::vector<T>& a) {\n  long long x = 0;\n  for (const T e : a)\
    \ x ^= e;\n  return x != 0;\n}\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/game/misere_nim.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nbool misere_nim(const std::vector<T>&\
    \ a) {\n  std::vector<T> positive;\n  positive.reserve(a.size());\n  for (const\
    \ T e : a) {\n    if (e > 0) positive.emplace_back(e);\n  }\n  if (positive.empty())\
    \ [[unlikely]] return true;\n  return *std::max_element(positive.begin(), positive.end())\
    \ == 1 ?\n         positive.size() % 2 == 0 : nim(positive);\n}\n\n}  // namespace\
    \ emthrm\n\n\n"
  code: "#ifndef EMTHRM_GAME_MISERE_NIM_HPP_\n#define EMTHRM_GAME_MISERE_NIM_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"emthrm/game/nim.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nbool misere_nim(const std::vector<T>&\
    \ a) {\n  std::vector<T> positive;\n  positive.reserve(a.size());\n  for (const\
    \ T e : a) {\n    if (e > 0) positive.emplace_back(e);\n  }\n  if (positive.empty())\
    \ [[unlikely]] return true;\n  return *std::max_element(positive.begin(), positive.end())\
    \ == 1 ?\n         positive.size() % 2 == 0 : nim(positive);\n}\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GAME_MISERE_NIM_HPP_\n"
  dependsOn:
  - include/emthrm/game/nim.hpp
  isVerificationFile: false
  path: include/emthrm/game/misere_nim.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/game/misere_nim.hpp
layout: document
title: "mis\xE8re Nim"
---

[ニム](nim.md)のルールの内、操作できなくなった方を勝ちとするものである。


## 時間計算量

$O(N)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`bool misere_nim(const std::vector<T>& a);`|盤面が $A$ のときの misère Nim で先手が勝利するか。|


## 参考文献

- http://winjii.hatenablog.com/entry/2016/05/29/143653
