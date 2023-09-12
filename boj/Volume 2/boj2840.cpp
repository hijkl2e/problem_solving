#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	string S(N, '?');
	deque<bool> A(26);
	int p{};
	while (K--) {
		int x{};
		char c{};
		cin >> x >> c;
		p = (p + x) % N;
		if ((S[p] == '?' && !A[c - 'A']) || S[p] == c) {
			S[p] = c;
			A[c - 'A'] = true;
		} else {
			cout << "!\n";
			return 0;
		}
	}
	reverse(S.begin(), S.end());
	rotate(S.begin(), S.begin() + N - p - 1, S.end());
	cout << S << "\n";
	return 0;
}
