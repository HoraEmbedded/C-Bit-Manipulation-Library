#include <stdio.h>
#include <stdint.h> // Required for uint32_t

// Your existing macros
#define SET_BIT(reg, bit)    ((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1 << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1)

// VIRTUAL HARDWARE DEFINITION 
typedef struct {
    uint32_t MODER; // Mode register
    uint32_t IDR;   // Input data register
    uint32_t ODR;   // Output data register
} GPIO_TypeDef;

int main() {
    //  "virtual" Port A in computer's RAM
    GPIO_TypeDef GPIOA;

    //  Initialize everything
    GPIOA.MODER = 0;
    GPIOA.IDR = 0;
    GPIOA.ODR = 0;

    // 
// 1. Configure Pin 5 as output
    SET_BIT(GPIOA.MODER, 5);
    printf("MODER after config: %u\n", GPIOA.MODER);

    // 2. Turn LED ON
    SET_BIT(GPIOA.ODR, 5);
    printf("ODR (LED ON): %u\n", GPIOA.ODR);

    // 3. Turn LED OFF
    CLEAR_BIT(GPIOA.ODR, 5);
    printf("ODR (LED OFF): %u\n", GPIOA.ODR);

    return 0;
}
