#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>



// class with room and guest details
class room
{
   int roomnumber;
   char roomtype[20];
   int roomavail;
   int nodays;
   char name[20];
   long int phone;
   char email[50];
   int roomprice;


 public:


   room()
   {
    roomavail=0; //room availability is 0 when unoccupied 
   }


   int rrn()
   { return roomnumber; }


   int ra()
   { return roomavail; }



   int rnd()
   { return nodays; }


   char* rn()


   { return name; }


   char* rrt()
   { return roomtype;}


   int rrp(){
        return roomprice;

   void fillroom()
   { roomavail=1; } // this occupies the room


   void emptyroom()
   { roomavail=0; } // // this empties the room


   }




   void entera();
   void Display()


   {
        cout<<"room number: "<<roomnumber<<" type: "<<roomtype<<" price:   "<<roomprice<<endl;
        }
        void DisplayU()


   {
        cout<<"Name: "<< Name<<"Roomnumber: "<<Roomnumber <<"No. of days:  "<<nodays<<endl;
        }
   void enteru();


   void exit();


   void changeprice(float);


   void basic();


};


void room::basic()
{
   roomavail=0;
   strcpy(name,'\0');
   strcpy(email,'\0');
   phone=0;
}


void room::entera()
{
         char Type;
         cout<<"Enter the room number"<<endl;
         cin>>roomnumber;
         cout<<"Enter the room type(n/s)"<<endl;
         cin>>Type;
         if(Type=='n')
          strcpy(roomtype,"Normal");
          else
          if(Type=='s')
          strcpy(roomtype,"Suite");
         cout<<"Enter the room price"<<endl;
         cin>>roomprice;


}


void searchavr();


void room::enteru()
{
          cout<<"Name?"<<endl;
          gets(name);
          cout<<"Email?"<<endl;
          gets(email);
          cout<<"Phone?"<<endl;
          cin>>phone;
          cout<<"Days?"<<endl;
          cin>>nodays;


}


void room::changeprice(float a)
{
 roomprice==a;
}


void room::exit()
{
         cout<<roomnumber;
         cout<<roomtype;
         gets(name);
         gets(email);
         cout<<phone;
}




void admininput()
{
 clrscr();
 fstream a;


   a.open("ROOM.DAT", ios::out|ios::binary);
  room r;
  cout<<"Enter Room details:\n";
  char ch;
  do
  {


   r.entera();


   a.write((char*)&r, sizeof(r));
   cout<<"More Rooms?(y/n); ";
   cin>>ch;
   }while(ch=='y');


  a.close();
}




void userinput()
{
   clrscr();
   room r;
   int x, found=0;
   fstream a;
   cout<<"Enter the room number that you want";
   cin>>x;


   a.open("ROOM.DAT", ios::in|ios::out|ios::binary);


   while(a.read((char*)&r, sizeof(r)) && found==0)


   {
        if(r.rrn()==x && r.ra()==0)
         {


           r.fillroom();


           r.enteru();
           r.Display();
           r.DisplayU();
          a.seekp(a.tellg()-sizeof(a));
          a.write((char*)&r, sizeof(r));


         cout<<"Assigned..."<<endl;
         found=1;
         }
   }


         a.close();
}


void DisplayAll()
{
   clrscr();
   room r;
   fstream a;
   a.open("ROOM.DAT", ios::in|ios::binary);


   while(a.read((char*)&r, sizeof(r)))
         r.Display();


         a.close();
}
void checkout()
{
   clrscr();
   fstream a;
   a.open("ROOM.DAT",ios::binary|ios::in|ios::out);


   room r;
   int roomno;
   cout<<"Enter the room number";
   cin>>roomno;
   int found=0;
  int cost;


   while(a.read((char*)&r,sizeof(room)) && !found)
   {
         if(r.rrn()==roomno){
                cost=r.rrp() * r.rnd();
                cout<<"num of days"<<r.rnd();
                cout<<"price of room"<<r.rrp();
                cout<<"Total amount to be paid is"<<cost<<endl;
                r.basic();
                a.seekp(a.tellg()-sizeof(a));
                a.write((char*)&r, sizeof(room));
        }
   }
   a.close();
}




void searchbyname()
{
 fstream a;
 char data[20];
 room r;
 cout<<endl<<"Enter Name";
 puts(data);
 a.open("room.DAT" ,ios::binary| ios::in);
 int found=0;




 while(found==0 && a.read((char*)&r, sizeof(r)))
 {
   if(strcmp(data, r.rn())==0)
   {
         found++;
         r.exit();
   }
  }
 a.close();
}




void searchbyroom(int data)
{
 fstream a;


 a.open("ROOM.DAT",ios::binary| ios::in);
 int found=0;
 room r;


 while(found==0 && a.read((char*)&r, sizeof(r)))
 {
   if(data==r.rrn())
   {
   //         r.changera();
         found++;


   }
  }
 a.close();


}




void searchbytype()
{
 fstream a;


 a.open("ROOM.DAT",ios::binary| ios::in);
 int found=0;
 room r;
 char type[20];
 cout<<"Enter your new room type";
 cin>>type;
 while(found==0 && a.read((char*)&r,sizeof(r)))
 {
   if((strcmp(type,r.rrt())==0)&&r.ra()==0)
   {
         r.rn();
         found++;


   }
  }
 a.close();


}


void upgrade()
{
   clrscr();
   fstream a;
   a.open("ROOM.DAT",ios::binary|ios::in|ios::out);
   room r1,r2;
   int roomno,newroomno;
   int found=0;
   cout<<"Enter your room number"<<endl;
   cin>>roomno;
   searchbyroom(roomno);
   r1.basic();
   searchavr();
   cout<<"Choose new room";
   cin>>newroomno;
   while(a.read((char*)&r2,sizeof(room)) && !found)
   {
        if(r2.rrn()!=newroomno)
        {a.seekg(a.tellg()-sizeof(room));


         r2.enteru();
         a.write((char*)&r2,sizeof(r2));
         found++;
        }
  }
  a.close();
}




void searchavr()
{
 clrscr();
 room r;
 fstream a;
 a.open("ROOM.DAT",ios::binary|ios::in);
 while(a.read((char*)&r, sizeof(r)))
 {
        if(r.ra()==0)
                cout<<"Room number: "<<r.rrn()<<"Room type: "<< r.rrt()<<endl;


 }
a.close();


}








void editroomprice()
{  clrscr();
   fstream a;
   a.open("ROOM.DAT", ios::binary| ios::out|ios::in) ;
   room r;
   int roomno;
   cout<<"Enter the room number";
   cin>>roomno;
   float price;
   cout<<"Enter the new price of the room";
   cin>>price;


   while(a.read((char*)&r, sizeof(room)))
   { if(r.rrn()==roomno)
        r.changeprice(price);
   }


   a.seekg(a.tellg()-sizeof(r));
   a.write((char*)&r,sizeof(r));


 }




void usertotal()
{ clrscr();
  int cho;


  do
  {
          cout<<" 1: Search for Available Rooms"<<endl;
          cout<<" 2: Book a room"<<endl;
          cout<<" 3: Dislpay all rooms"<<endl;
          cout<<" 4: Exit to the main menu"<<endl;
          cin>>cho;




   switch(cho)
   {
        case 1: searchavr(); break;
        case 2: userinput(); break;
        case 3: DisplayAll(); break;
        case 4: cout<<"Exiting..."<<endl;
   }
  } while(cho!=4);


}


void admintotal()
{ clrscr();
  int c;


  do
  {


  cout<<"1:Input Basic Details"<<endl;
  cout<<"2:Assign Room to Guest"<<endl;
  cout<<"3:Upgrade Room"<<endl;
  cout<<"4:Room Prices"<<endl;
  cout<<"5:Display all rooms\n";
  cout<<"6:Checkout"<<endl;
  cout<<"7:Exit to Main Menu"<<endl;
  cin>>c;


        switch(c)
        {
         case 1: admininput();             break;


         case 2: searchavr(); userinput(); break;


         case 3: upgrade();                break;


         case 4: editroomprice();          break;


         case 5: DisplayAll(); break;


         case 6: checkout();               break;


         case 7: cout<<"Exiting...";       break;
        }


   }
   while(c!=7);
}




void main()
{
   clrscr();
   int ch;




   do
   {
          cout<<"1.Admin   2.User   3.Quit "<<endl;
          cin>>ch;
          switch(ch)
                {
                        case 1:admintotal(); break;
                        case 2:usertotal(); break;




                }
          }while(ch!=3);


          getch();
}