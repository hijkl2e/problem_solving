#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	int sz = max(s1.size(), s2.size()) + 1;
	vector<int> A(sz);
	for (int i = 0; i < s1.size(); ++i) {
		A[i] = s1[s1.size() - i - 1] - '0';
	}
	for (int i = 0; i < s2.size(); ++i) {
		A[i] += s2[s2.size() - i - 1] - '0';
	}
	for (int i = 0; i < sz - 1; ++i) {
		if (A[i] >= 10) {
			A[i] -= 10;
			++A[i + 1];
		}
	}
	for (int i = sz - 1 - (A[sz - 1] == 0); i >= 0; --i) {
		cout << A[i];
	}
	cout << "\n";
	return 0;
}
