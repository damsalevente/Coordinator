//Macros
#define MAX_LENGTH_CHAR 256
//Lists
typedef struct Task {
	char *name;
	char *type;
	int progress;    //how much work-unit needed to do
	int dependencies;
} Task;

typedef struct Worker {
	char *name;
	char *job;
	int performance;  //how much work can he do in one day
	//Task actualTask;  //the first element of the Task list will be a non-working status, thats how we know if a worker is free atm
	struct Worker *next;
}Worker;
//Functions

//Worker struct functions

void newWorker(Worker *llist, char *Name, char *Job, int Performance)
{
	while (llist->next != NULL)
		llist = llist->next;
	llist->next = (Worker *)malloc(sizeof(Worker));
	llist->next->name = Name;
	llist->next->job = Job;
	llist->next->performance = Performance;
	llist->next->next = NULL;
}
void fireWorker(Worker *llist, char *Name) //by name
{
	Worker *temp;
	temp = (Worker *)malloc(sizeof(Worker));
	if(llist->name==Name)
	{
		temp = llist->next;
		free(llist);
		llist = temp;
	}
	else
	{
		while (llist->next->name != Name)
		{
			llist = llist->next;
		}
		temp = llist->next->next;
		free(llist->next);
		llist->next = temp;
	}
}
void showWorkers(Worker *llist)
{
	while (llist->next != NULL)
	{
		if (llist->name == "NULL")
		{

		}
		printf("Name: %s\n", llist->name);
		printf("Job: %s\n", llist->job);
		printf("Performance:%d\n", llist->performance);
		printf("*------------------------------------*\n");
		llist = llist->next;
	}
	printf("Name: %s\n", llist->name);
	printf("Job: %s\n", llist->job);
	printf("Performance:%d\n", llist->performance);
}
int searchWorker(Worker *llist, char *sName)
{
	int retVal = -1;
	while (llist->next != NULL)
	{
		if (llist->next->name==sName)
		{
			retVal = 1;
												//return -1 or 1
		}
		else
			retVal = -1;
		llist = llist->next;
		
	}
	return retVal;
}