#include<cstdio>
void power(int base, int exp, int result);
int main () {
    int base, exp;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &base);
        scanf("%d %d", &base, &exp);
        printf("#%d ", i + 1);
        power(base, exp, base);
    }
    return 0;
}
void power(int base, int exp, int result){
    if(exp == 1) {
        printf("%d\n", result);
        return;
    }
    else if(exp == 0) {
        printf("1\n");
        return;
    }
    power(base, exp - 1, result * base);
}
