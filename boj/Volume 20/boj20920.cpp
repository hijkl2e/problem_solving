#include <bits/stdc++.h>

using namespace std;

using iis = tuple<int, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	map<string, int> freq;
	while (N--) {
		string s;
		getline(cin, s);
		if (s.size() >= M) {
			++freq[s];
		}
	}
	vector<iis> A;
	for (auto &p : freq) {
		A.push_back({-p.second, -p.first.size(), p.first});
	}
	sort(A.begin(), A.end());
	for (auto &t : A) {
		cout << get<2>(t) << "\n";
	}
	return 0;
}
