#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<string> Q(N);
	for (int i = 0; i < N; ++i) {
		cin >> Q[i];
	}
	int C{};
	cin >> C;
	while (C--) {
		string E;
		cin >> E;
		if (E == "cut") {
			string x, y;
			cin >> x >> y;
			Q.insert(find(Q.begin(), Q.end(), y), x);
		} else {
			string x;
			cin >> x;
			Q.erase(find(Q.begin(), Q.end(), x));
		}
	}
	for (auto &x : Q) {
		cout << x << "\n";
	}
	return 0;
}
