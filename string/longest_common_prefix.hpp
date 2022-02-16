#pragma once
#include <algorithm>
#include <cassert>
#include <string>
#include <utility>
#include <vector>

#include "../data_structure/sparse_table.hpp"
#include "suffix_array.hpp"

template <typename T = std::string>
struct LongestCommonPrefix : SuffixArray<T> {
  std::vector<int> lcp_array;

  explicit LongestCommonPrefix(const T& s) : SuffixArray<T>(s) {
    const int n = s.size();
    lcp_array.resize(n);
    for (int i = 0, common = 0; i < n; ++i) {
      const int j = this->sa[this->rank[i] - 1];
      if (common > 0) --common;
      while (i + common < n && j + common < n &&
             s[i + common] == s[j + common]) {
        ++common;
      }
      lcp_array[this->rank[i] - 1] = common;
    }
    st.init(lcp_array, [](const int a, const int b) -> int {
      return std::min(a, b);
    });
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
