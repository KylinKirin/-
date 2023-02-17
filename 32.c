#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[]){
  int d1,d2,d;
  const char *str[] = {"前","後"};
  struct tm t1,t2;
  t1.tm_hour = t1.tm_min = t1.tm_sec = t2.tm_hour = t2.tm_min = t2.tm_sec = 0;
  t1.tm_isdst = t2.tm_isdst= -1;
  printf("日付2が日付1の何日後(前)かを求めます。\n日付1を西暦年/月/日の形式で入力してください(西暦年は1971以上)。\n");
  scanf("%d/%d/%d",&t1.tm_year,&t1.tm_mon,&t1.tm_mday);
  printf("日付2を日付1と同様に入力してください。\n");
  scanf("%d/%d/%d",&t2.tm_year,&t2.tm_mon,&t2.tm_mday);
  t1.tm_year -= 1900;
  t2.tm_year -= 1900;
  t1.tm_mon -= 1;
  t2.tm_mon -= 1;
  d1 = mktime(&t1);
  d2 = mktime(&t2);
  d = (d2-d1)/86400;
  printf("日付2は日付1の%d日%sです。\n",(d<0)?-d:d,(d<0)?str[0]:str[1]);
  return 0;
}
