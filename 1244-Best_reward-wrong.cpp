#include<iostream>
#include<cstring>

int ans, maxChange;

int strToNum(char* numStr){
    int index = 1, ans = 0;
    for(int i = 0; i < strlen(numStr); ++i){
        ans += (numStr[strlen(numStr) - i - 1] - '0') * index;
        index *= 10;
    }
    return ans;
}

void maxReward(char* numStr, int changedNum, int index){
    char temp, tempStr[100];
    int bigId = -1, biggest = -1;
    printf("ok\n");
    if(changedNum == maxChange){
        ans = (ans < strToNum(numStr)) ? strToNum(numStr) : ans;
        return;
    }

    if(index == strlen(numStr) - 2){
        strcpy(tempStr, numStr);
        temp = tempStr[strlen(numStr) - 2];
        tempStr[strlen(numStr) - 2] = tempStr[strlen(numStr) - 1];
        tempStr[strlen(numStr) - 1] = temp;
        maxReward(tempStr, changedNum + 1, index);
        return;
    }

    for(int i = index; i < strlen(numStr); ++i){
        biggest = (numStr[i] > biggest) ? numStr[i] : biggest;
        bigId = (numStr[i] > biggest) ? i : bigId;
    }

    if(numStr[index] == biggest){
        printf("==ok\n");
        maxReward(numStr, changedNum, index + 1);
    }

    for(int i = index + 1; i < strlen(numStr); ++i){
        if(numStr[i] == biggest){
            strcpy(tempStr, numStr);
            temp = tempStr[bigId];
            tempStr[bigId] = tempStr[index];
            tempStr[index] = temp;
            printf("2nd==ok\n");
            maxReward(tempStr, changedNum + 1, index + 1);    
        }
    }
}

int main () {
    int T;
    char numStr[100];
    scanf("%d", &T);
    for(int z = 0; z < T; ++z){
        while(getchar() != '\n');
        scanf("%s %d", numStr, &maxChange);
        ans = -1;
        maxReward(numStr, 0, 0);
        scanf("#%d %d\n", z + 1, ans);
    }
    return 0;
}
