#include <bits/stdc++.h>

using namespace std;

struct story {
	int x1{}, y1{}, x2{}, y2{}, area{};
};

bool overlap(story &s1, story &s2) {
	return s2.x1 < s1.x2 && s1.x1 < s2.x2 && s2.y1 < s1.y2 && s1.y1 < s2.y2;
}

int ans;
vector<story> A;
vector<deque<bool>> G;
vector<int> B, psum;

void solve(int step, int area) {
	if (step == G.size()) {
		ans = max(ans, area);
		return;
	} else if (area + psum[step] <= ans) {
		return;
	}
	bool yes = true;
	for (int x : B) {
		if (G[x][step]) {
			yes = false;
			break;
		}
	}
	if (yes) {
		B.push_back(step);
		solve(step + 1, area + A[step].area);
		B.pop_back();
	}
	solve(step + 1, area);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		A.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].x2 >> A[i].y2 >> A[i].x1 >> A[i].y1;
			A[i].x2 += A[i].x1;
			A[i].y2 += A[i].y1;
			A[i].area = (A[i].x2 - A[i].x1) * (A[i].y2 - A[i].y1);
		}
		sort(A.begin(), A.end(), [](story &s1, story &s2) {
			return s1.x1 + s1.y1 < s2.x1 + s2.y1;
		});
		G.assign(N, deque<bool>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				G[i][j] = G[j][i] = overlap(A[i], A[j]);
			}
		}
		psum.assign(N + 1, 0);
		for (int i = N - 1; i >= 0; --i) {
			psum[i] = psum[i + 1] + A[i].area;
		}
		ans = 0;
		solve(0, 0);
		cout << ans << "\n";
	}
	return 0;
}
