#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, string, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(24);
	for (int i = 0; i < 24; ++i) {
		cin >> A[i];
	}
	vector<rec> B;
	string ln, td, e;
	int l{};
	while (cin >> ln >> td >> e >> l) {
		int d = stoi(td.substr(3, 2));
		int h = stoi(td.substr(6, 2));
		int m = stoi(td.substr(9, 2));
		B.push_back({1440 * d + 60 * h + m, ln, e == "enter" ? 1 : -1, l});
	}
	sort(B.begin(), B.end());
	map<string, rec> l2r;
	map<string, int> l2b;
	for (int i = 0; i < B.size(); ++i) {
		auto &[td, ln, e, l] = B[i];
		if (e == 1) {
			l2r[ln] = B[i];
			continue;
		}
		auto it = l2r.find(ln);
		if (it == l2r.end()) {
			continue;
		}
		l2b[ln] += A[get<0>(it->second) / 60 % 24] * abs(l - get<3>(it->second)) + 100;
		l2r.erase(it);
	}
	for (auto &[u, v] : l2b) {
		v += 200;
		cout << u << " $" << v / 100 << "." << setfill('0') << setw(2) << v % 100 << "\n";
	}
	return 0;
}
