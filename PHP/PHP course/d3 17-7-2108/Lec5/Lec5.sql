--SQL Functions
---------------

--Single-row functions
/*
String 
number 
date time 
information
*/

--Multiple-row functions (group functions)


----------------------------------------
-- String functions
-------------------

select concat('ahmed' , '-','ali');

select concat('ahmed' , '-','ali') from dual;

select concat(first_name , last_name) from employees ;


select length('ahmed'); -- 5 bytes
select length('أحمد'); --8 bytes


select char_length('أحمد'); -- 4 char

select left('New Horizons' ,3); -- New

select right('New Horizons' ,3); -- ons

select substr('New Horizons' ,5,3); -- Hor
select substr('New Horizons' ,5);   --Horizons


select left(first_name , 3 ) , right(last_name, 3) from employees;

select concat(left(first_name , 3 ) , right(last_name, 3)) password from employees;


select upper('hello') ,lower('HEllo');

select concat(upper(left(first_name , 3 )) ,'@', lower(right(last_name, 3))) password from employees;

select instr('aaa@bb.com' , '@'); --4 
select instr('aaa@bb.com' , 'x'); --0 


select trim('     hello iam doaa      ') rslt;

select rtrim('     hello iam doaa      ') rslt ,  ltrim('     hello iam doaa      ') rsl2;


select lpad('hello' , 10,'x') rslt , rpad('hello' , 10,'x') rslt2
select last_name , lpad(salary,10, 0) sal from employees;
select concat(rpad(first_name,15,' ') ,space(5), last_name)rstl from employees;



--Numeric Functions 
--------------------

select abs(-10) rslt; -- 10
select pow(10,3) rslt ; --1000

select mod(10,3) rslt ; -- 1

select mod(10,2) rslt; -- 0


select round(15.1258 , 2) ; -- 15.13
select round(15.1258 , 0) ; -- 15

select truncate(15.1258 , 2) ; -- 15.12
select truncate(15.1258 , 0) ; -- 15



select round(189.99 , -1) ; -- 190
select truncate(189.99 , -1) ; -- 180

select truncate(8189.99 , -3) ; #8000


--Date and Time Functions 
--------------------------
select now() , current_timestamp() ; 

select  current_timestamp ; 
-- 2018-07-26 17:39:59

select  current_time() , current_date() ; 


select  date('2018-07-26 17:39:59') , time('2018-07-26 17:39:59') ;

select  last_name , year(hire_date) , month(hire_date) , day(hire_date) from employees;


select  hour(now()) ;

select  date_format(now() , '%a %d - %M - %Y %r') now;

select extract(year from now()) , year(now());


SELECT DATE_ADD('2008-01-02', INTERVAL 2 Month);


SELECT DATEDIFF('2007-12-31 23:59:59','2007-11-25'); -- 36 day


SELECT DATE_SUB(now(),  INTERVAL '1 1:1:1' DAY_SECOND);


SELECT DATE_SUB(now(),  INTERVAL '1' Month);

-- https://dev.mysql.com/doc/refman/5.7/en/date-and-time-functions.html#function_datediff

------------------------------------------------------
select last_name , salary , commission_pct , salary + salary * commission_pct sal_after_com  from employees;

select last_name , salary , commission_pct , salary + salary * ifnull(commission_pct , 0)  sal_after_com  from employees;

------------------------------------------------------

--Information Functions 
-------------------------

select DATABASE() , user();

select charset('أحمد');

select collation('أحمد');

select version();

update emps set salary = 5500;
set @c =  row_count();
select @c;


update emps set salary =1500 where employee_id=110;
set @c =  row_count();
select @c;


use d3;
insert into depts (dept_name) value('aaa');
select last_insert_id();

------------------------------------
-- Group Functions
-----------------------
--sum max min avg count 

select salary from employees;


select sum(salary) from employees;

select min(salary) , max(salary) , round(avg(salary) ) from employees;

select min(hire_date) , max(hire_date)  from employees;

select count(employee_id) , count(*)  , count(commission_pct)   from employees;



select count(*) from departments;   -- 27
select count(department_id) from employees; --106

select count(distinct department_id) from employees; -- 11

select count(*) from employees where department_id=50;  --45

select last_name , max(salary ) from employees;
-----------------------------------------------



select department_id , min(salary )  , max(salary) , count(*) 
from employees
group by department_id;


select job_id ,sum(salary) , count(*)
from employees
group by job_id;

select department_Id , job_id , count(*)
from employees
group by department_Id, job_id
order by department_id;


select department_Id , job_id , count(*)
from employees
where department_id in (50,80,90)
group by department_Id, job_id
order by department_id;


/*
select department_Id , job_id , count(*)
from employees
where count(*) >5
group by department_Id, job_id
order by department_id;

Error Code: 1111. Invalid use of group function

*/
select department_Id  , count(*)
from employees
group by department_Id
having count(*) >5
order by department_id;



select department_Id  , count(*)
from employees
where department_id <>10
group by department_Id
having count(*) >5
order by department_id;
------------------------------------------

select employee_id , salary from employees where department_id= 30
union
select employee_id , salary from employees where department_id= 40;

select employee_id , job_id from employees 
union 
select employee_id , job_id from job_history
order by 1;
-- 115


select employee_id , job_id from employees 
union all
select employee_id , job_id from job_history
order by 1;

-- 117

select employee_id , job_id  , salary from employees 
union 
select employee_id , job_id ,null from job_history
order by 1;



select employee_id id, job_id  , salary from employees
union 
select employee_id , job_id ,null from job_history
order by 1;

