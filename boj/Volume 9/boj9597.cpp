#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	queue<vector<string>> q;
	vector<string> A;
	map<string, int> freq;
	set<is> S;
	string str;
	while (cin >> str) {
		if (str == "<text>") {
			A.clear();
		} else if (str == "</text>") {
			if (q.size() == 7) {
				for (auto &s : q.front()) {
					int &val = freq[s];
					S.erase({-val, s});
					if (--val) {
						S.insert({-val, s});
					}
				}
				q.pop();
			}
			for (auto &s : A) {
				int &val = freq[s];
				if (val) {
					S.erase({-val, s});
				}
				S.insert({-++val, s});
			}
			q.push(A);
		} else if (str == "<top") {
			int top{};
			cin >> top >> str;
			cout << "<top " << top << ">\n";
			auto end = S.begin();
			int val{};
			while (top--) {
				val = end->first;
				++end;
			}
			while (end != S.end() && val == end->first) {
				++end;
			}
			for (auto it = S.begin(); it != end; ++it) {
				cout << it->second << " " << -it->first << "\n";
			}
			cout << "</top>\n";
		} else {
			if (str.size() >= 4) {
				A.push_back(str);
			}
		}
	}
	return 0;
}
