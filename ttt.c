#include "stdio.h"
#include "stdbool.h"

int a[3][3] = {
    {-1, -1, -1}, // 00, 01, 02
    {-1, -1, -1}, // 10, 11, 12
    {-1, -1, -1}  // 20, 21, 22
};
int check[10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0};

int xp, op;
bool end = false;

void printcoord()
{
    printf("1|2|3\n");
    printf("-----\n");
    printf("4|5|6\n");
    printf("-----\n");
    printf("7|8|9\n\n");
}

void printresult()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                printf("O");
            }
            else if (a[i][j] == 1)
            {
                printf("X");
            }
            else
            {
                if (end == false)
                {
                    if (i == 0)
                    {
                        if (j == 0)
                            printf("1");
                        else if (j == 1)
                            printf("2");
                        else
                            printf("3");
                    }
                    else if (i == 1)
                    {
                        if (j == 0)
                            printf("4");
                        else if (j == 1)
                            printf("5");
                        else
                            printf("6");
                    }
                    else
                    {
                        if (j == 0)
                            printf("7");
                        else if (j == 1)
                            printf("8");
                        else
                            printf("9");
                    }
                }
                else
                    printf("-");
            }
            if (j == 0 || j == 1)
                printf("|");
        }
        if (i == 0 || i == 1)
            printf("\n-----\n");
    }
}

void checkcross()
{
    if (a[0][0] == 1 && a[0][1] == 1 && a[0][2] == 1)
        end = true;
    else if (a[1][0] == 1 && a[1][1] == 1 && a[1][2] == 1)
        end = true;
    else if (a[2][0] == 1 && a[2][1] == 1 && a[2][2] == 1)
        end = true;

    else if (a[0][0] == 1 && a[1][0] == 1 && a[2][0] == 1)
        end = true;
    else if (a[0][1] == 1 && a[1][1] == 1 && a[2][1] == 1)
        end = true;
    else if (a[0][2] == 1 && a[1][2] == 1 && a[2][2] == 1)
        end = true;

    else if (a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1)
        end = true;
    else if (a[2][0] == 1 && a[1][1] == 1 && a[0][2] == 1)
        end = true;

    else if (a[0][0] == 0 && a[0][1] == 0 && a[0][2] == 0)
        end = true;
    else if (a[1][0] == 0 && a[1][1] == 0 && a[1][2] == 0)
        end = true;
    else if (a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0)
        end = true;

    else if (a[0][0] == 0 && a[1][0] == 0 && a[2][0] == 0)
        end = true;
    else if (a[0][1] == 0 && a[1][1] == 0 && a[2][1] == 0)
        end = true;
    else if (a[0][2] == 0 && a[1][2] == 0 && a[2][2] == 0)
        end = true;

    else if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
        end = true;
    else if (a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0)
        end = true;
}

void getinputX()
{
    if (xp == 1)
    {
        a[0][0] = 1;
    }
    else if (xp == 2)
    {
        a[0][1] = 1;
    }
    else if (xp == 3)
    {
        a[0][2] = 1;
    }
    else if (xp == 4)
    {
        a[1][0] = 1;
    }
    else if (xp == 5)
    {
        a[1][1] = 1;
    }
    else if (xp == 6)
    {
        a[1][2] = 1;
    }
    else if (xp == 7)
    {
        a[2][0] = 1;
    }
    else if (xp == 8)
    {
        a[2][1] = 1;
    }
    else if (xp == 9)
    {
        a[2][2] = 1;
    }
}

void getinputO()
{
    if (op == 1)
    {
        a[0][0] = 0;
    }
    else if (op == 2)
    {
        a[0][1] = 0;
    }
    else if (op == 3)
    {
        a[0][2] = 0;
    }
    else if (op == 4)
    {
        a[1][0] = 0;
    }
    else if (op == 5)
    {
        a[1][1] = 0;
    }
    else if (op == 6)
    {
        a[1][2] = 0;
    }
    else if (op == 7)
    {
        a[2][0] = 0;
    }
    else if (op == 8)
    {
        a[2][1] = 0;
    }
    else if (op == 9)
    {
        a[2][2] = 0;
    }
}

int main()
{
    system("cls");
    printf("Tic-Tac-Toe\n\n");
    printcoord();

start:
    printf("Player 1: Select the coordinate to place X: ");
inputx:
    scanf("%d", &xp);
    if (!(xp < 10 && xp > 0))
    {
        printf("[Error] Coordinate can only be between 1-9! Enter again: ");
        goto inputx;
    }
    if (check[xp] == 1)
    {
        printf("[Error] Coordinate has already been marked! Enter again: ");
        goto inputx;
    }
    else
    {
        check[xp] = 1;
    }
    getinputX();
    checkcross();
    if (end == true)
        goto end;

    printf("Player 2: Select the coordinate to place O: ");
inputy:
    scanf("%d", &op);
    if (!(op < 10 && op > 0))
    {
        printf("[Error] Coordinate can only be between 1-9! Enter again: ");
        goto inputy;
    }
    if (check[op] == 1)
    {
        printf("[Error] Coordinate has already been marked! Enter again: ");
        goto inputy;
    }
    else
    {
        check[op] = 1;
    }
    getinputO();
    checkcross();

    if (end == true)
        goto end;
    else
    {
        system("cls");
        printf("\n");
        printresult();
        printf("\n\n");
        goto start;
    }

end:
    system("cls");
    printf("\n");
    printresult();
    printf("\n\n");
    return (0);
}