import sqlite3

from sqlite3 import Error

def Connection():
    try:
        connect = sqlite3.connect("Student.db")
        return connect
    except Error:
        print("failed to create or read db file")

def CreateTable(connect):
    Obj = connect.cursor()
    Obj.execute("CREATE TABLE StudentDetails(Id n(3),Name char(10),Course char(3));")
    print("Table is Created")
def InsertData(connect):
    Obj = connect.cursor()
    Obj.executescript("""
    INSERT INTO StudentDetails VALUES (101,'Sam','AI');
    INSERT INTO StudentDetails VALUES(102,'Amy','ML');
    INSERT INTO StudentDetails VALUES(103,'Ravi','C++');
    INSERT INTO StudentDetails VALUES(104,'Feng','AI');
    INSERT INTO StudentDetails VALUES(105,'John','C');
    """)
    print("inserted records to the table")
def ReadData(connect):
    Obj = connect.cursor()
    Obj.execute("SELECT * FROM StudentDetails;")
    data = Obj.fetchall()
    print("records in table are")
    for i in data:
        print(i)
    print()
def UpdateData(connect):
    Obj = connect.cursor()
    Obj.execute("UPDATE StudentDetails SET Name = 'Ram' WHERE Id = 103;")
    print("Upated data")
    ReadData(connect)

def DeleteData(connect):
    Obj = connect.cursor()
    Obj.execute("DELETE FROM StudentDetails WHERE Course = 'C++';")
    print("Record Deteled")
    ReadData(connect)

sqlCon = Connection()
CreateTable(sqlCon)
InsertData(sqlCon)
ReadData(sqlCon)
UpdateData(sqlCon)
DeleteData(sqlCon)