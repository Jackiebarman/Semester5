/*num_threads.c*/
#include<stdio.h>
#include<omp.h>
int main(){
	//int tid;
#pragma omp parallel num_threads(7)
{
int tid=omp_get_thread_num();
printf("Hello world from thread=%d\n",tid);
}
}
