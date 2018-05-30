#include<iostream>
#include<cstdlib>

using namespace std;


int noOfComparison=0;
int noOfSwap = 0;

 int binarySearch(int arr[],int low,int high,int target){

	 if(low==high)
		 return low;

	 int mid = (low+(high-low))/2;

	 if(target == arr[mid] )
		 return mid;
	 else if(target>arr[mid])
		 return binarySearch(arr,mid+1,high,target);

	    return binarySearch(arr,low,mid,target);

 }
  /*void swap(int *arr,int i,int j){

    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;

    noOfSwap++;

  }
*/

  void insertionSort(int *arr,int size){


      int i,j,bin,temp;

     for( i=1;i<size;i++){

		  bin = binarySearch(arr,0,i,arr[i]);
	if(bin<i){

		 temp = arr[i];
      for( j=i-1;j>=0;j--){
          arr[j+1] = arr[j];


      }
	   arr[bin] = temp;

	}

     }

    }



int main(){



        int size;
	cout<<"\nenter the size of\n";
	cin>>size;

     int temp = size;

        int arr[size];
        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }


        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        insertionSort(arr,size);

         cout<<"\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}


