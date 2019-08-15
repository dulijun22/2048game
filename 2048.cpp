#include<stdio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>

#define ROW 4                                              
#define COL ROW

int get_emtpy(int(*a)[COL]);      //获取数组空值个数
void random(int (*a)[COL]);       //产生随机数的函数
void draw(int(*a)[COL]);         //绘图
void play(int(*a)[COL]);         //获得键值函数
void _up(int(*a)[COL]);          //向上移动
void _down(int(*a)[COL]);        //向下移动
void _left(int(*a)[COL]);        //像左移动
void _right(int(*a)[COL]);       //向右移动
void add_number(int(*a)[COL]);   //增加一个数字

int get_emtpy(int(*a)[COL])      //获取空位置的数量
{
	int emtpy=0;
	for(int i=0;i<ROW;i++)
	{
		 for(int j= 0;j<COL;j++)
		 {
			 if (a[i][j]==0) 
			 emtpy++;      //数组不为空 emtpy+1
		 }
	 }
	return emtpy;
}

void draw(int(*a)[COL])           //页面绘制
{
	int _back[4][4]={0};
    int i,j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            _back[i][j] =a[i][j];

            PIMAGE img; //开始画图
            img = newimage();
            switch(a[i][j])
            {
			case 0:
            {
                getimage(img,"..\\2048\\0.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 2:
            {
                getimage(img, "..\\2048\\2.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 4:
            {
                getimage(img, "..\\2048\\4.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 8:
            {
                getimage(img, "..\\2048\\8.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 16:
            {
                getimage(img, "..\\2048\\16.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 32:
            {
                getimage(img, "..\\2048\\32.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 64:
            {
                getimage(img, "..\\2048\\64.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 128:
            {
                getimage(img, "..\\2048\\128.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 256:
            {
                getimage(img, "..\\2048\\256.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 512:
            {
                getimage(img, "..\\2048\\512.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 1024:
            {
                getimage(img, "..\\2048\\1024.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            case 2048:
            {
                getimage(img, "..\\2048\\2048.png");
                putimage(j * 180, i * 180, img);
                break;
            }
            
			}
        }
    }
}


void random(int(*a)[COL])    //在空白的地方随机产生2或者4；
{
	int i,k,p,q;
	i=rand()%10+1;
	if(i<=7)
	{
		k=2;
	}
	else k=4;
	for(q=rand()%4+0,p=rand()%4+0;a[q][p]!=0;)
	{
		q=rand()%4+0;
		p=rand()%4+0;
	}
	a[q][p]=k;
}


void _up(int(*a)[COL])
{
    int x,y,i;
	for (y=0;y<4;++y)    // 从上向下合并相同的方块 
	{     
        for(x=0;x<4;++x)
		{
			if (a[x][y] == 0)
				;
            else 
			{
				for (i = x + 1; i < 4; ++i)
				{
					if (a[i][y] == 0)
                        ;
					else if (a[x][y] == a[i][y]) 
					{
                        a[x][y] += a[i][y];
                        a[i][y] = 0;
                        x = i;
                        break;
					}
                    else
					{
						break;
                    }
                }
            }
        }
    }

    for(y=0;y<4;++y)    // 向上移动箱子
	{
		  for(x=0;x<4;++x)
        {
			if(a[x][y] == 0)
                ;
            else 
			{
                for(i=x;(i>0)&&(a[i-1][y]==0);--i) 
				{
                    a[i-1][y]=a[i][y];
                    a[i][y]=0;
                }
            }
        }
	}
}

void _down(int(*a)[COL])
{
    int x,y,i;
	for(y=0;y<4;++y)  // 向下合并相同的方格 
	{
		 for(x=3;x>=0;--x) 
		 {
            if(a[x][y]==0)
                ;
            else{
                for(i=x-1;i>=0;--i) 
				{
                    if(a[i][y]==0)
                        ;
                    else if(a[x][y]==a[i][y]) 
					{
                        a[x][y]+=a[i][y];
                        a[i][y]=0;
                        x = i;
                        break;
                    }
                    else
                        break;
                }
            }
        }
	}

	for(y=0;y<4;++y)  // 向下移动方格 
	{
		for(x=3;x>=0;--x) 
		{
            if(a[x][y]==0)
                ;
            else{
                for(i=x;(i<3)&&(a[i+1][y]==0);++i)
				{
                    a[i+1][y]=a[i][y];
                    a[i][y]=0;
                }
            }
        }
	}
}

void _left(int(*a)[COL])
{
    int x, y, i;
	for(x=0;x<4;++x)   // 向左合并相同的方格 
	{
		for(y=0;y<4;++y) 
		{
            if(a[x][y]==0)
                ;
            else {
                for(i=y+1;i<4;++i) 
				{
                    if(a[x][i]==0)
                        ;
                    else if(a[x][y]==a[x][i]) 
					{
                        a[x][y] += a[x][i];
                        a[x][i] = 0;
                        y = i;
                        break;
                    }
                    else
                        break;
                }
            }
        }

	}
        
    for(x=0;x<4;++x)  // 向左移动方格 
	{
		for(y=0;y<4;++y) 
		{
            if(a[x][y]==0)
                ;
            else{
                for(i=y;(i>0)&&(a[x][i-1]==0);--i) 
				{
                    a[x][i-1]=a[x][i];
                    a[x][i]=0;
                }
            }
        }
	}
}

void _right(int(*a)[COL]) 
{
    int x,y,i;
	for(x=0;x<4;++x)  // 向右合并相同的方格 
	{
		for(y=3;y>=0;--y) 
		{
            if(a[x][y]==0)
                ;
            else{
                for(i=y-1;i>=0;--i) 
				{
                    if(a[x][i]==0)
                        ;
                    else if(a[x][y]==a[x][i])
					{
                        a[x][y]+=a[x][i];
                        a[x][i]=0;
                        y=i;
                        break;
                    }
                    else
                        break;
                }
            }
        }
	}
        for(y=3;y>=0;--y)
		{
            if(a[x][y]==0)
                ;
            else {
                for(i=y-1;i>=0;--i) 
				{
                    if(a[x][i]==0)
                        ;
                    else if(a[x][y]==a[x][i])
					{
                        a[x][y]+=a[x][i];
                        a[x][i]=0;
                        y=i;
                        break;
                    }
                    else
                        break;
                }
            }
        }

    for(x=0;x<4;++x)   // 向右移动方格 
	{
		for(y=3;y>=0;--y) 
		{
            if(a[x][y]==0)
                ;
            else 
			{
                for(i=y;(i<3)&&(a[x][i+1]==0);++i) 
				{
                    a[x][i+1]=a[x][i];
                    a[x][i]=0;
                }
            }
        }
	}
        
}

void add_number(int(*a)[COL])
{
	int _back[4][4] = {};
    srand(time(0));
    if(get_emtpy(a)>0)
    {
        int x,y,temp;
        do
        {   x = rand() % 4;
            y = rand() % 4;
        } while (a[x][y] != 0);     //有空格并且不等于0，产生两个随机数。

        temp = rand();
        int i=temp % 2;
        if (i == 1)
        {
            a[x][y] = 2;
		}
        else
        {
            a[x][y] = 4;
        }
        }
	}

void play(int(*a)[COL])
{
	int _back[4][4] = {};
    char c = getch();
    switch (c)
    {
    case 'w':
		{
        _up(a);
        add_number(a);
        draw(a);
		break;
		}
    case 's':
		{
        _down(a);
        add_number(a);
        draw(a);
        break;
		}
    case 'a':
		{
        _left(a);
        add_number(a);
        draw(a);
        break;
		}
	case 'd':
		{
        _right(a);
        add_number(a);
        draw(a);
        break;
		}
    case 'q':
		{
        for (int i = 0; i < 4; i++)
		{
            for (int j = 0; j < 4; j++)
            {
                a[i][j] = _back[i][j];
                draw(a);
            }
        }
		}
    }
}

int  main()
{
	int a[ROW][COL] ={0};
	int _back[4][4] ={0};

	random(a);
	random(a);

    initgraph(724, 724);//初始化
    PIMAGE img;
    img = newimage();
    getimage(img,"..\\2048\\背景.jpg");
    putimage(0, 0, img);
    draw(a);
    for (; is_run(); delay_fps(30))
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                _back[i][j] = a[i][j];
            }
        }
        play(a);
    }

	return 0;
}
	