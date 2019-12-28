#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int RACE_END = 70;

void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr );
void moveTortoise( int *const );
void moveHare( int * const );

int main()
{
    int tortoise=1;
    int hare = 1;
    srand( time( 0 ) );
    clock_t start,end;
    
    start=clock();
    while ( tortoise != RACE_END && hare != RACE_END ) 
   {
      Sleep( 100 );
      system("cls");
	      
      moveTortoise( &tortoise );
      moveHare(&hare);
      printCurrentPositions( &tortoise, &hare );
   }
   end=clock();
	if(tortoise>hare){
		cout<<"TORTOISE WINS!!! YAY!!!";
	}
	else if(tortoise<hare)
		cout<<"Hare wins. Yuch.";
	else
		cout<<"It's a tie!";
	cout<<endl;
	cout<<"TIME ELAPSED = "<<(end-start)/1000<<" seconds";
}

/*印出烏龜與兔子位置*/
void printCurrentPositions( const int * const snapperPtr, const int * const bunnyPtr )
{
	for(int i=1;i<=7;i++){
		cout<<"---------|";
	}
	cout<<endl;
	cout<<setw(*bunnyPtr)<<"H"<<endl;
	cout<<setw(*snapperPtr)<<"T"<<endl;
}

/*移動烏龜*/
void moveTortoise( int * const turtlePtr )
{
	int a;
	a=rand()%10;
	*turtlePtr+=(a<3)?1:(a<5)?-6:3;
	*turtlePtr=(*turtlePtr>70)?70:(*turtlePtr<0)?0:*turtlePtr;
}

/*移動兔子*/
void moveHare( int * const rabbitPtr )
{
	int a;
	a=rand()%10;
	*rabbitPtr+=(a<2)?0:(a<4)?9:(a<5)?-12:(a<8)?1:-2;
	*rabbitPtr=(*rabbitPtr>70)?70:(*rabbitPtr<0)?0:*rabbitPtr;
}
