#include <stdio.h>// including stdio.h and string.h library
#include <string.h>

typedef enum
{
    F,
    T
} boolean;

typedef struct// creating the structure candidate
{
    char name[30];
    int age;
    int physics;
    int chemistry;
    int maths;
    int totalmarks;
    char ref[10];
    boolean shortlisted;

} candidate;
void swap(candidate *one, candidate *two) // swaping function
{
    candidate temp;
    temp = *one;
    *one = *two;
    *two = temp;
} // swap cleared

void sort_ref(candidate a[], int n) // sorting function with respect to refrence
{
    int i = 0;
    for (int j = 0; j < n && i < n; j++)
    {
        if (strcmp(a[j].ref, "excellent") == 0)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    for (int j = 0; j < n && i < n; j++)
    {
        if (strcmp(a[j].ref, "good") == 0)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    for (int j = 0; j < n && i < n; j++)
    {
        if (strcmp(a[j].ref, "poor") == 0)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }

} // working and sorting according to ref

int max_index(candidate a[],int start ,int arraysize)// finding index of max total marks
{
    int i, index, max;
    index=start;max=a[start].totalmarks;
    for(i=start;i<arraysize;i++)
    {
        if(a[i].totalmarks>max)
        {
            max=a[i].totalmarks;
            index=i;
        }
    }
    return index;
}

void sort_totalmarks(candidate a[],int n)//function which sort w.r.t totoal marks
{
    int j;
    for(int i=0;i<n;i++)
    {
        j=max_index(a,i,n);
        swap(&a[i],&a[j]);
    }
}


int main()
{
    int no_candi, no_select;
    scanf("%d%d", &no_candi, &no_select);
    candidate a[no_candi];
    for (int i = 0; i < no_candi; i++)// taking the input in the array
    {

        scanf("%s", a[i].name);
        scanf("%d", &a[i].age);
        scanf("%d", &a[i].physics);
        scanf("%d", &a[i].chemistry);
        scanf("%d", &a[i].maths);
        scanf("%s", a[i].ref); 

        a[i].totalmarks = 0;
        a[i].totalmarks = a[i].chemistry + a[i].physics + a[i].maths;

    
    }
    sort_ref(a, no_candi);//applying sort_ref function
    sort_totalmarks(a,no_candi);//applying sort_totalmarks function

    int number_select=0;
        for (int i = 0; i < no_select; i++)//for calculating the total no of candidates selected
        {
            if (strcmp(a[i].ref,"poor") != 0)
            {
                number_select+=1;
            }
        }
        //printing output
        if(number_select<no_select)
        {printf("Only %d candidates found\n", number_select);}
        printf("List of %d selected candidates\n",number_select);





    printf("Rank Name Age Total Marks Shortlisted\n");
    for (int i = 0; i < no_select; i++)
    {
        if (strcmp(a[i].ref, "poor") != 0)
        {
            printf("%d ", i + 1);
            printf("%s ", a[i].name);
            printf("%d ", a[i].age);
            printf("%d ", a[i].totalmarks);
            printf("Yes\n"); 
            
        }
    }
}
//sort acc to maths physics and chemistry also