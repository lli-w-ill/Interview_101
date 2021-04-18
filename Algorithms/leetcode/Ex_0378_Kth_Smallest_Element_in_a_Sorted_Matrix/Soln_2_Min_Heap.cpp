#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

class Solution_2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // 方法一定义pq：用自定义的比较
        auto comp = [](Element e1, Element e2) { return e1.val > e2.val; };
        priority_queue<Element, vector<Element>, decltype(comp)> pq (comp);    // 用优先队列表示最小堆

        // 方法二定义pq：在 Element 中重载 operator>，然后用内置的std::greater
        // priority_queue<Element, vector<Element>, std::greater<Element>> pq;

        // 初始化：将 matrix 的第一列加入 pq 作为初始的「最小人候选值」列表
        for (int r = 0; r < n; r++) {
            Element e (matrix[r][0], r, 0);
            pq.push(e);
        }

        // 弹出前 k-1 小的值
        for (int i = 0; i < k-1; i++) {
            Element top = pq.top();
            pq.pop();
            if (top.y != n - 1) {   // 当前 (top.x, top.y) 右边还有数，将它右边的数 push 到队列中
                Element e (matrix[top.x][top.y + 1], top.x, top.y + 1);
                pq.push(e);
            }
        }

        return pq.top().val;
    }

private:
    struct Element {
        int val;
        int x;
        int y;

        Element(int val, int x, int y) : val(val), x(x), y(y) {
        }

        // 方法二定义pq：需要重载 operator>
        bool operator> (const Element &other) const {
            return this->val > other.val;
        }
    };
};

// 用lambda定义comparator并传给priority_queue：https://stackoverflow.com/questions/5807735/c-priority-queue-with-lambda-comparator-error
