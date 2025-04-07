#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string A, B;
	cin >> A >> B;
	vector<string> grid(B.size(), string(A.size(), '.'));
	for (int i = 0; i < A.size(); ++i) {
		if (B.find(A[i]) == -1) {
			continue;
		}
		int idx = B.find(A[i]);
		grid[idx] = A;
		for (int j = 0; j < B.size(); ++j) {
			grid[j][i] = B[j];
		}
		break;
	}
	for (auto &s : grid) {
		cout << s << "\n";
	}
	return 0;
}
