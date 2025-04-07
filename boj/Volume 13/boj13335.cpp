#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	queue<ii> q;
	int t{};
	for (int i = 0; i < N || q.size(); ++t) {
		if (q.size() && q.front().first == t) {
			K += q.front().second;
			q.pop();
		}
		if (i < N && K >= A[i]) {
			K -= A[i];
			q.push({t + M, A[i++]});
		}
	}
	cout << t << "\n";
	return 0;
}
