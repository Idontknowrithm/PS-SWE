#include<iostream>
#include<queue>

void inOrder(char* arr, int index);
int isItOperator(char a);

int ans;
char test;

int main () {
    char arr[500];
    int inp, num;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 500; ++j)
            arr[j] = 'z';
        scanf("%d", &num);
        for(int j = 0; j < num; ++j){
            while(getchar() != '\n');
            scanf("%d", &inp);
            while(getchar() != ' ');
            scanf("%c", &arr[j + 1]);
        }
        test = 'N'; ans = 1;
        inOrder(arr, 1);
        printf("#%d %d\n", i + 1, ans);
    }
    return 0;
}

void inOrder(char* arr, int index){
    if(arr[index] == 'z')
        return;
    inOrder(arr, index * 2);
    if((isItOperator(arr[index]) && test == 'N') ||
       (!isItOperator(arr[index]) && test == 'O')){
           ans = 0;
    }
    if(isItOperator(arr[index]))
        test = 'N';
    else 
        test = 'O';
    inOrder(arr, index * 2 + 1);
}
int isItOperator(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/')
        return 1;
    else 
        return 0;
}
