using namespace std;

class BankAccount
{
private:
    string accountOwner;
    int dollars;
    int cents;

    friend ostream& operator << (ostream& os, const BankAccount& ba);
public:
    BankAccount(string name, int dollars, int cents) : accountOwner(name), dollars(dollars), cents(cents) {}
    string getAccountOwner() { return accountOwner; }

    bool operator==(const BankAccount& a);
};

ostream& operator << (ostream& os, const BankAccount& ba)
{
    os << "Name: " << ba.accountOwner << endl;
    os << "Balance: $" << ba.dollars << "." << ba.cents << endl;
    return os;
}

bool BankAccount::operator==(const BankAccount& a)
{
    if(a.accountOwner != this->accountOwner) return false;
    if(a.dollars != this->dollars) return false;
    if(a.cents != this->cents) return false;
    return true;
}

int main()
{
    BankAccount andrew("Andrew", 5, 25);
    BankAccount paul("Paul", 10, 50);
    BankAccount andrewAlt("Andrew", 5, 25);

    cout << andrew << endl;
    cout << paul << endl;
    cout << andrewAlt << endl;

    if(andrew == paul) cout << "andrew is equal to paul" << endl;
    else cout << "andrew is not equal to paul" << endl;

    if(andrew == andrewAlt) cout << "andrew is equal to andrewAlt" << endl;
    else cout << "andrew is not equal to andrewAlt" << endl;

    return 0;
}
