#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string s1, s2;
	cin >> N >> s1 >> s2;
	int R{}, S{};
	for (int i = 0; i < N; ++i) {
		if (s1[i] == s2[i]) {
			s1[i] = s2[i] = '#';
			++R;
		}
	}
	for (int i = 0; i < N; ++i) {
		if (s2[i] == '#' || s1.find(s2[i]) == -1) {
			continue;
		}
		s1[s1.find(s2[i])] = '#';
		++S;
	}
	cout << R << " " << S << "\n";
	return 0;
}
