#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[4]{0, 0, -1, 1};
const int dy[4]{1, -1, 0, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'u', 0}, {'d', 1}, {'l', 2}, {'r', 3}
	};
	int W{}, L{};
	while (cin >> W >> L, W || L) {
		ii R, A;
		int N{};
		cin >> N;
		while (N--) {
			char x{};
			int y{};
			cin >> x >> y;
			int k = d2i[x];
			R = {R.first + y * dx[k], R.second + y * dy[k]};
			A = {A.first + y * dx[k], A.second + y * dy[k]};
			A.first = max(A.first, 0);
			A.first = min(A.first, W - 1);
			A.second = max(A.second, 0);
			A.second = min(A.second, L - 1);
		}
		cout << "Robot thinks " << R.first << " " << R.second << "\n";
		cout << "Actually at " << A.first << " " << A.second << "\n\n";
	}
	return 0;
}
