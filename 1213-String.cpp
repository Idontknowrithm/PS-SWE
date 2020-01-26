#include<iostream>
#include<string>
int main () {
    int inp, trace; char findStr[15];
    std::string inputStr;
    for(int i = 0; i < 10; ++i){
        std::cin >> inp >> findStr;
        std::cin >> inputStr;
        inp = trace = 0;
        while(inputStr.find(findStr, trace) != -1){
            trace = inputStr.find(findStr, trace) + 1; ++inp;
        }
        printf("#%d %d\n", i + 1, inp);
    }
    return 0;
}
