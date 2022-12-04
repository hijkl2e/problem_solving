#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(3);
	A[0] = 1;
	for (char c : S) {
		int x = c - 'A';
		swap(A[x], A[(x + 1) % 3]);
	}
	int ans{};
	for (int i = 0; i < 3; ++i) {
		if (A[i]) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
