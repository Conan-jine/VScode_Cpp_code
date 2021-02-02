#include <bits/stdc++.h>

using namespace std;

struct node {
	char val;
	node *next;
} *head, *tail, *now;

void ini () {
	head = tail = now = new node;
	//head->next = tail->next = now->next = NULL;
	head->next = NULL;
} 

int main () {
	char s[100086];
	while (scanf("%s", s) != EOF) {
		ini();
		int str = strlen(s);
		for (int i = 0; i < str; i++) {
			if (s[i] == '[') now = head;
			else if (s[i] == ']') now = tail;
			else {
				node *tmp = new node;
				tmp->val = s[i], tmp->next = now->next;
				now->next = tmp;
				now = tmp;
				if (now->next == NULL)
					tail = now;
			}
		}
		for (now = head->next; now != NULL; now = now->next)
			printf("%c", now->val);
		puts("");
	}
    return 0;
}