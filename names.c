#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define MAX_NAMES 5
#define NAME_LEN 15

char names[MAX_NAMES][NAME_LEN] = {0};
char menu[5][8] = {"Add", "Edit", "Delete", "Display", "Exit"};
int normalColor = 0;
int highlightColor = 4;
int currentSelection = 0;
int quitflag = 0;

// Set foreground color
void textattr(int fg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, fg);
}

int main()
{
    char ch;

    while (!quitflag)
    {
        system("cls");

        // Print menu
        for (int i = 0; i < 5; i++)
        {
            if (i == currentSelection)
                textattr(highlightColor);
            else
                textattr(normalColor);

            printf("%d. %s\n", i + 1, menu[i]);
        }

        textattr(normalColor);

        ch = _getch();

        // Handle arrow keys
        if (ch == 72) // up
        {
            currentSelection--;
            if (currentSelection < 0)
                currentSelection = 4;
        }
        else if (ch == 80) // down
        {
            currentSelection++;
            if (currentSelection > 4)
                currentSelection = 0;
        }
        else if (ch == 13) // enter
        {
            if (currentSelection == 4) // Exit
            {
                quitflag = 1;
                continue;
            }

            int index; // single declaration for Edit/Delete

            switch (currentSelection)
            {
            case 0: // Add
            {
                int added = 0;
                for (int i = 0; i < MAX_NAMES; i++)
                {
                    if (names[i][0] == '\0')
                    {
                        printf("Enter a name: ");
                        scanf("%14s", names[i]);
                        added = 1;
                        break;
                    }
                }
                if (!added)
                    printf("You reached maximum number of names.\n");

                system("pause");
                break;
            }

            case 1: // Edit
            {
                printf("Current names:\n");
                for (int i = 0; i < MAX_NAMES; i++)
                {
                    if (names[i][0] != '\0')
                        printf("%d. %s\n", i, names[i]);
                }

                printf("Enter index you want to change (0-%d): ", MAX_NAMES - 1);
                scanf("%d", &index);

                if (index >= 0 && index < MAX_NAMES && names[index][0] != '\0')
                {
                    char newName[NAME_LEN];
                    printf("Enter new name: ");
                    scanf("%14s", newName);
                    strcpy(names[index], newName);
                }
                else
                {
                    printf("Invalid index!\n");
                }

                system("pause");
                break;
            }

            case 2: // Delete
            {
                printf("Current names:\n");
                for (int i = 0; i < MAX_NAMES; i++)
                {
                    if (names[i][0] != '\0')
                        printf("%d. %s\n", i, names[i]);
                }

                printf("Enter index you want to delete (0-%d): ", MAX_NAMES - 1);
                scanf("%d", &index);

                if (index >= 0 && index < MAX_NAMES && names[index][0] != '\0')
                {
                    memset(names[index], 0, NAME_LEN);
                    printf("Deleted successfully.\n");
                }
                else
                {
                    printf("Invalid index!\n");
                }

                system("pause");
                break;
            }

            case 3: // Display
            {
                printf("Saved names:\n");
                for (int i = 0; i < MAX_NAMES; i++)
                {
                    if (names[i][0] != '\0')
                        printf("%d. %s\n", i, names[i]);
                }
                system("pause");
                break;
            }

            default:
                break;
            }
        }
    }

    return 0;
}
