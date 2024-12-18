#include<stdio.h>
int main(){
 int t;
 scanf("%d",&t);
 for(int f=0;f<t;f++){
  int n;
  scanf("%d",&n);
    printf("2\n");
  if(n==2){
    printf("%d %d\n",n-1,n);
  }
  else if(n==3){
    printf("1 3\n2 2\n");
  }
  else{
  int n1,n2;
  n1=n-2;
  n2=n;
  printf("%d %d\n",n1,n2);
  printf("%d %d\n",n-1,n-1);
  for(int i=0;n1!=1;i++){
     n1=n-3-i;
     n2=n1+2;
     printf("%d %d\n",n1,n2);
  }

 }
 }
return 0;
}
