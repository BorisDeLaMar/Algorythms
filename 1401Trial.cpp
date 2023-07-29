#include <iostream>
using namespace std;

typedef struct{
    int x;
    int y;
} point;

struct square{
    point A;
    point B;
    point C;
    point D;
};

struct triangle{
    point A;
    point B;
    point C;
    point D;
    point E;
    point F;
};

struct extended_triangle{
    struct triangle triangle;
    int type;
};

int position(int dimension, int x, int y){
    if(x%dimension > dimension/2){
        if(y%dimension > dimension/2){
            return 4;
        }
        else{
            return 3;
        }
    }
    else{
        if(y%dimension > dimension/2){
            return 2;
        }
        else{
            return 1;
        }
    }
    return 0;
}

struct square square_borders(struct square sqr, int pos){
    int dimension = sqr.B.y - sqr.A.y;
    int sqr_border = sqr.A.x;
    if(pos == 1){
        return {
            {dimension/2, sqr_border},
            {dimension/2, dimension/2},
            {sqr_border, dimension/2},
            {sqr_border, sqr_border}
        };
    }
    else if(pos == 2){
        return {
            {dimension/2, dimension/2},
            {dimension/2, dimension},
            {sqr_border, dimension},
            {sqr_border, dimension/2}
        };
    }
    else if(pos == 3){
        return {
            {dimension, sqr_border},
            {dimension, dimension/2},
            {dimension/2, dimension/2},
            {dimension/2, sqr_border}
        };
    }
    else if(pos == 4){
        return {
            {dimension/2, dimension/2},
            {dimension, dimension},
            {dimension/2, dimension},
            {dimension/2, dimension/2}
        };
    }
    return {0};
}

struct extended_triangle triangle_borders(struct square sqr_cur, struct square sqr_pred, int pos){
    struct extended_triangle triangle = {0};
    if(pos == 1){
        triangle.type = 3;
        triangle.triangle.A = sqr_pred.A;
        triangle.triangle.B = sqr_pred.B;
        triangle.triangle.C = sqr_pred.C;
        triangle.triangle.D = sqr_cur.C;
        triangle.triangle.E = sqr_cur.B;
        triangle.triangle.F = sqr_cur.A;
    }
    else if(pos == 2){
        triangle.type = 1;
        triangle.triangle.A = sqr_pred.A;
        triangle.triangle.B = sqr_pred.B;
        triangle.triangle.C = sqr_cur.B;
        triangle.triangle.D = sqr_cur.A;
        triangle.triangle.E = sqr_cur.D;
        triangle.triangle.F = sqr_pred.D;
    }
    else if(pos == 3){
        triangle.type = 4;
        triangle.triangle.A = sqr_cur.B;
        triangle.triangle.B = sqr_pred.B;
        triangle.triangle.C = sqr_pred.C;
        triangle.triangle.D = sqr_pred.D;
        triangle.triangle.E = sqr_cur.D;
        triangle.triangle.F = sqr_cur.C;
    }
    else if(pos == 4){
        triangle.type = 2;
        triangle.triangle.A = sqr_pred.A;
        triangle.triangle.B = sqr_cur.A;
        triangle.triangle.C = sqr_cur.D;
        triangle.triangle.D = sqr_cur.C;
        triangle.triangle.E = sqr_pred.C;
        triangle.triangle.F = sqr_pred.D;
    }
    return triangle;
}

struct extended_triangle* divide_triangle(struct extended_triangle triangle, struct extended_triangle* arr, int dimension){
    struct triangle trgl = triangle.triangle;
    if(triangle.type == 1){
        arr[0] = {
            .triangle = {
                .A = {trgl.A.x - (trgl.A.x + trgl.F.x)%4*dimension/2, trgl.A.y + (trgl.A.y + trgl.B.y)%4*dimension/2},
                .B = {trgl.A.x - (trgl.A.x + trgl.F.x)%4*dimension/2, trgl.B.y - (trgl.A.y + trgl.B.y)%4*dimension/2},
                .C = {trgl.C.x, (trgl.D.y + trgl.C.y)/2},
                .D = {trgl.D.x, trgl.D.y},
                .E = {(trgl.E.x + trgl.D.x)/2, trgl.E.y},
                .F = {(trgl.E.x + trgl.D.x)/2, (trgl.E.y + trgl.D.y)/2}
            },
            .type = 1
        };
        arr[1] = {
            .triangle = {
                .A = trgl.A,
                .B = {trgl.A.x, (trgl.A.y + trgl.B.y)/2},
                .C = {trgl.A.x - (trgl.A.x + trgl.F.x)%4*dimension/2, (trgl.A.y + trgl.B.y)/2},
                .D = arr[0].triangle.A,
                .E = {(trgl.A.x + trgl.F.x)/2, trgl.A.y + (trgl.A.y + trgl.B.y)%4*dimension/2},
                .F = {(trgl.A.x + trgl.F.x)/2, trgl.F.y}
            },
            .type = 1
        };
        arr[2] = {
            .triangle = {
                .A = arr[0].triangle.F,
                .B = arr[1].triangle.E,
                .C = arr[0].triangle.F,
                .D = arr[0].triangle.E,
                .E = trgl.E,
                .F = trgl.F
            },
            .type = 2
        };
        arr[3] = {
            .triangle = {
                .A = arr[1].triangle.B,
                .B = trgl.B,
                .C = trgl.C,
                .D = arr[0].triangle.C,
                .E = arr[0].triangle.B,
                .F = arr[1].triangle.C
            },
            .type = 3
        };
        return arr;
    }
    return 0;
}

int** filling(struct extended_triangle* array, int dimension, struct extended_triangle triangle, int** arr){
    if(dimension == 1){
        for(int i = 0; i < 4; i++){
            if(array[i].type == 1){
                arr[array[i].triangle.D.x][array[i].triangle.D.y] = 1;
                arr[array[i].triangle.C.x][array[i].triangle.C.y] = 1;
                arr[array[i].triangle.E.x][array[i].triangle.E.y] = 1;
            }
        }
        return arr;
    }
    else{
        for(int i = 0; i < 4; i++){
            struct extended_triangle* arr_small_trgl = (struct extended_triangle*) malloc(sizeof(struct extended_triangle)*4);
            arr_small_trgl = divide_triangle(array[i], arr_small_trgl, dimension/2);
            arr = filling(arr_small_trgl, dimension/2, array[i], arr);
        }
    }
}

int** func(struct square sqr_pred, int** arr, int number, int x, int y, int dimension){
    //dimension -= 1; //перевод в отсчет от нуля
    int pos = position(dimension, x, y);
    struct square sqr_cur = square_borders(sqr_pred, pos);

    struct extended_triangle triangle = triangle_borders(sqr_cur, sqr_pred, pos);
    struct extended_triangle* array = (struct extended_triangle*) malloc(sizeof(struct extended_triangle)*4);
    array = divide_triangle(triangle, array, dimension);
    arr = filling(array, dimension/4, triangle, arr);

    //dimension /= 2;
    //return func(sqr_cur, arr, number, x, y, dimension);
    return arr;
}

int main(){
    int n;
    int x; int y;

    cin >> n;
    cin >> x >> y;

    int** arr = (int**) malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        arr[i] = (int*) malloc(sizeof(int)*n);
    }
    struct square sqr{
        {n, 1},
        {n, n},
        {1, n},
        {1, 1}
    };
    arr = func(sqr, arr, 1, x, y, n);

    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}