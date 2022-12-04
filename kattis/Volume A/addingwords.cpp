#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> s2i;
	map<int, string> i2s;
	string s;
	while (getline(cin, s)) {
		istringstream iss(s);
		vector<string> A;
		while (iss >> s) {
			A.push_back(s);
		}
		if (A[0] == "clear") {
			s2i.clear();
			i2s.clear();
			continue;
		}
		if (A[0] == "def") {
			auto it = s2i.find(A[1]);
			int x = stoi(A[2]);
			if (it == s2i.end()) {
				s2i[A[1]] = x;
			} else {
				i2s.erase(it->second);
				it->second = x;
			}
			i2s[x] = A[1];
			continue;
		}
		int res{};
		for (int i = 1; i < A.size(); i += 2) {
			auto it = s2i.find(A[i]);
			if (it == s2i.end()) {
				res = INF;
				break;
			}
			res += (i == 1 || A[i - 1] == "+" ? 1 : -1) * it->second;
		}
		for (int i = 1; i < A.size(); ++i) {
			cout << A[i] << " ";
		}
		auto it = i2s.find(res);
		if (it == i2s.end()) {
			cout << "unknown\n";
		} else {
			cout << it->second << "\n";
		}
	}
	return 0;
}
