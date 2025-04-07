#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{}, Q{};
		cin >> N >> M >> Q;
		cin.ignore();
		string S;
		getline(cin, S);
		int maxv = M, cnt = M;
		for (char c : S) {
			if (c == '+') {
				maxv = max(maxv, ++M);
				++cnt;
			} else {
				--M;
			}
		}
		cout << (maxv == N ? "YES" : cnt < N ? "NO" : "MAYBE") << "\n";
	}
	return 0;
}
