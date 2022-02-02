#include "subset_sum.h"

#include <charconv>
#include <fstream>
#include <ranges>
#include <string_view>
/*
The solution should take test cases from a text file test.txt in the following
format

12
1 2 3 4 5 6 7
12

each test case consists of three lines. The first line represents T. The second
line represents I. The 3rd line represents S. The solution should find the
correct solution with sum equal to given S for each test case and output the M
in ascending order.
*/

// Function for converting line of string numbers to vector
std::vector<uint64_t> line_2_array(std::string numbers) {
  std::vector<uint64_t> output;
  auto split =
      numbers | std::ranges::views::split(' ') |
      std::ranges::views::transform([](auto &&str) {
        return std::string_view(&*str.begin(), std::ranges::distance(str));
      });
  uint64_t n;
  for (auto &&number : split) {
    std::from_chars(number.data(), number.data() + number.size(), n);
    output.push_back(n);
  }
  return output;
}

int main() {
  std::fstream infile("test.txt", std::ios_base::in);

  std::string line;
  uint64_t T, S, sum;
  do {
    std::vector<uint64_t> output, input;

    std::getline(infile, line);
    T = std::stoi(line);        // get T
    std::getline(infile, line); // get array
    input = line_2_array(line);
    std::cout << std::endl;
    std::getline(infile, line);
    S = std::stoi(line); // get S

    // calculate the sum
    find_largest_sum(T, input, output, sum);

    std::cout << "calculated sum: " << sum << " provided sum: " << S
              << std::endl;
    std::cout << "subset: ";
    for (const auto el : output) {
      std::cout << el << " ";
    }
    std::cout << std::endl;
  } while (std::getline(infile, line));
  return 0;
}