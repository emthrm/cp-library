#pragma once
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
  std::vector<std::string> res;
  int pos = 0;
  while (true) {
    int del_pos = s.find(delimiter, pos);
    if (del_pos == s.npos) break;
    res.emplace_back(s.substr(pos, del_pos - pos));
    pos = del_pos + delimiter.length();
  }
  res.emplace_back(s.substr(pos));
  return res;
}
