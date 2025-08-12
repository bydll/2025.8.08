#include <stdio.h>
#include <math.h>
int main() {
    float f1 = 3.14f;
    float f2 = 1.73f;

    union {
        float f[2];
        char c[8];
    } u;

    u.f[0] = f1;
    u.f[1] = f2;

    float r1 = u.f[0];
    float r2 = u.f[1];

    printf("原始数据: f1 = %.7f, f2 = %.7f\n", f1, f2);
    printf("提取数据: r1 = %.7f, r2 = %.7f\n", r1, r2);
    printf("差距: |f1-r1| = %.10f, |f2-r2| = %.10f\n",
           fabs(f1 - r1), fabs(f2 - r2));

    return 0;
}