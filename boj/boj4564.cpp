#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A{N};
		while (N >= 10) {
			int x = 1;
			while (N) {
				x *= N % 10;
				N /= 10;
			}
			N = x;
			A.push_back(N);
		}
		for (int i = 0; i < A.size(); ++i) {
			cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
