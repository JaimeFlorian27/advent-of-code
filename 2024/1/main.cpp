#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

struct Input {
  int lists_length;
  std::vector<int> first_input;
  std::vector<int> second_input;
};

Input read_input() {

  std::ifstream file("input.txt");

  Input input{};

  // Due to the mechanics of the >> operator, all whitespace including spaces
  // and newlines will be ignored, which automatically allows me to extract the
  // list items in a sequential manner.
  int line_num{0};
  int first_number{0};
  int second_number{0};
  while (file >> first_number >> second_number) {
    input.first_input.push_back(first_number);
    input.second_input.push_back(second_number);
    line_num++;
  }

  input.lists_length = line_num;

  // Sort both vectors before returning.
  std::sort(input.first_input.begin(), input.first_input.end());
  std::sort(input.second_input.begin(), input.second_input.end());

  return input;
}

int main() {

  // Read the list and end up with two std::vectors
  Input input{std::move(read_input())};

  // Iterate over them at the same time.
  int total_distance = {0};
  for (int i{0}; i < input.lists_length; i++) {
    total_distance += abs(input.first_input[i] - input.second_input[i]);
  }
  std::cout << "Total distance: " << total_distance << "\n";
}
