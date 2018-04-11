//shudu.cpp 数独游戏
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
usingnamespace std;

//定义数据结构
int shudu[9][9]={0};

//初始化数据
void init()
{
    int i=0,j=0;
    ifstream fin("input.txt");//打开文件
//读入数字
    for(i=0;i<9;i++)
    for(j=0;j<9;j++) 
            fin>>shudu[i][j];
    fin.close();
//输出刚刚读入的数据
    cout<<"The init structure is:"<<endl;
    for(i=0;i<9;i++,cout<<endl)
    for(j=0;j<9;j++) 
    cout<<shudu[i][j]<<'';
}

//检查在(x,y)位置处赋予i值是否满足行列互不相同的条件
bool checkAssign1(int x,int y,int i)
{
    for(int c=0;c<9;c++) //c是指列
    if(c!=y && shudu[x][c]==i)
    return false;    
    for(int r=0;r<9;r++)// r是指行
    if(r!=x && shudu[r][y]==i)
    return false;
    return true;
}

//检查(x,y)位置处是否满足其所在大方格中各数互不相同的条件
bool checkAssign2(int x,int y,int i)
{
    for(int r=(x/3)*3;r<(x/3)*3+3;r++)  // (x/3,y/3)是(x,y)所在的大方格的位置
    for(int c=(y/3)*3;c<(y/3*3)+3;c++) // x/3*3和y/3*3分别是(x,y)所在大方格
//位置的起始位置
    {                      
      if(shudu[r][c]==i)
      if(r==x && c==y)
      continue;
      else
      return false;
        }
    return  true;
}

//81个点中分别给每一个点搜索可行解
bool search(int depth)
{
     if(depth>=81)
    {
       return true;
    }
    int x,y;//检查当前位置(x,y)有没被赋值，没有则尝试赋值
//检查是否违法约束条件
    x=depth/9;y=depth%9;
    if(shudu[x][y]!=0)//(x,y)已赋值
    return search(depth+1);
    else
    for(int i=1;i<=9;i++)
        {
            shudu[x][y]=i;
            if(checkAssign1(x,y,i) && checkAssign2(x,y,i))
            {
                if(search(depth+1))
                return true;
            }    
            shudu[x][y]=0;
        }
    return false;
}


int main()
{
    
    cout<<"--------------------------"<<endl;
//define the data structure and input the data
    init();
    cout<<"--------------------------"<<endl;
if(search(0))   //search();
    {//output the answer
        cout<<"The answer is:"<<endl;
         for(int i=0;i<9;i++,cout<<endl)
         for(int j=0;j<9;j++)
                cout<<shudu[i][j]<<''; 
    }
else
    {
        cout<<"haven't found a resolution"<<endl;
    }
    system("pause"); //让画面停留，避免一闪而过
return 0;
}
