#include <iostream>

int main(int argc, char **argv)
{
    int num_cases;
    std::cin >> num_cases;

    for(int i = 0; i < num_cases; i++) {
        int num_farmers;
        std::cin >> num_farmers;

        int total = 0;
        for(int j = 0; j < num_farmers; j++) {
             int size, animals, eco_idx;
             std::cin >> size;
             std::cin >> animals;
             std::cin >> eco_idx;

             total += size * eco_idx;
        }
        std::cout << total << std::endl;
    }
}
