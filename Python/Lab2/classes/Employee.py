import re
from classes.Person import Person

class Employee(Person):
    def __init__(self, id, full_name,credit, is_manager):
        self.id = id
        self._email = ''
        self.work_mood = ' '
        self._salary = 0
        self.is_manager = is_manager
        super().__init__(full_name, credit)

    def work(self, hours):
        if hours > 8:
            self.work_mood = 'tired'
        elif hours < 8:
            self.work_mood = 'lazy'
        else:
            self.work_mood = 'happy'

    # def send_email(self,  suject_body, receiver_name):
    #     email_file = open('sended_email.txt', 'w', encoding='utf8')
    #     email_file.write('-'.join())
    @property
    def salary(self):
        return self._salary

    @salary.setter
    def salary(self, val):
        if val < 100:
            raise ValueError('salary cant be lower than 1000')
        self._salary = val

    @property
    def email(self):
        return self._email

    @email.setter
    def email(self, val):
        if not re.match("[^@]+@[^@]+\.[^@]+", val):
            print('invalid email')
        else:
            self._email = val

    def __str__(self):
        return f"{self.id},'{self.full_name}',{self.is_manager},'{self.email}',{self.salary},{self.money},'{self.sleep_mood}','{self.work_mood}',{self.health_rate}"
