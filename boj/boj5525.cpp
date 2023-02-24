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
	int ans{}, cnt{};
	for (int i = 0; i < S.size(); ++i) {
		if (i && S[i - 1] != S[i]) {
			++cnt;
		} else {
			ans += max((cnt + 1) / 2 - N, 0);
			cnt = S[i] == 'I';
		}
	}
	ans += max((cnt + 1) / 2 - N, 0);
	cout << ans << "\n";
	return 0;
}
