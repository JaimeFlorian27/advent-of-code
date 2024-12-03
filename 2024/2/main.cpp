#include <fstream>
#include <iostream>
#include <string>

bool is_report_safe(const std::string &report) {

  std::cout << "Inspecting report:" << report << '\n';
  std::string current_level_token{""};
  int previous_level{-1};
  bool increasing{false};
  bool increasing_set{false};

  for (int i{0}; i < report.length(); i++) {

    if (report[i] != ' ') {
      std::cout << "Token: " << report[i] << '\n';
      current_level_token.push_back(report[i]);
      if (report.length() - 1 != i) {
        continue;
      }
    }

    int current_level{std::stoi(current_level_token)};
    current_level_token = "";

    // Continue if no previous level exists. Handle the first level.
    if (previous_level == -1) {
      previous_level = current_level;
      continue;
    }

    // check if within range.
    int distance{abs(current_level - previous_level)};

    if (distance < 1 || distance > 3) {
      return false;
    }


    // set the report direction if not alreasy set.
    if (!increasing_set) {
      increasing = (current_level > previous_level);
      increasing_set = true;
    }

    if (increasing && current_level < previous_level ||
        !increasing && current_level > previous_level) {
      return false;
    }
    previous_level = current_level;
  }
  // The conditions were met, the report is safe.
  return true;
}

int main() {

  std::ifstream file("input.txt");

  int safe_reports{0};
  for (std::string report{}; std::getline(file, report);) {
      safe_reports += is_report_safe(report);
  }

  std::cout << "Total of safe reports:" << safe_reports << "\n";
}
