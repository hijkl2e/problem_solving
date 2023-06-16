#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		vector<int> A(26);
		for (char c : S) {
			++A[c - 'a'];
		}
		sort(A.rbegin(), A.rend());
		int ans = S.size() - A[0] - A[1];
		cout << ans << "\n";
	}
	return 0;
}
