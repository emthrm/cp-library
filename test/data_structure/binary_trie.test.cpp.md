---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/binary_trie.hpp
    title: binary trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/data_structure/binary_trie.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/binary trie\n */\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <iostream>\n\n#include\
    \ \"emthrm/data_structure/binary_trie.hpp\"\n\nint main() {\n  constexpr int B\
    \ = 30;\n  emthrm::BinaryTrie<B> binary_trie;\n  int q;\n  std::cin >> q;\n  while\
    \ (q--) {\n    int type, x;\n    std::cin >> type >> x;\n    if (type == 0) {\n\
    \      if (!binary_trie.find(x)) binary_trie.insert(x);\n    } else if (type ==\
    \ 1) {\n      binary_trie.erase(x);\n    } else if (type == 2) {\n      std::cout\
    \ << (binary_trie.min_element(x).second ^ x) << '\\n';\n    }\n  }\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/data_structure/binary_trie.hpp
  isVerificationFile: true
  path: test/data_structure/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2023-01-27 16:06:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/binary_trie.test.cpp
- /verify/test/data_structure/binary_trie.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/binary trie"
---
