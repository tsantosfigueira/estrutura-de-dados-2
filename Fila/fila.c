#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// -------------------------------
// Estruturas de dados
// -------------------------------

// Representa uma data simples (dia/mes/ano)
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Endereço usando apenas códigos numéricos
// (IDs para rua, bairro, cidade, estado, país; number é o número da casa)
typedef struct {
    int street_id;
    int zipcode;     // poderia ser um inteiro representando o CEP
    int district_id; // bairro
    int number;      // número do endereço
    int city_id;
    int state_id;
    int country_id;
} Address;

// Aluno com identificadores numéricos
typedef struct {
    int name_id;         // usamos um ID inteiro
    int registration;    // matrícula
    Date birthdate;      // data de nascimento
    Address address;     // endereço
} Student;

// Nó da fila
typedef struct Node {
    Student data;
    struct Node* next;
} Node;

// Fila encadeada
typedef struct {
    Node* head;   // início (remoção)
    Node* tail;   // fim (inserção)
    size_t size;  // quantidade de elementos
} Queue;

// -------------------------------
// API da Fila
// -------------------------------

// Inicializa a fila vazia
void queue_init(Queue* q) {
    if (!q) return;
    q->head = q->tail = NULL;
    q->size = 0;
}

// Retorna true se a fila está vazia
bool queue_is_empty(const Queue* q) {
    return !q || q->size == 0;
}

// Retorna a quantidade de elementos na fila
size_t queue_size(const Queue* q) {
    return q ? q->size : 0;
}

// Enfileira (inserção no fim). Retorna true se ok, false se erro de memória.
bool enqueue(Queue* q, const Student* s) {
    if (!q || !s) return false;

    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return false;

    node->data = *s;  // cópia simples (tudo é valor)
    node->next = NULL;

    if (q->tail) {
        q->tail->next = node;
    } else {
        // Fila estava vazia
        q->head = node;
    }
    q->tail = node;
    q->size++;
    return true;
}

// Desenfileira (remoção do início). Retorna true se removeu; false se vazia.
bool dequeue(Queue* q, Student* out) {
    if (!q || queue_is_empty(q)) return false;
    Node* first = q->head;
    if (out) *out = first->data; // devolve uma cópia
    q->head = first->next;
    if (!q->head) {
        // Fila ficou vazia → tail também deve ser NULL
        q->tail = NULL;
    }
    free(first);
    q->size--;
    return true;
}

// Espia (peek) o primeiro elemento sem remover. Retorna false se vazia.
bool queue_peek(const Queue* q, Student* out) {
    if (!q || queue_is_empty(q)) return false;
    if (out) *out = q->head->data;
    return true;
}

// Limpa toda a fila, liberando memória
void queue_clear(Queue* q) {
    if (!q) return;
    Node* cur = q->head;
    while (cur) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    q->head = q->tail = NULL;
    q->size = 0;
}

// -------------------------------
// Funções auxiliares de I/O (apenas para demonstrar)
// -------------------------------

// Imprime um aluno (apenas códigos numéricos)
void print_student(const Student* s) {
    if (!s) return;
    printf("Aluno {\n");
    printf("  name_id: %d\n", s->name_id);
    printf("  registration: %d\n", s->registration);
    printf("  birthdate: %02d/%02d/%04d\n", s->birthdate.day, s->birthdate.month, s->birthdate.year);
    printf("  address:\n");
    printf("    street_id: %d, number: %d\n", s->address.street_id, s->address.number);
    printf("    district_id: %d\n", s->address.district_id);
    printf("    zipcode: %d\n", s->address.zipcode);
    printf("    city_id: %d, state_id: %d, country_id: %d\n",
           s->address.city_id, s->address.state_id, s->address.country_id);
    printf("}\n");
}

// Imprime a fila inteira
void queue_print(const Queue* q) {
    if (!q) return;
    printf("Queue(size=%zu):\n", q->size);
    Node* cur = q->head;
    size_t idx = 0;
    while (cur) {
        printf("---- [%zu] ----\n", idx++);
        print_student(&cur->data);
        cur = cur->next;
    }
}

// -------------------------------
// Exemplo de uso
// -------------------------------

int main(void) {
    Queue q;
    queue_init(&q);

    // Monta alguns alunos com dados numéricos simples
    Student a = {
        .name_id = 101,
        .registration = 2023001,
        .birthdate = { .day = 15, .month = 1, .year = 2002 },
        .address = {
            .street_id = 10, .zipcode = 69000000, .district_id = 1,
            .number = 123, .city_id = 500, .state_id = 13, .country_id = 76
        }
    };

    Student b = {
        .name_id = 102,
        .registration = 2023002,
        .birthdate = { .day = 30, .month = 9, .year = 2001 },
        .address = {
            .street_id = 11, .zipcode = 69050010, .district_id = 2,
            .number = 45, .city_id = 500, .state_id = 13, .country_id = 76
        }
    };

    Student c = {
        .name_id = 103,
        .registration = 2023003,
        .birthdate = { .day = 5, .month = 12, .year = 2000 },
        .address = {
            .street_id = 12, .zipcode = 69057000, .district_id = 3,
            .number = 900, .city_id = 510, .state_id = 13, .country_id = 76
        }
    };

    // Enfileira
    enqueue(&q, &a);
    enqueue(&q, &b);
    enqueue(&q, &c);

    printf("\n== Fila apos enfileirar 3 alunos ==\n");
    queue_print(&q);

    // Peek
    Student top;
    if (queue_peek(&q, &top)) {
        printf("\n== Peek (primeiro da fila) ==\n");
        print_student(&top);
    }

    // Dequeue
    Student out;
    if (dequeue(&q, &out)) {
        printf("\n== Dequeue 1 ==\n");
        print_student(&out);
    }
    if (dequeue(&q, &out)) {
        printf("\n== Dequeue 2 ==\n");
        print_student(&out);
    }

    printf("\n== Fila restante ==\n");
    queue_print(&q);

    printf("\nTamanho da fila: %zu\n", queue_size(&q));

    // Limpa
    queue_clear(&q);
    printf("\nFila limpa. Vazia? %s\n", queue_is_empty(&q) ? "sim" : "nao");

    return 0;
}