#include <stdio.h>
#include <time.h>
int maxDays(int m){
  int iDayOfMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int iCurrentMaxDay;
  int iMonth = m;
  iCurrentMaxDay = iDayOfMonth[iMonth-1];
    return iCurrentMaxDay;
}
int maxDays_Feb(int y){
  int iCurrentMaxDay;
  int iYear = y;
  iCurrentMaxDay = ((iYear % 4 == 0)||(iYear % 100 == 0)||(iYear % 400 == 0)) ? 29 : 28;
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
int main(int argc, char const *argv[]){
const char *wd[] = {"日","月","火","水","木","金","土"};
int arr[7];
time_t t;
struct tm *tp;
t = time(NULL);
tp = localtime(&t);
int thisYear,thisMonth,thisDay,m,d,temp,res,maxDay;
thisYear = tp->tm_year+1900;
thisMonth = tp->tm_mon+1;
thisDay = tp->tm_mday;
printf("今日は%d年%d月%d日です。\n",thisYear,thisMonth,thisDay);
printf("月/日?");
scanf("%d/%d",&m,&d);
maxDay = maxDays(m);
if (m<1||m>12||d<1||d>maxDay) {
  printf("月日が範囲外です");
  return 0;
}
printf("来年以降で次に%d月%d日が各曜日になる西暦年は次のとおりです。\n",m,d);
for (int i=0;i<7;i++){
  temp = thisYear;
  while (1){ 
    temp++;
    res = whatDay(temp,m,d);
    if (m==2)if (maxDays_Feb(temp)<d) continue;
    if (i==res) {
      arr[i] = temp;
      break;
    }
  }
}
for (int i=0;i<7;i++){
  printf("%s曜日：%d年\n",wd[i],arr[i]);
}
  return 0;
}
