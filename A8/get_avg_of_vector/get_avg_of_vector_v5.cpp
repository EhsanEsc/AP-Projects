#include "get_avg_of_vector.hpp"
#include <stdexcept>

int get_sum_of_vector(const std::vector<int> &v, int index = 0) {
  return (index == v.size()) ? 0 : v[index] + get_sum_of_vector(v, index + 1);
}

float get_avg_of_vector(const std::vector<int> &v) {
  if (!v.size())
    throw std::length_error("Could not calcualte average of empty vector.");
  return float(get_sum_of_vector(v)) / v.size();
}
