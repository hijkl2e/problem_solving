#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A, B;
	string s;
	while (getline(cin, s), s.size()) {
		A.push_back(s);
	}
	while (getline(cin, s)) {
		B.push_back(s);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	bool yes = true;
	deque<bool> chk(A.size());
	for (int i = 0; i < B.size(); ++i) {
		s = B[i].substr(0, B[i].rfind('_', B[i].rfind('_') - 1));
		int idx = lower_bound(A.begin(), A.end(), s) - A.begin();
		if (idx < A.size() && A[idx] == s) {
			chk[idx] = true;
		} else {
			cout << "F " << B[i] << "\n";
			yes = false;
		}
	}
	for (int i = 0; i < A.size(); ++i) {
		if (!chk[i]) {
			cout << "I " << A[i] << "\n";
			yes = false;
		}
	}
	if (yes) {
		cout << "No mismatches.\n";
	}
	return 0;
}
