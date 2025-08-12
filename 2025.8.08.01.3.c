#include <stdio.h>
#include <math.h>
int main() {
    float f1 = 3.14f;
    float f2 = 1.73f;
    char c[8];
    *((float*)(c)) = f1;
    *((float*)(c + 4)) = f2;
    float r1 = *((float*)(c));
    float r2 = *((float*)(c + 4));
    printf("原始数据: f1 = %.7f, f2 = %.7f\n", f1, f2);
    printf("提取数据: r1 = %.7f, r2 = %.7f\n", r1, r2);
    printf("差距: |f1-r1| = %.10f, |f2-r2| = %.10f\n",
           fabs(f1 - r1), fabs(f2 - r2));

    return 0;