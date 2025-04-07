#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A;
	double x{};
	while (cin >> x) {
		A.push_back((x + 10) * 100 + EPS);
	}
	for (int i = 0; i < A.size() - 2; ++i) {
		int y = abs(A[i + 1] - A[i]);
		cout << (A[i] > A[i + 1] ? "-" : "") << y / 100 << "." << setfill('0') << setw(2) << y % 100 << "\n";
	}
	return 0;
}
