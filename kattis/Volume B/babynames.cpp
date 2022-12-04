#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ost = tree<string, null_type, less<string>, rb_tree_tag,
			tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ost> tree(2);
	int q{};
	while (cin >> q, q) {
		if (q == 1) {
			string s;
			int g{};
			cin >> s >> g;
			tree[g - 1].insert(s);
		} else if (q == 2) {
			string s;
			cin >> s;
			for (int i = 0; i < 2; ++i) {
				tree[i].erase(s);
			}
		} else {
			string s1, s2;
			int g{};
			cin >> s1 >> s2 >> g;
			int ans{};
			if (g == 0) {
				for (int i = 0; i < 2; ++i) {
					ans += tree[i].order_of_key(s2) - tree[i].order_of_key(s1);
				}
			} else {
				ans = tree[g - 1].order_of_key(s2) - tree[g - 1].order_of_key(s1);
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
