#ifndef EMTHRM_STRING_SUFFIX_ARRAY_HPP_
#define EMTHRM_STRING_SUFFIX_ARRAY_HPP_

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace emthrm {

template <typename T = std::string>
struct SuffixArray {
  std::vector<int> sa, rank;

  template <typename U = char>
  explicit SuffixArray(const T& s_, const U sentinel = 0) : s(s_) {
    const int n = s.size();
    s.push_back(sentinel);
    sa.resize(n + 1);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [this](const int a, const int b) -> bool {
      return s[a] == s[b] ? a > b : s[a] < s[b];
    });
    rank.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
      rank[i] = s[i];
    }
    std::vector<int> tmp(n + 1), prev_sa(n + 1);
    for (int len = 1; len <= n; len <<= 1) {
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&
            rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {
          tmp[sa[i]] = tmp[sa[i - 1]];
        } else {
          tmp[sa[i]] = i;
        }
      }
      rank.swap(tmp);
      std::iota(tmp.begin(), tmp.end(), 0);
      std::copy(sa.begin(), sa.end(), prev_sa.begin());
      for (int i = 0; i <= n; ++i) {
        const int idx = prev_sa[i] - len;
        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;
      }
    }
    for (int i = 0; i <= n; ++i) {
      rank[sa[i]] = i;
    }
  }

  std::vector<int> match(T* t) const {
    const int lb = lower_bound(t);
    ++t->back();
    const int ub = lower_bound(t);
    --t->back();
    std::vector<int> res(ub - lb);
    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());
    std::sort(res.begin(), res.end());
    return res;
  }

 private:
  T s;

  int lower_bound(const T* t) const {
    const int s_size = s.size(), t_size = t->size();
    int lb = 0, ub = s_size;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      int s_idx = sa[mid], t_idx = 0;
      bool finished = false;
      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {
        if (s[s_idx] != (*t)[t_idx]) {
          (s[s_idx] < (*t)[t_idx] ? lb : ub) = mid;
          finished = true;
          break;
        }
      }
      if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;
    }
    return ub;
  }
};

}  // namespace emthrm

#endif  // EMTHRM_STRING_SUFFIX_ARRAY_HPP_
