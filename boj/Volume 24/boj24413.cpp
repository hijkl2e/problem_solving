#include <bits/stdc++.h>

using namespace std;

vector<int> A{
	7, 56, 448, 73, 146, 292, 273, 84
};

int solve(int x) {
	for (int y : A) {
		if ((x & y & 511) != y) {
			continue;
		}
		int z = (x >> 9) & y & 511;
		if (z == y) {
			return 1;
		} else if (z == 0) {
			return 2;
		}
	}
	return (x & 511) == 511 ? 0 : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int x{};
		for (char c : S) {
			x = (x << 3) + (c & 7);
		}
		int res = solve(x);
		if (res == 1) {
			cout << "X wins\n";
		} else if (res == 2) {
			cout << "O wins\n";
		} else if (res == 0) {
			cout << "Cat's\n";
		} else {
			cout << "In progress\n";
		}
	}
	return 0;
}
