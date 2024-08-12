#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int merge(int a[],int l,int m,int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  int L[20], R[20];
  for(i=0;i<n1;i++)
    L[i]=a[l+i];
  for(j=0;j<n2;j++)
    R[j]=a[m+1+j];
  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<R[j])
    {
      a[k]=L[i];
      i++;
    }
    else
       a[k]=R[j];
       j++;
    k++;   
  }
  while(i<n1)
  {
   a[k]=L[i];
   i++;
   k++;
  }
  while(j<n2)
  {
    a[k]=R[j];
    j++;
    k++;
  }
}

void mergesort(int a[],int l,int r)
{
 int m;
 if(l<r)
 {
   m=l+(r-l)/2;
   mergesort(a,l,m);
   mergesort(a,m+1,r);
   merge(a,l,m,r);
  }
}
int main() {
    int i, n, a[100];
    time_t start, end;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    start = clock();
    mergesort(a, 0, n - 1);
    end = clock();
    printf("\nThe sorted array is \n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    double tc = (difftime(end, start) / CLOCKS_PER_SEC);
    printf("\nTime taken is %f", tc);
    return 0;
}

