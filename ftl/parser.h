#ifndef PARSER_H
#define PARSER_H

typedef struct node node;

struct node {
  char *kind;
  char *value;
  char *name;
  node *callee;
  node *expression;
  node **body;
  node **args;
  node **context;
};

#endif
