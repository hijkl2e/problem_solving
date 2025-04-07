#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu",
		"in", "bed", "tururu", "turu", "baby", "sukhwan"
	};
	int N{};
	cin >> N;
	--N;
	string ans = A[N % 14];
	if (ans[0] == 't') {
		N /= 14;
		while (N--) {
			ans += "ru";
		}
	}
	if (ans.size() > 10) {
		ans = "tu+ru*" + to_string(ans.size() / 2 - 1);
	}
	cout << ans << "\n";
	return 0;
}
