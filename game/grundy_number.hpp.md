---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"game/grundy_number.hpp\"\n#include <functional>\r\n#include\
    \ <map>\r\n#include <set>\r\n#include <vector>\r\n\r\ntemplate <typename T>\r\n\
    int grundy_number(long long val, const std::vector<T> &trans) {\r\n  std::map<long\
    \ long, int> mp;\r\n  std::function<int(long long)> rec = [&trans, &mp, &rec](long\
    \ long now) -> int {\r\n    if (mp.count(now) == 1) return mp[now];\r\n    std::set<int>\
    \ st;\r\n    for (T e : trans) {\r\n      if (now >= e) st.emplace(rec(now - e));\r\
    \n    }\r\n    mp[now] = 0;\r\n    while (st.count(mp[now]) == 1) ++mp[now];\r\
    \n    return mp[now];\r\n  };\r\n  return rec(val);\r\n}\r\n"
  code: "#pragma once\r\n#include <functional>\r\n#include <map>\r\n#include <set>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T>\r\nint grundy_number(long long\
    \ val, const std::vector<T> &trans) {\r\n  std::map<long long, int> mp;\r\n  std::function<int(long\
    \ long)> rec = [&trans, &mp, &rec](long long now) -> int {\r\n    if (mp.count(now)\
    \ == 1) return mp[now];\r\n    std::set<int> st;\r\n    for (T e : trans) {\r\n\
    \      if (now >= e) st.emplace(rec(now - e));\r\n    }\r\n    mp[now] = 0;\r\n\
    \    while (st.count(mp[now]) == 1) ++mp[now];\r\n    return mp[now];\r\n  };\r\
    \n  return rec(val);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: game/grundy_number.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: game/grundy_number.hpp
layout: document
title: "Grundy \u6570 (Grundy number)"
---

現在の状態から一手で遷移する状態における Grundy 数の mex である．


## 使用法

||説明|
|:--:|:--:|
|`grundy_number(val, trans)`|遷移 $\mathrm{trans}$ のときの $\mathrm{val}$ 個の山の Grundy 数|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.281-283


## Verified
