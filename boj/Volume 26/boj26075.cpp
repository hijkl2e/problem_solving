#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<int> A, B;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '1') {
			A.push_back(i);
		}
		if (T[i] == '1') {
			B.push_back(i);
		}
	}
	ll ans{};
	for (int i = 0; i < M; ++i) {
		ans += abs(A[i] - B[i]);
	}
	ans = (ans / 2) * (ans / 2) + ((ans + 1) / 2) * ((ans + 1) / 2);
	cout << ans << "\n";
	return 0;
}
