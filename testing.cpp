#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<sstream>
#include<limits>
#include<bits/stdc++.h>

using namespace std;
class tree;

class file
{

 char path[100];
 char filename[100];
 int type;
 public:
 friend file *createfile();
 void rename2(string);
 void writedata();
 void readdata();
 friend void addfile(tree *,int);
 friend void displayfile(tree *);
 friend void deepcopy3(file *,file &);
 friend void deepcopy5(file&, file*);

};


class tree
{

char name[100];
char pass[100];
char user[100];

vector<file *> headfile;
vector<tree *> headfolder;
tree *back;
tree *self;
int type;


public:
int countfile;

friend tree *createtree();
int password();
void setpass();
void rename1(string);
file * fileselect(int);
friend void addfile(tree *,int);
void delfile(int);
void addfolder();
friend void displayfile(tree *);
void display();
void delfolder(int);
void deleteall();
void store();
void shutdown1();
tree* folderselect(int);
void menu();
friend void connect1(tree *,tree *);
void connectfile(file *,int);
friend void travel(tree *,tree *);
void ready();
friend void deepcopy(tree *,tree *);
friend int main();
friend void deepcopy2(tree *,tree &);
friend void deepcopy4(tree &,tree *);
friend tree* retrieve();
void filedisplay();
};

void convert(char *ch,string s)
{

  int i;
  for(i=0;i<s.size();i++)
  {
     ch[i]=s[i];
  }

  ch[i]='\0';

}


tree *createtree()
{
    tree *temp=new tree;
    strcpy(temp->name," ");
    strcpy(temp->pass," ");
    strcpy(temp->user," ");
    temp->back=NULL;
    temp->self=temp;
    temp->type=0;
    temp->countfile=0;
    return temp;
}

file *createfile()
{
    file *temp=new file;
    strcpy(temp->filename," ");
    strcpy(temp->path," ");
    temp->type=0;

    return temp;
}

void deepcopy(tree *a,tree *b)
{
   strcpy(a->name,b->name);
   strcpy(a->pass,b->pass);
   strcpy(a->user,b->user);

    a->back=b->back;
    a->self=b->self;
    a->type=b->type;
    a->countfile=b->countfile;

  a->headfolder.assign(b->headfolder.begin(),b->headfolder.end());
  a->headfile.assign(b->headfile.begin(),b->headfile.end());
}

void deepcopy2(tree *a,tree &b)
{
    strcpy(a->name,b.name);
    strcpy(a->user,b.user);
    strcpy(a->pass,b.pass);
    a->back=b.back;
    a->self=b.self;
    a->type=b.type;
    a->countfile=b.countfile;

}

void deepcopy3(file *a,file &b)
{
   strcpy(a->filename,b.filename);
   strcpy(a->path,b.path);
   a->type=b.type;
}

void deepcopy4(tree &a,tree *b)
{
    strcpy(a.name,b->name);
    strcpy(a.user,b->user);
    strcpy(a.pass,b->pass);
    a.back=b->back;
    a.self=b->self;
    a.type=b->type;
    a.countfile=b->countfile;
}
void deepcopy5(file &a,file *b)
{
   strcpy(a.filename,b->filename);
   strcpy(a.path,b->path);
   a.type=b->type;
}


char* typepass()
{

   char c;
   char pass[40];

   int k=0;
   while((c=getch())!='\r')
   {

   if(c!='\b')
   {
    printf("*");
    pass[k]=c;
    k++;
   }

    else
   {
    printf("\b \b");
    pass[k]=' ';
    k--;

   }


   }
    pass[k]='\0';

    return pass;
}

int tree::password()
{

    cout<<"\n\nENTER THE PASSWORD :: ";
    int ch=0;

    if(strcmp(this->pass,typepass())==0)
    {
      ch=1;
    }

    return ch;
}

void tree::setpass()
{

   if(strcmp(this->pass," ")==0)
    {
     cout<<"\n\n ENTER THE PASSWORD :: ";
     strcpy(this->pass,typepass());
     cout<<" \n\n PASSWORD SUCESSFULLY CHANGED \n\n";
    }

    else
    {

        cout<<"\n\n ENTER THE PREVIOUS PASSWORD :: ";

        if(strcmp(this->pass,typepass())==0)
        {

            cout<<" \n\n ENTER THE NEW PASSWORD :: ";

            strcpy(this->pass,typepass());

            cout<<" \n\n PASSWORD SUCESSFULLY CHANGED \n\n";

        }

        else
        {

         cout<<"\n\n OOPS! PASSWORD CANNOT BE CHANGED \n\n";

        }


    }

 getch();
}

void tree::filedisplay()
{
   system("cls");

   int choice;

   cout<<"\n  SELECT FILE TYPE :: \n\n";
   cout<<" 1. TEXT FILE \n";
   cout<<" 2. WORD DOCUMENT \n";
   cout<<" 3. PDF DOCUMENT \n";

   cout<<"\n\n\n ENTER CHOICE:: ";
   cin>>choice;

   system("cls");
   addfile(this,choice);


}

void tree::rename1(string name)
{
    convert(this->name,name);
    if(this->type==1)
    {
    cout<<"\n DRIVE RENAMED SUCESSFULLY ";
    }

    else
    {
     cout<<"\n FOLDER RENAMED SUCESSFULLY ";
    }

    getch();
}

void file::rename2(string name)
{
   convert(this->filename,name);

   cout<<"\n FILE RENAMED";
   getch();

}

file *tree::fileselect(int choice)
{

    if(choice>this->headfile.size())
    {
       cout<<"\n FILE NOT FOUND!!! ";
       getch();
       return NULL;
    }

    else
    {
      vector<file *>::iterator z=this->headfile.begin();
      advance(z,choice-1);

      return (*z);
    }
}

void file::writedata()
{
 if(this->type==1)
 {
   system("cls");

    fstream handle;

   handle.open(this->path,ios::out|ios::app);

   cout<<"\n ::W R I T E    M O D E:: \n";

   char c;

   while((c=getc(stdin))!=EOF)
   {
      handle.put(c);
   }

  handle.close();
  getch();
 }

 else if(this->type==2)
 {
     fstream ptr;
    ptr.open("open.bat",ios::out);

    string op;
    op="start ";

    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }
    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
       ptr.put(this->filename[lk]);
    }
    op=".doc";
    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }

    ptr.close();

    system("open.bat");

    system("cls");
 }

 else if(this->type==3)
 {
    system("cls");

    fstream handle;

   handle.open("create.bat",ios::out);

    string op;
    op="copy con ";

    for(int lk=0;lk<op.size();lk++)
    {
       handle.put(op[lk]);
    }
    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
     handle.put(this->filename[lk]);
    }
    op=".doc ";
    for(int lk=0;lk<op.size();lk++)
    {
       handle.put(op[lk]);
    }
  handle.close();

  system("create.bat");


   handle.open("convert.bat",ios::out);

    op="OfficeToPDF ";

    for(int lk=0;lk<op.size();lk++)
    {
       handle.put(op[lk]);
    }
    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
       handle.put(this->filename[lk]);
    }
    op=".doc ";
    for(int lk=0;lk<op.size();lk++)
    {
       handle.put(op[lk]);
    }

    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
       handle.put(this->filename[lk]);
    }
    op=".pdf ";
    for(int lk=0;lk<op.size();lk++)
    {
       handle.put(op[lk]);
    }
   handle.close();

   system("convert.bat");
   system("cls");

 }

}

void file::readdata()
{
    system("cls");

  if(this->type==1)
  {
    fstream handle;
    handle.open(this->path,ios::in);

    char c;

    cout<<"\n ::R E A D   M O D E:: \n";

    while(!handle.eof())
    {
       handle.get(c);
       cout<<c;
    }

   handle.close();
   getch();
  }
  else if(this->type==2)
  {
    fstream ptr;
    ptr.open("open.bat",ios::out);

    string op;
    op="start ";

    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }
    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
       ptr.put(this->filename[lk]);
    }
    op=".doc";
    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }

    ptr.close();

    system("open.bat");

    system("cls");

  }
  else if(this->type==3)
  {
     fstream ptr;
    ptr.open("open.bat",ios::out);

    string op;
    op="start ";

    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }
    for(int lk=0;this->filename[lk]!='\0';lk++)
    {
       ptr.put(this->filename[lk]);
    }
    op=".pdf";
    for(int lk=0;lk<op.size();lk++)
    {
       ptr.put(op[lk]);
    }

    ptr.close();

    system("open.bat");

    system("cls");

  }

}

void addfile(tree *node,int choice)
{
   string name;
   string path;

   cout<<"\n ENTER THE NAME OF THE FILE:: ";
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   getline(cin,name);

   file *temp=createfile();
   convert(temp->filename,name);
if(choice==1)
{
   path="C:\\";
   path+=name;
   path+=".txt";
   convert(temp->path,path);
   temp->type=1;
}

else if(choice==2)
{
    path="C:\\";
    path+=name;
    path+=".doc";
    convert(temp->path,path);
    temp->type=2;

  string xc;
  xc=name;
  xc+=".doc";

  fstream ext;
  ext.open(xc.c_str(),ios::out);
  ext.close();

}
else if(choice==3)
{
   path="C:\\";
    path+=name;
    path+=".pdf";
    convert(temp->path,path);
    temp->type=3;

  string xc;
  xc=name;
  xc+=".doc";
}
    node->headfile.push_back(temp);

   cout<<"\n FILE SUCESSFULLY CREATED";
   node->countfile++;
   getch();
 temp->writedata();

 }


void tree::delfile(int choice)
{

  if(choice>this->headfile.size())
  {
      cout<<"\n FILE NOT FOUND!!!";
      getch();

      system("cls");
      this->display();
      this->menu();
  }

  else
  {
    vector<file *>::iterator z=this->headfile.begin();
    advance(z,choice-1);
    this->headfile.erase(z);

    cout<<"\n FILE DELETED" ;
    this->countfile--;
    getch();
  }
}


void tree::addfolder()
{
    string name;

    if(this->type==2)
    {
    cout<<"\n\n ENTER THE NAME OF THE DRIVE:: ";
    }

    else
    {
     cout<<"\n\n ENTER THE NAME OF THE FOLDER:: ";
     cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }


    getline(cin,name);


    tree *temp=createtree();
    convert(temp->name,name);
    temp->back=this;

    this->headfolder.push_back(temp);

  if(this->type==2)
  {
     temp->type=1;
     cout<<"\n DRIVE CREATED SUCESSFULLY ";
  }

  if(this->type==1)
  {
      temp->type=0;
      cout<<"\n FOLDER CREATED SUCESSFULLY ";
  }
  getch();

}

void displayfile(tree *node)
{
    if(node->type!=2)
    {
    int k=1;

    cout<<"\n\n :: FILES :: \n\n";

    if(node->headfile.empty())
    {
     cout<<"\n ---- EMPTY ----\n";
    }

    else
    {
        vector<file *>::iterator z=node->headfile.begin();

        while(z!=node->headfile.end())
        {
            cout<<k<<". ";
            cout<<(*z)->filename;

            if((*z)->type==1)
            {
              cout<<".txt\n";
            }
            else if((*z)->type==2)
            {
              cout<<".doc\n";
            }
            else if((*z)->type==3)
            {
              cout<<".pdf\n";
            }

            k++;
          z++;
        }
     }
  }

}


void tree::display()
{

  int k=1;

  if(this->type==2)
  {
    cout<<"\n\n :: HARD DISK DRIVES :: \n\n";
  }

  else
  {
     cout<<"\n\n :: FOLDERS :: \n\n";
  }

 if(this->headfolder.empty())
 {

  cout<<"\n ---- EMPTY ---- \n";

 }

 else
  {

    vector<tree *>::iterator z=this->headfolder.begin();

    while(z!=this->headfolder.end())
    {
     cout<<k<<". "<<(*z)->name<<"\n";
     k++;

     z++;
    }
  }
 displayfile(this);

}


void tree::delfolder(int choice)
{

  if(choice>this->headfolder.size())
  {
     if(this->type==2)
     {
      cout<<"\n DRIVE NOT FOUND!!!";
     }

     else
     {
       cout<<"\n FOLDER NOT FOUND!!!";
     }
  }

  else
  {
      vector<tree *>::iterator z=this->headfolder.begin();
      advance(z,choice-1);
      this->headfolder.erase(z);

      if(this->type==2)
     {
      cout<<"\n PARTITION DELETED ";
     }
     else
     {
      cout<<"\n FOLDER DELETED ";
     }

  }

  getch();

  system("cls");
}

void tree::deleteall()
{

this->headfolder.clear();

}

void gotoxy(int x,int y)
{

    for(int i=0;i<y;i++)
    {
     cout<<"\n";
    }
    for(int i=0;i<x;i++)
    {
     cout<<" ";
    }
}

void initialize()
{
    system("cls");

    gotoxy(25,10);
    cout<<"FILE SYSTEM IS STARTING.";
    Sleep(1000);
    system("cls");


    gotoxy(25,10);
    cout<<"FILE SYSTEM IS STARTING..";
    Sleep(1000);
    system("cls");


    gotoxy(25,10);
    cout<<"FILE SYSTEM IS STARTING...";
    Sleep(1000);
    system("cls");
}

void tree::store()
{
    fstream ptr;
    ptr.open("source.txt",ios::binary|ios::out|ios::app);

    tree assist;
    deepcopy4(assist,this);

    ptr.write((char*)&assist,sizeof(assist));

   vector<file *> ::iterator z=this->headfile.begin();

    file assist2;

    while(z!=this->headfile.end())
    {
       deepcopy5(assist2,*z);
       ptr.write((char *)&assist2,sizeof(assist2));
       z++;
    }


   ptr.close();
    vector<tree *>:: iterator z2=this->headfolder.begin();

    while(z2!=this->headfolder.end())
    {
      (*z2)->store();
       z2++;
    }

}

void tree::shutdown1()
{
    system("cls");
    gotoxy(25,10);

    cout<<"LOGGING OFF...";

    Sleep(2000);

    system("cls");
    gotoxy(25,10);

    cout<<"SHUTTING DOWN...";

    Sleep(3000);
    system("cls");

    fstream ptr;
    ptr.open("source.txt",ios::binary|ios::out);
    ptr.close();
    this->store();

    exit(0);
}


tree * tree::folderselect(int x)
{

    if(x>this->headfolder.size())
   {
    if(this->type==2)
     cout<<"\n OOPS! DRIVE NOT FOUND ";
    else
     cout<<"\n OOPS! FOLDER NOT FOUND";
     getch();
     return NULL;
   }

  else
   {
     vector<tree *> ::iterator z=this->headfolder.begin();

     advance(z,x-1);

     return (*z);

   }

}


void tree::menu()
{
  cout<<"\n";

  int choice;

  if(this->type==2)
  {
      cout<<"\n 1. FORMAT";
      cout<<"\n 2. RENAME";
      cout<<"\n 3. SET PASSWORD";
      cout<<"\n 4. OPEN";
      cout<<"\n 5. SHUTDOWN";

      cout<<"\n\n CONSOLE-> ";
      cin>>choice;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');

        char pass[100];
        tree *temps;
        char name[100];

          switch(choice)
          {
              case 1:  system("cls");


                        cout<<"\n ENTER PASSWORD:: ";
                        strcpy(pass,typepass());


                       if(strcmp(pass,this->pass)==0)
                       {
                         system("cls");
                         int choice2;

                         cout<<"\n\n 1. ADD PARTITION ";
                         cout<<"\n 2. DELETE PARTITION";
                         cout<<"\n 3. DELETE ALL DATA ";

                         cout<<"\n\n CONSOLE-> ";

                         cin>>choice2;
                         cin.ignore(numeric_limits<streamsize>::max(),'\n');


                         int ch;

                         switch(choice2)
                          {

                           case 1 : this->addfolder();
                                    break;

                           case 2 : cout<<"\n ENTER DRIVE:: ";
                                    cin>>ch;
                                    this->delfolder(ch);
                                    break;

                           case 3 : this->deleteall();
                                    break;

                          }


                        }

                       else
                        {
                          cout<<"\n\n WRONG PASSWORD!!! ";

                          getch();

                          system("cls");

                          this->display();

                          this->menu();

                        }
                      break;

           case 2: system("cls");

                   int drive;


                   cout<<"\n ENTER DRIVE:: ";
                   cin>>drive;

                   temps=this->folderselect(drive);

                  if(temps!=NULL)
                   {
                   cout<<"\n ENTER NAME:: ";
                   string name1;
                   cin.ignore(numeric_limits<streamsize>::max(),'\n');

                   getline(cin,name1);

                   temps->rename1(name1);
                   }

                   break;

            case 3:  system("cls");

                     drive=100;
                     cout<<"\n ENTER DRIVE:: ";
                     cin>>drive;


                     temps=this->folderselect(drive);

                     if(temps!=NULL)
                     temps->setpass();

                     break;

            case 4: system("cls");


                    cout<<"\n ENTER DRIVE:: ";
                    cin>>drive;

                    temps=this->folderselect(drive);

                  if(temps!=NULL)
                  {

                    system("cls");

                     int flag=0;

                    if(strcmp(temps->pass," ")==0)
                    {
                    flag=1;
                    }

                     else
                    {
                     char pass[100];
                     cout<<"\n ENTER THE PASSWORD:: ";

                     strcpy(pass,typepass());

                     if(strcmp(temps->pass,pass)==0)
                     {
                     flag=1;
                     }

                     else
                     {
                     cout<<"\n\n WRONG PASSWORD!!! ";
                     getch();
                     }

                    }

                   system("cls");

                    if(flag)
                   {
                    temps->display();
                    temps->menu();
                   }


                   {
                    this->display();
                    this->menu();
                   }
                  }
                    break;
          case 5:  this->shutdown1();


          }

        system("cls");
        this->display();
        this->menu();

     }


  else
  {

      cout<<"\n 1.CREATE FOLDER  5.CREATE FILE";
      cout<<"\n 2.DELETE FOLDER  6.DELETE FILE";
      cout<<"\n 3.RENAME FOLDER  7.RENAME FILE";
      cout<<"\n 4.OPEN   FOLDER  8.OPEN   FILE";
      cout<<"\n 10.BACK          9.EDIT   FILE";


      cout<<"\n\n CONSOLE-> ";
      cin>>choice;

      system("cls");

       tree *temps;
       file *tempf;

      switch(choice)
      {
         case 1: this->addfolder();
                 system("cls");
                 this->display();
                 this->menu();
                 break;


         case 2: cout<<"\n ENTER FOLDER:: ";
                 int folder;
                 cin>>folder;

                 this->delfolder(folder);
                 system("cls");
                 this->display();
                 this->menu();
                 break;

         case 3: cout<<"\n ENTER FOLDER:: ";
                 cin>>folder;

                 temps=this->folderselect(folder);

                 if(temps!=NULL)
                 {
                 string name;

                 cout<<"\n ENTER THE NEW NAME:: ";

                 cin.ignore(numeric_limits<streamsize>::max(),'\n');

                 getline(cin,name);

                 temps->rename1(name);
                 }

                 system("cls");
                 this->display();
                 this->menu();
                 break;

         case 4: cout<<"\n ENTER FOLDER:: ";
                 cin>>folder;
                 temps=NULL;
                 temps=this->folderselect(folder);

                 if(temps!=NULL)
                 {
                 temps->display();
                 temps->menu();
                 }
                 system("cls");
                 this->display();
                 this->menu();
                 break;
         case 5: this->filedisplay();
                 system("cls");
                 this->display();
                 this->menu();
                 break;


         case 6: cout<<"\n ENTER FILE:: ";
                 int file;
                 cin>>file;

                 this->delfile(file);
                 system("cls");
                 this->display();
                 this->menu();
                 break;

         case 7: cout<<"\n ENTER FILE:: ";
                 cin>>file;

                tempf=this->fileselect(file);

                 if(tempf!=NULL)
                {
                 string filename;
                 cout<<"\n ENTER THE NEW NAME:: ";

                 cin.ignore(numeric_limits<streamsize>::max(),'\n');

                 getline(cin,filename);

                 tempf->rename2(filename);
                 }

                 system("cls");
                 this->display();
                 this->menu();
                 break;

         case 8: cout<<"\n ENTER FILE:: ";
                 cin>>file;

                 tempf=this->fileselect(file);
                 if(tempf!=NULL)
                 tempf->readdata();

                 system("cls");
                 this->display();
                 this->menu();
                 break;
         case 9: system("cls");

                 cout<<"\n ENTER THE FILE:: ";
                 cin>>file;

                 tempf=this->fileselect(file);

                 if(tempf!=NULL)
                 tempf->writedata();

                 system("cls");
                 this->display();
                 this->menu();
                 break;

         case 10: system("cls");
                 this->back->display();
                 this->back->menu();

        }

    }

}

void connect1(tree *head,tree *node)
{
    tree *temp=createtree();

    deepcopy(temp,node);

    head->headfolder.push_back(temp);
}

void tree::connectfile(file *f,int size)
{

  for(int i=0;i<size;i++)
  {

    this->headfile.push_back(f+i);
  }

}

void travel(tree *node,tree *temp)
{

    if(node->self==temp->back)
   {
    connect1(node,temp);
   }

  else
  {
     vector<tree *> ::iterator z=node->headfolder.begin();

     while(z!=node->headfolder.end())
     {
        travel((*z),temp);
        z++;
     }

  }

}


tree *retrieve()
{
  tree assist;

  tree *node=createtree();

  fstream ptr;
  ptr.open("source.txt",ios::in|ios::binary);

  if(!ptr.eof())
  {
   ptr.read((char *)&assist,sizeof(assist));
   deepcopy2(node,assist);
  }

 tree *temp=createtree();


while(!ptr.eof())
  {

   if(ptr.read((char *)&assist,sizeof(assist)))
   {
     deepcopy2(temp,assist);


     int count=temp->countfile;

       if(count)
        {
          file *files=new file[count];
          file assist2;

          for(int i=0;i<count;i++)
           {
             ptr.read((char *)&assist2,sizeof(assist2));
             deepcopy3(files+i,assist2);
           }

          temp->connectfile(files,count);
        }
      travel(node,temp);

    }

  }

ptr.close();

return node;
}

void tree::ready()
{
   this->self=this;

   vector<tree *> ::iterator z=this->headfolder.begin();

   while(z!=this->headfolder.end())
   {
     (*z)->back=this;
      z++;
   }

   z=this->headfolder.begin();

   while(z!=this->headfolder.end())
   {
     (*z)->ready();
     z++;
   }
}

int main()
{

  fstream source;

  source.open("source.txt",ios::out|ios::binary|ios::app);
  source.close();

  tree *computer=retrieve();

  strcpy(computer->name,"ALIENWARE");
  strcpy(computer->pass,"qwerty");
  strcpy(computer->user,"jiitgeeks");
  computer->type=2;

  computer->ready();

   string user;
   char user1[100];
   string pass;
   char pass1[100];


    gotoxy(25,10);
    cout<<" USERNAME:: ";
    getline(cin,user);

    convert(user1,user);

    if(strcmp(computer->user,user1)==0)
    {
    gotoxy(25,2);
    cout<<" PASSWORD:: ";
    strcpy(pass1,typepass());

       if(strcmp(computer->pass,pass1)==0)
       {
        initialize();
       }

       else
       {
         gotoxy(25,2);
         cout<<" WRONG PASSWORD!!! ";

         getch();
         system("cls");
         main();
         return 0;

       }

    }

   else
   {
       gotoxy(25,2);

       cout<<" WRONG USERNAME!!! ";

       getch();

       system("cls");

       main();

       return 0;
    }

 computer->display();

 computer->menu();

 return 0;
}
