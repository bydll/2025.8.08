#include <stdio.h>
#include <stdint.h>
uint32_t swap_endian32(uint32_t value) {
    return ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8)  | 
           ((value & 0x00FF0000) >> 8)  | 
           ((value & 0xFF000000) >> 24);  
}

int is_big_endian() {
    uint16_t test = 0x1234;
    return (*(uint8_t*)&test == 0x12);
}

int main() {
    uint32_t num = 0x12253647;
     if (is_big_endian()) {
        printf("本机是大端模式\n");
    } else {
        printf("本机是小端模式\n");
    }
    printf("本机字节序下的 num = 0x%08X\n", num);
    uint32_t swapped = swap_endian32(num);
    printf("转换后（另一种字节序） num = 0x%08X\n", swapped);
    return 0;
}