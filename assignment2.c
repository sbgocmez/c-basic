#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int coloumnsize = 0;

void coloumn_setter(int coloumn)
{
	coloumnsize = coloumn;
}
void layout_printer(int **layout, int row_size, int coloumn_size)
{
	layout = (int **)malloc(sizeof(int) * row_size * coloumn_size);
	for (int k = 0; k < row_size; k++)
	{
		if (k > 0)
		{
			printf("%d", k);
		}
		else
		{
			printf(" ");
		}
		for (int j = 0; j < coloumn_size; j++)
		{
			if (k == 0)
			{
				if (layout[k][j] == 4)
				{
					printf("   A");
				}
				else if (layout[k][j] == 5)
				{
					printf("   B");
				}
				else if (layout[k][j] == 6)
				{
					printf("   C");
				}
				else if (layout[k][j] == 7)
				{
					printf("   D");
				}
				else if (layout[k][j] == 8)
				{
					printf("   E");
				}
				else if (layout[k][j] == 9)
				{
					printf("   F");
				}
				else if (layout[k][j] == 10)
				{
					printf("   G");
				}
				else if (layout[k][j] == 11)
				{
					printf("   H");
				}
				else if (layout[k][j] == 12)
				{
					printf("   I");
				}
				else if (layout[k][j] == 13)
				{
					printf("   J");
				}
				else if (layout[k][j] == 14)
				{
					printf("   K");
				}
				else if (layout[k][j] == 15)
				{
					printf("   L");
				}
				else if (layout[k][j] == 16)
				{
					printf("   M");
				}
				else if (layout[k][j] == 17)
				{
					printf("   N");
				}
				else if (layout[k][j] == 18)
				{
					printf("   O");
				}
				else if (layout[k][j] == 19)
				{
					printf("   P");
				}
				else if (layout[k][j] == 20)
				{
					printf("   Q");
				}
				else if (layout[k][j] == 22)
				{
					printf("   S");
				}
				else if (layout[k][j] == 23)
				{
					printf("   T");
				}
				else if (layout[k][j] == 21)
				{
					printf("   R");
				}
				else if (layout[k][j] == 1)
				{
					printf("   |   |");
				}
			}
			else if (k < 10)
			{
				if (layout[k][j] == 0)
				{
					printf("   -");
				}
				else if (layout[k][j] == 1)
				{
					printf("   |   |");
				}
				else if (layout[k][j] == 2)
				{
					printf("   X");
				}
				else if (layout[k][j] == 3)
				{
					printf("   +");
				}
			}
			else
			{
				if (j == 0)
				{
					if (layout[k][j] == 0)
					{
						printf("  -");
					}
					else if (layout[k][j] == 1)
					{
						printf("   |   |");
					}
					else if (layout[k][j] == 2)
					{
						printf("  X");
					}
					else if (layout[k][j] == 3)
					{
						printf("  +");
					}
				}
				else
				{
					if (layout[k][j] == 0)
					{
						printf("   -");
					}
					else if (layout[k][j] == 2)
					{
						printf("   X");
					}
					else if (layout[k][j] == 3)
					{
						printf("   +");
					}
					else if (layout[k][j] == 1)
					{
						printf("   |   |");
					}
				}
			}
		}
		printf("\n");
	}
}

int main()
{
	int rows = 0;
	int seats_per_row = 0;
	int aisles = 0;
	int coloumn = 0;

	printf("Number of rows:");
	scanf("%d", &rows);
	printf("Number of seats per row:");
	scanf("%d", &seats_per_row);
	printf("Number of aisles:");
	scanf("%d", &aisles);
	int *aisle = (int *)malloc(sizeof(int) * aisles);
	int row;
	row = rows + 1;
	coloumn = aisles + seats_per_row;
	coloumn_setter(coloumn);
	int n = 0;
	for (int i = 0; i < aisles; i++)
	{
		printf("Add aisle %d after seat:", i + 1);
		scanf("%d", &aisle[i]);
		aisle[i] += n;
		n += 1;
	}
	int **layout = (int **)malloc(sizeof(int) * row * coloumn);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coloumn; j++)
		{
			layout[i][j] = 0;
		}
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < aisles; j++)
		{
			layout[i][aisle[j]] = 1;
		}
	}
	int q = 4; //ABC... yazdırma kısmı
	for (int f = 0; f < coloumn; f++)
	{

		if (layout[0][f] == 0)
		{
			layout[0][f] = q;
			q++;
		}
	} //

	int passenger;
	layout_printer(layout, row, coloumn); // (buraya kadar kusursuz çalışıyor)uçak oturma planı
	double **scores = (double **)malloc(sizeof(double) * row * coloumn);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < coloumn; j++)
		{
			scores[i][j] = 0.0;
		}
	}
	while (passenger != -1)
	{
		int highesti;
		int highestj;
		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < coloumn; j++)
			{
				if (layout[i][j] == 3)
				{
					layout[i][j] = 2;
				}
			}
		}
		printf("Number of people in the reservation:");
		scanf("%d", &passenger);
		if (passenger == 0)
		{
			layout_printer(layout, row, coloumn);
		}
		else if (passenger == 1)
		{							//tek yolcu rezervasyonu durumu
			double dist = 0.000;	//formülü s(i,j) ile k(t,r) arasındaki mesafe = abs(i-t) + (abs(j-r))/2
			double adjdist = 0.000; //formülü 100 - 100^(1/dist)
			for (int k = 1; k < row; k++)
			{ //skorları  hesaplıyoruz
				for (int l = 0; l < coloumn; l++)
				{ //layout[k][l] nin skorunu hesaplıyoruz
					for (int i = 1; i < row; i++)
					{ //i. satırdaki
						for (int j = 0; j < coloumn; j++)
						{ //j. elemanın sebep olduğu skor;
							if (layout[i][j] == 2)
							{										  //önceden alınmış koltuklar sadece skoru etkiler
								dist = abs(k - i) + (abs(l - j)) / 2; //dist 0 çıkarsa sonsuz çıkıyor
								if (dist == 0)
								{ //dist 0 sa zaten 0 ekleyeceğiz ondan break yapıp çıktık
									break;
								}
								else
								{
									adjdist = 100 - pow(100, 1 / dist); //formulü uyguladık
								}
								scores[k][l] += adjdist; //çıkan sonucu layout[k][l] nin skoruna ekledik
							}
						}
					}
				}
			}

			double highest = -1; //en yüksek skora sahip olanı bulup rezerve edeceğimiz aşama
			for (int i = 1; i < row; i++)
			{ //skorlar eşitse o arraydeki eşit skordaki ilk elemanı seçmemiz lazım ondan dolayı burası böyle büyük eşittir değil sadece büyüktür.
				for (int j = 0; j < coloumn; j++)
				{
					if (scores[i][j] > highest && layout[i][j] == 0)
					{
						highest = scores[i][j];
						highesti = i; //i sini j sini belirledik
						highestj = j;
					}
				}
			}
			layout[highesti][highestj] = 3;		  //rezerve etmek
			layout_printer(layout, row, coloumn); //rezerve edilmiş halini printlemek
			for (int i = 0; i < row; i++)
			{ //skor kontrolleri
				for (int j = 0; j < coloumn; j++)
				{
					printf("%10.5f", scores[i][j]);
				}
				printf("\n");
			}
			for (int i = 0; i < row; i++)
			{ //skor arrayini 0 ladık ki bir dahakine kullanabilelim
				for (int j = 0; j < coloumn; j++)
				{
					scores[i][j] = 0.0;
				}
			}
		}
	}
	return EXIT_SUCCESS;
}
