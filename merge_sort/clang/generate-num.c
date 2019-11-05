#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*#include <math.h>*/

#define MAXNUM 10000

int main(void)
{
  int num, inum, expn, i;
  FILE *fp;

  setvbuf(stdout, NULL, _IONBF, 0);

  printf("How many numbers will be generated? Input the power?\n");
  scanf("%d", &inum);

  fp=fopen("sorting.data", "w");

  srand(time(NULL));
  /*expn = pow(2,inum);*/
  expn = 1<<inum;
  for (i=0; i<expn; i++) {
    num = rand() % MAXNUM;
    fprintf(fp, "%d ", num);
  }

  fclose(fp);

  printf("%d numbers were generated.\n", expn);

  return 0;
}
