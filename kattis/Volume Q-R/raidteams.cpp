#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<string> A;

bool raid_sort(ii &p1, ii &p2) {
	return p1.first > p2.first || (p1.first == p2.first && A[p1.second] < A[p2.second]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	vector<vector<ii>> B(3, vector<ii>(N));
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		for (int j = 0; j < 3; ++j) {
			cin >> B[j][i].first;
			B[j][i].second = i;
		}
	}
	for (int i = 0; i < 3; ++i) {
		sort(B[i].begin(), B[i].end(), raid_sort);
	}
	vector<string> ans(3);
	vector<int> idx(3);
	deque<bool> chk(N);
	for (int i = 0; i < N / 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			while (chk[B[j][idx[j]].second]) {
				++idx[j];
			}
			chk[B[j][idx[j]].second] = true;
			ans[j] = A[B[j][idx[j]].second];
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < 3; ++i) {
			cout << ans[i] << (i == 2 ? "\n" : " ");
		}
	}
	return 0;
}
