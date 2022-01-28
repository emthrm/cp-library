#include <tuple>
#include <vector>

template <typename T>
std::vector<std::tuple<T, T, T>> enumerate_quotient(const T n) {
  std::vector<std::tuple<T, T, T>> quotients;
  for (T l = 1; l <= n;) {
    const T quotient = n / l, r = n / quotient + 1;
    quotients.emplace_back(l, r, quotient);
    l = r;
  }
  return quotients;
}
