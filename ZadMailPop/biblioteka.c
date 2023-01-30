#include <stdio.h>
#include <string.h>

struct User {
    int id;
    char imie[20];
    char nazwisko[20];
};

struct Book {
    int id;
    char title[20];
    int lendedTo;
};

struct User users[1000];
struct Book books[1000];

int lastUserId = 0;
int lastBookId = 0;

void registerUser(char imie[20], char nazwisko[20]) {
    lastUserId++;
    struct User newUser;
    newUser.id = lastUserId;
    strcpy(newUser.imie, imie);
    strcpy(newUser.nazwisko, nazwisko);
    users[lastUserId - 1] = newUser;
    printf("Successfully registered user with id %d.\n", newUser.id);
}

void deleteUser(int userId) {
    if (userId > lastUserId || userId <= 0) {
        printf("Złe id użytkownika!.\n");
        return;
    }
    for (int i = userId - 1; i < lastUserId - 1; i++) {
        users[i] = users[i + 1];
    }
    lastUserId--;
    printf("Użytkownik z id %d został usunięty!.\n", userId);
}

void addBook(char title[20]) {
    lastBookId++;
    struct Book newBook;
    newBook.id = lastBookId;
    strcpy(newBook.title, title);
    newBook.lendedTo = -1;
    books[lastBookId - 1] = newBook;
    printf("Dodano nową książke z id %d.\n", newBook.id);
}

void lendBook(int userId, int bookId) {
    if (userId > lastUserId || userId <= 0) {
        printf("Nieprawidłowe id użytkownika!.\n");
        return;
    }
    if (bookId > lastBookId || bookId <= 0) {
        printf("Nieprawidłowe id ksiązki.\n");
        return;
    }
    if (books[bookId - 1].lendedTo != -1) {
        printf("Ta książka jest już wypożyczona!.\n");
        return;
    }
    books[bookId - 1].lendedTo = userId;
    printf("Książka o id %d jest wypożyczona do użytkownika z id %d.\n", bookId, userId);
}

void returnBook(int bookId) {
    if (bookId > lastBookId || bookId <= 0) {
        printf("Złe id książki.\n");
        return;
    }
    if (books[bookId - 1].lendedTo == -1) {
        printf("Ta książka nie jest wypożyczona.\n");
        return;
    }
    books[bookId - 1].lendedTo = -1;
    printf("Książla o id %d została zwrócona.\n", bookId);
}

void showUsers() {
    printf("Lista użytkowników:\n");
    for (int i = 0; i < lastUserId; i++) {
        printf("%d. ID: %d, %s %s\n", i+1, users[i].id, users[i].imie, users[i].nazwisko);
    }
}

void showBooks() {
    printf("Lista książek:\n");
    for (int i = 0; i < lastBookId; i++) {
        if (books[i].lendedTo == -1) {
            printf("%d. %s (dostępna)\n", books[i].id, books[i].title);
        } else {
            printf("%d. %s (wypożyczona do użytkownika z id %d)\n", books[i].id, books[i].title, books[i].lendedTo);
        }
    }
}

int main() {
    char firstName[20], lastName[20], title[20];
    int userId, bookId;
    int choice;
    while (1) {
        printf("1. Zarejestruj użytkownika\n2. Dodaj książkę\n3. Wyporzycz książkę\n4. Zwróć książkę\n5. Pokaż wszystkich użytkowników\n6. Pokaż wszystkie książkie\n7. Usuń użytkownika\n8. Wyjście\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Podaj imię: ");
            scanf("%s", firstName);
            printf("Podaj nazwiskoe: ");
            scanf("%s", lastName);
            registerUser(firstName, lastName);
        } else if (choice == 2) {
            printf("Zamiast spacji użyj kropki!!!!\nPodaj tytuł: ");
            scanf("%s", title);
            addBook(title);
        } else if (choice == 3) {
            printf("Podaj id użytkownika: ");
            scanf("%d", &userId);
            printf("Podaj id książki: ");
            scanf("%d", &bookId);
            lendBook(userId, bookId);
        } else if (choice == 4) {
            printf("Podaj id książki: ");
            scanf("%d", &bookId);
            returnBook(bookId);
        } else if (choice == 5) {
            showUsers();
        } else if (choice == 6) {
            showBooks();
        } else if (choice == 7) {
            printf("Enter user id: ");
            scanf("%d", &userId);
            deleteUser(userId);
        } else {
            break;
        }
    }

    return 0;
}
