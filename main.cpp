#include <iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int check()
    {
        system("cls");
    cout<<"\n\n\t\t\t\tEnter your Password: ";
    char password[11],word[11];
    gets(password);
    ifstream pfile("libsc++.dll",ios::in);
   if(pfile)
       {pfile.getline(word,11);}
   else
          cout<<"-------------------------ERROR File missing------------------------";
   int a;
   a=strcmp(word,password);
   pfile.close();
   return a;
    }

class key
{
    public:
    int srno;
    char pskey[9],title[100],des[10000];

    void show()
    {
        cout<<"\n-------------------------***********************-------------------------";
        cout<<"\n\t\t";cout<<"Sr No.  "<<srno<<"\n"<<"\n\t\t PASSKEY:-     ";
        puts(pskey); cout<<endl;
        cout<<"\t\t";cout<<"Title:-   "; puts(title);
        cout<<"\n\t\t";cout<<"Description :  ";
        puts(des);
        cout<<"\n-------------------------***********************-------------------------";
    }
    void input()
    {
        cout<<"\nEnter Serial No. ";
        cin>>srno;
        cout<<"\nEnter your Passkey ";
        getchar();
        gets(pskey);
        cout<<"\nEnter a Title for it. ";
        getchar();
        gets(title);
        cout<<"\nEnter Description ";
        gets(des);
        cout<<"\tTHANK YOU";
    }
    void inputr()
    {
        cout<<"\nEnter serial no. ";
        cin>>srno;
        cout<<"\nEnter Title for your key ";
        getchar();
        gets(title);
        cout<<"\nDecription of it ";

        gets(des);
        show();
    }

};
void gen()
{
    key obj;
    obj.input();
    ofstream file("libcal.dll.dat",ios::out|ios::app|ios::binary);
    if(file)
    file.write((char*)&obj,sizeof(obj));
    else cout<<"\n|||||||| File could not be opened. |||||||";
    file.close();
    obj.~key();

}
void out()
{
    cout<<"\n 1. View all records \n2. Specific Record \t";
    int res; cin>>res;
    if (res==1)

    {
        int t=0;
    key robj,revobj;
    ifstream revf("libcal.dll.dat",ios::binary);
    revf.read((char*)&revobj,sizeof(revobj));
    revf.close();
    ifstream f("libcal.dll.dat",ios::in|ios::binary);
        if(f)
       {

           do
           {f.read((char*)&robj,sizeof(robj));
           if(t!=1)
           robj.show();
           if(revobj.srno==robj.srno)
            ++t;
           revobj=robj;
           } while(!f.eof());
       }
       else
        cout<<"\nFile coud not be opened.";
         f.close();
    robj.~key();
    revobj.~key();
    }

    else if(res==2)
    {
        cout<<"\n\nEnter Serial No. ";
        int serial; cin>>serial;
        key sobj;
    ifstream fin("libcal.dll.dat",ios::binary);
    while(fin)
    {
        fin.read((char*)&sobj,sizeof(sobj));
        if (sobj.srno==serial)
           { sobj.show(); break; }
    }
    fin.close();
    sobj.~key();

    }
}
void rankey()
{
    char ans;
    key ranobj;
    time_t t;
     unsigned int seedval=time(&t);
    srand(seedval);
    char passwd[9],ch;
    cout<<"\n\n*****************-----------CATAEGORIES-----------**********:\n\n1. Only Numerals and Aplhabets\n\n2. Numerals and Aplhabets with '#'   '*'   '&' and '@'\n\n3. Numerals, Aplhabets and '@'\n\n4. All charcters.";
    int c; cin>>c;
    if(c==1)
    {
        for(int i=0;i<8;i++)
    {
        ch=(rand()%75)+48;
        while((ch>=58&&ch<=64)||(ch>=91&&ch<=96))
           ch=(rand()%75)+48;
        passwd[i]=(ch);
    }
    }
    else if(c==2)
    {
        for(int i=0;i<8;i++)
    {
        ch=(rand()%88)+35;
        while((ch>=58&&ch<=62)||(ch>=91&&ch<=96)||(ch>=39&&ch<=41)||(ch>=43&&ch<=47)||ch==36||ch==37||ch==63)
           ch=(rand()%88)+35;
        passwd[i]=(ch);
    }
    }
    else if(c==3)
    {
        for(int i=0;i<8;i++)
    {
        ch=(rand()%75)+48;
        while((ch>=58&&ch<=64)||(ch>=91&&ch<=96))
           { ch=(rand()%75)+48; }
        passwd[i]=(ch);
    }
    }
    else if (c==4)
    {
        for(int i=0;i<8;i++)
    {
        ch=(rand()%88)+35;
        while((ch>=58&&ch<=62)||(ch>=91&&ch<=96)||(ch>=39&&ch<=41)||(ch>=44&&ch<=47))
           ch=(rand()%88)+35;
        passwd[i]=(ch);
    }
    }
    cout<<"\nYour Password is ";
    puts(passwd);
    cout<<"\nDo you want to save it y or n ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
    {
        strcpy(ranobj.pskey,passwd);
        ranobj.inputr();
        ofstream fout("libcal.dll.dat",ios::binary|ios::app);
        fout.write((char*)&ranobj,sizeof(ranobj));
        fout.close();
    }
    ranobj.~key();
}
void del()
{
    cout<<"\nEnter serial no ";
    int no;cin>>no;
    key delobj;
    ifstream fin("libcal.dll.dat",ios::binary);
    ofstream fout("file.dat",ios::binary);
    while(fin)
    {
        fin.read((char*)&delobj,sizeof(delobj));
        if (delobj.srno!=no)
            fout.write((char*)&delobj,sizeof(delobj));
    }

    fout.close();
    fin.close();
    remove("libcal.dll.dat");
    rename("file.dat","libcal.dll.dat");
    delobj.~key();
}
void endo()
{
    double m=0;
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t--Concept M--";
     cout<<"\n\n\n--------------------------THANK YOU----------------------------";
    for(double j=0;j<100000000;j+=0.1)
                  m++;
}
void tools()
{
cout<<"\n-------------------------------------------TOOLS--------------------------";
cout<<"\n\n\t1. Generate a backup file.\n\n2. To change password.\n\n";
int c;cin>>c;
if(c==1)
{
    ofstream file("backup1.txt",ios::out);
    file<<"class key  public:  int srno;    char pskey[9],title[100],des[10000];";
    file.close();
    ofstream fine("backup2.dat",ios::binary);
    ifstream fin("libcal.dll",ios::binary);
    key bobj;
    do
    {
        fin.read((char*)&bobj,sizeof(bobj));
        fine.write((char*)&bobj,sizeof(bobj));
    }while(fin);
    fine.close();
    fin.close();
    bobj.~key();
    ofstream fout("readme.txt",ios::out);
    fout<<"\n----------------HELLO--------------------\n";
    fout<<"1. backup 1 consist of class that was used in source during making of this program.";
    fout<<"\n2. backup2 file consist of the database.*******BEWARE DO NOT SHARE IT POSITIVELY*************";
    fout<<"\n3. Make sure to delete backup files after using them.";
    cout<<"\nDone back up is in files 1 and 2 please read 'read me' file.";

}
else if(c==2)
    cout<<"\n\nTo change password open crypt.exe";

}
int main()
{
   int b=check();
   system("cls");
   if(b==1)
   {
   int choice;
   cout<<"\n************************************----------------------------------*******************************";
   cout<<"\n\n\n\t\t\t\t\t   *******WELCOME*****";
       cout<<"\n\n\n\n\t\t\t        --------------------MENU------------------";
    cout<<"\t\t\t\t\n\n\n1. Store a new passkey.\n2. Generate a random key.\n3. Search passkey.\n4. Delete passkey.\n5. EXIT.\n\n\n6. TOOLS\n\n\t";
    cin>>choice;
    while(choice!=5)
    {
        if (choice==1)
            gen();
        else if (choice==2)
            rankey();
        else if (choice==3)
            out();
        else if(choice==4)
                del();
        else if(choice==6)
            tools();
        cout<<"\nEnter your key again as of menu.\n";
        cin>>choice;
    }

    endo();
   }
   else
    return 1;

    return 0;
}

