#include<iostream>
int main () {
    int building[1000], tc, ans, max;
    for(int i = 0; i < 10; ++i){
        ans = 0;
        for(int j = 0; j < 1000; ++j)
            building[j] = 0;
        scanf("%d", &tc);
        for(int j = 0; j < tc; ++j)
            scanf("%d", &building[j]);
        for(int j = 2; j < tc - 2; ++j){
            max = 0;
            max = (max < building[j - 2]) ? building[j - 2] : max;
            max = (max < building[j - 1]) ? building[j - 1] : max;
            max = (max < building[j + 1]) ? building[j + 1] : max;
            max = (max < building[j + 2]) ? building[j + 2] : max;
            ans += (max > building[j]) ? 0 : building[j] - max;
        }
        printf("#%d %d\n", i + 1, ans);
    }
    return 0;
}
