#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumToFile(int N, int P, int Q, char* filename){
    FILE *fp = fopen(filename, "w");

    srand(time(NULL)); // initialize random seed

    for(int i=0; i<N; i++){
        int num = rand() % (Q-P+1) + P;
        fprintf(fp, "%d ", num);
    }

    fclose(fp);
}

int main(){
    int N, P, Q;
    char* filename = "Input.txt";

    printf("Enter the value of N: ");
    scanf("%d", &N);

    printf("Enter the value of P: ");
    scanf("%d", &P);

    printf("Enter the value of Q: ");
    scanf("%d", &Q);

    generateRandomNumToFile(N, P, Q, filename);

    printf("%d random numbers between %d and %d have been generated and written to the file %s\n", N, P, Q, filename);

    return 0;
}
