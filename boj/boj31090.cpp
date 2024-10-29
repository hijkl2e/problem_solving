#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		string ans = (N + 1) % (N % 100) == 0 ? "Good" : "Bye";
		cout << ans << "\n";
	}
	return 0;
}
