#include <iostream>
#include <ctime>
#include <windows.h>
#include<iomanip>
#include"colour.h"
using namespace std;
int main()
{  
/* TODO (#1#): 初始化 */
   int a[4][4]={0};
   int score(0);
   int b[4][4];
   int g[16];
   char name;
   int uu=0,i1=0,j1=0,uu1=0;
   srand((unsigned)time(0));
   int t1,t2,t3;
   int victory=0;
   bool w(0),z(0),s(0),d(0),ws(0),ad(0),boola(0);
   t1 = rand()%16;
   t2=t1/4;
   t3=t1%4;
   a[t2][t3]=2;
/* TODO (#1#): 显示 */
  begin:
   system("cls");
   for(int i=0;i<=3;++i){
   	for(int j=0;j<=3;++j)
   	{
	if(a[i][j]==2)
	red;
	if(a[i][j]==4)
	green;
	if(a[i][j]==8)
	yellow;
	if(a[i][j]==16)
	purple;
	if(a[i][j]==32)
	blue;
	if(a[i][j]==64)
	pink;
	if(a[i][j]==128)
	brown;
	if(a[i][j]>128)
	red;
   	cout<<std::left<<setw(6)<<a[i][j];
   	white;
   }
   	cout<<endl;
   }
   cout<<"your score is "<<score<<endl; 
/* TODO (#1#): 接收程序 */
w=0;
z=0;
s=0;
d=0;
ws=0;
ad=0;
name=0;
cin>>name;
if(name=='w')
{w=1;ws=1;}
else if(name=='a')
{z=1;ad=1;}
else if(name=='s')
{s=1;ws=1;}
else if(name=='d')
{d=1;ad=1;}

else if(name='v')
{
	cout<<"V我50，让你过关,请输入通关码"<<endl;
	int phone;
	cin>>phone;
	if(phone==123123) {
		score=999999;
		for(int i=0;i<=3;++i){
   	for(int j=0;j<=3;++j)
   	{a[i][j]=2048;
   	
	}}
}goto begin;}
++score;
/* TODO (#2#): 上下收缩 */
if(w){
	for(int p=1;p<=3;++p)
	{
		for(int i=0;i<=3;++i)//line
		{
			for(int j=0;j<=2;++j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j+1][i];
					a[j+1][i]=0;
				}
				
			}
		}
	}
}
if(s){
	for(int p=1;p<=3;++p)
	{
		for(int i=0;i<=3;++i)//line
		{
			for(int j=3;j>=1;--j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j-1][i];
					a[j-1][i]=0;
				}
				
			}
		}
	}
}
/* TODO (#3#): 左右收缩 */
if(z){
	for(int p=1;p<=3;++p)
	{
		for(int i=0;i<=3;++i)//line
		{
			for(int j=0;j<=2;++j)//lie
			{
				if(a[i][j]==0)
				{
					a[i][j]=a[i][j+1];
					a[i][j+1]=0;
				}
				
			}
		}
	}
}
if(d){
	for(int p=1;p<=3;++p)
	{
		for(int i=0;i<=3;++i)//line
		{
			for(int j=3;j>=1;--j)//lie
			{
				if(a[i][j]==0)
				{
					a[i][j]=a[i][j-1];
					a[i][j-1]=0;
				}
				
			}
		}
	}
}

/* TODO (#4#): 上下合并 */
if(ws)
{   
    int num[4]={0};
	for(int i=0;i<=3;++i)
	{   
		for(int j=0;j<=3;++j)
		{
			if(a[j][i]==0){
				++num[i];
			}
		}
		if(num[i]==3)
		continue;
		if(num[i]==2)
		{
			if(w&&(a[0][i]==a[1][i]))
			{
				a[0][i]*=2;
				a[1][i]=0;
			}
			else if(s&&(a[2][i]==a[3][i]))
			{
				a[3][i]*=2;
				a[2][i]=0;
			}
			else
			continue;
			}
		if(num[i]==0||num[i]==1)
		{
			if(w){
			if(w&&(a[0][i]==a[1][i]))
			{
				a[0][i]*=2;
				a[1][i]=0;
				if(a[2][i]==a[3][i])
				{
				a[2][i]*=2;
				a[3][i]=0;
			    }
			}
			if(w&&(a[0][i]!=a[1][i]))
			{
				if(a[1][i]==a[2][i])
				{
				a[1][i]*=2;
				a[2][i]=0;
			    }
			    else if(a[2][i]==a[3][i])
				{
				a[2][i]*=2;
				a[3][i]=0;
			    }
			    else
			    continue;
			}
			
			
		}//w end
		if(s){
			if(s&&(a[2][i]==a[3][i]))
			{
				a[3][i]*=2;
				a[2][i]=0;
				if(a[0][i]==a[1][i])
				{
				a[1][i]*=2;
				a[0][i]=0;
			    }
			}
			if(s&&(a[2][i]!=a[3][i]))
			{
				if(a[2][i]==a[1][i])
				{
				a[2][i]*=2;
				a[1][i]=0;
			    }
			    else if(a[0][i]==a[1][i])
				{
				a[1][i]*=2;
				a[0][i]=0;
			    }
			    else
			    continue;
			}
			
			
		}//s end	
		}
	}
	if(w){
		for(int i=0;i<=3;++i)//line
		{
			for(int j=0;j<=2;++j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j+1][i];
					a[j+1][i]=0;
					++score;
				}
				
			}
		}
	}
	if(s)
	{
		for(int i=0;i<=3;++i)//line
		{
			for(int j=3;j>=1;--j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j-1][i];
					a[j-1][i]=0;
				}
				
			}
		}
	}
}//ws over
/* TODO (#5#): 左右合并 */
if(ad)
{   //转置 
    for(int i = 0;i<=3;++i)//输入扫描行  
	{
		for (int i2 = 0 ;i2<=3;++i2)//输入扫描列 
		{
			b[i2][i]=a[i][i2];
		}
	}
	for(int i = 0;i<=3;++i)//输入扫描行  
	{
		for (int i2 = 0 ;i2<=3;++i2)//输入扫描列 
		{
			a[i][i2]=b[i][i2];
		}
	}
	//转置完成 
	int num[4]={0};
	for(int i=0;i<=3;++i)
	{    
		for(int j=0;j<=3;++j)
		{
			if(a[j][i]==0){
				++num[i];
			}
		}
		if(num[i]==3)
		continue;
		if(num[i]==2)
		{
			if(z&&(a[0][i]==a[1][i]))
			{
				a[0][i]*=2;
				a[1][i]=0;
			}
			else if(d&&(a[2][i]==a[3][i]))
			{
				a[3][i]*=2;
				a[2][i]=0;
			}
			else
			continue;
			}
		if(num[i]==0||num[i]==1)
		{
			if(z){
			if(z&&(a[0][i]==a[1][i]))
			{
				a[0][i]*=2;
				a[1][i]=0;
				if(a[2][i]==a[3][i])
				{
				a[2][i]*=2;
				a[3][i]=0;
			    }
			}
			if(z&&(a[0][i]!=a[1][i]))
			{
				if(a[1][i]==a[2][i])
				{
				a[1][i]*=2;
				a[2][i]=0;
			    }
			    else if(a[2][i]==a[3][i])
				{
				a[2][i]*=2;
				a[3][i]=0;
			    }
			    else
			    continue;
			}
			
			
		}//w end
		if(d){
			if(d&&(a[2][i]==a[3][i]))
			{
				a[3][i]*=2;
				a[2][i]=0;
				if(a[0][i]==a[1][i])
				{
				a[1][i]*=2;
				a[0][i]=0;
			    }
			}
			if(d&&(a[2][i]!=a[3][i]))
			{
				if(a[2][i]==a[1][i])
				{
				a[2][i]*=2;
				a[1][i]=0;
			    }
			    else if(a[0][i]==a[1][i])
				{
				a[1][i]*=2;
				a[0][i]=0;
			    }
			    else
			    continue;
			}
			
			
		}//s end	
		}
	}
	if(z){
		for(int i=0;i<=3;++i)//line
		{
			for(int j=0;j<=2;++j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j+1][i];
					a[j+1][i]=0;
					++score;
				}
				
			}
		}
	}
	if(d){
		for(int i=0;i<=3;++i)//line
		{
			for(int j=3;j>=1;--j)//lie
			{
				if(a[j][i]==0)
				{
					a[j][i]=a[j-1][i];
					a[j-1][i]=0;
				}
				
			}
		}
	}
	
	
	
	//转置 
    for(int i = 0;i<=3;++i)//输入扫描行  
	{
		for (int i2 = 0 ;i2<=3;++i2)//输入扫描列 
		{
			b[i2][i]=a[i][i2];
		}
	}
	for(int i = 0;i<=3;++i)//输入扫描行  
	{
		for (int i2 = 0 ;i2<=3;++i2)//输入扫描列 
		{
			a[i][i2]=b[i][i2];
		}
	}
	//转置完成 
}//ad over


/* TODO (#8#): 增加一项 */
uu=-1;
g[16]={0};
for(int i=0;i<=3;++i){
   	for(int j=0;j<=3;++j)
   	{
   	  if(a[i][j]==0){
   	  	++uu;
   	  	g[uu]=10*i+j;
		 }
   		
	   }
   }
   victory = 0;
   for(int i=0;i<=2;++i){
   	for(int j=0;j<=3;++j)
   	{  if(a[i][j]==a[i+1][j])
               ++victory;   	   
	   }}
	      for(int i=0;i<=3;++i){
   	for(int j=0;j<=2;++j)
   	{  if(a[i][j]==a[i][j+1])
               ++victory;   	   
	   }}
	   if(victory==0){
	   	boola=1;
	   }
	   else
	   boola=0;
	   victory=0;
	    for(int i=0;i<=2;++i){
   	for(int j=0;j<=3;++j)
   	{  if(a[i][j]==a[i+1][j]&&(a[i][j]==0))
               ++victory;   	   
	   }}
	      for(int i=0;i<=3;++i){
   	for(int j=0;j<=2;++j)
   	{  if(a[i][j]==a[i][j+1]&&(a[i][j]==0))
               ++victory;   	   
	   }}
	   score=score-victory/4;
	  
   if(uu==0&&boola){
   	system("cls");
   	cout<<"你失败了"<<"你的得分是"<<score<<endl;
   	system("pause");
   	return 0;
   }
   uu1 = rand()%uu;
   i1=g[uu1]/10;
   j1=g[uu1]%10;
   a[i1][j1]=2;

/* TODO (#9#): 计分板 */
   goto begin;

}
	
