/*
 * @title 数学/カタラン数
 */
#define PROBLEM "https://yukicoder.me/problems/no/790"

#include <iostream>

#include "emthrm/math/catalan_number.hpp"
#include "emthrm/math/modint.hpp"

int main() {
  int n;
  std::cin >> n;
  std::cout << emthrm::catalan_number<742909>(n)[n] << '\n';
  return 0;
}
