#include<iostream>
#include<algorithm>
int main () {
    int dump, flatten, temp, box[100];
    for(int i = 0; i < 10; ++i){
        std::cin >> dump;
        for(int j = 0; j < 100; ++j)
            std::cin >> box[j];
        std::sort(box, box + 100);
        for(int j = 0; j < dump; ++j){
            --box[99]; ++box[0];
            flatten = 0;
            while(box[++flatten] < box[0]);
            temp = box[0];
            box[0] = box[flatten - 1];
            box[flatten - 1] = temp;
            flatten = 99;
            while(box[--flatten] > box[99]);
            temp = box[99];
            box[99] = box[flatten + 1];
            box[flatten + 1] = temp;
        }
        std::cout << "#" << i + 1 << " " << box[99] - box[0] << "\n";
    }
    return 0;
}
