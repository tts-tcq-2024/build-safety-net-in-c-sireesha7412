#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
 //AAA
  char soundex[5];
  generateSoundex("AX", soundex);
  ASSERT_STREQ(soundex,"A200");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_1) {
 //AAA
  char soundex[5];
  generateSoundex("Srtvfr", soundex);
  ASSERT_STREQ(soundex,"S6316");
}
