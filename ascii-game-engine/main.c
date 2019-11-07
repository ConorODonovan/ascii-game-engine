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
void updateWindow(char **ptr, int x, int y, int prevX, int prevY);
void drawGameWindow(char **ptr);

// Set up Player struct
struct player
{
    int x;
    int y;
    int health;
};

typedef struct player Player;

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


    int prevX;
    int prevY;

    // Place Player into center of game world
    Player P1;
    P1.x = 30;
    P1.y = 10;
    P1.health = 100;
    prevX = 29;
    prevY = 10;

    updateWindow(window, P1.x, P1.y, prevX, prevY);
    drawGameWindow(window); // Draw the game window to the console

    char pDir = '-';

    // Game loop
    while (1)
    {
        prevX = P1.x;
        prevY = P1.y;

        printf("Pick a direction using WASD and press Enter\n");
        while (pDir != 'w' && pDir != 'a' && pDir != 's' && pDir != 'd')
        {
            pDir = getchar();
        }

        if (pDir == 'w')
        {
            if (P1.y > 0)
            {
                P1.y -= 1;
            }
        }
        else if (pDir == 's')
        {
            if (P1.y < WINDOW_HEIGHT - 1)
            {
                P1.y += 1;
            }
        }
        else if (pDir == 'a')
        {
            if (P1.x > 0)
            {
                P1.x -= 1;
            }
        }
        else if (pDir == 'd')
        {
            if (P1.x < WINDOW_WIDTH - 1)
            {
                P1.x += 1;
            }
        }

        pDir = '-';

        drawGameTitle();
        updateWindow(window, P1.x, P1.y, prevX, prevY);
        drawGameWindow(window);
    }
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

void updateWindow(char **ptr, int playerX, int playerY, int prevX, int prevY)
{
    ptr[prevY][prevX] = '.';
    ptr[playerY][playerX] = 'O';
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
