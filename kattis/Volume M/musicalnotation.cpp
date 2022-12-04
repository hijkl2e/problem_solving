#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int L{};
	for (auto &s : A) {
		L += s.size() == 1 ? 1 : stoi(s.substr(1));
	}
	vector<string> B(14);
	for (int i = 0; i < 14; ++i) {
		B[i] += i < 7 ? ('G' - i % 7) : ('g' - i % 7);
		B[i] += ": ";
		B[i] += string(L + N - 1, i % 2 == 0 || i == 11 ? ' ' : '-');
	}
	int c = 3;
	for (auto &s : A) {
		int d = s.size() == 1 ? 1 : stoi(s.substr(1));
		int r = isupper(s[0]) ? ('G' - s[0]) : ('g' - s[0] + 7);
		while (d--) {
			B[r][c++] = '*';
		}
		++c;
	}
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
