#include <stdio.h>

void main()
{
	/*
	0 - closed
	1 - open
	*/
	int state[100] = {0};
	int door, pass;

	for(pass = 0; pass < 100; pass++)
	{
		for(door = pass; door < 100; door += pass+1)
		{
			state[door] = !(state[door]);
		}
	}

	for(door = 0; door < 100; door++)
	{
		if(state[door])
			printf("Door %d is open\n", door+1);
	}
}