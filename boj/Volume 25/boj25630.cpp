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
	for (int i = 0; i < N / 2; ++i) {
		if (S[i] != S[N - i - 1]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
