#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1;
	getline(cin, s1);
	string s2 = s1 + "0000";
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	vector<int> A(s2.size() + 1);
	for (int i = 0; i < s1.size(); ++i) {
		A[i] += s1[i] - '0';
	}
	for (int i = 0; i < s2.size(); ++i) {
		A[i] += s2[i] - '0';
	}
	for (int i = 0; i < A.size() - 1; ++i) {
		if (A[i] > 1) {
			++A[i + 1];
			A[i] -= 2;
		}
	}
	while (A.size() > 1 && A.back() == 0) {
		A.pop_back();
	}
	for (int i = A.size() - 1; i >= 0; --i) {
		cout << A[i];
	}
	cout << "\n";
	return 0;
}
