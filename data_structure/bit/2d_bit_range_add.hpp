/**
 * @brief 2次元 BIT 領域加算版
 * @docs docs/data_structure/bit/bit.md
 */

#pragma once
#include <vector>

template <typename Abelian>
struct BIT2DRangeAdd {
  BIT2DRangeAdd(int height_, int width_, const Abelian ID = 0) : height(height_), width(width_), ID(ID) {
    ++height; ++width;
    dat_const.assign(height, std::vector<Abelian>(width, ID));
    dat_linear[0].assign(height, std::vector<Abelian>(width, ID));
    dat_linear[1].assign(height, std::vector<Abelian>(width, ID));
    dat_quadratic.assign(height, std::vector<Abelian>(width, ID));
  }

  void add(int y1, int x1, int y2, int x2, const Abelian val) {
    ++y1; ++x1; ++y2; ++x2;
    for (int i = y1; i < height; i += i & -i) for (int j = x1; j < width; j += j & -j) {
      dat_const[i][j] += val * (y1 - 1) * (x1 - 1);
      dat_linear[0][i][j] -= val * (x1 - 1);
      dat_linear[1][i][j] -= val * (y1 - 1);
      dat_quadratic[i][j] += val;
    }
    for (int i = y1; i < height; i += i & -i) for (int j = x2 + 1; j < width; j += j & -j) {
      dat_const[i][j] -= val * (y1 - 1) * x2;
      dat_linear[0][i][j] += val * x2;
      dat_linear[1][i][j] += val * (y1 - 1);
      dat_quadratic[i][j] -= val;
    }
    for (int i = y2 + 1; i < height; i += i & -i) for (int j = x1; j < width; j += j & -j) {
      dat_const[i][j] -= val * y2 * (x1 - 1);
      dat_linear[0][i][j] += val * (x1 - 1);
      dat_linear[1][i][j] += val * y2;
      dat_quadratic[i][j] -= val;
    }
    for (int i = y2 + 1; i < height; i += i & -i) for (int j = x2 + 1; j < width; j += j & -j) {
      dat_const[i][j] += val * y2 * x2;
      dat_linear[0][i][j] -= val * x2;
      dat_linear[1][i][j] -= val * y2;
      dat_quadratic[i][j] += val;
    }
  }

  Abelian sum(int y, int x) const {
    ++y; ++x;
    Abelian quad = ID, cons = ID, line[2] = {ID, ID};
    for (int i = y; i > 0; i -= i & -i) for (int j = x; j > 0; j -= j & -j) {
      quad += dat_quadratic[i][j];
      line[0] += dat_linear[0][i][j];
      line[1] += dat_linear[1][i][j];
      cons += dat_const[i][j];
    }
    return quad * y * x + line[0] * y + line[1] * x + cons;
  }

  Abelian sum(int y1, int x1, int y2, int x2) const {
    return y1 <= y2 && x1 <= x2 ? sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1) : ID;
  }

private:
  int height, width;
  const Abelian ID;
  std::vector<std::vector<Abelian>> dat_const, dat_quadratic;
  std::vector<std::vector<Abelian>> dat_linear[2];
};
