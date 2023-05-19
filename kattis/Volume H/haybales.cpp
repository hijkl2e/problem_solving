#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	while (S.size()) {
		while (S.size() && S.front() == 'C') {
			S.erase(S.begin());
		}
		while (S.size() && S.back() == 'P') {
			S.erase(--S.end());
		}
		if (S.size() < 3) {
			ans += S.size() > 0;
			break;
		}
		int p{};
		for (int i = 0; i < S.size() - 2; ++i) {
			if (S[i] == 'P' && S[i + 2] == 'C') {
				p = i;
				break;
			}
		}
		sort(S.begin() + p, S.begin() + p + 3);
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
