#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans = 50 * N;
	bool flag{};
	for (int i = 0; i < N; ++i) {
		if (A[i][1] == 'o') {
			ans -= 50;
			flag |= A[i][0] == 's';
		} else if (A[i][0] == 'n') {
			ans += flag ? -10 : 90;
		} else if (A[i][1] == 'i') {
			ans -= 20;
			if ((i && A[i - 1][0] == 'z') || (i + 1 < N && A[i + 1][0] == 'z')) {
				ans -= 30;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
