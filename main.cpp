#include <iostream>
using namespace std;
template<class T = int>
struct nodo {
    T valores[5];
    nodo<T>* next;
    T* p;
    nodo(T v, nodo<T>* n = NULL) {
        p = valores;
        *p = v;
        next = n;
    }
};

template<class T = int>
struct LLO {
    nodo<T>* head = NULL;
    nodo<T>* act = head;
    nodo<T>* tail = NULL;
    T* top = NULL;
    T* p = NULL;
    bool find(T v);
    void add(T v);
    void del(T v);
    void print();
};
int main() {
    LLO<int> l;
    l.add(10);
    l.add(12);
    l.add(1);
    l.add(13);
    l.add(18);
    l.add(17);
    l.add(15);
    l.add(4);


    l.print();

    l.del(4);

    l.print();

}
template<class T>
void LLO<T>::add(T v) {
    if (!head) {
        head = new nodo<T>(v);
        tail = head;
        top = head->p;
    }
    else {
        if (!find(v)) {

            if (v < *p) {
                if (top == ((act->p) + 4)) {
                    tail->next = new nodo<T>(v, tail->next);
                    tail = tail->next;
                    top = tail->p;
                }
                T tmp1 = *p;
                T tmp2 = *(p + 1);
                T* f = p;

                while (f <= top) {
                    if (f == ((act->p) + 4)) {
                        act = act->next;
                        f = act->p;
                    }
                    else {
                        f++;
                    }
                    tmp2 = *f;
                    *f = tmp1;
                    tmp1 = tmp2;
                }
                top++;
                *p = v;
                if (*top < *(act->p))top--;
            }
            else {
                if (p == ((act->p) + 4)) {
                    tail->next = new nodo<T>(v, tail->next);
                    tail = tail->next;
                    top = tail->p;
                }
                top++;
                p = top;
                *p = v;
            }
        }
    }
}
template<class T>
bool LLO<T>::find(T v) {
    if (!head)return false;
    act = head;
    p = act->p;
    while (p) {

        if (v > *top)return false;

        if (v < *p)return false;

        if (*p == v)return true;

        if (p == ((act->p) + 5)) {
            act = act->next;
            p = act->p;
        }
        else {
            p++;
        }
    }
    return false;
}



template<class T>
void LLO<T>::del(T v) {

    T* q = p;

    if (find(v)) {
        while (act->next) {
            if (p != (act->p + 4)) {
                q++;
                *p = *q;
                p++;
            }
            else {
                if (act->next) {
                    act = act->next;
                    q = act->p;
                    *p = *q;
                    p = q;
                }
                else {
                    p--;
                    top = p;

                }
            }

            if (p == top && act->p != p) {
                p--;
                p = top;
            }

        }


    }
}
template<class T>
void LLO<T>::print() {
	T* tmp = head->p;
	nodo<T>* TMP = head;
	
	while (tmp <= top) {

		if (tmp == (TMP->p + 4)) {
			TMP = TMP->next;
			tmp = TMP->p;
		}

		cout << *tmp << "-";
		tmp++;
	}

}
