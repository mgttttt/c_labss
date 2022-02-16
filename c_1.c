#include <stdio.h>

int main() {
    int b1, b2, b3;
    printf("Enter ineger b1:");
    if (!scanf("%d", &b1))
      {
        printf("Incorrect input");
        return 0;
      }
    printf("Enter ineger b2:");
    if (!scanf("%d", &b2))
    {
      printf("%s", "Incorrect input");
      return 0;
    }
    printf("Enter ineger b3:");
    if (!scanf("%d", &b3))
    {
      printf("%s", "Incorrect input");
      return 0;
    }

    if (b1 < b2 && b1 < b3)
      {
        if (b1 % 2)
        {
          printf("%d", 1);
          printf("\n");
        }
        else {
          float d = 1.0 / b1;
          printf("%.1f", d);
          printf("\n");
        }
      }
    else if (b2 < b1 && b2 < b3)
    {
      if (b2 % 2)
      {
        printf("%d", 1);
        printf("\n");
      }
      else {
        float d = 2.0 / b2;
        printf("%.2f", d);
        printf("\n");
      }
    }
    else {
      if (b3 % 2)
      {
        printf("%d", 1);
        printf("\n");
      }
      else {
        float d = 3.0 / b3;
        printf("%.3f", d);
        printf("\n");
      }
    }

  return 0;
}
