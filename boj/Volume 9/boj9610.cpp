#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(5);
	vector<string> B{
		"Q1", "Q2", "Q3", "Q4", "AXIS"
	};
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		int z = x == 0 || y == 0 ? 4 : x > 0 ? y > 0 ? 0 : 3 : y > 0 ? 1 : 2;
		++A[z];
	}
	for (int i = 0; i < 5; ++i) {
		cout << B[i] << ": " << A[i] << "\n";
	}
	return 0;
}
