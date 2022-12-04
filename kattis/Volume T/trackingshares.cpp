#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C{};
	cin >> C;
	vector<vector<int>> A(C, vector<int>(366));
	deque<bool> vst(366);
	for (int i = 0; i < C; ++i) {
		int K{};
		cin >> K;
		while (K--) {
			int N{}, D{};
			cin >> N >> D;
			A[i][D] = N;
			vst[D] = true;
		}
		for (int j = 1; j < 366; ++j) {
			if (!A[i][j]) {
				A[i][j] = A[i][j - 1];
			}
		}
	}
	vector<int> B;
	for (int i = 1; i < 366; ++i) {
		if (!vst[i]) {
			continue;
		}
		int sum{};
		for (int j = 0; j < C; ++j) {
			sum += A[j][i];
		}
		B.push_back(sum);
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
