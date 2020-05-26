#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
using namespace std;
class BUS
{
    public:
	int i,bno,cost,a;
	char bname[20],from[20],to[20],atime[20],dtime[20];
    void input()
	    {
	    	cout<<"bus number :";
	    	cin>>bno;
	    	cout<<"FROM:";
			cin>>from;
			cout<<"TO:";
			cin>>to;
			cout<<"Arrival-time:";
			cin>>atime;
			cout<<"Depart-time:";
			cin>>dtime;
			cout<<"COST:";
			cin>>cost;
		}
	void output()
		{
		
			cout<<endl<<bno<<ends<<ends<<ends<<ends<<ends<<from<<ends<<ends<<ends<<ends<<ends<<ends<<to<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<atime<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<dtime<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<ends<<cost<<endl;
			
		}
}b;
int admin();
void user();
void install();
void show();
void reservation();
main()
{
    int c;
	cout<<"\n\t\t\t1.admin \n\t\t\t2.user \n\t\t\t3.exit\n enter your choice :";
	cin>>c;
    switch(c)
	    {
		    case 1:
			       admin();
			       break;
			case 2:
				   user();
				   break;
			case 3:
			       exit(0);
			       break;
			default:
				   cout<<"error";
				   break;
        }
}

admin()
{
	int c,k=0,busnumber;
	char i;
	do
   {
		cout<<"\n\t\t\t1.install \n\t\t\t2.show \n\t\t\t3.MAIN\n\t\t\t4.EXIT";
		cout<<"\nEnter your choice :";
		cin>>c;
	    switch(c)
	   {
	     case 1:
			install();
			break;
		 case 2:
		     show();
		     break;
	     case 3:
		    main();
			break;
		 case 4:
		     exit(0);
		     break;		 
  	     default:
		  cout<<"error";
		  break;	
		}
	 cout<<"\n\ndo you want menu once (Y/N):";
	 cin>>i;
	 if(i=='N'||i=='n')
	    {
	    	k=1;
		}
	
    }while(!k);
}


void user()
	{  
	    int c,k=0;
		char i,from[20],to[20];
		do
		{
			cout<<"\n\t\t\t1.show all available buses \n\t\t\t2.reservation  \n\t\t\t3.MAIN \n\t\t\t4.EXIT\n";
			cout<<"Enter your choice :";
			cin>>c;
		    switch(c)
		   {
			 case 1:
				show();
				break;
			 case 2:
				
			    reservation();
			     break;
			 case 3:
		         main();
		         break;
		        
				case 4:
			    exit(0);    
	  	     default:
			  cout<<"error";
			  break;	
			}
	      cout<<"\n\ndo you want menu once (Y/N):";
	      cin>>i;
	      if(i=='N'||i=='n')
	       {
	    	  k=1;
		   }
	
	    }while(!k);
   }


void install()
    {
     ofstream outfile;
	 cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&& INSTALL BUSES &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
	 cout<<endl<<"Enter following bus details:";
	 outfile.open("p20.txt",ios :: in |ios :: app);
     b.input();
	 outfile.write((char *)&b,sizeof(b));
	 outfile.close();
     } 
 
 
void show()
   {
	 ifstream infile;
	 infile.open("p20.txt",ios :: out | ios :: app);
	 cout<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& BUSES INFO &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
	 cout<<"\nBUS.NO    FROM     TO     Arrival-time   Depart-time    COST   ";
	 while(infile.read((char *)&b,sizeof(b)))
	   {  
	 	  b.output();
	    }
	 infile.close();
    }
 
 

void reservation()
   { 
		int n,busno;
		char seat[20][20];
	   cout<<"\nENTER BUS NUMBER:";
	   cin>>busno;
		int r,z=0;
		ifstream infile;
		infile.open("p20.txt",ios :: out);
		while(infile.read((char *)&b,sizeof(b)))
		{
	    	if(busno==b.bno)
			{
				cout<<"\nnumber of seats you want to book:";
				cin>>n;
				for(int i=1;i<=n;i++)
				{
					cout<<"\nENTER NAME OF SEAT NO -"<<i<<" :";
					fflush(stdin);
					cin>>seat[i];
				}
				
			
			    cout<<"\n===============TICKET================\n";
			    for(int i=1;i<=n;i++)
			    {
			    	cout<<seat[i]<<"==================seat no."<<i<<"=========cost:"<<b.cost<<endl;
				}
					cout<<"\n================================================================\n";
					cout<<"\n total amount is============ << "<<n*b.cost<<"  >>";
            }
	    }
	    infile.close();
   }
