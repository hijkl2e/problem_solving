#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = 1; i <= K; ++i) {
		int x = N * i;
		string S = to_string(x);
		reverse(S.begin(), S.end());
		x = stoi(S);
		ans = max(ans, x);
	}
	cout << ans << "\n";
	return 0;
}
