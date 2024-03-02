#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <crtdbg.h>
#include "tests.h"
void allOp(int op[64][3])
{
    int pos = 0;
    while(pos<64)
    for (int i = 1; i <= 4; i++)
    {

        for (int j = 1; j <= 4; j++)

            for (int k = 1; k <= 4; k++)
            {
                op[pos][0] = i;
                op[pos][1] = j;
                op[pos][2] = k;
                pos++;
            }
    }
}
double computation(int a, int b, int op)
{
    if (op == 1)
        return a + b;
    if (op == 2)
        return a - b;
    if (op == 3)
        return a * b;
    if (op == 4 && b != 0)
        return (a / b);
}
char conversion(int a)
{
    if (a == 1)
        return '+';
    if (a == 2)
        return '-';
    if (a == 3)
        return '*';
    if (a == 4)
        return '/';
}
int counter_conversion(char c)
{
    if (c == '+')
        return 1;
    if (c == '-')
        return 2;
    if (c == '*')
        return 3;
    if (c == '/')
        return 4;
}

void generateAllCombinations(int** numbers, char** operators) {
    int pos_op[64][3];
    allOp(pos_op);
    int number_pos = 0;
    for (int i = 1; i <= 9; i++)

        for (int j = 1; j <= 9; j++)

            for (int l = 1; l <= 9; l++)

                for (int m = 1; m <= 9; m++)
                {
                    for (int ops = 0; ops < 64; ops++)
                    {
                        if (computation(m, computation(l, computation(j, i, pos_op[ops][0]), pos_op[ops][1]), pos_op[ops][2]) == 24)
                        {
                            numbers[number_pos][0] = i;
                            numbers[number_pos][1] = j;
                            numbers[number_pos][2] = l;
                            numbers[number_pos][3] = m;
                            operators[number_pos][0] = conversion(pos_op[ops][0]);
                            operators[number_pos][1] = conversion(pos_op[ops][1]);
                            operators[number_pos][2] = conversion(pos_op[ops][2]);
                            number_pos++;
                        }
                    }
                }


}
int check_operator(char operator)
{
    if (operator == '+' || operator == '-' || operator=='*' || operator=='/')
        return 1;
    else
    {
        printf("Invalid operator!!\n");
        printf("Choose one of the given operators\n");
        return 0;
    }
}
void print_instructions()
{
    printf("Instructions\n");
    printf("You are given 4 integers and you have to choose three out of the four basic operators such that the result equals to 24\n");
    printf("The four operators are: + (addition); - (division); * (multiplication); /(division)\n");
    printf("!! No other operators allowed!!");
}
void gameplay(int numbers[4], char operator1, char operator2, char operator3)
{
    double result, old_result;
    result = computation(numbers[0], numbers[1], counter_conversion(operator1));
    printf("%d %c %d = %f\n", numbers[0], operator1, numbers[1], result);
    old_result = result;
    result = computation(result, numbers[2], counter_conversion(operator2));
    printf("%f %c %d = %f\n", old_result, operator2, numbers[2], result);
    old_result = result;
    result = computation(result, numbers[3], counter_conversion(operator3));
    printf("%f %c %d = %f\n", old_result, operator3, numbers[3], result);
    if (result == 24)
        printf("Well done!\n");
    else
        printf("You lost! The result is not 24!\n");
    printf("Would you like to play again? y=Yes or n=No\n");

}

int main(int argc, char* argv[])
{


    printf("Welcome to the game of TwentyFour.\n");
    printf("Use each of the four numbers shown below exactly once, combining them somehow with the basic mathematical operators.\n");
    printf("Basic operators: +,-,*,/, to yield the value twenty-four.\n");
    char command = 'y', game_command;
    printf("Legend:\n");
    printf("s = save all possible solutions in a file and exit\n");
    printf("e = play game in easy mode\n");
    printf("h = show instructions about the game\n");
    printf("f = play game in full mode\n");
    printf("Which game mode do you prefer?\n");
    printf("Easy mode (e) or full mode(f)\n");
    scanf(" %c", &game_command);
    while (command != "n")
    {
        if (game_command == 'f') {
            int numSolutions = 3188;
            int** numbers = (int**)malloc(numSolutions * sizeof(int*));
            char** operators = (char**)malloc(numSolutions * sizeof(char*));
            for (int i = 0; i <= 3188; i++) {
                numbers[i] = (int*)malloc(4 * sizeof(int));
                operators[i] = (char*)malloc(3 * sizeof(char));
            }
            int line = rand() % 3188;
            generateAllCombinations(numbers, operators);
            printf("The numbers to use are: %d, %d, %d, %d.\n", numbers[line][0], numbers[line][1], numbers[line][2], numbers[line][3]);
            printf("Enter the operators to be used in the order(+,-,* or /).\n");
            char operator1, operator2, operator3;
            scanf(" %c", &operator1);
            scanf(" %c", &operator2);
            scanf(" %c", &operator3);
            if (check_operator(operator1) == 1 && check_operator(operator2) && check_operator(operator3))

            {
                gameplay(numbers[line], operator1, operator2, operator3);
            }
            printf("Would you like to try again?\n");
            scanf(" %c", &command);
        }
            if (game_command == 'e')
            {
                while (command != 'n')
                {
                    int set_num[7][4] = { {1, 1, 4, 6},{1, 1, 3, 8},{1, 2, 2, 6},{1, 2, 3, 4},{1, 1, 3, 9},{4, 4, 4, 6},{1, 8, 8, 8} };
                    int set = rand() % 7;
                    int number[4];
                    number[0] = set_num[set][0];
                    number[1] = set_num[set][1];
                    number[2] = set_num[set][2];
                    number[3] = set_num[set][3];
                    printf("The numbers to use are: %d, %d, %d, %d.\n", set_num[set][0], set_num[set][1], set_num[set][2], set_num[set][3]);
                    printf("Enter the operators to be used in the order(+,-,* or /).\n");
                    char operator1, operator2, operator3;
                    scanf(" %c", &operator1);
                    scanf(" %c", &operator2);
                    scanf(" %c", &operator3);
                    if (check_operator(operator1) == 1 && check_operator(operator2) && check_operator(operator3))
                    {
                        gameplay(number, operator1, operator2, operator3);
                    }
                    printf("Would you like to play again?\n");
                    printf("Yes (y) or No (n).\n");
                    scanf(" %c", &command);
                }
            }
            if (command == 'h')
                print_instructions();
            if (command == 's')
                printf("none");

        
        printf("Thank you for playing!!\n");
    }
}
