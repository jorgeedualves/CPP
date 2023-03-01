#include <iostream>
using std::string;


// class PhoneBook
// {
//     private:

//     char *contats[3];
// };

class Contact
{
    private:
        string FirstName;
        string LastName;
        int PhoneNumber;
    public:
        Contact();
        void Add();
        void Print();
        void search();

};

Contact::Contact()
{
    FirstName = "";
    LastName = "";
    PhoneNumber = 0;
}

void Contact::search()
{
    Print();
}

void Contact::Add()
{   
    std::cout << "Digite um nome" << std::endl;
    std::cin >> FirstName;
    std::cout << "Digite o Sobrenome:" << LastName << std::endl;
    std::cin >> LastName;
    std::cout << "Digite telefone:" << PhoneNumber << std::endl;
    std::cin >> PhoneNumber;     
};

void Contact::Print()
{
        std::cout << "Nome: " << FirstName << std::endl;
        std::cout << "Sobrenome: " << LastName << std::endl;
        std::cout << "Telefone: " << PhoneNumber << std::endl;
};

int main(void)
{
    Contact contact[3];
    int i;
    int count;
    int option;

    std::cout << "Opções: 1 = Add, 2 = Seach, 3 = Exit" << std::endl;
    std::cin >> option;


    while(option != 3)
    {
        switch (option)
        {
        case 1:
            std::cout << "How many contacts will you add?" << std::endl;
            std::cin >> count; 
            for(i = 0; i < count; i++)
                contact[i].Add();
            break;
        case 2:
            std::cout << "Which contacts do you want to look for?" << std::endl;
            std::cin >> count;
            contact[count].search();
            break;
        default:
            break;
        }
    }
    return (0);
}
