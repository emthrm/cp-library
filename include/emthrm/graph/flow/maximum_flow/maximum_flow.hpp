/**
 * @brief 最大流コンセプト
 */

#ifndef EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_
#define EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_

#include <concepts>
#include <utility>

namespace emthrm {

template <template <typename> class C, typename T>
concept MaximumFlow = requires (C<T> mf) {
  {mf.add_edge(std::declval<int>(), std::declval<int>(), std::declval<T>())}
      -> std::same_as<void>;
  {mf.maximum_flow(std::declval<int>(), std::declval<int>())}
      -> std::same_as<T>;
};

}  // namespace emthrm

#endif  // EMTHRM_GRAPH_FLOW_MAXIMUM_FLOW_MAXIMUM_FLOW_HPP_
