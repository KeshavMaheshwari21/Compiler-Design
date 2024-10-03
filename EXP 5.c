#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 20 

struct table {
  char label[MAX_ENTRIES][10];
  char symbol[MAX_ENTRIES][10];
  int address[MAX_ENTRIES];
};

int main() {
  int choice = 0, count = 0, del = 0;
  struct table entry;

  while (1) {
    printf("\n1. Add\n2. Delete\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      if (count >= MAX_ENTRIES) {
        printf("Symbol table is full! Cannot add more entries.\n");
        break;
      }
      printf("Enter the values in order Label Symbol Address: ");
      scanf("%s %s %d", entry.label[count], entry.symbol[count], &entry.address[count]);
      count++;
      break;
    case 2:
      if (count == 0) {
        printf("No entries to delete.\n");
        break;
      }
      printf("Enter the address of the record you want to delete: ");
      scanf("%d", &del);
      int found = 0; 
      for (int j = 0; j < count; j++) {
        if (entry.address[j] == del) { 
          for (int k = j; k < count - 1; k++) {
            strcpy(entry.label[k], entry.label[k + 1]);
            strcpy(entry.symbol[k], entry.symbol[k + 1]);
            entry.address[k] = entry.address[k + 1];
          }
          count--; 
          found = 1;  
          printf("Entry with address '%d' deleted.\n", del);
          break;
        }
      }
      if (!found) {
        printf("Address '%d' not found.\n", del);
      }
      break;
    case 3:
      if (count > 0) {
        printf("Displaying data:\n");
        printf("Label\t\tSymbol\t\tAddress\n");
        for (int j = 0; j < count; j++) {  
          printf("%s\t\t%s\t\t%d\n", entry.label[j], entry.symbol[j], entry.address[j]);
        }
      } else {
        printf("No data to display.\n");
      }
      break;
    case 4:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice, please try again.\n");
      break;
    }
  }
}
