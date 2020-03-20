-- cont.Procedures and functions
--------------------------------

delimiter $
create procedure get_dept_info (in did int ,out count_emps  int )
begin 
	select count(*) 
	into count_emps
	from employees 
	where department_id = did;
end$



call get_dept_info(50 , @emps);
select @emps;




drop procedure get_dept_info;

delimiter $
create procedure get_dept_info (in did int ,out count_emps  int , out sum_sal int )
begin 
	select count(*)  , sum(salary) 
	into count_emps , sum_sal
	from employees 
	where department_id = did;
end$


set @x = 50;
call get_dept_info(@x , @emps_c , @sum_sal);
select @emps_c ,@sum_sal;




drop procedure get_dept_info;

delimiter $
create procedure get_dept_info (inout dept int  )
begin 
	select count(*) 
	into dept
	from employees 
	where department_id = dept;
end$


set @x = 50;
call get_dept_info(@x);
select @x;


--select concat ('(',left('01257385142',3) ,')-' , substr('01257385142',4));




delimiter $
create procedure phone_formate (inout phone varchar(50)  )
begin 
	select concat('('  ,  left(phone, 3) , ')-(' , substr(phone , 4, 4) , ')(' , substr(phone , 8) )
	into phone;	
end$


set @p = '01254789648';
call phone_formate(@p);
select @p;




delimiter $
create function phone_formate_func ( phone varchar(50)  ) returns varchar(50)
begin 
	declare rslt varchar(50);
	select concat('('  ,  left(phone, 3) , ')-(' , substr(phone , 4, 4) , ')(' , substr(phone , 8) )
	into rslt;
	return rslt ;	
end$



select phone_formate_func('01254789648');

select phone_number , phone_formate_func(phone_number) from employees;

--------------------------------------------------------


-- triggers
--------------


create table audit_emps 
(
	id int auto_increment primary key , 
    emp_id int , 
    old_sal decimal(10,2) ,
    new_sal decimal(10,2) ,
    old_dept int , 
    new_dept int , 
    user_name varchar(100) , 
    created_at timestamp default current_timestamp
);




DELIMITER $$
CREATE TRIGGER emp_trigger 
    after insert           
	ON employees
    FOR EACH ROW 
BEGIN
   insert into audit_emps (emp_id  , new_sal, new_dept,user_name) 
   values(   new.employee_id  ,new.salary , new.department_id , user());
END$$
DELIMITER ;


INSERT INTO `employees` (`employee_id`, `first_name`, `last_name`, `email`, `phone_number`, `hire_date`, `job_id`, `salary`, `commission_pct`, `manager_id`, `department_id`) 
VALUES ('500', 'aaa', 'vvvv', 'sssss@sss', NULL, '2018-08-14', 'AD_PRES', '5000', NULL, '100', '10')


INSERT INTO `employees` (`employee_id`, `first_name`, `last_name`, `email`, `phone_number`, `hire_date`, `job_id`, `salary`, `commission_pct`, `manager_id`, `department_id`) 
VALUES ('550', 'aaa', 'vvvv', 'a44@sss', NULL, '2018-08-14', 'AD_PRES', '6000', NULL, '100', '20'),
('560', 'aaa', 'vvvv', 'ddsss@sss', NULL, '2018-08-14', 'AD_PRES', '7000', NULL, '100', '30');





DELIMITER $$
CREATE TRIGGER emp_update_trigger 
    after update           
	ON employees
    FOR EACH ROW 
BEGIN
   insert into audit_emps (emp_id  , old_sal , new_sal, old_dept , new_dept,user_name) 
   values(   new.employee_id  ,old.salary,new.salary ,old.department_id, new.department_id , user());
END$$
DELIMITER ;

update employees set salary = 9000 , department_id = 50
where employee_id = 500;

DELIMITER $$
CREATE TRIGGER emp_delet_trigger 
    after delete           
	ON employees
    FOR EACH ROW 
BEGIN
   insert into audit_emps (emp_id  , old_sal , new_sal, old_dept , new_dept,user_name) 
   values(   old.employee_id  ,old.salary,null ,old.department_id, null , user());
END$$
DELIMITER ;

delete from employees where employee_id >=500;
-------------------------------------------
create table dept_info 
as select department_id , department_name 
from departments;

alter table dept_info
add count_emps int ;

select * from dept_info;

update dept_info d set count_emps = (select count(*) from employees where department_id = d.department_id);


DELIMITER $$
CREATE TRIGGER emp_delet_trigger2 
    after delete           
	ON employees
    FOR EACH ROW 
BEGIN
  update dept_info set count_emps = count_emps -1 
  where department_id = old.department_id;
END$$
DELIMITER ;




DELIMITER $$
CREATE TRIGGER emp_delet_trigger_e1 
    after delete           
	ON e1
    FOR EACH ROW 
BEGIN
  update dept_info set count_emps = count_emps -1 
  where department_id = old.department_id;
END$$
DELIMITER ;


delete from e1 where department_id=50;


----------------------------------
-- events 
--------
-- root 

SET GLOBAL event_scheduler="ON";


-- one time == at

CREATE EVENT IF NOT EXISTS event2
ON SCHEDULE AT CURRENT_TIMESTAMP
DO
  delete from emps;
  
  
CREATE EVENT IF NOT EXISTS event2
ON SCHEDULE AT CURRENT_TIMESTAMP
ON COMPLETION PRESERVE
DO
  delete from emps;


CREATE EVENT event3
ON SCHEDULE EVERY 10 second
STARTS CURRENT_TIMESTAMP + INTERVAL 30 second
ENDS CURRENT_TIMESTAMP + INTERVAL 1 HOUR
DO
   update employees set salary = salary +100;























