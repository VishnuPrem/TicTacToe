

	#include<fstream.h>
	#include<stdlib.h>
	#include<stdio.h>
	#include<string.h>


	void update();

	class ACCOUNT
	  {
		  int accno;
		  char name[15];
		  char password[15];
		  int numofgames;
		  int numofwins;

		  public:

			void read()
			  {
				 cout<<"\n\n\t\t Enter account number: ";
				 cin>>accno;
				 cout<<"\n\t\t Enter user name(15 characters only): ";
				 gets(name);
				 cout<<"\n\t\t Enter password(15 characters only): ";
				 gets(password);
				 numofgames=0;
				 numofwins=0;
				 }

			 void print()
				{
				  float percent;
				  percent=numofwins*100/numofgames;

				  cout<<"\n.............. ...... ... ... .. .. .. ..  .  .  .   ";
				  cout<<"\n\t Profile Details";
				  cout<<"\n.............. ...... ... ... .. .. .. ..  .  .  .   ";

				  cout<<"\n\n\t\tAccount number: "<<accno;
				  cout<<"\n\t\tUser name: "<<name;
				  cout<<"\n\t\tNumber of games played: "<<numofgames;
				  cout<<"\n\t\tNumber of wins: "<<numofwins;
				  cout<<"\n\t\tWin percentage: "<<percent<<"%";

				  }

			  int retaccno()
				 { return accno;
					}

			  char* retname()
				 { return name;
					}

			  char* retpass()
				 { return password;
					}

			  void ngames()
				  { numofgames++;
					 }
			  void nwins()
				  { numofwins++;
					 }

			  void modify()
				 {
					cout<<"\n.............. ...... ... ... .. .. .. ..  .  .  .   ";
					cout<<"\n\t Modify ";
					cout<<"\n.............. ...... ... ... .. .. .. ..  .  .  .   ";

					char pass[15];

					start:
					cout<<"\n\n\tEnter current password: ";
					gets(pass);
					if(strcmpi(retpass(),pass)==0)
					  {	cout<<"\n\tEnter new password: ";
							gets(password);
					  }
					else
					  {	cout<<"\n\n\t\t Incorrect password. Enter again";
							goto start;
					  }
					update();
					cout<<"\n\n\tPassword changed..";
				 }




		  }Acc;
  //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
   
	class GAME
	 {

		  char A[3][3];

			void reset()
			  {  for(int i=1;i<=3;i++)
					 for (int j=1;j<=3;j++)
						A[i][j]=' ';
				}

			void table()
				{
						int i;
						cout<<"\n\n\t\t    A     B     C";
						for(i=1;i<=3;i++)
							{  cout<<"\n\t\t       |     |     ";
								cout<<"\n\t\t"<<i<<"   "<<A[i][1]<<"  |  "<<A[i][2]<<"  |  "<<A[i][3];
								if(i!=3)
									cout<<"\n\t\t  _____|_____|_____";
								else
									cout<<"\n\t\t       |     |     ";
							 }

				}



			  void player_play()
				  {
						 int row,colnum;
						 char col;

						 table();
						 start:
						 cout<<"\n\n\t Enter column and row(in A1,B2,C3,etc form)  ";
						 cin>>col>>row;

						 if((col!='A'&&col!='B'&&col!='C')||(row!=1&&row!=2&&row!=3))
							 { cout<<"\n\t\t Incorrect entry. Repeat entry";
								goto start;
							  }

						if(col=='A')
							colnum=1;
						else if(col=='B')
							colnum=2;
						else if(col=='C')
							colnum=3;

						if(A[row][colnum]=='X'||A[row][colnum]=='O')
							{  cout<<"\n\t\t Cannot enter here. Repeat enrty";
								goto start;
							}

						A[row][colnum]='X';

			}

 //.........................

			int think()
			  {
					int i,j,X,O;

					for(i=1;i<=3;i++)                                  //rowwise check for O
						 {
							 O=0;
							 for(j=1;j<=3;j++)
								 if(A[i][j]=='O')
										O++;
							 if(O==2)
								  {
									  for(j=1;j<=3;j++)
										  if(A[i][j]==' ')
											  {	A[i][j]='O';
													return 1;
											  }
									}
						  }

					 for(j=1;j<=3;j++)                                     //column wise chekc for O
						 {
							  O=0;
							  for(i=1;i<=3;i++)
									  if(A[i][j]=='O')
										  O++;
							  if(O==2)
								  {
									  for(i=1;i<=3;i++)
										  if(A[i][j]==' ')
											{	A[i][j]='O';
													return 1;
												}
									}
						 }

					 O=0;
																						 //leftdiagonal for O
					  if(A[1][1]=='O')
						 O++;
					  if(A[2][2]=='O')
						 O++;
					  if(A[3][3]=='O')
						 O++;
					  if(O==2)
						 {
							if(A[1][1]==' ')
							  {	A[1][1]='O';
									return 1;
								}
							else if(A[2][2]==' ')
							 {	A[2][2]='O';
									return 1;
								}
							else if(A[3][3]==' ')
								{	A[3][3]='O';
									return 1;
								}
						  }

					O=0;
																						 //right diagonal for O
					  if(A[3][1]=='O')
						 O++;
					  if(A[2][2]=='O')
						 O++;
					  if(A[1][3]=='O')
						 O++;
					  if(O==2)
						 {
							if(A[3][1]==' ')
							  {	A[3][1]='O';
									return 1;
								}
							else if(A[2][2]==' ')
							 {	A[2][2]='O';
									return 1;
								}
							else if(A[1][3]==' ')
								{	A[1][3]='O';
									return 1;
								}
						  }



						for(i=1;i<=3;i++)                                  //rowwise check for X
						 {
							 X=0;
							 for(j=1;j<=3;j++)
								  if(A[i][j]=='X')
										X++;

							 if(X==2)
								 {
									for(j=1;j<=3;j++)
										  if(A[i][j]==' ')
											  {	A[i][j]='O';
													return 1;
												}
								 }
						  }


					  for(j=1;j<=3;j++)                                     //column wise chekc for X
						 {
							  X=0;
							  for(i=1;i<=3;i++)
									if(A[i][j]=='X')
											X++;
								if(X==2)
									{
									  for(i=1;i<=3;i++)
										  if(A[i][j]==' ')
											{	A[i][j]='O';
													return 1;
												}
									}
						 }


					  X=0;
																						 //leftdiagonal for X
					  if(A[1][1]=='X')
						 X++;
					  if(A[2][2]=='X')
						 X++;
					  if(A[3][3]=='X')
						 X++;
					  if(X==2)
						 {
							if(A[1][1]==' ')
							  {	A[1][1]='O';
									return 1;
								}
							else if(A[2][2]==' ')
							 {	A[2][2]='O';
									return 1;
								}
							else if(A[3][3]==' ')
								{	A[3][3]='O';
									return 1;
								}
						  }


					 X=0;
																						 //right diagonal for X
					  if(A[3][1]=='X')
						 X++;
					  if(A[2][2]=='X')
						 X++;
					  if(A[1][3]=='X')
						 X++;
					  if(X==2)
						 {
							if(A[3][1]==' ')
							  {	A[3][1]='O';
									return 1;
								}
							else if(A[2][2]==' ')
							 {	A[2][2]='O';
									return 1;
								}
							else if(A[1][3]==' ')
								{	A[1][3]='O';
									return 1;
								}
						  }

				  return 0;

			  }

  //..................................

				void pc_play(int mode)
				 {
						int res=0;

						if(mode==2)
						  res=think();

						if(res==0)
						 {
							randomize();
							int r,c;

							start:
							r=random(3)+1;
							c=random(3)+1;

							if(A[r][c]=='X'||A[r][c]=='O')
							  goto start;

							A[r][c]='O';
						 }

				 }



				int result()
				  {
					  int i,j,X,O,count=0,flag=0;

					  for(i=1;i<=3;i++)
						 {  X=O=0;
							 for(j=1;j<=3;j++)
								 { if(A[i][j]=='X')
										X++;
									else if(A[i][j]=='O')
										O++;
								 }
								if(X==3)
									  return 1;
								else if(O==3)
										return 0;
						 }

					  for(j=1;j<=3;j++)
						 {   X=O=0;
							  for(i=1;i<=3;i++)
								 { if(A[i][j]=='X')
										X++;
									else if(A[i][j]=='O')
										O++;
								 }
								if(X==3)
										return 1;
								else if(O==3)
										return 0;
						 }

					  if(A[1][1]=='X'&&A[2][2]=='X'&&A[3][3]=='X')
							  return 1;

					  else if(A[1][1]=='O'&&A[2][2]=='O'&&A[3][3]=='O')
								return 0;

					  else if(A[3][1]=='X'&&A[2][2]=='X'&&A[1][3]=='X')
								 return 1;

					  else if(A[3][1]=='O'&&A[2][2]=='O'&&A[1][3]=='O')
								return 0;

					  for(i=1;i<=3;i++)
						 for(j=1;j<=3;j++)
							 if(A[i][j]!=' ')
								 count++;
					  if(count==9)
						 return 3;

					 return 2;
				  }

		 public:

		 GAME()
		 {
			for(int i=1;i<=3;i++)
				for (int j=1;j<=3;j++)
				  A[i][j]=' ';
		  }


		 void play()
			 {
					cout<<"\n................................................................................";
					cout<<"\t\tPLAY GAME ";
					cout<<"\n................................................................................";

					int mode;

					cout<<"\n\n\t\t1.Easy mode\n\t\t2.Hard mode\n\n\t\t\t\t\tEnter choice: ";
					cin>>mode;

					Acc.ngames();
					int res;

					do{
						 pc_play(mode);
						 res=result();
						 if(res!=2)
								break;
						 player_play();
						 res=result();
					 }while(res==2);

				  table();

				  if(res==0)
					 cout<<"\n\n\t\t YOU LOSE!";
				  else if(res==1)
					 { cout<<"\n\n\t\t YOU WIN! ";
						Acc.nwins();
					  }
				  else if(res==3)
					 cout<<"\n\n\t\t Draw..";

				  update();
				  reset();
			 }

	  }G;


	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



		void create()
		 {
			cout<<"\n................................................................................";
			cout<<"\t\tCREATE PROFILE";
			cout<<"\n................................................................................";

			ACCOUNT temp;

			fstream file;
			file.open("tictactoe.dat",ios::in|ios::binary);

			start:
			cout<<"\n\n\t Enter deatails for new profile-";
			Acc.read();
			file.seekg(0);

			while(file.read((char*)&temp,sizeof(temp)))
				{
				  if(strcmpi(Acc.retname(),temp.retname())==0)
					  {
						 cout<<"\n\n\t\t\t User name already exists. Re-enter details";
						 goto start;
						}
					if(Acc.retaccno()==temp.retaccno())
					  {
						 cout<<"\n\n\t\t\t Account number already exists. Re-enter details";
						 goto start;
						}
				  }
			file.close();

			file.open("tictactoe.dat",ios::app|ios::binary);
			file.write((char*)&Acc,sizeof(Acc));
			cout<<"\n\n\t\t\t Profile created!";

			file.close();

			}

	  void profile();

	  void log_in()
		  {
			 cout<<"\n................................................................................";
			 cout<<"\t\tLOG IN";
			 cout<<"\n................................................................................";

			 fstream file;
			 file.open("tictactoe.dat",ios::in|ios::binary);
			 file.seekg(0);
			 int num,flag=0;
			 char pass[15];

			 cout<<"\n\n\t\tACC. NO.\tUSER NAME";
			 cout<<"\n\t\t--------\t----------\n";
			 while(file.read((char*)&Acc,sizeof(Acc)))
				{
				  cout<<"\n\t\t   "<<Acc.retaccno()<<"\t\t "<<Acc.retname();
				 }
			 start:

			 cout<<"\n\n\n\t Select your account number: ";
			 cin>>num;

			 file.close();

			 file.open("tictactoe.dat",ios::in|ios::binary);
			 file.seekg(0);


			 while(file.read((char*)&Acc,sizeof(Acc)))
				{
				  if(Acc.retaccno()==num)
					  { flag=1;
						 cout<<"\n\t Enter password: ";
						 cin>>pass;

						 if(strcmpi(Acc.retpass(),pass)==0)
							  { file.close();
								 cout<<"\n\n\t\t\t Logging in..";
								 profile();
								}
						else
							{ cout<<"\n\t\t\t Wrong entry.Enter again";
								goto start;
							 }
						}
				}

				if(flag==0)
				  {  cout<<"\n\n\t\t Account number does not exist.Enter again.";
					  goto start;
					 }



			 }

		 void update()
				 {                                                               //rewrite
					  ACCOUNT temp;

					  fstream file;
					  fstream t;

					  file.open("tictactoe.dat",ios::in|ios::binary);
					  t.open("temporary.dat",ios::out|ios::binary);

					  file.seekg(0);

					  while(file.read((char*)&temp,sizeof(temp)))
						 {
							 if(Acc.retaccno()==temp.retaccno())
								  t.write((char*)&Acc,sizeof(Acc));
							 else
								  t.write((char*)&temp,sizeof(temp));
						  }

						file.close();
						t.close();
						remove("tictactoe.dat");
						rename("temporary.dat","tictactoe.dat");
				  }




	 void profile()
	  {
		 start:

		 cout<<"\n\n................................................................................";
		 cout<<"\t\t MY PROFILE";
		 cout<<"\n................................................................................";

		 int choice;

		 cout<<"\n\n\t\t1. Play\n\t\t2. Veiw profile details\n\t\t3. Change password\n\t\t4. Log out";
		 cout<<"\n\n\t\t\t\t \t Enter choice: ";
		 cin>>choice;

		 switch(choice)
			{
			  case 1: G.play();
					break;
			  case 2: Acc.print();
				  break;
			  case 3: Acc.modify();
				  break;
			  case 4:cout<<"\n\n\t\t\tLogging out..";
						return;
			 }


		  goto start;

	  }

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	void main()
	 {

		cout<<"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
		cout<<"\n\t\t\t\tTIC-TAC-TOE GAME";
		cout<<"\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
		int choice;
      
		cout<<"\n\n Tic-tac-toe (or Xs and Os) is a paper-and-pencil game for two players, X and O, ";
		cout<<"who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three ";
		cout<<"respective marks in a horizontal, vertical, or diagonal row wins the game.";

		start:
		cout<<"\n\n\n................................................................................";
		cout<<"\t\tMAIN MENU";
		cout<<"\n................................................................................";


		cout<<"\n\n\t1.Create Profile \n\t2.Login to existing profile \n\t3.Quit\n\n\t\t\t\t\t Enter choice: ";
		cin>>choice;

		if(choice==1)
		  create();

		else if(choice==2)
		  log_in();

		if(choice!=3)
			goto start;
	  }
