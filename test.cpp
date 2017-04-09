#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	
	for(int i=0;i<100;i++)
	{
		double r = ((double) rand() / (RAND_MAX));
		cout<<r<<"\n";
	}
	return 0;
}
