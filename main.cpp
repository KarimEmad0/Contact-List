#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//---------------------------------------------------
struct node{
 string name,email,phonenumber;
 node* next;
  };

 struct NODE{
  string newnumber;
  NODE* NEXT;
 };
node* Front=NULL;
node* rear=NULL;
NODE* head=NULL;
int counter=1;


//----------------------------------------------------
void Add_Contact(string newname,string newemail,string newnum)
{
  node* temp=new node;
  temp->name=newname;
  temp->email=newemail;
  temp->phonenumber=newnum;
  if(Front==NULL)                            //in case linked is empty
   {                                         // used queue method to display elements with records 1,2,3,.... not 3,2,1
  Front=temp;
  rear=temp;
  temp->next=NULL;
   }
  else if(rear!=NULL)                         //in case there is exist node
  {
      node* pos=Front;
    if(temp->name<=pos->name)     // in case the new node < first node
         {
          temp->next=pos;
          Front=temp;
          rear->next=NULL;

         }
    else {
       while(pos!=NULL)
       {
           if(pos->next==NULL)
           {
               pos->next=temp;
               temp->next=NULL;

               break;
           }
         else if(temp->name<=pos->next->name)
         {
             temp->next=pos->next;               //temp link with the next node
             pos->next=temp;                      //previous temp linked

             break;
         }
         pos=pos->next;
     }

       }
  }

}
//---------------------------------------------------------
void Add_Number(string number)
{
  NODE* raw=new NODE;
  raw->newnumber=number;     //option to add new number for an exist contact
  raw->NEXT=head;
  head=raw;
}
//---------------------------------------------------------------
// edit email or number for an exist contact
void Edit(string name,int choice)
{
  string newemail,mobileNumber,prenumb;
  node* ptr=Front;
  bool flag;
  while(ptr!=NULL)
  {
     if(ptr->name.compare(name)==0)           //searching for contact
     {
        flag=true;                            //contact is exist
        if(choice==1)                          //change email
        {
            cout<<"Please enter the new email that you want to edit"<<endl;
            getline(cin,newemail);
            ptr->email=newemail;
        }
        else if(choice==2)                   //change number
        {
            NODE* z=head;
            cout<<"Numbers of this contact "<<endl; //give you all number for this contact to choose one that you want to edit
            int pos=1;
            cout<<pos<<"- "<<ptr->phonenumber<<endl;
            while(z!=NULL)
            {
                pos++;
                cout<<pos<<"- "<<z->newnumber<<endl;
                z=z->NEXT;
            }
            string fnumber,prenumber;
            cout<<"please enter the number that you want to change"<<endl; // choos number
            getline(cin,prenumb);
            cout<<"please enter the new number "<<endl;                 //enter number after edit
            getline(cin,fnumber);
            if(prenumb==ptr->phonenumber)
            {
                ptr->phonenumber=fnumber;
                break;
            }
            NODE* t=head;
            while(t!=NULL)                               //if is not first number search for another
            {
                if(prenumb==t->newnumber)
                {
                    t->newnumber=fnumber;     //found the number so remove the old and put the new
                    break;
                }
            }
        }
    }
     ptr=ptr->next;
  }
  if(!flag)                                     //in case the name not exist and you want to add new contact
  {
      cout<<"This name not exist"<<endl;
      cout<<"if you want to add new contact press 1 or 2 to exit"<<endl;
      int ch;
      cin>>ch;
      cin.clear();
      cin.sync();
      string name,email,number;
      if(ch==1)
      {
      cout<<"Please Enter the name that you want to add"<<endl;
      getline(cin,name);
      cout<<"Please Enter the email_address that you want to add"<<endl;
       getline(cin,email);
      cout<<"Please Enter the phoneNumber that you want to add"<<endl;
      getline(cin,number);
      Add_Contact(name,email,number);
      }
  }
  else if(Front==NULL)
  {
      cout<<"There is no contacts"<<endl;
  }
}
//--------------------------------------------------------------------------
// function to delete node with name
void Delete(string name)
{
    int c=0;
    node* ptr=Front;
    bool flag;
  while(ptr!=NULL)
  {
         c++;
         if(ptr->name.compare(name)==0)           //searching for the name
         {
            flag=true;
             break;
         }
        ptr=ptr->next;
  }
    if(!flag)                                     //not true =false so  ( Do this scope )
    {
        cout<<"There is no contacts"<<endl;
    }
else {                                    // if flag= true
    node* q=Front;
   node* newptr=Front;
      if(c==1)
      {
       Front=Front->next;
       delete(q);                         // delete node
       }
      else{
         for(int i=1; i<c-1; i++)
          {
            q=q->next;
            newptr=newptr->next;
          }
          newptr=newptr->next;
          q->next=newptr->next;
          delete(newptr);
        }
   }
}
//---------------------------------------------------------
void display()
{
  NODE* pointer=head;
  node* q=Front;
  cout<<setw(6)<<"record"<<setw(20)<<"name"<<setw(30)<<"email_address"<<setw(14)<<"phonenumber"<<endl;
  while (q!=NULL)
   {
     cout<<setw(6)<<counter<<setw(20)<<q->name<<setw(30)<<q->email<<setw(14)<<q->phonenumber<<endl;
         while(pointer!=NULL)
         {
             cout<<setw(67)<<pointer->newnumber;
             pointer=pointer->NEXT;
         }
     counter++;
     q=q->next;
   }
}
//------------------------------------------------------------
//function to start delete exist contact and start new contact
void reset()
{
  node* q=Front;
  node* ptr=Front;
  while(q!=NULL)
  {
   ptr=ptr->next;           //delete all contacts
   delete(q);
   q=ptr;
  }
}

//-------------------------------------------------------------
void Search_Contact(string name)
{
   node* ptr=Front;
  while(ptr!=NULL)
  {
       if(ptr->name.compare(name)==0)
        {
            cout<<ptr->name<<"   "<<ptr->email<<"   "<<ptr->phonenumber<<endl;
            return ;
        }
        ptr=ptr->next;
  }
  cout<<"No such person is found"<<endl;
}
//--------------------------------------------------------------
bool Search(string name)
{
   node* ptr=Front;
  while(ptr!=NULL)
  {
       if(ptr->name.compare(name)==0)
        {
           return true;
        }
        ptr=ptr->next;
  }
  return false;

}
//------------------------------------------------------------------------------------------------------------------
int main()
{
// this part to get information and trase functoin .
  string name,number,email,tryname,editname,deletename;
    // Add_Contact(name,email,number);
//-----------------------------------------------------

 //this part to choose from functions

    cout<<"If you want to add new contact please  press    1 "<<endl;
    cout<<"If you want to edit    contact please  press    2 "<<endl;
    cout<<"If you want to delete  contact please  press    3 "<<endl;
    cout<<"If you want to display contacts please press    4 "<<endl;
    cout<<"If you want to  reseat contacts please press    5 "<<endl;
    cout<<"If you want to  search for contact please press 6 "<<endl;
     int choose;
     cin>>choose;
     cin.clear();
     cin.sync();
//-----------------------------------------------------------
// to add contact or add newnumber
     if(choose==1)
    {
        for(int i=0;i<5;i++)
        {
      cout<<"Please Enter the name that you want to add"<<endl;            //searching for the name that want to add
      getline(cin,tryname);
      name=tryname;                                                  // (save tryname) in case that isn't found
     if(!Search(name))                                              //if it is not exist save new contact
     {
         cout<<"This name isn't exist. "<<endl;
         cout<<"please enter  email_address "<<endl;
         getline(cin,email);
         cout<<"please enter Phonenumber"<<endl;
         getline(cin,number);
         Add_Contact(name,email,number);
     }
    else {                                                                //if it's exist if you want to add number
         cout<<"This name is already exist"<<endl;
         cout<<"if you want to add new number press 1 or press -1 to exit"<<endl;
         int to_continue;
         cin>>to_continue;
         cin.clear();
         cin.sync();
         if(to_continue==1)
          {
          string newnumber;
          cout<<"Enter the phonenumber"<<endl;
          getline(cin,newnumber);
          Add_Number(newnumber);
          }
        }
        }
        display();
    }
//---------------------------------------------------------------
// To edit contact

else if(choose==2)
{

    cout<<"Please Enter the name that you want to edit"<<endl;
    getline(cin,editname);
    cout<<"if you want to edit email press 1 or press 2 to edit phone number"<<endl;
    int choice;
    cin>>choice;
    cin.clear();
    cin.sync();
    Edit(editname,choice);
}


//-------------------------------------------------------------------
// To delete contact
else if(choose==3)
{
    cout<<"Enter the name of contact that you want to delete"<<endl;
    getline(cin,deletename);
    Delete(deletename);
}
//-------------------------------------------------------------------
// to display elements
 else if(choose==4)
      {
       display();
      }
//-----------------------------------------------------------------
//to reset contact list
else if(choose==5)
{
    reset();
}
//-----------------------------------------------------------------------
// to search for contact
else if(choose==6)
{
    string searchname;
    cout<<"Please enter the name that you want to search for"<<endl;
    getline(cin,searchname);
    Search_Contact(name);
}

    return 0;
}
