---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree (binary indexed tree)
  - icon: ':heavy_check_mark:'
    path: include/emthrm/misc/inversion_number.hpp
    title: "\u8EE2\u5012\u6570 (inversion number)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    document_title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/misc/inversion_number.test.cpp\"\n/*\n * @title \u305D\
    \u306E\u4ED6/\u8EE2\u5012\u6570\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/misc/inversion_number.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#line 7 \"include/emthrm/misc/inversion_number.hpp\"\
    \n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\n\n\
    \n\n#include <bit>\n#line 6 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTree {\n\
    \  explicit FenwickTree(const int n, const Abelian ID = 0)\n      : n(n), ID(ID),\
    \ data(n, ID) {}\n\n  void add(int idx, const Abelian val) {\n    for (; idx <\
    \ n; idx |= idx + 1) {\n      data[idx] += val;\n    }\n  }\n\n  Abelian sum(int\
    \ idx) const {\n    Abelian res = ID;\n    for (--idx; idx >= 0; idx = (idx &\
    \ (idx + 1)) - 1) {\n      res += data[idx];\n    }\n    return res;\n  }\n\n\
    \  Abelian sum(const int left, const int right) const {\n    return left < right\
    \ ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const int idx) const\
    \ { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val) const {\n  \
    \  if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for (int mask\
    \ = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n         mask > 0;\
    \ mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx < n && data[idx]\
    \ < val) {\n        val -= data[idx];\n        res += mask;\n      }\n    }\n\
    \    return res;\n  }\n\n private:\n  const int n;\n  const Abelian ID;\n  std::vector<Abelian>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 9 \"include/emthrm/misc/inversion_number.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nlong long inversion_number(const\
    \ std::vector<T>& a) {\n  const int n = a.size();\n  std::vector<T> b = a;\n \
    \ std::sort(b.begin(), b.end());\n  b.erase(std::unique(b.begin(), b.end()), b.end());\n\
    \  FenwickTree<int> bit(b.size());\n  long long res = 0;\n  for (int i = 0; i\
    \ < n; ++i) {\n    const int idx = std::distance(\n        b.begin(), std::lower_bound(b.begin(),\
    \ b.end(), a[i]));\n    res += i - bit.sum(idx + 1);\n    bit.add(idx, 1);\n \
    \ }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 11 \"test/misc/inversion_number.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::cout << emthrm::inversion_number(a)\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u305D\u306E\u4ED6/\u8EE2\u5012\u6570\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/misc/inversion_number.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::cout << emthrm::inversion_number(a)\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/misc/inversion_number.hpp
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  isVerificationFile: true
  path: test/misc/inversion_number.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/inversion_number.test.cpp
layout: document
redirect_from:
- /verify/test/misc/inversion_number.test.cpp
- /verify/test/misc/inversion_number.test.cpp.html
title: "\u305D\u306E\u4ED6/\u8EE2\u5012\u6570"
---
