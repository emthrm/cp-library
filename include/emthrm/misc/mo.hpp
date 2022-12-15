#ifndef EMTHRM_MISC_MO_HPP_
#define EMTHRM_MISC_MO_HPP_

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace emthrm {

struct Mo {
  explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs)
      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs) {
    const int width = std::round(std::sqrt(n));
    order.resize(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(),
              [&ls, &rs, width](const int a, const int b) -> bool {
                  if (ls[a] / width != ls[b] / width) return ls[a] < ls[b];
                  return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];
              });
  }

  int process() {
    if (ptr == n) return -1;
    const int id = order[ptr++];
    while (ls[id] < nl) add(--nl);
    while (nr < rs[id]) add(nr++);
    while (nl < ls[id]) del(nl++);
    while (rs[id] < nr) del(--nr);
    return id;
  }

  void add(const int idx) const;

  void del(const int idx) const;

 private:
  const int n;
  int ptr, nl, nr;
  std::vector<int> ls, rs, order;
};

}  // namespace emthrm

#endif  // EMTHRM_MISC_MO_HPP_
