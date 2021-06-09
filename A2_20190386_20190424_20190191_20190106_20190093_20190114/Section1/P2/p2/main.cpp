#include <iostream>
using namespace std;
int binarySearch(int h,int l,int data,int arr[]){
    int m = (l + h) / 2;
    if(h==l){
        if(data < arr[l])
            return l;
        else
            return (l+1);
    }
    if (data < arr[m])
        return binarySearch(m - 1,l,data,arr);
    if(data==arr[m])
        return m+1;
    return binarySearch(h,m + 1,data,arr);
}
void binaryInsertionSort(int *a, int length)
{
    int i=1, position, j, data;
    while (i < length)
    {
        data = a[i];
        j = i - 1;
        position = binarySearch(j,0, data, a);
        while (j >= position)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = data;
        i++;
    }
}
void insertionSort(int arr[], int size){
    int data;
    for(int i = 1; i < size; i++){
        data = arr[i];
        int j = i;
        while(j >= 1 && arr[j - 1] > data){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = data;
    }
}
int main() {
    int nums[] = {21, 20, 32, 5, 6, 13, 8, 23,55,6,88,100,50,100,56,1,4};
    cout<<"Array Before sorting--> ";
    for (int num : nums) {
        cout<<num<<" ";
    }
    cout<<"\n\n";
    int length = 17;
    binaryInsertionSort(nums, length);
    cout<<"Array After sorting--> ";
    for (int num : nums) {
        cout<<num<<" ";
    }
    cout<<"\n\n";
    return 0;
}
