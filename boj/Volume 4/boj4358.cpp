#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<string, int> freq;
	int cnt{};
	string s;
	while (getline(cin, s)) {
		++freq[s];
		++cnt;
	}
	vector<string> A;
	for (auto &p : freq) {
		A.push_back(p.first);
	}
	sort(A.begin(), A.end());
	cout << fixed << setprecision(4);
	for (auto &s : A) {
		cout << s << " ";
		cout << freq[s] * 100.0 / cnt << "\n";
	}
	return 0;
}
