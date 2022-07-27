#include <stdio.h>

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main()
{
	int red = get_r(00646464);
	printf("red: %d\n", red);
	int green = get_g(00646464);
	printf("green: %d\n", green);
	int blue = get_b(00646464);
	printf("blue: %d\n", blue);
	int trgb = create_trgb(00,64,64,64);
	printf("trgb: %d\n", trgb);
}


/* EOF */