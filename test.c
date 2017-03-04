#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024

typedef struct 
{
	char data_buffer[5000][1024];

} DATA;

int FileSIze_finder (char * File_Path)
{
	
	FILE * Data_File;

	Data_File = fopen (File_Path, "rb");

	if (Data_File == NULL) 
	{
		perror ("Failed to open the file\n");
	} 
	else 
	{
		printf ("File is opened\n");
	}

	//Get file length
	fseek (Data_File, 0, SEEK_END);
	unsigned long filelength = ftell(Data_File);
	printf ("File size: %ld bytes\n", filelength );
	//fseek(Data_File, 0, SEEK_SET);

  	return filelength;
}

int main (int argc, char *argv[])
{
	int i, j, r;
	FILE * file_handler;
	DATA x;
	
	char * file_path = argv[1];
	file_handler = fopen(file_path, "rb");

	if (file_handler == NULL) 
	{
		perror ("Failed to open the file\n");
	} 
	else 
	{
		printf ("File is opened\n");
	}
	
	int	file_size = FileSIze_finder (file_path);

	int chunks = file_size / CHUNK_SIZE ;
	int mod_num = file_size % CHUNK_SIZE ;
	if (mod_num > 0) 
		chunks = chunks + 1;

	/*
	char ** data_buffer;
	data_buffer = (char **) calloc (chunks, sizeof (char *));
	for (i = 0; i < chunks; i++)
		data_buffer[i] = (char *) calloc (CHUNK_SIZE, sizeof (char));
	*/
	//char data_buffer[5000][1024];
	for (i = 0; i < chunks; i++)
	{	
		r = fread(x.data_buffer[i], file_size, sizeof(char), file_handler);
		if (r == 0)
		{
			perror("Error reading the file !!\n");
		}
	}

	fclose(file_handler);
	
	for (i = 0; i < chunks; i++)
	{
		for (j = 0; j < CHUNK_SIZE; j++)
			printf ("%x", x.data_buffer[i][j]);
			printf ("\n");
		
	}

	return 1;
}





