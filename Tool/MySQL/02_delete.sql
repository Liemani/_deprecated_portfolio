# use rosmall;

# select * from Bank;
# select Name, Address, isMale from Customer;
# select Customer.Name from Customer;

select * from Employee;
# insert
select * from Employee where Name like '%cheol%';

select * from Customer;
delete from Customer where CustomerId = 'Supman'; 
select * from Employee where Name like '%cheol%';

select * from Customer;
delete from Customer where CustomerId = 'Supman';into Employee value(Null, 'Seongchul Kim', 'Sales 1', 01012345678);
insert into Employee value(3, 'BongcheolPark', 'Sales 1', 01025874152);

# You can use where at select, insert, update... etc
select * from Customer;
update Customer set EmployeeId = 1 where CustomerId = 'Hangman';
update Customer set BankId = 5, BankAccount = 4321 where CustomerId = 'Lieman';

select * from Employee;
select * from Employee where Name like '%cheol%';

select * from Customer;
delete from Customer where CustomerId = 'Supman';