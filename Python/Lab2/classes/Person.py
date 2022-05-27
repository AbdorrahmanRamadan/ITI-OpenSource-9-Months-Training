class Person(object):
    def __init__(self, full_name, money):
        self.full_name = full_name
        self.money = money
        self.sleep_mood = ''
        self.health_rate = 0

    def sleep(self, hours):
        if hours < 7:
            self.sleep_mood = 'tired'
        elif hours > 7:
            self.sleep_mood = 'lazy'
        else:
            self.sleep_mood = 'happy'

    def eat(self, meals):
        if meals == 3:
            self.health_rate = 100
        elif meals == 2:
            self.health_rate = 75
        elif meals == 1:
            self._health_rate = 50
        else:
            print('pls enter a valid meals count 1:3')

    def buy(self, items):
        if len(items) == 1:
            self.money -= 10

    @property
    def health_rate(self):
        return self._health_rate

    @health_rate.setter
    def health_rate(self, val):
        try:
            assert 0 <= val <= 100
            self._health_rate = val
        except AssertionError:
            print('health rate must be between 0 and 100')
