#include <vector>
#include <queue>

using std::vector;
using std::queue;

/*
// Definition for Employee.
*/
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution_1 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sumImportance = 0;
        
        queue<int> eid;
        eid.push(id);

        // run BFS
        while (!eid.empty()) {
            int frontId = eid.front();
            eid.pop();

            for (const Employee *e : employees) {
                if (e->id == frontId) {
                    sumImportance += e->importance;
                    for (const int &i : e->subordinates) {
                        eid.push(i);
                    }
                }
            }
        }
        
        return sumImportance;
    }
};

// 这个解法的缺点在于：每次都需要遍历 employees，是否能用空间换时间呢？
// 可以，详见 Soln_2 解法
