#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	while (cin >> N >> L, N) {
		deque<ii> A(N);
		for (int i = 0; i < N; ++i) {
			char c{};
			cin >> c >> A[i].first;
			A[i].second = (c == 'L' ? -1 : 1) * (i + 1);
		}
		int ans_x{}, ans_y{};
		while (A.size()) {
			for (int i = 0; i < A.size(); ++i) {
				A[i].first += (A[i].second < 0 ? -1 : 1);
			}
			sort(A.begin(), A.end());
			for (int i = 0; i < A.size() - 1; ++i) {
				if (A[i].first == A[i + 1].first) {
					A[i].second *= -1;
					A[i + 1].second *= -1;
				}
			}
			if (A.size() && A.back().first == L) {
				ans_y = A.back().second;
				A.pop_back();
			}
			if (A.size() && A.front().first == 0) {
				ans_y = -A.front().second;
				A.pop_front();
			}
			++ans_x;
		}
		cout << ans_x << " " << ans_y << "\n";
	}
	return 0;
}
