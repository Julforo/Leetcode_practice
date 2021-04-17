#include<iostream>
#include<string>
#include<vector>
using namespace std;


//5. Given a string s, return the longest palindromic substring in s.
//返回字符串的最长回文序列
//动态规划
//p(i,j)=1/0
//p(i,j)=p(i+1,j-1) && (s[i]==s[j])
class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.size();
        //用vector为二维数组分配空间 （老费时间and空间了
        //vector< vector<int> > dp(s_len,vector<int>(s_len));
        //用固定长度的二维数组，记得初始化空间 （更费 哭
        int **dp = new int*[s_len];
        string ans;
        int left,right,length;

        for(int i = 0; i < s_len; i++){
            dp[i] = new int[s_len];
            memset(dp[i],0,sizeof(int)*s_len);
        }

        for(length = 0; length < s_len; length++){
            for(left = 0; left+length < s_len; left++){
                right = left + length;
                if(length == 0){
                    dp[left][right]=1;
                }else if(length == 1){
                    dp[left][right] = s[left] == s[right];
                }else{
                    dp[left][right] = dp[left+1][right-1] && (s[left] == s[right]);
                }
                if(dp[left][right]&&length+1>ans.size()){
                    ans = s.substr(left,length+1);
                }
            }
        }
        return ans;
    }
};

int main(){
    string a = "aaba";
    cout << a << endl;
    Solution s;
    cout << s.longestPalindrome(a) << endl;
    return 0;
}
