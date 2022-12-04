#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	map<string, string> A;
	while (N--) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		A[s1] = s2;
	}
	int M{};
	cin >> M;
	cin.ignore();
	map<string, int> B;
	while (M--) {
		string s;
		getline(cin, s);
		++B[s];
	}
	vector<string> C;
	int maxv{};
	for (auto &p : B) {
		if (maxv < p.second) {
			C.clear();
			C.push_back(p.first);
			maxv = p.second;
		} else if (maxv == p.second) {
			C.push_back(p.first);
		}
	}
	if (C.size() == 1) {
		cout << A[C[0]] << "\n";
	} else {
		cout << "tie\n";
	}
	return 0;
}
