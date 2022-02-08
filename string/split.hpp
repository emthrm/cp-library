#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(
    const std::string& s, const std::string& delimiter) {
  std::vector<std::string> res;
  int pos = 0;
  while (true) {
    const int pos_to_del = s.find(delimiter, pos);
    if (pos_to_del == s.npos) break;
    res.emplace_back(s.substr(pos, pos_to_del - pos));
    pos = pos_to_del + delimiter.length();
  }
  res.emplace_back(s.substr(pos));
  return res;
}
