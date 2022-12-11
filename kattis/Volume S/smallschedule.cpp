#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{}, M{}, S{}, L{};
	cin >> Q >> M >> S >> L;
	int ans = L ? Q * ((L - 1) / M + 1) : 0;
	S -= min(Q * ((M - L % M) % M), S);
	ans += S ? (S - 1) / M + 1 : 0;
	cout << ans << "\n";
	return 0;
}
