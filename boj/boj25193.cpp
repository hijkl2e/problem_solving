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
	int cnt = count(S.begin(), S.end(), 'C');
	int ans{};
	if (cnt) {
		for (int i = 1;; ++i) {
			if ((cnt - 1) / i <= N - cnt) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
