from Customer import Customer

if __name__ == '__main__':
    customer = Customer()
    customer.CustomerId = 60
    customer.FirstName = "John"
    customer.LastName = "Wick"
    customer.Company = "Apple"
    customer.Address = "32 Eligin Street"
    customer.City = "LA"
    customer.State = "CA"
    customer.Country = "USA"
    customer.PostalCode = "123456"
    customer.Phone = '+82-10-6681-9940'
    customer.Fax = None
    customer.Email = "threego03@gmail.com"
    customer.SupportRepId = 1


    print(customer.get_all_Customer())
    customer.insert_Customer()


    print(customer.get_all_Customer())
    # customer.update_phone(60, "010-1234-5678")
    # print(customer.get_all_Customer())


    # print(customer.get_all_Customer())
    # customer.delete_Customer(60)
    # print(customer.get_all_Customer())