use Chinook;

select * from Album;

select Album.Title, Artist.Name from Album, Artist;

select * from Track;
select Track.Name as 'Track', Album.Title, MediaType.Name as 'MediaType', Genre.Name as 'Genre' from Track, Album, MediaType, Genre;

select * from Artist;
insert into Artist value(276, 'Muse');

select * from Invoice join Customer on Invoice.CustomerId = Customer.CustomerId;
select Invoice.InvoiceId, DISTINCT CustomerId from Invoice;

delete from Invoice where Invoice.CustomerId = 59;
delete from Customer where Customer.CustomerId = 59;

select * from Invoice join Customer on Invoice.CustomerId = Customer.CustomerId;

select * from Album;

select * from InvoiceLine;
select InvoiceLine.InvoiceLineId, InvoiceLine.InvoiceId, InvoiceLine.TrackId from InvoiceLine right join Track on InvoiceLine.TrackId = Track.TrackId;
select * from InvoiceLine right join Track on InvoiceLine.TrackId = Track.TrackId;

select * from Album;
select * from Artist;
select * from Customer;
select * from Employee;
select * from Genre;
select * from Invoice;
select * from InvoiceLine;
select * from MediaType;
select * from Playlist;
select * from PlaylistTrack;