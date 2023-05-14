---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/formal_power_series/polynomial_interpolation.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593 (polynomial interpolation)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/multipoint_evaluation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint evaluation"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/polynomial_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u88DC\
      \u9593"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/formal_power_series/multipoint_evaluation.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <template <typename> class C, typename T>\nstruct MultipointEvaluation\
    \ {\n  std::vector<T> f_x;\n  std::vector<C<T>> subproduct_tree;\n\n  explicit\
    \ MultipointEvaluation(const std::vector<T> &xs)\n      : f_x(xs.size()), subproduct_tree(xs.size()\
    \ << 1), n(xs.size()) {\n    std::transform(xs.begin(), xs.end(), std::next(subproduct_tree.begin(),\
    \ n),\n                   [](const T& x) -> C<T> { return C<T>{-x, 1}; });\n \
    \   for (int i = n - 1; i > 0; --i) {\n      subproduct_tree[i] =\n          subproduct_tree[i\
    \ << 1] * subproduct_tree[(i << 1) + 1];\n    }\n  }\n\n  void build(const C<T>&\
    \ f) { dfs(f, 1); }\n\n private:\n  const int n;\n\n  void dfs(C<T> f, int node)\
    \ {\n    f %= subproduct_tree[node];\n    if (node < n) {\n      dfs(f, node <<\
    \ 1);\n      dfs(f, (node << 1) + 1);\n    } else {\n      f_x[node - n] = f[0];\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_\n#define\
    \ EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_\n\n#include <algorithm>\n\
    #include <iterator>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate <template\
    \ <typename> class C, typename T>\nstruct MultipointEvaluation {\n  std::vector<T>\
    \ f_x;\n  std::vector<C<T>> subproduct_tree;\n\n  explicit MultipointEvaluation(const\
    \ std::vector<T> &xs)\n      : f_x(xs.size()), subproduct_tree(xs.size() << 1),\
    \ n(xs.size()) {\n    std::transform(xs.begin(), xs.end(), std::next(subproduct_tree.begin(),\
    \ n),\n                   [](const T& x) -> C<T> { return C<T>{-x, 1}; });\n \
    \   for (int i = n - 1; i > 0; --i) {\n      subproduct_tree[i] =\n          subproduct_tree[i\
    \ << 1] * subproduct_tree[(i << 1) + 1];\n    }\n  }\n\n  void build(const C<T>&\
    \ f) { dfs(f, 1); }\n\n private:\n  const int n;\n\n  void dfs(C<T> f, int node)\
    \ {\n    f %= subproduct_tree[node];\n    if (node < n) {\n      dfs(f, node <<\
    \ 1);\n      dfs(f, (node << 1) + 1);\n    } else {\n      f_x[node - n] = f[0];\n\
    \    }\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_FORMAL_POWER_SERIES_MULTIPOINT_EVALUATION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
  requiredBy:
  - include/emthrm/math/formal_power_series/polynomial_interpolation.hpp
  timestamp: '2023-02-21 03:04:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/multipoint_evaluation.test.cpp
  - test/math/formal_power_series/polynomial_interpolation.test.cpp
documentation_of: include/emthrm/math/formal_power_series/multipoint_evaluation.hpp
layout: document
title: multipoint evaluation
---

複数の $x$ に対して $f(x)$ を求めるアルゴリズムである。


## 時間計算量

$\langle O(N(\log{N})^2), O(N(\log{N})^2) \rangle$


## 仕様

```cpp
template <template <typename> class C, typename T>
struct MultipointEvaluation;
```

- `C`：冪級数を表す構造体
- `T`：係数を表す要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> f_x`|$\lbrace f(x) \mid x \in \mathrm{xs} \rbrace$|
|`std::vector<C<T>> subproduct_tree`|subproduct tree|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit MultipointEvaluation(const std::vector<T> &xs);`|multipoint evaluation を考える。|
|`void build(const C<T>& f);`|多項式 $f$ に対して `f_x` を構築する。|


## 参考文献

- Allan Borodin and Robert Moen: Fast modular transforms, *Journal of Computer and System Sciences*, Vol. 8, No. 3, pp. 366–386 (1974). https://doi.org/10.1016/S0022-0000(74)80029-2
- https://www.sci.kanagawa-u.ac.jp/info/matsuo/pub/pdf/IKM09.pdf
- https://judge.yosupo.jp/submission/3271
- https://scrapbox.io/ecasdqina-cp/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%EF%BC%88%EF%BC%9F%EF%BC%89%E3%81%AA%E3%83%86%E3%82%AF


## TODO

- https://drive.google.com/drive/folders/1gszRctvUfme7ST-K3DsrH7FIU64kHcsD


## Submissons

https://judge.yosupo.jp/submission/3793
