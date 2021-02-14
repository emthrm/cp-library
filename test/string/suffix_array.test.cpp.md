---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/suffix_array.test.cpp\"\n/*\r\n * @brief \u6587\
    \u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#line 2 \"string/suffix_array.hpp\"\
    \n#include <algorithm>\r\n#include <numeric>\r\n#line 5 \"string/suffix_array.hpp\"\
    \n#include <vector>\r\n\r\ntemplate <typename T = std::string>\r\nstruct SuffixArray\
    \ {\r\n  std::vector<int> sa, rank;\r\n\r\n  SuffixArray(const T &s_) : s(s_)\
    \ {\r\n    int n = s.size();\r\n    s.push_back(' ');\r\n    sa.resize(n + 1);\r\
    \n    std::iota(sa.begin(), sa.end(), 0);\r\n    std::sort(sa.begin(), sa.end(),\
    \ [&](int a, int b) -> bool { return s[a] == s[b] ? a > b : s[a] < s[b]; });\r\
    \n    rank.resize(n + 1);\r\n    for (int i = 0; i <= n; ++i) rank[i] = s[i];\r\
    \n    std::vector<int> tmp(n + 1), prev_sa(n + 1);\r\n    for (int len = 1; len\
    \ <= n; len <<= 1) {\r\n      tmp[sa[0]] = 0;\r\n      for (int i = 1; i <= n;\
    \ ++i) {\r\n        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n\
    \ && rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\r\n         \
    \ tmp[sa[i]] = tmp[sa[i - 1]];\r\n        } else {\r\n          tmp[sa[i]] = i;\r\
    \n        }\r\n      }\r\n      rank.swap(tmp);\r\n      std::iota(tmp.begin(),\
    \ tmp.end(), 0);\r\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\r\n\
    \      for (int i = 0; i <= n; ++i) {\r\n        int idx = prev_sa[i] - len;\r\
    \n        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\r\n      }\r\n    }\r\n  \
    \  for (int i = 0; i <= n; ++i) rank[sa[i]] = i;\r\n  }\r\n\r\n  std::vector<int>\
    \ match(T &t) const {\r\n    int lb = lower_bound(t);\r\n    ++t.back();\r\n \
    \   int ub = lower_bound(t);\r\n    --t.back();\r\n    std::vector<int> res(ub\
    \ - lb);\r\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\r\n\
    \    std::sort(res.begin(), res.end());\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  T s;\r\n\r\n  int lower_bound(const T &t) const {\r\n    int s_sz = s.size(),\
    \ t_sz = t.size(), lb = 0, ub = s_sz;\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1, s_idx = sa[mid], t_idx = 0;\r\n      bool finished = false;\r\
    \n      for (; s_idx < s_sz && t_idx < t_sz; ++s_idx, ++t_idx) {\r\n        if\
    \ (s[s_idx] != t[t_idx]) {\r\n          (s[s_idx] < t[t_idx] ? lb : ub) = mid;\r\
    \n          finished = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!finished) (s_idx == s_sz && t_idx < t_sz ? lb : ub) = mid;\r\n    }\r\
    \n    return ub;\r\n  }\r\n};\r\n#line 9 \"test/string/suffix_array.test.cpp\"\
    \n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  for (int\
    \ ans : SuffixArray<>(t).match(p)) std::cout << ans << '\\n';\r\n  return 0;\r\
    \n}\r\n"
  code: "/*\r\n * @brief \u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217\r\n */\r\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include \"../../string/suffix_array.hpp\"\
    \r\n\r\nint main() {\r\n  std::string t, p;\r\n  std::cin >> t >> p;\r\n  for\
    \ (int ans : SuffixArray<>(t).match(p)) std::cout << ans << '\\n';\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/test/string/suffix_array.test.cpp
- /verify/test/string/suffix_array.test.cpp.html
title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
---