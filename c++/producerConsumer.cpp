#include<bits/stdc++.h> 
#include<pthread.h> 
#include<semaphore.h> 
#include <unistd.h> 
using namespace std; 

// Declaration 
int r1,total_produced=0,total_consume=0; 

// Semaphore declaration 
sem_t notEmpty; 

// Producer Section 
void* produce(void *arg){ 
	while(1){ 
	cout<<"Producer produces item."<<endl; 
	cout<<"Total produced = "<<++total_produced<< 
		" Total consume = "<<total_consume*-1<<endl; 
	sem_post(¬Empty);	 
	sleep(rand()%100*0.01); 
	} 
} 

// Consumer Section 
void* consume(void *arg){ 
	while(1){ 
	sem_wait(¬Empty); 
	cout<<"Consumer consumes item."<<endl;	 
	cout<<"Total produced = "<<total_produced<< 
		" Total consume = "<<(--total_consume)*-1<<endl; 
	sleep(rand()%100*0.01); 
	}	 
} 

int main(int argv,char *argc[]){ 

	// thread declaration 
	pthread_t producer,consumer; 

	// Declaration of attribute...... 
	pthread_attr_t attr; 

	// semaphore initialization 
	sem_init(¬Empty,0,0); 

	// pthread_attr_t initialization 
	pthread_attr_init(&attr); 
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE); 

	// Creation of process 
	r1=pthread_create(&producer,&attr,produce,NULL); 
	if(r1){ 
	cout<<"Error in creating thread"<<endl; 
	exit(-1); 
	} 

	r1=pthread_create(&consumer,&attr,consume,NULL); 
	if(r1){ 
	cout<<"Error in creating thread"<<endl; 
	exit(-1); 
	} 

	// destroying the pthread_attr 
	pthread_attr_destroy(&attr); 

	// Joining the thread 
	r1=pthread_join(producer,NULL); 
	if(r1){ 
	cout<<"Error in joining thread"<<endl; 
	exit(-1); 
	} 

	r1=pthread_join(consumer,NULL); 
	if(r1){ 
	cout<<"Error in joining thread"<<endl; 
	exit(-1); 
	} 

	// Exiting thread 
	pthread_exit(NULL); 

	return 0; 
}
