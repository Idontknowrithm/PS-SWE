#include<iostream>
int flag, maze[100][100], trace[100][100];
void find(int curR, int curC);
int main (){
    int rowSt, colSt;
    char inp;
    for(int i = 0; i < 10; ++i){
        getchar();getchar();
        for(int j = 0; j < 100; ++j){
            for(int k = 0; k < 100; ++k){
                scanf("%c", &inp);
                maze[j][k] = inp - '0';
                if(inp == '2'){
                    rowSt = j; 
                    colSt = k;
                }
                trace[j][k] = 0;
            }
            getchar();
        }
        flag = 0;
        find(rowSt, colSt);
        printf("#%d %d\n", i + 1, flag);
    }
    return 0;
}
void find(int curR, int curC){
    if(curR < 0 || curR > 99 || curC < 0 || curC > 99 || 
    trace[curR][curC] == 1 || maze[curR][curC] == 1)
        return;
    else if(maze[curR][curC] == 3){
        ++flag;
        return;
    }
    ++trace[curR][curC];
    find(curR, curC + 1);
    find(curR + 1, curC);
    find(curR, curC - 1);
    find(curR - 1, curC);
}
