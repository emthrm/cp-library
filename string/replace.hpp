#pragma once
#include <string>

std::string replace(const std::string &s, const std::string &before, const std::string &after) {
  std::string res = "";
  int pos = 0;
  while (true) {
    int b_pos = s.find(before, pos);
    if (b_pos == s.npos) break;
    res += s.substr(pos, b_pos - pos) + after;
    pos = b_pos + before.length();
  }
  return res + s.substr(pos);
}
