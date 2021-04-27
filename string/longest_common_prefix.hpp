#pragma once
#include <algorithm>
#include <cassert>
#include <string>
#include <utility>
#include <vector>
#include "suffix_array.hpp"
#include "../data_structure/sparse_table.hpp"

template <typename T = std::string>
struct LongestCommonPrefix : SuffixArray<T> {
  std::vector<int> lcp_array;

  LongestCommonPrefix(const T &s) : SuffixArray<T>(s) {
    int n = s.size();
    lcp_array.resize(n);
    int common = 0;
    for (int i = 0; i < n; ++i) {
      int j = this->sa[this->rank[i] - 1];
      if (common > 0) --common;
      for (; i + common < n && j + common < n; ++common) {
        if (s[i + common] != s[j + common]) break;
      }
      lcp_array[this->rank[i] - 1] = common;
    }
    st.init(lcp_array, [](int a, int b) -> int { return std::min(a, b); });
  }

  int query(int i, int j) const {
    assert(i != j);
    i = this->rank[i];
    j = this->rank[j];
    if (i > j) std::swap(i, j);
    return st.query(i, j);
  }

private:
  SparseTable<int> st;
};
