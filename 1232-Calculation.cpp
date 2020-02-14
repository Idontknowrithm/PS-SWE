#include <cstdio>  
#include <cstdlib>  
#include <string>  
  
struct CVertex  
{  
    CVertex() {}  
    CVertex(std::string val)  
        : value(val), left(-1), right(-1)  
    {  
    }  
  
    // 현재 정점이 연산자인지?  
    bool IsOperator()  
    {  
        bool ret = false;  
  
        if (!value.compare("+") || !value.compare("-")  
            || !value.compare("*") || !value.compare("/"))  
            ret = true;  
          
        return ret;  
    }  
  
    std::string value;  
    int left;  
    int right;  
};  
  
int N;  
CVertex tree[1000 + 1];  
  
double PostOrder(int V);  
  
int main(void)  
{  
    for (int tc = 0; tc < 10; tc++)  
    {  
        scanf("%d", &N);  
  
        for (int i = 0; i < N; i++)  
        {  
            int V, L, R;  
            char value[100];  
  
            scanf("%d %s", &V, &value);  
            tree[V] = CVertex(std::string(value));  
              
            // 현재 정점이 연산자라면 자식 노드 추가  
            if (tree[V].IsOperator())  
            {  
                scanf("%d %d", &L, &R);  
                tree[V].left = L;  
                tree[V].right = R;  
            }  
        }  
  
        printf("#%d %d\n", tc + 1, static_cast<int>(PostOrder(1)));  
    }  
  
    return 0;  
}  
  
double PostOrder(int V)  
{  
    double x, y, ret;  
    int L = tree[V].left;  
    int R = tree[V].right;  
    std::string value(tree[V].value);  
  
    // 왼쪽 자식이 있다면  
    if (L != -1)  
        x = PostOrder(L);  
  
    // 오른쪽 자식이 있다면  
    if (R != -1)  
        y = PostOrder(R);  
  
    if (!value.compare("+"))  
        ret = x + y;  
    else if (!value.compare("-"))  
        ret = x - y;  
    else if (!value.compare("*"))  
        ret = x * y;  
    else if (!value.compare("/"))  
        ret = x / y;  
    else  
        ret = atoi(value.c_str());  
  
    return ret;  
}
