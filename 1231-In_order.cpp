#include<iostream>

void inOrder(char* arr, int index);

int main () {
    char arr[101];
    int inp, num;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 101; ++j)
            arr[j] = 'z';
        scanf("%d", &num);
        for(int j = 0; j < num; ++j){
            while(getchar() != '\n');
            scanf("%d", &inp); getchar();
            scanf("%c", &arr[j + 1]);
        }
        printf("#%d ", i + 1);
        inOrder(arr, 1);
        printf("\n");
    } 
    return 0;
}

void inOrder(char* arr, int index){
    if(arr[index] == 'z')
        return;
    inOrder(arr, index * 2);
    printf("%c", arr[index]);
    inOrder(arr, index * 2 + 1);
}
