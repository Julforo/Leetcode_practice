#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//3. Longest substring without repeating characters
//Given a string s, find the length of the longest substring without repeating characters.
//找出给定字符串中不含重复字符的最长字符串的长度
//滑动窗口问题
//
int lengthOfLongestSubstring(char * s){
    int len = 0,max_len=0;
    int offset[128];
    memset(offset,0xff,sizeof(offset));
    int front=0,rear=0;
    for (int i = 0; i < strlen(s); i++)
    {
        //遍历整个字符串，并记录字符出现过的位置
        //如果在子字符串之后出现过该字符的话则更新front位置为出现过的后一个，更新该字母出现的下标
        //s[i] -> s[1] -> b(98) -> offset[98]
        if (offset[s[i]] >= front)
        {
            front = offset[s[i]]+1;
            len = i-front;
            printf("in: front = %d, len = %d, i = %d\n",front,len,i);
        }
        offset[s[i]] = i;//更新offset[字母]出现的下标数
        printf("out: offset[%c]=%d\n",s[i],offset[s[i]]);
        len++;
        if(len > max_len){
            max_len = len;
        }
        printf("out: front = %d, len = %d, i = %d\n",front,len,i);   
    }
    return max_len;
}

int main(){
    char *s = "abcbcade";
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}
