mysql> set autocommit = 1; -- default
Query OK, 0 rows affected (0.00 sec)

mysql> select department_name from depts where department_id =10;
+-----------------+
| department_name |
+-----------------+
| yyyy            |
+-----------------+
1 row in set (0.00 sec)

mysql> update depts set department_name = 'aaaa' where department_id = 10;
Query OK, 1 row affected (0.03 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select department_name from depts where department_id =10;
+-----------------+
| department_name |
+-----------------+
| aaaa            |
+-----------------+
1 row in set (0.00 sec)

mysql> set autocommit = 0;
Query OK, 0 rows affected (0.00 sec)

mysql> update depts set department_name = 'bbbb' where department_id = 10;
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> delete from depts;
Query OK, 25 rows affected (0.00 sec)

mysql> select * from depts;
Empty set (0.00 sec)

mysql> select * from depts;
Empty set (0.00 sec)

mysql> rollback;
Query OK, 0 rows affected (0.04 sec)

mysql> select * from depts;
+---------------+----------------------+------------+-------------+
| department_id | department_name      | manager_id | location_id |
+---------------+----------------------+------------+-------------+
|            10 | aaaa                 |        200 |        1700 |
|            20 | Marketing            |        201 |        1800 |
|            30 | Purchasing           |        114 |        1700 |
|            40 | Human Resources      |        203 |        2400 |
|            50 | Shipping             |        121 |        1500 |
|            60 | IT                   |        103 |        1400 |
|            70 | Public Relations     |        204 |        2700 |
|            80 | Sales                |        145 |        2500 |
|            90 | Executive            |        100 |        1700 |
|           100 | Finance              |        108 |        1700 |
|           110 | Accounting           |        205 |        1700 |
|           120 | Treasury             |       NULL |        1700 |
|           130 | Corporate Tax        |       NULL |        1700 |
|           140 | Control And Credit   |       NULL |        1700 |
|           150 | Shareholder Services |       NULL |        1700 |
|           160 | Benefits             |       NULL |        1700 |
|           170 | Manufacturing        |       NULL |        1700 |
|           180 | Construction         |       NULL |        1700 |
|           190 | Contracting          |       NULL |        1700 |
|           200 | Operations           |       NULL |        1700 |
|           210 | IT Support           |       NULL |        1700 |
|           220 | NOC                  |       NULL |        1700 |
|           230 | IT Helpdesk          |       NULL |        1700 |
|           240 | Government Sales     |       NULL |        1700 |
|           250 | Retail Sales         |       NULL |        1700 |
+---------------+----------------------+------------+-------------+
25 rows in set (0.00 sec)

mysql> update depts set department_name = 'bbbb' where department_id = 10;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> delete from depts where department_id>20;
Query OK, 23 rows affected (0.00 sec)

mysql> select * from depts;
+---------------+-----------------+------------+-------------+
| department_id | department_name | manager_id | location_id |
+---------------+-----------------+------------+-------------+
|            10 | bbbb            |        200 |        1700 |
|            20 | Marketing       |        201 |        1800 |
+---------------+-----------------+------------+-------------+
2 rows in set (0.00 sec)

mysql> commit;
Query OK, 0 rows affected (0.04 sec)

mysql>

--------------------------------------------------
mysql> select * from depts;
+---------------+-----------------+------------+-------------+
| department_id | department_name | manager_id | location_id |
+---------------+-----------------+------------+-------------+
|            10 | bbbb            |        200 |        1700 |
|            20 | Marketing       |        201 |        1800 |
+---------------+-----------------+------------+-------------+
2 rows in set (0.00 sec)

mysql> update depts set location_id = 1900;
Query OK, 2 rows affected (0.04 sec)
Rows matched: 2  Changed: 2  Warnings: 0

mysql> select * from depts;
+---------------+-----------------+------------+-------------+
| department_id | department_name | manager_id | location_id |
+---------------+-----------------+------------+-------------+
|            10 | bbbb            |        200 |        1900 |
|            20 | Marketing       |        201 |        1900 |
+---------------+-----------------+------------+-------------+
2 rows in set (0.00 sec)

mysql> start transaction ;
Query OK, 0 rows affected (0.00 sec)

mysql> update depts set location_id = 1700;
Query OK, 2 rows affected (0.01 sec)
Rows matched: 2  Changed: 2  Warnings: 0

mysql> select * from depts;
+---------------+-----------------+------------+-------------+
| department_id | department_name | manager_id | location_id |
+---------------+-----------------+------------+-------------+
|            10 | bbbb            |        200 |        1700 |
|            20 | Marketing       |        201 |        1700 |
+---------------+-----------------+------------+-------------+
2 rows in set (0.00 sec)

mysql> commit;
Query OK, 0 rows affected (0.04 sec)

mysql> update depts set location_id = 2000;
Query OK, 2 rows affected (0.04 sec)
Rows matched: 2  Changed: 2  Warnings: 0


---------------------------------------------------------

create table test
(
	id int , name varchar(50)
	) engine= myisam;



mysql> use hr
Database changed
mysql> select * from test;
Empty set (0.00 sec)

mysql> insert into test values(1,'aaa'),(2,'xxx');
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * from test;
+------+------+
| id   | name |
+------+------+
|    1 | aaa  |
|    2 | xxx  |
+------+------+
2 rows in set (0.00 sec)

mysql> set autocommit=0;
Query OK, 0 rows affected (0.00 sec)

mysql> insert into test values(31,'aaa'),(32,'xxx');
Query OK, 2 rows affected (0.00 sec)
Records: 2  Duplicates: 0  Warnings: 0
-- from anothr session 
-----------------------
mysql> select * from test;
+------+------+
| id   | name |
+------+------+
|    1 | aaa  |
|    2 | xxx  |
|   31 | aaa  |
|   32 | xxx  |
+------+------+
4 rows in set (0.00 sec)

--------------------------------------------
-- views
------------
create view dept_view 
as
select department_id , department_name , location_id
from departments
where location_id =1700;


desc dept_view;


select * from dept_view;


select department_name  from dept_view
where department_id in (10,20);


insert into dept_view values (455,'aaa',1700);

insert into dept_view values (555,'aaa',1500);




create or replace view dept_view 
as
select department_id , department_name , location_id
from departments
where location_id =1700
with check option;




insert into dept_view values (566,'aaa',1500);
--Error Code: 1369. CHECK OPTION failed 'hr.dept_view'



insert into dept_view values (566,'aaa',1700);


drop view dept_view;

create view emp_data (lname , job , dname , city , country , region)
as
select last_name , job_id, department_name dname , city , country_name , region_name
from employees e join jobs j using(job_id)
left outer join departments d using(department_id) left outer  join locations l on (l.location_id= d.location_id)
left outer  join countries using(country_id) left outer  join regions using(region_id) ;


select * from emp_data;

-----------------------------
-- to drop unique constraint 
--------------------------

alter table e1 
add unique(email) ;

alter table e1 
drop key  email;

alter table e1 
add constraint xxxxx unique(email) ;


alter table e1 
drop key  xxxxx;
----------------------------------------

-- stored procedures and functions
-----------------------------------

delimiter /
create procedure getName (id int)
begin 
	select concat(first_name , ' ' ,last_name ) emp_name from employees 
	where employee_id = id;	
end/


call getName(100);




delimiter $
create procedure add_num (x int , y int)
begin 
	declare z int default 0;
	set z = x+y ;
	select z;
end$


call add_num(10,50);
call add_num(150,560);




delimiter //
create procedure update_sal (id int) 
begin 
	declare sal decimal(10,2) ; 
	declare tax decimal(2,2) ; 
	declare lname varchar(200);
	
	select salary , last_name
	into sal , lname
	from employees where employee_id = id;
	
	if sal < 5000 then 
		set tax = 0;
	elseif sal < 10000 then 
		set tax = 0.1;
	elseif sal < 14000 then 
		set tax = 0.15;
	elseif sal < 17000 then 
		set tax = 0.2;
	else 
		set tax = 0.25;
	end if;
	
	update employees set salary = salary * (1-tax)  where employee_id =id;
	
	select concat ('Hello ' ,  lname  , ' Your tax is = ' , tax) message;

end//


delimiter $
create function add_num_func (x int , y int) returns int
begin 
	declare z int default 0;
	set z = x+y ;
	return z;
end$


select add_num_func(1500,200);

select last_name , add_num_func(salary ,1200) new_sal from employees;