#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height = 0;

    do
    {
        height = get_int("Enter a height: ");
    }
    while (height < 1 || height >= 9);

    for (int y = 0; y < height; y++)
    {
        // Right spacing
        for (int x = 0; x < (height - (y + 1)); x++)
        {
            printf(" ");
        }

        // Left pyramid
        for (int x = 0; x < (y + 1); x++)
        {
            printf("#");
        }

        printf("  ");

        // Right Pyramid
        for (int x = 0; x < (y + 1); x++)
        {
            printf("#");
        }

        printf("\n");
    }
}
