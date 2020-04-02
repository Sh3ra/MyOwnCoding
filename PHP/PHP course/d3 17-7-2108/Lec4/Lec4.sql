
update employees set salary = 25000 where employee_id=100;

select * from employees;

select employee_id , last_name , salary from employees;


select employee_id , last_name , salary 
from employees
where employee_id=100;

/*
comparison operators
----------------------
= 
>
<
>=
<=
!= <>
is null
is not null
between x and y
not between x and y
in (x, y , z ,...) 
not in (x, y , z) 
like % ( 0 or more) _ (one char)
not like
*/


select employee_id , last_name , salary 
from employees
where salary >5000;

select employee_id , last_name , salary 
from employees
where salary >5000
order by salary ;


select employee_id , last_name , salary 
from employees
where salary >5000
order by salary desc;

select employee_id , last_name , salary 
from employees
where salary <=6000
order by salary desc;

select employee_id , last_name , salary 
from employees
where salary !=10000
order by salary desc;


select * from employees where commission_pct is null;

select * from employees where commission_pct is not null;

select * from employees 
where salary between 10000 and 14000
order by salary;

select * from employees 
where salary not between 10000 and 14000
order by salary

select * from employees 
where salary in (10000,8000,6000,5800)
order by salary;


select * from employees 
where job_id in ('it_prog','sa_man');


select * from employees 
where job_id in ('it_prog','sa_man')
order by manager_id asc;

select * from employees 
where job_id not in ('it_prog','sa_man')
order by manager_id asc



SELECT * FROM `employees` 
where hire_date 
BETWEEN '2004-01-01' and '2006-01-01' 
order by hire_date;


SELECT * FROM `employees` 
where hire_date < '2006-06-15';

select * from employees
where last_name = 'king';

select * from employees
where last_name like 'king';


select * from employees
where last_name like 'k%';

select * from employees
where last_name like '%e';


select * from employees
where last_name like '%ng%';

select * from employees
where last_name like '_e_';


select * from employees
order by department_id;


select * from employees
order by department_id , salary ;

select * from employees
order by department_id , salary  desc;

select * from employees
order by department_id desc, salary  desc


select employee_id , last_name , salary 
from employees
order by 2;

select employee_id , last_name , salary 
from employees
order by 3  desc;

select * from employees
order by 1;

select last_name , salary * 12 ann_sal from employees
order by ann_sal;

select last_name , salary * 12 ann_sal from employees
order by department_id;

-----------------------------------------------------------
-- logical operators 
-----------------

/*
and 
or 
not
*/
select * from employees where job_id='it_prog' and salary >8000;

select * from employees where job_id='it_prog' or salary >8000;

-----------------------------------------------------------

select department_id from employees;

select DISTINCT department_id from employees;

select DISTINCT job_id ,  department_id from employees;

-------------------------------------------------


create table emps 
as 
select * from employees;


desc emps;

select * from emps;


create table new_emps
as
select employee_id , concat(first_name , ' ' ,last_name) full_name , salary , department_id
from employees
where department_id in (50,60,90) 
order by employee_id desc;



select * from new_emps;


create table depts like departments;


insert into depts(department_id , department_name)
select department_id, department_name from departments;




select * from emps;

delete FROM `emps` ;

delete  FROM `new_emps` WHERE employee_id >=190;


truncate table `new_emps` ;
---------------------------------------

-- insert update delete (dml)
-- truncate (ddl)  reset auto_increment   -- commit
---------------------------------------------------


drop table new_emps;
drop table emps;
drop table depts;

------------------------------------------------

select employee_id , last_name , salary , department_id  , case department_id 
															when 50 then 1000
															when 80 then 800
															when 60 then 600
															else 500
															end bonus
from employees;



select employee_id , last_name , salary , department_id  , case department_id 
															when 50 then salary +1000
															when 80 then salary +800
															when 60 then salary +600
															else salary+500
															end sal_after_bonus
from employees;


select employee_id , last_name , salary , department_id  , case department_id 
															when 50 then salary +1000
															when 80 then salary +800
															when 60 then salary +600														
															end sal_after_bonus
from employees;


select employee_id , last_name , salary , department_id  , case  
															when department_id<50 then 1000
															when department_id between 50 and 80 then 800
															when department_id  in (90,100) then 1200
															else 500													
															end sal_after_bonus
from employees;
























