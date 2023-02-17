#include <stdio.h>
#include <time.h>
#define MAX 7
int maxDays(int y,int m){
  int iDayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int iCurrentMaxDay;
  int iMonth = m;
  int iYear = y;
  if(iMonth == 2)
  {
    iCurrentMaxDay = ((iYear % 4 == 0)||(iYear % 100 == 0)||(iYear % 400 == 0)) ? 29 : 28;
  }
  else{
    iCurrentMaxDay = iDayOfMonth[iMonth-1];
  }
  return iCurrentMaxDay;
}

int whatDay(int y,int m, int d){
  struct tm t;
  t.tm_year = y;
  t.tm_mon = m;
  t.tm_mday = d;
  t.tm_hour = t.tm_min = t.tm_sec = 0;
  t.tm_isdst = -1;
  t.tm_year -= 1900;
  t.tm_mon -= 1;
  if (mktime(&t) == -1) {
    return -1;
  }
  return t.tm_wday;
}

int main(int argc, char const *argv[])
{
  const char *wd[] = {"日","月","火","水","木","金","土"};
  int i,j,y,m,a,arr[MAX][MAX];
  printf("西暦年/月?\n");
  scanf("%d/%d",&y,&m);
  int maxDay = maxDays(y,m);
  int b = whatDay(y,m,1); 
  a = MAX-1;
  for (i=0;i<MAX;i++) for(j=0;j<MAX;j++) arr[i][j] = 0;
  arr[b][a] = 1;
  for (i=2;i<=maxDay;i++){
    if (b<6){
      b++;
    }else {
      b-=6;
      a--;
    }
    arr[b][a] = i;
  }
  for (i=0;i<MAX;i++){
    for (j=0;j<MAX;j++){
      if (arr[i][j]==0){
        if (j>=MAX/2 || arr[0][j]!=0) printf("   ");
      } else if(arr[i][j]!=0){
        printf("%3d",arr[i][j]);
      }
    }
    printf(" %s\n",wd[i]);
  }
  return 0;
}
