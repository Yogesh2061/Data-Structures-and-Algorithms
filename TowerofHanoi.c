#include <stdio.h>

void towerOfHanoi(int n, char source, char destination, char temporary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source,destination);
        return; // return in a void function exits the function immediately without returning a value.
    }
    towerOfHanoi(n - 1, source, temporary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, temporary, destination, source);
}

int main() {    
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi for moving %d disks are:\n",n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}   