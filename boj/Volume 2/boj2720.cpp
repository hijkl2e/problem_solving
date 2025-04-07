#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{25, 10, 5, 1};
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> B(4);
		for (int i = 0; i < 4; ++i) {
			B[i] = N / A[i];
			N %= A[i];
		}
		for (int i = 0; i < 4; ++i) {
			cout << B[i] << (i == 3 ? "\n" : " ");
		}
	}
	return 0;
}
