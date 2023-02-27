---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (longest increasing subsequence)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    document_title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\
      \u5206\u5217"
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/dynamic_programming/longest_increasing_subsequence.test.cpp\"\
    \n/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\
    \u5217\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/longest_increasing_subsequence\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <limits>\n#line 8\
    \ \"include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp\"\n\n\
    namespace emthrm {\n\ntemplate <bool IS_STRICT = true, typename T>\nstd::vector<T>\
    \ longest_increasing_subsequence(const std::vector<T>& a) {\n  const T inf = std::numeric_limits<T>::max();\n\
    \  const int n = a.size();\n  std::vector<int> idx(n);\n  std::vector<T> tmp(n,\
    \ inf);\n  for (int i = 0; i < n; ++i) {\n    idx[i] = std::distance(\n      \
    \  tmp.begin(),\n        IS_STRICT ? std::lower_bound(tmp.begin(), tmp.end(),\
    \ a[i]) :\n                    std::upper_bound(tmp.begin(), tmp.end(), a[i]));\n\
    \    tmp[idx[i]] = a[i];\n  }\n  int res_size =\n      std::distance(tmp.begin(),\
    \ std::lower_bound(tmp.begin(), tmp.end(), inf));\n  std::vector<T> res(res_size--);\n\
    \  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {\n    if (idx[i] == res_size)\
    \ res[res_size--] = a[i];\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\
    \n#line 11 \"test/dynamic_programming/longest_increasing_subsequence.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::vector<int> ans;\n\
    \  int i = 0;\n  for (const int lis_i : emthrm::longest_increasing_subsequence(a))\
    \ {\n    while (a[i] != lis_i) ++i;\n    ans.emplace_back(i++);\n  }\n  const\
    \ int k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i)\
    \ {\n    std::cout << ans[i] << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/longest_increasing_subsequence\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/dynamic_programming/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::vector<int> ans;\n\
    \  int i = 0;\n  for (const int lis_i : emthrm::longest_increasing_subsequence(a))\
    \ {\n    while (a[i] != lis_i) ++i;\n    ans.emplace_back(i++);\n  }\n  const\
    \ int k = ans.size();\n  std::cout << k << '\\n';\n  for (int i = 0; i < k; ++i)\
    \ {\n    std::cout << ans[i] << \" \\n\"[i + 1 == k];\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/dynamic_programming/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dynamic_programming/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/dynamic_programming/longest_increasing_subsequence.test.cpp
- /verify/test/dynamic_programming/longest_increasing_subsequence.test.cpp.html
title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
---
