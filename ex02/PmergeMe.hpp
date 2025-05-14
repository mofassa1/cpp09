#pragma once

#include <bits/stdc++.h>

class PmergeMe
{
    private:
        std::vector< std::pair<int, int> > vacPaired;
        std::deque<std::pair<int, int> > decPaired;  
        template <typename T>
        void merge(T& arr, int start, int mid, int end);
        template <typename T>
        void mergeSort(T& arr, int left, int right);
        
        std::deque<int> sortedElementsdeq;
        std::vector<int> sortedElementsvec;

        int Inputsize;

    public:
        PmergeMe(/* args */);
        PmergeMe(int ac, char **str);
        void sortUsingVector();
        void sortUsingDeque();
        ~PmergeMe();
        void printContainer(int a);
};


template <typename T>
void PmergeMe::merge(T& arr, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;



    T leftHalf(leftSize);
    T rightHalf(rightSize);


    for (int i = 0; i < leftSize; i++) {
        leftHalf[i] = arr[start + i];
    }
    
    for (int j = 0; j < rightSize; j++) {
        rightHalf[j] = arr[mid + 1 + j];
    }


    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = start;


    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftHalf[leftIndex].first <= rightHalf[rightIndex].first) {
            arr[mergeIndex] = leftHalf[leftIndex];
            leftIndex++;
        } else {
            arr[mergeIndex] = rightHalf[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }


    while (leftIndex < leftSize) {
        arr[mergeIndex] = leftHalf[leftIndex];
        leftIndex++;
        mergeIndex++;
    }


    while (rightIndex < rightSize) {
        arr[mergeIndex] = rightHalf[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}


template <typename T> 
void PmergeMe::mergeSort(T& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}