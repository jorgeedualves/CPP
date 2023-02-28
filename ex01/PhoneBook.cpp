#include <iostream>
using std::string;


// class PhoneBook
// {
//     private:

//     char *contats[8];
// };

class Contact
{
    private:
    string FirstName;
    string LastName;
    int PhoneNumber;

    public:
    void Add()
    {   
        std::cout << "Digite um nome" << std::endl;
        std::cin >> FirstName;
        std::cout << "Digite o Sobrenome:" << LastName << std::endl;
        std::cin >> LastName;
        std::cout << "Digite telefone:" << PhoneNumber << std::endl;
        std::cin >> PhoneNumber;
        void Print(string FirstName, string LastName, int PhoneNumber);
        
    };

};

void Print(string FirstName, string LastName, int PhoneNumber)
{
        std::cout << "Nome: " << FirstName << std::endl;
        std::cout << "Sobrenome: " << LastName << std::endl;
        std::cout << "Telefone: " << PhoneNumber << std::endl;
};

int main(void)
{
    Contact contact1;
    Contact contact2;

    contact1.Add();
    contact2.Add();

    return (0);
}
