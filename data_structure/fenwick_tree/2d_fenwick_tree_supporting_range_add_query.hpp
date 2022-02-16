/**
 * @brief 区間加算クエリ対応2次元 Fenwick tree
 * @docs docs/data_structure/fenwick_tree/fenwick_tree.md
 */

#pragma once
#include <vector>

template <typename Abelian>
struct FenwickTree2DSupportingRangeAddQuery {
  explicit FenwickTree2DSupportingRangeAddQuery(
      const int height_, const int width_, const Abelian ID = 0)
      : height(height_ + 1), width(width_ + 1), ID(ID) {
    data_const.assign(height, std::vector<Abelian>(width, ID));
    data_linear[0].assign(height, std::vector<Abelian>(width, ID));
    data_linear[1].assign(height, std::vector<Abelian>(width, ID));
    data_quadratic.assign(height, std::vector<Abelian>(width, ID));
  }

  void add(int y1, int x1, int y2, int x2, const Abelian val) {
    ++y1; ++x1; ++y2; ++x2;
    for (int i = y1; i < height; i += i & -i) {
      for (int j = x1; j < width; j += j & -j) {
        data_const[i][j] += val * (y1 - 1) * (x1 - 1);
        data_linear[0][i][j] -= val * (x1 - 1);
        data_linear[1][i][j] -= val * (y1 - 1);
        data_quadratic[i][j] += val;
      }
    }
    for (int i = y1; i < height; i += i & -i) {
      for (int j = x2 + 1; j < width; j += j & -j) {
        data_const[i][j] -= val * (y1 - 1) * x2;
        data_linear[0][i][j] += val * x2;
        data_linear[1][i][j] += val * (y1 - 1);
        data_quadratic[i][j] -= val;
      }
    }
    for (int i = y2 + 1; i < height; i += i & -i) {
      for (int j = x1; j < width; j += j & -j) {
        data_const[i][j] -= val * y2 * (x1 - 1);
        data_linear[0][i][j] += val * (x1 - 1);
        data_linear[1][i][j] += val * y2;
        data_quadratic[i][j] -= val;
      }
    }
    for (int i = y2 + 1; i < height; i += i & -i) {
      for (int j = x2 + 1; j < width; j += j & -j) {
        data_const[i][j] += val * y2 * x2;
        data_linear[0][i][j] -= val * x2;
        data_linear[1][i][j] -= val * y2;
        data_quadratic[i][j] += val;
      }
    }
  }

  Abelian sum(int y, int x) const {
    ++y; ++x;
    Abelian quad = ID, cons = ID, line[2]{ID, ID};
    for (int i = y; i > 0; i -= i & -i) {
      for (int j = x; j > 0; j -= j & -j) {
        quad += data_quadratic[i][j];
        line[0] += data_linear[0][i][j];
        line[1] += data_linear[1][i][j];
        cons += data_const[i][j];
      }
    }
    return quad * y * x + line[0] * y + line[1] * x + cons;
  }

  Abelian sum(const int y1, const int x1, const int y2, const int x2) const {
    return y1 > y2 || x1 > x2 ? ID :
        sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1);
  }

 private:
  const int height, width;
  const Abelian ID;
  std::vector<std::vector<Abelian>> data_const, data_quadratic;
  std::vector<std::vector<Abelian>> data_linear[2];
};
