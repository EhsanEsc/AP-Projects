#include "hailstone.hpp"

bool satisfies_hailstone(unsigned long long seed) {
  return seed ? seed == 1
                    ? true
                    : satisfies_hailstone(seed % 2 ? 3 * seed + 1 : seed / 2)
              : false;
}
