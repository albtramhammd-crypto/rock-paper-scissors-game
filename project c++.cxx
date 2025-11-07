#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
enum engamechoice{stone=1,paper=2,scissors=3};
enum enwinner{player1=1,computer=2,draw=3};


struct stroundinfo
{
  short roundnumber=0;
  engamechoice player1choice;
  engamechoice computerchoice;
  enwinner winner;
  string winnername;
};

struct stgameresults
{
short gamerounds=0;
short player1wintimes=0;
short computerwintimes=0;
short drawtimes=0;
enwinner gamewinner;  
string winnername=" ";
};
  
int randomnumber(int from,int to)    
{
int random=rand()%(to-from+1)+from;
return random;    
}

      
            
                        
 string winnername(enwinner winner)
{
string arrwinnername[3] ={"player1","computer","no winner"};
  
return arrwinnername[winner-1];
  } 

 
  
    enwinner  whowontherounds(stroundinfo roundinfo)
{
if(roundinfo.player1choice==roundinfo.computerchoice)
{
return enwinner::draw;
}
switch(roundinfo.player1choice)
{
case engamechoice::stone:
if(roundinfo.computerchoice==engamechoice::paper)
{
return enwinner::computer;
}
break;
case engamechoice::paper:
if(roundinfo.computerchoice==engamechoice::scissors)
{
return enwinner::computer;
}
break;
case engamechoice::scissors:
if(roundinfo.computerchoice==engamechoice::stone)
{
return enwinner::computer;
}
break;
}
return enwinner::player1;
}



string choicename  (engamechoice choice)
{
  string arrgamechoices[3]={"stone", "paper" , "scissors"};
  
  return arrgamechoices[choice -1];
}






void setwinnerscreencolor(enwinner winner)
{
  switch(winner)
 { 
  case enwinner::player1:
  system("color 2F");
break;
    case enwinner::computer:
  system("color 4F");
  break;
  default :
  system("color 6F");
  break;
 }
  }








void printroundresults(stroundinfo roundinfo)
{
cout<<"\n____________________round["<<roundinfo.roundnumber<<"]_______________\n\n";
cout<<"player1    choice:"<<choicename(roundinfo.player1choice)<<endl;
cout<<" computer choice:"<<choicename(roundinfo.computerchoice)<<endl;
cout<<"round winner:["<<roundinfo.winnername<<"]\n";
cout<<"_______________________________\n"<<endl;

setwinnerscreencolor(roundinfo.winner);
}


enwinner whowonthegame(short player1wintimes , short computerwintimes)
{
if(player1wintimes>computerwintimes)
{
  return enwinner::player1;
}
else if(computerwintimes>player1wintimes)
{
return enwinner::computer;
}
else
{
  return enwinner::draw;
}
}







stgameresults fillgameresults(int gamerounds,short player1wintimes,short computerwintimes,short drawtimes )
{
stgameresults    gameresults;
  
  gameresults.gamerounds=gamerounds;
  gameresults.player1wintimes=player1wintimes;
  gameresults.computerwintimes=computerwintimes;
  gameresults.drawtimes=drawtimes;
  gameresults.gamewinner=whowonthegame(player1wintimes,computerwintimes);
   gameresults.winnername=winnername(gameresults.gamewinner);

return gameresults;
}




engamechoice readplayer1choice()
{
short choice=1;
do
{
  cout<<"your choice:[1]stone,   [2]paper,   [3]scissors?";
  cin>>choice;
}while(choice<1|| choice>3);
return (engamechoice)choice;
}



engamechoice getcomputerchoice()
{
return (engamechoice)randomnumber(1,3);
}








stgameresults playgame(short howmanyrounds)
{
stroundinfo roundinfo;
short player1wintimes=0,computerwintimes=0,drawtimes=0,gameround=0;
for(short gameround=1;gameround<=howmanyrounds;gameround++)
{
  cout<<"\nround["<<gameround<<"] begins:\n";
  roundinfo.roundnumber=gameround;
  roundinfo.player1choice=readplayer1choice();
  roundinfo.computerchoice=getcomputerchoice();
  roundinfo.winner=whowontherounds(roundinfo);
  roundinfo.winnername=winnername(roundinfo.winner);
  
  
  
  if(roundinfo.winner==enwinner::player1)
  player1wintimes++;
  else if(roundinfo.winner==enwinner::computer)
  computerwintimes++;
  else
  drawtimes++;
  printroundresults(roundinfo);
}
return fillgameresults(howmanyrounds,player1wintimes,computerwintimes,drawtimes);
}





string Tabs(short numberoftabs)
{
string t=" ";  
  
  for(int i=1;i<numberoftabs;i++)
 {
   t=t+"\t";
   
 } 
return t;
}












void showfinalgameresults(stgameresults gameresults)
{
cout<<Tabs(2)<<"_________________[game results]_____________\n\n";
cout<<Tabs(2)<<"game rounds               :"<<gameresults.gamerounds<<endl;
cout<<Tabs(2)<<"player1 win     times   :"<<gameresults.player1wintimes<<endl;
cout<<Tabs(2)<<"computer  win  times :"<<gameresults.computerwintimes<<endl;
cout<<Tabs(2)<<"draw   times                 :"<<gameresults.drawtimes<<endl;
cout<<Tabs(2)<<"final winner                  :"<<gameresults.winnername<<endl;
setwinnerscreencolor(gameresults.gamewinner);
}




void showgameoverscreen()
{
cout<<Tabs(2)<<"______________________\n\n";
cout<<Tabs(2)<<"        ++ G a m  e   +++\n";
cout<<Tabs(2)<<"________________________\n\n";

}





short readhowmanyrounds()
{
 short gamerounds=1;
 do{
  cout<<"how many rounds 1 to 10?\n";
  cin>>gamerounds;
}while(gamerounds<1||gamerounds>10);
return gamerounds;
}








void resetscreen ()
{
  system("cls");
  system("color 0F");
  
}





void startgame()
{
char playagain='Y';
do{
  resetscreen();
  stgameresults gameresults = playgame(readhowmanyrounds());
  showgameoverscreen();
   showfinalgameresults(gameresults);

cout<<endl<<Tabs(3)<<"do you want to play again y/N";
cin>>playagain;
}while (playagain=='Y'||playagain=='y');
}






int main()
{
	srand((unsigned)time(NULL));


startgame();
}
