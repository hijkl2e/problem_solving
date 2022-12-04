#include <bits/stdc++.h>

using namespace std;

vector<string> S;
vector<vector<int>> A;

void print(int x) {
	cout << S[x];
	for (int y : A[x]) {
		print(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	S.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		getline(cin, S[i]);
	}
	A.resize(N + 1);
	int last = 1;
	for (int i = 0; i < N - 1; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A[x].push_back(y);
		last = x;
	}
	print(last);
	cout << "\n";
	return 0;
}
