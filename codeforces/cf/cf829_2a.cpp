#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		string S;
		cin >> N >> S;
		int cnt{};
		for (char c : S) {
			cnt += c == 'Q' ? 1 : -1;
			cnt = max(cnt, 0);
		}
		cout << (cnt == 0 ? "Yes" : "No") << "\n";
	}
	return 0;
}
