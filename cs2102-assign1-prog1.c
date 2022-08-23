/*
Name: Debprasad Kundu
Roll No.: cs2102
Date:8th January, 2022
Programme Description: DOMINATING FOLDING of a string of length n
*/

#include <stdio.h>
#include <string.h>

void Folding_L(char str[], int n){
    int i, j, x, y;
    char res[200];
    if (n % 2 == 0){
        for (i = 0; i < n / 2; i++)
            res[n / 2 - 1 - i] = ((int)str[i] > (int)str[n - 1 - i]) ? str[i] : str[n - 1 - i];
        for (i = 0; i < n / 2; i++)
            str[i] = res[i];
        str[i] = '\0';
        for (j = 0; j < n / 2; j++)
            printf("%c", str[j]);
    }
    else{
        for (i = 0; i < n / 2 + 1; i++)
            res[n / 2 - i] = ((int)str[i] > (int)str[n - 1 - i]) ? str[i] : str[n - 1 - i];
        for (i = 0; i < n / 2 + 1; i++)
            str[i] = res[i];
        res[i] = '\0';
        for (j = 0; j < n / 2 + 1; j++)
            printf("%c", str[j]);
    }
    printf(" ");
}

void Folding_R(char str[], int n){
    int i, j, x, y;
    char res[200];
    if (n % 2 == 0){
        for (i = 0; i < n / 2; i++)
            str[i] = ((int)str[i] > (int)str[n - 1 - i]) ? str[i] : str[n - 1 - i];
        str[i] = '\0';
        for (j = 0; j < n / 2; j++)
            printf("%c", str[j]);
    }
    else{
        for (i = 0; i < n / 2 + 1; i++)
            str[i] = ((int)str[i] > (int)str[n - 1 - i]) ? str[i] : str[n - 1 - i];
        str[i] = '\0';
        for (j = 0; j < n / 2 + 1; j++)
            printf("%c", str[j]);
    }
    printf(" ");
}

int main()
{
    int n, i, j, m;
    char str[2000], rule[1000];
    printf("Enter the string and rule(L or R) sequence:");
    scanf("%s",str);
    scanf("%s",rule);
    n = strlen(str);
    m = strlen(rule);
    for (i = 0; i < m; i++)
    {
        if ('L' == rule[i])
            Folding_L(str, n);
        else if ('R' == rule[i])
            Folding_R(str, n);
        else{
            printf("Invalid rule");
            return 0;
        }
        n = (n % 2 == 0) ? (n / 2) : (n / 2 + 1);
    }  
    return 0;
}