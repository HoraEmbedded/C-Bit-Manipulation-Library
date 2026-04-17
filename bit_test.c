#include <stdio.h>

// Your complete Bit Manipulation Library
#define SET_BIT(reg, bit)    ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1)

int main() {
    unsigned char my_register = 0; // 00000000

    // 1. Set bit 4
    SET_BIT(my_register, 4);
    printf("After SET_BIT(4): %d\n", my_register);

    // 2. Read bit 4
    unsigned char is_pressed = READ_BIT(my_register, 4);
    printf("Is Bit 4 on? %d\n", is_pressed);

    // 3. Toggle bit 4
    TOGGLE_BIT(my_register, 4);
    printf("After TOGGLE_BIT(4): %d\n", my_register);

    // 4. Clear bit 4
    CLEAR_BIT(my_register, 4);
    printf("After CLEAR_BIT(4): %d\n", my_register);

    return 0;
}
