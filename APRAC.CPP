#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <process.h>
#include<dos.h>

void down(int p);

void getpos(int sx,int sy,int b);

void windo1();

  int ladder[5][2]={{10,28},{17,37},{32,62},{45,84},{78,97}};
  int snake[5][2]={{34,16},{44,21},{68,47},{79,60},{95,73}};
  int one_dice=0,prev1_dice=0,prev2_dice=0,sec_dice=0;
  void *d1,*d2;

 unsigned int sd1,sd2;

		union REGS i,o;
		void initmouse()
		{
			i.x.ax=0;
			int86(0x33,&i,&o);
		}

		void showmouseptr()
		{
			i.x.ax=1;
			int86(0x33,&i,&o);
		}

		void hidemouseptr()
		{
			i.x.ax=2;
			int86(0x33,&i,&o);
		}


		void getmousepos(int *button,int *x,int *y)
		{
			i.x.ax=3;
			int86(0x33,&i,&o);

			*button=o.x.bx;
			*x=o.x.cx;
			*y=o.x.dx;
		}

		void restrictmouseptr(int x1,int y1,int x2,int y2)
		{
			i.x.ax=7;
			i.x.cx=x1;
			i.x.dx=x2;
			int86(0x33,&i,&o);
			i.x.ax=8;
			i.x.cx=y1;
			i.x.dx=y2;
			int86(0x33,&i,&o);
		}


void up(int x,int y,int w,int z)
      {
      setcolor(7);
      line(x,y,w,y);
      line(x,y,x,z);
      setcolor(0);
      line(w,y,w,z);
      line(x,z,w,z);
      }

void dow(int x,int y,int w,int z)
      {
      setcolor(0);
      line(x,y,w,y);
      line(x,y,x,z);
      setcolor(7);
      line(w,y,w,z);
      line(x,z,w,z);
     }

void bcreate(int x,int y,int w,int z,int col)
      {

	setcolor(7);
	rectangle(x,y,w,z);
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	rectangle(x+1,y+1,w,z);
	floodfill(x+5,y+5,8);


}


void createwindo(int x,int y,int w,int z,int col)
      {
	setcolor(8);
	rectangle(x,y,w,z);
	setcolor(7);
	setfillstyle(SOLID_FILL,8);
	rectangle(x+1,x+1,w-1,z-1);
	floodfill(x+3,y+3,7);
	setcolor(7);
	setfillstyle(SOLID_FILL,col);
	rectangle(x+30,y+30,w-20,z-20);
	floodfill(x+32,y+32,7);

	setfillstyle(SOLID_FILL,8);
	settextstyle(DEFAULT_FONT,0,1);
	setcolor(0);
	rectangle(249,7,386,22);
	setcolor(15);
	rectangle(250,8,385,21);
	rectangle(248,6,387,23);
	setfillstyle(1,0);
	floodfill(307,13,15);
	outtextxy(260,12,"SNAKE & LADDERS ");
	settextstyle(SMALL_FONT,0,4);
	setcolor(2);

	bcreate(530,53,615,85,15);
	bcreate(530,90,615,111,15);

	bcreate(528,400,614,440,11);
	bcreate(528,348,614,388,11);

	bcreate(468,150,562,170,0);
	bcreate(468,175,562,195,0);


	settextstyle(0,0,0);
	setcolor(0);

	setfillstyle(5,3);
	floodfill(473,244,0);
	setfillstyle(4,3);
	floodfill(541,240,0);
	setfillstyle(9,11);
	floodfill(524,230,0);

	setcolor(15);
	setfillstyle(1,12);

	floodfill(514,205,15);
	floodfill(541,223,15);

	setcolor(15);


	outtextxy(487,264,"SCORE");
	outtextxy(472,139,"Mode :");


	setfillstyle(1,4);
	bar(509,363,490,373);
	setfillstyle(1,14);
	bar(509,414,491,424);

	setcolor(15);
	outtextxy(492,304,"0");
	outtextxy(566,304,"0");
	outtextxy(492,157,"Single");
	outtextxy(462,279,"Player-1");
	outtextxy(538,279,"Player-2");

	setcolor(7);
	outtextxy(492,182,"Double");



	setcolor(15);
	outtextxy(536,357,"Player-1");
	outtextxy(536,370,"ROLL DICE");
	outtextxy(536,409,"Player-2");
	outtextxy(536,422,"ROLL DICE");
	outtextxy(541,65,"NEW GAME");
	outtextxy(537,98,"  EXIT  ");

	line(535,366,602,366);
	line(535,418,602,418);
}


void board()
{
int i,j,x=73,y=76;
char cc[3],num=100;
int m=2;
{
setbkcolor(RED);
setcolor(BLUE);

rectangle(60,60,440,440);
line(98,60,98,440);
line(136,60,136,440);
line(174,60,174,440);
line(212,60,212,440);
line(250,60,250,440);
line(288,60,288,440);
line(326,60,326,440);
line(364,60,364,440);
line(402,60,402,440);

line(60,98,440,98);
line(60,136,440,136);
line(60,174,440,174);
line(60,212,440,212);
line(60,250,440,250);
line(60,288,440,288);
line(60,326,440,326);
line(60,364,440,364);
line(60,402,440,402);
}

setcolor(WHITE);

   outtextxy(70, 430, "10    9    8    7    6    5    4    3    2   1");
   outtextxy(70, 390, "20   19   18   17   16   15   14   13  12   11");
   outtextxy(70, 350, "30   29   28   27   26   25   24   23  22   21");
   outtextxy(70, 315, "40   39   38   37   36   35   34   33  32   31");
   outtextxy(70, 275, "50   49   48   47   46   45   44   43  42   41");
   outtextxy(70, 235, "60   59   58   57   56   55   54   53  52   51");
   outtextxy(70, 200, "70   69   68   67   66   65   64   63  62   61");
   outtextxy(70, 165, "80   79   78   77   76   75   74   73  72   71");
   outtextxy(70, 120, "90   89   88   87   86   85   84   83  82   81");
   outtextxy(70, 85, "100  99   98   97   96   95   94   93  92   91");

   //ladder
   {
       line(200,90,170,160);
       line(190,90,160,160);
       line(186,100,194,100);
        line(177,120,186,120);
        line(168,140,177,140);

        line(320,130,280,270);
        line(310,130,270,270);
        line(305,150,315,150);
        line(299,170,309,170);
        line(293,190,303,190);
        line(288,210,298,210);
        line(282,230,292,230);
        line(276,250,286,250);


        line(400,200,400,300);
        line(390,200,390,300);
         line(390,280,400,280);
          line(390,260,400,260);
           line(390,240,400,240);
            line(390,220,400,220);

        line(180,300,180,380);
         line(190,300,190,380);
         line(190,315,180,315);
         line(190,330,180,330);
         line(190,350,180,350);
         line(190,365,180,365);

        line(150,340,60,430);
        line(170,340,80,430);
        line(130,360,150,360);
        line(110,380,130,380);
        line(90,400,110,400);

   }

   //snacks
setfillstyle(9,5);
setcolor(1);
fillellipse(242,382,2,2);
fillellipse(246,379,2,2);
fillellipse(247,379,2,2);
fillellipse(249,378,2,2);
fillellipse(252,375,2,2);
fillellipse(251,370,2,2);
fillellipse(250,365,2,2);
fillellipse(248,354,3,2);
fillellipse(248,362,3,2);
fillellipse(245,358,3,2);
fillellipse(252,351,3,2);
fillellipse(261,351,3,2);
fillellipse(266,353,3,2);
fillellipse(284,348,3,2);
fillellipse(288,340,3,2);
fillellipse(275,351,3,2);
fillellipse(285,336,3,2);
fillellipse(283,329,3,2);
fillellipse(284,319,3,2);
fillellipse(287,317,3,2);
fillellipse(257,350,3,2);
fillellipse(270,352,3,2);
fillellipse(281,350,3,2);
fillellipse(286,345,2,2);
fillellipse(285,333,2,2);
fillellipse(283,323,2,2);
fillellipse(291,316,2,2);
fillellipse(295,316,2,2);



fillellipse(420,358,3,2);
fillellipse(415,357,3,2);
fillellipse(404,350,3,2);
fillellipse(398,343,3,2);
fillellipse(392,335,3,2);
fillellipse(374,319,3,2);
fillellipse(362,315,3,2);
fillellipse(346,317,3,2);
fillellipse(333,313,3,2);
fillellipse(325,304,3,2);
fillellipse(319,293,3,2);
fillellipse(315,284,3,2);
fillellipse(316,289,3,2);
fillellipse(315,280,3,2);
fillellipse(321,298,3,2);
fillellipse(327,308,3,2);
fillellipse(323,301,3,2);

fillellipse(330,311,3,2);
fillellipse(337,315,3,2);
fillellipse(341,317,3,2);
fillellipse(352,317,3,2);
fillellipse(357,316,3,2);
fillellipse(368,313,3,2);
fillellipse(373,315,3,2);
fillellipse(374,323,3,2);
fillellipse(374,326,3,2);
fillellipse(375,330,3,2);
fillellipse(378,334,3,2);
fillellipse(383,334,3,2);
fillellipse(388,335,3,2);
fillellipse(393,337,3,2);
fillellipse(397,339,3,2);
fillellipse(399,348,3,2);
fillellipse(408,352,3,2);
fillellipse(411,354,3,2);

fillellipse(155,205,3,2);
fillellipse(158,207,3,2);
fillellipse(162,209,3,2);
fillellipse(170,227,3,2);
fillellipse(169,219,3,2);
fillellipse(169,236,3,2);
fillellipse(169,247,3,2);
fillellipse(173,257,3,2);
fillellipse(181,264,3,2);
fillellipse(175,260,3,2);
fillellipse(165,212,3,2);
fillellipse(168,216,3,2);
fillellipse(171,222,3,2);
fillellipse(170,231,3,2);
fillellipse(170,241,3,2);
fillellipse(172,252,3,2);
fillellipse(178,262,3,2);
fillellipse(184,266,3,2);


fillellipse(86,225,3,2);
fillellipse(90,221,3,2);
fillellipse(95,217,3,2);
fillellipse(101,212,3,2);
fillellipse(105,204,3,2);
fillellipse(106,196,3,2);
fillellipse(106,189,3,2);
fillellipse(106,179,3,2);
fillellipse(109,170,3,2);
fillellipse(112,164,3,2);
fillellipse(109,167,3,2);
fillellipse(107,174,3,2);
fillellipse(106,184,3,2);
fillellipse(106,194,3,2);
fillellipse(105,200,3,2);
fillellipse(103,208,3,2);
fillellipse(98,215,3,2);
fillellipse(92,219,3,2);
fillellipse(88,222,3,2);

fillellipse(285,87,3,2);
fillellipse(289,89,3,2);
fillellipse(295,91,3,2);
fillellipse(300,97,3,2);
fillellipse(305,104,3,2);
fillellipse(311,109,3,2);
fillellipse(320,113,3,2);
fillellipse(330,117,3,2);
fillellipse(338,122,3,2);
fillellipse(342,127,3,2);
fillellipse(345,132,3,2);
fillellipse(347,138,3,2);
fillellipse(350,142,3,2);
fillellipse(350,145,3,2);
fillellipse(298,93,3,2);
fillellipse(302,101,3,2);
fillellipse(307,107,3,2);
fillellipse(315,113,3,2);
fillellipse(325,112,3,2);
fillellipse(334,119,3,2);
fillellipse(340,125,3,2);
fillellipse(328,114,3,2);
}


void splash()
{
     clrscr();
     int j,t,sx,sy,b,nex,star;
     char dd[15];


bar(105,105,getmaxx()-125,getmaxy()-105);

bar(105,105,195,getmaxy()-105);
setcolor(0);
rectangle(106,106,getmaxx()-126,getmaxy()-106);
setfillstyle(1,12);

settextstyle(0,0,2);
setcolor(2);
outtextxy(116,129,"SNACK");
outtextxy(116,149,"&");
outtextxy(116,169,"LADDER");

setcolor(6);
outtextxy(114,128,"SNACK");
outtextxy(114,148,"&");
outtextxy(114,168,"LADDER");

   settextstyle(0,0,1);
   setcolor(7);
   outtextxy(243,137,"THE UPS AND DOWN");
   outtextxy(259,218,"OF VIRTUAL LIFE..");

   setcolor(8);
   outtextxy(241,135,"THE UPS AND DOWN");
   outtextxy(257,216,"OF VIRTUAL LIFE..");

   outtextxy(200,600,"www.FACEBOOK.com/KAZI.KHU");
   settextstyle(2,0,0);
   outtextxy(280,259,"KAZI SHAMIM SHAHAREAR ISLAM");
   outtextxy(230,250,"Developed by");
   setcolor(7);

   outtextxy(187,344,"1.02");





  nex=224;
  star=2;
 for(j=10,t=10;j<49;)
  {
  t++;
  j++;
   bar(nex,365,nex+star,368);
   nex+=star;
   nex+=2;
  delay(90);

 }
}
void splash1()

{
    clrscr();
     int j,t,sx,sy,b,nex,star;
     char dd[15];



setfillstyle(1,12);

settextstyle(0,0,2);
setcolor(2);
outtextxy(316,129,"SNACK");
outtextxy(316,149,"&");
outtextxy(316,169,"LADDER");
outtextxy(116,129,"WELCOME TO");

setcolor(6);
outtextxy(314,128,"SNACK");
outtextxy(314,148,"&");
outtextxy(314,168,"LADDER");
outtextxy(113,128,"WELCOME TO");






  nex=224;
  star=2;
 for(j=10,t=10;j<49;)
  {
  t++;
  j++;
   bar(nex,365,nex+star,368);
   nex+=star;
   nex+=2;
  delay(90);

 }
}


void sp()
{
     clrscr();
     int j,t,sx,sy,b,nex,star;
     char dd[15];

setcolor(0);
rectangle(106,106,getmaxx()-126,getmaxy()-106);
setfillstyle(1,12);

   settextstyle(0,0,1);
   setcolor(8);
   outtextxy(243,137,"Credits");
   outtextxy(116,169,"KAZI SHAMIM SHAHAREAR ISLAM");
   setcolor(2);
   outtextxy(116,179,"Department of Software Engineering");
   outtextxy(116,199,"DAFFODIL INTERNATIONAL UNIVERSITY");
   outtextxy(116,269,"BEST OF LUCK");






  nex=224;
  star=2;
 for(j=10,t=10;j<49;)
  {
  t++;
  j++;
   bar(nex,365,nex+star,368);
   nex+=star;
   nex+=2;
  delay(90);

 }
}

  void move(int x,int y,int sel)
  {
  if(sel==1)
   {
	setfillstyle(1,4);
	setcolor(14);
	rectangle(x-1,y-1,x+10,y+10);

   }
  else
  {
	setfillstyle(1,14);
	setcolor(12);
	rectangle(x-1,y-1,x+10,y+10);

  }

	bar(x,y,x+9,y+9);


  }


void changeposition(int num,int player)
{
       num--;
       if(player==1)
       move(417-(num%10*38),427-(num/10*38),1);
       if(player==2)
       move(417-(num%10*38),405-(num/10*38),2);
}


void saveimageportion(int num,int player)
{


  if(player==1)
   {
    sd1=imagesize(416-(num%10*38),426-(num/10*38),(417-(num%10*38))+10,(427-(num/10*38))+10);
    d1 = malloc(sd1);
    getimage(416-(num%10*38),426-(num/10*38),(417-(num%10*38))+10,(427-(num/10*38))+10,d1);
   }

  if(player==2)
    {

     sd2=imagesize(416-(num%10*38),404-(num/10*38),(417-(num%10*38))+10,(407-(num/10*38))+10);
     d2 = malloc(sd2);
     getimage(416-(num%10*38),404-(num/10*38),(417-(num%10*38))+10,(407-(num/10*38))+10,d2);

    }

}


void putimageportion(int num,int player)
{

  if(player==1)
   {
    putimage(416-(num%10*38),426-(num/10*38),d1,0);
   }

  if(player==2)
    {
     putimage(416-(num%10*38),404-(num/10*38),d2,0);
    }


}


void dicerun(int num)
{
    setcolor(12);
    setfillstyle(1,12);
    bar(508,209,537,226);
    setcolor(15);
    setfillstyle(1,15);

    if(num==1)
    fillellipse(522,217,3,1);

    if(num==2)
    {
	fillellipse(511,211,3,1);
	fillellipse(533,224,3,1);
    }

    if(num==3)
    {
    fillellipse(511,211,3,1);
    fillellipse(533,224,3,1);
    fillellipse(522,217,3,1);

    }
    if(num==4)
    {
    fillellipse(511,211,3,1);
    fillellipse(511,224,3,1);
    fillellipse(533,211,3,1);
    fillellipse(533,224,3,1);

    }
    if(num==5)
    {
    fillellipse(511,211,3,1);
    fillellipse(511,224,3,1);
    fillellipse(533,211,3,1);
    fillellipse(533,224,3,1);
    fillellipse(522,217,3,1);

    }
    if(num==6)
    {
    fillellipse(511,211,3,1);
    fillellipse(511,217,3,1);
    fillellipse(511,224,3,1);
    fillellipse(533,211,3,1);
    fillellipse(533,217,3,1);
    fillellipse(533,224,3,1);
    }

}

void main()
{
	int gd=DETECT,gm;
	int i,j,b,sx,sy,z,col,x1,y1,w1,z1;
	char dd[20],dc[5];
	int num;
	int dice=0,k,l,chance=1,selemode=1,end=0;
	int one_dice=0,prev1_dice=0,prev2_dice=0,sec_dice=0;
	void *d1,*d2,*result;
	unsigned int sd1,sd2,resarea;

	initmouse();

 initgraph(&gd, &gm, "C:/TURBOC3/BGI");
	w1=getmaxx(),z1=getmaxy();
	x1=0;
	y1=0;

	splash1();
	splash();
	sp();
	cleardevice();
	createwindo(x1,y1,w1,z1,9);
	board();
	showmouseptr();



while(1)
{



	getmousepos(&b,&sx,&sy);

	if(b==1&&sx>468&&sy>150&&sx<562&&sy<170)
	{
	settextstyle(0,0,0);
	hidemouseptr();
	setcolor(7);
	outtextxy(492,182,"Double");
	setcolor(15);
	outtextxy(492,157,"Single");
	showmouseptr();
	selemode=1;
	end=0;
	 one_dice=0;
	 sec_dice=0;
	 putimageportion(prev1_dice,1);
	 putimageportion(prev2_dice,2);
	 chance=1;
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	setcolor(0);

	setcolor(15);

    setcolor(12);
    setfillstyle(1,12);
    bar(508,209,537,226);
	}

	if(b==1&&sx>468&&sy>175&&sx<562&&sy<195)
	{
	hidemouseptr();
	setcolor(15);
	outtextxy(492,182,"Double");
	setcolor(7);
	outtextxy(492,157,"Single");
	showmouseptr();
	selemode=2;
	end=0;
	 one_dice=0;
	 sec_dice=0;
	 putimageportion(prev1_dice,1);
	 putimageportion(prev2_dice,2);
	 chance=1;
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	setcolor(0);

	setcolor(15);

    setcolor(12);
    setfillstyle(1,12);
    bar(508,209,537,226);
	}



	if(b==1&&sx>530&&sy>53&&sx<615&&sy<85)
	{
	settextstyle(0,0,0);
	end=0;
	 one_dice=0;
	 sec_dice=0;
	 putimageportion(prev1_dice,1);
	 putimageportion(prev2_dice,2);
	 chance=1;
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	setcolor(0);

	setcolor(15);

    setcolor(12);
    setfillstyle(1,12);
    bar(508,209,537,226);

	}


	if(b==1)
	{

	if(end==0&&chance==1&&b==1&&sx>528&&sy>348&&sx<614&&sy<388)
	{
	dice=0;
	while(b==1)
	{
	getmousepos(&b,&sx,&sy);
	dice++;
	if(dice==7)
	dice=1;
	}
	dicerun(dice);


       hidemouseptr();
	if(dice==6)
	{
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	chance=1;
	}
	else
	{
	setcolor(9);
	rectangle(528,348,614,388);
	setcolor(15);
	rectangle(528,400,614,440);
	chance=2;
	}
       showmouseptr();
	one_dice+=dice;

	for(i=0;i<5;i++)
	for(j=0;j<1;j++)
	{
	 if(ladder[i][j]==one_dice)
	  one_dice=ladder[i][1];
	 if(snake[i][j]==one_dice)
	  one_dice=snake[i][1];

	}
	sound(400);
	delay(500);
	nosound();

	if(one_dice<=100)
	{
	num=one_dice;
	num--;
	putimageportion(prev1_dice,1);
	saveimageportion(num,1);
	changeposition(one_dice,1);
	prev1_dice=one_dice-1;
	}
	else
	{
	one_dice-=dice;
	}

	sprintf(dc,"%d",one_dice);

	setcolor(0);

	setcolor(15);
	outtextxy(485,304,dc);


	if(one_dice==100)
	{
	end=1;

	hidemouseptr();
	resarea=imagesize(190,170,435,320);
	result=malloc(resarea);
	getimage(190,170,435,320,result);

	setfillstyle(1,0);
	setcolor(15);
	rectangle(190,170,435,320);
	bar(191,171,434,319);
	outtextxy(258,242,"PLAYER 1 WON");
	rectangle(369,272,415,280);
	rectangle(378,261,404,271);
	line(378,261,384,255);
	line(384,255,377,209);
	line(405,209,399,255);
	line(399,255,404,261);
	ellipse(391,209,0,360,14,3);
	setfillstyle(1,8);
	floodfill(391,234,15);
	setfillstyle(1,4);
	floodfill(386,267,15);
	setfillstyle(1,1);
	floodfill(386,276,15);
	setfillstyle(1,7);
	floodfill(391,208,15);
	settextstyle(2,0,0);
	setcolor(14);
	outtextxy(280,303,"press any key to continue..");
	getch();
	putimage(190,170,result,0);
	free(result);
	showmouseptr();
	}
	settextstyle(0,0,0);
	}

if(selemode==2&&end==0&&chance==2&&b==1&&sx>528&&sy>400&&sx<614&&sy<440)
	{

	dice=0;
	while(b==1)
	{
	getmousepos(&b,&sx,&sy);
	dice++;
	if(dice==7)
	dice=1;
	}
	dicerun(dice);

       hidemouseptr();
	if(dice==6)
	{
	setcolor(9);
	rectangle(528,348,614,388);
	setcolor(15);
	rectangle(528,400,614,440);
	chance=2;
	}
	else
	{
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	chance=1;
	}

	showmouseptr();
	sec_dice+=dice;

	for(i=0;i<5;i++)
	for(j=0;j<1;j++)
	{
	 if(ladder[i][j]==sec_dice)
	  sec_dice=ladder[i][1];
	 if(snake[i][j]==sec_dice)
	  sec_dice=snake[i][1];

	}
	sound(400);
	delay(500);
	nosound();


	if(sec_dice<=100)
	{
	num=sec_dice;
	num--;
	putimageportion(prev2_dice,2);
	saveimageportion(num,2);
	changeposition(sec_dice,2);
	prev2_dice=sec_dice-1;
	}
	else
	{
	sec_dice-=dice;
	}


	sprintf(dc,"%d",sec_dice);
	setcolor(0);

	setcolor(15);
	outtextxy(557,304,dc);


	if(sec_dice==100)
	{
	end=1;
	hidemouseptr();
	resarea=imagesize(190,170,435,320);
	result=malloc(resarea);
	getimage(190,170,435,320,result);

	setfillstyle(1,0);
	setcolor(15);
	rectangle(190,170,435,320);
	bar(191,171,434,319);
	outtextxy(258,242,"PLAYER 2 WON");
	rectangle(369,272,415,280);
	rectangle(378,261,404,271);
	line(378,261,384,255);
	line(384,255,377,209);
	line(405,209,399,255);
	line(399,255,404,261);
	ellipse(391,209,0,360,14,3);
	setfillstyle(1,8);
	floodfill(391,234,15);
	setfillstyle(1,4);
	floodfill(386,267,15);
	setfillstyle(1,1);
	floodfill(386,276,15);
	setfillstyle(1,7);
	floodfill(391,208,15);
	settextstyle(2,0,0);
	setcolor(14);
	outtextxy(280,303,"press any key to continue..");
	getch();
	putimage(190,170,result,0);
	free(result);
	showmouseptr();

	}

	}
else
	if(selemode==1&&end==0&&chance==2)
	{


	dice=random(6);
	if(dice==0)
	dice=1;
	dicerun(dice);
	hidemouseptr();
	if(dice==6)
	{
	setcolor(9);
	rectangle(528,348,614,388);
	setcolor(15);
	rectangle(528,400,614,440);
	chance=2;
	}
	else
	{
	setcolor(15);
	rectangle(528,348,614,388);
	setcolor(9);
	rectangle(528,400,614,440);
	chance=1;
	}

	showmouseptr();
	sec_dice+=dice;

	for(i=0;i<5;i++)
	for(j=0;j<1;j++)
	{
	 if(ladder[i][j]==sec_dice)
	  sec_dice=ladder[i][1];
	 if(snake[i][j]==sec_dice)
	  sec_dice=snake[i][1];

	}
	sound(200);
	delay(500);
	sound(300);
	delay(200);
	sound(500);
	delay(100);
	nosound();


	if(sec_dice<=100)
	{
	num=sec_dice;
	num--;
	putimageportion(prev2_dice,2);
	saveimageportion(num,2);
	changeposition(sec_dice,2);
	prev2_dice=sec_dice-1;
	}
	else
	{
	sec_dice-=dice;
	}


	sprintf(dc,"%d",sec_dice);

	setcolor(15);
	outtextxy(557,304,dc);


	if(sec_dice==100)
	{
	end=1;
		hidemouseptr();
	resarea=imagesize(190,170,435,320);
	result=malloc(resarea);
	getimage(190,170,435,320,result);

	setfillstyle(1,0);
	setcolor(15);
	rectangle(190,170,435,320);
	bar(191,171,434,319);
	outtextxy(258,242,"You Lost");
	rectangle(369,272,415,280);
	rectangle(378,261,404,271);
	line(378,261,384,255);
	line(384,255,377,209);
	line(405,209,399,255);
	line(399,255,404,261);
	ellipse(391,209,0,360,14,3);
	setfillstyle(1,8);
	floodfill(391,234,15);
	setfillstyle(1,4);
	floodfill(386,267,15);
	setfillstyle(1,1);
	floodfill(386,276,15);
	setfillstyle(1,7);
	floodfill(391,208,15);
	settextstyle(2,0,0);
	setcolor(14);
	outtextxy(280,303,"Press any key to continue..");
	getch();
	putimage(190,170,result,0);
	free(result);
	showmouseptr();
	}

	}
    }
	if(b==1&&sx>530&&sy>90&&sx<615&&sy<111)
	{
	break;
	}
}
 closegraph();
 restorecrtmode();

 //this code is ended by KAZI SHAMIM  SHAHAHREAR ISLAM
}

