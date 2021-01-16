#include<bits/stdc++.h>
using namespace std;
int main()
{	
	double consumption0=0,consumption1=0;
	
	const int length=20202;
	int test[length];
    
	for(int t=0;t<20;t++)
    {
    	
	for (int j=0;j<length;j++)
        {
        	//用随机数填充数组
		 	test[j]=rand()%256;
        }

		//记录第一次开始时间
        clock_t start=clock();
        long long sum=0;
    
	for(int i=0;i<10000;i++)
        {
            for(int j=0;j<length;j++)
            {
            	//分支跳转的条件test[j]>128
                if (test[j]>=128)
                sum+=test[j];
            }
        }
    
    //计算未排序前进行10000次loop消耗的时间
	consumption0+=(double)(clock()-start)/CLOCKS_PER_SEC;
	sum=0;
	clock_t start1=clock(); 
	sort(test,test+length);
	for(int i=0;i<10000;i++)
        {
            for(int j=0;j<length;j++)
            {
            	//分支跳转的条件test[j]>128
	            if (test[j]>=128)
                sum+=test[j];
                //cout<<sum; 
            }
        }
	
	//计算排序后进行10000次loop消耗的时间
	consumption1+=(double)(clock()-start1)/CLOCKS_PER_SEC;
	
    }
	
	//输出两次运算时间并计算提升效率 
    cout << "排序前: "<<consumption0 << endl;
    cout << "排序后: "<<consumption1 << endl;
    cout<<"效率提升"<<100*(consumption0-consumption1)/consumption0<<"%\n";
	system("pause");
	return 0;
}
