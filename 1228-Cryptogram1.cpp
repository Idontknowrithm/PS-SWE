#include<iostream>
#include<vector>
int main () {
    std::vector<int> code;
    int len, insLen, inp, insert;
    for(int i = 0; i < 10; ++i){
        code.clear();
        scanf("%d", &len);
        for(int j = 0; j < len; ++j){
            scanf("%d", &inp);
            code.push_back(inp);
        }
        scanf("%d", &insLen);
        for(int j = 0; j < insLen; ++j){
            while(getchar() != 'I');
            scanf("%d %d", &insert, &len);
            for(int k = 0; k < len; ++k){
                scanf("%d", &inp);
                code.insert(code.begin() + insert + k, inp);
            }
        }
        printf("#%d", i + 1);
        for(int j = 0; j < 10; ++j)
            printf(" %d", code[j]);
        printf("\n");
    }
    return 0;
}
