#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, string> A;
	while (N--) {
		string s1;
		cin >> s1;
		string s2 = s1;
		if (s2.size() > 3) {
			sort(s2.begin() + 1, s2.end() - 1);
		}
		A[s2] = s1;
	}
	int M{};
	cin >> M;
	for (int i = 0; i < M; ++i) {
		string s;
		cin >> s;
		if (s.size() > 3) {
			sort(s.begin() + 1, s.end() - 1);
		}
		cout << A[s] << (i == M - 1 ? "\n" : " ");
	}
	return 0;
}
