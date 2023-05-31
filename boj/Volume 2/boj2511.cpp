#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	vector<int> B(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 10; ++i) {
		cin >> B[i];
	}
	int x{}, y{};
	for (int i = 0; i < 10; ++i) {
		if (A[i] > B[i]) {
			x += 3;
		} else if (A[i] < B[i]) {
			y += 3;
		} else {
			++x, ++y;
		}
	}
	char c = x > y ? 'A' : x < y ? 'B' : 'D';
	for (int i = 9; i >= 0 && c == 'D'; --i) {
		c = A[i] > B[i] ? 'A' : A[i] < B[i] ? 'B' : 'D';
	}
	cout << x << " " << y << "\n";
	cout << c << "\n";
	return 0;
}
