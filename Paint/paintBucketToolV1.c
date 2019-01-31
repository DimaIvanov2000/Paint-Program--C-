#include<stdio.h>

int grid[20][20]={0};
int overlay[20][20]={0};
int cursor[2]={0};
int color=0;

main()
{
	char input;
	int i,j,k;
	
	int lfColor;
	int newFound;
	
	do
	{
		//display grid
		system("cls");
		for(j=0;j<20;j++)
		{
			for(i=0;i<20;i++)
			{
				if(cursor[0]==i&&cursor[1]==j)
				{
					printf("^");
				}
				else
				{
					switch(grid[i][j])
					{
						case 0:
							printf(" ");
							break;
						case 1:
							printf("%c",176);
							break;
						case 2:
							printf("%c",177);
							break;
						case 3:
							printf("%c",178);
							break;
						case 4:
							printf("%c",219);
							break;
					}
				}
			}
			printf("|\n");
		}
		printf("---------------------\nColor: ");
		switch(color)
		{
			case 0:
				printf(" ");
				break;
			case 1:
				printf("%c",176);
				break;
			case 2:
				printf("%c",177);
				break;
			case 3:
				printf("%c",178);
				break;
			case 4:
				printf("%c",219);
				break;
		}
		input=getch();
		//do stuff with input
		switch(input)
		{
			case 72://up
				if(cursor[1]>0)
				{
					cursor[1]--;
				}
				break;
			case 75://left
				if(cursor[0]>0)
				{
					cursor[0]--;
				}
				break;
			case 77://right
				if(cursor[0]<19)
				{
					cursor[0]++;
				}
				break;
			case 80://down
				if(cursor[1]<19)
				{
					cursor[1]++;
				}
				break;
			case 'c':
				color=(color+1)%5;
				break;
			case 'd':
				grid[cursor[0]][cursor[1]]=color;
				break;
			case 'f':
				lfColor=grid[cursor[0]][cursor[1]];
				overlay[cursor[0]][cursor[1]]=1;
				do
				{
					newFound=0;
					for(j=0;j<20;j++)
					{
						for(i=0;i<20;i++)
						{
							if(overlay[i][j]==1)
							{
								for(k=-1;k<=1;k+=2)
								{
									if(i+k>=0&&i+k<=19)
									{
										if(grid[i+k][j]==lfColor&&overlay[i+k][j]!=1)
										{
											overlay[i+k][j]=1;
											newFound=1;
										}	
									}
									if(j+k>=0&&j+k<=19)
									{
										if(grid[i][j+k]==lfColor&&overlay[i][j+k]!=1)
										{
											overlay[i][j+k]=1;
											newFound=1;
										}	
									}
								}
							}
						}
					}
					
				}
				while(newFound!=0);
				for(j=0;j<20;j++)
				{
					for(i=0;i<20;i++)
					{
						if(overlay[i][j]==1)
						{
							grid[i][j]=color;
							overlay[i][j]=0;
						}
					}
				}
				break;
		}
	}
	while(input!=27);
}
