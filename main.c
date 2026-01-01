#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    while (getchar() != '\n')
        ;
    getchar();
}

int main(void)
{
    int marks[MAX];
    int count = 0;
    int decision;
    int i, index;
    int sum;

    do
    {
        printf("\n--- Student Marks Menu ---\n");
        printf("1. Add student marks\n");
        printf("2. Edit student marks\n");
        printf("3. Display student marks\n");
        printf("4. Get sum of student marks\n");
        printf("5. Average of student marks\n");
        printf("6. Exit\n");

        printf("Enter your decision: ");
        scanf("%d", &decision);

        switch (decision)
        {
        case 1:
            if (count < MAX)
            {
                printf("Enter mark: ");
                scanf("%d", &marks[count]);
                count++;
            }
            else
            {
                printf("Maximum number of students reached.\n");
            }
            pauseScreen();
            system("cls");
            break;

        case 2:
            printf("Enter student index (0 to %d): ", count - 1);
            scanf("%d", &index);

            if (index >= 0 && index < count)
            {
                printf("Enter new mark: ");
                scanf("%d", &marks[index]);
            }
            else
            {
                printf("Invalid index.\n");
            }
            pauseScreen();
            system("cls");
            break;

        case 3:
            if (count == 0)
            {
                printf("No marks available.\n");
            }
            else
            {
                for (i = 0; i < count; i++)
                {
                    printf("Student %d: %d\n", i, marks[i]);
                }
            }
            pauseScreen();
            system("cls");
            break;

        case 4:
            sum = 0;
            for (i = 0; i < count; i++)
            {
                sum += marks[i];
            }
            printf("Sum of marks: %d\n", sum);
            pauseScreen();
            system("cls");
            break;

        case 5:
            if (count == 0)
            {
                printf("No marks available.\n");
            }
            else
            {
                sum = 0;
                for (i = 0; i < count; i++)
                {
                    sum += marks[i];
                }
                printf("Average marks: %.2f\n", (float)sum / count);
            }
            pauseScreen();
            system("cls");
            break;

        case 6:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
            pauseScreen();
            system("cls");
        }

    } while (decision != 6);

    return 0;
}