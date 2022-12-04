#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string per = "PER";
	int ans{};
	for (int i = 0; i < S.size(); i += 3) {
		for (int j = 0; j < 3; ++j) {
			if (S[i + j] != per[j]) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
