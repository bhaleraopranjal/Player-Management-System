#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
typedef struct Player
{
	char name[20];
	int noMatches,runs,wickets,jerseyNumber;            
}Player;

void storeInfo(Player*,int);
void displayInfo(Player*,int);
Player* increaseMemory(Player*,int);
void noIndex(Player*,int);
void displayPlayer1(Player*,int);
void hardCoaded(Player*);
void removePlayer(Player*,int);
int searchByName(Player*,char*);
int searchByJerseyNo(Player*,int);
void updatePlayer(Player*,int);
void sortByRuns(Player*);
void sortByWickets(Player*);
void sortByJerseyNo(Player*);
void sortAscRuns(Player*);
void sortAscWickets(Player*);
void sortAscJerseyNo(Player*);
int checkRepeat(Player*,int,int);

int size = 7;										
int ctr = 0;										

void main()
{
	Player* play = (Player*)malloc(sizeof(Player)*size);        
	hardCoaded(play);											
	int ch;
	do   
	{
		printf("\n1.Insert player Information \n2.Display player Information \n3.Search Player \n4.Remove Player \n5.Update Player Information \n6.Sort player \n7.Exit \n\nEnter Your Choice: \n ");	
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				{
					(ctr<size)?storeInfo(play,ctr):increaseMemory(play,ctr);  		
					if(ctr<size)
					{
						storeInfo(play,ctr);
					}
					else 
					{
						printf("\nYou can not enter player information\n");
						char choice;
						printf("\nDo you want to increase memory to insert details(y/n): ");
						fflush(stdin);
						scanf("%c",&choice);
							if(choice == 'y' || choice == 'Y')
							{
								play = increaseMemory(play,ctr);
								storeInfo(play,ctr);
							}						
							else if(choice == 'n' || choice == 'N')
							{
								printf("\nok...You can not insert more players\n");
							}
							else
							{
								printf("\nEnter valid choice\n");
							}
					}
				}
				break;
			case 2:
				{
					(ctr==0)?noIndex(play,ctr):displayInfo(play,ctr);				
				}
				break;
			case 3:
				{
					if(ctr==0)
					{
						noIndex(play,ctr);    														
					}
					else
					{
						int choice;
						printf("\n1.Search by Jersey Number \n2.Search by Player Name \n\nEnter your choice:");
						scanf("%d",&choice);
						
						if(choice == 1)
						{
							int jn;
							printf("\nEnter Jersey number of player you want to search: ");
							scanf("%d",&jn);
							
							int i = searchByJerseyNo(play,jn);                                            
								(i >= 0)?displayPlayer1(play,i):printf("\nPlayer not found \n");       

						}
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of player you want to search: "); 
							fflush(stdin);
							gets(name);
								
							int i = searchByName(play,name);										
								(i >= 0)?displayPlayer1(play,i):printf("\nPlayer not found \n");		
						}   
						else if(choice > 2)
						{
							printf("\nInvalid Choice\n");  		
						}
					}					
				}
				break;
				case 4:
					{
						if(ctr==0)
						{
							noIndex(play,ctr);    													
						}
						else
						{
							int choice;
							printf("\n1.Remove player by Jersey Number \n2.Remove player by Player Name \n\nEnter your choice: ");
							scanf("%d",&choice);
							
							if(choice == 1)
							{
								int jn;
								printf("\nEnter Jersey number of player you want to remove: ");
								scanf("%d",&jn);
								
								int i = searchByJerseyNo(play,jn);							 
								{
									if(i >= 0)
									{
										removePlayer(play,i);							   
										printf("\nPlayer removed Successfully\n");
									}
									else if(i==-1)
									{
										printf("\nPlayer not found \n",i);	
									}
								}
							}
							if(choice == 2)
							{
								char name[20];
								printf("\nEnter name of player you want to remove: ");
								fflush(stdin);
								gets(name);
									
								int i = searchByName(play,name);								
								{
									if(i >= 0)
									{
										removePlayer(play,i);									 
										printf("\nPlayer removed Successfully\n");				
									}
									else if(i==-1)
									{
										printf("\nPlayer not found \n",i);	
									}
								}
							}
							else if(choice > 2)
							{
								printf("\nInvalid Choice\n");
							}
						}						
					}
					break;
				case 5:
					{
						int choice;
						printf("\n1.Update player information by Jersey Number \n2.Update player information by Player Name  \nEnter your choice: ");
						scanf("%d",&choice);
								
						if(choice == 1)
						{
							int jn;
							printf("\nEnter the Jersey number of player to update: ");
							scanf("%d",&jn);
					
							int i = searchByJerseyNo(play,jn);										
								(i>=0)?updatePlayer(play,i):printf("\nPlayer not found\n");			
						}
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of player you want to update: ");
							fflush(stdin);
							gets(name);
										
							int i = searchByName(play,name);											
								(i>=0)?updatePlayer(play,i):printf("\nPlayer not found\n");				
						}
						else if(choice > 2)
						{
							printf("\nInvalid Choice\n");
						}						
					}
					break;
				case 6:
					{
						int ch;
						printf("\n1.Descending Sort \n2.Ascending Sort \n\nEnter which sort you want: ");
						scanf("%d",&ch);
						
						switch(ch)
						{
							case 1:
								{
									int choice;
									printf("\n1.Sort player by Runs \n2.Sort player by wickets  \n3.Sort player by Jersey Number \n\nEnter your choice: ");
									scanf("%d",&choice);
									
									(choice == 1)?sortByRuns(play):(choice == 2)?sortByWickets(play):(choice == 3)?sortByJerseyNo(play):printf("\nInvalid Choice\n");  										
								}
								break;
							case 2:
								{
									int choice;
									printf("\n1.Sort player by Runs \n2.Sort player by wickets  \n3.Sort player by Jersey Number \n\nEnter your choice: ");
									scanf("%d",&choice);
									
									(choice == 1)?sortAscRuns(play):(choice == 2)?sortAscWickets(play):(choice == 3)?sortAscJerseyNo(play):printf("\nInvalid Choice\n");  //calling 'sort' fun to sort player by wickets,run,jersey no							
								}
								break;
							default:
								{
									printf("\nEnter valid choice\n");
								}
						}		
					}
					break;
				case 7:
					{
						printf("\nThank You\n");				
					}
					break;
				default:
					{
						printf("\nEnter Valid choice\n");		
					}
				break;
		}
	}while(ch!=7);
}

void storeInfo(Player* play,int i)
{	
	printf("\nEnter Jersey Number of player: ");
	scanf("%d",&play[i].jerseyNumber);
	int jn = play[i].jerseyNumber;
	int res = checkRepeat(play,i,jn);
	if(res == 0)
	{
		printf("\nJersey Number already present\n");
		storeInfo(play,i);
	}
	else
	{
		printf("\nEnter Player Name: ");
		fflush(stdin);																
		gets(play[i].name);
			
		printf("\nEnter number of matches player played: ");
		scanf("%d",&play[i].noMatches);
				
		printf("\nEnter the number of runs player did: ");
		scanf("%d",&play[i].runs);
			
		printf("\nEnter the number of wickets player taken: ");
		scanf("%d",&play[i].wickets);
			
		ctr++;		
		}	
	}

void displayInfo(Player* play,int ctr) 
{
	printf("\nYou have entered %d Players Information\n",ctr);
	printf("\n+---------------------------------------------------------------------------+");
	printf("\n|   Jersey Number   |     Player Name     |  Matches  |   Runs  |  Wickets  |");
	printf("\n+---------------------------------------------------------------------------+");
	int j=0;
	while(j<ctr)
	{
		printf("\n| %8d          |   %-16s  |    %-3d    |   %-4d  |    %-4d   |",play[j].jerseyNumber,play[j].name,play[j].noMatches,play[j].runs,play[j].wickets);
		j++;
	}
		printf("\n+---------------------------------------------------------------------------+");
}

Player* increaseMemory(Player* play,int ctr)
{	
		int n;
		printf("\nHow much memory you want to increase: ");
		scanf("%d",&n);
		size = size + n;
		play = (Player*)realloc(play,(size)*sizeof(Player));                    	
		return play;
}

void noIndex(Player*play,int ctr)									
	printf("\nThere is no any information to show");
	char choice;
	printf("\nDo yo want to insert Information(y/n): ");
	fflush(stdin);
	scanf("%c",&choice);
				
	(choice == 'y' || choice == 'Y')?storeInfo(play,ctr):(choice == 'n' || choice == 'N')?printf("\nok...If you want to insert information choose choice 1\n"):printf("\nEnter valid choice\n");
}

int searchByJerseyNo(Player* play,int jn)                                    
{		
	for(int i=0; i<ctr; i++)
	{
		if(play[i].jerseyNumber == jn )
		{
			return i;
		}
	}
	return -1;	
}

int searchByName(Player* play,char* name)                                    
{
	for(int i=0; i<ctr; i++)
	{
		if(strcasecmp(play[i].name,name)==0)
		{
			return i;
		}
	}
	return -1;		
}

void displayPlayer1(Player* play,int j)   
{
	printf("\nPlayer information is as below: \n");
	printf("\n+---------------------------------------------------------------------------+");
	printf("\n|   Jersey Number   |     Player Name     |  Matches  |   Runs  |  Wickets  |");
	printf("\n+---------------------------------------------------------------------------+");
	printf("\n| %8d          |   %16s  |    %3d    |   %4d  |    %4d   |",play[j].jerseyNumber,play[j].name,play[j].noMatches,play[j].runs,play[j].wickets);
	printf("\n+---------------------------------------------------------------------------+");
}

void hardCoaded(Player* play)
{
	Player p;
	p.jerseyNumber = 10;
	strcpy(p.name,"Sachin Tendulkar");
	p.noMatches = 25;
	p.runs = 350;
	p.wickets = 2;
	play[ctr++] = p;
	
	p.jerseyNumber = 18;
	strcpy(p.name,"Virat Kohli");
	p.noMatches = 180;
	p.runs = 2000;
	p.wickets = 4;
	play[ctr++] = p;
	
	p.jerseyNumber = 07;
	strcpy(p.name,"Shubhman Gill");
	p.noMatches = 390;
	p.runs = 1500;
	p.wickets = 42;
	play[ctr++] = p;		
}

void removePlayer(Player* play,int i)
{
	for(int j=i; j<ctr-1; j++)
	{
		play[j] = play[j+1];
	}
	ctr--;													
}

void updatePlayer(Player* play,int i)
{
	int m;													
	printf("\nEnter how many matches you want to add: ");
	scanf("%d",&m);
	play[i].noMatches = play[i].noMatches + m;             
			
	int r;
	printf("\nEnter how many runs you want to add: ");
	scanf("%d",&r);
	play[i].runs = play[i].runs + r;						 
							
	int w;
	printf("\nEnter how many wickets you want to add: ");
	scanf("%d",&w);
	play[i].wickets = play[i].wickets + w;					 
					
	displayPlayer1(play,i);										
}

void sortByRuns(Player* play)								
{
	Player cricket[size];									
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];									
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].runs  < cricket[j].runs)					
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);										
}

void sortByWickets(Player* play)
{
	Player cricket[size];
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].wickets  < cricket[j].wickets)
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);
}

void sortByJerseyNo(Player* play)
{
	Player cricket[size];
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].jerseyNumber  < cricket[j].jerseyNumber)
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);
}

void sortAscRuns(Player* play)
{
	Player cricket[size];									
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];									
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].runs  > cricket[j].runs)					
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);											
}

void sortAscWickets(Player* play)
{
	Player cricket[size];
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].wickets  > cricket[j].wickets)
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);
}

void sortAscJerseyNo(Player* play)
{
	Player cricket[size];
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].jerseyNumber  > cricket[j].jerseyNumber)
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);
}

int checkRepeat(Player* play,int i,int jn)
{
	for(int j=0; j<i; j++)
	{
		if(jn == play[j].jerseyNumber)
		{
			return 0;
		}
	}			
	return 1;	
}
