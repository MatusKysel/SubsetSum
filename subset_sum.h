#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

/*
Given an integer (T) and an integer set (I), find a subset (M) that the sum (S)
of M's elements is the largest among all subsets of I, where S is less or equal
to T. There can be repeatitive elements. Each element can only used once.
Signature of the interface: void find_largest_sum(​uint64_t​ T, const
std::vector<​uint64_t​> &I,vector<​uint64_t​>& M, ​uint64_t​ &S);

The solution only needs to find one answer if there are multiple subsets meet
the requirement. Don’t assume I is a small vector, it can contain like 10,000
numbers.

example
T: 11
I: 1 2 3 4 5 6 7

possible answers
M: 5 6
S: 11

M: 4 7
S: 11

M: 1 3 7
S: 11

The solution should find the
correct solution with sum equal to given S for each test case and output the M
in ascending order.
*/

// Solution
// https://en.wikipedia.org/wiki/Subset_sum_problem#Pseudo-polynomial_time_dynamic_programming_solutions

inline void find_largest_sum(uint64_t T, const std::vector<uint64_t> &I,
                             std::vector<uint64_t> &M, uint64_t &S) {
  // get sorted unique numbers
  const std::set<uint64_t> set(I.begin(), I.end());
  // move set back to vector
  const std::vector<uint64_t> nums(std::make_move_iterator(set.begin()),
                                   std::make_move_iterator(set.end()));

  const size_t num_of_elements = nums.size(); // number of objects

  // if the smallest element is smaller then the target return
  if (nums[0] > T) {
    S = 0;
    M = {};
    return;
  }
  // if total sum all elements is smaller equal to the targer return
  if (const uint64_t sum = std::accumulate(nums.begin(), nums.end(), 0);
      sum <= T) {
    S = sum;
    M = std::move(nums);
    return;
  }

  // create lookup table for subsets
  std::vector<std::vector<bool>> lookup(num_of_elements + 1,
                                        std::vector<bool>(T + 1));

  for (uint64_t i = 0; i <= num_of_elements; ++i) {
    for (uint64_t j = 0; j <= T; ++j) {
      // for target == 0 everyting is true
      if (j == 0) {
        lookup[i][j] = true;
        continue;
      } else if (i == 0) {
        continue;
      }

      if (nums[i - 1] > j) {
        lookup[i][j] = lookup[i - 1][j];
      } else {
        lookup[i][j] = lookup[i][j] || lookup[i - 1][j - nums[i - 1]];
      }
    }
  }

  // Back search for the set in lookup table
  for (uint64_t target = T; target != 0; --target) {
    // we need to check if we found solution if not, try to find closes number
    // to it
    if (lookup[num_of_elements][target]) {
      S = target;
      uint64_t i = num_of_elements;
      do {
        --i;
        if (nums[i] == target) {
          M.push_back(nums[i]);
          break;
        } else if (!lookup[i][target]) {
          M.push_back(nums[i]);
          target -= nums[i];
        }
      } while (i != 0);
      // reverse result as ascending order is required
      std::reverse(M.begin(), M.end());
      return;
    }
  }
}
