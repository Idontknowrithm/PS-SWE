#include<cstdio>
int main () {
    int len, ans = 0;
    char table[8][8];
    for(int i = 0; i < 10; ++i){
        scanf("%d", &len);
        for(int j = 0; j < 8; ++j){
            getchar();
            for(int k = 0; k < 8; ++k)
                scanf("%c", &table[j][k]);
        }
        ans = 0;
        for(int j = 0; j < 8; ++j)
            for(int k = 0; k < 9 - len; ++k){
                int check1 = 0, check2 = 0;
                for(int l = 0; l < len / 2; ++l){
                    check1 += (table[j][k + l] == table[j][k + len - l - 1]) ? 1 : 0;
                    check2 += (table[k + l][j] == table[k + len - l - 1][j]) ? 1 : 0;
                }
                ans += (check1 == len / 2) ? 1 : 0;
                ans += (check2 == len / 2) ? 1 : 0;
            }
        printf("#%d %d\n", i + 1, ans);
    }
    return 0;
}
