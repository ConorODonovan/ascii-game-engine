/***
Simple ASCII Game Engine
By Conor O'Donovan
07/11/2019
***/

#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 60
#define WINDOW_HEIGHT 20

// Function declarations
void drawGameTitle();
void initialiseGameWindow(char **ptr);
void drawGameWindow(char **ptr);

int main()
{
    int i;

    char **window; // Initialise 2D array to act as game window

    window = malloc(WINDOW_WIDTH * sizeof *window);

    for (i = 0; i < WINDOW_WIDTH; i++)
    {
        window[i] = malloc(WINDOW_HEIGHT * sizeof * window[i]);
    }

    drawGameTitle(); // Put the game title header on the first three lines of the console

    initialiseGameWindow(window); // Set up the empty game window

    drawGameWindow(window); // Draw the game window to the console
}

// Draw game title above game window
void drawGameTitle()
{
    int i;

    for (i = 0; i < WINDOW_WIDTH; i++)
    {
        printf("=");
    }

    printf("\n");

    printf("----------------- Simple ASCII Game Engine -----------------");

    printf("\n");

    for (i = 0; i < WINDOW_WIDTH; i++)
    {
        printf("=");
    }

    printf("\n");
}

// Initialise game window
 void initialiseGameWindow(char **ptr)
{
    int x;
    int y;

    for (y = 0; y < WINDOW_HEIGHT; y++)
    {
        for (x = 0; x < WINDOW_WIDTH; x++)
        {
            ptr[y][x] = '.';
        }
    }
}

// Draw the game window to the console
void drawGameWindow(char **windowPtr)
{
    int x;
    int y;

    for (y = 0; y < WINDOW_HEIGHT; y++)
    {
        for (x = 0; x < WINDOW_WIDTH; x++)
        {
            printf("%c", windowPtr[y][x]);
        }

        printf("\n");
    }
}