#include<stdio.h>

    ///Variable type & declaration for Account & Balance in structure form

    struct accountholder_info{
        int account_number;
        float balance;
        float last_deposit;
        float last_withdraw;
    };
    ///Variable type & declaration for counting & info
    int counter,counter1;

    struct accountholder_info accountholder[10];

    ///Using function for showing account id & balance multiple times
    void output__account_info(){
        printf("\nAccount %d : %d\n",counter+1,accountholder[counter].account_number);
        printf("Balance %d : %.2f\n",counter+1,accountholder[counter].balance);
    }
int main(){

    printf("+++++++ Bank Management System +++++++\n\n");

    ///Taking Inputs for Account & Balance
    for(counter=0;counter<=9;counter++){
        printf("Enter account number %d : ",counter+1);
        scanf("%d",&accountholder[counter].account_number);
        for(counter1=0;counter1<=counter-1;counter1++){
            if(accountholder[counter].account_number==accountholder[counter1].account_number){
                accountholder[counter].account_number=0;
                accountholder[counter].balance=0;
            }
        }
        if (accountholder[counter].account_number!=0){
            printf("Enter balance %d: ",counter+1);
            scanf("%f",&accountholder[counter].balance);
            if(accountholder[counter].balance>499){
                printf("You can open this account!\n\n");
            }
            else{
                printf("Sorry,we can't open this account!\n\n");
                accountholder[counter].balance=0;
                accountholder[counter].account_number=0;
            }
        }
        else{
            printf("Sorry,we can't open this account!\n\n");
            accountholder[counter].balance=0;
            accountholder[counter].account_number=0;
        }
    }

    ///Printing Accounts & Balances as Output of the system
    printf("\n\n===== Accounts & Balances of all the account holders =====\n");
    for(counter=0;counter<=9;counter++){
        if(accountholder[counter].balance!=0 && accountholder[counter].account_number!=0){
            output__account_info();
        }
        else{
            printf("\nInvalid\n\n");
        }
    }

    ///Taking deposits to the valid accounts
    for(counter=0;counter<=9;counter++){
        if(accountholder[counter].balance!=0 && accountholder[counter].account_number!=0){
            printf("\nEnter amount to deposit to account %d: ",counter+1);
            scanf("%f",&accountholder[counter].last_deposit);
            accountholder[counter].balance=accountholder[counter].balance+accountholder[counter].last_deposit;
        }
        else{
            printf("\nInvalid\n");
        }

    }

    ///Printing total amounts after last depositing to balance
    printf("\n\n===== Balances of all the valid account holders after depositing =====\n");
    for(counter=0;counter<=9;counter++){
        if(accountholder[counter].balance!=0 && accountholder[counter].account_number!=0){
            output__account_info();
            printf("Last deposit to account no. %d: %.2f\n\n ",counter+1,accountholder[counter].last_deposit);
        }
        else{
            printf("\nInvalid\n\n");
        }
    }

    ///Withdrawing from the valid accounts
    for(counter=0;counter<=9;counter++){
        if(accountholder[counter].balance!=0 && accountholder[counter].account_number!=0){
            printf("\nEnter amount to withdraw from account %d: ",counter+1);
            scanf("%f",&accountholder[counter].last_withdraw);
            if(accountholder[counter].balance-accountholder[counter].last_withdraw>=500){
                printf("You can withdraw\n");
                accountholder[counter].balance=accountholder[counter].balance-accountholder[counter].last_withdraw;
            }
            else{
                printf("Sorry insufficient balance!!\n");
                accountholder[counter].balance=1;
            }
        }
        else{
            printf("\nInvalid\n");
        }

    }

    ///Printing total amounts after last withdraw from balance
    printf("\n\n===== Balances of all the valid account holders after withdraw =====\n");
    for(counter=0;counter<=9;counter++){
        if(accountholder[counter].balance!=0 && accountholder[counter].account_number!=0){
            if(accountholder[counter].balance!=1){
                output__account_info();
                printf("Last withdraw from account no. %d: %.2f\n\n ",counter+1,accountholder[counter].last_withdraw);
            }
            else{
                printf("\n\nSorry insufficient balance for withdraw from no. %d account!!\n\n",counter+1);
            }
        }
        else{
            printf("\nInvalid\n\n");
        }
    }
    return 0;
}



