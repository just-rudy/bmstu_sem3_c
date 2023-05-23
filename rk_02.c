#include <stdio.h>
#include <string.h>

struct Contact
{
    char s_name[30];
    char name [30];
    char f_name[30];
    char phone_num[9];
};

void separate(char s[256], struct Contact *phone_book);
//void swap(struct Contact *phone_book, struct Contact *phone_book);
//void sort(struct Contact *phone_book, int n);
void out_book(FILE *f, struct Contact *phone_book, int n);

int main(int args, char *argv[]) {
    int status = 0;
    if (args != 3)
    {
        status = 1;
        printf("argument error");
    }
    else
    {
        FILE *input = fopen(argv[1], "r");
        FILE *output = fopen(argv[2], "w");
        struct Contact phone_book[100];
        char s[256];
        int n = 0;
        
        while (fgets(s, 256, input))
        {
            s[strlen(s)-1] = 0;
            separate(s, phone_book+n);
            n++;
        }
        
        fclose(input);
        
        out_book(output, phone_book, n);
        
        fclose(output);
    }
    return status;
}

void separate(char s[256], struct Contact *phone_book)
{
    int i = 0, j = 0;
    while (s[i] != ' ')
    {
        phone_book->s_name[i]=s[i];
        i++;
    }
    i++;
    while (s[i] != ' ')
    {
        phone_book->name[j]=s[i];
        j++;
        i++;
    }
    j = 0;
    i++;
    while (s[i] != ' ')
    {
        phone_book->f_name[j]=s[i];
        j++;
        i++;
    }
    j = 0;
    i++;
    while (s[i] != ' ')
    {
        phone_book->phone_num[j]=s[i];
        j++;
        i++;
    }
}

void out_book(FILE *f, struct Contact *phone_book, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s %s %s %s\n", phone_book[i].s_name, phone_book[i].name, phone_book[i].f_name, phone_book[i].phone_num);
    }
}
