#include "doctest.h"
#include "crasis/experimental/is.hpp"

#include <algorithm>

using namespace crasis::experimental;

// only for testing
constexpr char a_to_z[] = "abcdefghijklmnopqrstuvwxyz";

// alphabet definitions
using a_to_z_range_alphabet = check_range<'a', 'z'>;

TEST_CASE("is in a range alphabet") {

  for (char c = 0; c < std::numeric_limits<char>::max(); ++c) {
    if (std::find(a_to_z, a_to_z + length(a_to_z), c) != a_to_z + length(a_to_z)) {
      CHECK((is<a_to_z_range_alphabet>(c)));
    } else {
      CHECK_FALSE((is<a_to_z_range_alphabet>(c)));
    }
  }
}
