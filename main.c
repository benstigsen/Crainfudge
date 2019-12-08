#include <stdio.h>

#define CELL_AMOUNT 30000

int main()
{
	char input[] = ">++++++++[-<++++++++>]<+[->+>+>+<<<]>>+>++<<[.>]!";
	int length = sizeof(input);

	unsigned char cells[CELL_AMOUNT];
	unsigned int index = 0;

	for (unsigned int i = 0; i < length; ++i)
	{
		if 		(input[i] == '+') {cells[index] = cells[index] < 255 ? cells[index] + 1 : 0;}
		else if (input[i] == '-') {cells[index] = cells[index] > 0 	 ? cells[index] - 1 : 255;}
		
		else if (input[i] == '>') {index += index < CELL_AMOUNT;}
		else if (input[i] == '<') {index -= index > 0;}
		
		else if (input[i] == '.') {putchar(cells[index]);}
		else if (input[i] == ',') {scanf("%c", &cells[index]);}
		
		else if (input[i] == '[')
		{
			if 	(cells[index] == 0)
			{
				int depth = 0;
				for (unsigned int j = i; j < length; ++j)
				{
					if 		(input[j] == '[') {++depth;}
					else if (input[j] == ']') {--depth;}

					if 		(depth == 0) {i = j; break;}
				}
			}
		}
		else if (input[i] == ']')
		{
			if 	(cells[index] > 0)
			{
				int depth = 0;
				for (unsigned int j = i; j > 0; --j)
				{
					if 		(input[j] == ']') {++depth;}
					else if (input[j] == '[') {--depth;}

					if 		(depth == 0) {i = j; break;}
				}
			}
		}
		// Debug character (print cells)
		else if (input[i] == '!') 
		{
			printf("\n");
			for (int j = 0; j < index + 5; ++j) 
			{
				printf("%03d, ", cells[j]);
			}
			printf("\n%*s^\n", (index * 5) + 1, "");
		}
	}

	return 0;
}
