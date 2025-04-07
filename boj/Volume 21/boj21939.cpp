#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(100001);
	set<ii> S;
	while (N--) {
		int p{}, l{};
		cin >> p >> l;
		A[p] = l;
		S.insert({l, p});
	}
	int M{};
	cin >> M;
	while (M--) {
		string cmd;
		cin >> cmd;
		if (cmd == "recommend") {
			int x{};
			cin >> x;
			cout << (x == 1 ? --S.end() : S.begin())->second << "\n";
		} else if (cmd == "add") {
			int p{}, l{};
			cin >> p >> l;
			A[p] = l;
			S.insert({l, p});
		} else {
			int p{};
			cin >> p;
			S.erase({A[p], p});
		}
	}
	return 0;
}
