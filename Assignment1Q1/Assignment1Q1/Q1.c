/* CS261- Assignment 1 - Q.1*/
/* Name: Thomas Buteau
 * Date: 4-16-17
 * Solution description:
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *arr = malloc(sizeof(struct student) * 10);
	return arr;
     /*return the pointer*/
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	for (int i = 0; i < 10; i++)
	{
		students[i].score = rand() % 101;
		int unique = 1;
		do
		{
			unique = 1;
			students[i].id = rand() % 10 + 1;
			for (int j = 0; j < i; j++)
			{
				if (students[j].id == students[i].id)
				{
					unique = 0;
				}
			}
		} while (unique == 0);
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("%d      %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = students[0].score;
	int max = students[0].score;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		if (students[i].score < min)
		{
			min = students[i].score;
		}
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		sum += students[i].score;
	}

	printf("The minimum score is %d, the maximum score is %d, the average score is %d.\n", min, max, sum / 10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if (stud != 0)
	{
		free(stud);
		stud = 0;
	}
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
