#include <iostream>
#include <algorithm>

#include <map>
#include <vector>

#include <cmath>
#include <cstdint>

struct {
    unsigned int start;
    unsigned int end;
    bool white;
} paint;



int main(int argc, char **argv)
{
    int num_paints;
    std::cin >> num_paints;

    std::vector<std::pair<int, int>> black_zones;

    for(int i = 0; i < num_paints; i++) {
        struct paint p;
        std::cin >> p.start;
        std::cin >> p.end;

        char color;
        std::cin >> color;

        if(color == 'w')
            p.white = true;
        else if(color == 'b')
            p.white = false;
        else
            abort();

        auto 



        paints.push_back(p);
    }


    for(int order : prime_orders) {
        std::cout << primes.find(order)->second << std::endl;
    }

    return 0;
}
