#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>

using namespace std;

// makes code faster but larger
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

class Solution {
public:
    // Time: O(mn) where m is the number of strings, n the min length of string
    // Space: O(1)
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
          return string();
        auto it = strs.cbegin();
        unsigned long minLength = it->length();
        ++it;
        for_each(it, strs.cend(), 
          [&minLength](const string& elem) { 
            minLength = min(minLength, elem.length()); 
          });
        for (unsigned long i = 0; i < minLength; ++i) {
          char check = strs[0][i];
          for (auto st = it; st < strs.cend(); ++st) {
             if (check != (*st)[i])
              return st->substr(0, i); 
          }
        }
        return strs[0].substr(0, minLength);
    }
};

void test1() {
  Solution S;
  vector<string> v{"flower","flow","flight"};
  cout << "fl? " << S.longestCommonPrefix(v) << endl;
}

void test2() {
  Solution S;
}

void test3() {
  Solution S;
}

int main() {
  test1();
  test2();
  test3();
  cout << "Done!" << endl;
  
  return 0;
}

