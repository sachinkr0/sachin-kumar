#include <stdio.h>          //header file for all I/O operations
#include <sys/types.h>     //header file for pid_t
#include <unistd.h>
#include <sys/wait.h>      //header file for wait function
int main()   //main function
{
int i, num;       //declaring variables
pid_t pid;       //declearing data type for  process

printf("Enter a number:\n");      //asking user to enter the number
scanf("%d",&num);      //it is reading the input entered by user

if(num<0)       //checking if number is not smaller than 0
printf("Enter a positive  number:\n");         //if number is smaller than 0 than  it will show message to enter positive number
else
{
  pid=fork();       //creating a new process which is child process
  if (pid==0)
{
  printf("Child process is running...\n\n");
  printf("Output: ");
  while(num>0)        //checking if number entered is greater than 0
{
  printf("%d"",",num);    // printing a integer values
  num=num/2;           //dividing the number entered by user  untill its 0. for eg if 8 is entered  then the out put will be 8,4,2,1
 }                        // it will divide  8 by 2  then this process will continue till its not zero

 printf("\n\nchild process is complete\n");      //printing the statement
 }
else
{
 printf("parent is waiting for child to complete.....\n");  //if  child process is still running it will show this message
 wait(NULL);     //waiting untill the process is complete
 printf("parent process is complete\n");      //after process completion prints the statement
      }
 }
 return 0;     //return after successful execution
}

