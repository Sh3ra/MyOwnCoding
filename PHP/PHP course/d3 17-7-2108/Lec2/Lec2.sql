create DATABASE if not EXISTS d3;

use d3;

drop schema if EXISTS lec1;



mysql> show create database d3;
+----------+---------------------------------------------------------------+
| Database | Create Database                                               |
+----------+---------------------------------------------------------------+
| d3       | CREATE DATABASE `d3` /*!40100 DEFAULT CHARACTER SET latin1 */ |
+----------+---------------------------------------------------------------+
1 row in set (0.00 sec)

mysql> show create table courses;
+---------+---------------------------------------
--------------------------------------------------
-----------------------------------+
| Table   | Create Table

                                   |
+---------+---------------------------------------
--------------------------------------------------
-----------------------------------+
| courses | CREATE TABLE `courses` (
  `course_no` int(11) DEFAULT NULL,
  `course_title` varchar(200) DEFAULT NULL,
  `no_of_hours` int(11) DEFAULT '40',
  `hour_price` decimal(7,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 |
+---------+---------------------------------------
--------------------------------------------------
-----------------------------------+
1 row in set (0.00 sec)

----------------------------------------------------------------


create database test charset='utf8';


mysql> show create database test;
+----------+---------------------------------------------------------------+
| Database | Create Database                                               |
+----------+---------------------------------------------------------------+
| test     | CREATE DATABASE `test` /*!40100 DEFAULT CHARACTER SET utf8 */ |
+----------+---------------------------------------------------------------+
1 row in set (0.00 sec)




create DATABASE test2 COLLATE='utf8_general_ci';



alter database d3 charset='utf8';


alter schema d3 COLLATE='utf8_bin';

------------------------------------
-- from my.ini change default storage engine from myisam to innodb
--default-storage-engine=innodb


use test;

create table test
(
	id int ,name varchar(50)
)engine='myisam';


mysql> show create table test;
+-------+----------------------------------
--------------------------------+
| Table | Create Table
                                |
+-------+----------------------------------
--------------------------------+
| test  | CREATE TABLE `test` (
  `id` int(11) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8 |
+-------+----------------------------------
--------------------------------+
1 row in set (0.00 sec)


alter table test engine='innodb';
-------------------------------------------------

insert into labs (location ,lab_type) VALUES(null , null);




drop table courses;


create table courses 
(
	course_no int PRIMARY key  , 
	course_title varchar(200) not null , 
	no_of_hours int not null default 40 , 
	hour_price decimal(7,2) not null 
	
);


insert into courses value (1000,'PHP',80,100) ;


/*
insert into courses value (1000,'PHP',80,100)
MySQL said: Documentation

#1062 - Duplicate entry '1000' for key 'PRIMARY'
*/



insert into courses value (null,'PHP',80,100);
/*
MySQL said: Documentation

#1048 - Column 'course_no' cannot be null
*/



insert into courses(course_no,hour_price) value (1010,100) ;
/*
insert into courses(course_no,hour_price) value (1010,100)
MySQL said: Documentation

#1364 - Field 'course_title' doesn't have a default value
*/


create table employees 
(
	id int primary key auto_increment , 
	name varchar(200) not null, 
	email varchar(255) unique , 
	mobile char(15) unique not null,
	salary decimal(10,2) default 5000,
	job 	varchar(255) 
);

desc employees;


insert into employees (name , mobile) values ('ahmed','054508080'),('sara','055608080');




select * from employees;


insert into employees (name , mobile) values ('dina','054508080');

/*insert into employees (name , mobile) values ('dina','054508080')
MySQL said: Documentation

#1062 - Duplicate entry '054508080' for key 'mobile'
*/


insert into employees (name , mobile) values ('dina','0344508080');

insert into employees (name , mobile) values ('dina',null)
/*
insert into employees (name , mobile) values ('dina',null)
MySQL said: Documentation

#1048 - Column 'mobile' cannot be null
*/


delete from labs where lab_no is null;


alter table labs
add primary key (lab_no);


alter table labs
drop primary key ;


alter table employees 
add dept_id int ;

desc employees;


alter table employees 
add dept_id int ;


alter table employees 
MODIFY  dept_id bigint ;

alter table employees 
change  dept_id did int ;

alter table employees 
drop  COLUMN did ;

create table depts 
(
	dept_id int primary key auto_increment, 
	dept_name varchar(200) not null
);


insert into depts(dept_name) values ('sales') , ('hr');


alter table employees
add did int ;


update employees set did = 1;


update employees set did = 2 where name='sara';


update employees set did = 100 where name='sara';


update employees set did = 2 where name='sara';





alter table employees
add foreign key (did) references depts(dept_id);



update employees set did = 100 where name='sara';


/*
update employees set did = 100 where name='sara'
MySQL said: Documentation

#1452 - Cannot add or update a child row: a foreign key constraint 
fails (`d3`.`employees`, CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`did`) REFERENCES `depts` (`dept_id`))
*/


 show create table employees;
 
 /*
 | employees | CREATE TABLE `employees` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) COLLATE utf8_bin NOT NULL,
  `email` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `mobile` char(15) COLLATE utf8_bin NOT NULL,
  `salary` decimal(10,2) DEFAULT '5000.00',
  `job` varchar(255) COLLATE utf8_bin DEFAULT NULL,
  `did` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `mobile` (`mobile`),
  UNIQUE KEY `email` (`email`),
  KEY `did` (`did`),
  CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`did`) REFERENCES `depts` (`dept_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COLLATE=utf8_bin |
 */


 
 alter table employees
 drop foreign key employees_ibfk_1;
 
 
 
 
 
 
alter table employees
add constraint fk_did_emps foreign key (did) references depts(dept_id);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
