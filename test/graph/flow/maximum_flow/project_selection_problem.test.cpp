/*
 * @title グラフ/フロー/最大流/project selection problem
 *
 * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
 */

#include <iostream>
#include <string>
#include <vector>

#include "emthrm/graph/flow/maximum_flow/dinic.hpp"
#include "emthrm/graph/flow/maximum_flow/project_selection_problem.hpp"

int main() {
  int r, c;
  std::cin >> r >> c;
  std::vector<std::string> s(r);
  for (int i = 0; i < r; ++i) {
    std::cin >> s[i];
  }
  std::vector<std::vector<int>> id(r, std::vector<int>(c, -1));
  int n = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (s[i][j] == '#') id[i][j] = n++;
    }
  }
  emthrm::ProjectSelectionProblem<emthrm::Dinic, int>
      project_selection_problem(n);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (id[i][j] == -1) continue;
      if (i + 1 < r && id[i + 1][j] != -1) {
        project_selection_problem.add_eq(id[i][j], id[i + 1][j], 0, -1);
      }
      if (j + 1 < c && id[i][j + 1] != -1) {
        project_selection_problem.add_eq(id[i][j], id[i][j + 1], 1, -1);
      }
    }
  }
  std::cout << n + project_selection_problem.solve() << '\n';
  return 0;
}
