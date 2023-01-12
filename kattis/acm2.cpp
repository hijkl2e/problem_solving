#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, p{};
	cin >> N >> p;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	swap(A[p], A[0]);
	sort(A.begin() + 1, A.end());
	ii ans;
	int x{};
	for (int i = 0; i < N && x + A[i] < 301; ++i) {
		x += A[i];
		++ans.first;
		ans.second += x;
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
