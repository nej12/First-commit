//                                BAHIRDAR INSTITUE OF TECHNOLOGY
//                                    FACULTY OF COMPUTING
//                                    DEP'T OF CS



#include <windows.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Divide and conquer solution to find the minimum and maximum number in an array
void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
{
    // if the array contains only one element

    if (low == high) // common comparison
    {
        if (max < nums[low])
        { // comparison 1
            max = nums[low];
        }

        if (min > nums[high])
        { // comparison 2
            min = nums[high];
        }

        return;
    }

    // if the array contains only two elements

    if (high - low == 1) // common comparison
    {
        if (nums[low] < nums[high]) // comparison 1
        {
            if (min > nums[low])
            { // comparison 2
                min = nums[low];
            }

            if (max < nums[high])
            { // comparison 3
                max = nums[high];
            }
        }
        else
        {
            if (min > nums[high])
            { // comparison 2
                min = nums[high];
            }

            if (max < nums[low])
            { // comparison 3
                max = nums[low];
            }
        }
        return;
    }

    // find the middle element
    int mid = (low + high) / 2;

    // recur for the left subarray
    findMinAndMax(nums, low, mid, min, max);

    // recur for the right subarray
    findMinAndMax(nums, mid + 1, high, min, max);
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// heap sort algorithm
void heapify(int arr[], int n, int i)
{
    // Heapify to build max heap
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        /*
        swap=>  int temp=arr[i];
                arr[i]=arr[largest];
                arr[largest]=temp;*/

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // to get highest element at root again
        heapify(arr, i, 0);
    }
}

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to print the array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partition(int array[], int low, int high)
{

    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);

        quickSort(array, pi + 1, high);
    }
}
void exitprogram();
void continueornot();
int main()
{
    int arr[] = {20, 22, 12, 14, 15, 19, 17, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> nums = {20, 22, 12, 14, 15, 19, 17, 16};
    int max = INT_MIN, min = INT_MAX;

    int n = nums.size();
    int x;
    cout << "1. FIND MIN MAX" << endl;
    cout << "2. MERGE SORT" << endl;
    cout << "3. HEAP SORT" << endl;
    cout << "4. QUICK SORT" << endl;
    cin >> x;
    switch (x)
    {
    case 1:

        // initialize the minimum element by INFINITY and the
        // maximum element by -INFINITY
        system("cls");
        findMinAndMax(nums, 0, n - 1, min, max);

        cout << "The minimum array element is " << min << endl;
        cout << "The maximum array element is " << max << endl;
        continueornot();
        break;
    case 2:
        system("cls");
        mergeSort(arr, 0, size - 1);

        cout << "after sorting using mergesort: \n";
        printArray(arr, size);
        continueornot();
        break;
    case 3:
        system("cls");
        heapSort(arr, size);

        cout << "Sorted array using heapsort is \n";
        printArray(arr, size);
        continueornot();
        break;
    case 4:
        system("cls");
        cout << "Unsorted Array: \n";
        printArray(arr, size);

        // perform quicksort on arr
        quickSort(arr, 0, size - 1);

        cout << "after sorting using quick sort: \n";
        printArray(arr, size);
        continueornot();
        break;
    }

    return 0;
}
void exitprogram()
{
    system("cls");
    cout << endl
         << "\t\t\tTHANK YOU FOR VISITING! GOODBYE" << endl
         << "\t\t";
    exit(1);
}
void continueornot()
{
    char a;
manipulate:
    cout << "Continue to sort in another fashion(Go to main menu) (y/n):";
    cin >> a;
    if (a == 'Y' || a == 'y')
        main();
    else if (a == 'N' || a == 'n')
        exitprogram();
    else
    {
        cout << "\t\t\t\tINVALID INPUT PICK EITHER Y OR N" << endl;
        goto manipulate;
    }
}
