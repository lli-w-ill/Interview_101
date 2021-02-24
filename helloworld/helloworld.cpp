#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
    std::cout << "hello world" << std::endl;

    vector<char> hello {'h', 'e', 'l', 'l', 'o'};
    vector<vector<char> > hw {
        {'h', 'e', 'l', 'l', 'o'},
        {'w', 'o', 'r', 'l', 'd'}
    };
    for (char c : hello) {
        cout << c;
    }
    cout << endl;
    for (auto vec : hw) {
        for (auto c : vec) {
            cout << c;
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}
