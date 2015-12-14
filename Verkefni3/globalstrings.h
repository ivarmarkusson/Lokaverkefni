#ifndef GLOBALSTRINGS
#define GLOBALSTRINGS
#include <QString>

//GLOBAL QSTRING VARIABLES

//SORT SCIENTISTS
QString SCI_ORDER_BY_NAME_ASC = "SELECT * FROM Persons Order By Name ASC";
QString SCI_ORDER_BY_NAME_DESC = "SELECT * FROM Persons ORDER BY Name DESC";
QString SCI_ORDER_BY_GENDER_ASC = "SELECT * FROM Persons ORDER BY Gender ASC, Name ASC";
QString SCI_ORDER_BY_GENDER_DESC = "SELECT * FROM Persons ORDER BY Gender DESC, Name ASC";
QString SCI_ORDER_BY_BIRTH_ASC = "SELECT * FROM Persons ORDER BY Birth ASC";
QString SCI_ORDER_BY_BIRTH_DESC = "SELECT * FROM Persons ORDER BY Birth DESC";
QString SCI_ORDER_BY_DEATH_ASC = "SELECT * FROM Persons ORDER BY Death ASC";
QString SCI_ORDER_BY_DEATH_DESC = "SELECT * FROM Persons ORDER BY Death DESC";

//SORT COMPUTERS
QString COM_ORDER_BY_NAME_ASC = "Select * FROM Computers Order By Name ASC";
QString COM_ORDER_BY_NAME_DESC = "SELECT * FROM Computers ORDER BY Name DESC";
QString COM_ORDER_BY_TYPE_ASC = "SELECT * FROM Computers ORDER BY Type ASC";
QString COM_ORDER_BY_TYPE_DESC = "SELECT * FROM Computers ORDER BY Type DESC";
QString COM_ORDER_BY_YEAR_ASC = "SELECT * FROM Computers ORDER BY Year ASC";
QString COM_ORDER_BY_YEAR_DESC = "SELECT * FROM Computers ORDER BY Year DESC";
QString COM_ORDER_BY_BUILT_ASC = "SELECT * FROM Computers ORDER BY Built ASC, Name ASC";
QString COM_ORDER_BY_BUILT_DESC = "SELECT * FROM Computers ORDER BY Built DESC, Name ASC";

//SEARCH SCIENTISTS
QString SEARCH_SCIENTIST = "SELECT * FROM Persons WHERE "
                           "(Name LIKE '%'||:Name||'%') "
                           "OR (Birth LIKE '%'||:Birth||'%') "
                           "OR (Death LIKE '%'||:Death||'%') "
                           "OR (Gender LIKE '%'||:Gender||'%')";

//SEARCH COMPUTERS
QString SEARCH_COMPUTER = "SELECT * FROM Computers WHERE "
                          "(Name LIKE '%'||:Name||'%') "
                          "OR (Year LIKE '%'||:Year||'%') "
                          "OR (Type LIKE '%'||:Type||'%') "
                          "OR (Built LIKE '%'||:Built||'%')";

//ADD SCIENTIST
QString INSERT_PERSON = "INSERT INTO persons (Name, Birth, Death, Gender, Hide) "
                        "VALUES (:Name, :Birth, :Death, :Gender, :Hide)";


//ADD COMPUTER
QString INSERT_COMPUTER = "INSERT INTO Computers (Name, Year, Type, Built, Hide) "
                          "VALUES (:Name, :Year, :Type, :Built, :Hide)";

//PRINT CONNECTION
QString PRINT_CONNECTION = "SELECT persons.Name as pName, ComPutErs.Name FROM Persons "
                           "INNER JOIN tengitafla ON persons.ID = tengitafla.ID INNER "
                           "JOIN Computers ON computers.ID = tengitafla.ID";

//ADD CONNECTION
QString ADD_CONNECTION = "INSERT INTO tengitafla (computers_id, persons_id) "
                         "VALUES (:c_tempId, :s_tempId)";

QString SORT_CONNECTIONS = "SELECT persons.Name as pName, ComPutErs.Name FROM Persons "
                           "INNER JOIN tengitafla ON persons.ID = tengitafla.ID INNER "
                           "JOIN Computers ON computers.ID = tengitafla.ID";

#endif // GLOBALSTRINGS
