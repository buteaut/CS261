/*
 * CS 261 Assignment 5
 * Name: Thomas Buteau
 * Date: 5-28-17
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	const int MAX_STRING_SIZE = 256;
	// load to-do list from a file
	if (command == 'l')
	{
		char *name = malloc(sizeof(char) * MAX_STRING_SIZE);
		printf("Enter the filename: \n");
		fgets(name, MAX_STRING_SIZE, stdin);
		if (name[strlen(name) - 1] == '\n')
		{
			name[strlen(name) - 1] = 0;
		}
		FILE *readFile = fopen(name, "r");
		listLoad(list, readFile);
		fclose(readFile);
		printf("%s opened. \n", name);
		free(name);
	}

	// save to-do list to a file
	else if (command == 's')
	{
		char *name = malloc(sizeof(char) * MAX_STRING_SIZE);
		printf("Enter the filename: \n");
		fgets(name, MAX_STRING_SIZE, stdin);
		FILE *writeFile = fopen(name, "w");
		listSave(list, writeFile);
		fclose(writeFile);
		printf("%s saved. \n", name);
		free(name);
	}

	// add a new task
	else if (command == 'a')
	{
		char *name = malloc(sizeof(char) * MAX_STRING_SIZE);
		printf("Please enter the task description: \n");
		fgets(name, MAX_STRING_SIZE, stdin);
		int priority;
		printf("Please enter the task priority (0-999): \n");
		scanf("%i", &priority);
		dyHeapAdd(list, taskNew(priority, name), taskCompare);
		printf("The task %s has been added to your to-do list. \n", name);
	}

	// get the first task
	else if (command == 'g')
	{
		if (dySize(list) == 0)
		{
			printf("Your to-do list is empty.");
		}
		else
		{
			printf("Your first task is: "); 
			taskPrint(dyHeapGetMin(list));
			printf("\n");
		}
	}

	// remove the first task
	else if (command == 'r')
	{
		if (dySize(list) == 0)
		{
			printf("Your to-do list is empty.");
		}
		else
		{
			printf("Your first task ");
			taskPrint(dyHeapGetMin(list));
			printf(" has been removed. \n");
			dyHeapRemoveMin(list, taskCompare);
		}
	}

	// print the list
	else if (command == 'p')
	{
		listPrint(list);
	}
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
	for (int i = 0; i < dySize(list); i++)
	{
		taskDelete(dyGet(list, i));
	}
    dyDelete(list);
	printf("Bye.");
    return 0;
}
