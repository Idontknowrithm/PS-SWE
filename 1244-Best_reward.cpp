#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int N, K, ans;
char tmp[256];
string s;

void cal(int cnt, int now) {
	if (cnt == K) {
		ans = max(ans, stoi(s));
		return;
	}
	for (int i = now; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			if (i == j)
                continue;
			if (s[i] <= s[j]) {
				swap(s[i], s[j]);
				cal(cnt + 1, i);
				swap(s[i], s[j]);
			}
		}
	}

}

int main() {
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s %d", tmp, &K);
        ans = 0; s = tmp;
		cal(0, 0);
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
