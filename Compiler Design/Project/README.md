## Report : Parser Project Using Lex and Yacc

### 1. Syntax >>


          DELETE FROM table_name WHERE condition;
              
  for example,
  
          DELETE FROM Parties WHERE PartyName='BJP';
          

### 2. Assumption >>


         No other keywords other those used in program.
         
              
  Capabilities :
  
        can parse delete queries
        can use both and & or in where clause
        can use <,>,<=,>=,== operations in where clause
        can parse delete statements without where as well 
          
  Limitations :
  
        can not use <=,>=
        can not parse compound sql  
        cannot use conditions, like , in , between etc
        can only use and and or in where.
        
        
 ### 3. Test Cases >>
        DeleTe fRoM h wHere ff=g or fg<o
        Syntax Correct
        
        DeleTe fRoM h where
        error: syntax error
        
        delete from h
        Syntax Correct

### 4. Output >>
![Project Output](https://user-images.githubusercontent.com/37971771/158452587-7c6e49d4-50b7-44b3-a420-fdb87265140f.png)

<hr>


<div align="center">
  << Submitted To >> <br><br>
          Dr. Ankit Rajpal<br>
          Dept. Of Computer Science
</div>
