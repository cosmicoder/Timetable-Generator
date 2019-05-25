
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>

int count=0;
int subcount=0;

void subjectmenu()
{
	cout<<"\nSUBJECT LIST\n";
	cout<<"\n1. Math - Math             9. II Language - SecLang\n2. English - Eng          10. Library - Lib\n3. Chemistry - Chem       11. Yoga - Yoga\n4. Physics - Phy          12. PT - PT\n5. Computer Sc - Comp     13. Lab - Lab\n6. Elective - Elec        14. EE - EE\n7. Hist/Civ - Hist        15. Club - Club\n8. Geography - Geo        16. GS - GS";
}

class Teacher
{   
	 char name[40];
	 int mon[9], tue[9], wed[9], thu[9], fri[9];//Stores the period taught by the teacher on a particular day
	 char subject[20];
	 int mond[9], tues[9], wedn[9], thur[9], frid[9];//Stores the class taught by the teacher
	 public:
	 Teacher(char t[40]="NA");
	 void write(int period,int sub,int classes,char daytable[3]);
	 int check(int period, char daytable[3]);
	 int returT(char tempteacher[40]);
	 int addteacher(int period, int sub, int classes, char daytable[3], char teachername[40]);
	 void disp();
	 void writefile();
	 void readfile();
};

Teacher sample[10];

int Teacher :: addteacher(int period, int sub, int classes, char daytable[3], char teachername[40])// Adds teacher
{
	 int subcount;
	 if(sample[0].returT(teachername))
	 {
	  subcount=sample[0].returT(teachername)-1; //Which position the teacher is in
	 }

	 else
	 {
		 Teacher temp(teachername);
		 sample[count++]=temp;
		 subcount=count-1;
	 }

	 if(!sample[subcount].check(period,daytable))
		 return 0; //cout<<"\nTeacher not free";

	 else
	 {
		sample[subcount].write(period,sub,classes,daytable);
		return 1; //cout<<"\nTeacher added";
	 }
}

void Teacher :: writefile()
{
	ofstream ofile1("Teacher.dat",ios::binary);

	for(int i=0;i<count;i++)
	{
		ofile1.write((char*)&sample[i],sizeof(sample[i]));
	}
	 ofile1.close();
}

void Teacher :: readfile()
{
	int m=0;
	ifstream ifile1("Teacher.dat",ios::binary);
	while(ifile1.read((char*)&sample[m],sizeof(sample[m])))
	{
		m++;
		count++;
	}
	ifile1.close();
}

int Teacher :: returT(char tempteacher[40]) //Returns the position of searched teacher
{
	 for(int i=0; i<count; i++)
	 {
		 if(strcmpi(sample[i].name,tempteacher)==0)
		 {
			 return i+1;
		 }

	 }
	  return 0;
}

Teacher :: Teacher(char t[40]) //Constructor
{
	  strcpy(name,t);
	  for(int i=0; i<9;i++)
	  {
		mon[i]=0;
		tue[i]=0;
		wed[i]=0;
		thu[i]=0;
		fri[i]=0;
		mond[i]=0;
		tues[i]=0;
		wedn[i]=0;
		thur[i]=0;
		frid[i]=0;
	  }
}

void Teacher :: write(int period, int sub, int classes, char daytable[3]) //Adds the period to teacher timetable
{
	if(strcmpi(daytable,"Mo")==0)
	{
		mon[period]=sub;
		mond[period]=classes;
	}
	 else if(strcmpi(daytable,"Tu")==0)
	{
		tue[period]=sub;
		tues[period]=classes;
	}
	 else if(strcmpi(daytable,"We")==0)
	{
		wed[period]=sub;
		wedn[period]=classes;
	}
	 else if(strcmpi(daytable,"Th")==0)
	{
		thu[period]=sub;
		thur[period]=classes;
	}
	else if(strcmpi(daytable,"Fr")==0)
	{
		fri[period]=sub;
		frid[period]=classes;
	}
}

int Teacher :: check(int period, char daytable[3]) //Checks if teacher is free
{
	 if(strcmpi(daytable,"Mo")&& mon[period]==0)
	 return 1;
	 else if(strcmpi(daytable,"Tu")&& tue[period]==0)
	 return 1;
	 else if(strcmpi(daytable,"We")&& wed[period]==0)
	 return 1;
	 else if(strcmpi(daytable,"Th")&& thu[period]==0)
	 return 1;
	 else if(strcmpi(daytable,"Fr")&& fri[period]==0)
	 return 1;
return 0;
}

void Teacher :: disp()
{
	 char teachername[40];
	 int flag=0;
	 cout<<"\nEnter teacher name: ";
	 gets(teachername);
	 for(int m=0; m<count; m++)
	 {
		 if(strcmpi(sample[m].name,teachername)==0)
		 {

		   flag=1;
		   int Ar[9];
		   int A[9];
		   cout<<"\n     1     2     3     4     5     6     7     8     9\n";
		   for(int i=1;i<=5;i++)
		   {
				if(i==1)cout<<"Mon  ";
				else if(i==2)cout<<"\nTue  ";
				else if(i==3)cout<<"\nWed  ";
				else if(i==4)cout<<"\nThu  ";
				else cout<<"\nFri  ";
				for(int j=0; j<9; j++)
				{
				  if(i==1)
				  {
					for(int q=0;q<9;q++)
					{
					  Ar[q]=sample[m].mond[q];
					  A[q]=sample[m].mon[q];
					}
				  }

				  else if(i==2)
				  {
					for(int q=0;q<9;q++)
					{
					  Ar[q]=sample[m].tues[q];
					  A[q]=sample[m].tue[q];
					}
				  }

				  else if(i==3)
				  {
					for(int q=0;q<9;q++)
					{
					  Ar[q]=sample[m].wedn[q];
					  A[q]=sample[m].wed[q];
					}
				  }

				  else if(i==4)
				  {
					for(int q=0;q<9;q++)
					{
					  Ar[q]=sample[m].thur[q];
					  A[q]=sample[m].thu[q];
					}
				  }

				 else if(i==5)
				 {
				  for(int q=0;q<9;q++)
				  {
					Ar[q]=sample[m].frid[q];
					A[q]=sample[m].fri[q];
				  }
				 }

				if(A[j]==1)
				{
					 if(j==2||j==5)
					 cout<<"Math |";
					 else
					 cout<<"Math  ";
				}
				else if(A[j]==2)
				{
					 if(j==2||j==5)
					 cout<<"Eng |";
					 else
					 cout<<"Eng  ";
				}
				else if(A[j]==3)
				{
					 if(j==2||j==5)
					 cout<<"Chem  |";
					 else
					 cout<<"Chem   ";
				}
				else if(A[j]==4)
				{
					 if(j==2||j==5)
					 cout<<"Phy  |";
					 else
					 cout<<"Phy   ";
				}
				else if(A[j]==5)
				{
					 if(j==2||j==5)
					 cout<<"Comp |";
					 else
					 cout<<"Comp  ";
				}
				else if(A[j]==6)
				{
					 if(j==2||j==5)
					 cout<<"Elec |";
					 else
					 cout<<"Elec  ";
				}
				else if(A[j]==7)
				{
					 if(j==2||j==5)
					 cout<<"H/C  |";
					 else
					 cout<<"H/C   ";
				}
				else if(A[j]==8)
				{
					 if(j==2||j==5)
					 cout<<"Geo  |";
					 else
					 cout<<"Geo   ";
				}
				else if(A[j]==9)
				{
					 if(j==2||j==5)
					 cout<<"II L |";
					 else
					 cout<<"II L  ";
				}
				else if(A[j]==10)
				{
					 if(j==2||j==5)
					 cout<<"Lib  |";
					 else
					 cout<<"Lib   ";
				}
				else if(A[j]==11)
				{
					 if(j==2||j==5)
					 cout<<"Yoga |";
					 else
					 cout<<"Yoga  ";
				}
				else if(A[j]==12)
				{
					 if(j==2||j==5)
					 cout<<"PT  |";
					 else
					 cout<<"PT   ";
				}
				else if(A[j]==13)
				{
					 if(j==2||j==5)
					 cout<<"Lab  |";
					 else
					 cout<<"Lab   ";
				}
				else if(A[j]==14)
				{
					 if(j==2||j==5)
					 cout<<"EE  |";
					 else
					 cout<<"EE   ";
				}
				else if(A[j]==15)
				{
					 if(j==2||j==5)
					 cout<<"Club |";
					 else
					 cout<<"Club  ";
				}
				else if(A[j]==16)
				{
					 if(j==2||j==5)
					 cout<<"GS   |";
					 else
					 cout<<"GS    ";
				}
				else
				{
					if(j==2||j==5)
					cout<<"NA   |";
					else
					cout<<"NA    ";}
				}

				cout<<"\n     ";
				for(j=0; j<9; j++)
				{
					if(Ar[j]==1){if(j==2||j==5)cout<<"12A  |";else cout<<"12A   ";}
					else if(Ar[j]==2){if(j==2||j==5)cout<<"12B  |";else cout<<"12B   ";}
					else if(Ar[j]==3){if(j==2||j==5)cout<<"11A  |";else cout<<"11A   ";}
					else if(Ar[j]==4){if(j==2||j==5)cout<<"11B  |";else cout<<"11B   ";}
					else if(Ar[j]==5){if(j==2||j==5)cout<<"10A  |";else cout<<"10A   ";}
					else if(Ar[j]==6){if(j==2||j==5)cout<<"10B  |";else cout<<"10B   ";}
					else if(Ar[j]==7){if(j==2||j==5)cout<<"10C  |";else cout<<"10C   ";}
					else if(Ar[j]==8){if(j==2||j==5)cout<<"9A   |";else cout<<"9A    ";}
					else if(Ar[j]==9){if(j==2||j==5)cout<<"9B   |";else cout<<"9B    ";}
					else if(Ar[j]==10){if(j==2||j==5)cout<<"9C   |";else cout<<"9C    ";}
					else {if(j==2||j==5)cout<<"NA   |";else cout<<"NA    ";}
				}
				cout<<"\n\n";
			 }
			break;
		}
	}

	if(flag==0)
	cout<<"Incorrect entry";
}

class day
{
  int mon[9], tue[9], wed[9], thu[9], fri[9];//stores subjects assigned to a particular class
  public:
  void algorithm(int c);  //Primary Algorithm on which assignment of periods works
  void display();
  void writefile();
  void readfile();
  day();
};

day :: day()
{
  for(int i=0; i<9; i++)
	  {
		mon[i]=0;
		tue[i]=0;
		wed[i]=0;
		thu[i]=0;
		fri[i]=0;
	  }
}

day array[10]; //class array

void day :: writefile()
{
	ofstream ofile("Classes.dat",ios::binary);

	for(int i=0;i<10;i++)
	{
		ofile.write((char*)&array[i],sizeof(array[i]));
	}
	 ofile.close();
}

void day :: readfile()
{
	int m=0;
	ifstream ifile("Classes.dat",ios::binary);
	while(ifile.read((char*)&array[m],sizeof(array[m])))
	{
		m++;
	}
	ifile.close();
}

void day :: algorithm(int classes)
{    
     int B[9];
	 int checkit=0;
	 int flag=0;
     int subcode;
	 char teachername[40],daytable[3],sub[20], teachername2[40];
	 int pcount;
	 int periodno;
	 cout<<"\nEnter Teacher name: ";
	 gets(teachername);
	 if(sample[0].returT(teachername))
	 {
	  subcount=sample[0].returT(teachername)-1; //Which position the teacher is in
	 }
	 else
	 {
		 Teacher temp(teachername);
		 sample[count++]=temp;
		 subcount=count-1;
	 }
	 cout<<"\nEnter Day (Mo,Tu,We,Th,Fr): ";
	 cin>>daytable;
	 subjectmenu();
	 cout<<"\n\nEnter subject: ";
	 gets(sub);
	 cout<<"\nEnter no. of periods: ";
	 cin>>pcount;

	 long double errorcase=0;
	 int A[9];

	 if(strcmpi(daytable,"Mo")==0)
	 {
		for(int u=0; u<9; u++)
		  A[u]=mon[u];
	 }
	 else if(strcmpi(daytable,"Tu")==0)
	 {
		for(int u=0; u<9; u++)
		  A[u]=tue[u];
	 }
	 else if(strcmpi(daytable,"We")==0)
	 {
		for(int u=0; u<9; u++)
		  A[u]=wed[u];
	 }
	 else if(strcmpi(daytable,"Th")==0)
	 {
		for(int u=0; u<9; u++)
		  A[u]=thu[u];
	 }
	 else if(strcmpi(daytable,"Fr")==0)
	 {
		for(int u=0; u<9; u++)
		  A[u]=fri[u];
	 }

	 for(int i=0; i<pcount; i++) //for loop that does the assignment of the period "pcount" number of times
	 {
		  errorcase++;
		  if(errorcase==5000000l)
		  {
				cout<<"\nError";                 //High number of iterations to tackle errors when entering data. Will lead to error message
				cout<<"\nProcessor fault.\nPress any key to continue: ";
				getch();
				break;
		  }

		  randomize();
		  periodno=random(9999);  //randomize generates random value and divides by 9 to get a number from 0 to 8 which are index values for period number
		  periodno=periodno%9;

		  if(A[periodno]==0 && sample[subcount].check(periodno,daytable))
		  {        
		          B[checkit++]=periodno;
				  if(strcmpi(sub,"Math")==0)
				  {
						 A[periodno]=1;
						 subcode=1;
						 sample[subcount].write(periodno,1,classes,daytable);        //Writes in teacher's timetable
				  }
				  else if(strcmpi(sub,"Eng")==0)
				  {
						 A[periodno]=2;
						 subcode=2;
						 sample[subcount].write(periodno,2,classes,daytable);
				  }
				  else if(strcmpi(sub,"Chem")==0)
				  {
						 A[periodno]=3;
						 subcode=3;
						 sample[subcount].write(periodno,3,classes,daytable);
				  }
				  else if(strcmpi(sub,"Phy")==0)
				  {
						 A[periodno]=4;
						 subcode=4;
						 sample[subcount].write(periodno,4,classes,daytable);
				  }
				  else if(strcmpi(sub,"Comp")==0)
				  {
						 A[periodno]=5;
						 subcode=5;
						 sample[subcount].write(periodno,5,classes,daytable);
				  }
				   else if(strcmpi(sub,"Elec")==0)
				  {
						 A[periodno]=6;
						 subcode=6;
						 sample[subcount].write(periodno,6,classes,daytable);
				  }
				   else if(strcmpi(sub,"Hist")==0)
				  {
						 A[periodno]=7;
						 subcode=7;
						 sample[subcount].write(periodno,7,classes,daytable);
				  }
				   else if(strcmpi(sub,"Geo")==0)
				  {
						 A[periodno]=8;
						 subcode=8;
						 sample[subcount].write(periodno,8,classes,daytable);
				  }
				   else if(strcmpi(sub,"seclang")==0)
				  {
						 A[periodno]=9;
						 subcode=9;
						 sample[subcount].write(periodno,9,classes,daytable);
				  }
				   else if(strcmpi(sub,"lib")==0)
				  {
						 A[periodno]=10;
						 subcode=10;
						 sample[subcount].write(periodno,10,classes,daytable);
				  }
				   else if(strcmpi(sub,"yoga")==0)
				  {
						 A[periodno]=11;
						 subcode=11;
						 sample[subcount].write(periodno,11,classes,daytable);
				  }
				   else if(strcmpi(sub,"PT")==0)
				  {
						 A[periodno]=12;
						 subcode=12;
						 sample[subcount].write(periodno,12,classes,daytable);
				  }
				   else if(strcmpi(sub,"lab")==0)
				  {
						 A[periodno]=13;
						 subcode=13;
						 sample[subcount].write(periodno,13,classes,daytable);
				  }
				   else if(strcmpi(sub,"EE")==0)
				  {
						 A[periodno]=14;
						 subcode=14;
						 sample[subcount].write(periodno,14,classes,daytable);
				  }
				   else if(strcmpi(sub,"Club")==0)
				  {
						 A[periodno]=15;
						 subcode=15;
						 sample[subcount].write(periodno,15,classes,daytable);
				  }
				   else if(strcmpi(sub,"GS")==0)
				  {
						 A[periodno]=16;
						 subcode=16;
						 sample[subcount].write(periodno,16,classes,daytable);
				  }
		  }
		  else
		  {
			i--;
		  }

	   }

		  if(strcmpi(daytable,"Mo")==0)
		  {
		   for(int u=0; u<9; u++)       //Assigns to the timetable
			 mon[u]=A[u];
		  }
		  else if(strcmpi(daytable,"Tu")==0)
		  {
		   for(int u=0; u<9; u++)
			 tue[u]=A[u];
		  }
		  else if(strcmpi(daytable,"We")==0)
		  {
		   for(int u=0; u<9; u++)
			 wed[u]=A[u];
		  }
		  else if(strcmpi(daytable,"Th")==0)
		  {
			for(int u=0; u<9; u++)
			 thu[u]=A[u];
		  }
		  else if(strcmpi(daytable,"Fr")==0)
		  {
		   for(int u=0; u<9; u++)
			 fri[u]=A[u];
		  }
		  
		  char ans1;
		  int checkvalue;
		  
		  cout<<"\nPeriod Allocated Successfully";

		  while(ans1!='n')
		  {
			 cout<<"\nDo you want to add a teacher? (y/n): ";
			 cin>>ans1;
			 if(ans1=='y')
			 {
				cout<<"\nEnter Teacher name: ";
				gets(teachername2);
				for(int v=0;v<checkit;v++)
				{
				  checkvalue = sample[0].addteacher(B[v],subcode,classes,daytable,teachername2);
				  if(checkvalue == 0)
					  flag=1;
				}
				
				if(flag==0)
					cout<<"\nTeacher Added Successfully";
				else
					cout<<"\nTeacher not free for some or all of the requested periods\nShe has been added for whichever periods she is free";
          }
		}
}

void day :: display() //Displays timetable
{
	 int A[9];
	 cout<<"\n     1     2     3    |4     5     6    |7     8     9\n";
	 for(int i=1; i<=5; i++)
	 {
		if(i==1)cout<<"Mon  ";
		else if(i==2)cout<<"\nTue  ";
        else if(i==3)cout<<"\nWed  ";
        else if(i==4)cout<<"\nThu  ";
        else cout<<"\nFri  ";
        for(int j=0; j<9; j++)
        {   
	        if(i==1)
			{ 
		      for(int q=0;q<9;q++)
				A[q]=mon[q];
			}
			else if(i==2)
            { 
		      for(int q=0;q<9;q++)
                A[q]=tue[q];
            }
            else if(i==3)
            { 
		      for(int q=0;q<9;q++)
                A[q]=wed[q];
			}
            else if(i==4)
            { 
		      for(int q=0;q<9;q++)
                A[q]=thu[q];
            }
            else if(i==5)
            { 
		      for(int q=0;q<9;q++)
                A[q]=fri[q];
            }

           if(A[j]==1)
            {
                if(j==2||j==5)
                cout<<"Math |";
                else
                cout<<"Math  ";
            }
            else if(A[j]==2)
            {
                if(j==2||j==5)
                cout<<"Eng |";
                else
                cout<<"Eng  ";
            }
            else if(A[j]==3)
            {
                if(j==2||j==5)
                cout<<"Chem  |";
                else
                cout<<"Chem   ";
            }
            else if(A[j]==4)
            {
                if(j==2||j==5)
                cout<<"Phy  |";
                else
                cout<<"Phy   ";
            }
            else if(A[j]==5)
            {
                if(j==2||j==5)
                cout<<"Comp |";
                else
                cout<<"Comp  ";
            }
			else if(A[j]==6)
            {
                if(j==2||j==5)
                cout<<"Elec |";
                else
                cout<<"Elec  ";
            }
			else if(A[j]==7)
            {
                if(j==2||j==5)
                cout<<"H/C  |";
                else
                cout<<"H/C   ";
            }
			else if(A[j]==8)
            {
                if(j==2||j==5)
                cout<<"Geo  |";
                else
                cout<<"Geo   ";
            }
			else if(A[j]==9)
            {
                if(j==2||j==5)
                cout<<"II L |";
                else
                cout<<"II L  ";
            }
			else if(A[j]==10)
            {
                if(j==2||j==5)
                cout<<"Lib  |";
                else
                cout<<"Lib   ";
            }
			else if(A[j]==11)
            {
                if(j==2||j==5)
                cout<<"Yoga |";
                else
                cout<<"Yoga  ";
            }
			else if(A[j]==12)
            {
                if(j==2||j==5)
                cout<<"PT   |";
                else
                cout<<"PT   ";
            }
			else if(A[j]==13)
            {
                if(j==2||j==5)
                cout<<"Lab  |";
                else
                cout<<"Lab   ";
            }
			else if(A[j]==14)
            {
                if(j==2||j==5)
                cout<<"EE  |";
                else
                cout<<"EE   ";
            }
			else if(A[j]==15)
            {
                if(j==2||j==5)
                cout<<"Club |";
                else
                cout<<"Club  ";
            }
			else if(A[j]==16)
            {
                if(j==2||j==5)
                cout<<"GS   |";
                else
                cout<<"GS    ";
            }
            else
            {
                if(j==2||j==5)
                cout<<"NA   |";
                else
                cout<<"NA    ";
			}
		 }
	}
}


void main()
{    
     clrscr();
     array[0].readfile();
     sample[0].readfile(); //initial assignment
	 
     int n,q;
	 char ans;
     do
     {
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n                         INTERACTIVE TIMETABLE GENERATOR\n\n";
		cout<<"--------------------------------------------------------------------------------";
		cout<<"\n1. Input teacher details\n2. Display Teacher Timetable\n3. Display Class Timetable\n4. Exit\nEnter your option: ";
		cin>>n;
		switch(n)
		{
		  case 1: cout<<"\nPlease select a class\n1. 12A   2. 12B   3. 11A   4. 11B   5. 10A\n6. 10B   7. 10C   8. 9A    9. 9B    10. 9C   \nEnter Your option: ";
		          cin>>q;
		          if(q==1)
		           array[0].algorithm(q);
		          else if(q==2)
		           array[1].algorithm(q);
		          else if(q==3)
		           array[2].algorithm(q);
		          else if(q==4)
		           array[3].algorithm(q);
				  else if(q==5)
		           array[4].algorithm(q);
				  else if(q==6)
		           array[5].algorithm(q);
				  else if(q==7)
		           array[6].algorithm(q);
				  else if(q==8)
		           array[7].algorithm(q);
				  else if(q==9)
		           array[8].algorithm(q);
				  else if(q==10)
		           array[9].algorithm(q);
			   
				  array[0].writefile();
                  sample[0].writefile(); //writes into file
			      break;

		 case 2:  sample[0].disp();
		          break;

		 case 3: cout<<"\nPlease select a class\n1. 12A   2. 12B   3. 11A   4. 11B   5. 10A\n6. 10B   7. 10C   8. 9A   9. 9B    10. 9C   \nEnter Your option: ";
				 cin>>q;
		         if(q==1)
                  array[0].display();
				 else if(q==2)
                  array[1].display();
	             else if(q==3)
                  array[2].display();
	             else if(q==4)
                  array[3].display();
				 else if(q==5)
                  array[4].display();
				 else if(q==6)
                  array[5].display();
				 else if(q==7)
                  array[6].display();
				 else if(q==8)
                  array[7].display();
				 else if(q==9)
                  array[8].display();
				 else if(q==10)
                  array[9].display();
                 break;
				 
		 case 4: exit(0);
		}		 
		 
		 cout<<"\nContinue? (y/n): ";
		 cin>>ans;
		 clrscr();
	 }while(ans!='n');
}        

 
