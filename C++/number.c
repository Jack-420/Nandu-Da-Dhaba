#include <stdio.h>

int main() {
    printf("Enter the number ");
    int n;
    scanf("%d",&n);
 
    char a[21][20]={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight","Nine", "Ten", "Eleven", "Tweleve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    char b[8][20]={"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",};
    if(n<21&&n>0){
        printf("%d in words :- %s \n",n,a[n]);
    }
    else if(n==0){
        printf("%d in words :- Zero",n);
    }
    else if(n>21&&n<=99) 
    {
        int x = n/10;
        int y = n%10;
        printf("%d in words :- %s %s\n",n,b[x-2],a[y]);
    } 
    else if(n>=120&&n<=999) {
        int x = n/100;
        int y = ((n%100-n%10)/10)-2;
        int z = n%10;
        printf("%d in words :- %s Hundred %s %s ",n,a[x],b[y],a[z]);
    } 
    else if(n>99&&n<=119){
        int x = n/100;
        int y = n%100;
        printf("%d in words :- %s Hundred %s ",n,a[x],a[y]);
    }
    else if (n>999&&n<=20999) {
        int x = n/1000;
        int y = (n%1000-n%100)/100;
        int z = (n%100-n%10)/10-2;
        int p = n%10;
        if(y!=0){
            if(n%1000==0){
                printf("%d in words :- %s Thousand ",n,a[x]);
            } else {
                if(n%100<=19){
                    int i = n%20;
                    printf("%d in words :- %s Thousand %s Hundred %s ",n,a[x],a[y],a[i]);
                } else {
                    printf("%d in words :- %s Thousand %s Hundred %s %s",n,a[x],a[y],b[z],a[p]);
                }
            } 
        } else {
            if(n%100<=19){
                int i = n%20;
                printf("%d in words :- %s Thousand %s ",n,a[x],a[i]);
            } else {
                printf("%d in words :- %s Thousand %s %s",n,a[x],b[z],a[p]);
            }
        }
    }
    else if(n>20999&&n<=99999) {
        int x = n/10000-2;
        int y = (n%10000-n%1000)/1000;
        int z = (n%1000-n%100)/100;
        int p = (n%100-n%10)/10-2;
        int q = n%10;
        if(z!=0){
            if(n%10000==0){
                printf("%d in words :- %s Thousand ",n,b[x]);
            } else {
                if(n%100<=19){
                    int i = n%20;
                    printf("%d in words :- %s %s Thousand %s Hundred %s",n,b[x],a[y],a[z],b[p],a[q]);
                } else {
                printf("%d in words :- %s %s Thousand %s Hundred %s %s",n,b[x],a[y],a[z],b[p],a[q]);
                }
            } 
        } else {
            if(n%100<=19){
                    int i = n%20;
                    printf("%d in words :- %s %s Thousand %s ",n,b[x],a[y],a[i]);
            } else {
                    printf("%d in words :- %s %s Thousand %s %s",n,a[x],b[y],b[z],a[p]);
            }
        }
    }
    else if(n==100000){
        printf("One lakh.");
    } else {
        printf("Give a number upto 1 lakh.");
    }
    return 0;
}