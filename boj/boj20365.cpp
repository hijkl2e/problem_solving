#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	int cnt{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && S[i] == S[j]) {
			++j;
		}
		++cnt;
	}
	int ans = cnt / 2 + 1;
	cout << ans << "\n";
	return 0;
}
