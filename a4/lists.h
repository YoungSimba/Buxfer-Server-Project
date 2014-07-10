#ifndef LISTS_H
#define LISTS_H

struct group {
	char *name;
	struct user *users;
	struct xct *xcts;
	struct group *next;
};

struct user {
	char *name;
	double balance;
	struct user *next;
};

struct xct{
	char *name;
	double amount;
	struct xct *next;
};

typedef struct group Group;
typedef struct user User;
typedef struct xct Xct;

int add_group(Group **group_list, const char *group_name);
void list_groups(Group *group_list);
Group *find_group(Group *group_list, const char *group_name);

int add_user(Group *group, const char *user_name);
void list_users(Group *group);
int user_balance(Group *group, const char *user_name);
User *find_prev_user(Group *group, const char *user_name);

int add_xct(Group *group, const char *user_name, double amount);

#endif
