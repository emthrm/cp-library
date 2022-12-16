---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/longest_common_prefix.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/sparse_table.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_STRING_LONGEST_COMMON_PREFIX_HPP_\n#define EMTHRM_STRING_LONGEST_COMMON_PREFIX_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/data_structure/sparse_table.hpp\"\n#include\
    \ \"emthrm/string/suffix_array.hpp\"\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T = std::string>\nstruct LongestCommonPrefix : SuffixArray<T> {\n  std::vector<int>\
    \ lcp_array;\n\n  explicit LongestCommonPrefix(const T& s) : SuffixArray<T>(s)\
    \ {\n    const int n = s.size();\n    lcp_array.resize(n);\n    for (int i = 0,\
    \ common = 0; i < n; ++i) {\n      const int j = this->sa[this->rank[i] - 1];\n\
    \      if (common > 0) --common;\n      while (i + common < n && j + common <\
    \ n &&\n             s[i + common] == s[j + common]) {\n        ++common;\n  \
    \    }\n      lcp_array[this->rank[i] - 1] = common;\n    }\n    st.init(lcp_array,\
    \ [](const int a, const int b) -> int {\n      return std::min(a, b);\n    });\n\
    \  }\n\n  int query(int i, int j) const {\n    assert(i != j);\n    i = this->rank[i];\n\
    \    j = this->rank[j];\n    if (i > j) std::swap(i, j);\n    return st.query(i,\
    \ j);\n  }\n\n private:\n  SparseTable<int> st;\n};\n\n}  // namespace emthrm\n\
    \n#endif  // EMTHRM_STRING_LONGEST_COMMON_PREFIX_HPP_\n"
  dependsOn:
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/string/suffix_array.hpp
  isVerificationFile: false
  path: include/emthrm/string/longest_common_prefix.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/longest_common_prefix.test.cpp
documentation_of: include/emthrm/string/longest_common_prefix.hpp
layout: document
title: longest common prefix
---


### 高さ配列 (longest common prefix array)

接尾辞配列中で隣接する接尾辞の最長共通接頭辞長を表す配列である．


## 時間計算量

テキスト長を $N$ とおくと $\langle O(N\log{N}), O(1) \rangle$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`LongestCommonPrefix<T = string>(s)`|$S$ の longest common prefix を考える．||
|`lcp_array`|高さ配列||
|`query(i, j)`|位置 $i, j$ を一文字目とする接尾辞の最長共通接頭辞長|$i \neq j$ でなければならない．|


## 参考

- https://github.com/beet-aizu/library/blob/8ca8433c2baf5ddd8efca091927475ad03caadce/string/longestcommonprefix.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.339-340，マイナビ出版（2012）


## Verified

https://judge.yosupo.jp/submission/3244
