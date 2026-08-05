#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
struct FileInfo
{
    char filename[50];
};
//Create File
void CreateFile(FileInfo *f)
{
    ofstream file(f->filename);
    if(file)
    {
        cout<<"\nFile Created Successfully. \n";
        file.close();
    }
    else
    {
        cout<<"\nError Creating File. \n";
    }
}
//Write File
void writeFile(FileInfo *f)
{
    ofstream file(f->filename);
    if(!file)
    {
        cout<<"\nError Opening File. \n";
        return;
    }
    cin.ignore();
    char data[500];
    cout<<"\nEnter Data: \n";
    cin.getline(data,500);
    file<<data;
    file.close();
    cout<<"\nData Written Successfully. \n";
}
//Read File
void readFile(FileInfo *f)
{
    ifstream file(f->filename);
    if(!file)
    {
        cout<<"\nFile Not Found. \n";
        return;
    }
    char data[500];
    cout<<"\n-------File Content-------\n";
    while(file.getline(data,500))
    {
        cout<<data<<endl;
    }
    file.close();
}
//Append File
void appendFile(FileInfo *f)
{
    ofstream 
    file(f->filename,ios::app);
    if(!file)
    {
        cout<<"\nError Opening File. \n";
        return;
    }
    cin.ignore();
    char data[500];
    cout<<"\nEnter Data Append: \n";
    cin.getline(data,500);
    file<<endl<<data;
    file.close();
    cout<<"\nData Appended Successfully. \n";
}
//Delete File
void deleteFile(FileInfo *f)
{
    if(remove(f->filename)==0)
    {
        cout<<"\nFile Delete Successfully. \n";
    }
    else
    {
        cout<<"\nFile Not Found. \n";
    }
}
int main()
{
    FileInfo file;
    cout<<"Enter File Name (Example: student.txt): ";
    cin>>file.filename;
    int choice;
    do
    {
        cout<<"\n=======FILE SYSTEM SIMULATION=======\n";
        cout<<" 1. Create File\n";
        cout<<" 2. Write File\n";
        cout<<" 3. Read File\n";
        cout<<" 4. Append File\n";
        cout<<" 5. Delete File\n";
        cout<<" 6. Exit\n";
        cout<<"\nEnter Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            CreateFile(&file);
            break;
            case 2:
            writeFile(&file);
            break;
            case 3:
            readFile(&file);
            break;
            case 4:
            appendFile(&file);
            break;
            case 5:
            deleteFile(&file);
            break;
            case 6:
            cout<<"\nThank You ! \n";
            break;
            default:
            cout<<"\nInvalid Choice. \n";
        }
    }while(choice!=6);
    return 0;
    
}