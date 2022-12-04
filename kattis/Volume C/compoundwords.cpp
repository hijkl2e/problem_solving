#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A;
	string s;
	while (cin >> s) {
		A.push_back(s);
	}
	vector<string> B;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {
			if (i == j) {
				continue;
			}
			B.push_back(A[i] + A[j]);
		}
	}
	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
