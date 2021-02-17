#include "get_avg_of_vector.hpp"
#include <stdexcept>

float get_avg_of_vector(const std::vector<int> &v) {
  if (!v.size())
    throw std::length_error("Could not calcualte average of empty vector.");
  int sum = 0;
  for (int i = 0; i < v.size(); ++i)
    sum += v[i];
  return float(sum) / v.size();
}
