#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class Reader
{
    public :
    char name[100];
    int age , id , seat;
};
class Book
{
    public :
    char name[100]; char auther[100];
    int serialnum;
};
void AddReader()
{
    fstream outfile1;
    outfile1.open("Reader.txt" , ios::out | ios::app);
    Reader r; char x;
    do
    {
      cout << "Enter The Reader'S Name: ";
      cin >> r.name; cout << endl;
      cout << "Enter The Reader'S Age: ";
      cin >> r.age; cout << endl;
      cout << "Enter The Reader'S ID: ";
      cin >> r.id; cout << endl;
      cout << "Enter The Reader'S Seat: ";
      cin >> r.seat; cout << endl;
      //File Writing
      outfile1.write((char*)&r , sizeof(r));
      cout << "Enter Any Record Again (Y / N) : ";
      cin >> x; cout << endl;
    }while(x == 'Y');

    outfile1.close();
}
void ReadReader()
{
    ifstream in1; Reader r;
    in1.open("Reader.txt", ios::in);
    if(in1.is_open())
    {
        cout << "Name\tAge\tID\tSeat" << endl;
        in1.read((char*)&r , sizeof(r));
        while(!in1.eof())
        {
            cout << r.name << "\t" << r.age << "\t" << r.id << "\t"<< r.seat << endl;
            in1.read((char*)&r , sizeof(r));
        }
        in1.close();

    }
    else
    {
        cout << "----This File Not Found----" << endl;
    }
}
void SearchReader()
{
    char str[100];
    cout << "Enter The Name Search For : ";
    cin >> str; cout << endl;
    bool found = false;
    ifstream in1; Reader r;
    in1.open("Reader.txt", ios::in);
    if(in1.is_open())
    {
        in1.read((char*)&r , sizeof(r));
        while(!in1.eof())
        {
            if(strcmp(str , r.name) == 0)
            {
              cout << "Name\tAge\tID\tSeat" << endl;
              cout << r.name <<"\t"<<r.age<<"\t"<<r.id<<"\t"<<r.seat<<endl;
              found = true;
            }
            in1.read((char*)&r , sizeof(r));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
}
void UpdateReader()
{
    char str[100];
    cout << "Enter The Name Update For : ";
    cin >> str; cout << endl;
    bool found = false;
    fstream in1; Reader r;
    in1.open("Reader.txt", ios::in | ios::out);
    if(in1.is_open())
    {
        in1.read((char*)&r , sizeof(r));
        while(!in1.eof())
        {
            if(strcmp(str , r.name) == 0)
            {
               cout << "Enter The New Seat For : " << str << endl;
               cin >> r.seat;
               int CurPos = in1.tellg();
               int RedSize = sizeof(r);
               in1.seekp(CurPos - RedSize , ios::beg);
               in1.write((char*) &r , sizeof(r));
               in1.seekg(CurPos - RedSize , ios::beg);
               in1.read((char*) &r , sizeof(r));
               cout << "Name\tAge\tID\tSeat" << endl;
               cout << r.name <<"\t"<<r.age<<"\t"<<r.id<<"\t"<<r.seat<<endl;
               found = true;
               break;
            }
            in1.read((char*)&r , sizeof(r));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
}
void DeleteReader()
{
     char str[100];
     cout << "Enter The Name Delete For : ";
     cin >> str; cout << endl;
     bool found = false;
     Reader r;
     ifstream in1("Reader.txt", ios::in);
     ofstream out1("NewReader.txt" , ios::out | ios::app);
    if(in1.is_open())
    {
        in1.read((char*)&r , sizeof(r));
        while(!in1.eof())
        {
            if(strcmp(str , r.name) != 0)
            {
              out1.write((char*)&r , sizeof(r));
              found = true;
            }
            in1.read((char*)&r , sizeof(r));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
        out1.close();
        remove("Reader.txt");
        rename("NewReader.txt" , "Reader.txt");
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }
  ReadReader();
}
void AddBook()
{
      fstream outfile1;
      outfile1.open("Book.txt" , ios::out | ios::app);
      Book b; char q;
    do
    {
      cout << "Enter The Book Name: ";
      cin >> b.name; cout << endl;
      cout << "Enter The Auther : ";
      cin >> b.auther; cout << endl;
      cout << "Enter The Serial Number: ";
      cin >> b.serialnum; cout<<endl;
      //File Writing
      outfile1.write((char*)&b , sizeof(b));
      cout << "Enter Any Record Again (Y / N) : ";
      cin >> q; cout << endl;
    }while(q == 'Y');

    outfile1.close();
}
void ReadBook()
{
    ifstream in1; Book b;
    in1.open("Book.txt", ios::in);
    if(in1.is_open())
    {
        cout << "Name\tAuther\tSerial Number" << endl;
        in1.read((char*)&b , sizeof(b));
        while(!in1.eof())
        {
            cout << b.name << "\t" << b.auther << "\t"<< b.serialnum<< endl;
            in1.read((char*)&b , sizeof(b));
        }
        in1.close();

    }
    else
    {
        cout << "----This File Not Found----" << endl;
    }
}
void SearchBook()
{
    char str[100];
    cout << "Enter The Name of Book Search For : ";
    cin >> str; cout << endl;
    bool found = false;
    ifstream in1; Book b;
    in1.open("Book.txt", ios::in);
    if(in1.is_open())
    {
        in1.read((char*)&b, sizeof(b));
        while(!in1.eof())
        {
            if(strcmp(str , b.name) == 0)
            {
              cout << "Name\tAuther\tSerial Number" << endl;
              cout << b.name << "\t"<<b.auther<<"\t"<< b.serialnum<<endl;
              found = true;
            }
            in1.read((char*)&b , sizeof(b));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }

}
void UpdateBook()
{
     char str[100];
     cout << "Enter The Name of Book To Update : ";
     cin >> str; cout << endl;
     bool found = false;
    fstream in1; Book b;
    in1.open("Book.txt", ios :: in | ios :: out);
    if(in1.is_open())
    {
        in1.read((char*)&b, sizeof(b));
        while(!in1.eof())
        {
            if(strcmp(str , b.name) == 0)
            {
                cout<< "The New Serial Number Of Book : ";
                cin >> b.serialnum;
                int curpos = in1.tellg();
                int bookSize = sizeof(b);
                in1.seekp(curpos-bookSize , ios::beg);
                in1.write((char*)&b , sizeof(b));
                in1.seekg(curpos-bookSize , ios::beg);
                in1.read((char*)&b , sizeof(b));
                cout << "Name\tAuther\tSerial Number" << endl;
                cout << b.name << "\t"<<b.auther<<"\t"<< b.serialnum<<endl;
                found = true;
                break;
            }
            in1.read((char*)&b , sizeof(b));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }

}
void DeleteBook()
{
    char str[100];
    cout << "Enter The Name of Book To Delete : ";
    cin >> str; cout << endl;
    bool found = false; Book b;
    ifstream in1("Book.txt" , ios :: in);
    ofstream out1("NewBook.txt" , ios :: out);
    if(in1.is_open())
    {
        in1.read((char*)&b, sizeof(b));
        while(!in1.eof())
        {
            if(strcmp(str , b.name) != 0)
            {
              out1.write((char*)&b , sizeof(b));
              found = true;
            }
            in1.read((char*)&b , sizeof(b));
        }
        if(!found)
        {
            cout << "----Name Not Found----" << endl;
        }
        in1.close();
        out1.close();
        remove("Book.txt");
        rename("NewBook.txt" , "Book.txt");
    }
    else
    {
        cout << "----File Not Found----" << endl;
    }

ReadBook();

}
int main()
{
     cout << "\t\t\t\t\t========Library Management System========" << endl;
     cout << "**************Your Choise************" << endl;
     int choise;
      do
     {
         cout << "1.Add Reader\t\t 2.Read Reader\n3.Search Reader\t\t4.Update Reader\n5.Delete Reader\t\t";
         cout << "6.Add Book\n7.Read Book\t\t8.Search Book\n9.Update Book\t\t10.Delete Book" << endl;
         cin >> choise;
         switch(choise)
         {
         case 1:
            AddReader();
            break;
         case 2:
            ReadReader();
            break;
         case 3:
            SearchReader();
            break;
         case 4:
            UpdateReader();
            break;
         case 5:
            DeleteReader();
            break;
         case 6:
            AddBook();
            break;
         case 7:
            ReadBook();
            break;
         case 8:
            SearchBook();
            break;
         case 9:
            UpdateBook();
            break;
         case 10:
            DeleteBook();
            break;
         case 11:
            cout << "==========Thank You=========" << endl;
         }
     }while(choise != 11);




}
