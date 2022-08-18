#include <stdio.h>
typedef struct data
{
    int id;
    char label[100];
    char text[100];
    int label_num;
} DATA;
int count_mails(FILE *);
void read_data(FILE *fp, DATA *d, int n);
void display(DATA *d, int n);
void swap(DATA *s1, DATA *s2);
void sort(DATA *d, int n);
void writetofile(DATA *d, FILE *fw, int n);
int writeham(DATA *d, int n, FILE *fw_spam);
int writespam(DATA *d, int n, FILE *fw_spam);
int mysearch(DATA *a, int low, int high, int id);
DATA get_spam_looks_like_ham(DATA *d, int n);
