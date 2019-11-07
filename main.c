#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 20

// Function declarations
void drawGameWindow(int width, int height);

int main()
{
    drawGameWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

// Draw game WINDOW_HEIGHT
void drawGameWindow(int width, int height)
{
    int x;
    int y;

    for (y = 0; y < height; y++)
    {
        if (y == 0 || y == 2)
        {
            int i;

            for (i = 0; i < width; i++)
            {
                printf("=");
            }
        }

        if (y == 1)
        {
            printf("----------------- Simple ASCII Game Engine -----------------");
        }

        if (y > 2)
        {
            for (x = 0; x < width; x++)
            {
                printf(".");
            }
        }

        printf("\n");
    }
}
