 create database d3;
 
 use d3
 
 select database();
 
 
create table emps (id int , name varchar(100) );

mysql> desc emps ;
+-------+--------------+------+-----+---------+-------+
| Field | Type         | Null | Key | Default | Extra |
+-------+--------------+------+-----+---------+-------+
| id    | int(11)      | YES  |     | NULL    |       |
| name  | varchar(100) | YES  |     | NULL    |       |
+-------+--------------+------+-----+---------+-------+
2 rows in set (0.03 sec)

mysql> select * from emps;
Empty set (0.00 sec)

mysql>