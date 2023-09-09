#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		vector<int> A(8);
		int x = 2 * (S[0] == 'H') + (S[1] == 'H');
		for (int i = 2; i < S.size(); ++i) {
			x = (2 * x + (S[i] == 'H')) % 8;
			++A[x];
		}
		for (int i = 0; i < 8; ++i) {
			cout << A[i] << (i == 7 ? "\n" : " ");
		}
	}
	return 0;
}
