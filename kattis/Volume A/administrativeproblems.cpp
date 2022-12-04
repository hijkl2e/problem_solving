#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<string> A(N + 1);
		vector<int> P(N + 1);
		vector<int> Q(N + 1);
		vector<int> K(N + 1);
		map<string, int> c2i;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i] >> P[i] >> Q[i] >> K[i];
			c2i.insert({A[i], i});
		}
		map<string, int> n2i;
		vector<int> B(M);
		vector<int> D(M);
		deque<bool> chk(M);
		while (M--) {
			int t{};
			string S;
			char e{};
			cin >> t >> S >> e;
			int x = n2i.insert({S, n2i.size()}).first->second;
			if (e == 'p') {
				string C;
				cin >> C;
				chk[x] |= B[x] > 0;
				B[x] = c2i[C];
				D[x] += Q[B[x]];
			} else if (e == 'r') {
				int d{};
				cin >> d;
				chk[x] |= B[x] == 0;
				D[x] += d * K[B[x]];
				B[x] = 0;
			} else {
				int s{};
				cin >> s;
				chk[x] |= B[x] == 0;
				if (s) {
					D[x] += (P[B[x]] * s - 1) / 100 + 1;
				}
			}
		}
		for (int i = 0; i < B.size(); ++i) {
			chk[i] |= B[i] > 0;
		}
		for (auto &p : n2i) {
			cout << p.first << " ";
			if (chk[p.second]) {
				cout << "INCONSISTENT\n";
			} else {
				cout << D[p.second] << "\n";
			}
		}
	}
	return 0;
}
