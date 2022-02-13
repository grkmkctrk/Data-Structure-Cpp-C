#include "../Inc/main.h"
#include "../Inc/selfOrganizingList.h"


int main(){

    SOL_t* sol = initSOL(Count);

    insertSOL(sol, 7);
    insertSOL(sol, 3);
    insertSOL(sol, 1);
    insertSOL(sol, 5);
    insertSOL(sol, 9);



    searchSOL(sol, 3);
    searchSOL(sol, 7);
    searchSOL(sol, 7);
    searchSOL(sol, 1);
    searchSOL(sol, 1);
    searchSOL(sol, 9);
    searchSOL(sol, 9);
    searchSOL(sol, 5);
    searchSOL(sol, 5);
    searchSOL(sol, 5);
    searchSOL(sol, 9);

    // printSearchSOL(sol); use to debug

    printSOL(sol);

    
    return 0;
}