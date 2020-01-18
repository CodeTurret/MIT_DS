#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;
//#define size 100

int i, j,k,  last=0,num=0,sum=0, flag=0;

int front=-1;

int s;



int *a = (int*)malloc(s*2* sizeof(int));

// a[size][2];
// a[s][2],



void read();
void compare();
void compare2();
void menu();
void display();
void del();

void read ()
{
    front=0;
    int n=0;
    cout<<"How many you want to insert: ";
    cin>> n;
   // cout<<"num: "<<num<<endl;
    sum=num+n;
    //cout<<"sum: "<<sum<<endl;
    for (i=last; i<sum; i++)
    {
        cout<<i+1<<"  Enter time with money: ";
        for(j=0; j<2; j++)
        {
            //*(arr + i*c + j) = ++count;
            //cin>>(a[i][j]);
            cin>>*(a+i+j);
        }
    }

    last=i;
  //  cout<<"Last: "<<last<<endl;
    num=sum;
   // cout<<"num: "<<num<<endl;
    flag++;
    //cout<<"flag: "<<flag<<endl;
 //compare();

    if(flag==1)
      compare();
    else
    {
       // cout<<"compare2"<<endl;
        compare2();

    }


}


void del()
{
    if(front==-1)
        cout<<"No element to delete"<<endl;
    else
    {
        //a[front][front]=NULL;
        for(i=0; i<sum-1; i++)
        {
            for(j=0;j<2;j++)
            {
                //cin>>*(a+i+j);
                //a[i][j]=a[i+1][j];
                *(a+i+j)=*(a+(i+1)+j);
            }
        }
        sum=sum-1;
        last--;
        num--;
    }

}



int main ()
{

//    read();
 //  compare();

    int ch;

    for(;;)
    {
        menu();
         cin>>ch;

        if(ch == 1)
            read();
        else if(ch==2)
            del();
        else if(ch==3)
            display();
        else if(ch==4)
            break;
        else
            cout<<"Invalid"<<endl;
    }

    return 0;
}


void compare()
{
    int temp, temp2;


   for(i=0;i<sum-1; i++)
    {
        for (k = 0; k <sum-i-1; k++)
        {
            //*(a+i+j)

           //if(a[k][0]>a[k+1][0])
            if(*(a+k+0)>*(a+(k+1)+0))
            {
                //cout<<"true";
                for(j=0; j<2; j++)
                {
                    //cout<<"compare ";
                    temp= *(a+k+j);
                    *(a+k+j)= *(a+(k+1)+j);
                    *(a+(k+1)+j)=temp;
                }

            }

            if( *(a+k+0) == *(a+(k+1)+0) && *(a+k+1)<*(a+(k+1)+1))
            {
                temp2= *(a+k+1);
                *(a+k+1)=*(a+(k+1)+1);
                //a[k][1]=a[k+1][1];
                *(a+(k+1)+1)=temp2;
                //a[k+1][1]=temp2;


            }

        }
    }


}




void compare2()
{
    int temp, temp2;


   for(i = 1;i<sum; i++)
    {
        for (k = 1; k <sum-i; k++)
        {
           if(*(a+k+0)>*(a+(k+1)+0))
            {
                //cout<<"true";
                for(j=0; j<2; j++)
                {
                    //cout<<"compare ";
                    temp= *(a+k+j);
                    *(a+k+j)= *(a+(k+1)+j);
                    *(a+(k+1)+j)=temp;
                }

            }

            //if(a[k][0] == a[k+1][0] && a[k][1]<a[k+1][1])
            if(*(a+k+0) == *(a+(k+1)+0) && *(a+k+1)<*(a+(k+1)+1))
            {
                temp2= *(a+k+1);
                *(a+k+1)=*(a+(k+1)+1);
                *(a+(k+1)+1)=temp2;


            }

        }
    }


}

void menu()
{
        cout<<endl<<"\t  MENU"<<endl;
        cout<<"Press 1 to enqueue"<<endl;
        cout<<"Press 2 to delete"<<endl;
        cout<<"Press 3 to display"<<endl;
        cout<<"Press 4 to Exit!!!"<<endl<<endl;
        cout<<"Enter choice: "<<endl;
}


void display()
{

    for (i=0; i<sum; i++)
    {

        for(j=0; j<2; j++)
        {
          //  cout<<"i:  "<<i<<" j:  "<<j<<endl;
            cout<<*(a+i+j)<<" ";
        }
        cout<<endl;
    }

}



