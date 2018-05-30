#include<iostream>
#include<cstdlib>
using namespace std;


int noOfComparison=0;
int noOfSwap=0;



 void merge(int arr[], int l, int m, int r);


int min(int x, int y) { return (x<y)? x :y; }



void mergeSort(int arr[], int n)
{
   int i;
   int l;

   for (i=1; i<n; i = 2*i)
   {

       for (l=0; l<n-1; l+= 2*i)
       {

           int mid = l + i - 1;

           int r = min(l + 2*i - 1, n-1);


           merge(arr, l, mid, r);
       }
   }
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}





int main(){



        int size;
	cout<<"\nenter the size of\n";
	cin>>size;

        int arr[size];


        int temp = size;


        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }

        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        mergeSort(arr,size);

         cout<<"\n the given array after applying merge sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}


