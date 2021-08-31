#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > grid(3,vector<int>(3,0));
vector<int> isfree(9,1);
string tic(int n)
{
	if(n==0)	return "  ";
	if(n==1)	return " X";
	if(n==2)	return " O";
}
void print()
{
	for(int j=0;j<3;j++)
	{
	
	for(int i=0;i<3;i++)	
	{
		cout<<tic(grid[j][i]);
		if(i!=2) cout<<" |";
	}
	cout<<"\n";
	if(j!=2) for(int i=0;i<3;i++)	
	{
		cout<<"----";
	}
	
	cout<<"\n";
	}
}
void convert(int turn,int &r,int &c)
{
	turn--;
	 r=2-(turn/3),c=(turn%3);
}
void put_random()
{
	
int num=rand()%9;
while(isfree[num]==0)	num=rand()%9;	
isfree[num]=0;
int r=2-(num/3),c=(num%3);
grid[r][c]=1;	
}
int check2(int win,int sign)
{
	int ans,flag=1;
	
	flag=1;
	for(int i=0;i<3;i++)
	{
		flag=1;
		for(int j=0;j<3;j++)
		{
			if(grid[i][j]!=sign)	flag=0;				
		}
		if(flag)	return win;
	}
	
	for(int i=0;i<3;i++)
	{
		flag=1;
		for(int j=0;j<3;j++)
		{
			if(grid[j][i]!=sign)	flag=0;				
		}
		if(flag)	return win;
	}
		flag=1;
		for(int i=0;i<3;i++)
	{
		if(grid[i][i]!=sign)	flag=0;				
	}
		if(flag)	return win;

		flag=1;
	for(int i=0;i<3;i++)
	{
		if(grid[i][2-i]!=sign)	flag=0;				
	}
		if(flag)	return win;
	return 0;
}
int check()
{
int flag;

if(check2(-1,2)==-1)	return -1;
if(check2(1,1)==1)	return 1;
	flag=1;
	for(int i=0;i<9;i++)	
	{
	if(isfree[i])	flag=0;
	}
	if(flag==0) return 2;
	return 0;
	
}
int solve(int p)
{
	int r,c,flag=1,ans;
	int mini=10,maxi=-10;
	for(int i=0;i<9;i++)
	{
		if(isfree[i])
		{
			flag=0;
			if(p==1)
			{
				
			
				convert(i+1,r,c);
				grid[r][c]=1,isfree[i]=0;
				int cur=solve(2);
				maxi=max(maxi,cur);
				grid[r][c]=0,isfree[i]=1;
			}	
			else
			{
				
				convert(i+1,r,c);
				grid[r][c]=2,isfree[i]=0;
				int cur=solve(1);
				mini=min(mini,cur);
				grid[r][c]=0,isfree[i]=1;
			}
		}	
	}
	if(flag) return check();
	if(p==1) return maxi;
	else  return mini;				
}
void bestmove()
{
	int r,c,maxi=-10,ans;
	for(int i=0;i<9;i++)
	{
			if(isfree[i])
			{
				convert(i+1,r,c);
				grid[r][c]=1,isfree[i]=0;
				int temp=solve(2);
				if(maxi<temp)
				{
					maxi=temp;
					ans=i;
				}
			 grid[r][c]=0,isfree[i]=1;
			}
		
	}

	convert(ans+1,r,c);
	grid[r][c]=1,isfree[ans]=0;
	
}
int main()
{
	int flag=1,cnt=0;
	while(1)
	{
		system("CLS");
		int turn;
			
			print();
			int state=check();
			if(state!=2)	
			{
				if(state==0)	cout<<"Draw\n";
				else if(state==-1)	cout<<"Player Wins\n";
				else cout<<"AI wins the match\n";
				break;
			}
			if(!flag)
			{
			cout<<"Enter Your Turn\n";
			cin>>turn;
			turn--;
			if(isfree[turn]==1)
			{
			
			int r=2-(turn/3),c=(turn%3);
			grid[r][c]=2;
			isfree[turn]=0;
			flag=1;
			cnt++;
			}
			}
			else 
			{			
					bestmove();		flag=0;
				
			}
	}
	
}


