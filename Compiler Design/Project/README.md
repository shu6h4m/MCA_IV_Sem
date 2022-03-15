## Report : Parser Project Using Lex and Yacc

### 1. Syntax >>


          DELETE FROM table_name WHERE condition;
              
  for example,
  
          DELETE FROM Parties WHERE PartyName='BJP';
          
Note: Be careful when deleting records in a table!
Notice the WHERE clause in the DELETE statement.The WHERE clause specifies which record(s) should be deleted. If you omit the WHERE clause, all records in the table will be deleted!

### 2. Assumption >>


         Same as standard SQL
         
              
  Capabilities :
  
        can parse delete queries
        can use both and & or in where clause
        can use <,>,= operations in where clause
        can parse delete statements without where as well 
          
  Limitations :
  
        can not use <=,>=
        can not parse compound sql  
        
        
        
 ### 3. Test Cases >>
        DeleTe fRoM h wHere ff=g or fg<o
        Syntax Correct
        
        DeleTe fRoM h where
        error: syntax error
        
        delete from h
        Syntax Correct

### 4. Output >>
![Project Output](https://user-images.githubusercontent.com/37971771/158448897-0731ce8e-02f1-47fd-8f6c-207d159d312b.png)
