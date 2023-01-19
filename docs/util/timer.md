---
title: タイマー (timer)
documentation_of: include/emthrm/util/timer.hpp
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
