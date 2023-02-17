#include <stdio.h>
#define MAX 10000
int abs (int n){
  if (n<0) return -n;
  return n;
}

int main(int argc, char const *argv[])
{
  int i,n,count,sign,p,q,u,r;
  int mode = sign = 0;
  static int res[MAX];
  for (i=0;i<MAX;i++) res[i] = -1;
  printf("整数/正整数の形式で分数を入力してください。\n");
  scanf("%d/%d",&p,&q);
  printf("小数点以下何桁表示しますか?");
  scanf("%d",&n);
  count = 0;
  u=abs(p/q);
  if ((p<0&&!(q<0))||(!(p<0)&&q<0)) sign=1;
  do
  {     
    res[count] = abs(p/q);
    r = abs(p%q);
    if (q==1||r==0) {
      mode = 1;
      break;
    }
    p = r*10;
    count++;
  } while (count<=n);
  if (sign==1) printf("-");
  printf("%d",u);
  if (res[1]!=-1) printf(".%d",res[1]);
  for (i=2;i<MAX;i++) {
    if (res[i]==-1) break;
    printf("%d",res[i]);
  }
  if (mode == 1){
    printf("\n割り切れました。\n");
  } else printf("\n");
  return 0;
}
