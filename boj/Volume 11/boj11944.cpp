#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	string ans;
	for (int i = 0; i < N && ans.size() < M; ++i) {
		ans += to_string(N);
	}
	ans = ans.substr(0, M);
	cout << ans << "\n";
	return 0;
}
