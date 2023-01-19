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
  bundledCode: "#line 1 \"include/emthrm/util/timer.hpp\"\n\n\n\n#include <chrono>\n\
    \nnamespace emthrm {\n\nstruct Timer {\n  Timer() { reset(); }\n  void reset()\
    \ { bgn = std::chrono::high_resolution_clock::now(); }\n  template <typename PeriodType\
    \ = std::chrono::milliseconds>\n  long long elapsed() const {\n    std::chrono::high_resolution_clock::time_point\
    \ end =\n        std::chrono::high_resolution_clock::now();\n    return std::chrono::duration_cast<PeriodType>(end\
    \ - bgn).count();\n  }\n private:\n  std::chrono::high_resolution_clock::time_point\
    \ bgn;\n} timer;\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_UTIL_TIMER_HPP_\n#define EMTHRM_UTIL_TIMER_HPP_\n\n#include\
    \ <chrono>\n\nnamespace emthrm {\n\nstruct Timer {\n  Timer() { reset(); }\n \
    \ void reset() { bgn = std::chrono::high_resolution_clock::now(); }\n  template\
    \ <typename PeriodType = std::chrono::milliseconds>\n  long long elapsed() const\
    \ {\n    std::chrono::high_resolution_clock::time_point end =\n        std::chrono::high_resolution_clock::now();\n\
    \    return std::chrono::duration_cast<PeriodType>(end - bgn).count();\n  }\n\
    \ private:\n  std::chrono::high_resolution_clock::time_point bgn;\n} timer;\n\n\
    }  // namespace emthrm\n\n#endif  // EMTHRM_UTIL_TIMER_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/util/timer.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/util/timer.hpp
layout: document
title: "\u30BF\u30A4\u30DE\u30FC (timer)"
---


## 仕様

```cpp
struct Timer;
```

#### メンバ変数

|名前|効果・戻り値|
|:--|:--|
|`Timer();`|コンストラクタ|
|`void reset();`|リセットする。|
|`template <typename PeriodType = std::chrono::milliseconds> long long elapsed() const;`|経過時間|


## 参考文献

- http://vivi.dyndns.org/tech/cpp/timeMeasurement.html#chrono
- https://cpprefjp.github.io/reference/chrono.html
