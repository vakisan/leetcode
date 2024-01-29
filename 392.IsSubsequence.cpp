#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j{0};
        for(int i{0}; j<s.size() && i<t.size(); i++){
            if(t[i] == s[j]){
                j++;
            }
        }
        return j == s.size();
    }
};

int main(){
    Solution s;
    string t1{"abc"}, t2{"ahbgdc"};
    cout << s.isSubsequence(t1,t2);
}