#include <iostream>

#include <vector>
#include <map>

#include <algorithm>
#include <utility>

using namespace std;

struct treasure {
    int depth;
    int cost;
    int gold;

    treasure(int depth, int gold, int cost) :
        depth(depth), gold(gold), cost(cost) {}
};

int main(int argc, char **argv)
{
    int max_air, dive_time, n;
    cin >> max_air >> dive_time >> n;

    dive_time *= 3;

    vector<struct treasure> treasures;
    using tr_iter = decltype(treasures)::const_iterator;

    for(int i = 0; i < n; ++i) {
        int depth, gold;
        cin >> depth >> gold;

        treasures.push_back(treasure(depth, gold, depth * dive_time));
    }

    map<tuple<int, int>, pair<int, vector<int>>> memo;

    int i = 1;
    for(auto const &tr : treasures) {
        for(int air = 0; air < max_air; air++) {
            auto excluding = memo.find(make_tuple(i-1, air));
            int excluding_val = (excluding == memo.end() ? 0 : excluding->second.first);
            auto excluding_elms = (excluding == memo.end() ? vector<int>() : excluding->second.second);

            if(tr.depth <= air) {
                auto including = memo.find(make_tuple(i-1, air - tr.depth));
                int including_val = (including == memo.end() ? 0 : including->second.first) + tr.gold;
                auto including_elms = (including == memo.end() ? vector<int>() : including->second.second);

                if(including_val > excluding_val) {
                    auto elms = including_elms;
                    elms.push_back(i);
                    memo.insert(make_tuple(i, air), make_pair(including_val, elms));
                } else {
                    memo.insert(make_tuple(i, air), make_pair(excluding_val, excluding_elms));
                }
            } else {
                memo.insert(make_tuple(i, air), make_pair(excluding_val, excluding_elms));    
            }
        }
        ++i;
    }

    auto picked = *memo.find(i, max_air);
    for(int pick : picked) {
        auto t = treasures[pick-1];
        cout << t.depth << " " << t.gold << endl;
    }

    return 0;
}
