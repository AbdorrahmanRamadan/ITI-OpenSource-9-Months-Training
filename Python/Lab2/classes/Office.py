from classes.dbConnector import dbConnector

class Office(object):
    def __init__(self):
        self.name = ''
        self.employees = ' '
        self.db = dbConnector();

    def get_all_employees(self):
        allEmployees = self.db.find_all()
        if(allEmployees):
            return allEmployees
        else:
            return 'sry no thing added yet'

    def get_employee(self, empToFind):
       self.db.find_by_id(empToFind.id)

    def fire(self, empToRemove):
        self.db.delete(empToRemove.id)

    def hire(self,empToAdd):
       self.db.insert_data(empToAdd)
