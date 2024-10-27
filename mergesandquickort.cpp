#include <bits/stdc++.h>
using namespace std;

int partitionFinder(int l, int r, int arr[]) {
    int x = arr[l];
    int i = l;
    int j = r;

    while (true) {
        while (arr[j] > x) j--;
        while (arr[i] < x) i++;
        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            swap(arr[j], arr[l]);
            return j;
        }
        i++, j--;
    }
}

void quicksort(int l, int r, int arr[]) {
    if (l < r) {
        int pivot = partitionFinder(l, r, arr);
        quicksort(l, pivot, arr);
        quicksort(pivot + 1, r, arr);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    int inputSizes[] = {10000, 50000, 80000, 100000};
    for (int size : inputSizes) {
        int arr1[size], arr2[size];
        for (int i = 0; i < size; i++) {
            int num = rand() % 100;
            arr1[i] = num;
            arr2[i] = num;
        }

        clock_t start, end;

        // Time for quicksort
        start = clock();
        quicksort(0, size - 1, arr1);
        end = clock();
        double quicksortTime = (double(end - start) / CLOCKS_PER_SEC) * 1000;

        // Time for merge sort
        start = clock();
        mergeSort(arr2, 0, size - 1);
        end = clock();
        double mergeSortTime = (double(end - start) / CLOCKS_PER_SEC) * 1000;

        // Output results
        cout << "Input Size: " << size << " ----- Merge Sort: " << mergeSortTime << "ms ----- Quick Sort: " << quicksortTime << "ms" << endl;
    }

    return 0;
}
