// BEGIN SUBMIT

#ifdef JONATHAN
#include "_testing.h"
#else
#define debug(x...)
#endif

#define ll long long
#define ull unsigned long long

#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pint pair<int, int>

#define vint vector<int>
#define vll vector<ll>
#define vull vector<ull> 

const int RANGE = 1e9+7;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
    }
};

// END SUBMIT

void test_example_0(Solution &_sol) {
    vector<vector<int>> adjacentPairs = {{2, 1}, {3, 4}, {3, 2}};
    vector<int> _ret_ans = {1, 2, 3, 4};
    vector<int> _ret = _sol.restoreArray(adjacentPairs);
    test("Example - 0", _ret_ans, _ret);
}


void test_example_1(Solution &_sol) {
    vector<vector<int>> adjacentPairs = {{4, -2}, {1, 4}, {-3, 1}};
    vector<int> _ret_ans = {-2, 4, 1, -3};
    vector<int> _ret = _sol.restoreArray(adjacentPairs);
    test("Example - 1", _ret_ans, _ret);
}


void test_example_2(Solution &_sol) {
    vector<vector<int>> adjacentPairs = {{100000, -100000}};
    vector<int> _ret_ans = {100000, -100000};
    vector<int> _ret = _sol.restoreArray(adjacentPairs);
    test("Example - 2", _ret_ans, _ret);
}


int main() {
    Solution _sol;
    test_example_0(_sol);
    test_example_1(_sol);
    test_example_2(_sol);
}
