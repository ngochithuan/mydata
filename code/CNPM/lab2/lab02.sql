create database school
go
use school

create table student(
	maso int IDENTITY(1,1) PRIMARY KEY,
	hoTen nvarchar(50),
	ngaySinh datetime,
	gioiTinh bit,
	email nvarchar(100)
)

select * from student

insert into student values('Son Tung MTP','10-24-1992',1,'mtp@gmail.com')
insert into student values('Dan Truong','11-04-1991',1,'dantruong@gmail.com')
insert into student values('Cam Ly','07-13-1990',0,'camly@gmail.com')
insert into student values('Pham Bang Bang','02-11-1993',0,'pbbang@gmail.com')
insert into student values('NgoThuan','02-11-1993',0,'thuan@gmail.com')

select maso from student where hoTen='NgoThuan'