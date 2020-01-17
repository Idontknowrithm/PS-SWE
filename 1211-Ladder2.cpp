#include<iostream>
int find(int ladder[][100], int col);
int main () {
    int ladder[100][100], ansTable[100], min;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &ladder[0][0]);
        for(int j = 0; j < 100; ++j)
        for(int k = 0; k < 100; ++k)
            scanf("%d", &ladder[j][k]);
        min = 100000;
        for(int j = 0; j < 100; ++j){
            ansTable[j] = 100000;
            if(ladder[0][j] == 1){
                ansTable[j] = find(ladder, j);
                min = (ansTable[j] < min) ? ansTable[j] : min;
            }
        }
        for(int j = 99; j >= 0; --j)
            if(min == ansTable[j]){
                printf("#%d %d\n", i + 1, j);
                break;
            }
    }
    return 0;
}
int find(int ladder[][100], int col){
    int row = 0, route = 0;
    while(row != 99){
            if(col > 0 && ladder[row][col - 1] == 1){
                while(col > 0  && ladder[row - 1][--col] != 1) ++route;
                ++route;
            }
            else if(col < 99 && ladder[row][col + 1] == 1){
                while(col < 99 && ladder[row - 1][++col] != 1) ++route;
                ++route;
            }
            ++row; ++route;
    }
    return route;
}
