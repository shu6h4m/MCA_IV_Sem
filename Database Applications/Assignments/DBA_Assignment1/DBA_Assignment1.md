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

![Snap1.png](attachment:Snap1.png)

![Snap2.png](attachment:Snap2.png)
