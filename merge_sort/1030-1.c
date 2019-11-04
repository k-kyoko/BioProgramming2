#include <stdio.h>
#define max 100000
void msort(int A[], int p, int q);
void merge(int A[], int a, int b, int c, int d);

int main(void){
    int A[max];
    int inum;
    FILE *fp;

    fp = fopen("sorting.data", "r");
    inum = 0;
    while (fscanf(fp, "%d", &A[inum]) != EOF){inum++;}
    fclose(fp);
    msort(A, 0, inum-1);
    
    return 0;
}

void msort(int A[], int p, int q){
    int x;
    if(p<q){
        x = (q+1-p)/2 + p-1;
        msort(A, p, x);
        msort(A, x+1, q);
        int j;
        for(j=0;j<q;j++){
            printf("%d ", A[j]);
        }
        merge(A, p, x, x+1, q);
    }
    int j;
    //for(j=0; j<q; j++){
     //   printf("%d ", A[j]);
    //}
}

void merge(int A[], int a, int b, int c, int d){
    int temp[max], i, l, mlen=(b-a+1)+(d-c+1);
    for(i=0; i<mlen; i++){
        if(a==b){
            temp[i] = A[c];
            c += 1;
        }else if(c==d){
            temp[i] = A[a];
            a += 1;
        }else if(A[a] <= A[c]){
            temp[i] = A[a];
            a += 1;
        }else if(A[c] < A[a]){
            temp[i] = A[c];
            c += 1;
        }
    }
    //for(l=0; l<mlen; l++){
    //    A[a+l] = temp[l];
    //    printf("%d ", temp[l]);
    //}
    //printf("\n");
}
