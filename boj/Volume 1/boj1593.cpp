#include <bits/stdc++.h>

using namespace std;

int func(char c) {
	if (isupper(c)) {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<int> A(52);
	vector<int> B(52);
	for (int i = 0; i < N; ++i) {
		++A[func(S[i])];
		++B[func(T[i])];
	}
	int ans = (A == B);
	for (int i = N; i < M; ++i) {
		++B[func(T[i])];
		--B[func(T[i - N])];
		if (A == B) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
