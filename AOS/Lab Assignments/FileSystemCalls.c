#include<stdio.h>
#include<sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include<stdbool.h>


//function declartion
void create(char *fName);
int openFile(char *fName);
int closeFile(int fd);
void readFile(char *fName);
void writeFile(char *fName);
void jump(char *fName);
bool isExists(char *fName);

void main(){
    int choice;
    char fName[100];
    do
    {
        printf("\n1. Create new file\n");
        printf("2. Open file\n");
        printf("3. Write to file\n");
        printf("4. Read from file\n");
        printf("5. Jump to any location in file\n");
        printf("6. exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        if(choice==1){
            printf("\nEnter file name:\n");
            scanf("%s",fName);
            create(fName); 
        }
        else if(choice==2){
            printf("\nEnter file name:\n");
            scanf("%s",fName);
            int fd = openFile(fName); 

            int ch;
            do{
                printf("\n1. Write to file\n");
                printf("2. Read from file\n");
                printf("3. Jump to any location in file\n");
                printf("4. Close file\n");  
                printf("Enter your choice:");
                scanf("%d",&ch);

                switch (ch)
                {
                    case  1:
                        writeFile(fName); 
                        break;        
                    case  2: 
                        readFile(fName); 
                        break;
                    case  3:
                        jump(fName); 
                        break;   		      		   		              
                    case  4:
                        fd = closeFile(fd);
                        break;
                    default: printf("Wrong Choice. Enter again\n");
                        break;
                }
            }while(ch!=4);
        }
        
        else if(choice==3){
            printf("\nEnter file name:\n");
            scanf("%s",fName);
            writeFile(fName); 
        }

        else if(choice==4){ 
            printf("\nEnter file name:\n");
            scanf("%s",fName);
            readFile(fName); 
        }

        else if(choice==5){
            printf("\nEnter file name:\n");
            scanf("%s",fName);
            jump(fName); 
        }
        else if(choice==6)
            printf("\nExit");
        else
            printf("Wrong Choice. Enter again\n");

    } while (choice != 6);
}

/*
Purpose:    Function to check if file exits in current directory
Input:      fName : name of file
return:     true if file exists otherwise return false
*/
bool isExists(char *fName){
    int fd;
    if( (fd = open(fName,O_RDONLY) ) == -1)
        return false;
    return true;
}

/*
Purpose:    Function to create a new file of given name. If file already exists then ask the user
            and take decision as per the user's requirement. 
Input:      fName : name of file
Output:     return nothing just create a new file.
*/
void create(char *fName){
    if(isExists(fName)){
        int ch;
    
        //if file already exists then asking for user action
        printf("\n\nFile already exists!! \n Please select following option\n");
        printf("1. Create a new file with new name\n");
        printf("2. Leave as it is \nEnter choice: ");
        scanf("%d",&ch);
        if(ch==1){
            printf("Enter new file name: ");
            char newName[50];
            scanf("%s",newName);
            create(newName);
        }          
    }
    else{
        //create file
        int fd = open(fName,O_CREAT | O_RDONLY | O_WRONLY | O_RDWR);
        printf("File created!!\n");
        close(fd);
    }
}

/*
Purpose:    Function to open the file in read and write mode
Input:      fName : Name of file
return:     fd : File Descriptor
*/
int openFile(char *fName){
    if(isExists(fName) == false){
        char option[1];
        printf("\nFile not Exists!!\n");
        printf("Wants to create file?(Y/N) ");
        scanf("%s",option);
        if(option[0]=='Y' || option[0]=='y'){
            create(fName);
        }   
    }
    int fd = open(fName,O_RDWR);

    return fd;
}

/*
Purpose:    Function to close current open file
Input:      fd : File Descriptor
return:     0 if file colsed
            -1 if not closed
*/
int closeFile(int fd){
    printf("\nFile closed!!\n");
    return close(fd);
}


/*
Purpose:    function to Jumping to any location in a given file acc. to user specs.(position & offset)  
Input:      fName : name of file 
*/
void writeFile(char *fName){
    if(!isExists(fName)){
        char option[1];
        printf("\nFile not Exists!!\n");
        printf("Wants to create file?(Y/N) ");
        scanf("%s",option);
        if(option[0]=='Y' || option[0]=='y'){
            create(fName);
        }
        else
            return;
    }
    char temp;
    scanf("%c",&temp); //to clear buffer
    char data[100];
    printf("Enter data\n\n"); 
    scanf("%[^\n]%*c",data);
    int fd = open(fName, O_RDWR);
    int len = strlen(data);
    write(fd,data,len);
    close(fd);
    printf("\nData Entered Successfully\n");
}

/*
Purpose:    Function to read the content file.
Input:      fName : name of file
Output:     show the content of file
*/
void readFile(char *fName){
    if(!isExists(fName)){
        printf("\nFile not Exists!!\n");
    }
    int sz;
    char c[100];
    int fd = open(fName, O_RDONLY|O_RANDOM);
    sz = read(fd, c, 10);
    c[sz] = '\0'; 
    printf("\nFile content:\n----------------------------------");
    printf("\n%s",c);
    printf("\n----------------------------------\n");
}

/*
Purpose:    function to Jumping to any location in a given file acc. to user specs.(position & offset)  
Input:      fName : name of file
*/
void jump(char *fName){
    if (!isExists(fName)){
            printf("sorry file doesn't exist try again!!!!!\n");
            return;
	}
    int fd = open(fName,O_RDWR);
    int pos, offset;
    printf("Enter the offset\n");
    scanf("%d", &offset);
    printf("Choose any from given 3 positions\n");
    printf("1. SEEK_END (It denotes end of the file)\n");
    printf("2. SEEK_SET (It denotes starting of the file)\n");
    printf("3. SEEK_CUR (It denotes file pointer�s current position)\n");
    int op;
    scanf("%d", &op);
    switch(op){
        case 1:
            pos=SEEK_END;
            break;
        case 2:
            pos=SEEK_SET;
            break;
        case 3:pos=SEEK_CUR;
            break;					   	        	       
    }
    int positon = lseek(fd,offset,pos);
    printf("\nPointer final location according to position & offset specified %ld\n", positon);
    close(fd);
}

