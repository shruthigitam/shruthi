#include<stdio.h>
#include<ctype.h>
int main()
{
	char str[20];
	int state,i=1;
	printf("Enter the string:");
	scanf("%s",str);
	if(isalpha(str[0]))
	   state=1;
	else if(isdigit(str[0]))
	   state=2;
	else
	   state=10;
	
	while(str[i]!='\0')
	{
		switch(state)
		{
			case 1:if(isalpha(str[i])||isdigit(str[i]))
			    	  state=1;
			       else if(str[i]=='(')
			       	  state=3;
			       else if(str[i]=='[')
			          state=4;
			       else
			          state=2;
			       break;
			
			case 3:if(str[i]==')'&&str[i+1]=='\0')
			       	  state=5;
			       else
			          state=2;
			       break;
			       
			case 4:if(isdigit(str[i]))
			          state=4;
			       else if(str[i]==']'&&str[i+1]=='\0')
			    	  state=6;
			       else
			           state=2;
			       break;
		}
		i++;
		if(state==2)
		  break;
	}
	printf("%s ",str);
	if(state==1)
		printf("Input  is a variable.");
	
	else if(state==5)
		printf("Input  is a function");
	
	else if(state==6)
		printf("Input is a array");
	
	else
		printf("Input is not an identifier");
}
