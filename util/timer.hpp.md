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
  bundledCode: "#line 2 \"util/timer.hpp\"\n#include <chrono>\n\nstruct Timer {\n\
    \  Timer() { reset(); }\n  void reset() { bgn = std::chrono::high_resolution_clock::now();\
    \ }\n  template <typename PeriodType = std::chrono::milliseconds>\n  long long\
    \ elapsed() const {\n    std::chrono::high_resolution_clock::time_point end =\n\
    \        std::chrono::high_resolution_clock::now();\n    return std::chrono::duration_cast<PeriodType>(end\
    \ - bgn).count();\n  }\n private:\n  std::chrono::high_resolution_clock::time_point\
    \ bgn;\n} timer;\n"
  code: "#pragma once\n#include <chrono>\n\nstruct Timer {\n  Timer() { reset(); }\n\
    \  void reset() { bgn = std::chrono::high_resolution_clock::now(); }\n  template\
    \ <typename PeriodType = std::chrono::milliseconds>\n  long long elapsed() const\
    \ {\n    std::chrono::high_resolution_clock::time_point end =\n        std::chrono::high_resolution_clock::now();\n\
    \    return std::chrono::duration_cast<PeriodType>(end - bgn).count();\n  }\n\
    \ private:\n  std::chrono::high_resolution_clock::time_point bgn;\n} timer;\n"
  dependsOn: []
  isVerificationFile: false
  path: util/timer.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/timer.hpp
layout: document
title: "\u30BF\u30A4\u30DE\u30FC (timer)"
---


## 使用法

||説明|
|:--:|:--:|
|`timer.reset()`|リセット|
|`timer.elapsed<PeriodType = std::chrono::milliseconds>()`|計測時間|


## 参考

- http://vivi.dyndns.org/tech/cpp/timeMeasurement.html#chrono
- https://cpprefjp.github.io/reference/chrono.html
