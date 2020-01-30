#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
int main () {
    int len, ans, tempVal1, tempVal2;
    char inpStr[10000];
    std::queue<char> postfix;
    std::stack<int> opeStk, calculator;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &len);
        scanf("%s", inpStr);
        for(int j = 0; j < strlen(inpStr); ++j){
            if(inpStr[j] >= '0' && inpStr[j] <= '9')
                postfix.push(inpStr[j]);
            else if(inpStr[j] == '(')
                opeStk.push('(');
            else if(inpStr[j] == '+'){
                while(opeStk.top() != '(' && !opeStk.empty()){
                    postfix.push(opeStk.top());
                    opeStk.pop();
                }
                opeStk.push('+');
            }
            else if(inpStr[j] == '*'){
                while(opeStk.top() == '*'){
                    postfix.push(opeStk.top());
                    opeStk.pop();
                }
                opeStk.push('*');
            }
            else if(inpStr[j] == ')'){
                while(opeStk.top() != '('){
                    postfix.push(opeStk.top());
                    opeStk.pop();
                }
                opeStk.pop();
            }
        }
        ans = 0;
        while(!postfix.empty()){
            if(postfix.front() >= '0' && postfix.front() <= '9'){
                calculator.push(postfix.front() - '0');
                postfix.pop();
            }
            else if(postfix.front() == '+'){
                postfix.pop();
                tempVal1 = calculator.top();
                calculator.pop();
                tempVal2 = calculator.top();
                calculator.pop();
                calculator.push(tempVal1 + tempVal2);
            }
            else if(postfix.front() == '*'){
                postfix.pop();
                tempVal1 = calculator.top();
                calculator.pop();
                tempVal2 = calculator.top();
                calculator.pop();
                calculator.push(tempVal1 * tempVal2);
            }
        }
        printf("#%d %d\n", i + 1, calculator.top());
    }
    return 0;
}
