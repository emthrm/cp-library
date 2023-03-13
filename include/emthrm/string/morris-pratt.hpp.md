---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/morris-pratt.1.test.cpp
    title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u30D1\u30BF\u30FC\
      \u30F3\u30DE\u30C3\u30C1\u30F3\u30B0\uFF09"
  - icon: ':warning:'
    path: test/string/morris-pratt.2.test.cpp
    title: "\u6587\u5B57\u5217/Morris\u2013Pratt algorithm\uFF08\u6700\u5C0F\u5468\
      \u671F\uFF09"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/morris-pratt.hpp\"\n\n\n\n#include\
    \ <string>\n#include <vector>\n\nnamespace emthrm {\n\nstruct MorrisPratt {\n\
    \  std::string s;\n  std::vector<int> border;\n\n  explicit MorrisPratt(const\
    \ std::string& s) : s(s), border({-1}), j(-1) {\n    const int n = s.length();\n\
    \    for (int i = 0; i < n; ++i) {\n      solve(i);\n    }\n  }\n\n  void add(const\
    \ char c) {\n    s += c;\n    solve(s.length() - 1);\n  }\n\n  std::vector<int>\
    \ match(const std::string& t) const {\n    const int n = s.length(), m = t.length();\n\
    \    std::vector<int> res;\n    for (int i = 0, k = 0; i < m; ++i) {\n      while\
    \ (k >= 0 && t[i] != s[k]) k = border[k];\n      if (++k == n) res.emplace_back(i\
    \ - n + 1);\n    }\n    return res;\n  }\n\n  int period(const int idx) const\
    \ { return idx - border[idx]; }\n\n private:\n  int j;\n\n  void solve(const int\
    \ idx) {\n    while (j >= 0 && s[idx] != s[j]) j = border[j];\n    border.emplace_back(++j);\n\
    \  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_MORRIS_PRATT_HPP_\n#define EMTHRM_STRING_MORRIS_PRATT_HPP_\n\
    \n#include <string>\n#include <vector>\n\nnamespace emthrm {\n\nstruct MorrisPratt\
    \ {\n  std::string s;\n  std::vector<int> border;\n\n  explicit MorrisPratt(const\
    \ std::string& s) : s(s), border({-1}), j(-1) {\n    const int n = s.length();\n\
    \    for (int i = 0; i < n; ++i) {\n      solve(i);\n    }\n  }\n\n  void add(const\
    \ char c) {\n    s += c;\n    solve(s.length() - 1);\n  }\n\n  std::vector<int>\
    \ match(const std::string& t) const {\n    const int n = s.length(), m = t.length();\n\
    \    std::vector<int> res;\n    for (int i = 0, k = 0; i < m; ++i) {\n      while\
    \ (k >= 0 && t[i] != s[k]) k = border[k];\n      if (++k == n) res.emplace_back(i\
    \ - n + 1);\n    }\n    return res;\n  }\n\n  int period(const int idx) const\
    \ { return idx - border[idx]; }\n\n private:\n  int j;\n\n  void solve(const int\
    \ idx) {\n    while (j >= 0 && s[idx] != s[j]) j = border[j];\n    border.emplace_back(++j);\n\
    \  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_MORRIS_PRATT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/morris-pratt.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_PARTIAL_AC
  verifiedWith:
  - test/string/morris-pratt.2.test.cpp
  - test/string/morris-pratt.1.test.cpp
documentation_of: include/emthrm/string/morris-pratt.hpp
layout: document
title: "Morris\u2013Pratt algorithm"
---

# Knuth–Morris–Pratt algorithm

文字列 $S$ に対して `S[0:i]` の接頭辞と接尾辞の最大共通文字数 ($< i$) を求めるアルゴリズムである。


## 時間計算量

パターン長を $N$, テキスト長を $M$ とおく。

### Morris–Pratt algorithm

||時間計算量|
|:--|:--|
|前処理|$O(N)$|
|更新|amortized $O(N)$ ?|
|パターンマッチング|$O(M)$|

### Knuth–Morris–Pratt algorithm

$$
  \langle O(N), O(M) \rangle
$$


## 仕様

### Morris–Pratt algorithm

```cpp
struct MorrisPratt;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::string s`|文字列 $S$|
|`std::vector<int> border`|$\mathrm{border}_i$ は `S[0:i]` の最長 border 長を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit MorrisPratt(const std::string& s);`|文字列 $S$ に対してオブジェクトを構築する。|
|`void add(const char c);`|$S$ の末尾に文字 $c$ を追加する。|
|`std::vector<int> match(const std::string& t) const;`|$S$ が出現する文字列 $T$ 中の位置|
|`int period(const int idx) const;`|`S[0:idx]` の最小周期|


### Knuth–Morris–Pratt algorithm

```cpp
template <typename T = std::string>
struct KnuthMorrisPratt;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> border`|`border[i]` は `S[0:i]` の最長 tagged border 長を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit KnuthMorrisPratt(const T& s);`|文字列 $S$ に対してオブジェクトを構築する。|
|`std::vector<int> match(const T& t) const;`|$S$ が出現する $T$ 中の位置|


## 参考文献

Morris–Pratt algorithm
- https://snuke.hatenablog.com/entry/2014/12/01/235807

Knuth–Morris–Pratt algorithm
- https://snuke.hatenablog.com/entry/2017/07/18/101026
- http://potetisensei.hatenablog.com/entry/2017/07/10/174908

周期性判定
- https://snuke.hatenablog.com/entry/2015/04/05/184819

パターンマッチング
- https://github.com/drken1215/algorithm/blob/d41481f5011e8b129128050627faddebe2add91a/String/knuth_morris_pratt.cpp


## Submissons

- Morris–Pratt algorithm
  - [`match(t)`](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086469/emthrm/C++14)
  - [`period(idx)`](https://codeforces.com/contest/1138/submission/68089639)
- [Knuth–Morris–Pratt algorithm](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4086467/emthrm/C++14)
