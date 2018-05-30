#include<iostream>

using namespace std;


void maxHeapify(int a[], int i, int s) {

    int temp, largeI, left, right;

        largeI = i;

        if(i >= (s/2)) {

            return;

        }

        left = 2*i+1;
        right = 2*i+2;

        if(right < s) {

            if(a[left] > a[right]) {
                largeI = left;
            }
            else {

                largeI = right;
            }

            if(a[i] >= a[largeI]) {

                return;

            }
            else {

                temp = a[i];
                a[i] = a[largeI];
                a[largeI] = temp;

                maxHeapify(a, largeI, s);
            }
        }

        else {


            if(a[left] > a[i]) {
                largeI = left;

                temp = a[i];
                a[i] = a[largeI];
                a[largeI] = temp;

                maxHeapify(a, largeI, s);
            }
            else {
                return;
            }


        }

}

void buildHeap(int a[], int s) {

    for(int i = (s/2)-1; i >= 0; --i) {
        maxHeapify(a, i, s);
    }

}




void heapSort(int a[], int s) {

int temp;
int heapsize = s;
    buildHeap(a, heapsize);

    for(int i = heapsize-1; i >= 0; --i) {

        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapsize -= 1;

        maxHeapify(a, 0, heapsize);
    }
}


int main() {

	int n = 10;
	int a[n];

	for(int i = 0; i < n; ++i)
		a[i] = n-i;

	//Isort(a, n);

    heapSort(a, n);

	cout<<"\n\n\n\n\nSorted array: "<<endl;
    for(int i =0; i < n; ++i) {
        cout<<a[i]<<" ";
    }

}



