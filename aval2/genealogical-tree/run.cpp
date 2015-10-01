#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <functional>
#include <algorithm>

using namespace std;

struct martian {
    int number;
    set<int> children;
    set<int> parents;
};

vector<struct martian> martians;
list<struct martian> ordered_martians;

void fix_children(struct martian &parent, struct martian &child) {
    if(&parent != &child) {
        parent.children.insert(child.number);
        child.parents.insert(parent.number);
    }

    for(auto child_num : child.children)
        if(child_num != child.number)
            fix_children(parent, martians[child_num - 1]);
}

int main(int argc, char **argv) {
    int n;
    cin >> n;

    martians.resize(n);

    int i = 0;
    for(auto &martian : martians) {
        martian.number = i + 1;

        for(;;) {
            int child;
            cin >> child;
            if(child == 0)
                break;

            martian.children.insert(child);
        }

        ++i;
    }

    for(auto &m : martians)
        fix_children(m, m);

    while(!martians.empty()) {
        struct martian martian = std::move(martians.back());
        martians.pop_back();

        int found_children = 0;
                
        auto it = ordered_martians.rbegin();
        auto last_child_pos = ordered_martians.rend();

        for(; it != ordered_martians.rend(); ++it) {
            if(martian.children.find(it->number) != martian.children.end()) {
                last_child_pos = it;

                if(++found_children == martian.children.size()) {
                    break;
                }
            }

            if(martian.parents.find(it->number) != martian.parents.end())
                break;
        }

        if(last_child_pos != ordered_martians.rend()) {
            it = last_child_pos;
            ++it;
        }

        ordered_martians.insert(it.base(), std::move(martian));
    }

    cout << ordered_martians.front().number;
    ordered_martians.pop_front();

    for(auto &martian : ordered_martians) {
        cout << " " << martian.number;
    }

    cout << endl;
    return 0;
}
