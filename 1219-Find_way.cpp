#include<cstdio>
void dfs(int graph[][100], int start, int* res);
int main () {
    int road, startInp, endInp, res, graph[100][100] = {0, };
    for(int i = 0; i < 10; ++i){
        res = 0;
        for(int j = 0; j < 100; ++j)
        for(int k = 0; k < 100; ++k)
            graph[j][k] = 0;
        scanf("%d", &road); scanf("%d", &road);
        for(int j = 0; j < road; ++j){
            scanf("%d %d", &startInp, &endInp);
            ++graph[startInp][endInp];
        }
        dfs(graph, 0, &res);
        printf("#%d %d\n", i + 1, res);
    }
    return 0;
}
void dfs(int graph[][100], int start, int* res){
    if(start == 99){
        *res = 1; return;
    }
    for(int i = 0; i < 100; ++i){
        if(graph[start][i] == 1)
            dfs(graph, i, res);
    }
}
