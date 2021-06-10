#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>
#include <fstream>
#include <time.h>
using namespace std;
using namespace std::chrono;

void print_arr(int nums[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl
         << endl;
}

void merge(int nums[], int start, int mid, int end)
{
    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    int *left = new int[leftLength];
    int *right = new int[rightLength];

    for (int i = 0; i < leftLength; i++)
    {
        left[i] = nums[start + i];
    }

    for (int j = 0; j < rightLength; j++)
    {
        right[j] = nums[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while (i < leftLength && j < rightLength)
    {
        if (left[i] < right[j])
        {
            nums[k] = left[i];
            i++;
        }
        else
        {
            nums[k] = right[j];
            j++;
        }

        k++;
    }

    while (i < leftLength)
    {
        nums[k] = left[i];
        i++;
        k++;
    }

    while (j < rightLength)
    {
        nums[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int nums[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

void mergeSort(int nums[], int length)
{
    mergeSort(nums, 0, length - 1);
    cout << "Sorted By Merge Sort: ";
}

int partitionMiddle(int nums[], int start, int end, int pivot)
{
    while (start <= end)
    {
        while (nums[start] < pivot)
        {
            start++;
        }

        while (nums[end] > pivot)
        {
            end--;
        }

        if (start <= end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    //The right spliting (Pivot in place) position of the array
    return start;
}

void quickSortMiddlePivot(int nums[], int start, int end)
{
    if (start < end)
    {
        int pivot = nums[(start + end) / 2];

        int pivotInRightPlaceIndex = partitionMiddle(nums, start, end, pivot);

        quickSortMiddlePivot(nums, start, pivotInRightPlaceIndex - 1);
        quickSortMiddlePivot(nums, pivotInRightPlaceIndex, end);
    }
}

void quickSortMiddlePivot(int nums[], int length)
{
    quickSortMiddlePivot(nums, 0, length - 1);
    cout << "Sorted By Quick Sort: ";
}

int partitionEnd(int nums[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = nums[high];

    // pointer for greater element
    int i = low;

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (nums[j] <= pivot)
        {

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

void quickSortEndPivot(int nums[], int start, int end)
{
    if (start < end)
    {

        int pivotInRightPlaceIndex = partitionEnd(nums, start, end);

        quickSortEndPivot(nums, start, pivotInRightPlaceIndex - 1);
        quickSortEndPivot(nums, pivotInRightPlaceIndex + 1, end);
    }
}

void quickSortEndPivot(int nums[], int length)
{
    quickSortEndPivot(nums, 0, length - 1);
    cout << "Sorted By Quick Sort: ";
    print_arr(nums, length);
}

void randGenerator(int nums[], int length)
{
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        nums[i] = rand();
    }
}

int main()
{
    int nums1[5000];
    int nums2[10000];
    int nums3[100000];

    randGenerator(nums1, 5000);
    randGenerator(nums2, 10000);
    randGenerator(nums3, 100000);

    auto start1 = high_resolution_clock::now();
    mergeSort(nums1, 5000);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "mergeSort time Taken: " << duration1.count() << " microseconds\n\n";

    ofstream time("Time.csv");
    time << duration1.count() << ",";

    start1 = high_resolution_clock::now();
    mergeSort(nums2, 10000);
    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "mergeSort time Taken: " << duration1.count() << " microseconds\n\n";
    time << duration1.count() << ",";

    start1 = high_resolution_clock::now();
    mergeSort(nums3, 100000);
    stop1 = high_resolution_clock::now();
    duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "mergeSort time Taken: " << duration1.count() << " microseconds\n\n";

    time << duration1.count() << endl;

    int nums4[5000];

    int nums5[10000];

    int nums6[100000];

    randGenerator(nums4, 5000);
    randGenerator(nums5, 10000);
    randGenerator(nums6, 100000);

    auto start2 = high_resolution_clock::now();
    quickSortMiddlePivot(nums4, 5000);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "quickSort time Taken: " << duration2.count() << " microseconds\n";

    time << duration2.count() << ",";

    auto start3 = high_resolution_clock::now();
    quickSortMiddlePivot(nums5, 10000);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "quickSort time Taken: " << duration3.count() << " microseconds\n";

    time << duration3.count() << ",";

    auto start4 = high_resolution_clock::now();
    quickSortMiddlePivot(nums6, 100000);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "quickSort time Taken: " << duration4.count() << " microseconds\n";

    time << duration4.count() << endl;

    time.close();
    return 0;
}