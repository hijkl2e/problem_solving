#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S;
	getline(cin, S);
	if (count(S.begin(), S.end(), '.') == N) {
		int ans = N - max(M - 2, 0);
		cout << ans << "\n";
		return 0;
	}
	vector<int> A;
	int cnt{}, ans{};
	for (int i = 0; i < N; ++i) {
		if (S[i] == '.') {
			++cnt;
			++ans;
		} else if (cnt || i == 0) {
			A.push_back(cnt);
			cnt = 0;
			ans += 2;
		}
	}
	A.push_back(cnt);
	sort(A.begin() + 1, A.end() - 1);
	for (int i = 1; i < A.size() - 1; ++i) {
		int x = min(A[i], M);
		M -= x;
		ans -= x + (x == A[i] ? 2 : 0);
	}
	ans -= min(A.front() + A.back(), M);
	cout << ans << "\n";
	return 0;
}
