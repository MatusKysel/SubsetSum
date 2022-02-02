#include "subset_sum.h"
#define BOOST_TEST_MODULE SubsetSumTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(example_from_description) {
  const std::vector<uint64_t> input{1, 2, 3, 4, 5, 6, 7};
  std::vector<uint64_t> output;
  const uint64_t target = 11;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_EQUAL(sum, target);
  const std::vector<uint64_t> answer{1, 2, 3, 5};
  BOOST_TEST(output == answer);
}

BOOST_AUTO_TEST_CASE(small_target) {
  const std::vector<uint64_t> input{1, 2, 3, 4, 5, 6, 7};
  std::vector<uint64_t> output;
  const uint64_t target = 0;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_LE(sum, target);
  const std::vector<uint64_t> answer{};
  BOOST_TEST(output == answer);
}

BOOST_AUTO_TEST_CASE(huge_target) {
  const std::vector<uint64_t> input{1, 2, 3, 4, 5, 6, 7};
  std::vector<uint64_t> output;
  const uint64_t target = 100;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_LE(sum, target);
  BOOST_TEST(output == input);
}

BOOST_AUTO_TEST_CASE(another_test) {
  const std::vector<uint64_t> input{1, 2, 3, 4, 6, 7};
  std::vector<uint64_t> output;
  const uint64_t target = 18;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_EQUAL(sum, target);
  const std::vector<uint64_t> answer{2, 3, 6, 7};
  BOOST_TEST(output == answer);
}

BOOST_AUTO_TEST_CASE(less_than_target) {
  const std::vector<uint64_t> input{2, 3, 4, 6, 7};
  std::vector<uint64_t> output;
  const uint64_t target = 21;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_LE(sum, target);
  BOOST_CHECK_EQUAL(sum, 20);
  const std::vector<uint64_t> answer{3, 4, 6, 7};
  BOOST_TEST(output == answer);
}

BOOST_AUTO_TEST_CASE(multiple_elements) {
  const std::vector<uint64_t> input{5, 5, 1, 1, 2};
  std::vector<uint64_t> output;
  const uint64_t target = 10;
  uint64_t sum;
  find_largest_sum(target, input, output, sum);
  BOOST_CHECK_EQUAL(sum, target);
  const std::vector<uint64_t> answer{5, 5};
  BOOST_TEST(output == answer);
}