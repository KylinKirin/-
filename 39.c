#include <stdio.h>
#define MAX 10000
int pow_c(int a,int b){
  int res = 1;
  for (int i=0;i<b;i++) res*=a;
  return res;
}

int getDigits(int n){
  int i=1;
  while (i<MAX)
  {
    if(pow_c(10,i)>n) break;
    i++;
  }
  return i;
}

int main(int argc, char const *argv[])
{
  unsigned int i,j,k=0,n,f,flag=0;
  unsigned int d[MAX];
  printf("2^n-1を10進数で表示します。1以上100,000未満の整数nを入力してください。\n");
  scanf("%d",&n);
  f = getDigits(MAX)-1;
  d[0] = 1;
  for (i=1;i<MAX;i++) d[i] = 0;
  for (j=0;j<n;j++){
    for (i=0;i<=k+1;i++){
      d[i]*=2;
    }
    for (k=0;k<MAX;k++){
      if (d[k]>=MAX){
        d[k] -= MAX;
        d[k+1]++;
      }
    }
  }
  for (i=MAX-1;i>=0;i--) {
    if (d[i]!=0) break;
  }
  d[0]--;
  if (i>0) {
    flag += getDigits(d[i]);
    printf("%d",d[i--]);
  }
  for(i;i>0;i--) {
    printf("%0*d",f,d[i]);
    flag+=f;
  }
  printf("%0*d",getDigits(d[0]),d[0]);
  printf("\n2^%d-1は10進数で%d桁です。\n",n,flag+getDigits(d[0]));
  return 0;
}
