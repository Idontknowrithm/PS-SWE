#include<iostream>
int main () {
    int N, input, max, scoreTable[101];
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < 101; ++j)
            scoreTable[j] = 0;
        max = 0;
        std::cin >> input;
        for(int j = 0; j < 1000; ++j){
            std::cin >> input;
            ++scoreTable[input];
        }
        for(int j = 0; j < 101; ++j)
            max = (scoreTable[j] > max) ? scoreTable[j] : max;
        for(int j = 100; j >= 0; --j)
            if(scoreTable[j] == max){
                std::cout << "#" << i + 1 << " " << j << "\n";
                break;
            }
    }
    return 0;
}
