---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/longest_common_prefix.hpp
    title: longest common prefix
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    document_title: "\u6587\u5B57\u5217/longest common prefix"
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/string/longest_common_prefix.test.cpp\"\n/*\n * @title\
    \ \u6587\u5B57\u5217/longest common prefix\n *\n * verification-helper: PROBLEM\
    \ https://judge.yosupo.jp/problem/number_of_substrings\n */\n\n#include <iostream>\n\
    #include <string>\n\n#line 1 \"include/emthrm/string/longest_common_prefix.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#line 7 \"include/emthrm/string/longest_common_prefix.hpp\"\
    \n#include <utility>\n#include <vector>\n\n#line 1 \"include/emthrm/data_structure/sparse_table.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/data_structure/sparse_table.hpp\"\n#include <bit>\n\
    #line 7 \"include/emthrm/data_structure/sparse_table.hpp\"\n#include <functional>\n\
    #line 9 \"include/emthrm/data_structure/sparse_table.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename Band>\nstruct SparseTable {\n  using BinOp = std::function<Band(Band,\
    \ Band)>;\n\n  SparseTable() = default;\n\n  explicit SparseTable(const std::vector<Band>&\
    \ a, const BinOp bin_op) {\n    init(a, bin_op);\n  }\n\n  void init(const std::vector<Band>&\
    \ a, const BinOp bin_op_) {\n    bin_op = bin_op_;\n    const int n = a.size();\n\
    \    assert(n > 0);\n    lg.assign(n + 1, 0);\n    for (int i = 2; i <= n; ++i)\
    \ {\n      lg[i] = lg[i >> 1] + 1;\n    }\n    const int table_h = std::countr_zero(std::bit_floor(a.size()))\
    \ + 1;\n    data.assign(table_h, std::vector<Band>(n));\n    std::copy(a.begin(),\
    \ a.end(), data.front().begin());\n    for (int i = 1; i < table_h; ++i) {\n \
    \     for (int j = 0; j + (1 << i) <= n; ++j) {\n        data[i][j] = bin_op(data[i\
    \ - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  Band query(const\
    \ int left, const int right) const {\n    assert(left < right);\n    const int\
    \ h = lg[right - left];\n    return bin_op(data[h][left], data[h][right - (1 <<\
    \ h)]);\n  }\n\n private:\n  BinOp bin_op;\n  std::vector<int> lg;\n  std::vector<std::vector<Band>>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/string/suffix_array.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/string/suffix_array.hpp\"\n#include <numeric>\n\
    #line 8 \"include/emthrm/string/suffix_array.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <typename T = std::string>\nrequires requires { typename T::value_type; }\n\
    struct SuffixArray {\n  std::vector<int> sa, rank;\n\n  explicit SuffixArray(const\
    \ T& s_, const typename T::value_type sentinel = 0)\n      : s(s_) {\n    const\
    \ int n = s.size();\n    s.push_back(sentinel);\n    sa.resize(n + 1);\n    std::iota(sa.rbegin(),\
    \ sa.rend(), 0);\n    std::ranges::stable_sort(\n        sa, {}, [this](const\
    \ int index) -> int { return s[index]; });\n    rank.resize(n + 1);\n    for (int\
    \ i = 0; i <= n; ++i) {\n      rank[i] = s[i];\n    }\n    std::vector<int> tmp(n\
    \ + 1), prev_sa(n + 1);\n    for (int len = 1; len <= n; len <<= 1) {\n      tmp[sa[0]]\
    \ = 0;\n      for (int i = 1; i <= n; ++i) {\n        if (rank[sa[i - 1]] == rank[sa[i]]\
    \ && sa[i - 1] + len <= n &&\n            rank[sa[i - 1] + (len >> 1)] == rank[sa[i]\
    \ + (len >> 1)]) {\n          tmp[sa[i]] = tmp[sa[i - 1]];\n        } else {\n\
    \          tmp[sa[i]] = i;\n        }\n      }\n      rank.swap(tmp);\n      std::iota(tmp.begin(),\
    \ tmp.end(), 0);\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\n  \
    \    for (int i = 0; i <= n; ++i) {\n        const int idx = prev_sa[i] - len;\n\
    \        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\n      }\n    }\n    for (int\
    \ i = 0; i <= n; ++i) {\n      rank[sa[i]] = i;\n    }\n  }\n\n  std::vector<int>\
    \ match(T* t) const {\n    const int lb = lower_bound(t);\n    ++t->back();\n\
    \    const int ub = lower_bound(t);\n    --t->back();\n    std::vector<int> res(ub\
    \ - lb);\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  T s;\n\n  int lower_bound(const\
    \ T* t) const {\n    const int s_size = s.size(), t_size = t->size();\n    int\
    \ lb = 0, ub = s_size;\n    while (ub - lb > 1) {\n      const int mid = std::midpoint(lb,\
    \ ub);\n      int s_idx = sa[mid], t_idx = 0;\n      bool finished = false;\n\
    \      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {\n        if\
    \ (s[s_idx] != (*t)[t_idx]) {\n          (s[s_idx] < (*t)[t_idx] ? lb : ub) =\
    \ mid;\n          finished = true;\n          break;\n        }\n      }\n   \
    \   if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;\n    }\n\
    \    return ub;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 12 \"include/emthrm/string/longest_common_prefix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T = std::string>\nstruct LongestCommonPrefix\
    \ : SuffixArray<T> {\n  std::vector<int> lcp_array;\n\n  explicit LongestCommonPrefix(const\
    \ T& s) : SuffixArray<T>(s) {\n    const int n = s.size();\n    lcp_array.resize(n);\n\
    \    for (int i = 0, common = 0; i < n; ++i) {\n      const int j = this->sa[this->rank[i]\
    \ - 1];\n      if (common > 0) --common;\n      while (i + common < n && j + common\
    \ < n &&\n             s[i + common] == s[j + common]) {\n        ++common;\n\
    \      }\n      lcp_array[this->rank[i] - 1] = common;\n    }\n    st.init(lcp_array,\
    \ [](const int a, const int b) -> int {\n      return std::min(a, b);\n    });\n\
    \  }\n\n  int query(int i, int j) const {\n    assert(i != j);\n    i = this->rank[i];\n\
    \    j = this->rank[j];\n    if (i > j) std::swap(i, j);\n    return st.query(i,\
    \ j);\n  }\n\n private:\n  SparseTable<int> st;\n};\n\n}  // namespace emthrm\n\
    \n\n#line 11 \"test/string/longest_common_prefix.test.cpp\"\n\nint main() {\n\
    \  std::string s;\n  std::cin >> s;\n  const int n = s.length();\n  long long\
    \ ans = static_cast<long long>(n) * (n + 1) / 2;\n  for (const int e : emthrm::LongestCommonPrefix<>(s).lcp_array)\
    \ ans -= e;\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/longest common prefix\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/number_of_substrings\n */\n\n#include\
    \ <iostream>\n#include <string>\n\n#include \"emthrm/string/longest_common_prefix.hpp\"\
    \n\nint main() {\n  std::string s;\n  std::cin >> s;\n  const int n = s.length();\n\
    \  long long ans = static_cast<long long>(n) * (n + 1) / 2;\n  for (const int\
    \ e : emthrm::LongestCommonPrefix<>(s).lcp_array) ans -= e;\n  std::cout << ans\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/longest_common_prefix.hpp
  - include/emthrm/data_structure/sparse_table.hpp
  - include/emthrm/string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/longest_common_prefix.test.cpp
  requiredBy: []
  timestamp: '2023-07-07 02:42:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/longest_common_prefix.test.cpp
layout: document
redirect_from:
- /verify/test/string/longest_common_prefix.test.cpp
- /verify/test/string/longest_common_prefix.test.cpp.html
title: "\u6587\u5B57\u5217/longest common prefix"
---
