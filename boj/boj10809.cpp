#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(26, -1);
	for (int i = S.size() - 1; i >= 0; --i) {
		A[S[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; ++i) {
		cout << A[i] << (i == 25 ? "\n" : " ");
	}
	return 0;
}
