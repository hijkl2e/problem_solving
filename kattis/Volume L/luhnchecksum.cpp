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
		reverse(S.begin(), S.end());
		vector<int> A(S.size());
		for (int i = 0; i < A.size(); ++i) {
			A[i] = S[i] - '0';
			if (i % 2) {
				A[i] = 2 * A[i] % 10 + 2 * A[i] / 10;
			}
		}
		bool yes = accumulate(A.begin(), A.end(), 0) % 10 == 0;
		cout << (yes ? "PASS" : "FAIL") << "\n";
	}
	return 0;
}
