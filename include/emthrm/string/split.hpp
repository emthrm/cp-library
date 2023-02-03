#ifndef EMTHRM_STRING_SPLIT_HPP_
#define EMTHRM_STRING_SPLIT_HPP_

#include <cstddef>
#include <string>
#include <vector>

namespace emthrm {

std::vector<std::string> split(
    const std::string& s, const std::string& delimiter) {
  std::vector<std::string> res;
  int pos = 0;
  while (true) {
    const std::size_t pos_to_del = s.find(delimiter, pos);
    if (pos_to_del == s.npos) [[unlikely]] break;
    res.emplace_back(s.substr(pos, pos_to_del - pos));
    pos = pos_to_del + delimiter.length();
  }
  res.emplace_back(s.substr(pos));
  return res;
}

}  // namespace emthrm

#endif  // EMTHRM_STRING_SPLIT_HPP_
