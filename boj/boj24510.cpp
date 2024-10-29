#include <bits/stdc++.h>

using namespace std;

int solve(string S, string T) {
	int cnt{}, idx = -1;
	while ((idx = S.find(T, idx + 1)) != -1) {
		++cnt;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	int ans{};
	while (N--) {
		string S;
		getline(cin, S);
		int cnt = solve(S, "for") + solve(S, "while");
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
