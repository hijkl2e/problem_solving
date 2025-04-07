#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, char> tab{
		{'.', '.'}, {'O', 'O'}, {'-', '|'}, {'|', '-'}, {'/', '\\'},
		{'\\', '/'}, {'^', '<'}, {'<', 'v'}, {'v', '>'}, {'>', '^'}
	};
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			A[i][j] = tab[A[i][j]];
		}
	}
	for (int j = M - 1; j >= 0; --j) {
		for (int i = 0; i < N; ++i) {
			cout << A[i][j];
		}
		cout << "\n";
	}
	return 0;
}
