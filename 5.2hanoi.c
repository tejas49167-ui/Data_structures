#include <stdio.h>
#include <math.h>   // required for pow()

void tower(int n, char source, char temp, char destination)
{
    if (n == 0)
        return;

    tower(n - 1, source, destination, temp);
    printf("\nMove disc %d from %c to %c", n, source, destination);
    tower(n - 1, temp, source, destination);
}

void main()
{
    int n;
    printf("\nEnter the number of discs: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');

    printf("\n\nTotal Number of moves are: %d", (int)pow(2, n) - 1);
}
