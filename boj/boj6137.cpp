#include <bits/stdc++.h>

using namespace std;

bool compare(string &S, int s, int e) {
	while (s < e) {
		if (S[s] < S[e]) {
			return true;
		} else if (S[s] > S[e]) {
			return false;
		}
		++s, --e;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string S;
	for (int i = 0; i < N; ++i) {
		char c{};
		cin >> c;
		S += c;
	}
	string T;
	int s = 0, e = N - 1;
	while (s <= e) {
		if (compare(S, s, e)) {
			T += S[s++];
		} else {
			T += S[e--];
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i && i % 80 == 0) {
			cout << "\n";
		}
		cout << T[i];
	}
	cout << "\n";
	return 0;
}
