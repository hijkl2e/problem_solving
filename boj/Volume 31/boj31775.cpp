#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(3);
	for (int i = 0; i < 3; ++i) {
		getline(cin, A[i]);
	}
	sort(A.begin(), A.end());
	bool yes = A[0][0] == 'k' && A[1][0] == 'l' && A[2][0] == 'p';
	cout << (yes ? "GLOBAL" : "PONIX") << "\n";
	return 0;
}
