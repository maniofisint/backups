class CreditCard:
    """ A Credit card"""

    def __init__(self, costumer, bank, acnt, limit):
        """ init documentation"""

        self._costumer = costumer
        self._bank = bank
        self._account = acnt
        self._limit = limit
        self._balance = 0

    def get_customer(self):
        return self._costumer

    def get_bank(self):
        return self._bank

    def charge(self, price):
        if price + self._balance > self._limit:
            return False
        else:
            self._balance += price
            return True

    def make_payment(self, amount):
        self._balance -= amount


 


if __name__ == '__main__':
    wallet = []

    wallet.append(CreditCard('John Bowman','California Savings','565391 0375 9387 5309', 2500) )
    wallet.append(CreditCard('John Bowman','California Federal','583485 0399 3395 1954', 3500) )
    wallet.append(CreditCard('John Bowman','California Finance','605391 0375 9387 5309', 5000) )

    for val in range (1, 17):
        wallet[0].charge(val)
        wallet[1].charge(2*val)
        wallet[2].charge(3*val)

    
    for c in range(3):
        print('Customer =', wallet[c].get_customer())
        print('Bank =', wallet[c].get_bank())
        """print('Account =', wallet[c].getaccount())
        print('Limit =', wallet[c].getlimit())
        print('Balance =', wallet[c].getbalance())"""
        while wallet[c].getbalance()>100:
            wallet[c].makepayment(100)
            print('New balance =', wallet[c].getbalance())
        print()


        
