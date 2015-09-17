#include <iostream>
#include <map>
#include <deque>
#include <set>
#include <string>
#include <utility>

using namespace std;

struct buy {
    int amount;
    int id;
};

template <typename Iter> 
void read_products(Iter inserter, int num) {
    string product_name;

    for(int i = 0; i < num; ++i) {
        int amount;
        cin >> amount;
        
        product_name.clear();
        getline(cin, product_name);
        
        auto pos = product_name.find(" of ");
        product_name.replace(pos, 4, "");

        struct buy buy {amount, i};
        *inserter = make_pair(product_name, buy);
    }
}

int main(int argc, char **argv) {
    int num_products, num_buys;

    map<string, struct buy> products;
    cin >> num_products;
    read_products(inserter(products, products.begin()), num_products);

    deque<pair<string, struct buy>> buys;
    cin >> num_buys;
    read_products(back_inserter(buys), num_buys);

    int wait = 0;
    //set<int> waits;

    while(!buys.empty()) {
        wait++;

        auto &prod_buy = buys.front();
        auto &prod = prod_buy.first;
        struct buy &buy = prod_buy.second;

        auto product_pos = products.find(prod);
        if(product_pos == products.end() || product_pos->second.amount == 0) {
            //cerr << "no product for " << buy.id << endl;
            buys.pop_front();
            continue;
        }

        auto &available = product_pos->second.amount;
        if(available < buy.amount) {
            /* auto wait = waits.find(buy.id); 
            if(wait != waits.end()) {
                if(available != buy.amount) {
                    ////cerr << buy.id << " leaving, already waited " << endl;
                    buys.pop_front();
                    continue;
                }
            } */
            if (buys.size() > 1) {
                //cerr << buy.id << " waiting " << endl;
                //waits.insert(buy.id);
                buy.amount = available;

                swap(buys[0], buys[1]);
                continue;
            } else {
                break;
            }
        }

        available -= buy.amount;
        //cerr << buy.id << " bought " << buy.amount << " "
        //     << prod << " " << available << " left" << endl;
        buys.pop_front();
    }

    cout << wait << endl;
    return 0;
}
