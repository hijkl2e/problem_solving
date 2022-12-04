#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		map<string, string> n2b, b2s1, b2s2, b2f;
		for (int i = 0; i < N; ++i) {
			string first, last, bib;
			cin >> first >> last >> bib;
			n2b[last + ", " + first] = bib;
		}
		for (int i = 0; i < 3 * N; ++i) {
			string bib, loc, time;
			cin >> bib >> loc >> time;
			if (loc == "S1") {
				b2s1[bib] = time;
			} else if (loc == "S2") {
				b2s2[bib] = time;
			} else {
				b2f[bib] = time;
			}
		}
		cout << "NAME                       BIB    SPLIT1      ";
		cout << "RANK    SPLIT2      RANK    FINISH      RANK\n";
		for (auto &p : n2b) {
			cout << left << setw(20) << p.first;
			cout << right << setw(10) << p.second;
			for (auto &rec : {b2s1, b2s2, b2f}) {
				auto &time = rec.find(p.second)->second;
				cout << setw(10) << time;
				int rank = 1;
				for (auto &q : rec) {
					if (q.second < time) {
						++rank;
					}
				}
				cout << setw(10) << rank;
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
