#include <stdio.h>

void swap(int* a, int* b){
  int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
  int a[10],b[10];
  int s;
  for (int i = 0; i <= 9; i++) {
    printf("a%d？",i);
    scanf("%d",&a[i]);
    b[i] = i;
  }

do { 
  s = 0; 
for (int j = 1; j < 10; j++) {
  if(a[j-1]>a[j]){
    swap(&a[j-1],&a[j]);
    swap(&b[j-1],&b[j]);
    s = 1; 
  } else if(a[j-1]==a[j]&&b[j-1]<b[j]){
    swap(&b[j-1],&b[j]);
    s = 1;
  }
  } 
  } while (s == 1);
  for (int i = 0; i < 10; i++) {
    printf((i<9)?"a%d=%d,":"a%d=%d\n",b[i],a[i]);
  }
  return 0;
}

