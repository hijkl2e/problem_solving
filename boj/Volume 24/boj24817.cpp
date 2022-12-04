#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, P{}, M{};
	cin >> N >> P >> M;
	while (N--) {
		string s;
		cin >> s;
	}
	map<string, int> A;
	vector<string> B;
	while (M--) {
		string s;
		int x{};
		cin >> s >> x;
		int &val = A[s];
		if (val < P && val + x >= P) {
			B.push_back(s);
		}
		val += x;
	}
	if (B.empty()) {
		cout << "No winner!\n";
	} else {
		for (auto &s : B) {
			cout << s << " wins!\n";
		}
	}
	return 0;
}
