#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int g{};
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			g = gcd(g, abs(A[i] - A[j]));
		}
	}
	vector<int> B;
	for (int i = 1; i * i <= g; ++i) {
		if (g % i == 0) {
			B.push_back(i);
			if (i * i < g) {
				B.push_back(g / i);
			}
		}
	}
	sort(B.begin(), B.end());
	for (int i = 1; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
