#include "sortfuc.h"
#include <iostream>
using namespace std;
/*
int main()
{   
    fileIO myfileIO;
    ifstream inFile("../inputs/1000.wc.in");
    vector <int> myvec = myfileIO.readFile(inFile);
    for (int i = 0; i < myvec.size(); i++) {
	int key =myvec[i];
	int j =i-1;
	while(j>=0&&myvec[j]>key){
	    myvec[j+1] = myvec[j];
	    j--;
	}
	myvec[j+1]=key;
    }
    cout<<"sorted"<<endl;
    for (vector<int>::iterator it = myvec.begin(); it < myvec.end(); it++) {
	cout<<*it<<" ";
    }
	cout<<endl;
}
*/
void sortfuc::insertionSort(vector<int> &v)
{
        for (int i = 0; i < v.size(); i++) {
	int key =v[i];
	int j =i-1;
	while(j>=0&&v[j]>key){
	    v[j+1] = v[j];
	    j--;
	}
	v[j+1]=key;
    }
}

void sortfuc::mergeSort(vector<int> &v)
{
    mergeSortStart(v,0,v.size()-1);
}

void sortfuc::mergeSortStart(vector<int> &v,int min ,int max){
    if((max-min)>=1){
	int p =(min+max)/2;
	int q =p+1;
	mergeSortStart(v,min,p);
	mergeSortStart(v,q,max);
	mergeVec(v,min,p,q,max);
    }
}

void sortfuc::mergeVec(vector<int> &v,int min,int p,int q,int max){
    int ai = min;
    int bi = q;
    vector<int> bufvec;
    while(ai<=p&&bi<=max)
    {
	if(v[ai]<=v[bi]){
	    bufvec.push_back(v[ai++]);
	}
	else{
	    bufvec.push_back(v[bi++]);
	}
    }
    if(ai==q){
	while(bi<=max){
	    bufvec.push_back(v[bi++]);
	}
    }
    else
    {
	while(ai<=p){
	    bufvec.push_back(v[ai++]);
	}
    }
    int j=0;
    for(int i=min;i<=max;i++){
	v[i]=bufvec[j];	
	j++;		 
    }
}

void sortfuc::heapSort(vector<int> &v )
{
    buildHeap(v);
    int i=v.size();
    while(i>=1){
	swap(v,0,i-1);
	i--;
        maxHeapify(v,1,i);
    }
}

void sortfuc::buildHeap(vector<int> &v)
{
    int i=v.size()/2;
    while(i>=1){
        maxHeapify(v,i,v.size());
	i--;
    }
}

void sortfuc::maxHeapify(vector<int> &v,int i,int heap_size)
{
    int	l=i*2;
    int	r=i*2+1;
    int bigone;
    if (l<=heap_size&&v[l-1]>v[i-1]) {
    	bigone=l;
    }
    else bigone=i;
    if (r<=heap_size&&v[r-1]>v[bigone-1]) {
    	bigone=r;
    }
    if(bigone!=i){
	swap(v,i-1,bigone-1);
	maxHeapify(v,bigone,heap_size);
    }
}

void sortfuc::swap(vector<int> &v,int i,int j)
{
    int tmp =v[i];
    v[i]=v[j];
    v[j]=tmp;
}
