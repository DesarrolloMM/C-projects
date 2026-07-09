#include<stdio.h>

#define SIZE 10
#define SUPERIORLIMIT 999
#define INFERIORLIMIT 100
#define TRUE 1
#define FALSE 0

void load(int array[]);
void show(int array[]);
//name specified by the test:
int centenas(int array[]);
//name specified by the test:
void mulfin(int array[], int);
void orderLines(int array[], int elementsPerLine);
void halfAdds(int array[]);

int main(){
    int numbers[SIZE];
    int itemsPerLine=0;
    int d=0;
    load(numbers);
    show(numbers);
    if(centenas(numbers)){
        printf("\nAll hundreds represented.\n");
    }
    else{
        printf("\nSome hundreds are not represented.\n");
    }
    printf("\nEnter the ammount per line: \n");
    scanf("%d", &itemsPerLine);
    orderLines(numbers, itemsPerLine);
    do
    {
        printf("\nEnter d number: \n");
        scanf("%d",&d);   
    } while (d<1||d>9);
    mulfin(numbers,d);
    halfAdds(numbers);
    return 0;
}

void load(int array[]){
    for (int i = 0; i < SIZE; i++)
    {
        do
        {
            printf("Enter the %dth number: ", i+1);
            scanf("%d", & array[i]);
        } while (INFERIORLIMIT>array[i] || array[i]>SUPERIORLIMIT);    
    }
}

void show(int array[]){
    printf("\nArray content: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("\n");
}

void orderLines(int array[], int elementsPerLine){
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
        if ((i+1)%elementsPerLine == 0){
            printf("\n");            
        }
    }
}

int centenas(int array[]){
    int auxArray[SIZE];
    int c;

    for (int i = 0; i < SIZE; i++) {
        auxArray[i] = 0;
    }

    for (int i = 0; i < SIZE; i++)
    {
        c = array[i]/100;
        if(c>=0 && c <SIZE){
            auxArray[c]=1;
        }
    }

    for (int i = 1; i < SIZE; i++)
    {
        if(auxArray[i]==0){
            return FALSE;
        }
    }
    return TRUE;
}


void mulfin(int array[], int d){
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if((array[i]%d)==0){
            counter++;
        }
        if((array[i]%10)==d){
            counter++;
        }
    }
    printf("\nD numbers: %d\n", counter);
}


void halfAdds(int array[]){
    
    int firstHalf = 0;
    int secondHalf = 0;
    int secondIndex = SIZE-1;
    
    for (int i = 0; i < secondIndex; i++)
    {
        secondIndex = SIZE -1 -i;
        firstHalf = firstHalf + array[i];
        secondHalf = secondHalf + array[secondIndex];
    }
    printf("\nFirsHalf: %d\n", firstHalf);
    printf("\nSecondHalf: %d\n", secondHalf);
}


