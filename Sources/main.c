#include <Vector3d.h>
int main()
{
    /*
    Vertex tutu1, tutu2;
    tutu1.x = 2 + 4I;
    tutu1.y = 0 - 3I;
    tutu1.z = 1 + 2I;
    print(tutu1);
    printf("%.3f\n", mod(tutu1));
    tutu2.x = 2 + 0.0I;
    tutu2.y = 0 + 0.0I;
    tutu2.z = 1 - 0.0I;
    print(tutu2);
    printf("%.3f", mod(tutu2));
    */
    int c = 1;
    double x1 = 0, y1 = 0, z1 = 0;
    Vertex D_t = {&x1, &y1, &z1, func_double};
    D_t = *(Vertex *)malloc(sizeof(double) * 3);
    D_t.x = malloc(sizeof(double));
    D_t.y = malloc(sizeof(double));
    D_t.z = malloc(sizeof(double));
    double _Complex x2 = 0, y2 = 0, z2 = 0;
    Vertex C_t = {&x2, &y2, &z2, func_Complex};
    C_t = *(Vertex *)malloc(sizeof(double _Complex) * 3);
    C_t.x = malloc(sizeof(double _Complex));
    C_t.y = malloc(sizeof(double _Complex));
    C_t.z = malloc(sizeof(double _Complex));
    double a, b;
    printf("1 - complex Vector3d, 2 - double Vector3d\n");
    scanf("%d", &c);
    if (c == 1)
    {
        Vertex u = {&x2, &y2, &z2, func_Complex};
        u = *(Vertex *)malloc(sizeof(double _Complex) * 3);
        u.x = malloc(sizeof(double _Complex));
        u.y = malloc(sizeof(double _Complex));
        u.z = malloc(sizeof(double _Complex));
        do
        {
            printf("\n1 - scan\n2 - sum\n3-different\n4 - abs\n5 - normalize\n6 - scalar\n7 - cross\n8 - multiply by number\n9 - divide by number\n10 - reverse\n11 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                C_t = *(Vertex *)scan_Complex();
                print_Complex(&C_t);
                break;
            case 2:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_Complex();
                C_t = *(Vertex *)sum_Complex(&C_t, &u);
                print_Complex(&C_t);
                break;
            case 3:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_Complex();
                C_t = *(Vertex *)diff_Complex(&C_t, &u);
                print_Complex(&C_t);
                break;
            case 4:
                printf("%f", *mod_Complex(&C_t));
                break;
            case 5:
                C_t = *(Vertex *)normalize_Complex(&C_t);
                print_Complex(&C_t);
                break;
            case 6:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_Complex();
                printf("%f", *(double *)scalar_Complex(&C_t, &u));
                break;
            case 7:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_Complex();
                C_t = *(Vertex *)cross_Complex(&C_t, &u);
                print_Complex(&C_t);
                break;
            case 8:
            {
                printf("enter number\n");
                double r;
                scanf("%lf", &r);
                C_t = *(Vertex *)dot_Complex(&C_t, r);
                print_Complex(&C_t);
                break;
            }
            case 9:
            {
                printf("enter number\n");
                double r;
                scanf("%lf", &r);
                C_t = *(Vertex *)divide_Complex(&C_t, r);
                print_Complex(&C_t);
                break;
            }
            case 10:
                C_t = *(Vertex *)reverse_Complex(&C_t);
                print_Complex(&C_t);
                break;
            case 11:
                print_Complex(&C_t);
                break;
            case 0:
                return 0;
            default:
                continue;
            }
        } while (c != 0);
    }
    else
    {
        Vertex u = {&x1, &y1, &z1, func_double};
        u = *(Vertex *)malloc(sizeof(double) * 3);
        u.x = malloc(sizeof(double));
        u.y = malloc(sizeof(double));
        u.z = malloc(sizeof(double));
        do
        {
            printf("\n1 - scan\n2 - sum\n3-different\n4 - abs\n5 - normalize\n6 - scalar\n7 - cross\n8 - multiply by number\n9 - divide by number\n10 - reverse\n11 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                D_t = *(Vertex *)scan_double();
                print_double(&D_t);
                break;
            case 2:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_double();
                D_t = *(Vertex *)sum_double(&D_t, &u);
                print_double(&D_t);
                break;
            case 3:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_double();
                D_t = *(Vertex *)diff_double(&D_t, &u);
                print_double(&D_t);
                break;
            case 4:
                printf("%f", *mod_double(&D_t));
                break;
            case 5:
                D_t = *(Vertex *)normalize_double(&D_t);
                print_double(&D_t);
                break;
            case 6:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_double();
                printf("%f", *(double *)scalar_double(&D_t, &u));
                break;
            case 7:
                printf("enter second Vector\n");
                u = *(Vertex *)scan_double();
                D_t = *(Vertex *)cross_double(&D_t, &u);
                print_double(&D_t);
                break;
            case 8:
            {
                printf("enter number\n");
                double r;
                scanf("%lf", &r);
                D_t = *(Vertex *)dot_double(&D_t, r);
                print_double(&D_t);
                break;
            }
            case 9:
            {
                printf("enter number\n");
                double r;
                scanf("%lf", &r);
                D_t = *(Vertex *)divide_double(&D_t, r);
                print_double(&D_t);
                break;
            }
            case 10:
                D_t = *(Vertex *)reverse_double(&D_t);
                print_double(&D_t);
                break;
            case 11:
                print_double(&D_t);
                break;
            case 0:
                return 0;
            default:
                continue;
            }
        } while (c != 0);
    }
}
