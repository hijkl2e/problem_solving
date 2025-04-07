#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	string S;
	cin >> S;
	for (int i = 0; i < 3; ++i) {
		cout << A[S[i] - 'A'] << (i == 2 ? "\n" : " ");
	}
	return 0;
}
