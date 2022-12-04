#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int K{};
	cin >> S >> K;
	vector<char> A;
	for (int i = 0; i < S.size(); ++i) {
		if (i + K < S.size() || i - K >= 0) {
			A.push_back(S[i]);
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0, j = 0; i < S.size(); ++i) {
		if (i + K < S.size() || i - K >= 0) {
			S[i] = A[j++];
		}
	}
	string T = S;
	sort(T.begin(), T.end());
	cout << (S == T ? "Yes" : "No") << "\n";
	return 0;
}
