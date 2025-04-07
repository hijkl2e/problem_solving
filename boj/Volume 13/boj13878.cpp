#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		10, 8, 11, 12, 13, 14, 11, 15, 1, 16,
		17, 18, 19, 20, 0, 21, 0, 22, 5, 23,
		24, 24, 25, 26, 24, 2
	};
	vector<int> D{2, 4, 5, 7, 8, 10, 11, 13};
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		string S;
		cin >> K >> S;
		cout << K << " ";
		vector<int> B(9);
		for (int i = 0; i < 9; ++i) {
			if (isdigit(S[i])) {
				B[i] = S[i] - '0';
			} else {
				B[i] = A[S[i] - 'A'];
			}
		}
		ll x{};
		for (int i = 0; i < 8; ++i) {
			x += D[i] * B[i];
		}
		x %= 27;
		if (x != B[8]) {
			cout << "Invalid\n";
			continue;
		}
		x = 0;
		for (int i = 0; i < 8; ++i) {
			x = 27 * x + B[i];
		}
		cout << x << "\n";
	}
	return 0;
}
