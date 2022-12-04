#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, string &S) {
	int cnt{};
	for (int i = 0; i < 3; ++i) {
		for (int j = A[i]; j < A[i + 1]; ++j) {
			if (S[j] == 'A' + i) {
				++cnt;
			}
		}
	}
	int ret = cnt;
	for (int i = 0; i < A[3] - 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (S[i + A[j]] == 'A' + j) {
				--cnt;
			}
			if (S[i + A[j + 1]] == 'A' + j) {
				++cnt;
			}
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(4);
	for (int i = 0; i < N; ++i) {
		++A[S[i] - 'A' + 1];
	}
	for (int i = 1; i < 4; ++i) {
		A[i] += A[i - 1];
	}
	S = S + S.substr(0, N - 1);
	string T = S;
	reverse(T.begin(), T.end());
	int ans = N - max(solve(A, S), solve(A, T));
	cout << ans << "\n";
	return 0;
}
