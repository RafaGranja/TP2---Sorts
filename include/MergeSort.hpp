#pragma once
#include <iostream>
#include "Vetor.hpp"


using namespace std;

class MergeSort : public Vetor{

    public:
        // Merges two subarrays ofelements[].
        // First subarray is arr[begin..mid]
        // Second subarray is arr[mid+1..end]
        void merge(int const left, int const mid,
                int const right)
        {
            auto const subArrayOne = mid - left + 1;
            auto const subArrayTwo = right - mid;
        
            // Create tempelementss
            auto *leftArray = new int[subArrayOne],
                *rightArray = new int[subArrayTwo];
        
            // Copy data to tempelementss leftArray[] and rightArray[]
            for (auto i = 0; i < subArrayOne; i++)
                leftArray[i] = elements[left + i];
            for (auto j = 0; j < subArrayTwo; j++)
                rightArray[j] = elements[mid + 1 + j];
        
            auto indexOfSubArrayOne
                = 0, // Initial index of first sub-array
                indexOfSubArrayTwo
                = 0; // Initial index of second sub-array
            int indexOfMergedArray
                = left; // Initial index of mergedelements
        
            // Merge the tempelementss back intoelements[left..right]
            stats->comparar();
            while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
                stats->comparar();

                stats->comparar();
                if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {

                    elements[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                    indexOfSubArrayOne++;

                }
                else {

                    elements[indexOfMergedArray]= rightArray[indexOfSubArrayTwo];
                    indexOfSubArrayTwo++;

                }
                indexOfMergedArray++;
            }
            // Copy the remaining elements of
            // left[], if there are any
            stats->comparar();
            while (indexOfSubArrayOne < subArrayOne) {

                stats->comparar();
                elements[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
                indexOfMergedArray++;

            }
            // Copy the remaining elements of
            // right[], if there are any
            stats->comparar();
            while (indexOfSubArrayTwo < subArrayTwo) {

                stats->comparar();
                elements[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
                indexOfMergedArray++;
            }
            delete[] leftArray;
            delete[] rightArray;
        }
        
        // begin is for left index and end is
        // right index of the sub-array
        // of arr to be sorted */
        void mergeSort( int const begin, int const end)
        {
            stats->comparar();
            if (begin >= end)
                return; // Returns recursively
        
            auto mid = begin + (end - begin) / 2;
            mergeSort(begin, mid);
            mergeSort(mid + 1, end);
            merge(begin, mid, end);
        }

        void Sort (char* saida)
        {    

            if(size <= 1) return;

            mergeSort(0, size);
            snapshot(saida);

        }

        MergeSort(int _tam, int seed){
            fill(_tam,seed,"MergeSort");
        }

        MergeSort(){}

};