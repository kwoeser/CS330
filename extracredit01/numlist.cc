#include "numlist.h"
#include <omp.h>

/*
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
*/

// Partitioning functions
// Serial partition
unsigned int NumList::partition(vector<int>& keys, unsigned int low, 
                                unsigned int high)
{
    // Use the last element as the pivot
    int pivot = keys[high];

 
    unsigned int i = low;
    unsigned int j = low;
    // TODO: Implement the serial partitioning method
    // Do the same job at the same time by several processors     
   
    while (i <= high) {

	   if (keys[i] >  pivot) {
	   	i++;
	   } else {
		swap(keys[i], keys[j]);
		j++;
		i++;
	   }
   }

   return j - 1;
}





using namespace std;
// Parallel partition
unsigned int NumList:: partition_par(vector<int>& keys, unsigned int low,
                                     unsigned int high)
{
     
    // Use the last element as the pivot
    int pivot = keys[high];


    // TODO: Implement the parallel partitioning method
    // There should be two #pragmas to parallelize the loop
    // First loop is calculating the lt and gt arrays
    // Second is when the integers are copied to the correct position (i.e.,
    // left or right side of the pivot

  
   
    // keys.size() // high - low + 1
    vector<int> lt(keys.size(), 0);
    vector<int> gt(keys.size(), 0);
    vector<int> ltSum(keys.size(), 0);
    vector<int> gtSum(keys.size(), 0);

    // Prefix sum output[i] = output[i + 1] + input[i]; i starts at 1

    #pragma omp parallel for schedule(static)
    for (unsigned int i = low; i <= high; i++) {
	
	    if (keys[i] < pivot) {
		lt[i - low] = 1;
	    } else {
		gt[i - low] = 1;
	    }
    }
    
   
    #pragma omp parallel for schedule(static)
    for (unsigned int i = 1; i < lt.size(); i++) {
	ltSum[i] = keys[i + 1] + lt[i];
   	gtSum[i] = keys[i + 1] + gt[i];

    }


    vector<int> A(keys.size(), 0);
    int mid = lt.size() / 2;
    
    for (unsigned int i = 0; i < ltSum.size(); i++) {
	if (lt[i] == 1) {
		A[ltSum[i]] = keys[i];
	} else if (gt[i] == 1){
		A[gtSum[i]] = keys[i];
	}

	
    }

    return pivot;

}

// Actual qsort that recursively calls itself with particular partitioning
// strategy to sort the list
void NumList::qsort(vector<int>& keys, int low, int high, ImplType opt)
{
    if(low < high) {
        unsigned int pi;
        if(opt == serial) {
            pi = partition(keys, low, high);
        } else {
            pi = partition_par(keys, low, high);
        }
        qsort(keys, low, pi - 1, opt);
        qsort(keys, pi + 1, high, opt);
    }
}

// wrapper for calling qsort
void NumList::my_qsort(ImplType opt)
{
    /* Initiate the quick sort from this function */
    qsort(list, 0, list.size() - 1, opt);
}


// Default constructor
// This should "create" an empty list
NumList::NumList() {
    /* do nothing */
    /* you will have an empty vector */
}


// Contructor
// Pass in a vector and the partitioning strategy to use
NumList::NumList(vector<int> in, ImplType opt) {
    list = in;
    my_qsort(opt);
}
// Destructor
NumList::~NumList() {
    /* do nothing */
    /* vector will be cleaned up automatically by its destructor */
}
// Get the element at index
int NumList::get_elem(unsigned int index)
{
    return list[index];
}
// Print the list
void NumList::print(ostream& os)
{
    for(unsigned int i = 0; i < list.size(); i++) {
        os << i << ":\t" << list[i] << endl;
    }
}
