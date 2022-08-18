#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
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

int main()
{
    FILE *fp = fopen("spam_ham_dataset.csv", "r");
    int count = count_mails(fp);
    printf("%d", count);

    fseek(fp, 0, SEEK_SET);
    DATA d[6000];
    read_data(fp, d, count);

    printf("The details of mails from the file are as below\n");

    display(d, count);

    printf("sorted data is\n");
    sort(d, count);
    display(d, count);
    printf("The number of mails %d\n", count);

    fclose(fp);
    printf("writing the sorted data to sorted.csv\n");
    FILE *fw = fopen("sorted.csv", "w");
    writetofile(d, fw, count);
    printf("sorted data successfully written to file\n");
    fclose(fw);

    printf("writing spam data to spam.csv and ham data to ham.csv\n");
    FILE *fw_spam = fopen("spam.csv", "w");
    FILE *fw_ham = fopen("ham.csv", "w");
    int count_spam = writespam(d, count, fw_spam);
    int count_ham = writeham(d, count, fw_ham);
    printf("Done writing to both files successfully:\nContains %d spam mails\nContains %d ham mails\n", count_spam, count_ham);
    fclose(fw_ham);
    fclose(fw_spam);

    int id;
    printf("enter the id to be searched in the dataset\n");
    scanf("%d", &id);
    int pos = mysearch(d, 0, count - 1, id);
    if (pos == -1)
        printf("id doesnt exist");
    else
        printf("present at pos %d with these details ----> %d, %s,%s, %d\n", pos, d[pos].id, d[pos].label, d[pos].text, d[pos].label_num);

    // There is logical error in this function.Rectify
    DATA dspam = get_spam_looks_like_ham(d, count);
    printf("id of spam which looks like ham is %d\n", dspam.id);
    return 0;

    fclose(fp);
    return 0;
}

int count_mails(FILE *fp)
{
    char line[1000];
    int count = 0;
    fgets(line, 1000, fp);
    while (fgets(line, 1000, fp) != NULL)
    {
        count++;
        // return count;
    }
    return count;
}
void read_data(FILE *fp, DATA *d, int n)
{
    char line[1000];
    fgets(line, 1000, fp);
    int i = 0;
    while (fgets(line, 1000, fp) != NULL)
    {
        int id = atoi(strtok(line, ","));
        char *label = strtok(NULL, ",");
        char *text = strtok(NULL, ",");
        int label_num = atoi(strtok(NULL, ","));
        d[i].id = id;
        strcpy(d[i].label, label);
        strcpy(d[i].text, text);
        d[i].label_num = label_num;
        // printf("%d\t%s\t%s\t%d\n", d[i].id, d[i].label, d[i].text, d[i].label_num);
        i++;
    }
}

void display(DATA *d, int n)
{
    for (int i = 0; i < n; i++)
    {

        fprintf(stdout, "%d\t%s\t%s\t%d\n", d[i].id, d[i].label, d[i].text, d[i].label_num);
    }
}

void sort(DATA *d, int n)
{
    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (d[pos].id > d[j].id)
            {
                pos = j;
            }
        }
        if (pos != i)
        {
            swap(&d[pos], &d[i]);
        }
    }
}

void swap(DATA *s1, DATA *s2)
{
    DATA t = *s1;
    *s1 = *s2;
    *s2 = t;
}

void writetofile(DATA *d, FILE *fw, int n)
{
    fputs("id,label,text,label_number\n", fw);
    for (int i = 0; i < n; i++)
    {
        fprintf(fw, "%d,%s,%s,%d\n", d[i].id, d[i].label, d[i].text, d[i].label_num);
    }
}

int writespam(DATA *d, int n, FILE *fw)
{
    int count_spam = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(d[i].label, "spam") == 0)
        {
            fprintf(fw, "%d,%s,%s,%d\n", d[i].id, d[i].label, d[i].text, d[i].label_num);
            count_spam++;
        }
    }
    return count_spam;
}
int writeham(DATA *d, int n, FILE *fw)
{
    int count_ham = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(d[i].label, "ham") == 0)
        {
            fprintf(fw, "%d,%s,%s,%d\n", d[i].id, d[i].label, d[i].text, d[i].label_num);
            count_ham++;
        }
    }
    return count_ham;
}

int mysearch(DATA *a, int low, int high, int id)
{
    if (low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (a[mid].id == id)
            return id;
        else if (id < a[mid].id)
            return mysearch(a, low, mid - 1, id);
        else
            return mysearch(a, mid + 1, high, id);
    }
}

DATA get_spam_looks_like_ham(DATA *d, int n)
{
    DATA did;
    int temp = 1;
    for (int i = 1; (i < n) && temp; i++)
    {
        if (strcmp(d[i].label, "ham") == 0 && d[i].label_num == 0 && strcmp(d[i].text, "Subject: ") != 0)
        {
            did = d[i];
            temp = 0;
        }
    }
    return did;
}
