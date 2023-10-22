#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi listed;
vb used;

void solve() {
	if (n == listed.size()) {
		for (const auto& x : listed) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (auto i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}

		listed.push_back(i);
		used[i] = true;

		solve();

		listed.pop_back();
		used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	listed.reserve(n);
	used = vb(n + 1, false);
	solve();

	return 0;
}