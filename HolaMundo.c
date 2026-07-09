#include <stdio.h>

void mensaje() {
    printf("Desde funcion externa!!\n");
    return;
}  

int main() {
    mensaje(); 
    return 0;
}
