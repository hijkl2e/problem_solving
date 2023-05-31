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
		string ans;
		int maxv{};
		while (N--) {
			string S;
			int L{};
			cin >> S >> L;
			if (maxv < L) {
				maxv = L;
				ans = S;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
