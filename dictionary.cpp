#include <iostream>
#include <fstream>
#include<string.h>
using namespace std;
class dictionary
{
  public:
      char word[50];
  private:
      char meaning[100];
  public:
    void accept()
    {
        cout<<endl<<"enter word";
        cin>>word;
        cout<<endl<<"enter meaning";
        cin>>meaning;
    }
    void display()
    {
        cout<<endl<<word<<"\t\t"<<meaning;
    }

};
dictionary obj;

//Writing to a file
void addword()
{
    obj.accept();
    fstream wr;
    wr.open("C:\\students\\mywords.txt",ios::app);
    wr.write((char *)&obj,sizeof(obj));
    cout<<endl<<"Object Written";
    wr.close();
}
void readwords()
{
    fstream rd;
    rd.open("C:\\students\\mywords.txt",ios::in);
    rd.seekg(0,ios::end);
    //calculate the size of file

    int n=rd.tellg();
    //calculate no of objects

    int nwords=n/sizeof(obj);
    //bring file cursor to beginning
    rd.seekg(0,ios::beg);

    for(int i=1;i<=nwords;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        obj.display();
    }
}
void search()
{
    char sr[50];
    cout<<endl<<"Enter Word";
    cin>>sr;

    fstream rd;
    rd.open("C:\\students\\mywords.txt");
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    int nwords=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=nwords;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(sr,obj.word)==0)
        {
            obj.display();
        }

    }
}
void removeword()
{
    fstream rd,wr;
    rd.open("C:\\students\\mywords.txt",ios::in);
    wr.open("C:\\students\\temp.txt",ios::out);

    char s[50];
    cout<<endl<<"Enter Word";
    cin>>s;

    rd.seekg(0,ios::end);
    int n=rd.tellg();
    int nwords=n/sizeof(obj);
    rd.seekg(0,ios::beg);

    for(int i=1;i<=nwords;i++)
    {

        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.word,s)==0)
        {
            cout<<endl<<"Word Deleted Successfully";
        }
        else
        {
           wr.write((char *)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("C:\\students\\mywords.txt");
    rename("C:\\students\\temp.txt","C:\\students\\mywords.txt");
}
void updateword()
{
    fstream rd,wr;
    rd.open("C:\\students\\mywords.txt",ios::in);
    wr.open("C:\\students\\temp.txt",ios::out);
    char s[50];
    cout<<endl<<"Enter Word";
    cin>>s;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    int nwords=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for(int i=1;i<=nwords;i++)
    {
        rd.read((char *)&obj,sizeof(obj));
        if(strcmp(obj.word,s)==0)
        {
            obj.accept();
        }
        wr.write((char *)&obj,sizeof(obj));

    }
    rd.close();
    wr.close();
    remove("C:\\students\\mywords.txt");
    rename("C:\\students\\temp.txt","C:\\students\\mywords.txt");
}
main()
{
    int e=0,choice;
    cout<<endl<<"************************************************************************************************************************************************";
    cout<<endl<<"\t\t\t\t\t\tWELCOME TO MY DICTIONARY \t\t\t\t\t\t";
    cout<<endl<<"************************************************************************************************************************************************";

    while(e!=1)
    {
        cout<<endl<<"Enter 1 to Add Word";
        cout<<endl<<"Enter 2 to Read Word";
        cout<<endl<<"Enter 3 to Search Word";
        cout<<endl<<"Enter 4 to Delete Word";
        cout<<endl<<"Enter 5 to Update Word";
        cout<<endl<<"Enter 6 to Exit";
        cout<<endl<<"Enter Your Choice";
        cin>>choice;
        switch(choice)
        {
          case 1:
             {
                addword();
                break;
             }
          case 2:
            {
                readwords();
                break;
            }
          case 3:
            {
                search();
                break;
            }
          case 4:
            {
               removeword();
               break;

            }
          case 5:
            {
                updateword();
                break;
            }
          case 6:
            {
                e=1;
                break;
            }

        }
    }


}




