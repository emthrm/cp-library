---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':x:'
    path: string/longest_common_prefix.hpp
    title: longest common prefix
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    document_title: "\u6587\u5B57\u5217/longest common prefix"
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/string/longest_common_prefix.test.cpp\"\n/*\r\n * @brief\
    \ \u6587\u5B57\u5217/longest common prefix\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n\r\n#line 2 \"string/longest_common_prefix.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#line 5 \"string/longest_common_prefix.hpp\"\
    \n#include <utility>\r\n#include <vector>\r\n\r\n#line 4 \"data_structure/sparse_table.hpp\"\
    \n#include <functional>\r\n#line 6 \"data_structure/sparse_table.hpp\"\n\r\ntemplate\
    \ <typename Band>\r\nstruct SparseTable {\r\n  using Fn = std::function<Band(Band,\
    \ Band)>;\r\n\r\n  SparseTable() = default;\r\n\r\n  explicit SparseTable(const\
    \ std::vector<Band>& a, const Fn fn) { init(a, fn); }\r\n\r\n  void init(const\
    \ std::vector<Band>& a, const Fn fn_) {\r\n    fn = fn_;\r\n    int n = a.size(),\
    \ table_h = 0;\r\n    lg.assign(n + 1, 0);\r\n    for (int i = 2; i <= n; ++i)\
    \ {\r\n      lg[i] = lg[i >> 1] + 1;\r\n    }\r\n    while ((1 << table_h) <=\
    \ n) ++table_h;\r\n    data.assign(table_h, std::vector<Band>(n));\r\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\r\n    for (int i = 1; i < table_h; ++i) {\r\
    \n      for (int j = 0; j + (1 << i) <= n; ++j) {\r\n        data[i][j] = fn(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  Band query(const int left, const int right) const {\r\n    assert(left < right);\r\
    \n    const int h = lg[right - left];\r\n    return fn(data[h][left], data[h][right\
    \ - (1 << h)]);\r\n  }\r\n\r\n private:\r\n  Fn fn;\r\n  std::vector<int> lg;\r\
    \n  std::vector<std::vector<Band>> data;\r\n};\r\n#line 3 \"string/suffix_array.hpp\"\
    \n#include <numeric>\r\n#line 6 \"string/suffix_array.hpp\"\n\r\ntemplate <typename\
    \ T = std::string>\r\nstruct SuffixArray {\r\n  std::vector<int> sa, rank;\r\n\
    \r\n  template <typename U = char>\r\n  explicit SuffixArray(const T& s_, const\
    \ U sentinel = 0) : s(s_) {\r\n    const int n = s.size();\r\n    s.push_back(sentinel);\r\
    \n    sa.resize(n + 1);\r\n    std::iota(sa.begin(), sa.end(), 0);\r\n    std::sort(sa.begin(),\
    \ sa.end(), [this](const int a, const int b) -> bool {\r\n      return s[a] ==\
    \ s[b] ? a > b : s[a] < s[b];\r\n    });\r\n    rank.resize(n + 1);\r\n    for\
    \ (int i = 0; i <= n; ++i) {\r\n      rank[i] = s[i];\r\n    }\r\n    std::vector<int>\
    \ tmp(n + 1), prev_sa(n + 1);\r\n    for (int len = 1; len <= n; len <<= 1) {\r\
    \n      tmp[sa[0]] = 0;\r\n      for (int i = 1; i <= n; ++i) {\r\n        if\
    \ (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&\r\n            rank[sa[i\
    \ - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\r\n          tmp[sa[i]] =\
    \ tmp[sa[i - 1]];\r\n        } else {\r\n          tmp[sa[i]] = i;\r\n       \
    \ }\r\n      }\r\n      rank.swap(tmp);\r\n      std::iota(tmp.begin(), tmp.end(),\
    \ 0);\r\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\r\n      for\
    \ (int i = 0; i <= n; ++i) {\r\n        const int idx = prev_sa[i] - len;\r\n\
    \        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\r\n      }\r\n    }\r\n   \
    \ for (int i = 0; i <= n; ++i) {\r\n      rank[sa[i]] = i;\r\n    }\r\n  }\r\n\
    \r\n  std::vector<int> match(T* t) const {\r\n    const int lb = lower_bound(t);\r\
    \n    ++t->back();\r\n    const int ub = lower_bound(t);\r\n    --t->back();\r\
    \n    std::vector<int> res(ub - lb);\r\n    std::copy(sa.begin() + lb, sa.begin()\
    \ + ub, res.begin());\r\n    std::sort(res.begin(), res.end());\r\n    return\
    \ res;\r\n  }\r\n\r\n private:\r\n  T s;\r\n\r\n  int lower_bound(const T* t)\
    \ const {\r\n    const int s_size = s.size(), t_size = t->size();\r\n    int lb\
    \ = 0, ub = s_size;\r\n    while (ub - lb > 1) {\r\n      const int mid = (lb\
    \ + ub) >> 1;\r\n      int s_idx = sa[mid], t_idx = 0;\r\n      bool finished\
    \ = false;\r\n      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx)\
    \ {\r\n        if (s[s_idx] != (*t)[t_idx]) {\r\n          (s[s_idx] < (*t)[t_idx]\
    \ ? lb : ub) = mid;\r\n          finished = true;\r\n          break;\r\n    \
    \    }\r\n      }\r\n      if (!finished) (s_idx == s_size && t_idx < t_size ?\
    \ lb : ub) = mid;\r\n    }\r\n    return ub;\r\n  }\r\n};\r\n#line 10 \"string/longest_common_prefix.hpp\"\
    \n\r\ntemplate <typename T = std::string>\r\nstruct LongestCommonPrefix : SuffixArray<T>\
    \ {\r\n  std::vector<int> lcp_array;\r\n\r\n  explicit LongestCommonPrefix(const\
    \ T& s) : SuffixArray<T>(s) {\r\n    const int n = s.size();\r\n    lcp_array.resize(n);\r\
    \n    for (int i = 0, common = 0; i < n; ++i) {\r\n      const int j = this->sa[this->rank[i]\
    \ - 1];\r\n      if (common > 0) --common;\r\n      while (i + common < n && j\
    \ + common < n &&\r\n             s[i + common] == s[j + common]) {\r\n      \
    \  ++common;\r\n      }\r\n      lcp_array[this->rank[i] - 1] = common;\r\n  \
    \  }\r\n    st.init(lcp_array, [](const int a, const int b) -> int {\r\n     \
    \ return std::min(a, b);\r\n    });\r\n  }\r\n\r\n  int query(int i, int j) const\
    \ {\r\n    assert(i != j);\r\n    i = this->rank[i];\r\n    j = this->rank[j];\r\
    \n    if (i > j) std::swap(i, j);\r\n    return st.query(i, j);\r\n  }\r\n\r\n\
    \ private:\r\n  SparseTable<int> st;\r\n};\r\n#line 10 \"test/string/longest_common_prefix.test.cpp\"\
    \n\r\nint main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  const int n =\
    \ s.length();\r\n  long long ans = static_cast<long long>(n) * (n + 1) / 2;\r\n\
    \  for (const int e : LongestCommonPrefix<>(s).lcp_array) ans -= e;\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/longest common prefix\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n\r\n#include \"../../string/longest_common_prefix.hpp\"\
    \r\n\r\nint main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  const int n\
    \ = s.length();\r\n  long long ans = static_cast<long long>(n) * (n + 1) / 2;\r\
    \n  for (const int e : LongestCommonPrefix<>(s).lcp_array) ans -= e;\r\n  std::cout\
    \ << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - string/longest_common_prefix.hpp
  - data_structure/sparse_table.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/longest_common_prefix.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 18:14:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/longest_common_prefix.test.cpp
layout: document
redirect_from:
- /verify/test/string/longest_common_prefix.test.cpp
- /verify/test/string/longest_common_prefix.test.cpp.html
title: "\u6587\u5B57\u5217/longest common prefix"
---
