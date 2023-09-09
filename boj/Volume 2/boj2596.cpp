#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{0, 15, 19, 28, 38, 41, 53, 58};
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	string ans;
	for (int i = 0; i < N; ++i) {
		int x{};
		for (int j = 0; j < 6; ++j) {
			x = 2 * x + S[6 * i + j] - '0';
		}
		int k = -1;
		for (int j = 0; j < 8; ++j) {
			if (__builtin_popcount(A[j] ^ x) < 2) {
				k = j;
				break;
			}
		}
		if (k == -1) {
			cout << i + 1 << "\n";
			return 0;
		}
		char c = k + 'A';
		ans += c;
	}
	cout << ans << "\n";
	return 0;
}
