#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		vector<int> A;
		int x{};
		while (iss >> x) {
			A.push_back(x);
		}
		sort(A.begin(), A.end());
		vector<int> B(A.back() + 1);
		for (int i = 0; i < A.size(); ++i) {
			for (int j = i + 1; j < A.size(); ++j) {
				++B[A[j] - A[i]];
			}
		}
		int cnt = count(B.begin() + 1, B.end(), 1);
		if (cnt == A.back()) {
			cout << "perfect\n";
		} else if (cnt + count(B.begin() + 1, B.end(), 0) == A.back()) {
			cout << "missing";
			for (int i = 1; i < B.size(); ++i) {
				if (B[i] == 0) {
					cout << " " << i;
				}
			}
			cout << "\n";
		} else {
			cout << "not a ruler\n";
		}
	}
	return 0;
}
