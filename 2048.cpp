//GAME 2048
//author: Artyom Simankov (Fantomka) 
//version: 1.6

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 4

void rules()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /*Getting out of descriptor*/
	system("color F0");
	printf("you need to add numbers\n");
	printf("equal to each other with the keys w a s d \n");
	printf("(use the English keyboard)\n");
	getch();
	SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15)); 
}



void Print_matrix(int Matrix[N][N], int &score)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /*Getting out of descriptor*/
	printf("%c", 201);      
	for (int l = 0; l < N-1; l++)                 //PRINT TO N-1 ARRAYS
	 	printf("%c%c%c%c%c", 205,205,205,205,209);
	printf("%c%c%c%c%c\n", 205,205,205, 205, 187);
	
 	for (int i=0; i<N-1; i++)
 	{
		 	printf("%c", 186);
	  		for (int j=0; j<N; j++)
	  		{
	  			switch(Matrix[i][j])
	  			{
	  				case 2   :SetConsoleTextAttribute(hConsole, (WORD) ((2  << 4) | 0)); break;  //
	  		 		case 4   :SetConsoleTextAttribute(hConsole, (WORD) ((13 << 4) | 2)); break;  //
	  				case 8   :SetConsoleTextAttribute(hConsole, (WORD) ((1  << 4) | 13));break;  //
	  				case 16  :SetConsoleTextAttribute(hConsole, (WORD) ((3  << 4) | 1)); break;  //
	  				case 32  :SetConsoleTextAttribute(hConsole, (WORD) ((6  << 4) | 8)); break;  // 
	  				case 64  :SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 14));break;  //    color
	  				case 128 :SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 6)); break;  //     of
	  				case 256 :SetConsoleTextAttribute(hConsole, (WORD) ((4  << 4) | 12));break;  //    numbers
					case 512 :SetConsoleTextAttribute(hConsole, (WORD) ((8  << 4) | 4)); break;  //
					case 1024:SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 2)); break;  //
					case 2048:SetConsoleTextAttribute(hConsole, (WORD) ((2  << 4) | 14)); break;  //
					case 4096:SetConsoleTextAttribute(hConsole, (WORD) ((6  << 4) | 8)); break;  //
				}
				
	  			if (j == N-1)
				{
	   				printf("%4d", Matrix[i][j]);
	   				SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
	   				printf("%c\n", 186);
	   		    }	
	   			else
	   			{
	   				printf("%4d", Matrix[i][j]);
	   				SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
	   				printf("%c", 179);
				}	
	 		}
	 		
	 		
	 		
	 		printf("%c", 199);
	 		for (int l = 0; l < N; l++)
			 	{
	 				if (l == N-1)
	 					printf("%c%c%c%c", 196,196,196,196);
	 				else
	 					printf("%c%c%c%c%c", 196,196,196,196,197);
			 	}
			printf("%c\n", 182); 	
 	}
 	printf("%c", 186);
	for (int j=0; j<N; j++)                       //PRINT  N-1 ARRAY
	{
		switch(Matrix[N-1][j])
	  	{
	  			case 2  :SetConsoleTextAttribute(hConsole, (WORD) ((2  << 4) | 0)); break;  //
	  			case 4  :SetConsoleTextAttribute(hConsole, (WORD) ((13 << 4) | 2)); break;  //
	  			case 8  :SetConsoleTextAttribute(hConsole, (WORD) ((1  << 4) | 13));break;  //
	  			case 16 :SetConsoleTextAttribute(hConsole, (WORD) ((3  << 4) | 1)); break;  //
	  			case 32 :SetConsoleTextAttribute(hConsole, (WORD) ((6  << 4) | 2)); break;  // 
	  			case 64 :SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 14));break;  //
	  			case 128:SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 6)); break;  //
	  			case 256:SetConsoleTextAttribute(hConsole, (WORD) ((4  << 4) | 12));break;  //
				case 512:SetConsoleTextAttribute(hConsole, (WORD) ((8  << 4) | 4));break;  //	
		}
		
	  	if (j == N-1)
		{
	   		printf("%4d", Matrix[N-1][j]);
	   		SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
	   	}	
	   	else
	   	{
	   		printf("%4d", Matrix[N-1][j]);
	   		SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
	   		printf("%c", 179);
		}
	}
	printf("%c\n", 186);
	
	printf("%c", 200);
	for (int l = 0; l < N-1; l++)
	 	printf("%c%c%c%c%c", 205,205,205,205,207);
	printf("%c%c%c%c%c\n", 205,205,205, 205, 188);
	
	printf("youre score: %d \n", score);
	 		
}



int First_Generation(int matr[N][N])
{
	int i=0, j=0;
	srand(time(NULL));
	
	i = rand() % N;
	j = rand() % N; 
	matr[i][j] = 2;
	
	i = rand() % N;
	j = rand() % N; 
	matr[i][j]= 4 /(1 + rand() % 2);
	
	
	return matr[N][N];
}

int Generation(int matr[N][N])
{
	bool gen = true;
	srand(time(NULL));
	int i = 0, j = 0;
	while (gen)
	{
		
		i = rand() % N;
		j = rand() % N; 
	
		if (matr[i][j] == 0)
		{
			matr[i][j]= 4 /(1 + rand() % 2);  //random generation in every itaration 2 or 4
			gen = false;
		}
	}

	return matr[N][N];
}

int Movement(int matr[N][N], char arr, int &score)
{
	switch(arr)
	{
//=================MOVE W======================================		
		case 'W':
		case 'w':
		case 'Ö':
		case 'ö':	
			for(int i = 0; i < N; i++)
			{	
				for (int j = 0; j < N; j++)
				{
					if ((matr[i][j] != 0) && (i != 0))
					{
						for (int i1 = i-1; i1 >= 0; i1--)
						{
							if (matr[i1][j] != 0 )
							{
								if (matr[i][j] / matr[i1][j] == 1)
								{
									matr[i1][j] *= 2;
									score += matr[i1][j];
									matr[i][j]  = 0;
									break;
								}
								else
								{
									if(i1+1 != i)
									{
										matr[i1+1][j] = matr[i][j];
										matr[i][j] = 0;	
										break;
									}
									break;	
								}	
							}
							else
							{
								if (i1 == 0)
								{
									matr[i1][j] = matr[i][j];
									matr[i][j] = 0;
									break;
								}
							}
						}
					}
				}
			}
		
		break;
//=================/MOVE W======================================


//=================MOVE S======================================				
		case 'S':
		case 's':
		case 'Û':
		case 'û':
			for(int i = N-1; i >= 0; i--)
			{	
				for (int j = N-1; j >= 0; j--)
				{
					if ((matr[i][j] != 0) && (i != N-1))
					{
						for (int i1 = i+1; i1 < N; i1++)
						{
							if (matr[i1][j] != 0 )
							{
								if (matr[i][j] / matr[i1][j] == 1)
								{
									matr[i1][j] *= 2;
									score += matr[i1][j];
									matr[i][j]  = 0;
									break;
								}
								else
								{
									if(i1-1 != i)
									{
										matr[i1-1][j] = matr[i][j];
										
										matr[i][j] = 0;	
										break;
									}
									break;	
								}	
							}
							else
							{
								if (i1 == N-1)
								{
									matr[i1][j] = matr[i][j];
									matr[i][j] = 0;
									break;
								}
							}
						}
					}
				}
			}
		
		break;
//=================/MOVE S======================================

			
//=================MOVE D======================================			
		case 'D':
		case 'd':
		case 'À':
		case 'à':
			for(int j = N-1; j >= 0; j--)
			{	
				for (int i = 0; i < N; i++)
				{
					if ((matr[i][j] != 0) && (j != N-1))
					{
						for (int j1 = j+1; j1 < N; j1++)
						{
							if (matr[i][j1] != 0 )
							{
								if (matr[i][j] / matr[i][j1] == 1)
								{
									matr[i][j1] *= 2;
									score += matr[i][j1];
									matr[i][j]  = 0;
									break;
								}
								else
								{
									if(j1-1 != j)
									{
										matr[i][j1-1] = matr[i][j];
										matr[i][j] = 0;	
										break;
									}
									break;	
								}	
							}
							else
							{
								if (j1 == N-1)
								{
									matr[i][j1] = matr[i][j];
									matr[i][j] = 0;
									break;
								}
							}
						}
					}
				}
			}
		
		break;
//=================/MOVE D======================================


//=================MOVE A======================================				
		case 'A':
		case 'a':
		case 'Ô':
		case 'ô':
			for(int j = 0; j < N; j++)
			{	
				for (int i = N-1; i >= 0; i--)
				{
					if ((matr[i][j] != 0) && (j != 0))
					{
						for (int j1 = j-1; j1 >= 0; j1--)
						{
							if (matr[i][j1] != 0 )
							{
								if (matr[i][j] / matr[i][j1] == 1)
								{
									matr[i][j1] *= 2;
									score += matr[i][j1];
									matr[i][j]  = 0;
									break;
								}
								else
								{
									if(j1+1 != j)
									{
										matr[i][j1+1] = matr[i][j];
										matr[i][j] = 0;	
										break;
									}
									break;	
								}	
							}
							else
							{
								if (j1 == 0)
								{
									matr[i][j1] = matr[i][j];
									matr[i][j] = 0;
									break;
								}
							}
						}
					}
				}
			}
		
		break;

//=================/MOVE A======================================
	default: break;
	}
	return matr[N][N];
    
}

void game()
{

	int Matrix[N][N] = {0};
	char arrow = 0;
	int score = 0;
	
	system("cls");
	First_Generation(Matrix);
	Print_matrix(Matrix, score);
	
	bool gaming = true;
	while(gaming)
	{	
		arrow=getch();
		if ((arrow == 'W')
	   	  ||(arrow == 'w')
		  ||(arrow == 'A')
		  ||(arrow == 'a')
		  ||(arrow == 'S')
		  ||(arrow == 's')
		  ||(arrow == 'D')
		  ||(arrow == 'd'))
		  {
			Movement(Matrix, arrow, score);
			Generation(Matrix);
			system("cls");	
			Print_matrix(Matrix, score);	
			arrow = 0;
		  }
	
	}
	
}

main()
{
	int menu = true;
	char choice = 0;
	
	system("mode con cols=50 lines=20");	
	
	while (menu)
	{	
		system("cls");
        
		printf("1 GAME START\n\n");
		printf("2 RULES\n\n");
		printf("3 EXIT\n\n");
		
		choice = getch();
		switch(choice)
		{
			case '1': game();             break;
			case '2': rules();            break;
			case '3': menu = false;       break;   
		}	
	}
}	
