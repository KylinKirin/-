#include <math.h>
#include <stdio.h>
#define MAX 100000000
void prime(int n){
  static char arr[MAX];
  long long int res,count=0;
  if (n==2){
    res = 2;
    count++;
    printf("%d以下の最大の素数=%lld\n",n,res);
    printf("%d以下の素数の個数=%lld\n",n,count);
    return;
  }
  for (int i = 2;i<=n;i++){
    arr[i] = 'p';
  }
  for (int i = 2;i<=sqrt(n);i++){
    if (arr[i] == 'p'){
      for (int j = 2*i;j<MAX;j+=i){
        arr[j] = 'c';
      }
    }
  }
  for (int i = 2;i<MAX;i++){
    if (arr[i]=='p'){
      count++;
      res = i;
    }
  }
  printf("%d以下の最大の素数=%lld\n",n,res);
  printf("%d以下の素数の個数=%lld\n",n,count);
}

int main(int argc, char const *argv[])
{ 
  long long int n;
  printf("2以上100,000,000未満の整数を入力してください。\n");
  scanf("%lld",&n);
  if (n<2||n>=MAX){
    printf("入力が範囲外です\n");
    return 0;
  }
  prime(n);
  return 0;
}
