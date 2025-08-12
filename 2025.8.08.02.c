#include <stdio.h>
#include <math.h>

// 三维向量结构体
typedef struct {
    float x;
    float y;
    float z;
} vector3f;

// 创建向量
vector3f vec3(float x, float y, float z) {
    vector3f v = {x, y, z};
    return v;
}

// 向量加法 v1 + v2
vector3f vec_add(vector3f a, vector3f b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

// 向量减法 v1 - v2
vector3f vec_sub(vector3f a, vector3f b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

// 点乘 a·b
float vec_dot(vector3f a, vector3f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// 叉乘 a×b
vector3f vec_cross(vector3f a, vector3f b) {
    return vec3(
        a.y*b.z - a.z*b.y,
        a.z*b.x - a.x*b.z,
        a.x*b.y - a.y*b.x
    );
}

// 向量模长 |v|
float vec_length(vector3f v) {
    return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

// 单位化 v/|v|
vector3f vec_normalize(vector3f v) {
    float len = vec_length(v);
    if (len == 0) return vec3(0,0,0);
    return vec3(v.x/len, v.y/len, v.z/len);
}
int main() {
    // 定义点
    vector3f A = vec3(0, 0, 0);
    vector3f B = vec3(1, 0, 0);
    vector3f C = vec3(1, 1, 0);
    vector3f A1 = vec3(0, 0, 1);
    vector3f B1 = vec3(1, 0, 1);
    vector3f C1 = vec3(1, 1, 1);

    vector3f E = vec3(0.5, 0, 1); // A1B1 中点
    vector3f F = vec3(0.5, 0, 0); // AB 中点

    // (1) B到直线AC的距离
    vector3f AB = vec_sub(B, A);
    vector3f AC = vec_sub(C, A);
    float d1 = vec_length(vec_cross(AB, AC)) / vec_length(AC);
    printf("B到AC的距离: %f\n", d1);

    // (2) 直线FC到平面AEC1的距离
    vector3f AE = vec_sub(E, A);
    vector3f AC1 = vec_sub(C1, A);
    vector3f normal = vec_normalize(vec_cross(AE, AC1)); // 平面法向量

    // 直线FC的一点F
    float d2 = fabs(vec_dot(vec_sub(F, A), normal)); // 点到平面距离
    printf("FC到AEC1的距离: %f\n", d2);

    return 0;
}