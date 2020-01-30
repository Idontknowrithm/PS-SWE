#include<cstdio>
int main () {
    int len, ans, val, temp;
    char ope;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &len); getchar();
        ans = 0;
        scanf("%d", &temp);
        for(int j = 0; j < len / 2; ++j){
            scanf("%c", &ope);
            if(ope == '+'){
                ans += temp;
                scanf("%d", &val);
                temp = val;
            }
            else if(ope == '*'){
                scanf("%d", &val);
                temp *= val;
            }
        }
        ans += temp;
        printf("#%d %d\n", i + 1, ans);
    }
    return 0;
}
