#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	int T{}, P{};
	cin >> T >> P;
	int x{}, y{}, z{};
	for (int i = 0; i < 6; ++i) {
		if (A[i]) {
			x += (A[i] - 1) / T + 1;
		}
	}
	y = N / P;
	z = N % P;
	cout << x << "\n" << y << " " << z << "\n";
	return 0;
}
