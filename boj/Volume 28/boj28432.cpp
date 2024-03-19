#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int idx = find(A.begin(), A.end(), "?") - A.begin();
	int M{};
	cin >> M;
	cin.ignore();
	string ans;
	while (M--) {
		string S;
		getline(cin, S);
		if ((idx == 0 || A[idx - 1].back() == S.front())
				&& (idx == N - 1 || A[idx + 1].front() == S.back())
				&& find(A.begin(), A.end(), S) == A.end()) {
			ans = S;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
