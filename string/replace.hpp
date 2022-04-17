#pragma once
#include <string>

std::string replace(const std::string& s, const std::string& before,
                    const std::string& after) {
  std::string res = "";
  int pos = 0;
  while (true) {
    const int pos_b = s.find(before, pos);
    if (pos_b == s.npos) break;
    res += s.substr(pos, pos_b - pos) + after;
    pos = pos_b + before.length();
  }
  return res + s.substr(pos);
}
