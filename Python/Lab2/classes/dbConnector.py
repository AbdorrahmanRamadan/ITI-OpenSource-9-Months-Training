from mysql.connector import connect, Error
import mysql.connector


class dbConnector(object):
    def __init__(self, host="localhost", user='pylabs', pw='', db='Employees'):
        self.cur = None
        self.conn = None
        try:
            connection = mysql.connector.connect(
                host=host,
                user=user,
                password=pw,
                database=db,
            )
            self.conn = connection
            self.cur = connection.cursor()
            self.createEmpTable()
        except Error as e:
            print(e)

    def createEmpTable(self):
        try:
            self.cur.execute('select * from employees LIMIT 0, 1')
            data = self.cur.fetchall()
        except Error as e:
            self.cur.execute('''create table employees(
                    NID int primary key not null,
                    full_name varchar(50) not null,
                    is_manager boolean default 0,
                    Email varchar(150) ,
                    salary int not null,
                    credit int ,
                    sleep_mood varchar(50),
                    work_mood varchar(50),
                    health_rate int,
                    UNIQUE (Email)
                    );''')
            self.conn.commit()

    def insert_data(self, employeeToAdd):
        query = f"""
                INSERT INTO employees (NID, full_name,is_manager, Email, salary,credit,sleep_mood,work_mood,health_rate)
                VALUES({employeeToAdd})
                """
        try:
            self.cur.execute(query)
            self.conn.commit()
        except Error as e:
            print(e)

    def find_by_id(self, id):
        retrive = f"""
            SELECT *
            FROM employees
            WHERE NID = {id}
        """
        self.cur.execute(retrive)
        data = self.cur.fetchall()
        return data

    def find_all(self):
        retrive = """
            SELECT *
            FROM employees
        """
        with self.cur as cur:
            cur.execute(retrive)
        # self.cur.execute(retrive)
            data = cur.fetchall()
        return data

    def delete(self, id):
        delete = f"""
            delete
            FROM employees
            WHERE NID = {id}
        """
        try:
            self.cur.execute(delete)
            self.conn.commit()
            return 'ok'
        except Error as e:
            return 'error cant delete it'

    # def __del__(self):
    #     try:
    #         self.cursor.close()
    #         self.conn.close()
    #         return 'ok'
    #     except Error as e:
    #         pass
