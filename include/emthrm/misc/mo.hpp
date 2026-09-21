#ifndef EMTHRM_MISC_MO_HPP_
#define EMTHRM_MISC_MO_HPP_

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace emthrm {

template <typename AddLeft, typename AddRight,
          typename DelLeft, typename DelRight>
struct Mo {
  explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs,
              const AddLeft& add_left, const AddRight& add_right,
              const DelLeft& del_left, const DelRight& del_right)
      : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs),
        add_left(add_left), add_right(add_right),
        del_left(del_left), del_right(del_right) {
    const int width = (
        n == 0 ? 1
               : std::max(std::llround(std::ranges::max(rs) / std::sqrt(n)),
                          1LL));
    order.resize(n);
    std::iota(order.begin(), order.end(), 0);
    std::sort(order.begin(), order.end(),
              [&ls, &rs, width](const int a, const int b) -> bool {
                  if (ls[a] / width != ls[b] / width) return ls[a] < ls[b];
                  return (ls[a] / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];
              });
  }

  int process() {
    if (ptr == n) [[unlikely]] return -1;
    const int id = order[ptr++];
    while (ls[id] < nl) {
      const int idx = --nl;
      add_left(idx, nl, nr);
    }
    while (nr < rs[id]) {
      const int idx = nr++;
      add_right(idx, nl, nr);
    }
    while (nl < ls[id]) {
      const int idx = nl++;
      del_left(idx, nl, nr);
    }
    while (rs[id] < nr) {
      const int idx = --nr;
      del_right(idx, nl, nr);
    }
    return id;
  }

 private:
  const int n;
  int ptr, nl, nr;
  std::vector<int> ls, rs, order;
  AddLeft add_left;
  AddRight add_right;
  DelLeft del_left;
  DelRight del_right;
};

}  // namespace emthrm

#endif  // EMTHRM_MISC_MO_HPP_
