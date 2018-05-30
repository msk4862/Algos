#include<iostream>
using namespace std;


/*int maximum(int *A,int size){

   int max=0;
   for(int i=0;i<size;i++){
      if(A[i]>max)
      max = arr[i];
   }

   return max;

}

int minimum(int *A,int size){

   int min=10000;
   for(int i=0;i<size;i++){
      if(A[i]<min)
      min = A[i];
   }

   return min;

}
*/

void linearSort(int *A,int size){


    //int min = minimum(A,size);
    //int max = maximum(A,size);


   int Range = 100;

   int *C = new int[Range];


   for(int i =0;i<size;i++){
   C[A[i]] +=1;
   }


   for(int i =1;i<Range;i++)
   C[i] = C[i]+C[i-1];


   int *B = new int[size];


   for(int i=size-1;i>=0;i--){


    B[C[A[i]]] = A[i];

    C[A[i]] = C[A[i]]-1;

   }

   for(int i=0;i<size;i++){
          A[i] = B[i];

        }
   

}


int main(){



      int size;
	cout<<"\nenter the size of array \n";
	cin>>size;

        int *arr = new int[size];


        int temp = size;


        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }
        

        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        linearSort(arr,size);

         cout<<"\n the given array after applying merge sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}
