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
			++x;
		} else if (A[i] < B[i]) {
			++y;
		}
	}
	char c = x > y ? 'A' : x < y ? 'B' : 'D';
	cout << c << "\n";
	return 0;
}
