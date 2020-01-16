#include<iostream>
int main () {
    int arr[100][100], max, temp1, temp2;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &arr[0][0]);
        for(int j = 0; j < 100; ++j)
        for(int k = 0; k < 100; ++k)
            scanf("%d", &arr[j][k]);
        max = -2100000000;
        for(int j = 0; j < 100; ++j){
            temp1 = temp2 = 0;
            for(int k = 0; k < 100; ++k){
                temp1 += arr[j][k];
                temp2 += arr[k][j];
            }
            max = (max < temp1) ? temp1 : max;
            max = (max < temp2) ? temp2 : max;
        }
        temp1 = temp2 = 0;
        for(int j = 0; j < 100; ++j){
            temp1 += arr[j][j];
            temp2 += arr[99 - j][j];
        }
        max = (max < temp1) ? temp1 : max;
        max = (max < temp2) ? temp2 : max;
        printf("#%d %d\n", i + 1, max);
    }
    return 0;
}
