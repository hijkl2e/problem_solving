#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(N + 1);
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == 'R') {
			++A[max(i - K, 0)];
			--A[min(i + K, N - 1) + 1];
		}
	}
	partial_sum(A.begin(), A.end(), A.begin());
	bool yes = N - count(A.begin(), A.end() - 1, 0) <= M;
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
