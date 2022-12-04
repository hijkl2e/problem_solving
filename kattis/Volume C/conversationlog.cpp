#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	map<string, map<string, int>> A;
	while (N--) {
		string s;
		getline(cin, s);
		istringstream iss(s);
		string name;
		iss >> name;
		while (iss >> s) {
			++A[name][s];
		}
	}
	vector<is> B;
	for (auto &p : A.begin()->second) {
		int sum{};
		for (auto &q : A) {
			auto it = q.second.find(p.first);
			if (it == q.second.end()) {
				sum = 0;
				break;
			}
			sum += it->second;
		}
		if (sum) {
			B.push_back({-sum, p.first});
		}
	}
	sort(B.begin(), B.end());
	if (B.empty()) {
		cout << "ALL CLEAR\n";
	} else {
		for (auto &p : B) {
			cout << p.second << "\n";
		}
	}
	return 0;
}
