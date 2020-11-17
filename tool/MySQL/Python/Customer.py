from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, INT, String
from sqlalchemy.orm import sessionmaker
from sqlalchemy import create_engine

Base = declarative_base()

class Customer(Base):
    __tablename__ = 'Customer'
    CustomerId = Column(INT, primary_key=True)
    FirstName = Column(String(40))
    LastName = Column(String(20))
    Company = Column(String(80))
    Address = Column(String(70))
    City = Column(String(40))
    State = Column(String(40))
    Country = Column(String(40))
    PostalCode = Column(String(10))
    Phone = Column(String(24))
    Fax = Column(String(24))
    Email = Column(String(60))
    SupportRepId = Column(INT)

    def insert_Customer(self):
        engine = create_engine('mysql+pymysql://root:1234@localhost:3306/Chinook')
        Session = sessionmaker(bind=engine)
        session = Session()

        session.add(self)
        session.commit()
        session.close()

    def get_all_Customer(self):
        engine = create_engine('mysql+pymysql://root:1234@localhost:3306/Chinook')
        Session = sessionmaker(bind=engine)
        session = Session()

        customer_list = []
        for row in session.query(Customer).all():
            customer_data = {}
            customer_data['CustomerId'] = row.CustomerId
            customer_data['FirstName'] = row.FirstName
            customer_data['LastName'] = row.LastName
            customer_data['Phone'] = row.Phone
            # customer_data['CustomerId'] = row.CustomerId
            # customer_data['CustomerId'] = row.CustomerId
            # customer_data['CustomerId'] = row.CustomerId
            # CustomerId = Column(INT, primary_key=True)
            # FirstName = Column(String(40))
            # LastName = Column(String(20))
            # Company = Column(String(80))
            # Address = Column(String(70))
            # City = Column(String(40))
            # State = Column(String(40))
            # Country = Column(String(40))
            # PostalCode = Column(String(10))
            # Phone = Column(String(24))
            # Fax = Column(String(24))
            # Email = Column(String(60))
            # SupportRepId = Column(INT)
            customer_list.append(customer_data)

        return customer_list

    def update_phone(self, customer_id, phone_number):
        engine = create_engine('mysql+pymysql://root:1234@localhost:3306/Chinook')
        Session = sessionmaker(bind=engine)
        session = Session()

        # update
        for row in session.query(Customer).filter(Customer.CustomerId == customer_id):
            row.Phone = phone_number

        session.commit()
        session.close()

    def delete_Customer(self, customer_id):
        engine = create_engine('mysql+pymysql://root:1234@localhost:3306/Chinook')
        Session = sessionmaker(bind=engine)
        session = Session()

        for row in session.query(Customer).filter(Customer.CustomerId == customer_id):
            session.delete(row)

        session.commit()
        session.close()




