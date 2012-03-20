#ifndef SORT_H
#define SORT_H

#include <vector>
using namespace std;
class sortfuc{
    public:
        void insertionSort(vector<int> &v);  
	void mergeSort(vector<int> &v);
	void heapSort(vector<int> &v);
    private:
	void mergeSortStart(vector<int> &v,int min,int max);
	void mergeVec(vector<int> &v,int min,int p,int q,int max);
	void buildHeap(vector<int> &v);
	void maxHeapify(vector<int> &v,int i,int heap_size);
	void swap(vector<int> &v,int i,int j);
};
#endif
