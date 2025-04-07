#include <bits/stdc++.h>

using namespace std;

bool solve(int N, int b) {
	vector<int> A;
	while (N) {
		A.push_back(N % b);
		N /= b;
	}
	vector<int> B(A.begin(), A.end());
	reverse(B.begin(), B.end());
	return A == B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		bool yes{};
		for (int i = 2; i < 65; ++i) {
			if (solve(N, i)) {
				yes = true;
				break;
			}
		}
		cout << yes << "\n";
	}
	return 0;
}
