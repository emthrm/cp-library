#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_
#define EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_

#include <algorithm>
#include <stack>
#include <vector>

namespace emthrm {

template <typename T>
long long largest_rectangle(const std::vector<T>& height) {
  const int n = height.size();
  std::vector<int> left(n);
  std::stack<T> st;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && height[st.top()] >= height[i]) {
      res = std::max(
          res, static_cast<long long>(height[st.top()]) * (i - left[st.top()]));
      st.pop();
    }
    left[i] = (st.empty() ? 0 : st.top() + 1);
    st.emplace(i);
  }
  while (!st.empty()) {
    res = std::max(
        res, static_cast<long long>(height[st.top()]) * (n - left[st.top()]));
    st.pop();
  }
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LARGEST_RECTANGLE_HPP_
