#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
   int l1, l2, i;
   int b[100];
   l1 = low;
   l2 = mid+1;
   i = low;

   while( l1 <= mid && l2 <= high) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
      
      i++;
    
   }
   
   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int a[], int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      sort(a,low, mid);
      sort(a,mid+1, high);
      merge(a,low, mid, high);
   } 
   else { 
      return;
   }   
}

int main() { 
   int i,n;
   int a[100];

   printf("Enter no. of elements:");
   scanf("%d",&n);

   printf("Enter elements of array\n");
   
   for(i = 0; i <= n-1; i++){
      scanf("%d ", &a[i]);
   }

   sort(a,0, n-1);

   printf("\nSorted Array\n");
   
   for(i = 0; i <=n-1; i++)
      printf("%d ", a[i]);

    return 0 ;
}