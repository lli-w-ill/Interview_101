#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::cout;
using std::endl;

int main() {
    std::set<std::pair<std::string, int>> set = {
        {"A", 4}, {"B", 4}, {"C", 1}, {"A", 0}, {"B", 4}
    };
 
    for (auto const &p: set) {
        std::cout << p.first << " " << p.second << '\n';
    }


    return 0;
}
