#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		string S(N, 'X');
		for (int i = 2;; ++i) {
			if (N % i) {
				for (int j = 0; j < N; ++j) {
					S[j] = 'a' + j % i;
				}
				break;
			}
		}
		cout << S << "\n";
	}
	return 0;
}
