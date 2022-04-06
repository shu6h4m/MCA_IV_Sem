
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <error.h>

using namespace std;

/*
Function : To create file with given name.
Input	 : File name
*/

void create_files(char fileName[]){
	int creat_status=creat(fileName,0666);
	if(creat_status!=-1)
	   cout<<"\nFile created successfully!!\n"<<endl;
	else if(creat_status==-1)
	   cout<<"\nError in creating file\n"<<endl;
}


/*
Function  : To open file 
Input	 :  File Name, mode(in which to open the file)
Returns :   File descriptor
*/

int open_file(char fileName[]){

   printf("Enter mode in which you want to open file.\n");
   printf("0 for Read only \n");
   printf("1 for write only \n");
   printf("2 for both read and write\n");

   int mode;
   cin>>mode;
   int open_code;

   switch(mode){
      case 0:open_code=open(fileName,O_RDONLY);
             break;
      case 1:open_code=open(fileName,O_WRONLY);
             break;
      case 2:open_code=open(fileName,O_RDWR);
             break;
   }
   
   if(open_code==-1)
	   cout<<"\nError in openeing file"<<endl;
	return open_code;

}


/*
Function : To write to the file,asks user to enter content.
Parameter: File name to write to.
*/
void write_to_file(char fileName[]){

   int open_code=open(fileName,O_WRONLY);
   if(open_code==-1) {
      cout<<"\nNo Such File Found !\n"<<endl;
      return;
   }

   cout<<"Enter the data you want to write, Press Tab+Enter when done !"<<endl;
   char buff[1024];
   scanf("%[^\t]s",buff);
 
   int cnt=strlen(buff);
   
   int byteWritten=write(open_code,buff+1,cnt);
   printf("\n %d Bytes of data written",byteWritten);
   printf("\n");
   close(open_code);
}


/*
Function : To read to the file,asks user to enter position and byte offset.
Parameter : File name to read from.
*/

void read_from_file(char fileName[]){

    int open_code=open(fileName,O_RDONLY);
     if(open_code==-1) {
      cout<<"\nCAN'T READ FROM GIVEN FILE"<<endl;
      return;
   }

    cout<<"\nReading Operation : Select Read Position in the file"<<endl;
    cout<<"_____________________________________________________\n"<<endl;
    cout<<"To read from Start :             Press 1"<<endl;
    cout<<"To read from the current :       Press 2"<<endl;
    cout<<"To read from the end of file :   Press 3"<<endl;
    cout<<"_____________________________________________________"<<endl;
    int position;
    cout<<"\nEnter your choice : ";
    cin>>position;
    
    int offset;
    cout<<"Enter offset : ";
    cin>>offset;
    
    int curr_position;
    switch(position){
      case 1:curr_position=lseek(open_code,offset,0);
             break;
      case 2:curr_position=lseek(open_code,offset,1);
             break;
      case 3:curr_position=lseek(open_code,offset,2);
             break;
    }



   char* buff=(char *) calloc(1024, sizeof(char));
   int n;
   int total_char;
   printf("Enter Number of characters you want to Read : ");
   cin>>total_char;

   cout<<"\nRequested Output from selected file :"<<endl;
   cout<<"________________________________________\n"<<endl;
   while((n=read(open_code,buff,1))>=1){
        write(STDOUT_FILENO,buff,1);
        total_char--;
        if(total_char==0) break;
   }
   cout<<endl;

   close(open_code);
   cout<<"________________________________________\n"<<endl;
}


int main(){
   
    cout<<"\nSelect Operation You Want to Perform : "<<endl;
    cout<<"__________________________\n"<<endl;
          
          cout<<"To Create file  : Press 1"<<endl;
          cout<<"To Write file 	: Press 2"<<endl;
          cout<<"To Read file 	: Press 3"<<endl;
          cout<<"To Open file 	: Press 4"<<endl;
    cout<<"__________________________"<<endl;
    string response="y";
    int open_code;

    while(response=="y"){

          printf("\nEnter Your Choice :  ");
          int num;
          scanf("%d",&num);

          while(num<1||num>4){
            printf("Invalid Choice!\nPlease Enter again : ");
            cin>>num;
          }
          
          char fileName[1024];
          printf("Provide a File Name : ");
          scanf("%s",fileName);


          switch(num){
            case 1: create_files(fileName);
                        break;
            case 2: write_to_file(fileName);
                    	break;
            case 3: read_from_file(fileName);
                   	break;
            case 4: open_code=open_file(fileName);
                	close(open_code);
                   	break;
          }
          cout<<"\nWant to Perform another Operation?\nPress ( Y ) if Yes else Press ( N ) : ";
          cin>>response;
    }
    
}
