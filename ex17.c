#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct database {
    struct address rows[MAX_ROWS];
};

struct connection {
    FILE *file;
    struct database *db;
};

void die(const char *message)
{
    if (errno) {
        perror(message);
    }
    else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void address_print(struct address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void database_load(struct connection *conn)
{
    int rc = fread(conn->db, sizeof(struct database), 1, conn->file);
    if (rc != 1) {
        die("Failed to load database.");
    }
}

struct connection *database_open(const char *filename, char mode)
{
    struct connection *conn = malloc(sizeof(struct connection));
    if (!conn){
        die("Memory error.");
    }
    conn->db = malloc(sizeof(struct database));
    if (!conn->db) {
        die("Memory error.");
    }
    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");
        if (conn->file) {
            database_load(conn);
        }
    }

    if (!conn->file) {
        die("Failed to open the file.");
    }

    return conn;
}

void database_close(struct connection *conn) 
{
    if (conn) {
        if (conn->file) {
            fclose(conn->file);
        }
        if (conn->db) {
            free(conn->db);
        }
        free(conn);
    }
}

void database_write(struct connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct database), 1, conn->file);
    if (rc != 1) {
        die("Failed to write database.");
    }
    rc = fflush(conn->file);
    if (rc == -1) {
        die("Cannot flush database.");
    }
}

void database_create(struct connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        //make a prototype to initialize
        struct address addr = {.id = i, .set = 0};
        //then assign it
        conn->db->rows[i] = addr;
    }
}

void database_set(struct connection *conn, int id, const char *name, const char *email)
{
    struct address *addr = &conn->db->rows[id];
    if (addr->set){
        die("Already set, delete it first");
    }
    addr->set = 1;
    //bug correction for strncpy null termination
    /*
    printf("Name: %s Email: %s\n", name, email);
    printf("Name size: %ld, Email size: %ld\n", sizeof(name), sizeof(email));
    
    if (sizeof(name) == MAX_DATA) {
        name[MAX_DATA-1] = '\0';
        printf("Name exceeds max data: shortened to \"%s\"\n", name);
    }
    if (sizeof(email) == MAX_DATA) {
        email[MAX_DATA-1] = '\0';
        printf("Email exceeds max data: shortened to \"%s\"\n", email);
    } */
    //end bug correction
    //WARNING: bug, read the "how to break it" section and fix
    char *res = strncpy(addr->name, name, MAX_DATA);
    //demonstrate the bug
    if (!res){
        die("Name copy failed.");
    }
    res = strncpy(addr->email, email, MAX_DATA);
    if (!res){
        die("Email copy failed.");
    }
}

void database_get(struct connection *conn, int id)
{
    struct address *addr = &conn->db->rows[id];

    if (addr->set){
        address_print(addr);
    } else {
        die("ID is not set.");
    }
}

void database_delete(struct connection *conn, int id)
{
    struct address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void database_list(struct connection *conn)
{
    int i = 0;
    struct database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct address *cur = &db->rows[i];

        if (cur->set) {
            address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }
    char *filename = argv[1];
    char action = argv[2][0];
    struct connection *conn = database_open(filename, action);
    int id = 0;

    if (argc > 3) id = atoi(argv[3]);
    if (id >= MAX_ROWS) die("There aren't that many records");

    switch (action) {
        case 'c':
            database_create(conn);
            database_write(conn);
            break;
        case 'g':
            if (argc != 4) {
                die("Need an id to get");
            }
            database_get(conn, id);
            break;
        case 's':
            if (argc != 6) {
                die("Need id, name, email to set");
            }
            printf("Name size: %lu Email size: %lu\n", strlen(argv[4]), strlen(argv[5]));
            //bug correction for strncpy null termination
            if (strlen(argv[4]) >= MAX_DATA) {
                argv[4][MAX_DATA-1] = '\0';
                printf("Name exceeds max length (%d bytes), shortened to \"%s\"\n", MAX_DATA, argv[4]);
            }
            if (strlen(argv[5]) >= MAX_DATA) {
                argv[5][MAX_DATA-1] = '\0';
                printf("Email exceeds max length (%d bytes), shortened to \"%s\"\n", MAX_DATA, argv[5]);
            }
            //end bug correction
            database_set(conn, id, argv[4], argv[5]);
            database_write(conn);
            break;
        case 'd':
            if (argc != 4) {
                die("Need id to delete");
            }
            database_delete(conn, id);
            database_write(conn);
            break;
        case 'l':
            database_list(conn);
            break;
        default:
            die("Invalid action: c=create, g=get, s=set, d=del, l=list");
    }
    database_close(conn);
    return 0;
}