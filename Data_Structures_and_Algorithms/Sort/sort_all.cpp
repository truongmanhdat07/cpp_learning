#include <iostream>
#include <algorithm>

using namespace std;

// O(n^2)

// sap xep cac phan tu lon nhat ve cuoi mang 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {	// phan tu cuoi cung khong can xep 
    	bool swapped = false;
    	
        for (int j = 0; j < n - 1 - i; j++) {	// bo qua i phan tu lon nhat da day ve cuoi mang
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
				swapped = true; 
            }
        }    
        if(swapped != true)	break;
    }
}


// so sanh truc tiep 2 phan tu lien ke va thuc hien hoan doi
void interchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// tim phan tu nho nhat roi hoan doi voi phan tu dau tien cua doan chua sap xep
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

// chen phan tu vao mang da duoc sap xep dung thu tu
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j] ) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// O(nlog(n)

// mergeSort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0;        // Con tro duyet mang L
    int j = 0;        // Con tro duyet mang R
    int k = left;     // Con tro ghi de vao mang arr

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } 
		else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int mid =(left + right) / 2; 

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int n) {
    if (n <= 1) return;
    mergeSort(arr, 0, n - 1);
}

// quickSort
int partition(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    while(1){
        do{
            ++i;
        }while(a[i] < pivot);
        do{
            --j;
        }while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        }
        else return j;
    }
}

void quicksort(int a[], int l, int r){
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p);
    quicksort(a, p + 1, r);
}

// heapSort
void pushdown(int a[], int i, int n) {
    int maxIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[maxIndex])
        maxIndex = left;
    if (right < n && a[right] > a[maxIndex])
        maxIndex = right;

    if (maxIndex != i) {
        swap(a[i], a[maxIndex]);
        pushdown(a, maxIndex, n); 
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        pushdown(a, i, n);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        pushdown(a, 0, i);
    }
}
