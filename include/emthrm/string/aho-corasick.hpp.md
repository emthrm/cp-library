---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/trie.hpp
    title: "\u30C8\u30E9\u30A4\u6728 (trie)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/aho-corasick.test.cpp
    title: "\u6587\u5B57\u5217/Aho\u2013Corasick algorithm"
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/string/trie.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef EMTHRM_STRING_AHO_CORASICK_HPP_\n#define EMTHRM_STRING_AHO_CORASICK_HPP_\n\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <map>\n\
    #include <queue>\n#include <string>\n#include <vector>\n\n#include \"emthrm/string/trie.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <int Sigma = 26, bool IS_FULL_VER = false>\n\
    struct AhoCorasick : Trie<Sigma + 1> {\n  using Trie<Sigma + 1>::Trie;\n\n  std::vector<int>\
    \ nums;\n\n  void build() {\n    auto& vertices = this->nodes;\n    const int\
    \ n = vertices.size();\n    nums.resize(n);\n    for (int i = 0; i < n; ++i) {\n\
    \      if constexpr (IS_FULL_VER) {\n        std::sort(vertices[i].tails.begin(),\
    \ vertices[i].tails.end());\n      }\n      nums[i] = vertices[i].tails.size();\n\
    \    }\n    std::queue<int> que;\n    for (int i = 0; i < Sigma; ++i) {\n    \
    \  if (vertices.front().nxt[i] == -1) {\n        vertices.front().nxt[i] = 0;\n\
    \      } else {\n        vertices[vertices.front().nxt[i]].nxt[Sigma] = 0;\n \
    \       que.emplace(vertices.front().nxt[i]);\n      }\n    }\n    while (!que.empty())\
    \ {\n      const auto& node = vertices[que.front()];\n      nums[que.front()]\
    \ += nums[node.nxt[Sigma]];\n      que.pop();\n      for (int i = 0; i < Sigma;\
    \ ++i) {\n        if (node.nxt[i] == -1) continue;\n        int on_failure = node.nxt[Sigma];\n\
    \        while (vertices[on_failure].nxt[i] == -1) {\n          on_failure = vertices[on_failure].nxt[Sigma];\n\
    \        }\n        vertices[node.nxt[i]].nxt[Sigma] = vertices[on_failure].nxt[i];\n\
    \        if constexpr (IS_FULL_VER) {\n          std::vector<int>& ids = vertices[node.nxt[i]].tails;\n\
    \          std::vector<int> tmp;\n          std::set_union(ids.begin(), ids.end(),\n\
    \                         vertices[vertices[on_failure].nxt[i]].tails.begin(),\n\
    \                         vertices[vertices[on_failure].nxt[i]].tails.end(),\n\
    \                         std::back_inserter(tmp));\n          ids.resize(tmp.size());\n\
    \          std::copy(tmp.begin(), tmp.end(), ids.begin());\n        }\n      \
    \  que.emplace(node.nxt[i]);\n      }\n    }\n  }\n\n  int move(char c, int pos)\
    \ const {\n    const int c_int = this->convert(c);\n    while (this->nodes[pos].nxt[c_int]\
    \ == -1) pos = this->nodes[pos].nxt[Sigma];\n    return pos = this->nodes[pos].nxt[c_int];\n\
    \  }\n\n  int match(const std::string& t, int pos = 0) const {\n    int total\
    \ = 0;\n    for (const char c : t) {\n      pos = move(c, pos);\n      total +=\
    \ nums[pos];\n    }\n    return total;\n  }\n\n  std::map<int, int> match_fully(const\
    \ std::string& t, int pos = 0) const {\n    static_assert(IS_FULL_VER);\n    std::map<int,\
    \ int> mp;\n    for (const char c : t) {\n      pos = move(c, pos);\n      for\
    \ (const int id : this->nodes[pos].tails) ++mp[id];\n    }\n    return mp;\n \
    \ }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_AHO_CORASICK_HPP_\n"
  dependsOn:
  - include/emthrm/string/trie.hpp
  isVerificationFile: false
  path: include/emthrm/string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2023-02-23 21:59:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/aho-corasick.test.cpp
documentation_of: include/emthrm/string/aho-corasick.hpp
layout: document
title: "Aho\u2013Corasick algorithm"
---

[トライ木](./trie.md)を用いてパターンマッチングを行うアルゴリズムである。


## 時間計算量

検索する文字列の長さを $N$, トライ木に追加する文字列の長さを $M$ とおくと $\langle O(\sum{M}), O(N + \sum{M}) \rangle$


## 仕様

```cpp
template <int Sigma = 26, bool IS_FULL_VER = false>
struct AhoCorasick : Trie<Sigma + 1>;
```

- `Sigma`：アルファベットサイズ
- `IS_FULL_VER`：完全版かを表す変数

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> nums`|各ノードが保有する文字列の数|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
||[継承コンストラクタ](./trie.md)||
|`void build();`|オートマトンを構築する。||
|`int move(char c, int pos) const;`|$\mathrm{pos}$ 番目のノードから見たときに、文字 $c$ に対応するノードのインデックス||
|`int match(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードをから見たときに、文字列 $T$ とマッチする回数||
|`std::map<int, int> match_fully(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードから見たときに、文字列 $T$ とそれぞれの文字列がマッチする回数|完全版|


## 参考文献

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/02578ddfa9d2a46e3c724df82e84797dd41eabac/string/ahocorasick.cpp


## Submissons

https://yukicoder.me/submissions/575927
