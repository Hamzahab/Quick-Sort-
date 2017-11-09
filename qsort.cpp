// This might be easiest to develop as a desktop program, and then move
// it over to an Arduino program once you know it is working.

#include <iostream>

using namespace std;

/* Given an array of length n > 0 and an index 0 <= pi < n, this rearranges
   the array so all items <= a[pi] appear before a[pi] and all items > a[pi]
	 appear after a[pi].

  Returns the index of a[pi] after the rearrangement.
*/

void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

int pivot(int a[], int n, int pi) {
	swap(a[pi],a[n-1]);
	bool alreadychanged = false;
	// for(int i = 0;i < n;i++){
	// 	cout << "Element" << i << ": " << a[i] << endl;
	// }

	int lo = 0, hi = n-2;
	// cout << "lo: "<< lo << endl << "high: "<< hi <<endl;
	// cout <<"lo: " << lo <<endl;
	while(true){
		if((a[hi] > a[n-1]) && !alreadychanged){hi--;alreadychanged = true;}

	  if(a[lo] <= a[n-1] && !alreadychanged){lo++;alreadychanged = true;}

		if((a[hi] < a[n-1]) && (a[lo] >= a[n-1]) && !alreadychanged){
			swap(a[lo],a[hi]);
			lo++;
			alreadychanged = true;
		}

		if(lo > hi){
			swap(a[lo],a[n-1]);
			break;
		}
		alreadychanged = false;
	}
	// cout << "we out" << lo << endl;

	// for(int i = 0;i < n;i++){
	// 	cout << "Element" << i << ": " << a[i] << endl;
	// }
	return lo;
}

/*
	Don't forget to test the pivot operation!

	You don't know exactly where all items will appear after a pivot so it is
	hard to fully automate this test. Here is what you can do. Suppose pivot()
	returns index npi:
	 - check a[i] <= a[npi] for i < npi
	 - check a[i] > a[npi] for i > npi
	 - check that a[npi] (after the pivot) is the same as the
	   value of a[pi] (before the pivot)

	A test that is not fully automatic would be to print the resulting array
	to the screen, so you can at least see visually that the pivot procedure
	worked as expected.
*/

// Sort an array with n elements using Quick Sort
void qsort(int array[], int n) {
	// if n <= 1 do nothing (just return)
	if(n <=1) return;
	// pick a pivot index pi
	int pi = n/2;
	// call pivot with this pivot index, store the returned
	// location of the pivot in a new variable, say new_pi
	// cout << "pi is" << pi << endl;
	int new_pi = pivot(array,n,pi);
	// recursively call qsort twice:
	// - once with the part before index new_pi
	// - once with the part after index new_pi
	// cout << "new_pi is: " <<new_pi << endl;
	qsort(array,new_pi);
	qsort(array + new_pi,n-new_pi);

	// and that’s it!
}

// Don't forget some tests! Use the tests from ssort as a starting point.

int main() {
	// call you tests from here
	int c[] = {19, 5 ,3, 21, 2, 6};
	int n = 6;
	qsort(c,n);
	for(int i = 0;i < n;i++){
		cout << c[i] << endl;
	}
	cout << "working";
	return 0;
}
