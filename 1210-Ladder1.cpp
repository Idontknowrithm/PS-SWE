#include<iostream>
int main () {
    int ladder[100][100], row, col;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &ladder[0][0]);
        for(int j = 0; j < 100; ++j)
        for(int k = 0; k < 100; ++k)
            scanf("%d", &ladder[j][k]);
        for(int j = 0; j < 100; ++j)
            if(ladder[99][j] == 2){
                row = 99; col = j;
                break;
            }
        while(row != 0){
            if(col > 0 && ladder[row][col - 1] == 1)
                while(col > 0 && ladder[row - 1][--col] != 1);
            else if(col < 99 && ladder[row][col + 1] == 1)
                while(col < 99 && ladder[row - 1][++col] != 1);
            --row;
        }
        printf("#%d %d\n", i + 1, col);
    }
    return 0;
}
