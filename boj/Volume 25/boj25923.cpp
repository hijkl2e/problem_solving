#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	if ((N & -N) == N || ((N - 1) & -(N - 1)) == N - 1 || K < 4) {
		cout << "-1\n";
		return 0;
	}
	vector<int> A;
	A.push_back(1);
	A.push_back(3);
	for (int i = 2; i <= N; i += 4) {
		A.push_back(i);
	}
	for (int i = N; i >= 4; --i) {
		if (i % 4 == 2) {
			continue;
		}
		if ((i & -i) == i) {
			A.pop_back();
			A.push_back(i);
			A.push_back(i + 1);
		} else {
			A.push_back(i);
		}
	}
	A.push_back(1);
	int len{};
	for (int i = 0; i < N; ++i) {
		len += abs(A[i] - A[i + 1]);
	}
	cout << len << "\n";
	for (int i = 0; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
