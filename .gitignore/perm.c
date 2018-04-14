#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int bt[20],p[20],pr[20],wt[20],tat[20],n,total_wt=0,total_tat=0,min,temp;
float avg_wt,avg_tat;
void sortbt()
{int i;
for( i=0;i<n;i++)
  {
	min=i;
	int j;
	for(j=i+1;j<n;j++)
	{
		if(bt[j]<bt[min])
		 {min=j;
		 }
	}
	temp=bt[i];
	bt[i]=bt[min];
	bt[min]=temp;
	
	temp=p[i];
	p[i]=p[min];
	p[min]=temp;
  }
}
//waiting time
void wat()
{int i;
for(i=1;i<n;i++)
  {  
	wt[i]=0;
	int j;
	for( j=0;j<i;j++)
	 {wt[i]+=bt[j];
	 
	 }
	 total_wt+=wt[i];
  } 

}
//turn around time
void turnat()
{int i;
for( i=0;i<n;i++)
  {
   tat[i]=bt[i]+wt[i];  //calculating turn around time
   total_tat+=tat[i];
 
  }
}
//creating an array of priority
void pr_array()
{int i;
	for( i=1;i<n;i++)
	  {
	  	pr[i]=1+wt[i]/bt[i];
	  }
}
//sorting accordind to priority
void pr_sort()
{int i;
for( i=1;i<n;i++)
  {
	min=i;
	int j; 
	for(j=i+1;j<n;j++)
	{
		if(pr[j]<pr[min])
		 {min=j;
		 }
	}
	temp=bt[i];
	bt[i]=bt[min];
	bt[min]=temp;
	
	temp=p[i];
	p[i]=p[min];
	p[min]=temp;
  }
	
}

