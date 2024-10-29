#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A, B;
	for (int i = 2; i < 10; ++i) {
		for (int j = 1; j < 4 + (i == 7 || i == 9); ++j) {
			A.push_back(i);
			B.push_back(j);
		}
	}
	int p{}, w{};
	cin >> p >> w;
	cin.ignore();
	string S;
	getline(cin, S);
	int ans{};
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == ' ') {
			ans += p;
			continue;
		}
		int x = S[i] - 'A';
		if (i && S[i - 1] != ' ' && A[x] == A[S[i - 1] - 'A']) {
			ans += w;
		}
		ans += p * B[x];
	}
	cout << ans << "\n";
	return 0;
}
