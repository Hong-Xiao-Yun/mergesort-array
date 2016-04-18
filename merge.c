#include <stdio.h>
 void mergesort(int a[],int low,int high);
 void merge(int a[],int low,int mid,int high);
int main () {

   int n[ 11 ]={10,5,6,9,8,7,5,11,3,4,10}; 
   mergesort (n,0,10);
   
   for (int j = 0; j < 11; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }
   return 0;
}
void mergesort(int a[],int low,int high){
   if (low<high){
      int m=(high+low)/2;
      mergesort(a,low,m);
      mergesort(a,m+1,high);
      merge(a,low,m,high);
   }
}
void merge(int a[],int low,int mid,int high){
  int dst[high-low+1]; 
  int i1=low;
  int i2=mid+1;
  int k=0;
   while(i1<=mid && i2<=high){
      if (a[i1]<=a[i2])
         dst[k++]=a[i1++];
      else
         dst[k++]=a[i2++];     
   }
   while(i1<=mid){
      dst[k++]=a[i1++];  
   }
   while(i2<=high){
      dst[k++]=a[i2++];
   }

   for (int i = 0; i < k; ++i)
   {
      a[low+i]=dst[i];
   }

}  