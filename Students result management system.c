#include<stdio.h>
#include<string.h>

struct card
{
    char name[50];
    char id[20];
    char dept[10];
    int marks[5];
    int total;
    float average;
    char grade[3];

};

   struct card students[100];

   struct card* searchID(int n, struct card s[], char *search_id, int i) {
    if (i >= n) {

        return NULL;
    }

    if (strcmp(s[i].id, search_id) == 0) {

        return &s[i];
    }
    return searchID(n, s, search_id, i + 1);
}
int main(void)
{
    printf("\n\t\t\t*-*-*-*-*-*-STUDENT RESULTS MANAGEMENT SYSTEM-*-*-*-*-*-*");
    printf("\n");
    printf("\n-------------------START-------------------\n");
    int choice;
    int i; //for loop counter of marks
    struct card s;
    int count; //to check how many students are currently available
    count = 0;
    int j; //for loop counter of students

    do
    {
    printf("1.  Add Student\n");
    printf("2.  Display All students\n");
    printf("3.  Update Student Marks\n");
    printf("4.  Search Student By ID\n");
    printf("5.  Delete Record\n");
    printf("6.  Average Marks And Display\n");
    printf("7.  Subject Wise Marks\n");
    printf("8.  Generate Report Card\n");
    printf("9.  Class Statistics\n");
    printf("10. Save Records To File\n");
    printf("11. Load Records From File\n");
    printf("12. EXIT\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        if(count >= 100)
        {
            printf("\nStudent list is full!\n");
        }
        else
        {
        getchar(); //to consume extra \n
        printf("\nEnter Student Name: ");
        gets(s.name);

        printf("\nEnter Student ID: ");
        gets(s.id);

        printf("\nEnter department: ");
        gets(s.dept);

        printf("\nEnter the marks of 5 Subjects: ");

        for(i=0; i<5; i++) //to insert the marks in array
        {
            scanf("%d", &s.marks[i]);
        }
         printf("\nSubject 1: %d", s.marks[0]);
         printf("\nSubject 2: %d", s.marks[1]);
         printf("\nSubject 3: %d", s.marks[2]);
         printf("\nSubject 4: %d", s.marks[3]);
         printf("\nSubject 5: %d", s.marks[4]);
         printf("\n");

         int total;
         total = s.marks[0]+s.marks[1]+s.marks[2]+s.marks[3]+s.marks[4];
         printf("\nTotal: %d", total);
         float avg;
         avg = total/5.0; //taking 5.0 because avg is a float number
         printf("\nAverage: %.2f", avg);

         s.total = total;
         s.average = avg;
         //only taking the lower limit because avg can be decimal number
         if(avg >= 80)
         {
             printf("\nGrade: A*");
             strcpy(s.grade, "A*");
         }
         else if(avg >= 75)
         {
             printf("\nGrade: A");
             strcpy(s.grade, "A");
         }
         else if(avg >= 70)
         {
             printf("\nGrade: A-");
             strcpy(s.grade, "A-");
         }
         else if(avg >= 65)
         {
             printf("\nGrade: B+");
             strcpy(s.grade, "B+");
         }
         else if(avg >= 60)
         {
             printf("\nGrade: B");
             strcpy(s.grade, "B");
         }
         else if(avg >= 55)
         {
             printf("\nGrade: B-");
             strcpy(s.grade, "B-");
         }
         else if(avg >= 50)
         {
             printf("\nGrade: C+");
             strcpy(s.grade, "C+");
         }
         else if(avg >= 45)
         {
             printf("\nGrade: C");
             strcpy(s.grade, "C");
         }
         else  if(avg >= 40)
         {
             printf("\nGrade: D");
             strcpy(s.grade, "D");
         }
         else{
             printf("\nFailed!");
             strcpy(s.grade, "F");
         }

         students[count] = s;
         count++;
         printf("\n\n");
        }
    }
    else if(choice == 2)
    {
        printf("\n-----------------Displaying All Students-----------------\n");
        if(count == 0)
        {
            printf("\nNo Students are found!\n");
        }
        else{
            printf("\n");
            printf("ID\tName\t\tDepartment\tTotal\tAverage\tGrade\n");
            printf("----------------------------------------------------------------\n");
            for(j = 0; j < count; j++)
            {
                 printf("%s\t", students[j].id);
                 printf("%-15s\t", students[j].name);
                 printf("%-10s\t", students[j].dept);
                 printf("%d\t", students[j].total);
                 printf("%.2f\t", students[j].average);
                 printf("%s\n", students[j].grade);
                 printf("\n");
            }
        }
    }
     else if (choice == 3)
    {
        printf("\n-----------Update Student Marks-----------\n");

        if(count == 0)
        {
            printf("\nNo students are found!\n");
        }
        else
        {
            char search_id[20];
            getchar(); //consume leftover newline

            printf("\nEnter Student ID to update: ");
            gets(search_id);

            struct card *ptr = searchID(count, students, search_id, 0);

            if(ptr != NULL)
            {
                printf("\nStudent Found! Enter new marks for 5 Subjects: ");
                for(i = 0; i < 5; i++)
                {
                    scanf("%d", &(*ptr).marks[i]);
                }

                int total;
                total = (*ptr).marks[0]+(*ptr).marks[1]+(*ptr).marks[2]+(*ptr).marks[3]+(*ptr).marks[4];
                float avg;
                avg = total/5.0;

                (*ptr).total = total;
                (*ptr).average = avg;

                if(avg >= 80)
                {
                    strcpy((*ptr).grade, "A");
                }
                else if(avg >= 75)
                {
                    strcpy((*ptr).grade, "A");
                }
                else if(avg >= 70)
                {
                    strcpy((*ptr).grade, "A-");
                }
                else if(avg >= 65)
                {
                    strcpy((*ptr).grade, "B+");
                }
                else if(avg >= 60)
                {
                    strcpy((*ptr).grade, "B");
                }
                else if(avg >= 55)
                {
                    strcpy((*ptr).grade, "B-");
                }
                else if(avg >= 50)
                {
                    strcpy((*ptr).grade, "C+");
                }
                else if(avg >= 45)
                {
                    strcpy((*ptr).grade, "C");
                }
                else if(avg >= 40)
                {
                    strcpy((*ptr).grade, "D");
                }
                else
                {
                    strcpy((*ptr).grade, "F");
                }

                printf("\nTotal: %d | Average: %.2f | Grade: %s\n", (*ptr).total, (*ptr).average, (*ptr).grade);
            }
            else
            {
                printf("\nStudent Not Found!\n");
            }
        }
    }
        else if(choice == 4)
    {
        printf("\n-----------Search ID-----------\n");
        if(count == 0)
        {
            printf("\nNo students are found!\n");
        }
        else
        {
            char search_id[20];
            getchar(); //consume leftover newline
            printf("\nEnter Student ID to search: ");
            gets(search_id);

            struct card *ptr = searchID(count, students, search_id, 0);

            if(ptr != NULL)
            {
                printf("\nStudent Found!\n");
                printf("\nID: %s", (*ptr).id);
                printf("\nName: %s", (*ptr).name);
                printf("\nDepartment: %s", (*ptr).dept);
                printf("\nMarks: ");
                for(i = 0; i < 5; i++)
                {
                    printf("%d ", (*ptr).marks[i]);
                }
                printf("\nTotal: %d | Average: %.2f | Grade: %s\n", (*ptr).total, (*ptr).average, (*ptr).grade);
            }
            else
            {
                printf("\nStudent Not Found!\n");
            }
        }
    }
    else if(choice == 5)
    {
        printf("\n----------------Delete Record----------------\n");

        if(count == 0)
        {
            printf("\nNo Students Found!\n");
        }
        else
        {
            char search_id[20];
            getchar(); //consume leftover newline
            printf("\nEnter Student ID to delete: ");
            gets(search_id);

            struct card *ptr = searchID(count, students, search_id, 0);
            if(ptr != NULL)
            {
                int index = ptr - students;
                for(i = index; i < count-1; i++)
                {
                    students[i] = students[i + 1];
                }
                count--;
                printf("\nStudent deleted successfully!\n\n");
            }
            else
            {
                printf("\nStudent Not Found!\n\n");
            }


        }
    }
   else if(choice == 6)
{
    printf("\n---------------Average Marks & Display---------------\n");
    if(count == 0)
    {
        printf("\nNo students are found!\n");
    }
    else
    {
       int total = 0;
       float avg;

       for(j = 0; j < count; j++)
        {
            total = total + students[j].total;
            printf("\nID: %s, Name: %s, Average: %.2f, Grade: %s\n", students[j].id, students[j].name, students[j].average, students[j].grade);
        }

        avg = total/(float)count;
        printf("\nClass Average (based on %d students): %.2f\n", count, avg);
    }
    printf("\n");
}
    else if(choice == 7)
    {
        printf("\n-----------SUBJECT-WISE MARKS-----------\n");

        if(count == 0)
      {
        printf("\nNo students are found!\n");
      }
        else
      {
        for(i = 0; i < count; i++)
        {
            printf("\nID: %s", students[i].id);
            printf("\nName: %s", students[i].name);

        for(j = 0; j<5; j++)
        {
            printf("\nSubject %d Marks: %d", j+1, students[i].marks[j]);
        }
        printf("\n\n");
      }
}
}
else if(choice == 8)
    {
       printf("\n--------------------Report Card--------------------\n");
       if(count == 0)
        {
            printf("\nNo students are found!\n");
        }
        else
        {
            char search_id[20];
            getchar(); //consume leftover newline
            printf("\nEnter Student ID to create a Report Card: ");
            gets(search_id);
            struct card *ptr = searchID(count, students, search_id, 0);
            if(ptr != NULL)
            {
               printf("\nStudent Found!\n");
               printf("\nID: %s", (*ptr).id);
               printf("\nName: %s", (*ptr).name);
               printf("\nDepartment: %s", (*ptr).dept);
               printf("\nMarks: ");

               for(i = 0; i < 5; i++)
                {
                    printf("%d ", (*ptr).marks[i]);
                }
                printf("\nTotal: %d | Average: %.2f | Grade: %s\n", (*ptr).total, (*ptr).average, (*ptr).grade);
            }

        }printf("\n");
    }

    else if(choice == 9)
    {
        if(count == 0)
        {
            printf("\nNo students are found!\n");
        }
        printf("\n----------------------Class Statistics----------------------\n");
        int pass;
        pass = 0;
        int fail;
        fail = 0;
        int topper;
        topper = 0;
        float totalAvg;
        totalAvg = 0;

        for(j = 0; j < count; j++)
        {
            totalAvg = students[j].average + totalAvg;

            if(students[j].average >= 40)
            {
                pass++;
            }
            else{fail++;}

            if(students[j].average >= students[topper].average)
            {
                topper = j;
            }
        }
        float classAvg = students[j].average/count;
        printf("\nTotal Students: %d", count);
        printf("\nClass Average: %.2f", totalAvg);
        printf("\nPass: %d", pass);
        printf("\nFail: %d", fail);
        printf("\nTopper: %s (ID: %s, Average: %.2f)\n", students[topper].name, students[topper].id, students[topper].average);
        printf("\n");
    }
    else if(choice == 10)
{
    printf("\n---------------Save Records To File---------------\n");
    if(count == 0)
    {
        printf("\nNo Students are found!\n");
    }
    else
{
    FILE *fp;
    fp = fopen("Students.data","wb");

    if(fp == NULL)
    {
        printf("\nERROR! CANNOT OPEN FILE!\n");
    }
    else
{
    fwrite(&count,sizeof(int),1,fp); //to store current students
    fwrite(students,sizeof(struct card),count,fp); //to store all records

    fclose(fp);
    printf("\n%d Record saved successfully!\n",count);
}
}
printf("\n");

}
else if(choice == 11)
{
    printf("\n-----------Load Records From File------------\n");

    FILE *fp;
    fp = fopen("Students.data","wb");

    if(fp == NULL)
    {
        printf("\nNO SAVE FILE FOUND\n");

    }
    else
    {
        int fullCount;
        fread(&fullCount,sizeof(int),1,fp);

     if(fullCount>100)
     {
         printf("\nFILES ARE TOO LARGE OR CORRUPTED!\n");

     }
     else
     {
         fread(students,sizeof(struct card),fullCount,fp);

         if(fp == NULL)
         {
             printf("\nNO FILES FOUND!\n");
         }
         else
         {
             int fullCount;
             fread(&fullCount,sizeof(int),1,fp);

             if(fullCount > 100)
       {
           printf("\nFILES ARE TOO LARGE OR CORRUPTED!\n");

       }
       else
       {
           fread(students,sizeof(struct card),fullCount,fp);
           count = fullCount; //replacing current records with loaded ones

           printf("\n%d Record saved successfully!\n",count);
       }
       fclose(fp);

         }
         printf("\n");

     }

    }
    }

    else
    {
        printf("\n-----------EXIT-------------\n");
    }

    }while(choice != 12);

return 0;
}
