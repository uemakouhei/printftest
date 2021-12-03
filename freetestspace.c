#include<stdio.h>
#include<unistd.h>
int main(void)
{
	write(1," ",5);
	write(1,"a",1);
}
