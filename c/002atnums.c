#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode *p1 = l1, *p2 = l2;
    struct ListNode *res = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    struct ListNode *pmove = res, *last=NULL,*t=NULL;
    int sum = 0;//sum 计算了对应两位的value，和前一对指针计算的进位 二者的和

    while (1)//循环直到有链表遍历到表尾
    {
        if( p1 && p2 ){
            sum += p1->val + p2->val;
            p1 = p1->next;
            p2 = p2->next;
        }else if (p1 && (p2==NULL))
        {
            sum += p1->val;
            p1 = p1->next;
        }else if ((p1==NULL) && p2)
        {
            sum += p2->val;
            p2 = p2->next;
        }else{
            break;
        }
        //将整除10后的计算结果放入结果链表中
        pmove->val = sum%10;
        //为sum保留进位数，从而留到下一对链表元素的相加
        sum /= 10;

        //分配结果链表的下一个位置空间，并移动pmove的位置
        pmove->next = t = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        last = pmove;//last保留pmove这次循环相加后的链表的最后一个位置，从而让pmove放心移动到下一个元素去
        pmove = pmove->next;
    }
    //跳出循环后，pmove还留在不存在的last的下一个位置，但last位置的相加之和有可能会有进位 因此last之后是否还有取决于sum
    if(sum != 0){
        t->val = sum;
    }else{
        free(t);
        last->next= NULL;
    }

    return res;

}

int main(){
    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    //9->8->3
    p1->val = 9;
    p1->next = p1 + 1;
    p1++;

    p1->val = 8;
    p1->next = p1 + 1;
    p1++;

    p1->val = 3;
    p1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p2 = l2;
    //4->1->8->9->9
    p2->val = 4;
    p2->next = p2 + 1;
    p2++;

    p2->val = 1;
    p2->next = p2 + 1;
    p2++;

    p2->val = 8;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = NULL;

    struct ListNode *p = addTwoNumbers(l1, l2);
    
    /* 983 + 41899 = 302001 */
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
