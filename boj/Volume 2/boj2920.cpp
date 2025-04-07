#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(8);
	for (int i = 0; i < 8; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	if (A == B) {
		cout << "ascending\n";
	} else {
		sort(B.rbegin(), B.rend());
		cout << (A == B ? "descending" : "mixed") << "\n";
	}
	return 0;
}
