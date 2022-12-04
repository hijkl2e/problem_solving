#include <bits/stdc++.h>

using namespace std;

const int dx[4]{-1, 1, 0, 0};
const int dy[4]{0, 0, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> d2i{
		{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}
	};
	int L{}, W{};
	cin >> L >> W;
	vector<int> O(L);
	vector<int> I(L);
	vector<int> S(L);
	for (int i = 0; i < L; ++i) {
		cin >> O[i] >> I[i] >> S[i];
	}
	int P{};
	string M;
	cin >> P >> M;
	int x = L;
	int y = P;
	bool enter{}, yes = true;
	for (int i = 0; i < M.size(); ++i) {
		char c = M[i];
		x += dx[d2i[c]];
		y += dy[d2i[c]];
		if ((x >= L && enter) || y == -1 || y == W) {
			yes = false;
			break;
		}
		enter |= x < L;
		if (x < 0 || x >= L) {
			continue;
		}
		deque<bool> A(I[x]);
		int ofst = (O[x] + (i + 1) * S[x]) % I[x];
		A[ofst] = true;
		for (int i = 1; i < S[x]; ++i) {
			ofst = (ofst + I[x] - 1) % I[x];
			A[ofst] = true;
		}
		if (A[(x % 2 ? W - y - 1 : y) % I[x]]) {
			yes = false;
			break;
		}
	}
	yes &= x < 0;
	cout << (yes ? "safe" : "squish") << "\n";
	return 0;
}
