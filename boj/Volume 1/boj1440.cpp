#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(3);
	char c{};
	cin >> A[0] >> c >> A[1] >> c >> A[2];
	vector<int> B(3);
	for (int i = 0; i < 3; ++i) {
		B[i] = i;
	}
	int ans{};
	do {
		int x = A[B[0]];
		int y = A[B[1]];
		int z = A[B[2]];
		if (1 <= x && x <= 12 && 0 <= y && y <= 59 && 0 <= z && z <= 59) {
			++ans;
		}
	} while (next_permutation(B.begin(), B.end()));
	cout << ans << "\n";
	return 0;
}
