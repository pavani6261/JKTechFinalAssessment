//Creating a file, writing and reading into the file with user defined functions and using structures
#include<stdio.h>
struct student{
    int id;
    char name[10];
    char course[10];
};
void main()
{
    char filename[20];
    FILE *fp;
    int n;
    struct student s[n];

    printf("Enter a file name to create\n");
    scanf("%s",&filename);
    fp = fopen(filename,"r+");
    OpenFile(fp);
    printf("Enter number of records\n");
    scanf("%d",&n);
    WriteStruct(n,s);  // calling the function to create structure data
    WriteFile(fp,n,s); //calling this function to write structure into the file
    ReadFile(fp,n,s);  //calling this function to read the content of file
}
void OpenFile(FILE *f)
{
    if(f == NULL)
    {
        printf("Failed to create file");
        exit(0);
    }
}
void WriteStruct(int n,struct student a[n])
{
    int i;
    printf("Enter student details:\n id\tname\tcourse\n");
    for(i=0;i<n;i++)
    {
        scanf("%d\t%s\t%s",&a[i].id,&a[i].name,&a[i].course);
    }
}
void WriteFile(FILE *f,int n,struct student a[n])
{
    int i;
    fprintf(f,"id\tname\tcourse\n");
    for(i=0;i<n;i++)
    {
        //fwrite(&a,sizeof(a),1,f);
        fprintf(f,"%d\t%s\t%s\n",a[i].id,a[i].name,a[i].course);
    }
    printf("added to file");
}
void ReadFile(FILE *f,int n,struct student a[n])
{
    int i;
    printf("records in file are:\n");
    printf("id\tname\tcourse\n");
    for(i=0;i<n;i++)
    {
        fscanf(f,"%d\t%s\t%d",&a[i].id,&a[i].name,&a[i].course);
        printf("%d\t",a[i].id);
        printf("%s\t",a[i].name);
        printf("%s\t",a[i].course);
        printf("\n");
    }
}
