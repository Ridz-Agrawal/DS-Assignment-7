#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

struct Node {
    int sum, i, j;
    bool operator<(const Node &other) const {
        return sum < other.sum;  
    }
};

int main() {
    int A[] = {1, 4, 2, 3};
    int B[] = {2, 5, 1, 6};
    int n = 4;
    int k = 3;

    sort(A, A + n);
    sort(B, B + n);

    priority_queue<Node> pq;
    set<pair<int, int>> used;  

    pq.push({A[n-1] + B[n-1], n-1, n-1});
    used.insert({n-1, n-1});

    int result[100];
    int idx = 0;

    while(k--) {
        Node top = pq.top();
        pq.pop();

        result[idx++] = top.sum;

        int i = top.i;
        int j = top.j;

        if(i - 1 >= 0 && used.count({i-1, j}) == 0) {
            pq.push({A[i-1] + B[j], i-1, j});
            used.insert({i-1, j});
        }

        if(j - 1 >= 0 && used.count({i, j-1}) == 0) {
            pq.push({A[i] + B[j-1], i, j-1});
            used.insert({i, j-1});
        }
    }

    cout << "Top K Maximum Sum Combinations: ";
    for(int i = 0; i < idx; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
