#include <bits/stdc++.h>

using namespace std;

void convert(string &s) {
	static deque<bool> A(123);
	fill(A.begin(), A.end(), false);
	for (auto &c : s) {
		if (A[c]) {
			c = '#';
		} else {
			A[c] = true;
		}
	}
	while (s.back() == '#') {
		s.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	unordered_map<string, int> freq;
	while (N--) {
		string s;
		getline(cin, s);
		convert(s);
		++freq[s];
	}
	while (M--) {
		string s;
		getline(cin, s);
		convert(s);
		int ans{};
		for (int i = 0; i < s.size(); ++i) {
			auto it = freq.find(s.substr(0, i + 1));
			if (it != freq.end()) {
				ans += it->second;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
