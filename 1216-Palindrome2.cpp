#include<cstdio>
int onePalC(char table[][100], int row, int col);
int onePalR(char table[][100], int row, int col);
int twoPalC(char table[][100], int row, int col);
int twoPalR(char table[][100], int row, int col);
int main () {
    int inp, longest;
    char table[100][100];
    for(int i = 0; i < 10; ++i){
        scanf("%d", &inp);
        for(int j = 0; j < 100; ++j){
            getchar();
            for(int k = 0; k < 100; ++k)
                scanf("%c", &table[j][k]);
        }
        longest = -2147000000;
        for(int j = 0; j < 100; ++j)
        for(int k = 0; k < 100; ++k){
            int temp;
            temp = onePalC(table, j, k);
            longest = (temp > longest) ? temp : longest;
            temp = onePalR(table, j, k);
            longest = (temp > longest) ? temp : longest;
            temp = twoPalC(table, j, k);
            longest = (temp > longest) ? temp : longest;
            temp = twoPalR(table, j, k);
            longest = (temp > longest) ? temp : longest;
        }
        printf("#%d %d\n", i + 1, longest);
    }
}
int onePalC(char table[][100], int row, int col){
    int l = col, r = col, ans = 1;
    l -= (col - 1 >= 0) ? 1 : 0;
    r += (col + 1 < 100) ? 1 : 0;
    while(l + r == col * 2 && table[row][l] == table[row][r]){
        ++ans; ++ans;
        l -= (l - 1 >= 0) ? 1 : 0;
        r += (r + 1 < 100) ? 1 : 0;
    }
    return ans;
}
int onePalR(char table[][100], int row, int col){
    int l = row, r = row, ans = 1;
    l -= (row - 1 >= 0) ? 1 : 0;
    r += (row + 1 < 100) ? 1 : 0;
    while(l + r == row * 2 && table[l][col] == table[r][col]){
        ++ans; ++ans;
        l -= (l - 1 >= 0) ? 1 : 0;
        r += (r + 1 < 100) ? 1 : 0;
    }
    return ans;
}
int twoPalC(char table[][100], int row, int col){
    if(col == 99) return 0;
    int l = col, r = col + 1, ans;
    if(table[row][r] == table[row][l]) ans = 2;
    else                               return 0;
    l -= (l - 1 >= 0) ? 1 : 0;
    r += (r + 1 < 100) ? 1 : 0;
    while(l + r == (col * 2) + 1 && table[row][r] == table[row][l]){
        ++ans; ++ans;
        l -= (l - 1 >= 0) ? 1 : 0;
        r += (r + 1 < 100) ? 1 : 0;    
    }
    return ans;
}
int twoPalR(char table[][100], int row, int col){
    if(row == 99) return 0;
    int l = row, r = row + 1, ans;
    if(table[l][col] == table[r][col]) ans = 2;
    else                               return 0;
    l -= (l - 1 >= 0) ? 1 : 0;
    r += (r + 1 < 100) ? 1 : 0;
    while(l + r == (row * 2) + 1 && table[r][col] == table[l][col]){
        ++ans; ++ans;
        l -= (l - 1 >= 0) ? 1 : 0;
        r += (r + 1 < 100) ? 1 : 0;    
    }
    return ans;
}
