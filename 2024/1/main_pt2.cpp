#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Input {
  std::unordered_map<int, int> number_similarity_map{};
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
    // Add an entry to the map for each number in the first list with an initial 
    // similarity value of 0.
    input.number_similarity_map[first_number] = 0;

    input.second_input.push_back(second_number);
    line_num++;
  }

  return input;
}

int main() {

  // Read the list and end up with two std::vectors
  Input input{std::move(read_input())};

  // Calculate the similarity for each number by checking if it exists in the map, if it
  // does then add the number to the values (same as multiplying the number by the 
  // amount of times it's appeared).
  for (auto id : input.second_input) {
    if (input.number_similarity_map.count(id) > 0) {
      input.number_similarity_map[id] += id;
    }
  }

  // Calculate the similarity by iterating over the key, value pairs and adding up the
  // values.
  int total_similarity{0};
  for (auto &[key, value] : input.number_similarity_map) {
    total_similarity += value;
  }

  std::cout << "Total similarity: " << total_similarity << "\n";
}
