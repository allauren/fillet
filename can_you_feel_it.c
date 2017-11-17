#include <stdio.h>
#include <string.h>

void	print_bit(unsigned short *data, int size)
{
	int		i;
	int		j;
	char	str[20];

	bzero(str, sizeof(str));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16)
		{
			str[j] = (data[i] & (1 << j)) ? '1': '0';
			j++;
		}
		printf("%s\n", str);
		i++;
	}
}
/*
int	main()
{
	int					i;
	unsigned	long	*yo;
	unsigned	long	yo2;
	unsigned	short	map[16] = {
									0b1111111111111110,
									0b1111111111111110,
									0b1111111111111110,
									0b1111100001111110,
									0b1110000000011110,
									0b1100000000000110,
									0b0000000000000000,
									0b0000000100000000,
									0b0000001111000000,
									0b0000111111100000,
									0b0001111111111000,
									0b1111111111111110,
									0b1111111011111110,
									0b1111111000111110,
									0b1111111000000000,
									0b1111100000000000,
									};

	double	lola = 3.14159265359;
	yo2 = *((unsigned long*)(&lola));
	print_bit((unsigned short*)&yo2, 4);
*/
/*
	print_bit(map, 16);
	printf("\n\n\n\n");
	i = 0;
	while (i < 12)
	{
		yo = ((unsigned long*)(map + i));
	//	*yo |= 1 << 0 | 1 << 16 | 1ul << 32 | 1ul << 48;
		yo2 = *yo;
		yo2 |= 1 << 0 | 1 << 16 | 1ul << 32 | 1ul << 48;
		*(unsigned long*)(map + i) = yo2;
		print_bit(map + i, 4);
		printf("\n\n---------------\n");
		i++;
	}

}*/
