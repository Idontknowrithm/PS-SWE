#include<cstdio>
#include<stack>
int main () {
    int len; char inp;
    std::stack<char> box;
    for(int i = 0; i < 10; ++i){
        scanf("%d", &len);
        getchar();
        for(int j = 0; j < len; ++j){
            scanf("%c", &inp);
            if((inp == '>' && box.top() == '<') ||
               (inp == ')' && box.top() == '(') ||
               (inp == '}' && box.top() == '{') ||
               (inp == ']' && box.top() == '[')  )
                box.pop();
            else 
                box.push(inp);
        }
        if(box.empty())
            printf("#%d %d\n", i + 1, 1);
        else 
            printf("#%d %d\n", i + 1, 0);
        
        while(!box.empty()) box.pop();
    }
}
