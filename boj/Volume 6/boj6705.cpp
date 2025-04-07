#include <bits/stdc++.h>

using namespace std;

vector<int> A(10);

void solve(int x) {
	while (x) {
		++A[x % 10];
		x /= 10;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string rn, s;
		getline(cin, rn);
		int N{};
		cin >> N >> s;
		fill(A.begin(), A.end(), 0);
		int cnt{};
		while (cnt < N) {
			cin >> s;
			if (s == "+") {
				int a{}, b{}, c{};
				cin >> a >> b >> c;
				for (int i = a; i <= b; i += c) {
					solve(i);
				}
				cnt += (b - a) / c + 1;
			} else {
				solve(stoi(s));
				++cnt;
			}
		}
		cin.ignore();
		cout << rn << "\n";
		cout << N << " address" << (N == 1 ? "" : "es") << "\n";
		for (int i = 0; i < 10; ++i) {
			cout << "Make " << A[i] << " digit " << i << "\n";
		}
		int total = accumulate(A.begin(), A.end(), 0);
		cout << "In total " << total << " digit" << (total == 1 ? "" : "s") << "\n";
	}
	return 0;
}
