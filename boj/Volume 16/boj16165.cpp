#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	map<string, vector<string>> A;
	map<string, string> B;
	while (N--) {
		string s1;
		int x{};
		cin >> s1 >> x;
		vector<string> &v = A[s1];
		while (x--) {
			string s2;
			cin >> s2;
			v.push_back(s2);
			B[s2] = s1;
		}
		sort(v.begin(), v.end());
	}
	while (M--) {
		string S;
		int q{};
		cin >> S >> q;
		if (q) {
			cout << B[S] << "\n";
		} else {
			for (auto &s : A[S]) {
				cout << s << "\n";
			}
		}
	}
	return 0;
}
