#include "unity.h"
#include <stdint.h>

// 1. Paste macros so the test can see them
#define SET_BIT(reg, bit)    ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1)

// 2. Unity requires these, we leave them empty for now
void setUp(void) {}
void tearDown(void) {}

// 3. Write our first test!
void test_SET_BIT_should_TurnOnCorrectBit(void) {
    uint32_t my_reg = 0;      // Start with 00000000
    SET_BIT(my_reg, 3);       // Turn on bit 3

    // If bit 3 is on, the value should be exactly 8 (00001000)
    TEST_ASSERT_EQUAL(8, my_reg); 
}

// 4. Write our second test!
void test_CLEAR_BIT_should_TurnOffCorrectBit(void) {
    uint32_t my_reg = 15;     // Start with 00001111 (Decimal 15)
    CLEAR_BIT(my_reg, 0);     // Turn off bit 0

    // If bit 0 is off, the value should be 14 (00001110)
    TEST_ASSERT_EQUAL(14, my_reg); 
}

// 5. The Main function that runs everything
int main(void) {
    UNITY_BEGIN(); // Start the framework

    // Run our two tests
    RUN_TEST(test_SET_BIT_should_TurnOnCorrectBit);
    RUN_TEST(test_CLEAR_BIT_should_TurnOffCorrectBit);

    return UNITY_END(); // Print the final report
}
