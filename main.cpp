#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

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
          return "";
        string prefix;
        unsigned long minLength = strs[0].length();
        for (const string& s: strs) {
          minLength = min(s.length(), minLength);
        }
        for (unsigned long i = 0; i < minLength; ++i) {
          char check = strs[0].at(i);
            for (const string& s: strs) {
              if (check != s[i]) {
                return s.substr(0, i);
              }
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

