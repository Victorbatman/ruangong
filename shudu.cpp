//shudu.cpp ������Ϸ
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
usingnamespace std;

//�������ݽṹ
int shudu[9][9]={0};

//��ʼ������
void init()
{
    int i=0,j=0;
    ifstream fin("input.txt");//���ļ�
//��������
    for(i=0;i<9;i++)
    for(j=0;j<9;j++) 
            fin>>shudu[i][j];
    fin.close();
//����ոն��������
    cout<<"The init structure is:"<<endl;
    for(i=0;i<9;i++,cout<<endl)
    for(j=0;j<9;j++) 
    cout<<shudu[i][j]<<'';
}

//�����(x,y)λ�ô�����iֵ�Ƿ��������л�����ͬ������
bool checkAssign1(int x,int y,int i)
{
    for(int c=0;c<9;c++) //c��ָ��
    if(c!=y && shudu[x][c]==i)
    return false;    
    for(int r=0;r<9;r++)// r��ָ��
    if(r!=x && shudu[r][y]==i)
    return false;
    return true;
}

//���(x,y)λ�ô��Ƿ����������ڴ󷽸��и���������ͬ������
bool checkAssign2(int x,int y,int i)
{
    for(int r=(x/3)*3;r<(x/3)*3+3;r++)  // (x/3,y/3)��(x,y)���ڵĴ󷽸��λ��
    for(int c=(y/3)*3;c<(y/3*3)+3;c++) // x/3*3��y/3*3�ֱ���(x,y)���ڴ󷽸�
//λ�õ���ʼλ��
    {                      
      if(shudu[r][c]==i)
      if(r==x && c==y)
      continue;
      else
      return false;
        }
    return  true;
}

//81�����зֱ��ÿһ�����������н�
bool search(int depth)
{
     if(depth>=81)
    {
       return true;
    }
    int x,y;//��鵱ǰλ��(x,y)��û����ֵ��û�����Ը�ֵ
//����Ƿ�Υ��Լ������
    x=depth/9;y=depth%9;
    if(shudu[x][y]!=0)//(x,y)�Ѹ�ֵ
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
    system("pause"); //�û���ͣ��������һ������
return 0;
}
