---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    document_title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/string/suffix_array.test.cpp\"\n/*\n * @title \u6587\
    \u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217\n *\n * verification-helper: PROBLEM\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n */\n\n\
    #include <iostream>\n#include <string>\n\n#line 1 \"include/emthrm/string/suffix_array.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <numeric>\n#line 7 \"include/emthrm/string/suffix_array.hpp\"\
    \n#include <vector>\n\nnamespace emthrm {\n\ntemplate <typename T = std::string>\n\
    requires requires { typename T::value_type; }\nstruct SuffixArray {\n  std::vector<int>\
    \ sa, rank;\n\n  explicit SuffixArray(const T& s_, const typename T::value_type\
    \ sentinel = 0)\n      : s(s_) {\n    const int n = s.size();\n    s.push_back(sentinel);\n\
    \    sa.resize(n + 1);\n    std::iota(sa.rbegin(), sa.rend(), 0);\n    std::ranges::stable_sort(\n\
    \        sa, {}, [this](const int index) -> int { return s[index]; });\n    rank.resize(n\
    \ + 1);\n    for (int i = 0; i <= n; ++i) {\n      rank[i] = s[i];\n    }\n  \
    \  std::vector<int> tmp(n + 1), prev_sa(n + 1);\n    for (int len = 1; len <=\
    \ n; len <<= 1) {\n      tmp[sa[0]] = 0;\n      for (int i = 1; i <= n; ++i) {\n\
    \        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&\n     \
    \       rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\n        \
    \  tmp[sa[i]] = tmp[sa[i - 1]];\n        } else {\n          tmp[sa[i]] = i;\n\
    \        }\n      }\n      rank.swap(tmp);\n      std::iota(tmp.begin(), tmp.end(),\
    \ 0);\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\n      for (int\
    \ i = 0; i <= n; ++i) {\n        const int idx = prev_sa[i] - len;\n        if\
    \ (idx >= 0) sa[tmp[rank[idx]]++] = idx;\n      }\n    }\n    for (int i = 0;\
    \ i <= n; ++i) {\n      rank[sa[i]] = i;\n    }\n  }\n\n  std::vector<int> match(T*\
    \ t) const {\n    const int lb = lower_bound(t);\n    ++t->back();\n    const\
    \ int ub = lower_bound(t);\n    --t->back();\n    std::vector<int> res(ub - lb);\n\
    \    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  T s;\n\n  int lower_bound(const\
    \ T* t) const {\n    const int s_size = s.size(), t_size = t->size();\n    int\
    \ lb = 0, ub = s_size;\n    while (ub - lb > 1) {\n      const int mid = std::midpoint(lb,\
    \ ub);\n      int s_idx = sa[mid], t_idx = 0;\n      bool finished = false;\n\
    \      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {\n        if\
    \ (s[s_idx] != (*t)[t_idx]) {\n          (s[s_idx] < (*t)[t_idx] ? lb : ub) =\
    \ mid;\n          finished = true;\n          break;\n        }\n      }\n   \
    \   if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;\n    }\n\
    \    return ub;\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 11 \"test/string/suffix_array.test.cpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::SuffixArray<>(t).match(&p)) {\n    std::cout << ans << '\\n';\n\
    \  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\n\
    \ */\n\n#include <iostream>\n#include <string>\n\n#include \"emthrm/string/suffix_array.hpp\"\
    \n\nint main() {\n  std::string t, p;\n  std::cin >> t >> p;\n  for (const int\
    \ ans : emthrm::SuffixArray<>(t).match(&p)) {\n    std::cout << ans << '\\n';\n\
    \  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/suffix_array.test.cpp
  requiredBy: []
  timestamp: '2023-07-07 02:42:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/suffix_array.test.cpp
layout: document
redirect_from:
- /verify/test/string/suffix_array.test.cpp
- /verify/test/string/suffix_array.test.cpp.html
title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
---
