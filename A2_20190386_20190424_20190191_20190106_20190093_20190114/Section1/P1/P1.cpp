#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <time.h>
using namespace std;
using namespace std::chrono;

void print_arr(int nums[], int length){
    for(int i = 0; i < length; i++){
        cout << nums[i] << " ";
    }
    cout << endl<<endl;
}

void merge(int nums[], int start, int mid, int end) {
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int* left = new int[leftLength];
    int* right = new int[rightLength];

    for(int i = 0; i < leftLength; i++){
        left[i] = nums[start + i];
    }

    for(int j = 0; j < rightLength; j++){
        right[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while(i < leftLength && j < rightLength){
        if(left[i] < right[j]){
            nums[k] = left[i];
            i++;
        }else{
            nums[k] = right[j];
            j++;
        }
        
        k++;
    }

    while(i < leftLength){
        nums[k] = left[i];
        i++;
        k++;
    }

    while(j < rightLength){
        nums[k] = right[j];
        j++;
        k++;
    }

}

void mergeSort(int nums[], int start, int end) {
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

void mergeSort(int nums[], int length) {
    mergeSort(nums, 0, length - 1);
    cout << "Sorted By Merge Sort: ";
    print_arr(nums, length);
}

int partitionMiddle(int nums[], int start, int end, int pivot){
    while(start <= end){
        while(nums[start] < pivot){
            start++;
        }

        while(nums[end] > pivot){
            end--;
        }
        
        if(start <= end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    //The right spliting (Pivot in place) position of the array
    return start;
}

void quickSortMiddlePivot(int nums[], int start, int end){
    if(start < end){
        int pivot = nums[(start + end) / 2];
        
        int pivotInRightPlaceIndex = partitionMiddle(nums, start, end, pivot);
        
        quickSortMiddlePivot(nums, start, pivotInRightPlaceIndex - 1);
        quickSortMiddlePivot(nums, pivotInRightPlaceIndex, end);

    }
}

void quickSortMiddlePivot(int nums[], int length) {
    quickSortMiddlePivot(nums, 0, length - 1);
    cout << "Sorted By Quick Sort: ";
    print_arr(nums, length);
}




int partitionEnd(int nums[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = nums[high];
  
  // pointer for greater element
  int i = low;

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (nums[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      
      // swap element at i with element at j
      swap(nums[i], nums[j]);
      i++;
    }
  }
  
  // swap pivot with the greater element at i
  swap(nums[i], nums[high]);
  
  // return the partition point
  return i;
}

void quickSortEndPivot(int nums[], int start, int end){
    if(start < end){
        
        int pivotInRightPlaceIndex = partitionEnd(nums, start, end);
        
        quickSortEndPivot(nums, start, pivotInRightPlaceIndex - 1);
        quickSortEndPivot(nums, pivotInRightPlaceIndex + 1, end);

    }
}


void quickSortEndPivot(int nums[], int length) {
    quickSortEndPivot(nums, 0, length - 1);
    cout << "Sorted By Quick Sort: ";
    print_arr(nums, length);
}

// int partitionStart(int nums[], int low, int high) {
    
//   // select the leftmost element as pivot
//   int pivot = nums[low];
  
//   // pointer for greater element
//   int i = low;

//   // traverse each element of the array
//   // compare them with the pivot
//   for (int j = low; j < high; j++) {
//     if (nums[j] <= pivot) {
        
//       // if element smaller than pivot is found
//       // swap it with the greater element pointed by i
      
//       // swap element at i with element at j
//       swap(nums[i], nums[j]);
//       i++;
//     }
//   }
  
//   // swap pivot with the greater element at i
//   swap(nums[i], nums[high]);
  
//   // return the partition point
//   return i;
// }



// void quickSortStartPivot(int nums[], int start, int end){
//     if(start < end){
        
//         int pivotInLeftPlaceIndex = partitionStart(nums, start, end);
        
//         quickSortStartPivot(nums, start, pivotInLeftPlaceIndex - 1);
//         quickSortStartPivot(nums, pivotInLeftPlaceIndex + 1, end);

//     }
// }


// void quickSortStartPivot(int nums[], int length) {
//     quickSortStartPivot(nums, 0, length - 1);
//     cout << "Sorted By Quick Sort: ";
//     print_arr(nums, length);
// }



void randGenerator(int nums[],int length){
    srand(time(0));
    for(int i =0;i<length;i++){ nums[i] = rand();}
}


int main(){
    int t;
    int size;
    cout<<"Number of tests + Number of elements\n";
    cin>>t>>size;
    while(t){
    
    int nums1[size];
    int nums2[size];
    randGenerator(nums1,size);
    for(int i = 0;i<size;i++){
        nums2[i]=nums1[i];
    }
    auto start1 = high_resolution_clock::now();
    mergeSort(nums1,size);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout<<"mergeSort time Taken: " << duration1.count() << " microseconds\n\n";

    auto start2 = high_resolution_clock::now();
    quickSortMiddlePivot(nums2,size);
    auto stop2 = high_resolution_clock::now();
    auto duration2= duration_cast<microseconds>(stop2 - start2);
    cout<<"quickSort time Taken: " << duration2.count()  << " microseconds\n";
    t--;}
    return 0;
}