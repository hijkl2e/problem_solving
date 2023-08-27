#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		cin.ignore();
		string S;
		getline(cin, S);
		if (K % 2 == 0) {
			sort(S.begin(), S.end());
			cout << S << "\n";
			continue;
		}
		string s1, s2;
		for (int i = 0; i < N; ++i) {
			if (i % 2) {
				s2 += S[i];
			} else {
				s1 += S[i];
			}
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		for (int i = 0; i < N; ++i) {
			if (i % 2) {
				S[i] = s2[i / 2];
			} else {
				S[i] = s1[i / 2];
			}
		}
		cout << S << "\n";
	}
	return 0;
}
