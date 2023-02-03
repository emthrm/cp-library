#ifndef EMTHRM_STRING_REPLACE_HPP_
#define EMTHRM_STRING_REPLACE_HPP_

#include <cstddef>
#include <string>

namespace emthrm {

std::string replace(const std::string& s, const std::string& before,
                    const std::string& after) {
  std::string res = "";
  int pos = 0;
  while (true) {
    const std::size_t pos_b = s.find(before, pos);
    if (pos_b == s.npos) [[unlikely]] break;
    res += s.substr(pos, pos_b - pos) + after;
    pos = pos_b + before.length();
  }
  return res + s.substr(pos);
}

}  // namespace emthrm

#endif  // EMTHRM_STRING_REPLACE_HPP_
