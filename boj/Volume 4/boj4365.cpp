#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> suit{
		"Clubs", "Diamonds", "Hearts", "Spades"
	};
	vector<string> val{
		"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
	};
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(52));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 52; ++j) {
			cin >> A[i][j];
			--A[i][j];
		}
	}
	vector<int> B(52);
	for (int i = 0; i < 52; ++i) {
		B[i] = i;
	}
	vector<int> C(52);
	int k{};
	for (int tc = 0; cin >> k; ++tc) {
		--k;
		for (int i = 0; i < 52; ++i) {
			C[i] = B[A[k][i]];
		}
		swap(B, C);
		if (tc) {
			cout << "\n";
		}
		for (int x : B) {
			cout << val[x % 13] << " of " << suit[x / 13] << "\n";
		}
	}
	return 0;
}
