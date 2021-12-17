#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<windows.h>

#include<cstdlib>
#include<time.h>
using namespace std;
int s = 0; //score for game.
const int m = 200;//array size.
const int n = 100;//array size.
int gridsize, mines, row, column;
char arr[m][n], sys[m][n];
int score(int &s); //score function.
void placeorremoveflag(); //put flag for the mine.
void display(); //display the menu.
void startgame(); //print table..
void gameplay(); //for play game and open cells.
void minecheck(int, int); //if a cell had a mine check then add 1 in his neighbour.
void show();//when we open a cell and it had a mine then open all the cells which have mine.
void reveal(int, int);//when we open a cell and this cell has no mine near it than open it neighbour cells.
int  flagcounter = 0; //to count flag.
int minesflagcounter = 0;//to count mines flag.
bool gamewin();// check game win.
bool gamelose = false; // check game lose.
int x=0;
void minesweeper();
void full();

void printsiditriangle(int );
void printultitriangle(int );

void printrighttriangle(int );
void printhalfdiamond(int );
void printfulldiamond(int );
double add(double  , double );
double subtraction (double ,double );
double multiplication(double ,double);
double division (double ,double );

void menuofcalculatar()
{
	int choice1;
	double v,x;
	double sum,divide,sub,multiply;
	bool p=false;
	do
	{
	
	cout<<"press 9 to addition"<<endl;
	cout<<"press 10 to subtraction"<<endl;
	cout<<"press 11 to multiplication"<<endl;
	cout<<"press 12 to division"<<endl;
	cout<<"press 13 to play game"<<endl;
	cout<<"press 14 to go back "<<endl;
	cout<<"enter choice1 to calculate"<<endl;
	cin>>choice1;
	if(choice1!=9 && choice1!=10 && choice1!=11 && choice1!=12&&choice1!=13)
	{
		cout<<"invalide input"<<endl;
		menuofcalculatar();
	}
	

	switch(choice1)
	{
	case 9:
		cout<<"enter the number v"<<endl;
	cin>>v;
	cout<<"enter the number x"<<endl;
	cin>>x;
	cout<<"sum is:"<<add(v,x)<<endl;
	break;
	case 10:
		cout<<"enter the number v"<<endl;
	cin>>v;
	cout<<"enter the number x"<<endl;
	cin>>x;
	cout<<"subtraction is :"<<subtraction(v,x) <<endl;
	break;

	case 11:
		cout<<"enter the number v"<<endl;
	cin>>v;
	cout<<"enter the number x"<<endl;
	cin>>x;
	cout<<"multiplication is :"<<multiplication(v,x) <<endl;
	break;
	case 12:
		cout<<"enter the number v"<<endl;
	cin>>v;
	cout<<"enter the number x"<<endl;
	cin>>x;
	cout<<"division is :"<<division(v,x)<<endl;
	break;
	case 13:
		minesweeper();
		
		break;
	case 14:
		full();
		
		break;

	}

	
	}
	while(p!=true);
}
 void full()
 {
	 
	 bool j=false; 
	 int a,b,c,e,f;
	 int choice;
	 cout<<"                                                    "<<"hello in this triangles family"<<endl;
	while(!j)
	{ cout<<"press 1:to printsiditriangle"<<endl;
	cout<<"press 2:to ptrintultitriangle"<<endl;
	cout<<"press 3:to printrighttriangle"<<endl;

	cout<<"press 4:to printhalfdiamond"<<endl;
	cout<<"press 5:to printfulldiamond"<<endl;
	cout<<"press 6:to calculate"<<endl;
	cout<<"press 7:to play game"<<endl;
	cout<<"press 8:to exit"<<endl;
	cout<<"enter choice which you want to print"<<endl;
	cin>>choice;
	
	 
	 
	switch(choice)
	{
	case 1:
		cout<<"enter a size you want to print"<<endl;
	 cin>>a;
		printsiditriangle(a);
		break;
	case 2:
		cout<<"enter a size which you want to print"<<endl;
	 cin>>b;
		printultitriangle(b);
		break;
	case 3:
		cout<<"enter the size you want to print "<<endl;
	cin>>c;
		printrighttriangle(c);
		break;
	
	case 4:
		cout<<"enter the size halfdiamond"<<endl;
		cin>>e;
		printhalfdiamond(e);
		break;
	case 5:
		cout<<"enter the size which you want to print "<<endl;
		cin>>f;
		printfulldiamond(f);
		break;
	case 6:
		menuofcalculatar();
		
		break;
	case 7:
		minesweeper();

		break;
	case 8:
		j=true;
		cout<<"exit"<<endl;
		
		break;


	}
	}

	 
	
 }
 int main()
 {
	 int m,n;
	 full();
	 cout<<"enter m to clear all and start calulatar"<<endl;
	 cin>>m;
	 system("cls");
	 menuofcalculatar();
	 cout<<"press n to clear all and start game"<<endl;
	 cin>>  n;
	 system("cls");
	 minesweeper();

	 system("pause");
	 return 0;
 }





void printsiditriangle(int a)
 {
	 
	 
	 for(int i=1;i<=a;i++)
	 {
		 for(int j=1;j<=i;j++)
		 {
			 cout<<setw(2)<<'*'<<" ";
		 }
		 cout<<endl;
	 }
}
void printultitriangle(int b)
 { 
	 
	  
  for(int i=1;i<=b;i++)
	 {
		 for(int j=b;j>=i;j--)
		 {
			 cout<<setw(2)<<'*'<<" ";
		 }
		 cout<<endl;
	
  }
 }
void printrighttriangle(int c)
{
	
int n;
n=c-1;

	for(int k=1;k<=c;k++)
	{
for(int i=1 ;i<=n;i++)
{
	cout<<"  ";
}
n--;


for(int j=1;j<=k;j++)
{
	cout<<setw(1)<<'*'<<" ";
}
cout<<"\n";
}
	cout<<endl;


}
void printhalfdiamond(int e)
{
	
int m;
m=e-1;

	for(int k=1;k<=e;k++)
	{
for(int i=1 ;i<=m;i++)
{
	cout<<"  ";
}
m--;


for(int j=1;j<=k;j++)
{
	cout<<setw(1)<<'*'<<"   ";
}
cout<<"\n";
}
	cout<<endl;


}
void printfulldiamond(int f)
{
	{int z=1;
	for(int i=1;i<=f;i++)
	{
		for(int s=1;s<=(f-i);s++)
			cout<<" ";
		if(i>=f)
		{
			break;
		}
		
		for (int j=1;j<=z;j++)
		{
			cout<<"*";
		}
		cout<<endl;
		z+=2;
	}
	for(int i=f;i>=1;i--)
	{
		for(int s=1;s<=(f-i);s++)
			cout<<" ";
		for (int j=1;j<=z;j++)
		{
			cout<<"*";
		}
		cout<<endl;
		z=z-2;
	}
	}

}


	double add(double g , double h)
{
	return g+h;
}
double subtraction (double g,double h)
{
	return g-h;
}
double multiplication(double g,double h)
{
	return g*h;
}
double division (double g,double h)
{
	return g/h;
}
void minesweeper()

{
display();
	cout << setw(150) << "\t\t\t\t\t MINESWEEPER \n\n\n";
	cout << "\tEnter size of grid\n\n";
	cin >> gridsize;
	cout << "\tEnter the number of mines\n\n";
	cin >> mines;
	startgame();
	gameplay();
	
}
void display()
{      cout<<         "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t***********************"<<endl;
	cout << setw(150) << " MINESWEEPER \n\n\n";
	          cout << "\t\t\t\t\t \t\t\t\t\t\t\t\t\t\t\t************************"<<endl;
	cout << "1.Play game\n";
	cout << "2.How to play\n";

	cout << "3.Exit\n";
	int choice;
	cin >> choice;
	ifstream out;
	string x;
	switch (choice)
	{
	case 1:
	system("cls");
		break;

	case 2:
		cout << "\tInstructions" << endl;

		out.open("instruction.txt");
		while (!out.eof())
		{
			getline(out, x);
			cout << x;
			cout << endl;
		}

		cout << " \n";

		break;

	case 3:
		cout << "Thanks for playing\n";
		cout << "Better see next time\n";
		cout << "Press twice to close\n";
		system("pause");
		break;
	case 4:
		display();
		break;
	default:
		cout << "Invalid selection\n";

	}


}
void startgame() 
{
	system("cls");
	for (int i = 0; i < gridsize; i++)
	{
		for (int j = 0; j < gridsize; j++)
		{
			arr[i][j] = 254;
			sys[i][j] = '0';
		}
	}

}
void gameplay()
{
	char ch1 = 'f';
	char ch2 = 'e';
	char choice;
	srand(time(0));
	int p, q;
	ifstream in;
	ofstream out;


	for (int i = 0; i < mines; i++)
	{
		p = rand() % gridsize;
		q = rand() % gridsize;
		if (sys[p][q] != 'M')
		{
			sys[p][q] = 'M';
		}
		else i--;
	}
	for (int i = 0; i<gridsize; i++)
	{
		for (int j = 0; j<gridsize; j++)
		{
			minecheck(i, j);
		}
	}
	do
	{
		cout<<"total mines"<<mines<<endl;
		cout << "Score = " << score(s);
		cout << setw(150) << "\t\t\t\t\t MINESWEEPER \n\n\n";
		cout << setw(2) << "   ";
		for (int i = 0; i < gridsize; i++)cout << setw(2) << i << " "; cout << endl;

		for (int i = 0; i < gridsize; i++)
		{
			cout << setw(2) << i << " ";
			for (int j = 0; j < gridsize; j++)
			{
				cout << setw(2) << arr[i][j] << " ";
			}
			cout << endl;
		}



		cout << "\nPress e to reveal" << endl;
		cout << "\nPress f to put a flag" << endl;
		cout << "\nEnter choice:  ";
		cin >> choice;
		switch (choice)
		{
		case 'e':
			cout << "\n\n  Enter the row no: \n";
			cin >> row;
			cout << "\n\n  Enter the column no: \n";
			cin >> column;
			if(sys[row][column]=='M' && x==0)
			{
				row=gridsize+row;
				column=gridsize+column;
			}
			x++;
			system("cls");
			reveal(row, column);

			if (sys[row][column] == 'M')
			{
				show();

				score(s);
				gamelose = true;
				cout << "you lose the game" << endl;
				break;
			}
			break;
		case 'f':
			system("cls");
			placeorremoveflag();
			if (gamewin())
			{
				cout << "you win the game" << endl;
				system("pause");
				exit(0);
			}
			break;

			default:
			{cout << "Inavlid choice \n";
			cout << "Enter the valid choice again\n";
			s = s - 1;
			Sleep(1450);

			system("cls");
			break;
			}

		}

		
	
	} while (gamelose != true);


}
void minecheck(int r, int c)
{
	if (sys[r][c] == 'M')
		return;
	int count = 0;
	if (sys[r - 1][c - 1] == 'M')
		count++;
	if (sys[r - 1][c] == 'M')
		count++;
	if (sys[r - 1][c + 1] == 'M')
		count++;
	if (sys[r][c - 1] == 'M')
		count++;
	if (sys[r][c + 1] == 'M')
		count++;
	if (sys[r + 1][c - 1] == 'M')
		count++;
	if (sys[r + 1][c] == 'M')
		count++;
	if (sys[r + 1][c + 1] == 'M')
		count++;

	sys[r][c] += count;


}
void show()
{ 
	cout << setw(150) << "\t\t\t\t\t MINESWEEPER \n\n\n";
	cout << setw(3) << " ";
	for (int i = 0; i < gridsize; i++)cout << setw(2) << i << " "; cout << endl;

	for (int i = 0; i < gridsize; i++)
	{
		cout << setw(2) << i << " ";
		for (int j = 0; j < gridsize; j++)
		{
			cout << setw(2) << sys[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\n\n";
}
int score(int &s)
{
	s = s + 1;
	return s;
}
void reveal(int i, int j)
{
	if (arr[i][j] == sys[i][j] || i<0 || j<0 || i>gridsize || j>gridsize)
		return;
	arr[i][j] = sys[i][j];
	if (sys[i][j] == 'M')
		return;

	if (sys[i][j] == '0')
	{
		reveal(i, j - 1);
		reveal(i, j + 1);
		reveal(i - 1, j);
		reveal(i + 1, j);
		reveal(i + 1, j - 1);
		reveal(i - 1, j + 1);
		reveal(i - 1, j - 1);
		reveal(i + 1, j + 1);
	}
}
void placeorremoveflag()
{
	int i, j;
	do
	{
		cout << "enter row " << endl;
		cin >> i;
		cout << "enter col" << endl;
		cin >> j;

	} while (i<0 || i>gridsize || j<0 || j>gridsize);
	if (arr[i][j] == static_cast<char>(254))
	{
		arr[i][j] = 'F';
		flagcounter++;
		if (sys[i][j] == 'M')
			minesflagcounter++;
	
	cout<<"flag is:"<<flagcounter<<endl;
	}
	else if (arr[i][j] = 'F')
	{
		arr[i][j] = 254;
		flagcounter--;
		if (sys[i][j] == 'M')
			minesflagcounter--;
	}
}
bool gamewin()
{
	if (flagcounter == minesflagcounter)
		return 1;
	else
		return 0;

}
