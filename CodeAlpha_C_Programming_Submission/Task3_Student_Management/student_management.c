#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 60
#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[NAME_LEN];
    float marks;
} Student;

void addStudent(void);
void displayStudents(void);
void searchStudent(void);
void updateStudent(void);
void deleteStudent(void);

int main(void) {
    int choice;
    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add\n2. Delete\n3. Update\n4. Search\n5. Display\n0. Exit\n");
        printf("Choose: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayStudents(); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 0);
    return 0;
}

void addStudent(void) {
    FILE *fp=fopen(FILE_NAME,"ab");
    Student s;
    if(!fp){perror("File"); return;}
    printf("ID: "); scanf("%d",&s.id);
    printf("Name: "); scanf(" %59[^\n]",s.name);
    printf("Marks: "); scanf("%f",&s.marks);
    fwrite(&s,sizeof(Student),1,fp);
    fclose(fp);
    printf("Student added.\n");
}

void displayStudents(void) {
    FILE *fp=fopen(FILE_NAME,"rb");
    Student s;
    if(!fp){printf("No records found.\n"); return;}
    printf("\n%-8s %-30s %-8s\n","ID","Name","Marks");
    while(fread(&s,sizeof(Student),1,fp)==1)
        printf("%-8d %-30s %.2f\n",s.id,s.name,s.marks);
    fclose(fp);
}

void searchStudent(void) {
    FILE *fp=fopen(FILE_NAME,"rb");
    Student s; int id,found=0;
    if(!fp){printf("No records found.\n"); return;}
    printf("Enter ID: "); scanf("%d",&id);
    while(fread(&s,sizeof(Student),1,fp)==1) {
        if(s.id==id) {
            printf("ID: %d\nName: %s\nMarks: %.2f\n",s.id,s.name,s.marks);
            found=1; break;
        }
    }
    fclose(fp);
    if(!found) printf("Student not found.\n");
}

void updateStudent(void) {
    FILE *fp=fopen(FILE_NAME,"rb+");
    Student s; int id,found=0;
    if(!fp){printf("No records found.\n"); return;}
    printf("Enter ID to update: "); scanf("%d",&id);
    while(fread(&s,sizeof(Student),1,fp)==1) {
        if(s.id==id) {
            printf("New name: "); scanf(" %59[^\n]",s.name);
            printf("New marks: "); scanf("%f",&s.marks);
            fseek(fp,-(long)sizeof(Student),SEEK_CUR);
            fwrite(&s,sizeof(Student),1,fp);
            found=1; break;
        }
    }
    fclose(fp);
    printf(found ? "Student updated.\n" : "Student not found.\n");
}

void deleteStudent(void) {
    FILE *fp=fopen(FILE_NAME,"rb");
    FILE *tmp=fopen("students.tmp","wb");
    Student s; int id,found=0;
    if(!fp || !tmp){printf("No records found.\n"); if(fp)fclose(fp); if(tmp)fclose(tmp); return;}
    printf("Enter ID to delete: "); scanf("%d",&id);
    while(fread(&s,sizeof(Student),1,fp)==1) {
        if(s.id==id){found=1; continue;}
        fwrite(&s,sizeof(Student),1,tmp);
    }
    fclose(fp); fclose(tmp);
    remove(FILE_NAME);
    rename("students.tmp",FILE_NAME);
    printf(found ? "Student deleted.\n" : "Student not found.\n");
}
