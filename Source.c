#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main(void) {
	//tools
	int inputListener=12;
	//Ezekbe olvasom be az elsõ elemeket
	char actName[50];
	char actJob[50];
	int actperf;
	////Ezekbe olvasom a taskot
	//char actTName[50];
	//char actRequiredJob[50];
	//int progress;
	//int dependencies[50];
	//---------------------
	Worker *worker;
	worker = (Worker*)malloc(sizeof(Worker));
	worker->name = "Damsa Levente";
	worker->job = "Vezeto";
	worker->next = NULL;
	worker->performance = 80000;

	//Címsor:
	while (inputListener != 5) 
	{
	printf("*********************************************************************\n");
	printf("*1:ADD WORKER|2:DELETE WORKER|3:LIST WORKERS|4:SEARCH BY NAME|5:EXIT*\n");
	printf("*********************************************************************\n");
	scanf("%d", &inputListener);
	
	switch (inputListener)
		{
		case 1:
			printf("You chosed ADD WORKER\n");
			printf("Add his name:\n");
			scanf("%s", actName);
			printf("Add his job at the office\n");
			scanf("%s", &actJob);
			printf("Add his performance:\n");
			scanf("%d", &actperf);
			newWorker(worker, actName, actJob, actperf);
			break;
		case 2:
			printf("You chosed DELETE WORKER. Please add his/her name:\n");
			scanf("%s", actName);
			fireWorker(worker, actName);
			break;
		case 3:
			printf("You asked for a list of workers\n");
			showWorkers(worker);
			break;
		case 4:
			printf("You chosed SEARCH BY NAME\n Please add his/her name:\n");
			scanf("%s", &actName);
			searchWorker(worker, actName);
			if (searchWorker(worker, actName) == 1)
			{
				printf("Success!");

			}
			else
				printf("Sorry, I cant find him/her");
			break;
				
		case 5:
			printf("Bye\n");
			break;
		default:
			printf("Sorry, I cannot understand that one");
		}
	}
	free(worker);
	return 0;
}