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
		istringstream iss(S);
		vector<int> A;
		int x{};
		while (iss >> x) {
			A.push_back(x);
		}
		int ans = 1;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = i + 1; j < A.size(); ++j) {
				ans = max(ans, gcd(A[i], A[j]));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
