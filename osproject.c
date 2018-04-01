#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
int counter=0;						//for check the time quantum for all queues
float average_waiting_time=0,average_turnaround=0;    
int process_count=0;

struct Process{
    int burst_time,priority,process_id;
    int wait_time,end_time,b;
    struct Process* next;
};

struct Process* queue1=NULL;
struct Process* queue2=NULL;
struct Process* queue3=NULL;

void Queue1(int pid ,int burst,int prior){
	 struct Process* temp=(struct Process*)malloc(sizeof(struct Process));
            temp->process_id=pid;
            temp->burst_time=burst;
            temp->priority=prior;
            temp->wait_time=0;
            temp->end_time=0;
            temp->b=burst;
            temp->next=NULL;
            if(queue1==NULL)
            {
            queue1=temp;
            }
			else{
            struct Process* ptr=queue1;
            while(ptr->next!=NULL)
            {
               ptr=ptr->next;
             }
              ptr->next=temp;
             }
             process_count++;
	
}

//function for priority scheduling it will automatic arrange the process according their priority 
// by using the concept of priority queue.
void Queue2(int pid,int burst,int prior)
{
    struct Process* temp=(struct Process*)malloc(sizeof(struct Process));
    temp->burst_time=burst;
    temp->process_id=pid;
    temp->priority=prior;
    temp->wait_time=0;
    temp->end_time=0;
    temp->b=burst;
    temp->next=NULL;
    if(queue2==NULL)
    {
        queue2=temp;
    }
    else{
    struct Process* ptr=queue2;
        if(queue2->priority>prior)
        {
            temp->next=queue2;
            queue2=temp;

        }

        else{
            while(ptr->next!=NULL&&ptr->next->priority<prior)
            {
                ptr=ptr->next;
            }
            temp->next=ptr->next;
            ptr->next=temp;
        }
    }
    process_count++;
}
void Queue3(int pid ,int burst,int prior){
	 struct Process* temp=(struct Process*)malloc(sizeof(struct Process));
            temp->process_id=pid;
            temp->burst_time=burst;
            temp->priority=prior;
            temp->wait_time=0;
            temp->end_time=0;
            temp->b=burst;
            temp->next=NULL;
            if(queue3==NULL)
             {
              queue3=temp;
              }
            else{
              struct Process* ptr=queue3;
              while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=temp;
            }
            process_count++;
	
}
int isEmpty(struct Process* Queue)
{
    if(Queue==NULL)
        return 1;
    else 
		return 0;
}
int process_exhausted(struct Process* Queue)
{
    struct Process *ptr=Queue;
    if(isEmpty(Queue))
        return 1;
    else{
        while(ptr!=NULL)
        {
            if(ptr->burst_time!=0)
                return 0;
            ptr=ptr->next;
        }
    }
    return 1;
}

void Insert(int burst,int prior,int pid)
{
    struct Process* head=NULL;
    if(prior>=0&&prior<=6)
        Queue1(pid,burst,prior);
    else if(prior>=7&&prior<=13)
        Queue2(pid,burst,prior);
    else if(prior>=14&&prior<=20)
        Queue3(pid,burst,prior);
    else
    {
        printf("Priority must be in the given Range.\n");
        return;
    }
    
}

int main()
{
	printf("            ****This Program is for Mulitlevel Queue Scheduling*****\n\n");
    int limit,burst,prior,pid,arr;
    printf("\t Enter Total Number of Processes: ");
	scanf("%d", &limit);
	printf("\n\n");
	printf("Priority for Queue \n");
	printf("Queue 1 for Round Robin Scheduling                 Range 0-6 \n");  //queue one has range 0 to 6
	printf("Queue 2 for Priority Scheduling                    Range 7-12 \n"); //queue two has range 7 to 12
	printf("Queue 3 for First Come First Serve Scheduling      Range 13-19 \n"); // queue three has rannge  13 to 19
    while(limit--)
    {
        
        printf("\n\nEnter the process pid: ");
        scanf("%d",&pid);
        printf("Enter the burst time: ");
        scanf("%d",&burst);
        printf("Enter the priority: ");
        scanf("%d",&prior);
        Insert(burst,prior,pid);
        
    }
    
   /*while(!process_exhausted(queue1)||!process_exhausted(queue2)||!process_exhausted(queue3))
	{
	roundrobin_scheduling();
	priority_scheduling();
	FCFS();*/
}


