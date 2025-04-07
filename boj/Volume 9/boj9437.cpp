#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{};
	while (cin >> N >> P) {
		int x = P;
		x = min(N - x + 1, x);
		x -= 1 - x % 2;
		vector<int> A{
			x, x + 1, N - x, N - x + 1
		};
		A.erase(find(A.begin(), A.end(), P));
		for (int i = 0; i < 3; ++i) {
			cout << A[i] << (i == 2 ? "\n" : " ");
		}
	}
	return 0;
}
