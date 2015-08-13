#include <iostream>
#include <algorithm>

#include <map>
#include <vector>

#include <cmath>
#include <cstdint>

template class std::vector<int>;
template class std::map<int, long>;

bool is_prime(long n) 
{
    long d = 2;
    for(;;) {
        ldiv_t quot = ldiv(n, d);
        if(quot.quot < d)
            return true;
        if(quot.rem == 0)
            return false;

        d++;
    }
}

long next_prime(long n) {
    if(n == 2)
        return 3;
    
    do {
        n += 2;
    } while(!is_prime(n));

    return n;
}

int main(int argc, char **argv)
{
    int num_primes;
    std::cin >> num_primes;

    std::vector<int> prime_orders;

    for(int i = 0; i < num_primes; i++) {
        int prime_order;
        std::cin >> prime_order;

        prime_orders.push_back(prime_order);
    }

    std::vector<int> sorted_orders(prime_orders);
    std::sort(sorted_orders.begin(), sorted_orders.end());

    std::map<int, long> primes;

    for(int order : sorted_orders) {
        int cur_order = 1;
        uint64_t start = 2;

        if(!primes.empty()) {
            auto prev_prime_pos = primes.lower_bound(order);
                        
            if (prev_prime_pos != primes.end()) {
                if(prev_prime_pos->second != order) {
                    if (prev_prime_pos == primes.begin())
                        goto start;
                }
            }

            prev_prime_pos--;
            cur_order = prev_prime_pos->first;
            start = prev_prime_pos->second;
        }
start:
        uint64_t value = start;
        for(; cur_order < order; cur_order++) {
            value = next_prime(value);
        }

        primes.insert(primes.end(), std::pair<int, long>(cur_order, value));
    }

    for(int order : prime_orders) {
        std::cout << primes.find(order)->second << std::endl;
    }

    return 0;
}
