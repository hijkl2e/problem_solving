#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int k = 0; k < 2; ++k) {
		vector<int> A(5);
		for (int i = 0; i < 5; ++i) {
			cin >> A[i];
		}
		int x = 6 * A[0] + 3 * A[1] + 2 * A[2] + A[3] + 2 * A[4];
		cout << x << (k ? "\n" : " ");
	}
	return 0;
}
