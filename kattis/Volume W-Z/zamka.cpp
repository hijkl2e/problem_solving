#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, D{}, X{};
	cin >> L >> D >> X;
	int N = 1e9, M{};
	for (int i = L; i <= D; ++i) {
		string s = to_string(i);
		if (accumulate(s.begin(), s.end(), 0) - s.size() * '0' == X) {
			N = min(N, i);
			M = i;
		}
	}
	cout << N << "\n" << M << "\n";
	return 0;
}
