#include<iostream>
#include<queue>
int main () {
    int inp;
    std::queue<int> que;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &inp);
        for(int j = 0; j < 8; ++j){
            scanf("%d", &inp);
            que.push(inp);
        }
        while(que.back()){
            for(int j = 0; j < 5; ++j){
                inp = (que.front() - j - 1 < 0) ? 0 : que.front() - j - 1;
                que.pop();
                que.push(inp);
                if(!que.back()) break;
            }
        }
        printf("#%d", i + 1);
        for(int j = 0; j < 8; ++j){
            printf(" %d", que.front());
            que.pop();
        }
        printf("\n");
    }
}
