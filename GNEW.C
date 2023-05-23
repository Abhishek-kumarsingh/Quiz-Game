#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define BUFFER_SIZE 1024
void func();
void help();
int menu();
void front();
void questions();
void correct();
void incorrect1();
void incorrect2();
void incorrect3();
void incorrect4();
void select();
void pass();
void sorry();
void score();
void prevscore();
void exit1();
FILE *fin;
int flag,count=0;
int button, x1,y1;
char correctans[2];
int scr=0;
// mouse integration start
union REGS i, o;
int initmouse()
{
   i.x.ax = 0;
   int86(0X33, &i, &o);
   return ( o.x.ax );
}
void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33, &i, &o);
}
void hidemouseptr()
{
	i.x.ax=2;
	int86(0x33,&i,&o);
}
void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33, &i, &o);
   *button = o.x.bx;
   *x = o.x.cx;
   *y= o.x.dx;
}
//mouse integration end
void main()
{
    int gd=DETECT,gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    front();
    menu();
    closegraph();
}
void func()//function for starting the quiz
{
	setcolor(YELLOW);
	setlinestyle(0,3,3);
	rectangle(55, 400, 305, 420);
	delay(1000);
	cleardevice();
	setbkcolor(BLACK);
	setcolor(WHITE);
	delay(100);
	settextstyle(10, 0, 2);
	outtextxy(200,200,"QUIZ STARTS.........");
	setcolor(BLACK);
	delay(100);
	sleep(2);
	settextstyle(10, 0, 2);
	outtextxy(200,200,"QUIZ STARTS.........");
	sleep(1);
	questions();
}
void help()
{
    char ch;
    setcolor(YELLOW);
    setlinestyle(0,3,3);
    rectangle(55, 435, 305, 455);
    delay(1000);
    cleardevice();
    setbkcolor(BLACK);
	outtextxy(100, 150,"* USE MOUSE TO PLAY THE GAME") ;
	outtextxy(100, 200,"* Game will be consisting of total 15 Questions ") ;
	outtextxy(100, 250,"* Every correct answer will award you 10 points") ;
	outtextxy(100, 300,"* Incorrect answer will award you 0 points") ;
	outtextxy(100, 350,"* PRESS ENTER TO GO BACK TO THE MENU");
    while(1)
    {
		if(kbhit())
		{
			ch=getch();
			if((int)ch==13)
			{
				cleardevice();
				menu();
			}
		}
    }
}
int menu()
{
    int status,button,x,y,opt,key,p,i,n,c;
    cleardevice();
    setlinestyle(0,0,3);
	setbkcolor(CYAN);
	setcolor(BLUE);
	setfillstyle(1,BLUE);
	circle(320,165,165);
	floodfill(320,165,BLUE);
	setcolor(LIGHTBLUE);
	setfillstyle(1,LIGHTBLUE);
	circle(320,165,135);
	setcolor(0);
	setfillstyle(SLASH_FILL,0);
	//INNER CIRCLE BACKGROUND
	setlinestyle(1,0,0);
	for(p=0;p<=130;p++)
	{
	setcolor(LIGHTBLUE);
		circle(320,165,p);
		delay(10);
	}
	setlinestyle(1,0,3);
	setcolor(BLUE);
	setfillstyle(7,BLUE);
	setcolor(BLUE);
	setcolor(15);
	setfillstyle(1,15);
	setcolor(15);
	settextstyle(8,0,5);
	settextstyle(0,0,2);
	outtextxy(162,152,"A");
	outtextxy(169,118,"C");
    outtextxy(182,84,"A");
	outtextxy(205,55,"D");
	outtextxy(250,22,"Q");
	outtextxy(290,10,"U");
	outtextxy(330,10,"I");
	outtextxy(375,22,"Z");
	outtextxy(423,55,"G");
	outtextxy(443,84,"A");
	outtextxy(457,118,"M");
	outtextxy(462,152,"E");
	setlinestyle(1,0,3);
	for(i=165;i<170;i++)
	{
	    setcolor(MAGENTA);
		setfillstyle(SOLID_FILL,5);
		circle(320,165,i);
	}
	settextstyle(12,0,5);
	setcolor(10);
	setlinestyle(1,0,1);
	setcolor(YELLOW);
	settextstyle(11,0,5);
	settextstyle(0,0,5);
	outtextxy(250,150," U ");
	outtextxy(290,150," I ");
	sound(1100);
	delay(600);
	sound(1200);
	delay(500);
	outtextxy(210,150," Q ");
	outtextxy(320,150," Z ");
	sound(1000);
	delay(500);
	nosound();
    setfillstyle(SOLID_FILL,LIGHTGRAY);// the shadow parts of main bars
    bar(50, 405, 300, 425);  //first left bar
    bar(320, 405, 580, 425); // first right bar
    bar(50, 440, 300, 460);  //second left bar
    bar(320, 440, 580, 460); //second right bar
    bar(170, 370, 450, 390); // top most bar in center
    setfillstyle(SOLID_FILL,BLUE); //the main bars
    bar(55, 400, 305, 420);;//first left bar
    bar(325, 400, 585, 420); //first right bar
    bar(55, 435, 305, 455); //second left bar
    bar(325, 435, 585, 455); //second right bar
    bar(175, 365, 455, 385); //top most bar in the center
    setcolor(WHITE);
    settextstyle(0, 0, 1);
    outtextxy(60, 407, " 1). START"); // messege on first left bar
    outtextxy(330, 407, " 2). PREVIOUS SCORES");// messege on first left bar
    outtextxy(60, 442, " 3). HELP");// messege on second left bar
    outtextxy(330, 442, " 4). EXIT"); // messege on second right bar
    outtextxy(240, 370, "SELECT YOUR CHOICE:"); // messege on top most center bar
    gotoxy(43, 24); // dimensions of input choice
    textcolor(RED);
	status = initmouse();
    if ( status == 0 )
	printf("Mouse support not available.\n");
    else
    {
	showmouseptr();
	getmousepos(&button,&x,&y);
	while(1)
	{
		getmousepos(&button,&x,&y);
		if(button==1)
		{
		    button = -1;
		    if(x>=55&&x<=300&&y>=400&&y<=425)
		    {
				opt=1;
				break;
		    }
		    else if(x>=325&&x<=585&&y>=400&&y<=425)
		    {
			    opt=2;
			    break;
		    }
		    else if(x>=55&&x<=300&&y>=435&&y<=460)
		    {
			    opt=3;
			    break;
		    }
		    else if(x>=325&&x<=585&&y>=435&&y<=460)
		    {
			    opt=4;
			    break;
		    }
		}
		else if( button == 2 )
		{
		    button = -1;
		    cleardevice();
		}
	}
   }
    switch(opt)
    {
	    case 1:
		    func();
		    break;
	    case 2:
		    prevscore();
		    break;
	    case 3:
		    help();
		    break;
	    case 4:
		    exit1();
		    break;
	    default:
		    printf("Please try again");
    }
    getch();
    return 0;
}
void front()
{
    int n,colo,i;
    setbkcolor(WHITE);
    circle(10,1,50);
    setfillstyle(HATCH_FILL, RED);
    floodfill(10,2,WHITE);
    circle(630,1,50);
    setfillstyle(HATCH_FILL, YELLOW);
    floodfill(630, 2,WHITE);
    circle(100,100,30);
    setfillstyle(HATCH_FILL, LIGHTMAGENTA);
    floodfill(100, 110, WHITE);
    circle(250, 400, 100);
    setfillstyle(HATCH_FILL, YELLOW);
    floodfill(250, 401, WHITE);
    circle(450, 400, 60);
    setfillstyle(HATCH_FILL, MAGENTA);
    floodfill(450, 400, WHITE);
    circle(400, 35, 35);
    setfillstyle(HATCH_FILL, BLUE);
    floodfill(400, 36, WHITE);
    circle(100, 450, 45);
    setfillstyle(HATCH_FILL, CYAN);
    floodfill(100, 451, WHITE);
    circle(500, 40, 30);
    setfillstyle(SLASH_FILL, GREEN);
    floodfill(500, 41, WHITE);
    circle(610,400, 70);
    setfillstyle(HATCH_FILL, GREEN);
    floodfill(610,401, WHITE);
    circle(150, 400, 20);
    setfillstyle(SLASH_FILL, BROWN);
    floodfill(150, 401, WHITE);
    circle(50, 100, 50);
    setfillstyle(HATCH_FILL, YELLOW);
    floodfill(50, 101, WHITE);
    circle(2, 429, 40);
    setfillstyle(SLASH_FILL, LIGHTRED);
    floodfill(3, 400, WHITE);
    circle(600, 200, 45);
    setfillstyle(SLASH_FILL, RED);
    floodfill(600, 201, WHITE);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(50, 100, 590, 380);//front page bar(shadow part)
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(40, 90, 580, 370);// front page bar
    setcolor(WHITE);
    settextstyle(7, 0, 4);
    outtextxy(110, 200, "WELCOME TO THE QUIZ!");
    line(100, 200, 520, 200); //upper line to the messege
    line(100,240, 520, 240); //line below the messege
    delay(1000);
    setcolor(BROWN);
    settextstyle(0, 0, 1);
    n=100;
    while(n>0)  //loop for change in color of the below "press any key to start"
    {
		for(i=0;i<1;i++)
		{
			colo=rand()%10;
			setcolor(colo);
			outtextxy(200, 280, " ' press any key to start ' ");
			delay(500);
		}
		if(kbhit())
		{
			break;
		}
		n--;
    }
    getch();
	cleardevice();
}
void questions()
{
	char question[200];
	char ans1[150];
	char ans2[150];
	char ans3[150];
	char ans4[150];
    int temp=0;
	char ch,ch1;
	int num=0,ct=0,i=0,t=0;
	int randnum[15];
	char str[4],co[4],numc[2];
    int fc;
	char quit;
    randomize();
	fin=fopen("KBC.txt","r");
	while(!feof(fin))
	{
		ch=fgetc(fin);
		if(ch=='\n')
		t++;
	}
	fclose(fin);
	t=t/6;

    fin=fopen("KBC.txt","r");
	settextstyle(COMPLEX_FONT,0,3);
    while(ct<3) //no of questions
	{
		count=0;
		num=random(t);
		for(i=0;i<temp;i++)
		{
			if(randnum[i]==num)
			{
				num=random(t);
			i=0;
			}
		}
		randnum[temp]=num;

		temp++;
		fseek(fin, 0, SEEK_SET);
		//fin.seekg(0,ios::beg);
		while(!feof(fin))
		{
			ch=fgetc(fin);
			if(ch=='\n')
			count++;
		if(count==(6*num))
		{
			break;
		}
		}
		if(ct>0)
		{
			setcolor(RED);
			outtextxy(190,300,"NEXT question!!!!");
			sleep(3);
			setcolor(BLACK);
			outtextxy(190,300,"NEXT question!!!!");
		}
	fgets(question,sizeof(question),fin);
		fgets(ans1,sizeof(ans1),fin);
		fgets(ans2,sizeof(ans2),fin);
		fgets(ans3,sizeof(ans3),fin);
		fgets(ans4,sizeof(ans4),fin);
		fgets(correctans,sizeof(correctans),fin);
		if(strlen(question)>=40||strlen(ans1)>=25||strlen(ans2)>=25||strlen(ans3)>=25||strlen(ans4)>=25)
		settextstyle(COMPLEX_FONT,0,1);
		else
		settextstyle(COMPLEX_FONT,0,2);

		setfillstyle(SOLID_FILL,LIGHTGRAY);// the shadow parts of main bars
		bar(33, 100, 303,140);  //first left bar
		bar(323, 100, 593,140); // first right bar
		bar(323, 150, 593, 190);  //second right bar
		bar(33, 150, 303, 190); //second left bar
		bar(33, 40, 593, 80); // top most bar in center
		setfillstyle(SOLID_FILL,BLUE); //the main bars
		bar(30, 97, 300, 137);//first left bar
		bar(320, 97, 590, 137); //first right bar
		bar(30, 147, 300, 187); //second left bar
		bar(320, 147, 590, 187); //second right bar
		bar(30, 37, 590, 77); //top most bar in the center
		setfillstyle(LINE_FILL,CYAN);
		bar(1, 350, 675, 479);
		bar(1, 1, 29, 349);
		bar(591, 1, 640, 349);
		bar(30, 1, 590, 36);
		setfillstyle(XHATCH_FILL, GREEN);
		rectangle(600, 300, 620, 400);
		rectangle(250, 430, 400, 490);
		rectangle(500, 350, 660, 420);
		rectangle(90, 400, 380, 450);
		rectangle(350, 410, 500, 430);
		rectangle(50, 420, 200, 440);
		rectangle(300, 420, 620, 460);
		rectangle(4, 400, 340, 450);
		setcolor(RED);
		setcolor(15);
		outtextxy(33,37,question);
		outtextxy(35,97,ans1);
		outtextxy(326,97,ans2);
		outtextxy(35,147,ans3);
		outtextxy(326,147,ans4);
		showmouseptr();
		if(correctans[0]=='a')
		{
			incorrect1();
		}
		else if(correctans[0]=='b')
		{
			incorrect2();
		}
		else if(correctans[0]=='c')
		{
			incorrect3();
		}
		else if(correctans[0]=='d')
		{
			incorrect4();
		}
		ct++;
		cleardevice();
		setcolor(LIGHTGRAY);
		outtextxy(80,250,"Press any key to exit the quiz");
		outtextxy(180,300,"Otherwise Wait");
		delay(2000);
		i=0;
		do
		{
		delay(1000);
		i++;
		if(kbhit())
		{
			cleardevice();
			gotoxy(30,12);
			printf("Your score is: %d",scr);
			gotoxy(30,14);
			scr=0;
			delay(2000);
			menu();
		}
		}while(i<2);
		setcolor(BLACK);
		outtextxy(80,250,"Press any key to exit the quiz");
		outtextxy(180,300,"Otherwise Wait");
	}
	fclose(fin);
	score();
	clearviewport();
}
void incorrect1()
{
	count++;
	showmouseptr();
	flag=0;
	select();
	while(flag==0)
	{
		getmousepos(&button,&x1,&y1);
		if((button & 1)==1)
		{
			if((x1>=30&&x1<=300&&y1>=97&&y1<=137))
				correct();
			else if((x1>=320&&x1<=590&&y1>=97&&y1<=137)||(x1>=30&&x1<=300&&y1>=147&&y1<=187)||(x1>=320&&x1<=573&&y1>=147&&y1<=187))
				sorry();
		}
	}
}
void incorrect2()
{
	count++;
	showmouseptr();
	flag=0;
	select();
	while(flag==0)
	{
		getmousepos(&button,&x1,&y1);
		if((button & 1)==1)
		{
			if((x1>=320&&x1<=590&&y1>=97&&y1<=137))
			correct();
			else if ((x1>=30&&x1<=300&&y1>=97&&y1<=137)||(x1>=30&&x1<=300&&y1>=147&&y1<=187)||(x1>=320&&x1<=573&&y1>=147&&y1<=187))
			sorry();
		}
	}
}
void incorrect3()
{
	count++;
	showmouseptr();
    flag=0;
    select();
	while(flag==0)
	{
		getmousepos(&button,&x1,&y1);
		if((button & 1)==1)
		{
			if((x1>=30&&x1<=300&&y1>=147&&y1<=187))
				correct();
			else  if((x1>=30&&x1<=300&&y1>=97&&y1<=137)||(x1>=320&&x1<=590&&y1>=97&&y1<=137)||(x1>=320&&x1<=573&&y1>=147&&y1<=187))
				sorry();
		}
	}
}
void incorrect4()
{
	count++;
	showmouseptr();
	flag=0;
	select();
	while(flag==0)
	{
		getmousepos(&button,&x1,&y1);
		if((button & 1)==1)
		{
			if((x1>=320&&x1<=573&&y1>=147&&y1<=187))
				correct();
			else if((x1>=30&&x1<=300&&y1>=97&&y1<=137)||(x1>=320&&x1<=590&&y1>=97&&y1<=137)||(x1>=30&&x1<=300&&y1>=147&&y1<=187))
				sorry();
		}
	}
}
void correct()
{
	int polygon1[]={30,97,300,97,300,137,30,137,30,97};
	int polygon2[]={320,97,590,97,590,137,320,137,320,97};
	int polygon3[]={30,147,300,147,300,187,30,187,30,147};
	int polygon4[]={320,147,590,147,590,187,320,187,320,147};
	int polygon5[]={30,37,590,37,590,77,30,77,30,37};
	hidemouseptr();
	flag=1;
	settextstyle(0,0,2);
	rectangle(170,300, 410,340);
    outtextxy(180,310,"Correct answer");
    sleep(1);
    setfillstyle(1,BLUE);
    setcolor(BLACK);
    rectangle(170, 300, 410,340);
    outtextxy(180,310,"Correct answer");
    fillpoly(5,polygon1);
    fillpoly(5,polygon2);
    fillpoly(5,polygon3);
    fillpoly(5,polygon4);
    fillpoly(5,polygon5);
	scr=scr+10;

}
void sorry()
{
	int polygon1[]={30,97,300,97,300,137,30,137,30,97};
	int polygon2[]={320,97,590,97,590,137,320,137,320,97};
	int polygon3[]={30,147,300,147,300,187,30,187,30,147};
	int polygon4[]={320,147,590,147,590,187,320,187,320,147};
	int polygon5[]={30,37,590,37,590,77,30,77,30,37};
	hidemouseptr();
	flag=1;
	sleep(1);
	setcolor(MAGENTA);
	settextstyle(0,0,2);
	outtextxy(180,310,"SORRY ! INCORRECT");
	sleep(1);
	setfillstyle(1,BLUE);
    setcolor(BLACK);
	outtextxy(180,310,"SORRY ! INCORRECT");
	fillpoly(5,polygon1);
    fillpoly(5,polygon2);
    fillpoly(5,polygon3);
    fillpoly(5,polygon4);
    fillpoly(5,polygon5);
}
void pass(int poly[10])
{
setfillstyle(1,LIGHTBLUE);
setcolor(LIGHTBLUE);
drawpoly(5,poly);
setfillstyle(1,YELLOW);
setcolor(YELLOW);
}
void select()
{
	int polygon1[]={30,97,300,97,300,137,30,137,30,97};
	int polygon2[]={320,97,590,97,590,137,320,137,320,97};
	int polygon3[]={30,147,300,147,300,187,30,187,30,147};
	int polygon4[]={320,147,590,147,590,187,320,187,320,147};
setcolor(RED);
setfillstyle(1,RED);
setlinestyle(1,0,15);
do
{
settextstyle(3,0,2);
x:
getmousepos(&button,&x1,&y1);

if(x1>=30&&x1<=300&&y1>=97&&y1<=137)
{

pass(polygon2);
pass(polygon3);
pass(polygon4);
drawpoly(5,polygon1);
}

else if(x1>=320&&x1<=590&&y1>=97&&y1<=137)
{
pass(polygon1);
pass(polygon3);
pass(polygon4);
drawpoly(5,polygon2);
}

else if(x1>=30&&x1<=300&&y1>=147&&y1<=187)
{
pass(polygon1);
pass(polygon2);
pass(polygon4);
drawpoly(5,polygon3);
}
else if(x1>=320&&x1<=573&&y1>=147&&y1<=187)
{
pass(polygon1);
pass(polygon2);
pass(polygon3);
drawpoly(5,polygon4);}

}while((button & 1)!=1);

}
void score()
{
	cleardevice();
	fin = fopen("score.txt", "a");
    if (fin == NULL) {
	printf("Error opening file!\n");
    }

    // Append the integer to the file
    fprintf(fin, "%d\n", scr);

    // Close the file
    fclose(fin);
	gotoxy(30,12);
	printf("Your score is: %d",scr);
	gotoxy(30,14);
	printf("Press any key to go back to main menu");
	getch();
	getch();
	scr=0;
	cleardevice();
	menu();
}
void prevscore()
{
    int number;
	setcolor(YELLOW);
    setlinestyle(0,3,3);
    rectangle(325, 400, 585, 420);
    delay(1000);
    cleardevice();
    // Open the file
    fin = fopen("score.txt", "r");
	setbkcolor(CYAN);
	gotoxy(2,2);
    if (fin == NULL)
	 {
		printf("Error opening file!\n");
     }
     // Read integers from the file until the end of the file
     while (fscanf(fin, "%d", &number) == 1)
	 {
			printf("%d\n", number);
     }
    // Close the file
    fclose(fin);
    gotoxy(1,30);
    printf("Press any key to go back to main menu");
    getch();
    cleardevice();
    menu();
}
void exit1()
{
	setcolor(YELLOW);
	setlinestyle(0,3,3);
	rectangle(325, 435, 585, 455);
	delay(1000);
	exit(0);
}