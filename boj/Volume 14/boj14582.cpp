#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(9);
	vector<int> B(9);
	for (int i = 0; i < 9; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 9; ++i) {
		cin >> B[i];
	}
	bool yes = false;
	int x{}, y{};
	for (int i = 0; i < 9; ++i) {
		x += A[i];
		yes |= x > y;
		y += B[i];
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
