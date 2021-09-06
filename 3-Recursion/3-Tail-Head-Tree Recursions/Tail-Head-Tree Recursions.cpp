#include <iostream>
#include <stdio.h>

void tail(int n) {
    if (n > 0) {
        printf("%d", n);
        tail(n - 1);     //tailde funk çağrısından sonra herhangi bit işlrm olmaz
    }
}
void head(int n) {
    if (n > 0) {
        head(n - 1);   // head te funk çağrısında önce herhangi bir işlem olamaz;
        printf("%d", n);
    }
}
void linear(int n) {
    if (n > 0) {
        printf("%d", n);
        linear(n - 1);    //linerda funk sadece bir kere çağrılır ancak hem öncesinde hemde  sonrasında işlem olmak zorunda
        printf("%d", n);
    }
}
void tree(int n) {
    if (n > 0) {
        printf("%d", n);
        tree(n - 1);
        tree(n - 1);
    }
}

int main()
{
    printf("tail : ");
    tail(3);
    printf("\nhead : ");
    head(3);
    printf("\nlinear : ");
    linear(3);
    printf("\ntree : ");
    tree(3);
}

