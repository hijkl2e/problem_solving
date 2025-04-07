#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (auto &s : A) {
		if (count(s.begin(), s.end(), 'G') == 4
				&& count(s.begin(), s.end(), 'Y') == 1) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	cout << "ABCDE\n";
	for (auto &s : A) {
		string t = "ABCDE";
		int prev = -1;
		for (int i = 0; i < 5; ++i) {
			if (s[i] == 'G') {
				continue;
			}
			if (prev != -1) {
				swap(t[prev], t[i]);
			}
			prev = i;
		}
		for (int i = 0; i < 5; ++i) {
			if (s[i] == 'B') {
				t[i] = 'F';
			}
		}
		cout << t << "\n";
	}
	return 0;
}
