#include <vector>
#include <queue>
#include <unordered_map>

using std::pair;
using std::vector;
using std::queue;
using std::unordered_map;

/*
// Definition for Employee.
*/
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // 用空间换时间：将 employees 存到一个 map 中
        // key: leader id
        // value: pair<int, vector<int>>
        //        where the first is the importance
        //              the second is subordinate ids
        unordered_map<int, pair<int, vector<int>>> ump;
        for (const Employee *e : employees) {
            ump.insert({e->id, make_pair(e->importance, e->subordinates)});
        }

        int sumImportance = 0;
        
        queue<int> eid;
        eid.push(id);

        // run BFS
        while (!eid.empty()) {
            int frontId = eid.front();
            eid.pop();

            sumImportance += ump[frontId].first;

            // 将所有下属加入到 queue
            for (const int &subid : ump[frontId].second) {
                eid.push(subid);
            }
        }
        
        return sumImportance;
    }
};

// 将 employees vector 存放到一个 map 中，这样就避免了每次都要遍历 employees 去匹配 id
 