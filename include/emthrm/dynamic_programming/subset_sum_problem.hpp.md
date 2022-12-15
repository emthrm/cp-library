---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/math/formal_power_series/formal_power_series.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570 (formal power series)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/subset_sum_problem.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u90E8\u5206\u548C\u554F\u984C"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/math/formal_power_series/formal_power_series.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_\n\
    \n#include <vector>\n\n#include \"emthrm/math/formal_power_series/formal_power_series.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> subset_sum_problem(const\
    \ std::vector<int>& a, const int d) {\n  T zero = 1;\n  std::vector<int> nums(d\
    \ + 1, 0);\n  for (const int e : a) {\n    if (e == 0) {\n      zero *= 2;\n \
    \   } else if (e <= d) {\n      ++nums[e];\n    }\n  }\n  FormalPowerSeries<T>\
    \ fps(d);\n  for (int i = 1; i <= d; ++i) {\n    for (int j = 1; i * j <= d; ++j)\
    \ {\n      fps[i * j] += static_cast<T>(nums[i]) / (j & 1 ? j : -j);\n    }\n\
    \  }\n  return (fps.exp(d) * zero).coef;\n}\n\n}  // namespace emthrm\n\n#endif\
    \  // EMTHRM_DYNAMIC_PROGRAMMING_SUBSET_SUM_PROBLEM_HPP_\n"
  dependsOn:
  - include/emthrm/math/formal_power_series/formal_power_series.hpp
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/subset_sum_problem.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/subset_sum_problem.test.cpp
documentation_of: include/emthrm/dynamic_programming/subset_sum_problem.hpp
layout: document
title: "\u90E8\u5206\u548C\u554F\u984C (subset sum problem)"
---

$n$ 個の数の選び方の内，要素の和が特定の数となるものの存在性を判定する問題である．

ナップサック問題の部分問題である．

[形式的冪級数](../math/formal_power_series/formal_power_series.md)を用いて場合の数を求められる．


## 時間計算量

$O(N + D\log{D})$


## 使用法

||説明|条件|
|:--:|:--:|:--:|
|`subset_sum_problem(a, d)`|集合内の要素の和が $s$ ($0 \leq s \leq D$) となる $A$ の部分集合の個数|$A_i \geq 0$|


## 参考

- https://yukicoder.me/wiki/polynomial_techniques


## Verified

https://judge.yosupo.jp/submission/6908
