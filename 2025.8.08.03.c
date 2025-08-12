#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
int main(){
    int num,i,n;
    uint32_t result = 0;
    srand(time(NULL));
    for (n = 0; n < 32;n++)
    {
        num=rand()%101;
         if (num > 50) {
            result |= (1u << (n - 1)); // 将第 n 位设置为1（n从1开始）
            printf("位 %d 置为 1\n", n);
        } else {
            printf("位 %d 保持 0\n", n);
        }
    }

    printf("\n最终结果（十进制）: %u\n", result);
    printf("最终结果（二进制）: ");
    for (int i = 31; i >= 0; i--) { 
        // 从最高位到最低位输出
        printf("%d", (result >> i) & 1);
    }
    return 0;
}