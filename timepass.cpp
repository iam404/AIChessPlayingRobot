#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

int main()
{
	char *poin;
	int i,c,k,count,f,sum=0,count1=0;
	
	for (i=0;;i++)
	{
		f=0;
		count=0;
		poin = (char*)malloc(32);
		//f=(int)malloc(100);
		//sum=(int)malloc(1000);
		for (c=31;c>=0;c--)
		{
			k = i >> c;
 
	  if (k & 1)
      *(poin+count)=1;
	 else
    *(poin+count)=0;
	  f =f*10 + *(poin+count);
	  count++;
	 
		}
		//*(poin+count)='\0';
		//int num=  (int)poin;
		if ((f%19)==0)
		{		sum +=f;
			cout<<f<<endl;
			getchar();
			count1++;
		}

		if (count1 ==49)
		{
			cout<<sum<<endl;
			getchar();
			return 0;
		}
			
			//cout<<f<<endl;
	
	


	}
	getchar();
}
	
