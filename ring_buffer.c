#include <stdio.h>

int QUEUE_EMPTY (char * queue)
{
	if (q_head == q_tail)
		return 1;
	else return 0;
}

int QUEUE_FULL (char * queue)
{
	if (q_head == q_tail + 1)
		return 1;
	else return 0;
}

void ENQUEUE (char * queue,char x)
{
	if (QUEUE_FULL (queue))
		perror ("overflow");
	else
	{
		queue [q_tail] = x;
		if (q_tail == q_length)
			q_tail = 1;
		else q_tail = q_tail + 1;
	}
}

int DEQUEUE (char * queue)
{
	char x;
	if (QUEUE_EMPTY (queue))
			perror ("underflow");
	else
	{
		x = queue [q_head];
		if (q_head == q_length)
				q_head = 1;
		else q_head = q_head + 1;
		return x;
	}
}
