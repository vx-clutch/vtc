#include "./../../ftl/error.h"

int main(int argc, char **argv) {
  if (argc < 2) {
    fatal_error("No feature provided.");
  }
} 
