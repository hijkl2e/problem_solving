#include <bits/stdc++.h>

using namespace std;

string S;
vector<int> A;
deque<bool> B;

bool solve(int i) {
	if (i == S.size()) {
		return true;
	}
	int x{};
	for (int j = 0; j < 2 && i + j < S.size(); ++j) {
		x = 10 * x + S[i + j] - '0';
		if (x >= B.size() || B[x]) {
			continue;
		}
		B[x] = true;
		A.push_back(x);
		if (solve(i + j + 1)) {
			return true;
		}
		A.pop_back();
		B[x] = false;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getline(cin, S);
	int N{}, len{};
	while (len < S.size()) {
		len += ++N < 10 ? 1 : 2;
	}
	B.resize(N + 1);
	solve(0);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
