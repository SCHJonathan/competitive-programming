// BEGIN SUBMIT

#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int> 

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef JONATHAN_DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int RANGE = 1e9+7;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<vector<int>> visited;
        pair<int, vector<int>> pr;
        int m = mat.size(), n = mat[0].size(), currSum =0;
        vector<int> v(m, 0);
        for(int i = 0; i < m; i++)
            currSum += mat[i][0];
        pr = {currSum, v};

        visited.insert(v);
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push(pr);


        while(k) {
            auto [sum, vec] = pq.top();
            pq.pop();
            currSum=sum;
            for(int i = 0; i < m; i++) {
                int rowidx = i;
                int colidx = vec[i];
                if(colidx < n - 1) {
                    vec[i]++;
                    if(!visited.count(vec)){
                        pq.push({sum-mat[rowidx][colidx]+mat[rowidx][colidx+1],vec});
                        visited.insert(vec);
                    }
                    vec[i]--;
                }
            }
            k--;
        }
        return currSum;
    }
};


// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 5;
    int _ret_ans = 7;
    int _ret = _sol.kthSmallest(mat, k);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    int k = 9;
    int _ret_ans = 17;
    int _ret = _sol.kthSmallest(mat, k);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> mat = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    int k = 7;
    int _ret_ans = 9;
    int _ret = _sol.kthSmallest(mat, k);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


void test_example_3(Solution &_sol) {
    vector<vector<int>> mat = {{1, 1, 10}, {2, 2, 9}};
    int k = 7;
    int _ret_ans = 12;
    int _ret = _sol.kthSmallest(mat, k);
    debug("Expected: ", _ret_ans, "My Answer: ", _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
    test_example_3(_sol);
}
