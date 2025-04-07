#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(4);
	cin >> A[0] >> A[1] >> A[3] >> A[2];
	int maxv{}, maxi{};
	for (int i = 0; i < 4; ++i) {
		int val = A[0] * A[1] * (A[0] * A[2] + A[1] * A[3]);
		if (maxv < val) {
			maxv = val;
			maxi = i;
		}
		rotate(A.begin(), A.end() - 1, A.end());
	}
	cout << maxi << "\n";
	return 0;
}
