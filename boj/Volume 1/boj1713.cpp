#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(101);
	vector<int> B(101);
	set<iii> S;
	for (int i = 0; i < M; ++i) {
		int x{};
		cin >> x;
		if (A[x]) {
			auto it = S.find({A[x], B[x], x});
			S.erase(it);
			S.insert({++A[x], B[x], x});
			continue;
		}
		if (S.size() == N) {
			auto it = S.begin();
			int y = get<2>(*it);
			A[y] = 0;
			S.erase(it);
		}
		S.insert({++A[x], B[x] = i, x});
	}
	vector<int> C;
	for (auto &[a, b, c] : S) {
		C.push_back(c);
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	for (int i = 0; i < C.size(); ++i) {
		cout << C[i] << (i == C.size() - 1 ? "\n" : " ");
	}
	return 0;
}
