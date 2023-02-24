---
title: misère Nim
documentation_of: //include/emthrm/game/misere_nim.hpp
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
