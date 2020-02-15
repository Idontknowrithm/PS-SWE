#include<iostream>
#include<cstring>

int converter(char* numStr){
    if(!strcmp(numStr, "0001101"))
        return 0;
    else if(!strcmp(numStr, "0011001"))
        return 1;
    else if(!strcmp(numStr, "0010011"))
        return 2;
    else if(!strcmp(numStr, "0111101"))
        return 3;
    else if(!strcmp(numStr, "0100011"))
        return 4;
    else if(!strcmp(numStr, "0110001"))
        return 5;
    else if(!strcmp(numStr, "0101111"))
        return 6;
    else if(!strcmp(numStr, "0111011"))
        return 7;
    else if(!strcmp(numStr, "0110111"))
        return 8;
    else if(!strcmp(numStr, "0001011"))
        return 9;
}
int main () {
    int T, row, col, index, checker, save[2], numTable[8];
    char realCode[8][8], code[50][100];
    
    scanf("%d", &T);
    for(int z = 0; z < T; ++z){
        for(int i = 0; i < 50; ++i)
        for(int j = 0; j < 100; ++j)
            code[i][j] = 0;
        scanf("%d %d", &row, &col);
        for(int i = 0; i < row; ++i){
            while(getchar() != '\n'); // char check
            for(int j = 0; j < col; ++j){
                scanf("%c", &code[i][j]);
                if(code[i][j] == '1'){
                    save[0] = i;
                    save[1] = j;
                }
            }
        }
        index = save[1] - 55;
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 7; ++j){
                realCode[i][j] = code[save[0]][index++];
            }
            realCode[i][7] = '\0';
        }
        for(int i = 0; i < 8; ++i)
            numTable[i] = converter(realCode[i]);
        checker = 0;
        for(int i = 0; i < 8; ++i)
            checker += (i & 1) ? numTable[i] : numTable[i] * 3;
        if(checker % 10 == 0){
            checker = 0;
            for(int i = 0; i < 8; ++i)
                checker += numTable[i];
            printf("#%d %d\n", z + 1, checker);
        }
        else 
            printf("#%d %d\n", z + 1, 0);
    }
    return 0;
}
