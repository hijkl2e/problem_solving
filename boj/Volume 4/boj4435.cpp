#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	vector<int> A{1, 2, 3, 3, 4, 10};
	vector<int> B{1, 2, 2, 2, 3, 5, 10};
	for (int tc = 1; tc <= T; ++tc) {
		vector<int> C(6);
		vector<int> D(7);
		for (int i = 0; i < 6; ++i) {
			cin >> C[i];
		}
		for (int i = 0; i < 7; ++i) {
			cin >> D[i];
		}
		int x{}, y{};
		for (int i = 0; i < 6; ++i) {
			x += A[i] * C[i];
		}
		for (int i = 0; i < 7; ++i) {
			y += B[i] * D[i];
		}
		cout << "Battle " << tc << ": ";
		if (x > y) {
			cout << "Good triumphs over Evil\n";
		} else if (x < y) {
			cout << "Evil eradicates all trace of Good\n";
		} else {
			cout << "No victor on this battle field\n";
		}
	}
	return 0;
}
