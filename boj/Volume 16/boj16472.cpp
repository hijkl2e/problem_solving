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
	vector<int> A(26);
	int ans{}, cnt{};
	for (int i = 0, j = 0; j < S.size(); ++j) {
		if (++A[S[j] - 'a'] == 1) {
			++cnt;
		}
		while (cnt > N) {
			if (--A[S[i++] - 'a'] == 0) {
				--cnt;
			}
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans << "\n";
	return 0;
}
