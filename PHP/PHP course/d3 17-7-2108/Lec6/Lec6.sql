-- Joins
-----------

select first_name , last_name , department_name
from employees join departments
on (employees.department_id = departments.department_id);


select first_name  , last_name , department_name
from employees e join departments d
on (e.department_id = d.department_id);


select city , country_name 
from locations l join countries  c
on(l.country_id = c.country_id);



SELECT region_name , country_name
from regions join countries 
on (countries.region_id = regions.region_Id);


SELECT region_name , country_name
from regions r join countries  c
on (c.region_id = r.region_Id);


select first_name , last_name , e.manager_id ,e.department_id,d.department_id,  department_name , d.manager_id
from employees e join departments d
on (e.department_id = d.department_id);


select first_name , last_name , e.manager_id ,department_id,  department_name , d.manager_id
from employees e join departments d
using (department_id);


select city , country_name 
from locations l , countries  c
where(l.country_id = c.country_id);

---------------------------------------------------------

-- join types
-------------
/*
inner join
outer join ( left - right)
self join
*/

select first_name  , last_name ,e.department_id, department_name
from employees e inner join departments d
on (e.department_id = d.department_id);


select first_name  , last_name ,e.department_id, department_name
from employees e join departments d
on (e.department_id = d.department_id);




select first_name  , last_name ,e.department_id, department_name
from employees e  left outer join departments d
on (e.department_id = d.department_id);

select first_name  , last_name ,e.department_id, department_name
from employees e  left join departments d
on (e.department_id = d.department_id);

select first_name  , last_name ,e.department_id, department_name
from employees e  right join departments d
on (e.department_id = d.department_id);



select first_name  , last_name ,e.department_id, department_name
from employees e left outer join departments d
on (e.department_id = d.department_id)
union
select first_name  , last_name ,e.department_id, department_name
from employees e right outer join departments d
on (e.department_id = d.department_id);


select employee_id , last_name , d.* 
from employees e join departments d
using(department_id);



select employee_id , last_name , d.* 
from departments d right outer join employees e
using(department_id);


select e.first_name emp , m.first_name  mgr
from employees e join employees m
on (e.manager_id = m.employee_id) ;


select e.first_name emp , m.first_name  mgr
from employees e left join employees m
on (e.manager_id = m.employee_id) ;


select last_name , job_id, department_name , city , country_name , region_name
from employees e join jobs j using(job_id)
join departments d using(department_id) join locations l on (l.location_id= d.location_id)
join countries using(country_id) join regions using(region_id) ;



select last_name , job_id, department_name , city , country_name , region_name
from employees e join jobs j using(job_id)
left outer join departments d using(department_id) left outer  join locations l on (l.location_id= d.location_id)
left outer  join countries using(country_id) left outer  join regions using(region_id) ;


select  department_name , concat(first_name , ' ', last_name) mgr_name  ,city 
from departments  , employees , locations


select  department_name , concat(first_name , ' ', last_name) mgr_name  ,city 
from departments d  join  employees e
on(d.manager_id = e.employee_id)
join  locations l using(location_id);

select  department_name , concat(first_name , ' ', last_name) mgr_name  ,city 
from departments d  left join  employees e
on(d.manager_id = e.employee_id)
join  locations l using(location_id);


select region_name , country_name 
from regions cross join countries;



create table e1 
as select * from employees;


select  department_name , concat(first_name , ' ', last_name) mgr_name  ,city 
from departments d  left join  employees e
on(d.manager_id = e.employee_id)
join  locations l using(location_id);


-------------------------------------------------
-- subqueries
--------------

select * from employees 
where department_id = (select department_id from employees where first_name = 'Lex');


select * from employees 
where salary >(select avg(salary) from employees)
order by salary ;



select * from employees 
where salary = (select max(salary) from employees);

select * from employees 
where salary = (select min(salary) from employees);



SELECT * FROM hr.employees
where job_id =(select job_id from employees where employee_id=105) 
and salary>(select salary from employees where employee_id=105);

/*
select * from employees 
where department_id = (select department_id from employees where last_name = 'king');


Error Code: 1242. Subquery returns more than 1 row

*/

/*
single row operators 
=
!=
<>
>
<
>=
<=
between x and y 
like 
--------------------------

multiple rows operators
-----------------------
in not in
>all > any 
< all < any

*/

select * from employees 
where department_id in (select department_id from employees where last_name = 'king');



select * from employees 
where salary in (select salary from employees where job_id = 'it_prog');

select * from employees 
where salary >all (select salary from employees where job_id = 'it_prog')
order by salary;



select * from employees 
where salary >any (select salary from employees where job_id = 'it_prog')
order by salary;


select * from employees 
where salary >all (select salary from employees where department_id=60)
order by salary;



SELECT * FROM EMPLOYEES 
WHERE EMPLOYEE_ID IN (SELECT EMPLOYEE_ID FROM job_history);

-- CORELAATED SUPQUARY
----------------------

SELECT * FROM EMPLOYEES E
WHERE exists (SELECT 'X' FROM job_history WHERE employee_id = E.employee_id);



SELECT * FROM DEPARTMENTS D
WHERE 5 < (SELECT COUNT(*) FROM EMPLOYEES WHERE DEPARTMENT_ID = D.DEPARTMENT_ID);


SELECT DEPARTMENT_ID ,DEPARTMENT_NAME , COUNT(EMPLOYEE_ID)
FROM DEPARTMENTS JOIN EMPLOYEES
USING(DEPARTMENT_ID) 
GROUP BY DEPARTMENT_ID,DEPARTMENT_NAME
HAVING COUNT(EMPLOYEE_ID)>5;



SELECT * FROM employees
	WHERE SALARY > (SELECT AVG(SALARY) FROM employees)
    ORDER BY SALARY;

SELECT department_id , avg(salary)  FROM employees
	group by department_id
    ORDER BY SALARY;
	
SELECT * FROM employees e
	WHERE SALARY > (SELECT AVG(SALARY) FROM employees where department_id = e.department_id )
    ORDER BY SALARY;	
---------------------------------------------------------
delete from e1 where employee_id not in (select manager_id from departments) ;
-- 0 row

delete from e1 where employee_id not in (select manager_id from departments where manager_id  is not null) ;
--  done


alter table emps add dname varchar(100);


update emps e set dname = (select department_name from departments where department_id = e.department_id) ;


