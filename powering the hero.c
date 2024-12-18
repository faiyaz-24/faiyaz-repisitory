#include<stdio.h>
void hero_adder(long long arr[],long long *sum,int i){
 long long largest=0;
 int j,j_max=0;
 for(j=0;j<i;j++){
    if(largest<arr[j]){
      largest=arr[j];
      j_max=j;
    }
 }
 *sum=*sum+arr[j_max];
  arr[j_max]=0;
}
int main(){
 int t;
 scanf("%d",&t);
 for(int f=0;f<t;f++){
   int n;
   scanf("%d",&n);
   long long arr[n],sum=0;
   for(int i=0;i<n;i++){
    scanf("%lld",&arr[i]);
     if(arr[i]==0){hero_adder(arr,&sum,i);}
   }
   printf("%lld\n",sum);

 }

return 0;
}
