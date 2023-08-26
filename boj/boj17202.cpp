#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	getline(cin, A);
	getline(cin, B);
	string S;
	for (int i = 0; i < 8; ++i) {
		S += A[i];
		S += B[i];
	}
	while (S.size() > 2) {
		string T;
		for (int i = 1; i < S.size(); ++i) {
			T += to_string((S[i - 1] + S[i] - 2 * '0') % 10);
		}
		S = T;
	}
	cout << S << "\n";
	return 0;
}
