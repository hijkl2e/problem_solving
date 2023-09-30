#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(100001);
	vector<int> B(100001);
	set<ii> S1;
	vector<set<ii>> S2(101);
	while (N--) {
		int p{}, l{}, g{};
		cin >> p >> l >> g;
		A[p] = l;
		B[p] = g;
		S1.insert({l, p});
		S2[g].insert({l, p});
	}
	int M{};
	cin >> M;
	while (M--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			int p{}, l{}, g{};
			cin >> p >> l >> g;
			A[p] = l;
			B[p] = g;
			S1.insert({l, p});
			S2[g].insert({l, p});
			continue;
		} else if (cmd == "solved") {
			int p{};
			cin >> p;
			S1.erase({A[p], p});
			S2[B[p]].erase({A[p], p});
			continue;
		}
		int ans{};
		if (cmd.back() == '3') {
			int x{}, l{};
			cin >> x >> l;
			auto it = S1.lower_bound({l, -1});
			if (x == 1) {
				ans = it == S1.end() ? -1 : it->second;
			} else {
				ans = it == S1.begin() ? -1 : (--it)->second;
			}
		} else if (cmd.back() == '2') {
			int x{};
			cin >> x;
			ans = (x == 1 ? --S1.end() : S1.begin())->second;
		} else {
			int g{}, x{};
			cin >> g >> x;
			ans = (x == 1 ? --S2[g].end() : S2[g].begin())->second;
		}
		cout << ans << "\n";
	}
	return 0;
}
