#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;

const ll N = 1000000000000000000LL;

struct Segment {
  ll l, r; // Half-open interval [l, r)
  ld w;    // Weight of each individual position
};

string read_answer() {
  string s;
  if (!(cin >> s) || s == "-1")
    exit(0);
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<Segment> segments{{0, N, 1}};

  // Reserve the final query for the exact bit comparison.
  for (int q = 0; q < 191; ++q) {
    ld total = 0;
    for (auto s : segments)
      total += (s.r - s.l) * s.w;

    // Find a split closest to half the total weight.
    ld before = 0;
    ll x = 1;

    for (auto s : segments) {
      ld mass = (s.r - s.l) * s.w;

      if (before + mass >= total / 2) {
        ll count = (ll)roundl((total / 2 - before) / s.w);

        count = clamp(count, 0LL, s.r - s.l);
        x = clamp(s.l + count, 1LL, N - 1);
        break;
      }

      before += mass;
    }

    cout << "1 " << x << ' ' << N - 1 << endl;
    bool higher = (read_answer() == "NO");

    vector<Segment> next;

    for (auto s : segments) {
      if (s.l < x && x < s.r) {
        // The query splits this interval.
        next.push_back({s.l, x, s.w * (higher ? 1 : 12)});
        next.push_back({x, s.r, s.w * (higher ? 12 : 1)});
      } else {
        bool consistent = ((s.l >= x) == higher);
        if (consistent)
          s.w *= 12;

        next.push_back(s);
      }
    }

    segments.swap(next);
  }

  // Choose the most likely individual position.
  auto best =
      max_element(segments.begin(), segments.end(),
                  [](const Segment &a, const Segment &b) { return a.w < b.w; });

  ll h = best->l + (best->r - best->l - 1) / 2;

  cout << "2 " << h << endl;
  string winner = read_answer();

  // An unlucky search can select an equal bit.
  if (winner == "EQUAL")
    winner = "MARIO";

  cout << "! " << winner << endl;
}
