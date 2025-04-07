#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A(26);
	while (N--) {
		string S;
		getline(cin, S);
		reverse(S.begin(), S.end());
		int x = 1;
		for (char c : S) {
			A[c - 'A'] += x;
			x *= 10;
		}
	}
	sort(A.rbegin(), A.rend());
	int ans{};
	for (int i = 0; i < 10; ++i) {
		ans += (9 - i) * A[i];
	}
	cout << ans << "\n";
	return 0;
}
