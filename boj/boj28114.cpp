#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> P(3);
	vector<int> Y(3);
	vector<string> S(3);
	for (int i = 0; i < 3; ++i) {
		cin >> P[i] >> Y[i] >> S[i];
	}
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		A[i] = Y[i] % 100;
	}
	sort(A.begin(), A.end());
	vector<is> B(3);
	for (int i = 0; i < 3; ++i) {
		B[i] = {P[i], S[i]};
	}
	sort(B.rbegin(), B.rend());
	for (int i = 0; i < 3; ++i) {
		cout << A[i] << (i == 2 ? "\n" : "");
	}
	for (int i = 0; i < 3; ++i) {
		cout << B[i].second[0] << (i == 2 ? "\n" : "");
	}
	return 0;
}
