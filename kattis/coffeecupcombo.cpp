#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int last = -INF;
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (S[i] == '1') {
			last = i;
		}
		if (i - last < 3) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
