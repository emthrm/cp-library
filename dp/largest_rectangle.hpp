#pragma once
#include <stack>
#include <vector>

template <typename T>
long long largest_rectangle(const std::vector<T> &height) {
  int n = height.size();
  std::vector<int> left(n);
  std::stack<T> st;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && height[st.top()] >= height[i]) {
      long long tmp = static_cast<long long>(height[st.top()]) * (i - left[st.top()]);
      if (tmp > res) res = tmp;
      st.pop();
    }
    left[i] = st.empty() ? 0 : st.top() + 1;
    st.emplace(i);
  }
  while (!st.empty()) {
    long long tmp = static_cast<long long>(height[st.top()]) * (n - left[st.top()]);
    if (tmp > res) res = tmp;
    st.pop();
  }
  return res;
}
