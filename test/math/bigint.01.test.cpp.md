---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u4ED8\u304D\u6700\u5927\
      \u30DE\u30C3\u30C1\u30F3\u30B0"
  - icon: ':question:'
    path: include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528 $s$-$t$-\u30D5\u30ED\u30FC (minimum cost $s$-$t$-flow)\
      \ \u6700\u77ED\u8DEF\u53CD\u5FA9\u6CD5 (successive shortest path algorithm)\
      \ \u7248"
  - icon: ':question:'
    path: include/emthrm/math/bigint.hpp
    title: "\u591A\u500D\u9577\u6574\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679
    document_title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679
  bundledCode: "#line 1 \"test/math/bigint.01.test.cpp\"\n/*\n * @title \u6570\u5B66\
    /\u591A\u500D\u9577\u6574\u6570\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <string>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\n\n\n#include <cassert>\n#line 6 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n#include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #line 11 \"include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T, typename U>\nstruct MinimumCostSTFlow\
    \ {\n  struct Edge {\n    int dst, rev;\n    T cap;\n    U cost;\n    explicit\
    \ Edge(const int dst, const T cap, const U cost, const int rev)\n        : dst(dst),\
    \ rev(rev), cap(cap), cost(cost) {}\n  };\n\n  const U uinf;\n  std::vector<std::vector<Edge>>\
    \ graph;\n\n  explicit MinimumCostSTFlow(const int n,\n                      \
    \       const U uinf = std::numeric_limits<U>::max())\n      : uinf(uinf), graph(n),\
    \ tinf(std::numeric_limits<T>::max()), n(n),\n        has_negative_edge(false),\
    \ prev_v(n, -1), prev_e(n, -1), dist(n),\n        potential(n, 0) {}\n\n  void\
    \ add_edge(const int src, const int dst, const T cap, const U cost) {\n    has_negative_edge\
    \ |= cost < 0;\n    graph[src].emplace_back(dst, cap, cost, graph[dst].size());\n\
    \    graph[dst].emplace_back(src, 0, -cost, graph[src].size() - 1);\n  }\n\n \
    \ U solve(const int s, const int t, T flow) {\n    if (flow == 0) [[unlikely]]\
    \ return 0;\n    U res = 0;\n    has_negative_edge ? bellman_ford(s) : dijkstra(s);\n\
    \    while (true) {\n      if (dist[t] == uinf) return uinf;\n      res += calc(s,\
    \ t, &flow);\n      if (flow == 0) break;\n      dijkstra(s);\n    }\n    return\
    \ res;\n  }\n\n  U solve(const int s, const int t) {\n    U res = 0;\n    T flow\
    \ = tinf;\n    bellman_ford(s);\n    while (potential[t] < 0 && dist[t] != uinf)\
    \ {\n      res += calc(s, t, &flow);\n      dijkstra(s);\n    }\n    return res;\n\
    \  }\n\n  std::pair<T, U> minimum_cost_maximum_flow(const int s, const int t,\n\
    \                                            const T flow) {\n    if (flow ==\
    \ 0) [[unlikely]] return {0, 0};\n    T f = flow;\n    U cost = 0;\n    has_negative_edge\
    \ ? bellman_ford(s) : dijkstra(s);\n    while (dist[t] != uinf) {\n      cost\
    \ += calc(s, t, &f);\n      if (f == 0) break;\n      dijkstra(s);\n    }\n  \
    \  return {flow - f, cost};\n  }\n\n private:\n  const T tinf;\n  const int n;\n\
    \  bool has_negative_edge;\n  std::vector<int> prev_v, prev_e;\n  std::vector<U>\
    \ dist, potential;\n  std::priority_queue<std::pair<U, int>, std::vector<std::pair<U,\
    \ int>>,\n                      std::greater<std::pair<U, int>>> que;\n\n  void\
    \ bellman_ford(const int s) {\n    std::fill(dist.begin(), dist.end(), uinf);\n\
    \    dist[s] = 0;\n    bool is_updated = true;\n    for (int step = 0; step <\
    \ n && is_updated; ++step) {\n      is_updated = false;\n      for (int i = 0;\
    \ i < n; ++i) {\n        if (dist[i] == uinf) continue;\n        for (int j =\
    \ 0; std::cmp_less(j, graph[i].size()); ++j) {\n          const Edge& e = graph[i][j];\n\
    \          if (e.cap > 0 && dist[e.dst] > dist[i] + e.cost) {\n            dist[e.dst]\
    \ = dist[i] + e.cost;\n            prev_v[e.dst] = i;\n            prev_e[e.dst]\
    \ = j;\n            is_updated = true;\n          }\n        }\n      }\n    }\n\
    \    assert(!is_updated);\n    for (int i = 0; i < n; ++i) {\n      if (dist[i]\
    \ != uinf) potential[i] += dist[i];\n    }\n  }\n\n  void dijkstra(const int s)\
    \ {\n    std::fill(dist.begin(), dist.end(), uinf);\n    dist[s] = 0;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (dist[ver] < d) continue;\n      for (int i = 0; std::cmp_less(i,\
    \ graph[ver].size()); ++i) {\n        const Edge& e = graph[ver][i];\n       \
    \ const U nxt = dist[ver] + e.cost + potential[ver] - potential[e.dst];\n    \
    \    if (e.cap > 0 && dist[e.dst] > nxt) {\n          dist[e.dst] = nxt;\n   \
    \       prev_v[e.dst] = ver;\n          prev_e[e.dst] = i;\n          que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n      }\n    }\n    for (int i = 0; i < n; ++i) {\n    \
    \  if (dist[i] != uinf) potential[i] += dist[i];\n    }\n  }\n\n  U calc(const\
    \ int s, const int t, T* flow) {\n    T f = *flow;\n    for (int v = t; v != s;\
    \ v = prev_v[v]) {\n      f = std::min(f, graph[prev_v[v]][prev_e[v]].cap);\n\
    \    }\n    *flow -= f;\n    for (int v = t; v != s; v = prev_v[v]) {\n      Edge&\
    \ e = graph[prev_v[v]][prev_e[v]];\n      e.cap -= f;\n      graph[v][e.rev].cap\
    \ += f;\n    }\n    return potential[t] * f;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 8 \"include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct WeightedBipartiteMatching\
    \ {\n  explicit WeightedBipartiteMatching(const int left, const int right)\n \
    \     : is_built(false), left(left), right(right), mcf(left + right + 2) {}\n\n\
    \  void add_edge(const int src, const int dst, const T cost) {\n    mcf.add_edge(src,\
    \ left + dst, 1, -cost);\n  }\n\n  T solve() {\n    assert(!is_built);\n    is_built\
    \ = true;\n    const int s = left + right, t = left + right + 1;\n    for (int\
    \ i = 0; i < left; ++i) {\n      mcf.add_edge(s, i, 1, 0);\n    }\n    for (int\
    \ i = 0; i < right; ++i) {\n      mcf.add_edge(left + i, t, 1, 0);\n    }\n  \
    \  return -mcf.minimum_cost_maximum_flow(s, t, left).second;\n  }\n\n  std::vector<int>\
    \ matching() const {\n    assert(is_built);\n    std::vector<int> res(left, -1);\n\
    \    for (int i = 0; i < left; ++i) {\n      for (const auto& e : mcf.graph[i])\
    \ {\n        if (e.cap == 0 && left <= e.dst && e.dst < left + right) {\n    \
    \      res[i] = e.dst - left;\n          break;\n        }\n      }\n    }\n \
    \   return res;\n  }\n\n private:\n  bool is_built;\n  const int left, right;\n\
    \  MinimumCostSTFlow<int, T> mcf;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"\
    include/emthrm/math/bigint.hpp\"\n\n\n\n#line 6 \"include/emthrm/math/bigint.hpp\"\
    \n#include <cmath>\n#include <compare>\n#include <iomanip>\n#line 10 \"include/emthrm/math/bigint.hpp\"\
    \n#include <iterator>\n#line 12 \"include/emthrm/math/bigint.hpp\"\n#include <sstream>\n\
    #line 16 \"include/emthrm/math/bigint.hpp\"\n\nnamespace emthrm {\n\ntemplate\
    \ <int LOG_B = 9, int B = 1000000000>  // B = 10^{LOG_B}\nstruct BigInt {\n  int\
    \ sgn;\n  std::vector<int> data;\n\n  BigInt(const long long val = 0) { *this\
    \ = val; }\n  BigInt(const std::string& s) { *this = s; }\n\n  std::vector<long\
    \ long> convert_base(const int next_log_b,\n                                 \
    \     const int next_b) const {\n    assert(next_b == std::llround(std::pow(10,\
    \ next_log_b)));\n    const int max_base = std::max(LOG_B, next_log_b);\n    std::vector<long\
    \ long> p(max_base + 1, 1);\n    for (int i = 1; i <= max_base; ++i) {\n     \
    \ p[i] = p[i - 1] * 10;\n    }\n    std::vector<long long> res;\n    long long\
    \ cur_val = 0;\n    int cur_log_b = 0;\n    for (const int e : data) {\n     \
    \ cur_val += p[cur_log_b] * e;\n      cur_log_b += LOG_B;\n      for (; cur_log_b\
    \ >= next_log_b; cur_log_b -= next_log_b) {\n        res.emplace_back(cur_val\
    \ % next_b);\n        cur_val /= next_b;\n      }\n    }\n    res.emplace_back(cur_val);\n\
    \    while (!res.empty() && res.back() == 0) res.pop_back();\n    return res;\n\
    \  }\n\n  int digit_sum() const {\n    assert(sgn == 1);\n    int res = 0;\n \
    \   for (char c : to_string()) res += c - '0';\n    return res;\n  }\n\n  int\
    \ length() const {\n    if (data.empty()) return 0;\n    int res = LOG_B * (data.size()\
    \ - 1);\n    for (int tmp = data.back(); tmp > 0; tmp /= 10) {\n      ++res;\n\
    \    }\n    return res;\n  }\n\n  BigInt pow(BigInt exponent) const {\n    BigInt\
    \ res = 1, tmp = *this;\n    for (; exponent > 0; exponent /= 2) {\n      if (exponent.data.front()\
    \ & 1) res *= tmp;\n      tmp *= tmp;\n    }\n    return res;\n  }\n\n  long long\
    \ to_llong() const {\n    assert(*this >= std::numeric_limits<long long>::min()\
    \ &&\n           *this <= std::numeric_limits<long long>::max());\n    long long\
    \ res = 0;\n    for (int i = std::ssize(data) - 1; i >= 0; --i) {\n      res =\
    \ res * B + data[i];\n    }\n    return res;\n  }\n\n  std::string to_string()\
    \ const {\n    std::stringstream ss;\n    ss << *this;\n    std::string res;\n\
    \    ss >> res;\n    return res;\n  }\n\n  void trim() {\n    while (!data.empty()\
    \ && data.back() == 0) data.pop_back();\n    if (data.empty()) sgn = 1;\n  }\n\
    \n  BigInt& operator=(long long val) {\n    if (val < 0) {\n      sgn = -1;\n\
    \      val = -val;\n    } else {\n      sgn = 1;\n    }\n    data.clear();\n \
    \   for (; val > 0; val /= B) {\n      data.emplace_back(val % B);\n    }\n  \
    \  return *this;\n  }\n  BigInt& operator=(const std::string& s) {\n    sgn =\
    \ 1;\n    data.clear();\n    if (!s.empty()) {\n      int tail = 0;\n      if\
    \ (s.front() == '-') {\n        sgn = -1;\n        tail = 1;\n      } else if\
    \ (s.front() == '+') {\n        tail = 1;\n      }\n      for (int i = s.length()\
    \ - 1; i >= tail; i -= LOG_B) {\n        int val = 0;\n        for (int j = std::max(tail,\
    \ i - LOG_B + 1); j <= i; ++j) {\n          val = val * 10 + (s[j] - '0');\n \
    \       }\n        data.emplace_back(val);\n      }\n    }\n    trim();\n    return\
    \ *this;\n  }\n  BigInt& operator=(const BigInt& x) = default;\n\n  BigInt& operator+=(const\
    \ BigInt& x) {\n    if (sgn != x.sgn) return x.data.empty() ? *this : *this -=\
    \ -x;\n    if (data.size() < x.data.size()) data.resize(x.data.size(), 0);\n \
    \   bool carry = false;\n    for (int i = 0; std::cmp_less(i, x.data.size()) ||\
    \ carry; ++i) {\n      if (std::cmp_equal(i, data.size())) data.emplace_back(0);\n\
    \      data[i] += (std::cmp_less(i, x.data.size()) ? x.data[i] : 0) + carry;\n\
    \      if (data[i] >= B) {\n        carry = true;\n        data[i] -= B;\n   \
    \   } else {\n        carry = false;\n      }\n    }\n    return *this;\n  }\n\
    \n  BigInt& operator-=(const BigInt& x) {\n    if (sgn != x.sgn) return *this\
    \ += -x;\n    if ((sgn == 1 ? *this : -*this) < (x.sgn == 1 ? x : -x)) {\n   \
    \   return *this = -(x - *this);\n    }\n    bool carry = false;\n    for (int\
    \ i = 0; std::cmp_less(i, data.size()) || carry; ++i) {\n      data[i] -= (std::cmp_less(i,\
    \ x.data.size()) ? x.data[i] : 0) + carry;\n      if (data[i] < 0) {\n       \
    \ carry = true;\n        data[i] += B;\n      } else {\n        carry = false;\n\
    \      }\n    }\n    trim();\n    return *this;\n  }\n\n  BigInt& operator*=(const\
    \ BigInt& x) {\n    constexpr int next_log_b = 6, next_b = 1000000;\n    std::vector<long\
    \ long> this6 = convert_base(next_log_b, next_b);\n    std::vector<long long>\
    \ x6 = x.convert_base(next_log_b, next_b);\n    std::vector<long long> res = karatsuba(&this6,\
    \ 0, this6.size(),\n                                           &x6, 0, x6.size());\n\
    \    for (int i = 0; std::cmp_less(i, res.size()); ++i) {\n      const long long\
    \ quo = res[i] / next_b;\n      if (quo > 0) {\n        if (std::cmp_equal(i +\
    \ 1, res.size())) {\n          res.emplace_back(quo);\n        } else {\n    \
    \      res[i + 1] += quo;\n        }\n        res[i] %= next_b;\n      }\n   \
    \ }\n    std::string s = (sgn * x.sgn == 1 ? \"+\" : \"-\");\n    for (int i =\
    \ std::ssize(res) - 1; i >= 0; --i) {\n      const std::string tmp = std::to_string(res[i]);\n\
    \      s += std::string(next_log_b - tmp.length(), '0') + tmp;\n    }\n    return\
    \ *this = s;\n  }\n\n  BigInt& operator/=(const int x) { return *this = divide(x).first;\
    \ }\n  BigInt& operator/=(const BigInt& x) { return *this = divide(x).first; }\n\
    \  BigInt& operator%=(const int x) { return *this = divide(x).second; }\n  BigInt&\
    \ operator%=(const BigInt& x) { return *this = divide(x).second; }\n\n  std::strong_ordering\
    \ operator<=>(const BigInt& x) const {\n    if (sgn != x.sgn) return sgn <=> x.sgn;\n\
    \    if (data.size() != x.data.size()) {\n      return sgn * data.size() <=> x.sgn\
    \ * x.data.size();\n    }\n    for (int i = std::ssize(data) - 1; i >= 0; --i)\
    \ {\n      if (data[i] != x.data[i]) return data[i] * sgn <=> x.data[i] * x.sgn;\n\
    \    }\n    return std::strong_ordering::equivalent;\n  }\n  bool operator==(const\
    \ BigInt& x) const {\n    if (sgn != x.sgn || data.size() != x.data.size()) return\
    \ false;\n    const int n = data.size();\n    for (int i = 0; i < n; ++i) {\n\
    \      if (data[i] != x.data[i]) return false;\n    }\n    return true;\n  }\n\
    \n  BigInt& operator++() { return *this += 1; }\n  BigInt operator++(int) {\n\
    \    const BigInt res = *this;\n    ++*this;\n    return res;\n  }\n  BigInt&\
    \ operator--() { return *this -= 1; }\n  BigInt operator--(int) {\n    const BigInt\
    \ res = *this;\n    --*this;\n    return res;\n  }\n\n  BigInt operator+() const\
    \ { return *this; }\n  BigInt operator-() const {\n    BigInt res = *this;\n \
    \   if (!res.data.empty()) res.sgn = -res.sgn;\n    return res;\n  }\n\n  BigInt\
    \ operator+(const BigInt& x) const { return BigInt(*this) += x; }\n  BigInt operator-(const\
    \ BigInt& x) const { return BigInt(*this) -= x; }\n  BigInt operator*(const BigInt&\
    \ x) const { return BigInt(*this) *= x; }\n  BigInt operator/(const int x) const\
    \ { return BigInt(*this) /= x; }\n  BigInt operator/(const BigInt& x) const {\
    \ return BigInt(*this) /= x; }\n  BigInt operator%(const int x) const { return\
    \ BigInt(*this) %= x; }\n  BigInt operator%(const BigInt& x) const { return BigInt(*this)\
    \ %= x; }\n\n  friend std::ostream& operator<<(std::ostream& os, const BigInt&\
    \ x) {\n    if (x.sgn == -1) os << '-';\n    os << (x.data.empty() ? 0 : x.data.back());\n\
    \    for (int i = std::ssize(x.data) - 2; i >= 0; --i) {\n      os << std::setw(LOG_B)\
    \ << std::setfill('0') << x.data[i];\n    }\n    return os;\n  }\n  friend std::istream&\
    \ operator>>(std::istream& is, BigInt& x) {\n    std::string s;\n    is >> s;\n\
    \    x = s;\n    return is;\n  }\n\n private:\n  std::vector<long long> karatsuba(\n\
    \      std::vector<long long>* a, const int a_l, const int a_r,\n      std::vector<long\
    \ long>* b, const int b_l, const int b_r) const {\n    const int a_len = a_r -\
    \ a_l, b_len = b_r - b_l;\n    if (a_len < b_len) return karatsuba(b, b_l, b_r,\
    \ a, a_l, a_r);\n    std::vector<long long> res(a_len + b_len, 0);\n    if (b_len\
    \ <= 32) {\n      for (int i = a_l; i < a_r; ++i) {\n        for (int j = b_l;\
    \ j < b_r; ++j) {\n          res[(i - a_l) + (j - b_l)] += (*a)[i] * (*b)[j];\n\
    \        }\n      }\n    } else {\n      const int mid = (a_len + 1) / 2, n =\
    \ std::min(a_len, mid);\n      for (int i = a_l; i + mid < a_r; ++i) {\n     \
    \   (*a)[i] += (*a)[i + mid];\n      }\n      for (int i = b_l; i + mid < b_r;\
    \ ++i) {\n        (*b)[i] += (*b)[i + mid];\n      }\n      std::ranges::copy(karatsuba(a,\
    \ a_l, a_l + mid, b, b_l, b_l + n),\n                        std::next(res.begin(),\
    \ mid));\n      for (int i = a_l; i + mid < a_r; ++i) {\n        (*a)[i] -= (*a)[i\
    \ + mid];\n      }\n      for (int i = b_l; i + mid < b_r; ++i) {\n        (*b)[i]\
    \ -= (*b)[i + mid];\n      }\n      std::vector<long long> tmp =\n          karatsuba(a,\
    \ a_l, a_l + mid, b, b_l, b_l + n);\n      for (int i = 0; std::cmp_less(i, tmp.size());\
    \ ++i) {\n        res[i] += tmp[i];\n        res[mid + i] -= tmp[i];\n      }\n\
    \      tmp = karatsuba(a, a_l + mid, a_r, b, b_l + n, b_r);\n      for (int i\
    \ = 0; std::cmp_less(i, tmp.size()); ++i) {\n        res[mid + i] -= tmp[i];\n\
    \        res[(mid << 1) + i] += tmp[i];\n      }\n    }\n    while (!res.empty()\
    \ && res.back() == 0) res.pop_back();\n    return res;\n  }\n\n  std::pair<BigInt,\
    \ int> divide(int x) const {\n    assert(x != 0);\n    BigInt dividend = *this;\n\
    \    if (x < 0) {\n      dividend.sgn = -dividend.sgn;\n      x = -x;\n    }\n\
    \    long long rem = 0;\n    for (int i = std::ssize(dividend.data) - 1; i >=\
    \ 0; --i) {\n      const long long tmp = rem * B + dividend.data[i];\n      dividend.data[i]\
    \ = tmp / x;\n      rem = tmp % x;\n    }\n    dividend.trim();\n    return {dividend,\
    \ static_cast<int>(rem)};\n  }\n\n  std::pair<BigInt, BigInt> divide(const BigInt&\
    \ x) const {\n    assert(!x.data.empty());\n    const int k = B / (x.data.back()\
    \ + 1);\n    const BigInt dividend = (sgn == 1 ? *this : -*this) * k;\n    const\
    \ BigInt divisor = (x.sgn == 1 ? x : -x) * k;\n    BigInt quo, rem = 0;\n    quo.data.resize(dividend.data.size());\n\
    \    const int n = divisor.data.size();\n    for (int i = std::ssize(dividend.data)\
    \ - 1; i >= 0; --i) {\n      rem.data.emplace(rem.data.begin(), dividend.data[i]);\n\
    \      quo.data[i] =\n          ((std::cmp_less(n, rem.data.size()) ?\n      \
    \      static_cast<long long>(rem.data[n]) * B : 0)\n           + (std::cmp_less(n\
    \ - 1, rem.data.size()) ? rem.data[n - 1] : 0))\n          / divisor.data.back();\n\
    \      rem -= divisor * quo.data[i];\n      while (rem.sgn == -1) {\n        rem\
    \ += divisor;\n        --quo.data[i];\n      }\n    }\n    quo.sgn = sgn * x.sgn;\n\
    \    quo.trim();\n    rem.sgn = sgn;\n    rem.trim();\n    return {quo, rem /\
    \ k};\n  }\n};\n\n}  // namespace emthrm\n\nnamespace std {\n\ntemplate <int LOG_B,\
    \ int B>\nemthrm::BigInt<LOG_B, B> gcd(emthrm::BigInt<LOG_B, B> a,\n         \
    \                    emthrm::BigInt<LOG_B, B> b) {\n  while (!b.data.empty())\
    \ std::swap(a %= b, b);\n  return a;\n}\n\ntemplate <int LOG_B, int B>\nemthrm::BigInt<LOG_B,\
    \ B> lcm(const emthrm::BigInt<LOG_B, B>& a,\n                             const\
    \ emthrm::BigInt<LOG_B, B>& b) {\n  return a / std::__gcd(a, b) * b;\n}\n\ntemplate\
    \ <int LOG_B, int B>\nemthrm::BigInt<LOG_B, B> abs(const emthrm::BigInt<LOG_B,\
    \ B>& x) {\n  return x.sgn == 1 ? x : -x;\n}\n\ntemplate <int LOG_B, int B>\n\
    emthrm::BigInt<LOG_B, B> max(const emthrm::BigInt<LOG_B, B>& a,\n            \
    \                 const emthrm::BigInt<LOG_B, B>& b) {\n  return a < b ? b : a;\n\
    }\n\ntemplate <int LOG_B, int B>\nemthrm::BigInt<LOG_B, B> min(const emthrm::BigInt<LOG_B,\
    \ B>& a,\n                             const emthrm::BigInt<LOG_B, B>& b) {\n\
    \  return a < b ? a : b;\n}\n\n}  // namespace std\n\n\n#line 15 \"test/math/bigint.01.test.cpp\"\
    \n\nnamespace std {\n\ntemplate <int LOG_B, int B>\nstruct numeric_limits<emthrm::BigInt<LOG_B,\
    \ B>> {\n  static constexpr emthrm::BigInt<LOG_B, B> max() {\n    return static_cast<std::string>(\n\
    \        \"453152254949043485887196599220742984693877551020408163265306122448979591836734693877551\"\
    );\n  }\n};\n\n};  // namespace std\n\nint main() {\n  using bigint = emthrm::BigInt<>;\n\
    \  constexpr int SIGMA = 26;\n  int n;\n  std::cin >> n;\n  std::map<char, bigint>\
    \ cost;\n  bigint cur = 0;\n  for (int i = SIGMA - 1; i >= 0; --i) {\n    cost['a'\
    \ + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n  }\n  for (int i = SIGMA - 1;\
    \ i >= 0; --i) {\n    cost['A' + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n \
    \ }\n  std::vector<std::string> c(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> c[i];\n  }\n  emthrm::WeightedBipartiteMatching<bigint> weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> c[i];\n    for (int j\
    \ = 0; j < n; ++j) {\n      weighted_bipartite_matching.add_edge(i, j, cost[c[i][j]]);\n\
    \    }\n  }\n  weighted_bipartite_matching.solve();\n  std::string ans = \"\"\
    ;\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    ans += c[i][matching[i]];\n  }\n  std::sort(ans.begin(),\
    \ ans.end());\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u591A\u500D\u9577\u6574\u6570\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2679\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <string>\n\
    #include <vector>\n\n#include \"emthrm/graph/flow/matching/weighted_bipartite_matching.hpp\"\
    \n#include \"emthrm/math/bigint.hpp\"\n\nnamespace std {\n\ntemplate <int LOG_B,\
    \ int B>\nstruct numeric_limits<emthrm::BigInt<LOG_B, B>> {\n  static constexpr\
    \ emthrm::BigInt<LOG_B, B> max() {\n    return static_cast<std::string>(\n   \
    \     \"453152254949043485887196599220742984693877551020408163265306122448979591836734693877551\"\
    );\n  }\n};\n\n};  // namespace std\n\nint main() {\n  using bigint = emthrm::BigInt<>;\n\
    \  constexpr int SIGMA = 26;\n  int n;\n  std::cin >> n;\n  std::map<char, bigint>\
    \ cost;\n  bigint cur = 0;\n  for (int i = SIGMA - 1; i >= 0; --i) {\n    cost['a'\
    \ + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n  }\n  for (int i = SIGMA - 1;\
    \ i >= 0; --i) {\n    cost['A' + i] = cur;\n    cur = cur * SIGMA * 2 + 1;\n \
    \ }\n  std::vector<std::string> c(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> c[i];\n  }\n  emthrm::WeightedBipartiteMatching<bigint> weighted_bipartite_matching(n,\
    \ n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> c[i];\n    for (int j\
    \ = 0; j < n; ++j) {\n      weighted_bipartite_matching.add_edge(i, j, cost[c[i][j]]);\n\
    \    }\n  }\n  weighted_bipartite_matching.solve();\n  std::string ans = \"\"\
    ;\n  const std::vector<int> matching = weighted_bipartite_matching.matching();\n\
    \  for (int i = 0; i < n; ++i) {\n    ans += c[i][matching[i]];\n  }\n  std::sort(ans.begin(),\
    \ ans.end());\n  std::cout << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp
  - include/emthrm/graph/flow/minimum_cost_flow/minimum_cost_s-t-flow.hpp
  - include/emthrm/math/bigint.hpp
  isVerificationFile: true
  path: test/math/bigint.01.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/bigint.01.test.cpp
layout: document
redirect_from:
- /verify/test/math/bigint.01.test.cpp
- /verify/test/math/bigint.01.test.cpp.html
title: "\u6570\u5B66/\u591A\u500D\u9577\u6574\u6570"
---
