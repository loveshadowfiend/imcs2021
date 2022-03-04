#include <iostream>
#include <vector>
#include "settings.txt"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

struct visitor {
    char name;
    int time;
};

struct node {
    visitor data;
    node *next;
};

struct queue {
    node *head;
    node *tail;
    int size = 0;
    void push(char name, int time) {
        if (size == 0) {
            head = new node;
            head->data.name = name;
            head->data.time = time;
            head->next = nullptr;
        } else if (size == 1) {
            tail = new node;
            head->next = tail;
            tail->data.name = name;
            tail->data.time = time;
            tail->next = nullptr;
        } else {
            tail->next = new node;
            tail = tail->next;
            tail->data.name = name;
            tail->data.time = time;
            tail->next = nullptr;
        }
        size++;
    }
    void pop() {
        if (size == 0) {
            return;
        } else if (size == 1) {
            delete head;
        } else {
            node *tmp = head;
            head = head->next;
            delete tmp;
        }
        size--;
    }
    char frontName() { return head->data.name; }
    int frontTime() { return head->data.time; }
};

struct cashier {
    char busy = '-';
    int people;
    queue cur;
};

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    int t = 0, gameover = 0, 
        happy = 0, // людей обслужено
        sad = 0,   // людей в очереди
        cashiers = 1;
    std::vector<cashier*> remi;
    queue aw;
    node *iter;
    for (int i = 0; i < MAX_CASHIERS; i++) {
        cashier *a = new cashier;
        remi.push_back(a);
    }
    remi[0]->busy = '+';
    while(!gameover) {
        system("clear");
        //  заполняем очередь
        //  и проверяем нагруженность кассы
        for (int i = 0; i < rand()%MAX_NEXT_CUSTOMERS; i++) {
            aw.push(rand()%25+97, rand()%MAX_CUSTOMER_TIME+1);
        }
        for (int i = 0; i < remi.size(); i++) {
            if (remi[i]->cur.size < MAX_CASHIER_QUEUE && aw.size > 0 && remi[i]->busy == '+') {
                while (aw.size > 0 && remi[i]->cur.size < MAX_CASHIER_QUEUE) {
                    remi[i]->cur.push(aw.head->data.name, aw.head->data.time);
                    aw.pop();
                    sad++;
                }
            } else if (remi[i]->cur.size == 0 && i != 0) {
                if (remi[i]->busy == '+')
                    cashiers--;
                remi[i]->busy = '-';
            }
        }
        //  вывод
        std::cout << "супермаркет реми ♡\n\n";
        for (int i = 0; i < remi.size(); i++) {
            std::cout << i+1 << " " << (i+1 > 9 ? " " : "  ") << remi[i]->busy << "   ";
            iter = remi[i]->cur.head;
            for (int j = 0; j < MAX_CASHIER_QUEUE; j++) {
                if (j < remi[i]->cur.size) {
                    std::cout << iter->data.name << iter->data.time; 
                    std::cout << (iter->data.time > 9 ? "  " : "   ");
                    iter = iter->next;
                } else {
                    std::cout << "==" << "   ";
                }
            } std::cout << '\n';
            if (remi[i]->cur.size > 0) {
                remi[i]->cur.head->data.time--;
                if (remi[i]->cur.head->data.time == 0) {
                    remi[i]->cur.pop();
                    sad--;
                    happy++;
                }
            }
        }
        t++; 
        std::cout << "\nвремя: " << t << '\n'
                  << "людей в очереди: " << sad << '\n'
                  << "людей обслужено: " << happy << '\n'
                  << "максимум людей в очереди: " << MAX_CASHIER_QUEUE << '\n'
                  << "касс работает: " << cashiers << '\n'
                    << "вне очереди: ";
        iter = aw.head;
        for (int i = 0; i < aw.size; i++) {
            std::cout << iter->data.name << iter->data.time << " ";
            iter = iter->next;
        } std::cout << '\n';
        //  открыаем следующую кассу, если есть люди вне очереди
        //  и проверяем на gameover (все кассы заняты и есть люди вне очереди)
        for (int i = 0; i < remi.size(); i++) {
            if (remi[i]->cur.size == 0 && aw.size > 0) {
                remi[i]->busy = '+';
                cashiers++;
                gameover = 0;
                break;
            } else if (remi[i]->cur.size < MAX_CASHIER_QUEUE) {
                gameover = 0;
            } else if (remi[i]->cur.size == MAX_CASHIER_QUEUE && aw.size > 0) {
                gameover = 1;
            }
        }
        sleep(1);
    }
}
