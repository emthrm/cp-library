/**
 * @brief 2次元 Fenwick tree
 * @docs docs/data_structure/fenwick_tree/fenwick_tree.md
 */

#pragma once
#include <vector>

template <typename Abelian>
struct FenwickTree2D {
  explicit FenwickTree2D(
      const int height_, const int width_, const Abelian ID = 0)
      : height(height_ + 1), width(width_ + 1), ID(ID) {
    data.assign(height, std::vector<Abelian>(width, ID));
  }

  void add(int y, int x, const Abelian val) {
    ++y; ++x;
    for (int i = y; i < height; i += i & -i) {
      for (int j = x; j < width; j += j & -j) {
        data[i][j] += val;
      }
    }
  }

  Abelian sum(int y, int x) const {
    ++y; ++x;
    Abelian res = ID;
    for (int i = y; i > 0; i -= i & -i) {
      for (int j = x; j > 0; j -= j & -j) {
        res += data[i][j];
      }
    }
    return res;
  }

  Abelian sum(const int y1, const int x1, const int y2, const int x2) const {
    return y1 > y2 || x1 > x2 ? ID :
        sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1);
  }

  Abelian get(const int y, const int x) const { return sum(y, x, y, x); }

 private:
  const int height, width;
  const Abelian ID;
  std::vector<std::vector<Abelian>> data;
};
