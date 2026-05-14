#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Helper Funcs
int min(int a,int b){
    return (a<b)?a:b;
}
int max(int a,int b){
    return (a<b)?a:b;
}
void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int cmp(const void* a,const void* b){
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1>num2)-(num1<num2);
}
void sortArray(int* arr,int size){
    qsort(arr,size,sizeof(int),cmp);
}
// 1. 
int deciToBin(int deciNum){
    int n = deciNum;
    int rem = 0;
    int pow = 1;
    int ans = 0;
    while (deciNum>0)
    {
        rem = deciNum%2;
        deciNum /= 2;
        ans += rem*pow;
        pow*=10;
    }
    return ans;
}
// 2.
int binToDeci(int binNum){
    int n = binNum;
    int rem = 0;
    int pow = 1;
    int ans = 0;
    while (n>0)
    {
        rem = n%10;
        n /= 10;
        ans += rem*pow;
        pow*=2;
    }
    return ans;
}
//3. 
int isPowOfTwo(int n){
    return n&(n-1)==0;
}
//4. 
int* minMax(int* arr,int size){
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
    }
    int* ans = (int*) calloc(2,sizeof(int));
    ans[0] = min;
    ans[1] = max;
    return ans;
}
//5.
void revArray(int* arr,int size){
    int st = 0;
    int end = size-1;
    while (st<end)
    {
        swap(&arr[st],&arr[end]);
        st++;
        end--;
    }   
}

void printArray(int *arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
//6.
void printAllSubArray(int* arr,int size){
    for (int st = 0; st < size; st++)
    {
        for (int end = st; end < size; end++)
        {
            for (int i = st; i <= end; i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
        
    }
}
//7.
int bruteMaxSubArrSum(int* arr,int size){
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int st = 0; st < size; st++)
    {
        currSum = 0;
        for (int end = st; end < size; end++)
        {
            currSum += arr[end];
            maxSum = max(maxSum,currSum);
        }
    }
    return maxSum; 
}
//8.
int kadanesAlgo(int* arr,int size){
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int i = 0; i < size; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    } // If all elements are negative then in that case maxSum will come out to be 0;
    return maxSum;
}
//9. Pair Sum Brute
int* pairSum(int* arr,int size,int target){
    int* ans = (int*) calloc(2,sizeof(int));
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]+arr[j]==target){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }   
}
//10. Pair Sum optimal
int* oppairSum(int* nums, int size, int target) {
    int* ans = (int*) calloc(2,sizeof(int));
    int n = size;
    int i=0, j = n-1;

    while(i <j) {
        int pairSum = nums[i] + nums[j];
        if(pairSum > target) {
            j --;
        } else if(pairSum < target) {
            i++;
        } else{
            ans[0]=i;
            ans[1]=j;
        }
    }
    return ans;
}
//11. Majority Element : Brute
int majorityElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++; 
            }
        }
        if (count > n / 2) {
            return arr[i]; 
        }
    }
    return -1;  
}
// Majority element better
int mjEle(int* arr,int n){
    sortArray(arr,n);
    int freq = 1;
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]==arr[i-1]){
            freq++;
        }
        else{
            freq = 1;
            ans = arr[i];
        }
        if(freq>n/2){
            return ans;
        }
    }
    return ans;
}
// Majority element Moore's
int moores(int* arr,int n){
    int freq = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if(freq==0){
            ans = arr[i];
        }
        if(ans==arr[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    return ans;
}
// 12. X^n
double power(double x,int n){
    double num = x;
    int binForm = n;
    double ans = 1.0;
    if(binForm<0){
        num = 1/num;
        binForm = -binForm;
    }
    while (binForm>0)
    {
        if(binForm%2==1){
            ans*=num;
        }
        num*=num;
        binForm/=2;
    }
    return ans;
}
// Maximum profit
int maximumProfit(int* prices,int size){
    int bestBuy = prices[0];
    int maxProfit = 0;
}
int main()
{
    //1.
    printf("****************************************************************\n");
    printf("1.\nBinary of 4: %d\n",deciToBin(4));
    printf("****************************************************************\n");
    //2.
    printf("2. \nDecimal of 111: %d\n",binToDeci(111));
    printf("****************************************************************\n");
    //3.
    int arr[6] = {1,2,10,0,5,6};
    int* ans = minMax(arr,6);
    printf("3. \nArray is: \n");
    printArray(arr,6);
    printf("Min: %d, Max: %d\n",ans[0],ans[1]);
    printf("****************************************************************\n");
    //4.
    printf("4. \nBefore reverse array is: \n");
    printArray(arr,6);
    revArray(arr,6);
    printf("After reverse array is: \n");
    printArray(arr,6);
    printf("****************************************************************\n");
    //5. Print all subarrays
    int arr1[3] = {1,2,3};
    printf("5. \nArray is: \n");
    printArray(arr1,3);
    printf("Subarrays are: \n");
    printAllSubArray(arr1,3);
    printf("****************************************************************\n"); 
    //6. Max subarray sum (Brute force and Optimal)
    int arr2[7] = {3,-4,5,4,-1,7,-8};
    printf("6. \nArray is: \n");
    printArray(arr2,7);
    printf("Brute Force: Max subarray Sum: %d\n",bruteMaxSubArrSum(arr2,7));
    printf("Optimal: Max subarray Sum: %d\n",kadanesAlgo(arr2,7));
    printf("****************************************************************\n");
    //7. Pair Sum ()
    int target = 9;
    printf("7. \nArray is: \n");
    int arr3[4] = {2,7,11,15};
    printArray(arr3,4);
    printf("target = %d \n",target);
    int* ans1 = pairSum(arr3,4,target);
    printf("Brute Force: Indices are i = %d, j = %d\n",ans1[0],ans1[1]);
    printf("****************************************************************\n");
    // Optimal pair sum
    int* ans2 = pairSum(arr3,4,target);
    printf("8. \nOptimal: Indices are i = %d, j = %d\n",ans2[0],ans2[1]);
    printf("****************************************************************\n");
    // Brute force maority element
    int arr4[] = {2, 2, 1, 2, 3, 2, 2};
    int majorityEle = majorityElement(arr4,7);
    printf("9. \nArray is: \n");
    printArray(arr4,7);
    printf("Mazority element is: %d\n",majorityEle); 
    printf("****************************************************************\n");
    // Better approach maority element
    int* arr5 = (int*) calloc(7,sizeof(int));
    memcpy(arr5,arr4,7*sizeof(int));
    majorityEle = mjEle(arr5,7);
    printf("10. \nOptimal: Mazority element is: %d\n",majorityEle); 
    printf("****************************************************************\n");
    //Moore's Voting Algo
    printf("11. \nMoore's: Mazority element is: %d\n",moores(arr4,7)); 
    printf("****************************************************************\n");
    //Pow X^n
    printf("12. \n2^3=%lf\n",power(2,3));
    printf("****************************************************************\n");
    //Buy stock and sell
    return 0;
}
