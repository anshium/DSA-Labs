#include "defs.h"

//helper functions

int comparator1(const void *a, const void *b) {
    DataPtr da = (DataPtr) a;
    DataPtr db = (DataPtr) b;
    return (da->a - db->a);//asc
    // return (db->a - da->a);//desc
}

// function to print the list
void printList(DataPtr list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, %f, %s\n", list[i].a, list[i].b, list[i].c);
    }
}

void heapify(Data a[],int i,int n)
{
	int w = i*2 + 1; 
	while( w < n ) 
    {
		if ( w+1 < n )
			if ( a[w+1].a > a[w].a ) 
                w++;
		if ( a[i].a >= a[w].a ) 
            return;
		Data temp=a[i];
        a[i]=a[w];
        a[w]=temp;		
		i = w; 
		w =i*2+1; 
	}
}

void swap(Data* a, int i, int j){
	int temp = a[i].a;
	a[i].a = a[j].a;
	a[j].a = temp;
	return;
}

// Sorting Algorithms

void InsertionSort(Data a[],int n)
{
    // Your code goes here
    for(int i = 0; i < n; i++){
    	int current = a[i].a;
		int j = i - 1;
    	while(j >= 0 && a[j].a > current){
    		a[j + 1] = a[j];
    		j --;
    	}
    	a[j] = a[i];
    }
}

void BubbleSort(Data a[],int n)
{
    // Your code goes here
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n - 1; j++){
    		if(a[j].a > a[j + 1].a){
    			swap(a, j, j + 1);
    		}
    	}	
    }
}

void SelectionSort(Data a[],int n)
{
    // Your code goes here
    // find the minimum
    char* min = a[0].c;
    int min_index = 0;
    for(int p = 0; p < n; p++){
	    for(int i = p ; i < n; i++){
	    	if(a[i].c < min){
	    		min = a[i].c;
	    		min_index = i;
	    	}
	    }
	    swap(a, p, min_index);
    }
}

/*void MergeSort(Data a[],int l,int r)
{	
	if(l - r <= 0)
		return;
    // Your code goes here
    int mid = (l + r) / 2;
    MergeSort(a, l, mid);
    MergeSort(a, mid, r);
    Data b[l + r];
    int c = 0;
    while(c < l + r){
    	int k1 = l;
    	int k2 = mid;
    	if(k1 >= mid){
    		b[c++] = a[k2++];
    	}
		
		if(k2 >= l + r){
			b[c++] = a[k1++];
		}
		    	
		if(a[k1].a < a[k2].a){
			b[c++] = a[k1++]; 
		}
		
		if(a[k1].a > a[k2].a){
			b[c++] = a[k2++]; 
		}
    }
    a = b;
}*/

// In this fn, I have the assumption that the start and end provided won't let a seg fault happen, that is the indices would be less than the length of the string.

// Also that the size of source is end - start + 1.

// end is included
void copyArray(Data source[], Data destination[], int start, int end){
	for(int i = start; i < end; i++){
		destination[i - start] = source[i];
	}
}

void mergeTheTwo(Data mergeto[], Data array1[], Data array2[], int l, int r){
	int c = 0;
	int k1 = l;
	int mid = l + (r - l) / 2;
	int k2 = mid + 1;
	while(c != l + r){
		if(k1 > mid){
			mergeto[c++] = array2[k2];
		}
		
		if(k2 > r){
			mergeto[c++] = array1[k1];
		}
		
		if(array1[k1].a >= array2[k2].a){
			mergeto[c++] = array1[k1++];
		}
		if(array2[k2].a > array1[k1].a){
			mergeto[c++] = array2[k2++];
		}
	}
}

void MergeSort(Data a[], int l, int r){
	// compute mid
	int mid = l + (r - l) / 2;
	
	// make two small arrays of size mid - l and r - mid
	Data left[mid - l];
	Data right[r - mid];
	
	// Copy the neccessary items from a to the small arrays
	copyArray(a, left, l, mid);
	copyArray(a, right, mid + 1, r);
	
	// Apply merge sort on both the arrays and merge them.
	MergeSort(left, l, mid);
	MergeSort(right, mid + 1, r);
	
	mergeTheTwo(a, left, right, l, r);
}


void HeapSort(Data a[], int n)
{
    // Your code goes here
    
}
