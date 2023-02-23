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
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    document_title: "\u6587\u5B57\u5217/longest common prefix"
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/longest_common_prefix.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u6587\u5B57\u5217/longest common prefix\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#include <iostream>\n\
    #include <string>\n\n#include \"emthrm/string/longest_common_prefix.hpp\"\n\n\
    int main() {\n  std::string s;\n  std::cin >> s;\n  const int n = s.length();\n\
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
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/longest_common_prefix.test.cpp
layout: document
redirect_from:
- /verify/test/string/longest_common_prefix.test.cpp
- /verify/test/string/longest_common_prefix.test.cpp.html
title: "\u6587\u5B57\u5217/longest common prefix"
---
