#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		A[i] = A[i - 1] + (S[i - 1] == 'S');
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		while (A[p] < i && p + i - A[p] <= N) {
			p += i - A[p];
			++B[i];
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << B[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
