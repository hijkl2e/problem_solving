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
	int ans{};
	for (int i = 0, j = 0; i < N; ++i) {
		if (S[i] == 'O') {
			ans += i + j++ + 1;
		} else {
			j = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}
