---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':x:'
    path: string/lcp.hpp
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
  bundledCode: "#line 1 \"test/string/lcp.test.cpp\"\n/*\r\n * @brief \u6587\u5B57\
    \u5217/longest common prefix\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#line 2 \"string/lcp.hpp\"\
    \n#include <algorithm>\r\n#include <cassert>\r\n#line 5 \"string/lcp.hpp\"\n#include\
    \ <utility>\r\n#include <vector>\r\n#line 3 \"string/suffix_array.hpp\"\n#include\
    \ <numeric>\r\n#line 6 \"string/suffix_array.hpp\"\n\r\ntemplate <typename T =\
    \ std::string>\r\nstruct SuffixArray {\r\n  std::vector<int> sa, rank;\r\n\r\n\
    \  SuffixArray(const T &s_) : s(s_) {\r\n    int n = s.size();\r\n    s.push_back('\
    \ ');\r\n    sa.resize(n + 1);\r\n    std::iota(sa.begin(), sa.end(), 0);\r\n\
    \    std::sort(sa.begin(), sa.end(), [&](int a, int b) -> bool { return s[a] ==\
    \ s[b] ? a > b : s[a] < s[b]; });\r\n    rank.resize(n + 1);\r\n    for (int i\
    \ = 0; i <= n; ++i) rank[i] = s[i];\r\n    std::vector<int> tmp(n + 1), prev_sa(n\
    \ + 1);\r\n    for (int len = 1; len <= n; len <<= 1) {\r\n      tmp[sa[0]] =\
    \ 0;\r\n      for (int i = 1; i <= n; ++i) {\r\n        if (rank[sa[i - 1]] ==\
    \ rank[sa[i]] && sa[i - 1] + len <= n && rank[sa[i - 1] + (len >> 1)] == rank[sa[i]\
    \ + (len >> 1)]) {\r\n          tmp[sa[i]] = tmp[sa[i - 1]];\r\n        } else\
    \ {\r\n          tmp[sa[i]] = i;\r\n        }\r\n      }\r\n      rank.swap(tmp);\r\
    \n      std::iota(tmp.begin(), tmp.end(), 0);\r\n      std::copy(sa.begin(), sa.end(),\
    \ prev_sa.begin());\r\n      for (int i = 0; i <= n; ++i) {\r\n        int idx\
    \ = prev_sa[i] - len;\r\n        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\r\n\
    \      }\r\n    }\r\n    for (int i = 0; i <= n; ++i) rank[sa[i]] = i;\r\n  }\r\
    \n\r\n  std::vector<int> match(T &t) const {\r\n    int lb = lower_bound(t);\r\
    \n    ++t.back();\r\n    int ub = lower_bound(t);\r\n    --t.back();\r\n    std::vector<int>\
    \ res(ub - lb);\r\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\r\
    \n    std::sort(res.begin(), res.end());\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  T s;\r\n\r\n  int lower_bound(const T &t) const {\r\n    int s_sz = s.size(),\
    \ t_sz = t.size(), lb = 0, ub = s_sz;\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1, s_idx = sa[mid], t_idx = 0;\r\n      bool finished = false;\r\
    \n      for (; s_idx < s_sz && t_idx < t_sz; ++s_idx, ++t_idx) {\r\n        if\
    \ (s[s_idx] != t[t_idx]) {\r\n          (s[s_idx] < t[t_idx] ? lb : ub) = mid;\r\
    \n          finished = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!finished) (s_idx == s_sz && t_idx < t_sz ? lb : ub) = mid;\r\n    }\r\
    \n    return ub;\r\n  }\r\n};\r\n#line 3 \"data_structure/sparse_table.hpp\"\n\
    #include <functional>\r\n#line 5 \"data_structure/sparse_table.hpp\"\n\r\ntemplate\
    \ <typename MeetSemilattice>\r\nstruct SparseTable {\r\n  using Fn = std::function<MeetSemilattice(MeetSemilattice,\
    \ MeetSemilattice)>;\r\n\r\n  SparseTable() {}\r\n\r\n  SparseTable(const std::vector<MeetSemilattice>\
    \ &a, Fn fn) { init(a, fn); }\r\n\r\n  void init(const std::vector<MeetSemilattice>\
    \ &a, Fn fn_) {\r\n    is_built = true;\r\n    fn = fn_;\r\n    int n = a.size(),\
    \ table_h = 0;\r\n    lg.assign(n + 1, 0);\r\n    for (int i = 2; i <= n; ++i)\
    \ lg[i] = lg[i >> 1] + 1;\r\n    while ((1 << table_h) <= n) ++table_h;\r\n  \
    \  dat.assign(table_h, std::vector<MeetSemilattice>(n));\r\n    for (int j = 0;\
    \ j < n; ++j) dat[0][j] = a[j];\r\n    for (int i = 1; i < table_h; ++i) for (int\
    \ j = 0; j + (1 << i) <= n; ++j) {\r\n      dat[i][j] = fn(dat[i - 1][j], dat[i\
    \ - 1][j + (1 << (i - 1))]);\r\n    }\r\n  }\r\n\r\n  MeetSemilattice query(int\
    \ left, int right) const {\r\n    assert(is_built && left < right);\r\n    int\
    \ h = lg[right - left];\r\n    return fn(dat[h][left], dat[h][right - (1 << h)]);\r\
    \n  }\r\n\r\nprivate:\r\n  bool is_built = false;\r\n  Fn fn;\r\n  std::vector<int>\
    \ lg;\r\n  std::vector<std::vector<MeetSemilattice>> dat;\r\n};\r\n#line 9 \"\
    string/lcp.hpp\"\n\r\ntemplate <typename T = std::string>\r\nstruct LCP : SuffixArray<T>\
    \ {\r\n  std::vector<int> lcp_array;\r\n\r\n  LCP(const T &s) : SuffixArray<T>(s)\
    \ {\r\n    int n = s.size();\r\n    lcp_array.resize(n);\r\n    int common = 0;\r\
    \n    for (int i = 0; i < n; ++i) {\r\n      int j = this->sa[this->rank[i] -\
    \ 1];\r\n      if (common > 0) --common;\r\n      for (; i + common < n && j +\
    \ common < n; ++common) {\r\n        if (s[i + common] != s[j + common]) break;\r\
    \n      }\r\n      lcp_array[this->rank[i] - 1] = common;\r\n    }\r\n    st.init(lcp_array,\
    \ [](int a, int b) -> int { return std::min(a, b); });\r\n  }\r\n\r\n  int query(int\
    \ i, int j) const {\r\n    assert(i != j);\r\n    i = this->rank[i];\r\n    j\
    \ = this->rank[j];\r\n    if (i > j) std::swap(i, j);\r\n    return st.query(i,\
    \ j);\r\n  }\r\n\r\nprivate:\r\n  SparseTable<int> st;\r\n};\r\n#line 9 \"test/string/lcp.test.cpp\"\
    \n\r\nint main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  int n = s.length();\r\
    \n  LCP<> lcp(s);\r\n  long long ans = static_cast<long long>(n) * (n + 1) / 2;\r\
    \n  for (int e : LCP<>(s).lcp_array) ans -= e;\r\n  std::cout << ans << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/longest common prefix\r\n */\r\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\r\n\r\n#include\
    \ <iostream>\r\n#include <string>\r\n#include \"../../string/lcp.hpp\"\r\n\r\n\
    int main() {\r\n  std::string s;\r\n  std::cin >> s;\r\n  int n = s.length();\r\
    \n  LCP<> lcp(s);\r\n  long long ans = static_cast<long long>(n) * (n + 1) / 2;\r\
    \n  for (int e : LCP<>(s).lcp_array) ans -= e;\r\n  std::cout << ans << '\\n';\r\
    \n  return 0;\r\n}\r\n"
  dependsOn:
  - string/lcp.hpp
  - string/suffix_array.hpp
  - data_structure/sparse_table.hpp
  isVerificationFile: true
  path: test/string/lcp.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/lcp.test.cpp
layout: document
redirect_from:
- /verify/test/string/lcp.test.cpp
- /verify/test/string/lcp.test.cpp.html
title: "\u6587\u5B57\u5217/longest common prefix"
---
