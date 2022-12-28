#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string S;
	cin >> N >> S;
	vector<vector<char>> seq{
		{'A', 'B', 'C'},
		{'B', 'A', 'B', 'C'},
		{'C', 'C', 'A', 'A', 'B', 'B'}
	};
	vector<string> name{"Adrian", "Bruno", "Goran"};
	vector<int> A(3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < N; ++j) {
			if (seq[i][j % seq[i].size()] == S[j]) {
				++A[i];
			}
		}
	}
	int M = max(max(A[0], A[1]), A[2]);
	cout << M << "\n";
	for (int i = 0; i < 3; ++i) {
		if (A[i] == M) {
			cout << name[i] << "\n";
		}
	}
	return 0;
}
