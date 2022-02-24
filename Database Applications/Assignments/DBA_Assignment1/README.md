**Assignment 1  : Install Required Softwares for Postgres and share screenshot.** <br><br>
*Submitted by : Subham Sharma* <br>
*Roll Number  : 58*   


```python
# 1.Downloaded and installed PostGresSQL
# 2.Using Jupyter notebook 
# 3.Required libraries :

import psycopg2
import pandas as pd
import pandas.io.sql as sqlio
```


```python
# Setting up connection with NorthWind Database

conn = psycopg2.connect(user="postgres", password="2580", host="localhost", database="NorthWind")
```
<br>

# Screenshots :

![Snap1.png](https://github.com/shu6h4m/MCA_IV_Sem/blob/main/Database%20Applications/Assignments/DBA_Assignment1/Snap1.png)

![Snap2.png](https://github.com/shu6h4m/MCA_IV_Sem/blob/main/Database%20Applications/Assignments/DBA_Assignment1/Snap2.png)
