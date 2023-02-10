#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(6);
	vector<int> B(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < 6; ++i) {
		cin >> B[i];
	}
	int n{}, d = 36;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (A[i] > B[j]) {
				++n;
			}
		}
	}
	int g = gcd(n, d);
	n /= g, d /= g;
	cout << n << "/" << d << "\n";
	return 0;
}
