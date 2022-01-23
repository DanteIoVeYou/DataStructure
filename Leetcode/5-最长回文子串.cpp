class Solution {
public:
    bool IsPalindrome(string s) {
        string::iterator begin = s.begin();
        string::iterator end = s.end() - 1;
        while(begin <= end) {
            if(*begin != *end) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ret = "";
        for(int i = 0; i < s.length(); i++) {
            string tmp = "";
            for(int j = i; j < s.length(); j++) {
                tmp += s[j];
                if(IsPalindrome(tmp)) {
                    if(tmp.length() > ret.length()) {
                        ret = tmp;
                    }
                }
            }
        }
        return ret;
    }
};