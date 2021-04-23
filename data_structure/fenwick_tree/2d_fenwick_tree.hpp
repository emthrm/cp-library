/**
 * @brief 2次元 Fenwick tree
 * @docs docs/data_structure/fenwick_tree/fenwick_tree.md
 */

#pragma once
#include <vector>

template <typename Abelian>
struct FenwickTree2D {
  FenwickTree2D(int height_, int width_, const Abelian ID = 0) : height(height_), width(width_), ID(ID) {
    dat.assign(++height, std::vector<Abelian>(++width, ID));
  }

  void add(int y, int x, Abelian val) {
    ++y; ++x;
    for (int i = y; i < height; i += i & -i) {
      for (int j = x; j < width; j += j & -j) {
        dat[i][j] += val;
      }
    }
  }

  Abelian sum(int y, int x) const {
    ++y; ++x;
    Abelian res = ID;
    for (int i = y; i > 0; i -= i & -i) {
      for (int j = x; j > 0; j -= j & -j) {
        res += dat[i][j];
      }
    }
    return res;
  }

  Abelian sum(int y1, int x1, int y2, int x2) const {
    return y1 <= y2 && x1 <= x2 ? sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1) : ID;
  }

private:
  int height, width;
  const Abelian ID;
  std::vector<std::vector<Abelian>> dat;
};
