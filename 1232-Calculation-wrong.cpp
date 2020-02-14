#include<iostream>
#include<cstring>
#include<queue>
#include<stack>

typedef struct{
    char data[6];
} tree;

tree treeNode[2500];
int hash[2500];
std::queue<tree> cal;
std::stack<double> ans;

void postOrder(int start);
int strToNum(char* str);

int main () {
    int N, inp, left, right;
    double temp;
    char inpStr[6];

    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 2500; ++j){
            hash[j] = j;
            strcpy(treeNode[j].data, "N");
        }
        scanf("%d", &N);
        for(int j = 0; j < N; ++j){
            scanf("%d", &inp);
            scanf("%s", inpStr);
            if(inpStr[0] == '-' ||
               inpStr[0] == '+' ||
               inpStr[0] == '/' ||
               inpStr[0] == '*'){
                   scanf("%d %d", &left, &right);
                   hash[left] = inp * 2;
                   hash[right] = inp * 2 + 1;
               }
            strcpy(treeNode[hash[inp]].data, inpStr);
        }
        postOrder(1);
        ans.push(double)(strToNum(cal.front().data)));
        cal.pop();
        while(!cal.empty()){
            if(strcmp(cal.front().data, "+") == 0){
                temp = ans.top();
                ans.pop();
                temp = ans.top() + temp;
                ans.pop();
                ans.push(temp);
                //printf("ok\n");
            }
            else if(strcmp(cal.front().data, "-") == 0){
                temp = ans.top();
                ans.pop();
                temp = ans.top() - temp;
                ans.pop();
                ans.push(temp);
                //printf("ok\n");
            }
            else if(strcmp(cal.front().data, "*") == 0){
                temp = ans.top();
                ans.pop();
                temp = ans.top() * temp;
                ans.pop();
                ans.push(temp);
                //printf("ok\n");
            }
            else if(strcmp(cal.front().data, "/") == 0){
                temp = ans.top();
                ans.pop();
                if(temp == 0)
                    temp = 0;
                else 
                    temp = ans.top() / temp;
                ans.pop();
                ans.push(temp);
                //printf("ok\n");
            }
            else 
                ans.push((double)(strToNum(cal.front().data)));
            cal.pop();
        }
        if(!ans.empty())
            printf("#%d %.0lf\n", i + 1, ans.top());
    }
}

void postOrder(int start){
    if(strcmp(treeNode[start].data, "N") == 0)
        return;
    postOrder(start * 2);
    postOrder(start * 2 + 1);
    cal.push(treeNode[start]);
    // printf("ok, %s\n", treeNode[start].data);
}
int strToNum(char* str){
    int ans = 0, digit = 1;
    for(int i = strlen(str) - 1; i >= 0; --i){
        ans += (str[i] - '0') * digit;
        digit *= 10;
    }
    return ans;
}
