#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "N" + S;
	int ans{};
	for (int i = 1; i < S.size(); ++i) {
		if (S[i] == 'N') {
			continue;
		}
		for (int j = i; j < S.size(); j += i) {
			S[j] ^= 23;
		}
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
