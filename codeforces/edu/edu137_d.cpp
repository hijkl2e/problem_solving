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
	if (S.find('1') == -1) {
		cout << "0\n";
		return 0;
	}
	S = S.substr(S.find('1'));
	if (S.find('0') == -1) {
		cout << S << "\n";
		return 0;
	}
	int idx = S.find('0');
	string ans = S;
	for (int i = 0; i < idx; ++i) {
		string T = S;
		for (int j = idx; j < N; ++j) {
			T[j] |= S[i + j - idx];
		}
		ans = max(ans, T);
	}
	cout << ans << "\n";
	return 0;
}
