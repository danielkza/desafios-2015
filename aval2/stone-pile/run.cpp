#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

template <typename T>
void add_sums(T start, T end, std::set<int> &sums) {
    auto cur = start;
    static std::vector<int> to_add;

    while(cur != end) {
        to_add.clear();

        for(int sum : sums) {
            sum += *cur;
            to_add.push_back(sum);
        }

        for(int sum : to_add)
            sums.insert(sum);

        sums.insert(*cur);
        ++cur;
    }
}

int main(int argc, char **argv) {
    int n;
    std::cin >> n;

    std::vector<int> stones;
    std::set<int> sums;
  
    for(int i = 0; i < n; ++i) {
        int stone;
        std::cin >> stone;
        stones.push_back(stone);
    }

    std::sort(stones.begin(), stones.end());

    add_sums(stones.begin(), stones.end(), sums);
    //for(int sum : sums)
    //    std::cout << sum << std::endl;

    int max = *sums.rbegin();
    int max_h = max / 2;
    int min_diff = INT_MAX, best_sum;

    for(auto it = sums.rbegin(); it != sums.rend(); ++it) {
        int sum = *it;
        if(sum < max_h)
            break;

        int diff = sum - max_h;
        if(diff < min_diff) {
            min_diff = diff;
            best_sum = sum;
        }
    }

    std::cout << abs(max - 2 * best_sum) << std::endl;
}
