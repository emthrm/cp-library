#pragma once
#include <functional>
#include <map>
#include <set>
#include <vector>

template <typename T>
int grundy_number(long long n, const std::vector<T> &trans) {
  std::map<long long, int> mp;
  std::function<int(long long)> rec = [&trans, &mp, &rec](long long now) -> int {
    if (mp.count(now) == 1) return mp[now];
    std::set<int> st;
    for (T e : trans) {
      if (now >= e) st.emplace(rec(now - e));
    }
    mp[now] = 0;
    while (st.count(mp[now]) == 1) ++mp[now];
    return mp[now];
  };
  return rec(n);
}
