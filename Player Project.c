/* Player Management System :
Problem Statement:
A Player Management System is required to efficiently organize and manage information about cricket players. The system should support various operations, including adding, removing, searching, updating, displaying all player records, and showcasing the top 3 players based on runs and wickets. The system should handle player attributes, including Jersey Number, Name, Runs, Wickets, and Matches played.
Key Requirements:
�Add Player: The system should allow for the addition of new players with their respective attributes, including Jersey Number, Player Name, Runs, Wickets, and Matches played.
�Remove Player: Users should be able to remove players from the system, ensuring that associated data is deleted while preserving data integrity.
�Search Player: The system should facilitate player retrieval by both Jersey Number and Player Name, enabling users to quickly access player details.
�Update Player Data: Users must have the ability to update a player's Runs, Wickets, and Matches played, providing a means for keeping player information accurate and up-to-date.
�Display Sorted Players: The system should provide a feature to display the sorted player information based on minimum/maximum runs and minimum/maximum wickets, allowing users to see the leading performers in the team.
�Display All Players: The system should offer the option to display details of all the players in the database, enabling users to access the complete list of players.
*/

#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
typedef struct Player
{
	char name[20];
	int noMatches,runs,wickets,jerseyNumber;            //user build-in structure having data type Player
}Player;

void storeInfo(Player*,int);
void displayInfo(Player*,int);
void increaseMemory(Player*,int);
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

int size = 7;										//hard coaded size value given globally
int ctr = 0;										//counter(ctr) declare globally having initial value 0

void main()
{
	Player* play = (Player*)malloc(sizeof(Player)*size);        //create array of name play using malloc() having data base Player 
	hardCoaded(play);											//some hard coaded details entered
	int ch;
	do   
	{
		printf("\n1.Insert player Information \n2.Display player Information \n3.Search Player \n4.Remove Player \n5.Update Player Information \n6.Sort player \n7.Exit \n\nEnter Your Choice: \n ");	
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				{
					(ctr<size)?storeInfo(play,ctr):increaseMemory(play,ctr);  		//calling 'storeInfo' fun to store data by user
				}
				break;
			case 2:
				{
					(ctr==0)?noIndex(play,ctr):displayInfo(play,ctr);				//calling 'displayInfo' fun to display data present in array
				}
				break;
			case 3:
				{
					if(ctr==0)
					{
						noIndex(play,ctr);    										 //calling 'noindex' fun if ctr value is 0				
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
							
							int i = searchByJerseyNo(play,jn);                                            //calling 'searchByJerseyNo' to search player 
								(i >= 0)?displayPlayer1(play,i):printf("\nPlayer not found \n");       //calling 'displayPlayer1' fun to show only searched player data

						}
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of player you want to search: "); 
							fflush(stdin);
							gets(name);
								
							int i = searchByName(play,name);										//calling 'searchByName' to search player
								(i >= 0)?displayPlayer1(play,i):printf("\nPlayer not found \n");		//calling 'displayPlayer1' fun to show only searched player data
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
							noIndex(play,ctr);    										//calling 'noindex' fun if ctr value is 0			
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
								
								int i = searchByJerseyNo(play,jn);							//calling 'searchByJerseyNo' to search player 
								{
									if(i >= 0)
									{
										removePlayer(play,i);							   //calling 'removePlayer' to remove player 
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
									
								int i = searchByName(play,name);								//calling 'searchByJerseyNo' to search player 
								{
									if(i >= 0)
									{
										removePlayer(play,i);									//calling 'removePlayer' to remove player 
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
					
							int i = searchByJerseyNo(play,jn);										//calling 'searchByJerseyNo' to search player 
								(i>=0)?updatePlayer(play,i):printf("\nPlayer not found\n");			//calling 'updatePlayer' to update player information
						}
						if(choice == 2)
						{
							char name[20];
							printf("\nEnter name of player you want to update: ");
							fflush(stdin);
							gets(name);
										
							int i = searchByName(play,name);											//calling 'searchByJerseyNo' to search player 
								(i>=0)?updatePlayer(play,i):printf("\nPlayer not found\n");				//calling 'updatePlayer' to update player information
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
									
									(choice == 1)?sortByRuns(play):(choice == 2)?sortByWickets(play):(choice == 3)?sortByJerseyNo(play):printf("\nInvalid Choice\n");  //calling 'sort' fun to sort player by wickets,run,jersey no											
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
		fflush(stdin);																//to clear buffer
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

void increaseMemory(Player* play,int ctr)
{
	printf("\nYou can not enter player information\n");
	char choice;
	printf("\nDo you want to increase memory to insert details(y/n): ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == 'y' || choice == 'Y')
	{
		int n;
		printf("\nHow much memory you want to increase: ");
		scanf("%d",&n);
		size = size + n;
		play = (Player*)realloc(play,(size)*sizeof(Player));                    //calling 'realloc' fun to increase the size of array
		storeInfo(play,ctr);													//calling 'storeinfo' fun to store info
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

void noIndex(Player*play,int ctr)									//fun if counter value is 0
{
	printf("\nThere is no any information to show");
	char choice;
	printf("\nDo yo want to insert Information(y/n): ");
	fflush(stdin);
	scanf("%c",&choice);
				
	(choice == 'y' || choice == 'Y')?storeInfo(play,ctr):(choice == 'n' || choice == 'N')?printf("\nok...If you want to insert information choose choice 1\n"):printf("\nEnter valid choice\n");
}

int searchByJerseyNo(Player* play,int jn)                                    //call fun 'searchByJerseyNo' to search by jersey num
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

int searchByName(Player* play,char* name)                                    //call fun 'searchByName' to search by jersey name
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
	ctr--;												//counter value decrased because one/searched index removed	
}

void updatePlayer(Player* play,int i)
{
	int m;													
	printf("\nEnter how many matches you want to add: ");
	scanf("%d",&m);
	play[i].noMatches = play[i].noMatches + m;             //adding new no of matches in previous count of matches
			
	int r;
	printf("\nEnter how many runs you want to add: ");
	scanf("%d",&r);
	play[i].runs = play[i].runs + r;						 //adding new no of runs in previous count of runs
							
	int w;
	printf("\nEnter how many wickets you want to add: ");
	scanf("%d",&w);
	play[i].wickets = play[i].wickets + w;					 //adding new no of wickets in previous count of wickets
					
	displayPlayer1(play,i);										//display updated player info
}

void sortByRuns(Player* play)								//fun to descending sort players by euns
{
	Player cricket[size];									//create new array to keep original array as it is
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];									//assign original array value to duplicate array
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].runs  < cricket[j].runs)					//sort duplicated array
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);										//display duplicated array
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
	Player cricket[size];									//create new array to keep original array as it is
	for(int i=0; i<ctr; i++)
	{
		cricket[i] = play[i];									//assign original array value to duplicate array
	}
	
	for(int i=0; i<ctr; i++)
	{
		for(int j=i+1; j<ctr; j++)
		{
			if(cricket[i].runs  > cricket[j].runs)					//sort duplicated array
			{
				Player temp = cricket[i];
				cricket[i] = cricket[j];
				cricket[j] = temp;
			}
		}
	}
	displayInfo(cricket,ctr);										//display duplicated array	
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