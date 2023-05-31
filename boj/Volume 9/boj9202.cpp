#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int dx[8]{-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8]{-1, 0, 1, 1, 1, 0, -1, -1};
const int dz[9]{0, 0, 0, 1, 1, 2, 3, 5, 11};

struct Trie {
	Trie() {
		memset(next, -1, sizeof next);
	}
	void insert(string &s, int i) {
		if (i == s.size()) {
			++cnt;
			return;
		}
		int j = s[i] - 'A';
		if (next[j] == -1) {
			next[j] = trie_cnt++;
		}
		node[next[j]].insert(s, i + 1);
	}
	int cnt{};
	int next[26]{};
	static int trie_cnt;
	static vector<Trie> node;
};

int Trie::trie_cnt;
vector<Trie> Trie::node;

string A[4];
bool vst[4][4];
int ans;
string s, L;
set<int> S;

void solve(int x, int y, int p) {
	if (p == -1) {
		return;
	}
	vst[x][y] = true;
	Trie &t = Trie::node[p];
	if (t.cnt && S.insert(p).second) {
		if (L.size() < s.size() || (L.size() == s.size() && L > s)) {
			L = s;
		}
		ans += dz[s.size()];
	}
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == -1 || nx == 4 || ny == -1 || ny == 4 || vst[nx][ny]) {
			continue;
		}
		s += A[nx][ny];
		solve(nx, ny, t.next[A[nx][ny] - 'A']);
		s.pop_back();
	}
	vst[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	Trie::trie_cnt = 1;
	Trie::node.resize(2400001);
	Trie &root = Trie::node[0];
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		root.insert(s, 0);
	}
	int T{};
	cin >> T;
	while (T--) {
		getline(cin, A[0]);
		for (int i = 0; i < 4; ++i) {
			getline(cin, A[i]);
		}
		ans = 0;
		L = "";
		S.clear();
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				s = string(1, A[i][j]);
				solve(i, j, root.next[A[i][j] - 'A']);
			}
		}
		cout << ans << " " << L << " " << S.size() << "\n";
	}
	return 0;
}
