from classes.Employee import Employee
from classes.Person import Person
from classes.Office import Office


# NID int
# full_name
# Email varchar(150) unique,
# salary int not null,
# credit int,
# sleep_mood varchar(50),
# work_mood varchar(50),
# health_rate varchar(50),


# ---------------------------------
#     employee atrr
# ---------------------------------
#in constructor
    # id
    # is_manager
    # full name
    # credit
# using setters
    # email
    # work() ==> work_mood
    # salary

# ---------------------------------
#     person atrr
# ---------------------------------
# sleep_mood
# health_rate

yaya = Employee(200, 'yaya', 30000, True)
yaya.email = 'yaya@iti.com'
yaya.salary = 9000
yaya.work(8)

yaya.sleep(7)
yaya.eat(3)   
print(yaya)

yaya2 = Employee(300, 'yaya2', 30000, True)
yaya2.email = 'yaya2@iti.com'
yaya2.salary = 9000
yaya2.work(8)

yaya2.sleep(7)
yaya2.eat(3)
print(yaya2)

dbHandler = Office()
dbHandler.hire(yaya)
dbHandler.hire(yaya2)
# dbHandler.fire(yaya2)
allEmps = dbHandler.get_all_employees()
print(f'all employees : {allEmps}')

while True:
    res = input('enter employee data ? y/N:').lower()
    if res == 'y' :
        NID = input('enter NID :')
        name = input('enter name :')
        credit =   int(input('enter credit :'))
        email = input('enter email :')

    if res == 'n':
        break 