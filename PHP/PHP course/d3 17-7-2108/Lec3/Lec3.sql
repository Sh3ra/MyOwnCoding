delete from depts where dept_id = 1;

update depts set dept_id = 5 where dept_id=1;
/*
 Cannot delete or update a parent row: a foreign key constraint fails 
 (`d3`.`employees`, CONSTRAINT `fk_did_emps` FOREIGN KEY (`did`) REFERENCES `depts` (`dept_id`))
*/

alter table employees
drop  foreign key fk_did_emps;
 
alter table employees
add constraint fk_did_emps foreign key (did) references depts(dept_id)
on update cascade on delete cascade;

 
alter table employees
add constraint fk_did_emps foreign key (did) references depts(dept_id)
on update set null on delete set null;
--------------------------------------------------------
use hr;

select * from employees;

select  employee_id , last_name , salary from employees;


select  employee_id , last_name , salary , salary *12 as ann_sal from employees;
select  employee_id , last_name , salary , salary *12 ann_sal from employees;
select  employee_id , last_name , salary , salary *12 "ann sal" from employees;


select  employee_id , last_name name , salary , salary *12 "ann sal" from employees;




select  employee_id , concat(first_name,' ', last_name) full_name , salary , salary *12 "ann sal" 
from employees;




















