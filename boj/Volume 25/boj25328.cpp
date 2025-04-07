#include <bits/stdc++.h>

using namespace std;

vector<string> A;
string T;

void solve(string &s, int k, int idx) {
	if (T.size() == k) {
		A.push_back(T);
		return;
	}
	for (int i = idx; i < s.size(); ++i) {
		T.push_back(s[i]);
		solve(s, k, i + 1);
		T.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string x, y, z;
	int k{};
	cin >> x >> y >> z >> k;
	solve(x, k, 0);
	solve(y, k, 0);
	solve(z, k, 0);
	sort(A.begin(), A.end());
	vector<string> B;
	for (int i = 0, j = 1; i < A.size(); i = j) {
		while (j < A.size() && A[i] == A[j]) {
			++j;
		}
		if (i + 1 < j) {
			B.push_back(A[i]);
		}
	}
	if (B.empty()) {
		cout << "-1\n";
	} else {
		for (auto &s : B) {
			cout << s << "\n";
		}
	}
	return 0;
}
