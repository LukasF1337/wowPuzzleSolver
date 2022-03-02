#include "stdio.h"
#include "assert.h"

void set_all_zero(char* field){
    for(int y = 0; y<5; y++){
    for(int x = 0; x<5; x++){
        field[y*5+x]=0;
    }
    }
}

void set_to_one(int x, int y, char* field){
    assert(0<=x && x<5 && 0<=y && y<5);
    field[y*5+x] = 1;
}

void apply_cross(int x, int y, char* field){
    assert(0<=x && x<5 && 0<=y && y<5);
    // middle
    field[y*5+x] ^= 1;
    // right
    if(x+1<5){
        field[y*5+x+1] ^= 1;
    }
    // left
    if(0<=x-1){
        field[y*5+x-1] ^= 1;
    }
    // up
    if(y+1<5){
        field[(y+1)*5+x] ^= 1;
    }
    // down
    if(0<=y-1){
        field[(y-1)*5+x] ^= 1;
    }
}

char check_equal(char* field, char* result){
    char res = 1; // assume equal
    for(int y = 0; y<5; y++){
    for(int x = 0; x<5; x++){
        if(field[y*5+x] != result[y*5+x]){
            res = 0;
        }
    }
    }
    return res;
}

void apply_number_to_field(char* field, int number){
    set_all_zero(field);
    for(int pos=1; (1<<pos)<=number; pos++){
        if((1<<pos) & number){
            int y = pos/5;
            int x = pos%5;
            apply_cross(x,y,field);
        }
    }
}

void set_number_positions_on_field(char* field, int number){
    set_all_zero(field);
    for(int pos=1; (1<<pos)<=number; pos++){
        if((1<<pos) & number){
            int y = pos/5;
            int x = pos%5;
            set_to_one(x,y,field);
        }
    }
}

char search(char* field, char* compare_field, char* positions, int* result_number){
    int res = 0;
    int current = 0;
    int max = 1<<(5*5);
    for(;current<max; current++){
        if(current%(1<<16) == 0){
            printf("Testing Combination %d out of %d\r",current,max);
        }
        for(int pos=1; (1<<pos)<=current; pos++){
            apply_number_to_field(compare_field,current);
        }
        if(check_equal(field,compare_field)){
            res=1;
            *result_number = current;
            set_number_positions_on_field(positions,current);
            break;
        }
    }
    printf("\n\n");
    return res;
}

void print_field(char* field){
    for(int y = 0; y<5; y++){
    for(int x = 0; x<5; x++){
        printf("|%d",field[y*5+x]);
    }
    printf("|\n");
    }
    printf("\n");
}

void read_user_input(char* field){
    printf("Enter the values of the puzzle, e.g. line \"1: 0 0 1 0 1\", confirm each line with enter.\n");
    printf("   v v v v v\n");
    for(int row = 0; row < 5; row++){
        fflush(stdin);
        fflush(stdout);
        printf("%d: ", row+1);
        fflush(stdin);
        fflush(stdout);
        scanf("%d %d %d %d %d", &field[row*5+0],&field[row*5+1],&field[row*5+2],&field[row*5+3],&field[row*5+4]);
        fflush(stdin);
        fflush(stdout);
    }
}

int main () {
    //         y  x
    char field[5][5];
    char search_field[5][5];
    char positions[5][5];
    set_all_zero((char*)field);
    set_all_zero((char*)search_field);
    set_all_zero((char*)positions);

    printf("Number of possibilities for cross placement is 2^(5*5) = %d\n\n",1<<25);

    read_user_input((char*)field);
    
    printf("\nsearching solution positions for:\n");
    print_field((char*)field);

    int result_number = 0;
    if(search((char*)field, (char*)search_field, (char*)positions, &result_number)){
        printf("Success!\n\n");
    }else{
        printf("\nFailure! No solution found.\nWrong input numbers?\n\n");
    }
    //print_field((char*)search_field);
    printf("Result Combination Number: %d\nResult Positions for cross placements:\n", result_number);
    print_field((char*)positions);
    
    printf("\nPress enter to exit");
    fflush(stdin);
    fflush(stdout);
    getchar();
    fflush(stdin);
    fflush(stdout);
}