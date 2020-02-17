#include<iostream>

int main () {
    int T, N, where; double magnet[2][15];
    double st, nd, mid, leftF, rightF;
    scanf("%d", &T);
    for(int z = 0; z < T; ++z){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i)
            scanf("%lf", &magnet[0][i]); // x
        for(int i = 0; i < N; ++i)
            scanf("%lf", &magnet[1][i]); // force

        printf("#%d", z + 1);
        for(int i = 0; i < N - 1; ++i){
            int test = 100000;
            st = (double)magnet[0][i];
            nd = (double)magnet[0][i + 1];
            where = i + 1;
            while(--test){
                mid = (st + nd) / 2;
                leftF = rightF = 0;
                for(int j = 0; j < where; ++j)
                    leftF += (double)magnet[1][j] / ((mid - magnet[0][j]) * (mid - magnet[0][j]));
                for(int j = 0; j < N - where; ++j)
                    rightF += (double)magnet[1][N - j - 1] / ((mid - magnet[0][N - j - 1]) * (mid - magnet[0][N - j - 1]));
                if(leftF < rightF)
                    nd = mid;
                else if(leftF > rightF)
                    st = mid;
            }
            printf(" %.10lf", mid);
        }   
        printf("\n");
    }
    return 0;
}
