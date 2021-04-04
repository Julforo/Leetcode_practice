#include <stdio.h>
#include <stdlib.h>

//1 two sum
struct object{
    int val;
    int index;
};

//比较函数
static int compare(void *a, void *b){
    return ((struct object *) a)->val - ((struct object *) b)->val;
}

//input an array, the length of array, twovaluesum, foundindex
int * twosum(int *nums, int numsSize, int target, int *returnSize){
    //void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) 排序
    //为nums数组的每个元素分配一个对应的结构体
    struct object *objs = malloc(sizeof(objs)*numsSize);
    //找到的元素数组
    int *results = malloc(sizeof(int)*2);
    int m=0,n= numsSize - 1;

    //初始化查找的结构体数组
    for (int i = 0; i < numsSize; ++i) {
        objs[i].index = i;
        objs[i].val = nums[i];
    }
    //使objs按照value从小到大排序
    qsort(objs,numsSize, sizeof(*objs),compare);
    while (m < n){
        int sum = objs[m].val + objs[n].val;
        //两者从两边往中间靠 但注意m,n序号不是数组元素原有的序号，因为按值升序排列过
        if(sum < target){
            m++;
        } else if (sum > target){
            n--;
        } else{
            //results[0] = (objs[m].index<objs[n].index)?objs[m].index:objs[n].index;
            //results[1] = (objs[m].index<objs[n].index)?objs[n].index:objs[m].index;
            results[0] = objs[m].index;
            results[1] = objs[n].index;
            *returnSize = 2;
            return results;
        }
    }
    return NULL;
}



int main() {

    int numbers[] = {3,2,5,6,1,45,22,43,11,4};
    int target = 33;
    int count = 0;
    int *index = twosum(numbers, sizeof(numbers)/ sizeof(numbers[0]),target,&count);
    if (index != NULL) {
        printf("%d %d\n", index[0], index[1]);
    } else {
        printf("Not found\n");
    }

    return 0;
}
