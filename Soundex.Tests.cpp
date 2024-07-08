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
  ASSERT_STREQ(soundex,"S631");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_2) {
 //AAA
  char soundex[5];
  generateSoundex("A12[45", soundex);
  ASSERT_STREQ(soundex,"A000");
}
TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_3) {
 //AAA
  char soundex[5];
  generateSoundex("", soundex);
  //ASSERT_STREQ(soundex,"");
}TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits_4) {
 //AAA
  char soundex[5];
  generateSoundex("123456", soundex);
  ASSERT_STREQ(soundex,"0000");
}
