/*
 * @brief 数学/行列/バイナリ行列/バイナリ行列
 */
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/utpc2014/tasks/utpc2014_k"

#include <algorithm>
#include <bitset>
#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>
#include "../../../../math/matrix/binary_matrix/binary_matrix.hpp"

// editorial: https://www.utpc.jp/2014/slides/K.pdf
//            http://kmjp.hatenablog.jp/entry/2015/05/28/0900
// BSGS の解説: http://sonickun.hatenablog.com/entry/2016/11/20/192743
int main() {
  constexpr int N = 36;
  using binary_matrix = BinaryMatrix<N>;

  long long a_ll, b_ll, x_ll;
  std::cin >> a_ll >> b_ll >> x_ll;
  std::bitset<N> a_bit(a_ll), b_bit(b_ll), x_bit(x_ll);
  binary_matrix a(N, 1), x(N, 1);
  for (int i = 0; i < N; ++i) a[i][0] = a_bit[N - 1 - i];
  for (int i = 0; i < N; ++i) x[i][0] = x_bit[N - 1 - i];

  // 2進表記で a_t は abcdef
  //           B   は uvwxyz であるとおく．
  // a_{t+1} = (a_t >> 1) ^ ((a_t & 1) * B)
  //         = 0abcde ^ (f * uvwxyz)
  //         = 0^(f&u) a^(f&v) b^(f&w) c^(f&x) d^(f&y) e^(f&z)．
  // バイナリ行列 M を用いると
  // 0^(f&u)   0 0 0 0 0 u  a
  // a^(f&v)   1 0 0 0 0 v  b
  // b^(f&w) = 0 1 0 0 0 w  c
  // c^(f&x)   0 0 1 0 0 x  d
  // d^(f&y)   0 0 0 1 0 y  e
  // e^(f&z)   0 0 0 0 1 z  f
  // a_{t+1}        M      a_t
  // となる．
  // ∴ a_t = M^t A．

  binary_matrix m(N, N);  // バイナリ行列 M
  for (int i = 0; i < N; ++i) m[i][N - 1] = b_bit[N - 1 - i];
  for (int i = 1; i < N; ++i) m[i][i - 1] = 1;

  // a_t のとりうる値は 0 以上 2^36 未満の高々 2^36 ≓ 7 * 10^10 個である．
  // 内部状態 a は長さ 2^36 以下の周期をもつ．
  // ここで 0 <= t < 2^36 を満たす整数 t は
  // 0 < i, j <= √(2^36) を満たす整数 i, j を用いて t = j √(2^36) - i と一意に表せる．
  //
  // しかし周期 √(2^36) 以下の場合，同一の t, j に対して上記の式を満たす i が複数存在する．
  // そのため周期 √(2^36) 以下のものは愚直に計算する．
  std::map<long long, bool> mp;  // 周期性の確認に用いる．
  long long internal_state = a_ll;
  for (int t = 0; t < (1 << (N / 2)); ++t) {
    if (internal_state == x_ll) {
      std::cout << t << '\n';
      return 0;
    }
    if (mp.count(internal_state) == 1) {
      std::cout << "-1\n";
      return 0;
    }
    mp[internal_state] = true;
    internal_state = (internal_state >> 1) ^ ((internal_state & 1) * b_ll);
  }

  // 以下，Baby-step Giant-step を用いて a_t = X を満たす最小の t を求める．

  /***** Baby-step *****/
  std::vector<std::pair<long long, int>> mx(1 << (N / 2));  // {M^i X, i} (0 < i <= 2^18) を昇順に格納する．
  binary_matrix mix = m * x;  // M^i X を保持しておく．
  for (int i = 1; i <= (1 << (N / 2)); ++i) {
    long long val = 0;  // M^i X の値
    for (int bit = 0; bit < N; ++bit) val |= static_cast<long long>(mix[bit][0]) << (N - 1 - bit);
    mx[i - 1] = {val, -i};  // 最小の t を求めるため i はできる限り大きくしたい．
    mix = m * mix;  // M^(i+1) X = M * M^i X．
  }
  std::sort(mx.begin(), mx.end());

  /***** Giant-step *****/
  binary_matrix mh = m.pow(1 << (N / 2)), mha = mh * a;  // それぞれ M^(2^18), M^((2^18)j) A を保持しておく．
  for (int j = 1; j <= (1 << (N / 2)); ++j) {
    long long val = 0;  // M^((2^18)j) A
    for (int bit = 0; bit < N; ++bit) val |= static_cast<long long>(mha[bit][0]) << (N - 1 - bit);
    auto it = std::lower_bound(mx.begin(), mx.end(), std::make_pair(val, std::numeric_limits<int>::min()));
    if (it != mx.end() && it->first == val) {  // M^i X = M^((2^18)j) A を満たす i, j が存在する場合
      // M が正則?ならば X = M((2^18)j-i) A が成り立つ．
      // しかしそうでない場合に上式が成り立つとは限らないため，実際に計算を行う．
      long long ans = (1LL << (N / 2)) * j + it->second;
      binary_matrix maybe_x = m.pow(ans) * a;
      bool is_ans = true;
      for (int bit = 0; bit < N; ++bit) {
        if (x[bit][0] != maybe_x[bit][0]) is_ans = false;
      }
      if (is_ans) {
        std::cout << ans << '\n';
        return 0;
      }
    }
    mha = mh * mha;
  }

  // a_t = x を満たす t は存在しない．
  std::cout << "-1\n";
  return 0;
}
