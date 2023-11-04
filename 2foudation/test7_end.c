#include<stdio.h>
void hanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        printf("将圆盘从柱子 %c 移动到柱子 %c\n", from_peg, to_peg);
        return;
    }
    hanoi(n - 1, from_peg, aux_peg, to_peg);
    printf("将圆盘从柱子 %c 移动到柱子 %c\n", from_peg, to_peg);
    hanoi(n - 1, aux_peg, to_peg, from_peg);
    printf("将圆盘从柱子 %c 移动到柱子 %c\n", from_peg, to_peg);
}
int jumpWays(int n) {
    if (n <= 0) return 0;  // 如果台阶数小于等于0，没有跳法
    if (n == 1) return 1;  // 如果只有1级台阶，只有1种跳法
    if (n == 2) return 2;  // 如果有2级台阶，有2种跳法（一次跳1级，或者一次跳2级）

    // 对于 n 级台阶，可以选择跳1级后再跳 n-1 级台阶，或者跳2级后再跳 n-2 级台阶
    return jumpWays(n - 1) + jumpWays(n - 2);
}
int main()
{
    //汉诺塔问题，将一个柱子上的圆盘移动到另一个圆盘上，且大圆盘不能在小圆盘上
    hanoi(3,'a','b','c');
    //青蛙跳台阶问题，一次跳一级或者两级
    printf("5级台阶有%d种跳法\n",jumpWays(5));
    return 0;  
}