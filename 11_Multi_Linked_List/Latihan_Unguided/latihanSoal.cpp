#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Book
{
    string title;
    string returnDate;
    Book *next;
};

struct Member
{
    string name;
    string id;
    Book *bookHead;
    Member *next;
};

class LibraryManagement
{
private:
    Member *head;

public:
    LibraryManagement() : head(nullptr) {}

    void addMember(const string &name, const string &id)
    {
        Member *newMember = new Member{name, id, nullptr, head};
        head = newMember;
    }

    void addBook(const string &memberId, const string &title, const string &returnDate)
    {
        Member *mem = findMember(memberId);
        if (mem)
        {
            Book *newBook = new Book{title, returnDate, mem->bookHead};
            mem->bookHead = newBook;
        }
        else
        {
            cout << "Member not found.\n";
        }
    }

    void deleteMember(const string &memberId)
    {
        Member **curr = &head;
        while (*curr)
        {
            if ((*curr)->id == memberId)
            {
                Member *toDelete = *curr;
                *curr = (*curr)->next;

                // Delete all books of the member
                Book *currBook = toDelete->bookHead;
                while (currBook)
                {
                    Book *toDeleteBook = currBook;
                    currBook = currBook->next;
                    delete toDeleteBook;
                }

                delete toDelete;
                return;
            }
            curr = &((*curr)->next);
        }
        cout << "Member not found.\n";
    }

    void display()
    {
        Member *currMem = head;
        while (currMem)
        {
            cout << "Member: " << currMem->name << " (ID: " << currMem->id << ")\n";
            Book *currBook = currMem->bookHead;
            while (currBook)
            {
                cout << "  Book: " << currBook->title << ", Return Date: " << currBook->returnDate << "\n";
                currBook = currBook->next;
            }
            currMem = currMem->next;
        }
    }

private:
    Member *findMember(const string &id)
    {
        Member *curr = head;
        while (curr)
        {
            if (curr->id == id)
                return curr;
            curr = curr->next;
        }
        return nullptr;
    }
};

int main()
{
    LibraryManagement lm;
    lm.addMember("Losrumaho", "NIM1");
    lm.addMember("Lostugaso", "NIM2");
    lm.addMember("Lospinguinos", "NIM3");

    lm.addBook("NIM1", "Web Pemro", "01/12/2024");
    lm.addBook("NIM2", "CI/CD Devops", "15/12/2024");
    lm.addBook("NIM1", "Laracasts", "10/12/2024");

    lm.deleteMember("NIM2");

    lm.display();
    return 0;
}
